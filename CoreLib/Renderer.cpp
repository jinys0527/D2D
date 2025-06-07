#include "Renderer.h"
#include "GeometryObject.h"

bool Renderer::Initialize()
{
	const wchar_t* className = L"D2DHomework01";
	const wchar_t* windowName = L"D2DHomework01";

	if (false == __super::Create(className, windowName, 800, 600))
	{
		return false;
	}

	InitD2DRenderSystem(m_hWnd);

	return true;
}

void Renderer::Finalize()
{
	ReleaseD2DRenderSystem();

	__super::Destroy();
}

void Renderer::OnResize(int width, int height)
{
	__super::OnResize(width, height);
}

void Renderer::OnClose()
{
}

bool Renderer::InitD2DRenderSystem(HWND hwnd)
{
	D3D_FEATURE_LEVEL featureLevels[] = { D3D_FEATURE_LEVEL_11_0 };
	ComPtr<ID3D11Device> d3dDevice;
	
	HRESULT hr = D3D11CreateDevice(nullptr,
		D3D_DRIVER_TYPE_HARDWARE,
		nullptr,
		D3D11_CREATE_DEVICE_BGRA_SUPPORT,
		featureLevels,
		ARRAYSIZE(featureLevels),
		D3D11_SDK_VERSION,
		&d3dDevice,
		nullptr,
		nullptr
	);

	if (FAILED(hr)) return false;

	ComPtr<IDXGIDevice> dxgiDevice;
	hr = d3dDevice.As(&dxgiDevice);
	if (FAILED(hr)) return false;

	ComPtr<IDXGIAdapter> dxgiAdapter;
	hr = dxgiDevice->GetAdapter(&dxgiAdapter);
	if (FAILED(hr)) return false;

	ComPtr<IDXGIFactory2> dxgiFactory;
	hr = dxgiDevice->GetParent(IID_PPV_ARGS(&dxgiFactory));
	if (FAILED(hr)) return false;

	DXGI_SWAP_CHAIN_DESC1 scDesc = {};
	scDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
	scDesc.SampleDesc.Count = 1;
	scDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	scDesc.BufferCount = 2;
	scDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
	scDesc.Scaling = DXGI_SCALING_STRETCH;

	ComPtr<IDXGISwapChain1> swapChain;
	hr = dxgiFactory->CreateSwapChainForHwnd(d3dDevice.Get(), hwnd, &scDesc, nullptr, nullptr, &swapChain);
	if (FAILED(hr)) return false;

	D2D1_FACTORY_OPTIONS opts = {};
	ComPtr<ID2D1Factory8> d2dFactory;

	hr = D2D1CreateFactory(
		D2D1_FACTORY_TYPE_SINGLE_THREADED, 
		__uuidof(ID2D1Factory8),
		&opts,
		reinterpret_cast<void**>(d2dFactory.GetAddressOf()));
	if (FAILED(hr)) return false;

	ComPtr<ID2D1Device> baseDevice;
	hr = d2dFactory->CreateDevice(dxgiDevice.Get(), &baseDevice);
	if (FAILED(hr)) return false;

	ComPtr<ID2D1Device7> d2dDevice;
	hr = baseDevice.As(&d2dDevice);
	if (FAILED(hr)) return false;

	ComPtr<ID2D1DeviceContext7> d2dContext;
	hr = d2dDevice->CreateDeviceContext(D2D1_DEVICE_CONTEXT_OPTIONS_NONE, &d2dContext);
	if (FAILED(hr)) return false;

	ComPtr<IDXGISurface> dxgiSurface;
	hr = swapChain->GetBuffer(0, IID_PPV_ARGS(&dxgiSurface));
	if (FAILED(hr)) return false;

	D2D1_BITMAP_PROPERTIES1 bitmapProps = {};
	bitmapProps.bitmapOptions = D2D1_BITMAP_OPTIONS_TARGET | D2D1_BITMAP_OPTIONS_CANNOT_DRAW;
	bitmapProps.pixelFormat.format = DXGI_FORMAT_B8G8R8A8_UNORM;
	bitmapProps.pixelFormat.alphaMode = D2D1_ALPHA_MODE_PREMULTIPLIED;
	bitmapProps.dpiX = bitmapProps.dpiY = 96.0f;

	ComPtr<ID2D1Bitmap1> targetBitmap;
	hr = d2dContext->CreateBitmapFromDxgiSurface(dxgiSurface.Get(), bitmapProps, targetBitmap.GetAddressOf());
	if (FAILED(hr)) return false;

	d2dContext->SetTarget(targetBitmap.Get());

	ComPtr<ID2D1SolidColorBrush> brush;
	hr = d2dContext->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Tomato), &brush);
	if (FAILED(hr)) return false;

	m_d3dDevice = d3dDevice;
	m_d2dFactory = d2dFactory;
	m_d2dDevice = d2dDevice;
	m_d2dContext = d2dContext;
	m_swapChain = swapChain;
	m_targetBitmap = targetBitmap;
	m_brush = brush;

	return true;
}

void Renderer::ReleaseD2DRenderSystem()
{
	m_brush.Reset();
	m_d3dDevice.Reset();
	m_d2dDevice.Reset();
	m_d2dFactory.Reset();
	m_d2dContext.Reset();
	m_swapChain.Reset();
	m_targetBitmap.Reset();
}

void Renderer::RenderFrame()
{
	if (!m_d2dContext || !m_swapChain)
		return;

	m_d2dContext->BeginDraw();

	Point point;
	int scale1;
	int scale2;
	Color color;
	//GeometryObject::GetGeometryInfo(point, scale1, scale2, color);
	//·»´õ¸µ Á¤º¸
	/*switch (currentScene)
	{
	case Line:

	case Circle:

	case Rectangle:

	case Polygon:

	}
	*/

	m_d2dContext->EndDraw();

	m_swapChain->Present(1, 0);
}