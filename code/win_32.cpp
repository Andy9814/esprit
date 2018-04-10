#include <windows.h>




LRESULT CALLBACK MainWindowCallBack(
  HWND   window,
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
	
		default : {
			
			result = DefWindowProc(window,message,WParam,LParam);

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

// this is my window clas 
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

  WNDCLASS windowClass;
	windowClass.style =CS_OWNDC|CS_HREDRAW|CS_VREDRAW ;
	windowClass.lpfnWndProc = MainWindowCallBack;
  windowClass.hInstance = Instance;
  windowClass.lpszClassName = "AndyGameWindowClass";

	if(RegisterClass(&windowClass)){
		HWND windowHandle = CreateWindowEx(
  _In_opt_ LPCTSTR   lpClassName,
  _In_opt_ LPCTSTR   lpWindowName,
  _In_     DWORD     dwStyle,
  _In_     int       x,
  _In_     int       y,
  _In_     int       nWidth,
  _In_     int       nHeight,
  _In_opt_ HWND      hWndParent,
  _In_opt_ HMENU     hMenu,
  _In_opt_ HINSTANCE hInstance,
  _In_opt_ LPVOID    lpParam
);
)
	}
	else{

	}



  return (0); 

}

