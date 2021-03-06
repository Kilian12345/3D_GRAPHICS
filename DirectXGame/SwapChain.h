#pragma once
#include <d3d11.h>
#include "Prerequisistes.h"

class SwapChain
{
public:
	SwapChain(HWND hwnd, UINT width, UINT height , RenderSystem* m_system);

	bool present(bool vsync);

	//Release the SwapChain
	~SwapChain();

private:
	IDXGISwapChain* m_swap_chain;
	ID3D11RenderTargetView* m_rtv;
	RenderSystem* m_system = nullptr;

private:
	friend class DeviceContext;
};

