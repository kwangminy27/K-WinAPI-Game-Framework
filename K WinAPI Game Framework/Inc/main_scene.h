#pragma once

#include "scene_component.h"

class MainScene final : public SceneComponent
{
	friend class Scene;
private:
	MainScene() = default;

	virtual void _Release() override;
	
	virtual bool _Initialize() override;
	virtual void _Input(float _time) override;
	virtual void _Update(float _time) override;
	virtual void _LateUpdate(float _time) override;
	virtual void _Collision(float _time) override;
	virtual void _Render(HDC _device_context, float _time) override;
};