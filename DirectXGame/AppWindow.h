#pragma once
#include"Window.h"
#include "GraphicsEngine.h"
#include "SwapChain.h"
#include "DeviceContext.h"
#include "VertexBuffer.h"
#include "ConstantBuffer.h"
#include "IndexBuffer.h"
#include "VertexShader.h"
#include "PixelShader.h"
#include "InputListener.h"
#include "Matrix4x4.h"


class AppWindow : public Window, public InputListener
{
public:
	AppWindow();

	void update();

	~AppWindow();

	// Inherited via Window
	virtual void onCreate() override;
	virtual void onUpdate() override;
	virtual void onDestroy() override;
	virtual void onFocus() override;
	virtual void onKillFocus() override;

	// Inherited via InputListener
	virtual void onKeyDown(int key) override;
	virtual void onKeyUp(int key) override;
	virtual void onMouseMove(const Point& mouse_pos) override;

	virtual void onLeftMouseDown(const Point& delta_mouse_pos) override;
	virtual void onLeftMouseUp(const Point& delta_mouse_pos) override;

	virtual void onRightMouseDown(const Point& delta_mouse_pos) override;
	virtual void onRightMouseUp(const Point& delta_mouse_pos) override;

private:
	SwapChainPtr m_swap_chain;
	VertexBufferPtr m_vb;
	VertexShaderPtr m_vs;
	PixelShaderPtr m_ps;
	ConstantBufferPtr m_cb;
	IndexBufferPtr m_ib;
	TexturePtr m_wood_tex;


private :
	float m_old_delta;
	float m_new_delta;
	float m_delta_time;

	float m_delta_pos;
	float m_delta_scale;

	float m_rot_x = 0;
	float m_rot_y = 0;

	float m_scale_cube = 1;
	float m_forward = 0.0f;
	float m_rightward = 0.0f;
	Matrix4x4 m_world_cam;
};

