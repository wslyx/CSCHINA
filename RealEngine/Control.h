#pragma once
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#include<d3d9.h>
#include<d3dx9.h>
#include<Windows.h>
#include<vector>

enum class ControlType
{
	TEXT,BUTTON,PICTURE
};

struct Control
{
	// Control type, id, and color.
	ControlType type;
	int id;
	unsigned long color;

	// If text then this is the id of the font it uses, else vertex buffer.
	int listID;

	// Starting location for the control.
	float xPos, yPos;

	// Width and height of the button.
	float width, height;

	// Text of static text.
	LPCWSTR text;

	// Fullscreen image of the background.
	LPDIRECT3DTEXTURE9 backDrop;

	// Button's up, down, and over textures.
	LPDIRECT3DTEXTURE9 upTex, downTex, overTex;
};

class ControlManager
{
public:
	ControlManager(HWND MainWindow,LPDIRECT3DDEVICE9 Direct3DDevice);
	~ControlManager();

	bool AddText(LPCWSTR Text, int xPos, int yPos, int Width, int Height);

	bool ControlRender();

private:
	HWND MainWindow;
	LPDIRECT3DDEVICE9 Direct3DDevice;
	std::vector<Control> ControlList;
	LPD3DXFONT g_pTextUI;

};
