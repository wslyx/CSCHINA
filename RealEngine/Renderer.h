#pragma once
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#include<d3d9.h>
#include<d3dx9.h>
#include<Windows.h>
#include"defines.h"
#include"Control.h"
#include"Renderer.h"

class RenderInterface
{
public:
    RenderInterface() : ScreenWidth(0), ScreenHeight(0), Near(0), Far(0), MainWindow(NULL), FullScreen(0), ClearColor(NULL), Direct3DObject(NULL), Direct3DDevice(NULL){ }
    virtual ~RenderInterface() {}

    virtual bool Initialize(int w, int h, HWND mainWin, bool fullScreen) = 0;
    virtual void OneTimeInit() = 0;
    virtual void Shutdown() = 0;
    virtual void SetClearColor(float r, float g, float b) = 0;
    virtual void StartRender(bool bColor, bool bDepth, bool bStencil) = 0;
    virtual void SetClearFlags(bool bColor, bool bDepth, bool bStencil) = 0;
    virtual void EndRendering() = 0;
    virtual void CalculateProjMatrix(float fov, float n, float f) = 0;
    virtual void CalculateOrthoMatrix(float n, float f) = 0;
    virtual int CreateStaticBuffer(VertexType, PrimType, int totalVerts, int totalIndices, int stride, void** data, unsigned int* indices, int* staticId) = 0;
    virtual int Render(int staticId) = 0;

protected:
    int ScreenWidth;
    int ScreenHeight;
    HWND MainWindow;//主窗口句柄
    bool FullScreen;//是否全屏
    D3DCOLOR ClearColor;//清屏颜色
    LPDIRECT3D9 Direct3DObject;//D3D对象
    LPDIRECT3DDEVICE9 Direct3DDevice;//D3D设备

    float Near;
    float Far;
};

class Renderer : public RenderInterface
{
private:
    bool IsRenderedScene;
    LPD3DXFONT g_pTextUI = NULL;
    ControlManager *g_pManager;
	
public:
	Renderer();
	~Renderer();

    void OneTimeInit();
	bool Initialize(int w, int h, HWND mainWin, bool fullScreen); //填充窗口数据，并获得设备参数

    void Shutdown();

    void SetClearColor(float r, float g, float b);
    void StartRender(bool bColor, bool bDepth, bool bStencil);
    void SetClearFlags(bool bColor, bool bDepth, bool bStencil);
    void EndRendering();

    void CalculateProjMatrix(float fov, float n, float f);
    void CalculateOrthoMatrix(float n, float f);

    int CreateStaticBuffer(VertexType, PrimType, int totalVerts, int totalIndices, int stride, void** data, unsigned int* indices, int* staticId);

    int Render(int staticId);
};