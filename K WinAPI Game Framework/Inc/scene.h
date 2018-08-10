#pragma once

#include "tag.h"

class Scene final : public Tag, public std::enable_shared_from_this<Scene>
{
	friend class SceneManager;
private:
	Scene() = default;
	Scene(Scene const& _other);
	Scene(Scene&& _other) noexcept;
	Scene& operator=(Scene const&) = default;
	Scene& operator=(Scene&&) noexcept = default;

	virtual void _Release() override;

	bool _Initialize();
	void _Input(float _time);
	void _Update(float _time);
	void _LateUpdate(float _time);
	void _Collision(float _time);
	void _Render(HDC _device_context, float _time);
};