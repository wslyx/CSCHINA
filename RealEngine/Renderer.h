#pragma once
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#include<d3d9.h>
#include<d3dx9.h>
#include<Windows.h>

class Renderer
{
private:
	D3DCOLOR ClearColor;//������ɫ
	HWND MainWindow;//�����ھ��
	bool FullScreen;//�Ƿ�ȫ��
	LPDIRECT3D9 Direct3DObject;//D3D����
	LPDIRECT3DDEVICE9 Direct3DDevice;//D3D�豸
public:
	Renderer();
	~Renderer();
	bool Initialize(int w, int h, HWND mainWin, bool fullScreen);//��䴰�����ݣ�������豸����
};