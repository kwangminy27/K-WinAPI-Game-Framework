#pragma once

#include "singleton.h"

class Timer;

class Core final : public Singleton<Core>
{
	friend class Singleton<Core>;
public:
	bool Initialize(std::wstring const& _class_name, std::wstring const& _window_name, HINSTANCE _instance, HICON _icon);
	int Run();

	HINSTANCE instance() const;
	HWND window() const;
	HDC device_context() const;

	MESSAGE_LOOP state() const;
	void set_state(MESSAGE_LOOP _state);

private:
	Core() = default;
	Core(Core const&) = delete;
	Core& operator=(Core const&) = delete;

	virtual void _Release() override;

	static LRESULT CALLBACK _WindowProc(HWND _window, UINT _message, WPARAM _w_param, LPARAM _l_param);
	void _RegisterClass(std::wstring const& _class_name, HICON _icon);
	void _CreateWindow(std::wstring const& _class_name, std::wstring const& _window_name);

	bool _CreateTimer();

	void _Logic();
	void _Input(float _time);
	void _Update(float _time);
	void _Collision(float _time);
	void _Render(float _time);

	HINSTANCE instance_{};
	HWND window_{};
	HDC device_context_{};

	MESSAGE_LOOP state_{ MESSAGE_LOOP::RUN };

	std::unique_ptr<Timer, std::function<void(Timer*)>> timer_{};
	float time_scale_{};
};