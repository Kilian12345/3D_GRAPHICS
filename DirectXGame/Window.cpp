#include "Window.h"

Window* window = NULL;

Window::Window()
{
}

LRESULT CALLBACK WndProck (HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
		case WM_CREATE:
		{
			// Event fired when the Window will be created
			window->onCreate();
			break;
		}
		case WM_DESTROY :
		{
			//Event fired when the window will be destroyed
			window->onDestroy();
			::PostQuitMessage(0);
			break;
		}
		default :
			return ::DefWindowProc(hwnd, msg, wparam, lparam);
	}

	return NULL;
}

bool Window::init()
{
	WNDCLASSEX wc;
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = NULL;
	wc.lpszClassName = L"MyWindowClass";
	wc.lpszMenuName = L"";
	wc.style = NULL;
	wc.lpfnWndProc = &WndProck;


	if (!::RegisterClassEx(&wc)) // IF the registration of class will fail, the function will return false
		return false;


	if (!window)
		window = this;

	//Creation of the window
	m_hwnd=::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, L"MyWindowClass", L"Kilian First Window (moment cultissime)", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1024, 768, NULL, NULL, NULL, NULL);

	//if the creation fail return false
	if (!m_hwnd)
		return false;

	//show up the window
	::ShowWindow(m_hwnd, SW_SHOW);
	::UpdateWindow(m_hwnd);


	//set this flag to true to indicate that the window is initialized and running
	m_is_run = true;

	return true;
}

bool Window::broadcast()
{
	MSG msg;

	while (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	window->onUpdate();

	Sleep(0);

	return true;
}

bool Window::release()
{
	//Destroy the window
	if (!::DestroyWindow(m_hwnd))
		return false;

	return true;
}

bool Window::isRun()
{
	return m_is_run;
}

void Window::onCreate()
{
}

void Window::onUpdate()
{
}

void Window::onDestroy()
{
	m_is_run = false;
}

Window::~Window()
{
}
