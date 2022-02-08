#include"Renderer.h"

Renderer::Renderer()
{
	ClearColor = D3DCOLOR_XRGB(100, 100, 0);
	MainWindow = NULL;
	FullScreen = false;
	Direct3DObject = NULL;
	Direct3DDevice = NULL;
	IsRenderedScene = 0;
	g_pManager = NULL;
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

	if (FAILED(Direct3DObject->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, MainWindow, processing, &Params, &Direct3DDevice)))
		return false;

	if (Direct3DDevice == NULL)
		return false;

	OneTimeInit();

	return true;
}

void Renderer::OneTimeInit()
{
	g_pManager = new ControlManager(MainWindow, Direct3DDevice);
}

void Renderer::SetClearColor(float r, float g, float b)
{
	ClearColor = D3DCOLOR_COLORVALUE(r, g, b, 1.0f);
}

int Renderer::Render(int staticId)
{
	g_pManager->ControlRender();
	return 0;
}

void Renderer::Shutdown()
{
}

void Renderer::StartRender(bool bColor, bool bDepth, bool bStencil)
{
	if (!Direct3DDevice) return;

	unsigned int ClearFlags = 0;
	if (bColor) ClearFlags |= D3DCLEAR_TARGET;
	if (bDepth) ClearFlags |= D3DCLEAR_ZBUFFER;
	if (bStencil) ClearFlags |= D3DCLEAR_STENCIL;

	if (FAILED(Direct3DDevice->Clear(0, NULL, ClearFlags, ClearColor, 1, 0))) return;
	if (FAILED(Direct3DDevice->BeginScene())) return;

	Render(0);

	IsRenderedScene = true;//用于EndRendering()判断是否结束渲染
}

void Renderer::SetClearFlags(bool bColor, bool bDepth, bool bStencil)
{
}

void Renderer::EndRendering()
{
	if (!Direct3DDevice) return;

	Direct3DDevice->EndScene();
	Direct3DDevice->Present(NULL, NULL, NULL, NULL);

	IsRenderedScene = false;
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
