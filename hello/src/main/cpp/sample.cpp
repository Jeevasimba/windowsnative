#define WINVER 0x0500
#include <Windows.h>
#include <pdh.h>
#include "tchar.h"

#include <array>
#include <iostream>
#include <string>
#include <stdexcept>

#include "stdlib.h"


using namespace std;

void sendSpecialKeyEvent(DWORD flags, WORD key)
{
    INPUT ip;
    ZeroMemory(&ip, sizeof(ip));
    ip.type = INPUT_KEYBOARD;
    ip.ki.time = 0;
    ip.ki.dwFlags = flags;
    ip.ki.wScan = MapVirtualKey(key, MAPVK_VK_TO_VSC);
    ip.ki.wVk = key;

    ip.ki.dwExtraInfo = 0;
    SendInput(1, &ip, sizeof(INPUT));
}

void sendMouseEvent(DWORD flags, LONG dx, LONG dy, DWORD mouseData)
{
    INPUT input;
    ZeroMemory(&input, sizeof(input));
    input.type = INPUT_MOUSE;
    input.mi.mouseData = mouseData;
    input.mi.dx = dx;
    input.mi.dy = dy;
    input.mi.dwFlags = flags;

    SendInput(1, &input, sizeof(input));
}