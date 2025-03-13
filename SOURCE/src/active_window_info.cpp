#include "active_window_info.h"
#include <windows.h>

namespace godot {

Dictionary ActiveWindowInfo::get_active_window_info() {
    Dictionary result;

    // Get the handle of the active window
    HWND hwnd = GetForegroundWindow();
    if (hwnd == NULL) {
        return result;
    }

    // Get the window title
    char title[256];
    GetWindowTextA(hwnd, title, sizeof(title));
    result["title"] = String(title);

    // Get the window position and size
    RECT rect;
    if (GetWindowRect(hwnd, &rect)) {
        result["x"] = rect.left;
        result["y"] = rect.top;
        result["width"] = rect.right - rect.left;
        result["height"] = rect.bottom - rect.top;
    }

    return result;
}

void ActiveWindowInfo::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_active_window_info"), &ActiveWindowInfo::get_active_window_info);
}

} // namespace godot