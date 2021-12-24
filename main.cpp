#include <iostream>
#include <cmath> 
#include <Windows.h>

#define ID_TIMER 2

using namespace std;

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdline, int iCmdShow)
{
    static TCHAR szAppName[] = TEXT("Bounce");
    HWND hWnd;//窗口句柄
    MSG mSg;//消息结构体
    //创建窗口类
    WNDCLASSEX wndClass;
 
    //设置窗口类各类属性
    wndClass.cbSize = sizeof(WNDCLASSEX);//设置窗口类结构体大小
    wndClass.cbClsExtra = 0;//窗口类尾部的一部分额外的空间
    wndClass.cbWndExtra = 0;
    wndClass.hInstance = hInstance;//应用程序当前的实例句柄
    wndClass.hCursor = LoadCursor(NULL, IDC_HELP);
    wndClass.hIcon = NULL;
    wndClass.hIconSm = NULL;
    wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndClass.lpfnWndProc = WndProc;//回调函数的地址（窗口消息处理程序）
    wndClass.lpszClassName = szAppName;//窗口类的名字，也就是窗口的标识，后面用于创建窗口函数的参数。
    wndClass.lpszMenuName = NULL;//菜单的名字，没有为NULL。
    wndClass.style = CS_HREDRAW | CS_VREDRAW;//窗口类的样式，它的值可以是窗口样式值的任意组合。CS_HREDRAW  CS_VREDRAW，这个是垂直刷新和水平刷新，窗口尺寸改变，重画活动区域。
 
    //注册对话框类
    if (!RegisterClassEx(&wndClass))
    {
        DWORD error_code = GetLastError();
        MessageBox(NULL, TEXT("This program requires Windows NT!"), TEXT("NumRain"), MB_ICONERROR | MB_OKCANCEL);
        return 0;
    }
 
    hWnd = CreateWindow(szAppName, TEXT("The Hello Program"), WS_OVERLAPPEDWINDOW, 200, 200, 800, 500, NULL, NULL, hInstance, NULL);
 
    ShowWindow(hWnd, iCmdShow);
    UpdateWindow(hWnd);
    while (GetMessage(&mSg, NULL, 0, 0))
    {
        TranslateMessage(&mSg);
        DispatchMessage(&mSg);
    }
    return (int)mSg.wParam;
}
 
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc,hdcMem;
    HBRUSH hBrush;
    int iScale;
    static HBITMAP hBitmap;
    static int cxClient, cyClient,xCenter,yCenter,cxTotal,cyTotal,cxRadius,cyRadius,cxMove,cyMove,xPixel,yPixel;
    switch (message)
    {
    case WM_CREATE:
        //初始化数据
        hdc = GetDC(hwnd);
        xPixel = GetDeviceCaps(hdc, ASPECTX);//36
        yPixel = GetDeviceCaps(hdc, ASPECTY);//36
        ReleaseDC(hwnd, hdc);
 
        SetTimer(hwnd, ID_TIMER, 0, NULL);
        return 0;
    case WM_SIZE:
        //客户区中心的坐标
        xCenter = (cxClient = LOWORD(lParam)) / 2;//392
        yCenter = (cyClient = HIWORD(lParam)) / 2;//230
 
        iScale = min(cxClient*xPixel, cyClient*yPixel) / 16;//1037
 
        //球水平的半径和垂直的半径
        cxRadius = iScale / xPixel;//28
        cyRadius = iScale / yPixel;//28
 
        //球水平的半径的一半和垂直的半径的一半
        cxMove = max(1, cxRadius / 2);//14
        cyMove = max(1, cyRadius / 2);//14
 
        //位图宽和高
        cxTotal = 2 * (cxRadius + cxMove);//84
        cyTotal = 2 * (cyRadius + cyMove);//84
 
        if (hBitmap)
        {
            DeleteObject(hBitmap);
        }
 
        hdc = GetDC(hwnd);
        //创建内存设备环境
        hdcMem = CreateCompatibleDC(hdc);
        //创建与客户区兼容的GDI位图对象，该位图宽为cxTotal，高为cyTotal
        hBitmap = CreateCompatibleBitmap(hdc, cxTotal, cyTotal);
        ReleaseDC(hwnd, hdc);
 
        //将GDI位图对象选入内存设备环境，扩大了显示表面
        SelectObject(hdcMem, hBitmap);
        //矩形的边框被绘制在位图之外
        Rectangle(hdcMem, -1, -1, cxTotal + 1, cyTotal + 1);
        //创建阴影画刷
        hBrush = CreateHatchBrush(HS_DIAGCROSS, 0L);
        SelectObject(hdcMem, hBrush);
        //设置阴影画刷间隔的空白处为紫色
        SetBkColor(hdcMem, RGB(255, 0, 255));
        /*
        将小球绘制在位图的中心
        值得注意的是，阴影画刷和阴影间隙的紫色效果都是在Rectangle函数之后，说明只有球才有阴影画刷和紫色间隙，而球外面的边空还是白色的。
        */
        Ellipse(hdcMem, cxMove, cyMove, cxTotal - cxMove, cyTotal - cyMove);
        DeleteDC(hdcMem);
        DeleteObject(hBrush);
        return 0;
    case WM_TIMER:
        if (!hBitmap)
        {
            break;
        }
 
        hdc = GetDC(hwnd);
        //创建内存设备环境
        hdcMem = CreateCompatibleDC(hdc);
        //将绘制好的位图对象选入内存设备环境
        SelectObject(hdcMem, hBitmap);
 
        //如果画图细心分析，会发现位图中心，水平和垂直每移动cxMove个像素，都会有新的位图覆盖上一个位图的球，这就不会出现球的残影了
        BitBlt(hdc, xCenter - cxTotal / 2, yCenter - cyTotal / 2, cxTotal, cyTotal, hdcMem, 0, 0, SRCCOPY);
        ReleaseDC(hwnd, hdc);
        DeleteDC(hdcMem);
 
        xCenter += cxMove;
        yCenter += cyMove;
 
        //客户区左右两边的碰撞检测
        if ((xCenter + cxRadius >= cxClient) || (xCenter - cxRadius <= 0))
        {
            //将小球反弹回去
            cxMove = -cxMove;
        }
        if ((yCenter + cyRadius >= cyClient) || (yCenter - cyRadius <= 0))
        {
            //将小球反弹回去
            cyMove = -cyMove;
        }
        return 0;
 
    case WM_CLOSE:
        if (IDOK == MessageBox(hwnd, TEXT("是否退出？"), TEXT("对话框"), MB_OKCANCEL | MB_DEFBUTTON1 | MB_ICONQUESTION))
        {
            DestroyWindow(hwnd);
        }
        else
        {
            return 0;
        }
    case WM_DESTROY:
        if (hBitmap)
        {
            DeleteObject(hBitmap);
        }
        KillTimer(hwnd, ID_TIMER);
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, message, wParam, lParam);
}
