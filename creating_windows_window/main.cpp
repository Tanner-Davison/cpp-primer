#include <iostream>
#include <windows.h>
/*in order to compile this code use the following command:
*
g++ -g -O0 -std=c++2b -Wall -Wextra main.cpp -o main -lgdi32 -luser32

**/

// Window procedure - handles messages sent to your window
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam,
                            LPARAM lParam) {
  switch (uMsg) {
  case WM_DESTROY:
    PostQuitMessage(0);
    return 0;

  case WM_PAINT: {
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hwnd, &ps);

    // Draw something simple
    TextOut(hdc, 20, 20, "Hello, Windows API!", 19);

    // Draw a rectangle
    Rectangle(hdc, 50, 50, 200, 100);

    EndPaint(hwnd, &ps);
    return 0;
  }

  case WM_LBUTTONDOWN: {
    // Handle left mouse click
    int x = LOWORD(lParam);
    int y = HIWORD(lParam);

    // Show message box with click coordinates
    char buffer[100];
    sprintf(buffer, "You clicked at (%d, %d)", x, y);
    MessageBox(hwnd, buffer, "Mouse Click", MB_OK);
    return 0;
  }

  case WM_KEYDOWN:
    if (wParam == VK_ESCAPE) {
      // Close window when ESC is pressed
      DestroyWindow(hwnd);
    }
    return 0;
  }

  return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int main() {
  // Step 1: Get the application instance
  HINSTANCE hInstance = GetModuleHandle(NULL);

  // Step 2: Register a window class
  const char *CLASS_NAME = "MyWindowClass";

  WNDCLASS wc = {};
  wc.lpfnWndProc = WindowProc;                   // Our window procedure
  wc.hInstance = hInstance;                      // Application instance
  wc.lpszClassName = CLASS_NAME;                 // Class name
  wc.hCursor = LoadCursor(NULL, IDC_ARROW);      // Default cursor
  wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); // Background color
  wc.style = CS_HREDRAW | CS_VREDRAW;            // Window style

  // Register the window class
  if (!RegisterClass(&wc)) {
    MessageBox(NULL, "Failed to register window class!", "Error", MB_ICONERROR);
    return -1;
  }

  // Step 3: Create the window using CreateWindowA
  HWND hwnd = CreateWindowA(
      CLASS_NAME,          // lpClassName - the class we registered
      "My Awesome Window", // lpWindowName - window title
      WS_OVERLAPPEDWINDOW, // dwStyle - window style (standard window)
      100,                 // x - horizontal position
      100,                 // y - vertical position
      800,                 // nWidth - window width
      600,                 // nHeight - window height
      NULL,                // hWndParent - parent window (none)
      NULL,                // hMenu - menu handle (none)
      hInstance,           // hInstance - application instance
      NULL                 // lpParam - additional data (none)
  );

  // Check if window creation failed
  if (hwnd == NULL) {
    MessageBox(NULL, "Failed to create window!", "Error", MB_ICONERROR);
    return -1;
  }

  // Step 4: Show and update the window
  ShowWindow(hwnd, SW_SHOW);
  UpdateWindow(hwnd);

  std::cout << "Window created successfully! Close it to continue...\n";

  // Step 5: Message loop - keeps the window alive
  MSG msg = {};
  while (GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  std::cout << "Window closed. Program ending.\n";
  return 0;
}

/*
PARAMETER BREAKDOWN:

lpClassName:  "MyWindowClass" - Must match registered class name
lpWindowName: "My Awesome Window" - Text shown in title bar
dwStyle:      WS_OVERLAPPEDWINDOW - Standard window with title bar, borders,
etc. x, y:         100, 100 - Window position on screen (pixels from top-left)
nWidth:       800 - Window width in pixels
nHeight:      600 - Window height in pixels
hWndParent:   NULL - No parent window (top-level window)
hMenu:        NULL - No menu bar
hInstance:    hInstance - Handle to our application
lpParam:      NULL - No extra creation data

COMMON WINDOW STYLES (dwStyle):
- WS_OVERLAPPEDWINDOW: Standard window (title bar, borders, min/max buttons)
- WS_POPUP: Popup window (no title bar)
- WS_CHILD: Child window (must have parent)
- WS_VISIBLE: Window is initially visible
- WS_MINIMIZE: Window starts minimized
- WS_MAXIMIZE: Window starts maximized

You can combine styles with | operator:
WS_OVERLAPPEDWINDOW | WS_VISIBLE
*/
