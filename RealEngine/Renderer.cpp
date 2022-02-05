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

	return false;
}
