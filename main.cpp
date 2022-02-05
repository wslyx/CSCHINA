/*
   Demo Name:  Game Project 1
      Author:  Allen Sherrod
     Chapter:  Chapter 2
*/

#include <Windows.h>
#include"main.h"


// Globals...
HWND g_hwnd;


LRESULT WINAPI MsgProc(HWND hd, UINT msg, WPARAM wp, LPARAM lp)
{
    switch (msg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
        break;

    case WM_KEYUP:
        if (wp == VK_ESCAPE) PostQuitMessage(0);
        break;
    }

    return DefWindowProc(hd, msg, wp, lp);
}

ATOM RegisterMyClass(HINSTANCE hInstance)
{
    WNDCLASS wc;

    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = static_cast<WNDPROC>(MsgProc);
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(0, IDI_APPLICATION);
    wc.hCursor = LoadCursor(0, IDC_ARROW);
    wc.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
    wc.lpszMenuName = nullptr;
    wc.lpszClassName = L"CS::CHINA";

    return RegisterClass(&wc);
}

INT WINAPI WinMain(_In_ HINSTANCE hInstance,_In_opt_ HINSTANCE hPrevInstance,_In_ LPSTR lpCmdLine,_In_ int nShowCmd)
{
    // 注册窗口类
    if (!RegisterMyClass(hInstance))
    {
        MessageBox(nullptr, L"RegisterClass() - FAILED", nullptr, 0);
        return 0;
    }

    g_hwnd = CreateWindow(L"StrendedGame",
        WINDOW_NAME,
        WS_POPUP|WS_EX_TOPMOST,
        CW_USEDEFAULT, CW_USEDEFAULT, WIN_WIDTH, WIN_HEIGHT,
        nullptr /*parent hwnd*/, nullptr /* menu */, hInstance, nullptr /*extra*/);

    if (!g_hwnd)
    {
        MessageBox(nullptr, L"CreateWindow() - FAILED", nullptr, 0);
        return 0;
    }
    //居中窗口
    int scrWidth, scrHeight;
    RECT rect;
    scrWidth = GetSystemMetrics(SM_CXSCREEN);
    scrHeight = GetSystemMetrics(SM_CYSCREEN);
    GetWindowRect(g_hwnd, &rect);
    SetWindowPos(g_hwnd, HWND_TOPMOST, (scrWidth - rect.right) / 2, (scrHeight - rect.bottom) / 2, rect.right - rect.left, rect.bottom - rect.top, SWP_SHOWWINDOW);

    if (g_hwnd)
    {
        // Show the window
        ShowWindow(g_hwnd, SW_SHOWDEFAULT);
        UpdateWindow(g_hwnd);
    }

    // Initialize the Stranded Engine.
    if (InitializeEngine())
    {
        // Initialize Stranded game.
        if (GameInitialize())
        {
            // Enter the message loop
            MSG msg;
            ZeroMemory(&msg, sizeof(msg));

            //SetCursorPos(0, 0);

            while (msg.message != WM_QUIT)
            {
                if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
                {
                    TranslateMessage(&msg);
                    DispatchMessage(&msg);
                }
                else
                    GameLoop();
            }
        }
    }

    // Release any and all resources.
    GameShutdown();
    ShutdownEngine();

    //UnregisterClass(WINDOW_CLASS, wc.hInstance);
    return 0;
}


bool InitializeEngine()
{
    if (!CreateD3DRenderer(&g_Render)) return false;

    if (!g_Render->Initialize(WIN_WIDTH, WIN_HEIGHT, g_hwnd, FULLSCREEN)) return false;

    g_Render->SetClearCol(0, 100, 0);

    return true;
}


void ShutdownEngine()
{
    if (g_Render)
    {
        g_Render->Shutdown();
        delete g_Render;
        g_Render = NULL;
    }
}


bool GameInitialize()
{
    return true;
}


void GameLoop()
{
    if (!g_Render) return;

    g_Render->StartRender(1, 1, 0);

    g_Render->EndRendering();
}


void GameShutdown()
{

}