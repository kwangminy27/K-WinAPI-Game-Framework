#include "stdafx.h"
#include "core.h"

#include "timer.h"
#include "path_manager.h"
#include "texture_manager.h"
#include "audio_manager.h"

using namespace std;

bool Core::Initialize(wstring const& _class_name, wstring const& _window_name, HINSTANCE _instance, HICON _icon)
{
	instance_ = _instance;

	_RegisterClass(_class_name, _icon);
	_CreateWindow(_class_name, _window_name);

	device_context_ = GetDC(window_);

	if (!PathManager::GetSingleton()->Initialize())
		return false;

	if (!TextureManager::GetSingleton()->Initialize())
		return false;

	if (!AudioManager::GetSingleton()->Initialize())
		return false;

	if (!_CreateTimer())
		return false;

	return true;
}

int Core::Run()
{
	MSG message{};
	while (state() == MESSAGE_LOOP::RUN)
	{
		if (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		else
			_Logic();
	}

	return static_cast<int>(message.wParam);
}

HINSTANCE Core::instance() const
{
	return instance_;
}

HWND Core::window() const
{
	return window_;
}

HDC Core::device_context() const
{
	return device_context_;
}

MESSAGE_LOOP Core::state() const
{
	return state_;
}

void Core::set_state(MESSAGE_LOOP _state)
{
	state_ = _state;
}

void Core::_Release()
{
	ReleaseDC(window_, device_context_);
}

LRESULT Core::_WindowProc(HWND _window, UINT _message, WPARAM _w_param, LPARAM _l_param)
{
	switch (_message)
	{
	case WM_KEYDOWN:
		switch (_w_param)
		{
		case VK_ESCAPE:
			DestroyWindow(_window);
			break;
		}
		return 0;
	case WM_DESTROY:
		Core::GetSingleton()->set_state(MESSAGE_LOOP::EXIT);
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(_window, _message, _w_param, _l_param);
}

void Core::_RegisterClass(wstring const& _class_name, HICON _icon)
{
	WNDCLASS wc{};
	wc.lpfnWndProc = Core::_WindowProc;
	wc.hInstance = instance_;
	wc.hIcon = _icon;
	wc.hbrBackground = static_cast<HBRUSH>(GetStockObject(LTGRAY_BRUSH));
	wc.lpszClassName = _class_name.c_str();
	RegisterClass(&wc);
}

void Core::_CreateWindow(wstring const& _class_name, wstring const& _window_name)
{
	window_ = CreateWindow(
		_class_name.c_str(), _window_name.c_str(),
		WS_CAPTION | WS_SYSMENU,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		nullptr, nullptr, instance_,
		nullptr
	);

	if (!window_)
		return;

	RECT rc{ 0, 0, static_cast<long>(RESOLUTION::WIDTH), static_cast<long>(RESOLUTION::HEIGHT) };
	AdjustWindowRect(&rc, WS_CAPTION | WS_SYSMENU, false);
	SetWindowPos(window_, HWND_TOP, 100, 50, rc.right - rc.left, rc.bottom - rc.top, NULL);

	ShowWindow(window_, SW_SHOW);
}

bool Core::_CreateTimer()
{
	timer_ = unique_ptr<Timer, function<void(Timer*)>>(new Timer, [](Timer* p) {
		delete p;
	});
	time_scale_ = 1.f;

	return true;
}

void Core::_Logic()
{
	timer_->Update();
	float delta_time = timer_->delta_time() * time_scale_;

	_Input(delta_time);
	_Update(delta_time);
	_Collision(delta_time);
	_Render(delta_time);
}

void Core::_Input(float _time)
{
}

void Core::_Update(float _time)
{
	AudioManager::GetSingleton()->Update();
}

void Core::_Collision(float _time)
{
}

void Core::_Render(float _time)
{
	wstring fps = to_wstring(timer_->frame_per_second());
	fps += L" FPS";
	TextOut(device_context_, 0, 0, fps.c_str(), static_cast<int>(fps.size()));
}