#include "Control.h"

ControlManager::ControlManager(HWND MainWindow, LPDIRECT3DDEVICE9 Direct3DDevice)
{
	this->MainWindow = MainWindow;
	this->Direct3DDevice = Direct3DDevice;
	D3DXCreateFont(Direct3DDevice, 36, 0, 0, 1000, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, L"Calibri", &g_pTextUI);
}

ControlManager::~ControlManager()
{
}

bool ControlManager::AddText(LPCWSTR Text, int xPos, int yPos, int Width, int Height)
{
	Control temp;
	temp.text = Text;
	temp.xPos = xPos;
	temp.yPos = yPos;
	temp.width = Width;
	temp.height = Height;
	return false;
}

bool ControlManager::ControlRender()
{
	//����һ�����Σ����ڻ�ȡ�����ھ���
	RECT formatRect;
	GetClientRect(MainWindow, &formatRect);

	D3DXCreateFont(Direct3DDevice, 36, 0, 0, 1000, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, L"Calibri", &g_pTextUI);
	//�ڴ������ϽǴ�����ʾÿ��֡��
	formatRect.top = 5;
	wchar_t	g_strFPS[50];
	int charCount = swprintf_s(g_strFPS, 20, L"Hello UI");
	//MessageBox(MainWindow, L"����Ϊ��", L"ǳī����Ϣ����", 0);
	g_pTextUI->DrawText(NULL, g_strFPS, charCount, &formatRect, DT_TOP | DT_RIGHT, D3DCOLOR_RGBA(0, 239, 136, 255));

	return true;
}
