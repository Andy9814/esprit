#include <windows.h>


// Design  window procdure 
LRESULT CALLBACK MainWindowCallBack(
  HWND   Hwindow,
  UINT   message,
  WPARAM WParam,
  LPARAM LParam
){
	LRESULT result = 0;
	switch(message)
	{
	 	case WM_SIZE:
	 	{
	 		OutputDebugStringA("WA_SIZE\n");

	 	}break;
	 	case WM_DESTROY:
	 	{
	 		OutputDebugStringA("WM_DESTROY\n");

	 	}break;

	 	case WM_CLOSE:
	 	{
	 OutputDebugStringA("WM_CLOSE\n");

	 	}break;
	
	 	case WM_ACTIVATEAPP:
	 	{
	 OutputDebugStringA("WM_ACTIVATEAPP\n");
	 	}break;
		 case WM_PAINT:
		 {
		 	PAINTSTRUCT  paint;
		 	HDC DeviceContext = BeginPaint(Hwindow, &paint);
			 static DWORD  operation = WHITENESS;
		 	PatBlt(DeviceContext,
			 paint.rcPaint.left,
			 paint.rcPaint.top,
			 paint.rcPaint.right - paint.rcPaint.left,
				paint.rcPaint.bottom - paint.rcPaint.top,
			 operation);
			if(operation == WHITENESS){
				operation = BLACKNESS;
			}
			else{
				operation   = WHITENESS;
			}
		 	EndPaint(Hwindow, &paint);
		 }
	
		default : {
			
			result = DefWindowProc(Hwindow,message,WParam,LParam);

		}break;

		
	}
	return result;
	

}

int CALLBACK WinMain
(
	HINSTANCE Instance,
	HINSTANCE PrevInstance,
	LPSTR     commandLine,
	int       showCode)

{

// this is my window clas  structure 
// wnd class
// typedef struct tagWNDCLASS {
//   UINT      style;
//   WNDPROC   lpfnWndProc;
//   int       cbClsExtra;
//   int       cbWndExtra;
//   HINSTANCE hInstance;
//   HICON     hIcon;
//   HCURSOR   hCursor;
//   HBRUSH    hbrBackground;
//   LPCTSTR   lpszMenuName;
//   LPCTSTR   lpszClassName;
// } WNDCLASS, *PWNDCLASS;

// create a window class 
	WNDCLASS windowClass = {};
  windowClass.style =CS_OWNDC|CS_HREDRAW|CS_VREDRAW ;
 windowClass.lpfnWndProc = MainWindowCallBack;// this is window procedure
  windowClass.hInstance = Instance;
  windowClass.lpszClassName = "AndyGameWindowClass";


// Create window prototype
// HWND WINAPI CreateWindowEx(
//   _In_     DWORD     dwExStyle,
//   _In_opt_ LPCTSTR   lpClassName,
//   _In_opt_ LPCTSTR   lpWindowName,
//   _In_     DWORD     dwStyle,
//   _In_     int       x,
//   _In_     int       y,
//   _In_     int       nWidth,
//   _In_     int       nHeight,
//   _In_opt_ HWND      hWndParent,
//   _In_opt_ HMENU     hMenu,
//   _In_opt_ HINSTANCE hInstance,
//   _In_opt_ LPVOID    lpParam
// );
// Register the window class 
	if(RegisterClass(&windowClass))
	{
	HWND windowHandle = CreateWindowEx
	(
	    	/*DWORD     dwExStyle,*/         0,
            /*LPCTSTR   lpClassName,*/     windowClass.lpszClassName,
			/*LPCTSTR   lpWindowName,*/    "Andy's Game",
			/*DWORD     dwStyle,*/         WS_OVERLAPPEDWINDOW|WS_VISIBLE,
			/*int       x,*/               CW_USEDEFAULT,
			/*int       y,*/               CW_USEDEFAULT,
			/*int       nWidth,*/          CW_USEDEFAULT,
			/*int       nHeight,*/         CW_USEDEFAULT,
			/*HWND      hWndParent,*/      0,
			/*HMENU     hMenu,*/           0,
			/*HINSTANCE hInstance,*/       Instance,
			/*LPVOID    lpParam*/          0
	);

	// if function succed return HWND else null
	if(windowHandle)
	{
		MSG Wmessage;

		for(;;)
		{
			if(GetMessage(&Wmessage,0,0,0 > 0))
			{
			TranslateMessage(&Wmessage);
			DispatchMessage(&Wmessage);
			}
		else
			{
			break;
			}

		}
	}
	else
	{

	}


	}
	else
	{

	}



  return 0; 

}

