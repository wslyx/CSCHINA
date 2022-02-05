#include"Renderer.h"

Renderer::Renderer()
{
	ClearColor = D3DCOLOR_XRGB(100, 100, 0);
	MainWindow = NULL;
	FullScreen = false;
	Direct3DObject = NULL;
	Direct3DDevice = NULL;
}

Renderer::~Renderer()
{

}

bool Renderer::Initialize(int w, int h, HWND mainWin, bool fullScreen)
{
	MainWindow = mainWin;
	if (!MainWindow)
		return false;
	FullScreen = fullScreen;

	D3DDISPLAYMODE mode;
	D3DCAPS9 caps;
	D3DPRESENT_PARAMETERS Params;
	
	ZeroMemory(&Params, sizeof(Params));

	Direct3DObject = Direct3DCreate9(D3D_SDK_VERSION);
	if (!Direct3DObject) 
		return false;
	if (FAILED(Direct3DObject->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &mode))) 
		return false;
	if (FAILED(Direct3DObject->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps))) 
		return false;

	DWORD processing = 0;
	if (caps.VertexProcessingCaps != 0)
		processing = D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_PUREDEVICE;
	else
		processing = D3DCREATE_SOFTWARE_VERTEXPROCESSING;

	if (FullScreen)
	{
		Params.FullScreen_RefreshRateInHz = mode.RefreshRate;
		Params.PresentationInterval = D3DPRESENT_INTERVAL_ONE;
	}
	else
		Params.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

	Params.Windowed = !FullScreen;
	Params.BackBufferWidth = w;
	Params.BackBufferHeight = h;
	Params.hDeviceWindow = MainWindow;
	Params.SwapEffect = D3DSWAPEFFECT_DISCARD;
	Params.BackBufferFormat = mode.Format;
	Params.BackBufferCount = 1;
	Params.EnableAutoDepthStencil = TRUE;
	Params.AutoDepthStencilFormat = D3DFMT_D16;

	ScreenWidth = w;
	ScreenHeight = h;

	if (FAILED(Direct3DObject->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, MainWindow, processing, &Params, &Direct3DDevice))) return false;

	if (Direct3DDevice == NULL) return false;

	OneTimeInit();

	return false;
}

void Renderer::OneTimeInit()
{
}

void Renderer::SetClearCol(float r, float g, float b)
{
	ClearColor = D3DCOLOR_COLORVALUE(r, g, b, 1.0f);
}

int Renderer::Render(int staticId)
{
	return 0;
}

void Renderer::Shutdown()
{
}

void Renderer::StartRender(bool bColor, bool bDepth, bool bStencil)
{
}

void Renderer::ClearBuffers(bool bColor, bool bDepth, bool bStencil)
{
}

void Renderer::EndRendering()
{
}

void Renderer::CalculateProjMatrix(float fov, float n, float f)
{
}

void Renderer::CalculateOrthoMatrix(float n, float f)
{
}

int Renderer::CreateStaticBuffer(VertexType, PrimType, int totalVerts, int totalIndices, int stride, void** data, unsigned int* indices, int* staticId)
{
	return 0;
}
