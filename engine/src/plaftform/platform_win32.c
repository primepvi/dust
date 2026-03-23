#include "platform.h"

#if CB_PLATFORM == CB_PLATFORM_WINDOWS

#include <windows.h>
#include <windowsx.h>

typedef struct {
    HINSTANCE instance;
    HWND handle;
} PlatformStateBuffer;

b8 platform_init(PlatformState *state, const char *name, i32 width, i32 height) {
    PlatformStateBuffer *buffer = malloc(sizeof(PlatformStateBuffer));
    state->buffer = buffer;

    buffer->instance = GetModuleHandleA(0);

    WNDCLASSA wc;
    memset(&wc, 0, sizeof(wc));
    wc.style = CS_DBLCLKS;
    wc.lpfnWndProc = NULL;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = buffer->instance;
    wc.hIcon = NULL;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = NULL;
    wc.lpszClassName = "carbon_window_class";

    if (!RegisterClassA(&wc)) {
        MessageBoxA(0, "Window registration failed.", "Error", MB_ICONERROR | MB_OK);
        return false;
    }

    MessageBoxA(0, "Window registration success.", "OK", MB_ICONASTERISK | MB_OK);
    return true;
}

#endif