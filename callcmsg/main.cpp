#include "main.h"

HWND _cmsgHwnd;
void set_cmsgHwnd(LPCTSTR cls1 = "WinRetMsgApp");
void dbgMsg(LPCTSTR	s);
//
void set_cmsgHwnd(LPCTSTR cls1 /*= "WinRetMsgApp"*/){
	_cmsgHwnd=FindWindow(cls1,NULL);
	//
	if(_cmsgHwnd==NULL){
		UINT x=WinExec("cmsg.exe",SW_SHOWNORMAL);
		Sleep(1000*2);
		_cmsgHwnd=FindWindow(cls1,NULL);
	}
}
//
void dbgMsg(LPCTSTR	s){
	set_cmsgHwnd(); //you can just call set_cmsgHwnd() one time when your app start
	//
	SendMessage(_cmsgHwnd, WM_SETTEXT, 0, (LPARAM)s );
}
//
void sndMsg(){
	TCHAR s[]="123³Ô·¹45";
	dbgMsg(s);
	//
}

void getSlfDir(LPTSTR sPath,LPTSTR sFiln=NULL){
	ZeroMemory(sPath,MAX_PATH);
	if(sFiln){
        ZeroMemory(sFiln,MAX_PATH);
	}
    GetModuleFileName(NULL,sPath,MAX_PATH);
    LPTSTR pFen=_tcsstr(sPath,"\\");
    *pFen='\0';
    pFen++;
	if(sFiln){
        sFiln=pFen;
	}
}
#include <iostream>
void callcmsg(LPSTR lpszArgument){
	TCHAR s[]="00³Ô123³Ô·¹45";
	LPTSTR gls=GetCommandLine();


	dbgMsg(lpszArgument);
	dbgMsg(gls);
	//return;
	//
	//std::printf("%02d",9);

	TCHAR sz[MAX_PATH]={0};
	TCHAR sFiln[MAX_PATH]={0};

    //getSlfDir(sz /*,LPTSTR sFiln=NULL*/);
    getSlfDir(sz ,sFiln);

    dbgMsg(sz);
    dbgMsg(sFiln);
    tstring x;

}

///////////////////////////////////////////////////////////////////// ok v
int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    callcmsg(lpszArgument);
    return 0;
    //
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("Code::Blocks Template Windows App"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           544,                 /* The programs width */
           375,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
