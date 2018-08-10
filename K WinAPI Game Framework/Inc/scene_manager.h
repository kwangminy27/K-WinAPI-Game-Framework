#pragma once

#include "singleton.h"

class Scene;

class SceneManager final : public Singleton<SceneManager>
{
	friend class Singleton<SceneManager>;
public:
	bool Initialize();
	void Input(float _time);
	void Update(float _time);
	void LateUpdate(float _time);
	void Collision(float _time);
	void Render(HDC _device_context, float _time);

private:
	SceneManager() = default;
	SceneManager(SceneManager const&) = delete;
	SceneManager& operator=(SceneManager const&) = delete;

	virtual void _Release() override;

	std::shared_ptr<Scene> _CreateScene(std::string const& _tag);

	std::shared_ptr<Scene> scene_{};
};