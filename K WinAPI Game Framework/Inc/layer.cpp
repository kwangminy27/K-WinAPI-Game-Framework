#include "stdafx.h"
#include "layer.h"

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
	scene_ = _scene;
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
}

void Layer::_Update(float _time)
{
}

void Layer::_LateUpdate(float _time)
{
}

void Layer::_Collision(float _time)
{
}

void Layer::_Render(HDC _device_context, float _time)
{
}