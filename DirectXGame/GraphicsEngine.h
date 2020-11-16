#pragma once
#include <d3d11.h>
#include "Prerequisistes.h"	
#include "RenderSystem.h"

class GraphicsEngine
{
public:
	GraphicsEngine();
	// Inititalize the GraphicsEngine and DirectX 11 Device
	bool init();

	//Release all the resources loaded
	bool release();
	RenderSystem* getRenderSystem();
	~GraphicsEngine();

public:
	static GraphicsEngine* get();

private:
	RenderSystem* m_render_system = nullptr;
};

