#include "ClockWidget.hpp"
#include <minwindef.h>
#include <windef.h>
#include <winuser.h>

// The main entry point for Win32 apps: WinMain
// @param instance: Handle to the executable, basically an identifer
// of our widget executable
int WINAPI WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int){

    // A name for our "window template". Do not ask why we need this,
    // it's probably what Windows uses to identify our widegt window.
    const wchar_t CLASS_NAME[] = L"NullWidget";        // Unicode btw

    // Apparently we are creating a template for our window
    // WNDCLASS creates a template for a window (just like how
    // a class is a template for an object, closest thing to
    // OOP in Windows API so far.)
    WNDCLASSW widgetTemplate = { };

    // We define what kind of window our window will be here
    widgetTemplate.lpfnWndProc = WidgetHandler;                                 //
    widgetTemplate.hInstance = instance;                                        //
    widgetTemplate.lpszClassName = CLASS_NAME;                                  //
    widgetTemplate.style = CS_HREDRAW | CS_VREDRAW;                             //
    widgetTemplate.hCursor = LoadCursor(NULL, IDC_ARROW);                       //
    widgetTemplate.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(20,20,20));     //

    // Now we register our template and now we can reference it by CLASS_NAME?
    RegisterClassW(&widgetTemplate);

    CreateWindowExW(
        WS_EX_TOOLWINDOW,           // Hide executable from taskbar
        CLASS_NAME, L"NullWidget",  // Use "this" template
        WS_POPUP | WS_VISIBLE,      // Borderless window to be shown after creation (same bit packing logic.. ig?)
        100, 100,                   // Initial X,Y coords
        250, 80,                    // Width and Height of the window in px
        NULL, NULL, instance, NULL  // NO.
    );
    // WS_EX_TOOLWINDOW  — hides it from the taskbar
    // WS_POPUP          — borderless window (no title bar, no frame)
    // WS_VISIBLE        — show immediately after creation
    // 100, 100          — initial x, y position on screen
    // 250, 80           — width, height in pixels

    // MSG holds one event from the Windows event queue, they said.
    // I think it's a "holder" for those events Windows works on,
    // you know.. those MACROS WHICH EXPANDS TO HEX.
    // It's a container for one of those events.
    MSG eventMsg = { };

    // The always on loop for our window for those messages
    // GetMessages gets those messages (see it wasn't hard to
    // properly name things microsoft.) and fills the event_msg
    // with that MACRO.
    while (GetMessageW(&eventMsg, NULL, 0, 0)) {

        //      TranslateMessage translates those Macros to
        //      meaningfull things I guess, I am assuming those
        //      numbers/codes are mapped to instructions/functions.
        //
        // Nope, that's wrong, it's more of a "specifier"? Like
        // it adds more details, why is it named translate?!?
        // And I won't use this atm, since I am not pressing
        // any keys or need to attach extra information, the
        // only complexity is dragging amd mouse click doesn't
        // need extra info.
        //
        // WE WILL NEED THIS, IF KEYBOARD gets involved though.
        // TranslateMessage(&eventMsg);

        // Send the message we stored to our "WidgetHandler"
        // cuz we need to spoonfeed these event messages windows
        // detected and created to our event handler we created
        DispatchMessageW(&eventMsg);
    }

    // I have given up on documenting this cleanly,
    // I am mad.

    return 0;
}

// I am so done with typedefs and exapands to hex
// In my honest opinion, WinAPI isn't bad, it's
// intutive.. just in a very ancient kind of way.
// Sighhh, why am I still using Windows!?
