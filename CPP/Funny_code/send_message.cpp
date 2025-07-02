#define UNICODE
#define _UNICODE

#include <windows.h>
#include <iostream>
#include <string>
#include <thread>

const std::wstring QQ_GROUP_WINDOW_TITLE = L"弘茗智能科技有限公司"; 
const std::wstring MESSAGE = L"Test";
const int HOUR = 8;
const int MINUTE = 30;

void sendMessageToQQGroup() {
    HWND hwnd = FindWindow(NULL, QQ_GROUP_WINDOW_TITLE.c_str());
    if (!hwnd) {
        std::wcerr << L"Can't find the windows: " << QQ_GROUP_WINDOW_TITLE << std::endl;
        return;
    }

    SetForegroundWindow(hwnd);
    Sleep(500);

    OpenClipboard(0);
    EmptyClipboard();
    HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, (MESSAGE.size() + 1) * sizeof(wchar_t));
    if (!hg) return;
    memcpy(GlobalLock(hg), MESSAGE.c_str(), (MESSAGE.size() + 1) * sizeof(wchar_t));
    GlobalUnlock(hg);
    SetClipboardData(CF_UNICODETEXT, hg);
    CloseClipboard();

    keybd_event(VK_CONTROL, 0, 0, 0);
    keybd_event('V', 0, 0, 0);
    keybd_event('V', 0, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
    Sleep(100);


    keybd_event(VK_RETURN, 0, 0, 0);
    keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);

    std::wcout << L"Message have been send" << std::endl;
}

void timerLoop() {
    while (true) {
        SYSTEMTIME time;
        GetLocalTime(&time);
        if (time.wHour == HOUR && time.wMinute == MINUTE) {
            sendMessageToQQGroup();
            Sleep(60000); 
        }
        Sleep(10000); 
    }
}

int main() {
    std::wcout << L"Starting..." << std::endl;
    std::thread timer(timerLoop);
    timer.join();
    return 0;
}
