// ClockWidget.hpp
#pragma once
#include <windows.h>

/*
 * The state of the widget is stored here, it only stores the font information for now.
 * Each widget gets its own state object with its own Font Data.
 */
struct WidgetState {
    HFONT DayFont;
    HFONT TimeFont;
};

// I do realize that WidgetState is probably overkill for just "one" widget,
// but on paper this makes mroe sense to me than `static DayFont`
// and leave everything to the global scope.

/*
 * @brief The Event Handler for the Widget
 *
 * This function handles each Windows Event (like Create Window, Paint Window,
 * Left Mouse button clicked on Window, etc.).
 *
 * Each HWND (window) will store a pointer to its own WidgetState via GWLP_USERDATA,
 * essentially storing a pointer to WidgetState object inside HWND's user data.
 *
 * Usually it's termed as WindowProc as in "Windows Procedure"; procedure == function.
 * But that's stupid in my honest opinion, no offense to anceint coding practices.
 *
 */
LRESULT CALLBACK WidgetHandler(HWND window, UINT event, WPARAM wparam, LPARAM lparam);
