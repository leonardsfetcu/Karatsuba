// KaratsubaMultiplier.cpp : Defines the entry point for the application.
//



#include "stdafx.h"
#include "Header.h"


#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name
HWND g_hToolbar = NULL;
HWND text_box, ButtonDif, ButtonFact,
window1, window2,
ButtonC, ButtonD, ButtonSum, ButtonM;

HWND nr1, nr2, operationWindow, operationText;

int *buff1_int, *buff2_int, digits, operation;
TCHAR *buff;
// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	SubSub(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	ToolDlgProc(HWND, UINT, WPARAM, LPARAM);





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
	buff1_int = (int*)malloc(2000 * sizeof(int));
	buff2_int = (int*)malloc(2000 * sizeof(int));
	buff = (TCHAR*)malloc(2000 * sizeof(TCHAR));


	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_KARATSUBAMULTIPLIER, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
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

	return (int)msg.wParam;
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

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_KARATSUBAMULTIPLIER));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_KARATSUBAMULTIPLIER);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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


	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPED | WS_MINIMIZEBOX | WS_SYSMENU,
		CW_USEDEFAULT, 0, 760, 300, NULL, NULL, hInstance, NULL);
	//  SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE)&~WS_SIZEBOX);
	text_box = CreateWindow(
		L"EDIT",  // Predefined class; Unicode assumed 
		L"",      // Button text 
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT | ES_READONLY | ES_NUMBER,  // Styles 
		80,         // x position 
		100,         // y position 
		500,        // Button width
		70,        // Button height
		hWnd,     // Parent window
		NULL,       // No menu.
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		NULL);      // Pointer not needed.

	nr1 = CreateWindow(
		L"EDIT",  // Predefined class; Unicode assumed 
		L"",      // Button text 
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT | ES_NUMBER,  // Styles 
		80,         // x position 
		20,         // y position 
		500,        // Button width
		20,        // Button height
		hWnd,     // Parent window
		NULL,       // No menu.
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		NULL);      // Pointer not needed.

	operationWindow = CreateWindow(
		L"EDIT",  // Predefined class; Unicode assumed 
		L"",      // Button text 
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_CENTER | ES_READONLY,  // Styles 
		550,         // x position 
		45,         // y position 
		30,        // Button width
		20,        // Button height
		hWnd,     // Parent window
		NULL,       // No menu.
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		NULL);      // Pointer not needed.

	window1 = CreateWindow(
		L"EDIT",  // Predefined class; Unicode assumed 
		L"Numarul 1:",      // Button text 
		WS_CHILD | WS_VISIBLE | ES_CENTER | ES_READONLY,  // Styles 
		5,         // x position 
		20,         // y position 
		70,        // Button width
		20,        // Button height
		hWnd,     // Parent window
		NULL,       // No menu.
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		NULL);      // Pointer not needed.

	window2 = CreateWindow(
		L"EDIT",  // Predefined class; Unicode assumed 
		L"Numarul 2:",      // Button text 
		WS_CHILD | WS_VISIBLE | ES_CENTER | ES_READONLY,  // Styles 
		5,         // x position 
		70,         // y position 
		70,        // Button width
		20,        // Button height
		hWnd,     // Parent window
		NULL,       // No menu.
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		NULL);      // Pointer not needed.


	operationText = CreateWindow(
		L"EDIT",  // Predefined class; Unicode assumed 
		L"Operator",      // Button text 
		WS_CHILD | WS_VISIBLE | ES_CENTER | ES_NUMBER | ES_READONLY,  // Styles 
		480,         // x position 
		45,         // y position 
		60,        // Button width
		20,        // Button height
		hWnd,     // Parent window
		NULL,       // No menu.
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		NULL);      // Pointer not needed.


	nr2 = CreateWindow(
		L"EDIT",  // Predefined class; Unicode assumed 
		L"",      // Button text 
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT | ES_NUMBER,  // Styles 
		80,         // x position 
		70,         // y position 
		500,        // Button width
		20,        // Button height
		hWnd,     // Parent window
		NULL,       // No menu.
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		NULL);      // Pointer not needed.




	ButtonSum = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"+",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		600,         // x position 
		40,         // y position 
		35,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		NULL,       // No menu.
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		NULL);      // Pointer not needed.
	ButtonDif = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"-",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		650,         // x position 
		40,         // y position 
		35,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		NULL,       // No menu.
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		NULL);      // Pointer not needed.
	ButtonM = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"x",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		700,         // x position 
		40,         // y position 
		35,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		NULL,       // No menu.
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		NULL);      // Pointer not needed.


	ButtonC = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"C",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		600,         // x position 
		80,         // y position 
		35,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		NULL,       // No menu.
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		NULL);      // Pointer not needed.
	ButtonFact = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"!",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		650,         // x position 
		80,         // y position 
		35,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		NULL,       // No menu.
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		NULL);      // Pointer not needed.

	ButtonD = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"<--",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		700,         // x position 
		80,         // y position 
		35,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		NULL,       // No menu.
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		NULL);      // Pointer not needed.


	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	//  UpdateWindow(hWnd);

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
		wmId = LOWORD(wParam);
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

			if (lParam == (LPARAM)ButtonC)
			{

				SetWindowText(text_box, L"");
				SetWindowText(nr1, L"");
				SetWindowText(nr2, L"");
				SetWindowText(operationWindow, L"");
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

				SetWindowText(operationWindow, L"+");
				GetWindowText(nr1, buff, 200);

				if (wcslen(buff))
				{
					buff1_int[0] = wcslen(buff);

					for (int i = 0; i < wcslen(buff); i++)
					{
						buff1_int[i + 1] = buff[i] - '0';
					}



					GetWindowText(nr2, buff, 200);

					if (wcslen(buff))
					{

						buff2_int[0] = wcslen(buff);

						for (i = 0; i < wcslen(buff); i++)
							buff2_int[i + 1] = buff[i] - '0';

						SetWindowText(text_box, L"");

						value = Sum(buff1_int, buff2_int);

						if (value != NULL)
						{
							value = Cleaner(value);

							for (i = 1; i <= value[0]; i++)
								buff[i - 1] = value[i] + '0';


							buff[i - 1] = '\0';
							SetWindowText(text_box, buff);
						}
						buff1_int = value;
					}
					else {
						SetWindowText(text_box, L"Introduceti mai intai datele de intrare in campurile 'Numarul 1' si 'Numarul 2' ");
					}

				}
				else {
					SetWindowText(text_box, L"Introduceti mai intai datele de intrare in campurile 'Numarul 1' si 'Numarul 2'");
				}


			}

			if (lParam == (LPARAM)ButtonM)
			{

				SetWindowText(operationWindow, L"x");
				GetWindowText(nr1, buff, 200);

				if (wcslen(buff))
				{
					buff1_int[0] = wcslen(buff);

					for (int i = 0; i < wcslen(buff); i++)
					{
						buff1_int[i + 1] = buff[i] - '0';
					}



					GetWindowText(nr2, buff, 200);

					if (wcslen(buff))
					{

						buff2_int[0] = wcslen(buff);

						for (i = 0; i < wcslen(buff); i++)
							buff2_int[i + 1] = buff[i] - '0';

						SetWindowText(text_box, L"");

						value = Multiplier(buff1_int, buff2_int, DigitsNumber(buff1_int[0], buff2_int[0]));

						if (value != NULL)
						{
							value = Cleaner(value);

							for (i = 1; i <= value[0]; i++)
								buff[i - 1] = value[i] + '0';


							buff[i - 1] = '\0';
							SetWindowText(text_box, buff);
						}
						buff1_int = value;
					}
					else {
						SetWindowText(text_box, L"Introduceti mai intai datele de intrare in campurile 'Numarul 1' si 'Numarul 2' ");
					}

				}
				else {
					SetWindowText(text_box, L"Introduceti mai intai datele de intrare in campurile 'Numarul 1' si 'Numarul 2'");
				}


			}

			if (lParam == (LPARAM)ButtonFact)
			{
				operation = 4;
				SetWindowText(operationWindow, L"!");
				GetWindowText(nr1, buff, 200);

				if (wcslen(buff))
				{
					buff1_int[0] = wcslen(buff);

					for (int i = 0; i < wcslen(buff); i++)
					{
						buff1_int[i + 1] = buff[i] - '0';
					}

					value = factorial(buff1_int);

					if (value != NULL)
					{
						value = Cleaner(value);

						for (i = 1; i <= value[0]; i++)
							buff[i - 1] = value[i] + '0';


						buff[i - 1] = '\0';
						SetWindowText(text_box, buff);
					}
				}
				else {
					SetWindowText(text_box, L"Introduceti datele doar in campul 'Numarul 1'");
				}
			}

			if (lParam == (LPARAM)ButtonDif)
			{
				SetWindowText(operationWindow, L"-");
				GetWindowText(nr1, buff, 200);

				if (wcslen(buff))
				{
					buff1_int[0] = wcslen(buff);

					for (int i = 0; i < wcslen(buff); i++)
					{
						buff1_int[i + 1] = buff[i] - '0';
					}



					GetWindowText(nr2, buff, 200);

					if (wcslen(buff))
					{

						buff2_int[0] = wcslen(buff);

						for (i = 0; i < wcslen(buff); i++)
							buff2_int[i + 1] = buff[i] - '0';

						SetWindowText(text_box, L"");

						value = Diff(buff1_int, buff2_int);

						if (value != NULL)
						{
							value = Cleaner(value);

							for (i = 1; i <= value[0]; i++)
								buff[i - 1] = value[i] + '0';


							buff[i - 1] = '\0';


							SetWindowText(text_box, buff);
						}
						buff1_int = value;
					}
					else {
						SetWindowText(text_box, L"Introduceti mai intai datele de intrare in campurile 'Numarul 1' si 'Numarul 2' ");
					}

				}
				else {
					SetWindowText(text_box, L"Introduceti mai intai datele de intrare in campurile 'Numarul 1' si 'Numarul 2'");
				}


			}


		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
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