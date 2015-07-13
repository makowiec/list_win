//============================================================================
// Name        : list.cpp
// Author      : Makowiec
// Version     : 0.1
// Copyright   : IC
// Description : Program do tworzenia listy plik�w wersja okienkowa, Ansi-style
//				 Pliki mniejsze ni� 1TB
//============================================================================

#include <windows.h>

LPCSTR NazwaKlasy = "Klasa Okna";
MSG Komunikat; //zmienan do przechwytywania komunikat�w
HWND g_hPrzycisk1; //przycisk 1
HWND g_hRamka1; //ramka 1
HWND g_hComboBox1; //ComboBox 1 - Nazwa
HWND g_hStaticText1; //StaticText 1 - Nazwa
HWND g_hComboBox2; //ComboBox 2 - ID
HWND g_hStaticText2; //StaticText 2 - ID
HWND g_hComboBox3; //ComboBox 3 - rok
HWND g_hStaticText3; //StaticText 3 - rok
HWND g_hComboBox4; //ComboBox 4 - miesi�c
HWND g_hStaticText4; //StaticText 4 - miesi�c

LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam );

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{

    // WYPE�NIANIE STRUKTURY
    WNDCLASSEX wc;

    wc.cbSize = sizeof( WNDCLASSEX ); //Rozmiar struktury w bajtach
    wc.style = 0; //style klasy
    wc.lpfnWndProc = WndProc; //Wska�nik do procedury obs�uguj�cej okno
    wc.cbClsExtra = 0; //Dodatkowe bajty pami�ci dla klasy
    wc.cbWndExtra = 0; //Dodatkowe bajty pami�ci dla klasy
    wc.hInstance = hInstance; //Identyfikator aplikacji, kt�ra ma by� w�a�cicielem okna
    wc.hIcon = LoadIcon( NULL, IDI_APPLICATION ); //Ikonka okna. Dok�adniej: du�a ikonka, wida� j� kiedy naci�niesz Alt-Tab
    wc.hCursor = LoadCursor( NULL, IDC_ARROW ); //Kursor myszki
    wc.hbrBackground =( HBRUSH )( COLOR_WINDOW + 1 ); //T�o naszego okienka, czyli jego kolor i wz�r
    wc.lpszMenuName = NULL; //Nazwa identyfikuj�ca menu naszego okna w pliku zasob�w
    wc.lpszClassName = NazwaKlasy; //Nazwa klasy, kt�r� tworzymy
    wc.hIconSm = LoadIcon( NULL, IDI_APPLICATION ); //Ma�a ikonka naszej aplikacji. Wida� j� w rogu naszego okienka oraz na pasku zada�

    // REJESTROWANIE KLASY OKNA
    if( !RegisterClassEx( & wc ) )
    {
        MessageBox( NULL, "Okno nie zosta�o zarejestrowane", "Do poprawy",
        MB_ICONEXCLAMATION | MB_OK );
        return 1;
    }

    // TWORZENIE OKNA
    HWND hwnd;

    hwnd = CreateWindowEx( WS_EX_CLIENTEDGE, NazwaKlasy, "KC List", WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, CW_USEDEFAULT, 800, 400, NULL, NULL, hInstance, NULL );

    	// Tworzenie ramki 1
    	g_hRamka1 = CreateWindowEx( 0, "BUTTON", "Zmienne", WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
    	30, 30, 350, 250, hwnd, NULL, hInstance, NULL );

    		// ComboBox1 - Nazwa
    		HWND hComboBox1 = CreateWindowEx( WS_EX_CLIENTEDGE, "COMBOBOX", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER |
    		CBS_DROPDOWN, 150, 60, 150, 200, hwnd, NULL, hInstance, NULL );
    			SendMessage( hComboBox1, CB_ADDSTRING, 0,( LPARAM ) "Radom" );
    			SendMessage( hComboBox1, CB_ADDSTRING, 0,( LPARAM ) "Nysa" );

    				// StaticText1 - Nazwa
    				HWND hStaticText1 = CreateWindowEx( 0, "STATIC", NULL, WS_CHILD | WS_VISIBLE |
    				SS_LEFT, 50, 60, 75, 20, hwnd, NULL, hInstance, NULL );
    					SetWindowText( hStaticText1, " Nazwa: " );

    		// ComboBox2 - ID
    		HWND hComboBox2 = CreateWindowEx( WS_EX_CLIENTEDGE, "COMBOBOX", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER |
    		CBS_DROPDOWN, 150, 110, 150, 200, hwnd, NULL, hInstance, NULL );
    			SendMessage( hComboBox2, CB_ADDSTRING, 0,( LPARAM ) "R001" );
    			SendMessage( hComboBox2, CB_ADDSTRING, 0,( LPARAM ) "N002" );

    				// StaticText2 - ID
    				HWND hStaticText2 = CreateWindowEx( 0, "STATIC", NULL, WS_CHILD | WS_VISIBLE |
    				SS_LEFT, 50, 110, 75, 20, hwnd, NULL, hInstance, NULL );
    					SetWindowText( hStaticText2, " ID:" );

    		// ComboBox3 - rok
    		HWND hComboBox3 = CreateWindowEx( WS_EX_CLIENTEDGE, "COMBOBOX", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER |
    		CBS_DROPDOWN, 150, 160, 150, 200, hwnd, NULL, hInstance, NULL );
    			SendMessage( hComboBox3, CB_ADDSTRING, 0,( LPARAM ) "2010" );
    			SendMessage( hComboBox3, CB_ADDSTRING, 0,( LPARAM ) "2011" );
    			SendMessage( hComboBox3, CB_ADDSTRING, 0,( LPARAM ) "2012" );
    			SendMessage( hComboBox3, CB_ADDSTRING, 0,( LPARAM ) "2013" );
    			SendMessage( hComboBox3, CB_ADDSTRING, 0,( LPARAM ) "2014" );
    			SendMessage( hComboBox3, CB_ADDSTRING, 0,( LPARAM ) "2015" );

    				// StaticText3 - rok
    				HWND hStaticText3 = CreateWindowEx( 0, "STATIC", NULL, WS_CHILD | WS_VISIBLE |
    				SS_LEFT, 50, 160, 75, 20, hwnd, NULL, hInstance, NULL );
    					SetWindowText( hStaticText3, " Rok: " );

    		// ComboBox4 - miesi�c
    		HWND hComboBox4 = CreateWindowEx( WS_EX_CLIENTEDGE, "COMBOBOX", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER |
    		CBS_DROPDOWN, 150, 210, 150, 250, hwnd, NULL, hInstance, NULL );
    			SendMessage( hComboBox4, CB_ADDSTRING, 0,( LPARAM ) "ALL" );
    			SendMessage( hComboBox4, CB_ADDSTRING, 0,( LPARAM ) "01" );
    			SendMessage( hComboBox4, CB_ADDSTRING, 0,( LPARAM ) "02" );
    			SendMessage( hComboBox4, CB_ADDSTRING, 0,( LPARAM ) "03" );
    			SendMessage( hComboBox4, CB_ADDSTRING, 0,( LPARAM ) "04" );
    			SendMessage( hComboBox4, CB_ADDSTRING, 0,( LPARAM ) "05" );
    			SendMessage( hComboBox4, CB_ADDSTRING, 0,( LPARAM ) "06" );
    			SendMessage( hComboBox4, CB_ADDSTRING, 0,( LPARAM ) "07" );
    			SendMessage( hComboBox4, CB_ADDSTRING, 0,( LPARAM ) "08" );
    			SendMessage( hComboBox4, CB_ADDSTRING, 0,( LPARAM ) "09" );
    			SendMessage( hComboBox4, CB_ADDSTRING, 0,( LPARAM ) "10" );
    			SendMessage( hComboBox4, CB_ADDSTRING, 0,( LPARAM ) "11" );
    			SendMessage( hComboBox4, CB_ADDSTRING, 0,( LPARAM ) "12" );

    				// StaticText4 - miesi�c
    				HWND hStaticText4 = CreateWindowEx( 0, "STATIC", NULL, WS_CHILD | WS_VISIBLE |
    				SS_LEFT, 50, 210, 75, 20, hwnd, NULL, hInstance, NULL );
    					SetWindowText( hStaticText4, " Miesi�c: " );

    // Tworzenie przycisku 1
    g_hPrzycisk1 = CreateWindowEx( 0, "BUTTON", "Tworzenie listy", WS_CHILD | WS_VISIBLE,
    50, 300, 150, 30, hwnd, NULL, hInstance, NULL );


    if( hwnd == NULL )
    {
        MessageBox( NULL, "Okno odm�wi�o przyj�cia na �wiat!", "Ale kicha...", MB_ICONEXCLAMATION );
        return 1;
    }

    ShowWindow( hwnd, nCmdShow ); // Poka� okienko...
    UpdateWindow( hwnd );

    // Obsluga komunikat�w komunikat�w
    while( GetMessage( & Komunikat, NULL, 0, 0 ) )
    {
        TranslateMessage( & Komunikat );
        DispatchMessage( & Komunikat );
    }

    return Komunikat.wParam;
}

// OBS�UGA ZDARZE�
LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
    switch( msg )
    {
    case WM_CLOSE:
        DestroyWindow( hwnd );
        break;

    case WM_DESTROY:
        PostQuitMessage( 0 );
        break;

    case WM_COMMAND:
    if(( HWND ) lParam == g_hPrzycisk1 )
         MessageBox( hwnd, "Rozpocz�to tworzenie listy plik�w", "Tworzenie listy", MB_ICONINFORMATION );

    break;
        default:
        return DefWindowProc( hwnd, msg, wParam, lParam );
    }

    return 0;
}
