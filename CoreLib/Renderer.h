#pragma once
#include "pch.h"

class Renderer : public NzWndBase
{
public:
	Renderer() = default;
	~Renderer() = default;

	bool Initialize();
	void Finalize();
private:
	void OnResize(int width, int height) override;
	void OnClose() override;

	bool InitD2DRenderSystem(HWND hwnd);
	void ReleaseD2DRenderSystem();

	void RenderFrame();

	ComPtr<ID3D11Device>		m_d3dDevice;

	ComPtr<IDXGISwapChain1>		m_swapChain;

	ComPtr<ID2D1Factory8>		m_d2dFactory;
	ComPtr<ID2D1Device7>		m_d2dDevice;
	ComPtr<ID2D1DeviceContext7> m_d2dContext;

	ComPtr<ID2D1HwndRenderTarget> m_renderTarget;

	ComPtr<ID2D1SolidColorBrush> m_brush;

	ComPtr<ID2D1Bitmap1> m_targetBitmap;
};

