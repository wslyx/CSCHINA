#pragma once
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#include<d3d9.h>
#include<d3dx9.h>
#include<Windows.h>

class Renderer
{
private:
	D3DCOLOR ClearColor;//清屏颜色
	HWND MainWindow;//主窗口句柄
	bool FullScreen;//是否全屏
	LPDIRECT3D9 Direct3DObject;//D3D对象
	LPDIRECT3DDEVICE9 Direct3DDevice;//D3D设备
public:
	Renderer();
	~Renderer();
	bool Initialize(int w, int h, HWND mainWin, bool fullScreen);//填充窗口数据，并获得设备参数
};