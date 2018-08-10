#include "stdafx.h"
#include "scene_manager.h"

#include "scene.h"
#include "logo_scene.h"
#include "object_manager.h"

using namespace std;

bool SceneManager::Initialize()
{
	scene_ = _CreateScene("Hello, world!");
	scene_->scene_component_ = scene_->_CreateSceneComponent<LogoScene>("Hello, world!");

	return true;
}

void SceneManager::Input(float _time)
{
	scene_->_Input(_time);
}

void SceneManager::Update(float _time)
{
	scene_->_Update(_time);
}

void SceneManager::LateUpdate(float _time)
{
	scene_->_LateUpdate(_time);
}

void SceneManager::Collision(float _time)
{
	scene_->_Collision(_time);
}

void SceneManager::Render(HDC _device_context, float _time)
{
	scene_->_Render(_device_context, _time);
}

void SceneManager::TrySceneChange()
{
	if (!next_scene_)
		return;

	ObjectManager::GetSingleton()->ErasePrototype(scene_);
	scene_ = move(next_scene_);
}

void SceneManager::_Release()
{
}

shared_ptr<Scene> SceneManager::_CreateScene(string const& _tag)
{
	auto scene = shared_ptr<Scene>(new Scene, [](Scene *_p) {
		_p->_Release();
		delete _p;
	});

	scene->set_tag(_tag);

	if (!scene->_Initialize())
		return scene_nullptr_;

	return scene;
}