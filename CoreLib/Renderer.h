#pragma once
#include <wrl/client.h>
using Microsoft::WRL::ComPtr;

#include <d3d11.h>
//#include <d3dcompiler.h>
#include <dxgi1_6.h>
#include <d2d1_3.h>
#include <d2d1.h>

class Renderer
{
public:
	Renderer() = default;
	~Renderer() = default;
private:

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

