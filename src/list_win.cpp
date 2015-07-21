//============================================================================
// Name        : list_win.cpp
// Author      : Makowiec
// Version     : 0.1
// Copyright   : IC
// Description : Program do tworzenia listy plików wersja okienkowa, Ansi-style
//============================================================================
#include <windows.h>
#include <windowsx.h>
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

HWND hWnd; // uchwyt na okno rodzica
HWND g_hRamka1; //ramka 1
HWND hComboBox1; //ComboBox 1 - "Nazwa"
HWND hComboBox2; //ComboBox 2 - "ID"
HWND hComboBox3; //ComboBox 3 - "Rok"
HWND hComboBox4; //ComboBox 4 - "Miesi¹c"

CHAR szClassName[]="OknoRodzica";
HINSTANCE* hInst; //globalny wskaŸnik na uchwyt naszego programu

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

//INT WINAPI WinMain(HINSTANCE hInstance,HINSTANCE,LPSTR lStart,INT nShow)
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{

	hInst=&hInstance; //pobieramy uchwyt programu do globalnego wskaŸnika

	//tworzenie okna rodzica

	  WNDCLASSEX wc;
	  wc.hInstance=*hInst; //u¿ywamy globalnego wskaŸnika

	  wc.lpszClassName=szClassName; //Nazwa klasy, któr¹ tworzymy
	  wc.lpfnWndProc=WndProc; //WskaŸnik do procedury obs³uguj¹cej okno
	  wc.style=0; //style klasy
	  wc.cbSize=sizeof(WNDCLASSEX); //Rozmiar struktury w bajtach
	  wc.hIcon=LoadIcon(NULL,IDI_APPLICATION); //Ikonka okna. Dok³adniej: du¿a ikonka, widaæ j¹ kiedy naciœniesz Alt-Tab
	  wc.hIconSm=LoadIcon(NULL,IDI_APPLICATION); //Ma³a ikonka naszej aplikacji. Widaæ j¹ w rogu naszego okienka oraz na pasku zadañ
	  wc.hCursor=LoadCursor(NULL,IDC_ARROW); //Kursor myszki
	  wc.lpszMenuName=NULL; //Nazwa identyfikuj¹ca menu naszego okna w pliku zasobów
	  wc.cbClsExtra=0; //Dodatkowe bajty pamiêci dla klasy
	  wc.cbWndExtra=0; //Dodatkowe bajty pamiêci dla klasy
	  wc.hbrBackground=(HBRUSH)(COLOR_WINDOW+1); //T³o naszego okienka, czyli jego kolor i wzór

	  // REJESTROWANIE KLASY OKNA
	  if( !RegisterClassEx( & wc ) )
	  {
		  MessageBox( NULL, "Okno nie zosta³o zarejestrowane", "Do poprawy",
	      MB_ICONEXCLAMATION | MB_OK );
	      return 1;
	  }
	  // TWORZENIE OKNA
	  hWnd=CreateWindowEx(
			  WS_EX_CLIENTEDGE,
			  szClassName,
			  "KC List",
			  WS_OVERLAPPEDWINDOW,
			  CW_USEDEFAULT,
			  CW_USEDEFAULT,
			  800,
			  400,
			  NULL,
			  NULL,
			  hInstance,
			  NULL
			  );
	  // Tworzenie ramki 1
	  g_hRamka1=CreateWindowEx(0,"BUTTON","Zmienne",WS_CHILD | WS_VISIBLE | BS_GROUPBOX,30,30,350,250,hWnd,(HMENU) 1,*hInst,NULL);

	  // Text do Combobox 1 - Nazwa
	  HWND hStaticText1=CreateWindowEx(0,"STATIC",NULL,WS_CHILD | WS_VISIBLE | SS_LEFT,50,60,75,20,hWnd,NULL,*hInst,NULL);
	  SetWindowText( hStaticText1, " Nazwa: " );

	  // Text do Combobox 2 - ID
	  HWND hStaticText2=CreateWindowEx(0,"STATIC",NULL,WS_CHILD | WS_VISIBLE | SS_LEFT,50,110,75,20,hWnd,NULL,*hInst,NULL);
	  SetWindowText( hStaticText2, " ID:" );

	  // Text do Combobox 3 - Rok
	  HWND hStaticText3=CreateWindowEx(0,"STATIC",NULL,WS_CHILD | WS_VISIBLE | SS_LEFT,50,160,75,20,hWnd,NULL,*hInst,NULL);
	  SetWindowText( hStaticText3, " Rok: " );

	  // Text do Combobox 4 - Miesi¹c
	  HWND hStaticText4=CreateWindowEx(0,"STATIC",NULL,WS_CHILD | WS_VISIBLE | SS_LEFT,50,210,75,20,hWnd,NULL,*hInst,NULL);
	  SetWindowText( hStaticText4, " Miesi¹c: " );

	  if( hWnd == NULL )
	  {
		  MessageBox(NULL,"Okno odmówi³o przyjœcia na œwiat!", "Ale kicha...", MB_ICONEXCLAMATION);
		  return 1;
	  }

	  ShowWindow(hWnd,nCmdShow);
	  MSG msgs;
	  while(GetMessage(&msgs,0,0,0))
	  {
		  TranslateMessage(&msgs);
	      DispatchMessage(&msgs);
	    }
	    return msgs.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	static int cb_1_1;
	static int cb_1_2;
	//static int cb_2_1;
	//static int cb_2_2;


	switch( msg )
    {
    case WM_CREATE:

    	//ComboBox1
    	//tworzenie ComboBox1
    	hComboBox1=CreateWindowEx(WS_EX_CLIENTEDGE,"COMBOBOX",NULL,WS_CHILD | WS_VISIBLE | WS_BORDER | CBS_DROPDOWNLIST | CBS_DROPDOWN,150,60,150,200,hWnd,NULL,*hInst,NULL);
    	//dodawanie pozycji dla ComboBox1
    	cb_1_1=SendMessage(hComboBox1, CB_ADDSTRING,0, (LPARAM)"Radom");
    	cb_1_2=SendMessage(hComboBox1, CB_ADDSTRING,0, (LPARAM)"Nysa");

    	//ComboBox2
    	//tworzenie ComboBox2
    	hComboBox2=CreateWindowEx(WS_EX_CLIENTEDGE,"COMBOBOX",NULL,WS_CHILD | WS_VISIBLE | WS_BORDER | CBS_DROPDOWNLIST | CBS_DROPDOWN,150,110,150,200,hWnd,NULL,*hInst,NULL);

    	//ComboBox3
    	//tworzenie ComboBox3
    	hComboBox3=CreateWindowEx(WS_EX_CLIENTEDGE,"COMBOBOX",NULL,WS_CHILD | WS_VISIBLE | WS_BORDER | CBS_DROPDOWN,150,160,150,200,hWnd,NULL,*hInst,NULL);

    	//ComboBox4
    	//tworzenie ComboBox4
    	hComboBox4=CreateWindowEx(WS_EX_CLIENTEDGE,"COMBOBOX",NULL,WS_CHILD | WS_VISIBLE | WS_BORDER | CBS_DROPDOWNLIST | CBS_DROPDOWN,150,210,150,250,hWnd,NULL,*hInst,NULL);

    	break;

    case WM_COMMAND:

    	if (lParam == (LPARAM)hComboBox1 && HIWORD (wParam) == CBN_SELENDOK)
    	{
    	int iIndex = SendMessage(hComboBox1, CB_GETCURSEL, 0, 0);

    		if (cb_1_1 == iIndex)
    		{
    			//dodawanie pozycji dla combobo 2
    			SendMessage(hComboBox2, CB_RESETCONTENT,0,0);
    			SendMessage(hComboBox2, CB_ADDSTRING,0, (LPARAM)"R01");
    			SendMessage(hComboBox2, CB_ADDSTRING,0, (LPARAM)"R02");
    			//dodawanie pozycji dla combobo 3
    			SendMessage(hComboBox3, CB_RESETCONTENT,0,0);
    	    	SendMessage(hComboBox3, CB_ADDSTRING,0, (LPARAM)"2010");
    	    	SendMessage(hComboBox3, CB_ADDSTRING,0, (LPARAM)"2011");
    	    	SendMessage(hComboBox3, CB_ADDSTRING,0, (LPARAM)"2012");
    	    	SendMessage(hComboBox3, CB_ADDSTRING,0, (LPARAM)"2013");
    	    	SendMessage(hComboBox3, CB_ADDSTRING,0, (LPARAM)"2014");
    	    	SendMessage(hComboBox3, CB_ADDSTRING,0, (LPARAM)"2015");
    			//dodawanie pozycji dla combobo 4
    			SendMessage(hComboBox4, CB_RESETCONTENT,0,0);
    			SendMessage(hComboBox4, CB_ADDSTRING,0, (LPARAM)"01");
    			SendMessage(hComboBox4, CB_ADDSTRING,0, (LPARAM)"02");
    			SendMessage(hComboBox4, CB_ADDSTRING,0, (LPARAM)"03");
    			SendMessage(hComboBox4, CB_ADDSTRING,0, (LPARAM)"04");
    			SendMessage(hComboBox4, CB_ADDSTRING,0, (LPARAM)"05");
    			SendMessage(hComboBox4, CB_ADDSTRING,0, (LPARAM)"06");
    			SendMessage(hComboBox4, CB_ADDSTRING,0, (LPARAM)"07");
    			SendMessage(hComboBox4, CB_ADDSTRING,0, (LPARAM)"08");
    			SendMessage(hComboBox4, CB_ADDSTRING,0, (LPARAM)"09");
    			SendMessage(hComboBox4, CB_ADDSTRING,0, (LPARAM)"10");
    			SendMessage(hComboBox4, CB_ADDSTRING,0, (LPARAM)"11");
    			SendMessage(hComboBox4, CB_ADDSTRING,0, (LPARAM)"12");
    		}
    		if (cb_1_2 == iIndex)
    		{
    			//dodawanie pozycji dla combobo 2
    			SendMessage(hComboBox2, CB_RESETCONTENT,0,0);
    			SendMessage(hComboBox2, CB_ADDSTRING,0, (LPARAM)"N01");
    			SendMessage(hComboBox2, CB_ADDSTRING,0, (LPARAM)"N02");
    			//dodawanie pozycji dla combobo 3
    			SendMessage(hComboBox3, CB_RESETCONTENT,0,0);
    	    	SendMessage(hComboBox3, CB_ADDSTRING,0, (LPARAM)"2010");
    	    	SendMessage(hComboBox3, CB_ADDSTRING,0, (LPARAM)"2011");
    	    	SendMessage(hComboBox3, CB_ADDSTRING,0, (LPARAM)"2012");
    	    	SendMessage(hComboBox3, CB_ADDSTRING,0, (LPARAM)"2013");
    	    	SendMessage(hComboBox3, CB_ADDSTRING,0, (LPARAM)"2014");
    	    	SendMessage(hComboBox3, CB_ADDSTRING,0, (LPARAM)"2015");
    			//dodawanie pozycji dla combobo 4
    			SendMessage(hComboBox4, CB_RESETCONTENT,0,0);
    			SendMessage(hComboBox4, CB_ADDSTRING,0, (LPARAM)"01*");
    			SendMessage(hComboBox4, CB_ADDSTRING,0, (LPARAM)"02*");
    			SendMessage(hComboBox4, CB_ADDSTRING,0, (LPARAM)"03*");
    			SendMessage(hComboBox4, CB_ADDSTRING,0, (LPARAM)"04*");
    			SendMessage(hComboBox4, CB_ADDSTRING,0, (LPARAM)"05*");
    			SendMessage(hComboBox4, CB_ADDSTRING,0, (LPARAM)"06*");
    			SendMessage(hComboBox4, CB_ADDSTRING,0, (LPARAM)"07*");
    			SendMessage(hComboBox4, CB_ADDSTRING,0, (LPARAM)"08*");
    			SendMessage(hComboBox4, CB_ADDSTRING,0, (LPARAM)"09*");
    			SendMessage(hComboBox4, CB_ADDSTRING,0, (LPARAM)"10*");
    			SendMessage(hComboBox4, CB_ADDSTRING,0, (LPARAM)"11*");
    			SendMessage(hComboBox4, CB_ADDSTRING,0, (LPARAM)"12*");
    		}
    	}
    	break;
    /*case WM_PAINT:
    {

    }
        break;
	*/
    case WM_CLOSE:
        DestroyWindow( hWnd );
        break;

    case WM_DESTROY:
        PostQuitMessage( 0 );
        break;

        default:
        return DefWindowProc( hWnd, msg, wParam, lParam );
    }

    return 0;
}
