//============================================================================
// Name        : list.cpp
// Author      : Makowiec
// Version     : 0.1
// Copyright   : IC
// Description : Program do tworzenia listy plików wersja okienkowa, Ansi-style
//				 Pliki mniejsze ni¿ 1TB
//============================================================================

#include <windows.h>

LPCSTR NazwaKlasy = "Klasa Okna";
MSG Komunikat; //zmienan do przechwytywania komunikatów
HWND g_hPrzycisk1; //przycisk 1
HWND g_hRamka1; //ramka 1

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
    CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, hInstance, NULL );

    // Tworzenie przycisku 1
    g_hPrzycisk1 = CreateWindowEx( 0, "BUTTON", "Tworzenie listy", WS_CHILD | WS_VISIBLE,
    50, 500, 150, 30, hwnd, NULL, hInstance, NULL );

    // Tworzenie ramki 1
    g_hRamka1 = CreateWindowEx( 0, "BUTTON", "Podaj zmienne", WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
    30, 30, 400, 300, hwnd, NULL, hInstance, NULL );



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
