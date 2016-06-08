// KaratsubaMultiplier.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "KaratsubaMultiplier.h"
#include "math.h"


#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name
HWND g_hToolbar = NULL;
HWND text_box, Button1, Button2, Button3, Button4, Button5, ButtonDif
, Button6, Button7, Button8, Button9, Button0,
ButtonC, ButtonD, ButtonSum, ButtonEq, ButtonM;

int *buff1_int, *buff2_int, operation,digits;
TCHAR *buff;
// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	SubSub(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	ToolDlgProc(HWND, UINT, WPARAM, LPARAM);

int* Copy_left(int *source);
int* Multiplier(int*, int*, int);
int* Copy_right(int *source);
int* Sum(int* x, int* y);
int* Shift(int *src, int poz);
int* rev(int *a);
int* Diff(int* a, int* b);
int Compare(int *a, int *b);
int* Cleaner(int *a);
int *ech(int *a, int n);
int DigitsNumber(int a, int b);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;
	buff1_int = (int*)malloc(200 * sizeof(int));
	buff2_int = (int*)malloc(200 * sizeof(int));
	buff = (TCHAR*)malloc(200 * sizeof(TCHAR));


	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_KARATSUBAMULTIPLIER, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_KARATSUBAMULTIPLIER));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_KARATSUBAMULTIPLIER));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_KARATSUBAMULTIPLIER);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable


   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 350, 450, NULL, NULL, hInstance, NULL);
   //text_box = CreateWindow(L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_AUTOHSCROLL | ES_WANTRETURN, 350, 470, 100, 50, hWnd, NULL, hInst, 0);

   text_box = CreateWindow(
	   L"EDIT",  // Predefined class; Unicode assumed 
	   L"",      // Button text 
	   WS_CHILD | WS_VISIBLE |WS_BORDER | ES_RIGHT | ES_READONLY,  // Styles 
	   50,         // x position 
	   100,         // y position 
	   200,        // Button width
	   35,        // Button height
	   hWnd,     // Parent window
	   NULL,       // No menu.
	   (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
	   NULL);      // Pointer not needed.
   
   

   Button1 = CreateWindow(
	   L"BUTTON",  // Predefined class; Unicode assumed 
	   L"1",      // Button text 
	   WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
	   50,         // x position 
	   150,         // y position 
	   45,        // Button width
	   35,        // Button height
	   hWnd,     // Parent window
	   NULL,       // No menu.
	   (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
	   NULL);      // Pointer not needed.

   Button2 = CreateWindow(
	   L"BUTTON",  // Predefined class; Unicode assumed 
	   L"2",      // Button text 
	   WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
	   95,         // x position 
	   150,         // y position 
	   45,        // Button width
	   35,        // Button height
	   hWnd,     // Parent window
	   NULL,       // No menu.
	   (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
	   NULL);      // Pointer not needed.

   Button3 = CreateWindow(
	   L"BUTTON",  // Predefined class; Unicode assumed 
	   L"3",      // Button text 
	   WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
	   140,         // x position 
	   150,         // y position 
	   45,        // Button width
	   35,        // Button height
	   hWnd,     // Parent window
	   NULL,       // No menu.
	   (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
	   NULL);      // Pointer not needed.
   ButtonSum = CreateWindow(
	   L"BUTTON",  // Predefined class; Unicode assumed 
	   L"+",      // Button text 
	   WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
	   185,         // x position 
	   150,         // y position 
	   45,        // Button width
	   35,        // Button height
	   hWnd,     // Parent window
	   NULL,       // No menu.
	   (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
	   NULL);      // Pointer not needed.
   ButtonEq = CreateWindow(
	   L"BUTTON",  // Predefined class; Unicode assumed 
	   L"=",      // Button text 
	   WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
	   185,         // x position 
	   185,         // y position 
	   45,        // Button width
	   35,        // Button height
	   hWnd,     // Parent window
	   NULL,       // No menu.
	   (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
	   NULL);      // Pointer not needed.
  
   Button4 = CreateWindow(
	   L"BUTTON",  // Predefined class; Unicode assumed 
	   L"4",      // Button text 
	   WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
	   50,         // x position 
	   185,         // y position 
	   45,        // Button width
	   35,        // Button height
	   hWnd,     // Parent window
	   NULL,       // No menu.
	   (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
	   NULL);      // Pointer not needed.

   Button5 = CreateWindow(
	   L"BUTTON",  // Predefined class; Unicode assumed 
	   L"5",      // Button text 
	   WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
	   95,         // x position 
	   185,         // y position 
	   45,        // Button width
	   35,        // Button height
	   hWnd,     // Parent window
	   NULL,       // No menu.
	   (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
	   NULL);      // Pointer not needed.

   Button6 = CreateWindow(
	   L"BUTTON",  // Predefined class; Unicode assumed 
	   L"6",      // Button text 
	   WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
	   140,         // x position 
	   185,         // y position 
	   45,        // Button width
	   35,        // Button height
	   hWnd,     // Parent window
	   NULL,       // No menu.
	   (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
	   NULL);      // Pointer not needed.

   Button7 = CreateWindow(
	   L"BUTTON",  // Predefined class; Unicode assumed 
	   L"7",      // Button text 
	   WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
	   50,         // x position 
	   220,         // y position 
	   45,        // Button width
	   35,        // Button height
	   hWnd,     // Parent window
	   NULL,       // No menu.
	   (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
	   NULL);      // Pointer not needed.

   Button8 = CreateWindow(
	   L"BUTTON",  // Predefined class; Unicode assumed 
	   L"8",      // Button text 
	   WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
	   95,         // x position 
	   220,         // y position 
	   45,        // Button width
	   35,        // Button height
	   hWnd,     // Parent window
	   NULL,       // No menu.
	   (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
	   NULL);      // Pointer not needed.

   Button9 = CreateWindow(
	   L"BUTTON",  // Predefined class; Unicode assumed 
	   L"9",      // Button text 
	   WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
	   140,         // x position 
	   220,         // y position 
	   45,        // Button width
	   35,        // Button height
	   hWnd,     // Parent window
	   NULL,       // No menu.
	   (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
	   NULL);      // Pointer not needed.
   ButtonDif = CreateWindow(
	   L"BUTTON",  // Predefined class; Unicode assumed 
	   L"-",      // Button text 
	   WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
	   185,         // x position 
	   220,         // y position 
	   45,        // Button width
	   35,        // Button height
	   hWnd,     // Parent window
	   NULL,       // No menu.
	   (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
	   NULL);      // Pointer not needed.
   ButtonC = CreateWindow(
	   L"BUTTON",  // Predefined class; Unicode assumed 
	   L"C",      // Button text 
	   WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
	   50,         // x position 
	   255,         // y position 
	   45,        // Button width
	   35,        // Button height
	   hWnd,     // Parent window
	   NULL,       // No menu.
	   (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
	   NULL);      // Pointer not needed.
   Button0 = CreateWindow(
	   L"BUTTON",  // Predefined class; Unicode assumed 
	   L"0",      // Button text 
	   WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
	   95,         // x position 
	   255,         // y position 
	   45,        // Button width
	   35,        // Button height
	   hWnd,     // Parent window
	   NULL,       // No menu.
	   (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
	   NULL);      // Pointer not needed.
   ButtonD = CreateWindow(
	   L"BUTTON",  // Predefined class; Unicode assumed 
	   L"Back",      // Button text 
	   WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
	   140,         // x position 
	   255,         // y position 
	   45,        // Button width
	   35,        // Button height
	   hWnd,     // Parent window
	   NULL,       // No menu.
	   (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
	   NULL);      // Pointer not needed.
   ButtonM = CreateWindow(
	   L"BUTTON",  // Predefined class; Unicode assumed 
	   L"*",      // Button text 
	   WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
	   185,         // x position 
	   255,         // y position 
	   45,        // Button width
	   35,        // Button height
	   hWnd,     // Parent window
	   NULL,       // No menu.
	   (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
	   NULL);      // Pointer not needed.

  

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	
	INT  *value, i;
	
	switch (message)
	{

	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
				
		case BN_CLICKED: 
			if (lParam == (LPARAM)Button1)
			{
				GetWindowText(text_box, buff, 200);
				wcscat(buff, L"1");
				SetWindowText(text_box, buff);
			}
			if (lParam == (LPARAM)Button2)
			{
				GetWindowText(text_box, buff, 200);
				wcscat(buff, L"2");
				SetWindowText(text_box, buff);
			}
			if (lParam == (LPARAM)Button3)
			{
				GetWindowText(text_box, buff, 200);
				wcscat(buff, L"3");
				SetWindowText(text_box, buff);
			}
			if (lParam == (LPARAM)Button4)
			{
				GetWindowText(text_box, buff, 200);
				wcscat(buff, L"4");
				SetWindowText(text_box, buff);
			}
			if (lParam == (LPARAM)Button5)
			{
				GetWindowText(text_box, buff, 200);
				wcscat(buff, L"5");
				SetWindowText(text_box, buff);
			}
			if (lParam == (LPARAM)Button6)
			{
				GetWindowText(text_box, buff, 200);
				wcscat(buff, L"6");
				SetWindowText(text_box, buff);
			}
			if (lParam == (LPARAM)Button7)
			{
				GetWindowText(text_box, buff, 200);
				wcscat(buff, L"7");
				SetWindowText(text_box, buff);
			}
			if (lParam == (LPARAM)Button8)
			{
				GetWindowText(text_box, buff, 200);
				wcscat(buff, L"8");
				SetWindowText(text_box, buff);
			}
			if (lParam == (LPARAM)Button9)
			{
				GetWindowText(text_box, buff, 200);
				wcscat(buff, L"9");
				SetWindowText(text_box, buff);
			}
			if (lParam == (LPARAM)Button0)
			{
				GetWindowText(text_box, buff, 200);
				wcscat(buff, L"0");
				SetWindowText(text_box, buff);
				
					
				
			}
			if (lParam == (LPARAM)ButtonC)
			{
				GetWindowText(text_box, buff, 200);
				wcscpy(buff, buff + wcslen(buff));
				SetWindowText(text_box, buff);
			}
			if (lParam == (LPARAM)ButtonD)
			{
				GetWindowText(text_box, buff, 200);
				wcsrev(buff);
				if (wcslen(buff) != 0)
				{
					wcscpy(buff, buff + 1);
					wcsrev(buff);
					SetWindowText(text_box, buff);
				}
			}
			if (lParam == (LPARAM)ButtonSum)
			{
				operation = 1;
				GetWindowText(text_box, buff, 200);

				buff1_int[0] = wcslen(buff);

				for (int i = 0; i < wcslen(buff); i++)
				{	
					buff1_int[i+1] = buff[i] - '0';
				}


				SetWindowText(text_box, L"");

			
			}
			if (lParam == (LPARAM)ButtonEq)
			{

				digits = DigitsNumber(buff1_int[0], buff2_int[0]);
					GetWindowText(text_box, buff, 200);
					buff2_int[0] = wcslen(buff);

					for (i = 0; i < wcslen(buff); i++)
						buff2_int[i + 1] = buff[i] - '0';
					
					switch (operation)
					{
					case 1: value = Sum(buff1_int, buff2_int);
						break;
					case 2: value = Diff(buff1_int, buff2_int);
						break;
					case 3: value = Multiplier(buff1_int, buff2_int, digits);
					default:
						break;
					}
						
						
					
						if (value != NULL)
						{
							value = Cleaner(value);

							for (i = 1; i <= value[0]; i++)
								buff[i - 1] = value[i] + '0';


							buff[i - 1] = '\0';
							SetWindowText(text_box, buff);
						}
						buff1_int=value;

				
					
			}
			if (lParam == (LPARAM)ButtonDif)
			{
				operation = 2;
				GetWindowText(text_box, buff, 200);

				buff1_int[0] = wcslen(buff);

				for (int i = 0; i < wcslen(buff); i++)
				{
					buff1_int[i + 1] = buff[i] - '0';
				}


				SetWindowText(text_box, L"");
			}
			if (lParam == (LPARAM)ButtonM)
			{
				operation = 3;
				GetWindowText(text_box, buff, 200);

				buff1_int[0] = wcslen(buff);

				for (int i = 0; i < wcslen(buff); i++)
				{
					buff1_int[i + 1] = buff[i] - '0';
				}


				SetWindowText(text_box, L"");
			}
			break;

		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

int DigitsNumber(int a, int b)
{
	double x = __max(a, b);
	double n = log2(x);

	if ((n - floor(n)) != 0)
		return pow(2.0, int(floor(n)) + 1);
	else return pow(2.0, int(floor(n)));
}
int *ech(int *a, int n)
{
	int *out;
	out = (int*)calloc(n + 1, sizeof(int));
	out[0] = n;

	for (int i = n - a[0] + 1; i <= n; i++)
		out[i] = a[i - (n - a[0])];

	return out;

}

int* rev(int *a)
{
	int *out;
	out = (int*)malloc(a[0] * sizeof(int));

	out[0] = a[0];

	for (int i = a[0]; i > 0; i--)
		out[out[0] - i + 1] = a[i];

	return out;
}

int* Diff(int* a, int* b)
{

	int *st, *nd, c, *out, carry;

	if (a[0] > b[0])

		b = Shift(b, b[0] - a[0]);
	else
		a = Shift(a, a[0] - b[0]);
	c = Compare(a, b);

	if (c == 1)
	{
		st = rev(a);
		nd = rev(b);
	}
	else
	{
		st = rev(b);
		nd = rev(a);
	}

	out = (int*)malloc((a[0] + 1)*sizeof(int));

	out[0] = a[0];

	carry = 0;

	for (int i = 1; i <= a[0]; i++)
	{


		if ((st[i] - nd[i]) < 0)
		{
			st[i + 1]--;
			carry = 10;
		}

		out[i] = st[i] - nd[i] + carry;

		carry = 0;

	}


	out = rev(out);
	out = Cleaner(out);
	return out;
}



int* Multiplier(int *x, int *y, int n)
{
	int *xl, *xr, *yl, *yr, *aux, d, *L, *R, *C, *P4, *rezultat;
	int x_y, len;
	x = ech(x, n);
	y = ech(y, n);
	if (n == 1)
	{
		x_y = x[1] * y[1];
		if (x_y > 10)
		{
			d = 1;
			len = 2;
		}
		else
		{
			d = 0;
			len = 1;

		}

		aux = (int*)malloc((len + 1)*sizeof(int));

		if (d){
			aux[0] = len;
			aux[1] = (x[1] * y[1]) / 10;
			aux[2] = (x[1] * y[1]) % 10;
		}
		else {

			aux[0] = len;
			aux[1] = x[1] * y[1];
		}

		return aux;

	}


	xl = Copy_left(x);
	xr = Copy_right(x);
	yl = Copy_left(y);
	yr = Copy_right(y);

	L = Multiplier(xl, yl, xl[0]);
	R = Multiplier(xr, yr, xr[0]);

	C = Multiplier(Sum(xr, xl), Sum(yr, yl), Sum(xr, xl)[0]);

	P4 = Diff(C, Sum(R, L));

	int * r1, *r2;

	r1 = Shift(L, n);
	r2 = Shift(P4, n / 2);
	rezultat = Sum(Sum(r1, r2), R);


	return rezultat;


}

int* Copy_left(int *source)
{
	int i, n, *out;
	n = source[0] / 2;

	out = (int*)malloc((n + 1)*sizeof(int));
	out[0] = n;

	for (i = 1; i <= n; i++)
		out[i] = source[i];

	return out;


}


int* Copy_right(int *source)
{
	int i, n, *out, start, nr;

	n = source[0] / 2;
	start = n + 1;
	nr = n;

	out = (int*)malloc((n + 1)*sizeof(int));

	out[0] = nr;

	for (i = start; i <= source[0]; i++)
	{
		out[i - start + 1] = source[i];
	}

	return out;


}
int* Sum(int* x, int* y)
{
	int k = 1;
	int carry, *aux = NULL, *sol, *a, *b;

	if (x[0] > y[0])

		y = Shift(y, y[0] - x[0]);
	else
		x = Shift(x, x[0] - y[0]);


	sol = (int*)calloc(x[0] + 2, sizeof(int));
	sol[0] = x[0] + 1;

	a = rev(x);
	b = rev(y);

	carry = 0;

	for (int i = 1; i <= a[0]; i++)
	{

		sol[i] = (a[i] + b[i] + carry) % 10;
		carry = (a[i] + b[i]) / 10;
	}

	if (carry) sol[sol[0]] = carry;
	else
	{
		sol = (int*)realloc(sol, (x[0] + 1)*sizeof(int));
		sol[0]--;

	}

	sol = rev(sol);
	//	sol = Cleaner(sol);

	return sol;





}

int* Shift(int *src, int poz)
{
	int aux, *out;
	/*
	if (src[0] == 1 && src[1] == 0)
	{
	return src;
	}
	*/
	out = (int*)calloc(src[0] + abs(poz) + 1, sizeof(int));
	out[0] = src[0] + abs(poz);

	if (poz > 0)
	{


		for (int i = 1; i <= src[0]; i++)
			out[i] = src[i];
	}
	else
	for (int i = abs(poz) + 1; i <= out[0]; i++)
		out[i] = src[i - abs(poz)];

	return out;
}

int Compare(int *a, int *b)  //return 0 => a == b // 1  => a > b // 2 => b > a
{
	if (a[0] > b[0]) return 1;
	else if (b[0] > a[0]) return 2;
	else if (a[0] == b[0])
	{
		for (int i = 1; i <= a[0]; i++)
		if (a[i] > b[i]) return 1;
		else if (b[i] > a[i]) return 2;
	}

	return 0;
}


int* Cleaner(int *a)
{
	int i = 1, *out;


	while ((a[i] == 0) && (i <= a[0]))
		i++;


	if (i == a[0] + 1)
	{
		out = (int*)malloc(2 * sizeof(int));
		out[0] = 1;
		out[1] = 0;
		return out;
	}


	out = (int*)malloc((a[0] - i + 2)*sizeof(int));
	out[0] = a[0] - i + 1;

	for (int j = i; j <= a[0]; j++)
		out[j - i + 1] = a[j];

	return out;

}