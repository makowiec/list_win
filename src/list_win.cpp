//============================================================================
// Name        : list.cpp
// Author      : Makowiec
// Version     : 0.1
// Copyright   : IC
// Description : Program do tworzenia listy plików wersja okienkowa, Ansi-style
//				 Pliki mniejsze ni¿ 1TB
//============================================================================

#include <windows.h>
#include <Windowsx.h>
#include <string.h>

using namespace std;

LPCSTR NazwaKlasy = "Klasa Okna";
MSG Komunikat; //zmienan do przechwytywania komunikatów
HWND g_hPrzycisk1; //przycisk 1
HWND g_hRamka1; //ramka 1
HWND g_hComboBox1; //ComboBox 1 - Nazwa
HWND g_hStaticText1; //StaticText 1 - Nazwa
HWND g_hComboBox2; //ComboBox 2 - ID
HWND g_hStaticText2; //StaticText 2 - ID
HWND g_hComboBox3; //ComboBox 3 - rok
HWND g_hStaticText3; //StaticText 3 - rok
HWND g_hComboBox4; //ComboBox 4 - miesi¹c
HWND g_hStaticText4; //StaticText 4 - miesi¹c

LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam );

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{

    // WYPE£NIANIE STRUKTURY
    WNDCLASSEX wc;

    wc.cbSize = sizeof( WNDCLASSEX ); //Rozmiar struktury w bajtach
    wc.style = 0; //style klasy
    wc.lpfnWndProc = WndProc; //WskaŸnik do procedury obs³uguj¹cej okno
    wc.cbClsExtra = 0; //Dodatkowe bajty pamiêci dla klasy
    wc.cbWndExtra = 0; //Dodatkowe bajty pamiêci dla klasy
    wc.hInstance = hInstance; //Identyfikator aplikacji, która ma byæ w³aœcicielem okna
    wc.hIcon = LoadIcon( NULL, IDI_APPLICATION ); //Ikonka okna. Dok³adniej: du¿a ikonka, widaæ j¹ kiedy naciœniesz Alt-Tab
    wc.hCursor = LoadCursor( NULL, IDC_ARROW ); //Kursor myszki
    wc.hbrBackground =( HBRUSH )( COLOR_WINDOW + 1 ); //T³o naszego okienka, czyli jego kolor i wzór
    wc.lpszMenuName = NULL; //Nazwa identyfikuj¹ca menu naszego okna w pliku zasobów
    wc.lpszClassName = NazwaKlasy; //Nazwa klasy, któr¹ tworzymy
    wc.hIconSm = LoadIcon( NULL, IDI_APPLICATION ); //Ma³a ikonka naszej aplikacji. Widaæ j¹ w rogu naszego okienka oraz na pasku zadañ

    // REJESTROWANIE KLASY OKNA
    if( !RegisterClassEx( & wc ) )
    {
        MessageBox( NULL, "Okno nie zosta³o zarejestrowane", "Do poprawy",
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

    	//ComboBox - Nazwa

    		//ComboBox1 - tablica
    		const char *ComboBox1_text[] = { "Radom", "Nysa" };
    		// ComboBox1
    		HWND hComboBox1 = CreateWindowEx( WS_EX_CLIENTEDGE, "COMBOBOX", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | CBS_DROPDOWNLIST |
    		CBS_DROPDOWN, 150, 60, 150, 200, hwnd, NULL, hInstance, NULL );
    		for(int Count = 0; Count < 2; Count++)
            {
                SendMessage(hComboBox1, CB_ADDSTRING, 0, reinterpret_cast<LPARAM>((LPCTSTR)ComboBox1_text[Count]));
            }

    		// StaticText1
    		HWND hStaticText1 = CreateWindowEx( 0, "STATIC", NULL, WS_CHILD | WS_VISIBLE |
    		SS_LEFT, 50, 60, 75, 20, hwnd, NULL, hInstance, NULL );
    		SetWindowText( hStaticText1, " Nazwa: " );

    	// ComboBox2 - ID

    		//ComboBox2 - tablica
    		const char *ComboBox2_text[] = { "R001", "R002", "R003", "N001", "N002", "N003" };
    		// ComboBox2
    		HWND hComboBox2 = CreateWindowEx( WS_EX_CLIENTEDGE, "COMBOBOX", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | CBS_DROPDOWNLIST |
    		CBS_DROPDOWN, 150, 110, 150, 200, hwnd, NULL, hInstance, NULL );
    		for(int Count = 0; Count < 6; Count++)
    		{
    			SendMessage(hComboBox2, CB_ADDSTRING, 0, reinterpret_cast<LPARAM>((LPCTSTR)ComboBox2_text[Count]));
    		}
    		// StaticText2
    		HWND hStaticText2 = CreateWindowEx( 0, "STATIC", NULL, WS_CHILD | WS_VISIBLE |
    		SS_LEFT, 50, 110, 75, 20, hwnd, NULL, hInstance, NULL );
    		SetWindowText( hStaticText2, " ID:" );

    	// ComboBox3 - rok

    		//ComboBox3 - tablica
    		const char *ComboBox3_text[] = { "2010", "2011", "2012", "2013", "2014", "2015" };
    		// ComboBox3
    		HWND hComboBox3 = CreateWindowEx( WS_EX_CLIENTEDGE, "COMBOBOX", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER |
    		CBS_DROPDOWN, 150, 160, 150, 200, hwnd, NULL, hInstance, NULL );
    		for(int Count = 0; Count < 6; Count++)
    		{
    			SendMessage(hComboBox3, CB_ADDSTRING, 0, reinterpret_cast<LPARAM>((LPCTSTR)ComboBox3_text[Count]));
    		}
    		// StaticText3
    		HWND hStaticText3 = CreateWindowEx( 0, "STATIC", NULL, WS_CHILD | WS_VISIBLE |
    		SS_LEFT, 50, 160, 75, 20, hwnd, NULL, hInstance, NULL );
    		SetWindowText( hStaticText3, " Rok: " );

/*
 Problem do rozwi¹zania wybór combobox 4 w zale¿noœci od wartoœci combobox 1
 	 	 // ComboBox4 - miesi¹c
    		//ComboBox4 - tablica - R
    		const char *ComboBox4R_text[] = { "*", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12" };
    		//ComboBox4 - tablica - N
    		const char *ComboBox4N_text[] = { "*", "01*", "02*", "03*", "04*", "05*", "06*", "07*", "08*", "09*", "10*", "11*", "12*" };
    		// ComboBox4
    		HWND hComboBox4 = CreateWindowEx( WS_EX_CLIENTEDGE, "COMBOBOX", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER |
    		CBS_DROPDOWN, 150, 210, 150, 250, hwnd, NULL, hInstance, NULL );

    		// StaticText4 - miesi¹c
    		HWND hStaticText4 = CreateWindowEx( 0, "STATIC", NULL, WS_CHILD | WS_VISIBLE |
    		SS_LEFT, 50, 210, 75, 20, hwnd, NULL, hInstance, NULL );
    		SetWindowText( hStaticText4, " Miesi¹c: " );
*/
    // Tworzenie przycisku 1
    g_hPrzycisk1 = CreateWindowEx( 0, "BUTTON", "Tworzenie listy", WS_CHILD | WS_VISIBLE,
    50, 300, 150, 30, hwnd, NULL, hInstance, NULL );


    if( hwnd == NULL )
    {
        MessageBox( NULL, "Okno odmówi³o przyjœcia na œwiat!", "Ale kicha...", MB_ICONEXCLAMATION );
        return 1;
    }

    ShowWindow( hwnd, nCmdShow ); // Poka¿ okienko...
    UpdateWindow( hwnd );

    // Obsluga komunikatów komunikatów
    while( GetMessage( & Komunikat, NULL, 0, 0 ) )
    {
        TranslateMessage( & Komunikat );
        DispatchMessage( & Komunikat );
    }

    return Komunikat.wParam;
}

// OBS£UGA ZDARZEÑ
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
         MessageBox( hwnd, "Rozpoczêto tworzenie listy plików", "Tworzenie listy", MB_ICONINFORMATION );

    break;
        default:
        return DefWindowProc( hwnd, msg, wParam, lParam );
    }

    return 0;
}
