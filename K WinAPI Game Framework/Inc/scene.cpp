#include "stdafx.h"
#include "scene.h"

using namespace std;

Scene::Scene(Scene const& _other)
{
	*this = _other;
}

Scene::Scene(Scene&& _other) noexcept
{
	*this = move(_other);
}

void Scene::_Release()
{
}

bool Scene::_Initialize()
{
	return true;
}

void Scene::_Input(float _time)
{
}

void Scene::_Update(float _time)
{
}

void Scene::_LateUpdate(float _time)
{
}

void Scene::_Collision(float _time)
{
}

void Scene::_Render(HDC _device_context, float _time)
{
}