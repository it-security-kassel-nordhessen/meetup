#include "windows.h"
#include <stdio.h>

int main (void)
{
  DWORD   dwChars,dwErr;
  WCHAR   wszMsgBuff[512];

  dwErr = ShellExecute( NULL,
    "runas",
    "minor.exe",
    "",
    NULL,                        // default dir
    SW_SHOWNORMAL
);
  
   HINSTANCE hInst;

   // Load the library.
   hInst = LoadLibrary(L"Ntdsbmsg.dll");
   dwChars = FormatMessage( FORMAT_MESSAGE_FROM_HMODULE |
                                FORMAT_MESSAGE_IGNORE_INSERTS,
                                hInst,
                                dwErr,
                                0,
                                wszMsgBuff,
                                512,
                                NULL );
   printf("Error value: %d Message: %ws\n",
        dwErr,
        dwChars ? wszMsgBuff : L"Error message not found." );

	return 0;
}
