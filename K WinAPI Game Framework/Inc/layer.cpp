#include "stdafx.h"
#include "layer.h"

#include "scene.h"
#include "object.h"

using namespace std;

int Layer::z_order() const
{
	return z_order_;
}

void Layer::set_z_order(int _z_order)
{
	z_order_ = _z_order;
}

shared_ptr<Scene> Layer::scene() const
{
	return scene_.lock();
}

void Layer::set_scene(shared_ptr<Scene> const& _scene)
{
	if (!_scene)
		return;

	scene_ = _scene;
}

shared_ptr<Object> const& Layer::FindObject(string const& _tag) const
{
	for (auto iter = object_list_.begin(); iter != object_list_.end(); ++iter)
	{
		if ((*iter)->tag() == _tag)
			return *iter;
	}

	return object_nullptr_;
}

Layer::Layer(Layer const& _other)
{
	*this = _other;
}

Layer::Layer(Layer && _other) noexcept
{
	*this = move(_other);
}

void Layer::_Release()
{
}

bool Layer::_Initialize()
{
	return true;
}

void Layer::_Input(float _time)
{
	for (auto iter = object_list_.begin(); iter != object_list_.end();)
	{
		if (!(*iter)->activation())
			iter = object_list_.erase(iter);
		else if (!(*iter)->enablement())
			++iter;
		else
		{
			(*iter)->_Input(_time);
			++iter;
		}
	}
}

void Layer::_Update(float _time)
{
	for (auto iter = object_list_.begin(); iter != object_list_.end();)
	{
		if (!(*iter)->activation())
			iter = object_list_.erase(iter);
		else if (!(*iter)->enablement())
			++iter;
		else
		{
			(*iter)->_Update(_time);
			++iter;
		}
	}
}

void Layer::_LateUpdate(float _time)
{
	for (auto iter = object_list_.begin(); iter != object_list_.end();)
	{
		if (!(*iter)->activation())
			iter = object_list_.erase(iter);
		else if (!(*iter)->enablement())
			++iter;
		else
		{
			(*iter)->_LateUpdate(_time);
			++iter;
		}
	}
}

void Layer::_Collision(float _time)
{
	for (auto iter = object_list_.begin(); iter != object_list_.end();)
	{
		if (!(*iter)->activation())
			iter = object_list_.erase(iter);
		else if (!(*iter)->enablement())
			++iter;
		else
		{
			//CollisionManager::GetSingleton()->AddCollider(*iter);
			++iter;
		}
	}
}

void Layer::_Render(HDC _device_context, float _time)
{
	for (auto iter = object_list_.begin(); iter != object_list_.end();)
	{
		if (!(*iter)->activation())
			iter = object_list_.erase(iter);
		else if (!(*iter)->enablement())
			++iter;
		else
		{
			(*iter)->_Render(_device_context, _time);
			++iter;
		}
	}
}

void Layer::_AddObject(shared_ptr<Object> const& _object)
{
	if (!_object)
		return;

	object_list_.push_back(_object);
}