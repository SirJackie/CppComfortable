#include <iostream>
#include <cmath> 
#include <Windows.h>

#define ID_TIMER 2

using namespace std;

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdline, int iCmdShow)
{
    static TCHAR szAppName[] = TEXT("Bounce");
    HWND hWnd;//���ھ��
    MSG mSg;//��Ϣ�ṹ��
    //����������
    WNDCLASSEX wndClass;
 
    //���ô������������
    wndClass.cbSize = sizeof(WNDCLASSEX);//���ô�����ṹ���С
    wndClass.cbClsExtra = 0;//������β����һ���ֶ���Ŀռ�
    wndClass.cbWndExtra = 0;
    wndClass.hInstance = hInstance;//Ӧ�ó���ǰ��ʵ�����
    wndClass.hCursor = LoadCursor(NULL, IDC_HELP);
    wndClass.hIcon = NULL;
    wndClass.hIconSm = NULL;
    wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndClass.lpfnWndProc = WndProc;//�ص������ĵ�ַ��������Ϣ�������
    wndClass.lpszClassName = szAppName;//����������֣�Ҳ���Ǵ��ڵı�ʶ���������ڴ������ں����Ĳ�����
    wndClass.lpszMenuName = NULL;//�˵������֣�û��ΪNULL��
    wndClass.style = CS_HREDRAW | CS_VREDRAW;//���������ʽ������ֵ�����Ǵ�����ʽֵ��������ϡ�CS_HREDRAW  CS_VREDRAW������Ǵ�ֱˢ�º�ˮƽˢ�£����ڳߴ�ı䣬�ػ������
 
    //ע��Ի�����
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
        //��ʼ������
        hdc = GetDC(hwnd);
        xPixel = GetDeviceCaps(hdc, ASPECTX);//36
        yPixel = GetDeviceCaps(hdc, ASPECTY);//36
        ReleaseDC(hwnd, hdc);
 
        SetTimer(hwnd, ID_TIMER, 0, NULL);
        return 0;
    case WM_SIZE:
        //�ͻ������ĵ�����
        xCenter = (cxClient = LOWORD(lParam)) / 2;//392
        yCenter = (cyClient = HIWORD(lParam)) / 2;//230
 
        iScale = min(cxClient*xPixel, cyClient*yPixel) / 16;//1037
 
        //��ˮƽ�İ뾶�ʹ�ֱ�İ뾶
        cxRadius = iScale / xPixel;//28
        cyRadius = iScale / yPixel;//28
 
        //��ˮƽ�İ뾶��һ��ʹ�ֱ�İ뾶��һ��
        cxMove = max(1, cxRadius / 2);//14
        cyMove = max(1, cyRadius / 2);//14
 
        //λͼ��͸�
        cxTotal = 2 * (cxRadius + cxMove);//84
        cyTotal = 2 * (cyRadius + cyMove);//84
 
        if (hBitmap)
        {
            DeleteObject(hBitmap);
        }
 
        hdc = GetDC(hwnd);
        //�����ڴ��豸����
        hdcMem = CreateCompatibleDC(hdc);
        //������ͻ������ݵ�GDIλͼ���󣬸�λͼ��ΪcxTotal����ΪcyTotal
        hBitmap = CreateCompatibleBitmap(hdc, cxTotal, cyTotal);
        ReleaseDC(hwnd, hdc);
 
        //��GDIλͼ����ѡ���ڴ��豸��������������ʾ����
        SelectObject(hdcMem, hBitmap);
        //���εı߿򱻻�����λͼ֮��
        Rectangle(hdcMem, -1, -1, cxTotal + 1, cyTotal + 1);
        //������Ӱ��ˢ
        hBrush = CreateHatchBrush(HS_DIAGCROSS, 0L);
        SelectObject(hdcMem, hBrush);
        //������Ӱ��ˢ����Ŀհ״�Ϊ��ɫ
        SetBkColor(hdcMem, RGB(255, 0, 255));
        /*
        ��С�������λͼ������
        ֵ��ע����ǣ���Ӱ��ˢ����Ӱ��϶����ɫЧ��������Rectangle����֮��˵��ֻ���������Ӱ��ˢ����ɫ��϶����������ı߿ջ��ǰ�ɫ�ġ�
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
        //�����ڴ��豸����
        hdcMem = CreateCompatibleDC(hdc);
        //�����ƺõ�λͼ����ѡ���ڴ��豸����
        SelectObject(hdcMem, hBitmap);
 
        //�����ͼϸ�ķ������ᷢ��λͼ���ģ�ˮƽ�ʹ�ֱÿ�ƶ�cxMove�����أ��������µ�λͼ������һ��λͼ������Ͳ��������Ĳ�Ӱ��
        BitBlt(hdc, xCenter - cxTotal / 2, yCenter - cyTotal / 2, cxTotal, cyTotal, hdcMem, 0, 0, SRCCOPY);
        ReleaseDC(hwnd, hdc);
        DeleteDC(hdcMem);
 
        xCenter += cxMove;
        yCenter += cyMove;
 
        //�ͻ����������ߵ���ײ���
        if ((xCenter + cxRadius >= cxClient) || (xCenter - cxRadius <= 0))
        {
            //��С�򷴵���ȥ
            cxMove = -cxMove;
        }
        if ((yCenter + cyRadius >= cyClient) || (yCenter - cyRadius <= 0))
        {
            //��С�򷴵���ȥ
            cyMove = -cyMove;
        }
        return 0;
 
    case WM_CLOSE:
        if (IDOK == MessageBox(hwnd, TEXT("�Ƿ��˳���"), TEXT("�Ի���"), MB_OKCANCEL | MB_DEFBUTTON1 | MB_ICONQUESTION))
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
