#include <windows.h> 
#pragma comment(linker, "/align:16")
#pragma comment(lib,"kernel32.lib")
#pragma comment(linker, "/subsystem:windows")
#pragma comment(linker, "/ENTRY:WinMainX")

void WinMainX() { 
  int n;
  STARTUPINFO * s = LocalAlloc(0x0040,sizeof(STARTUPINFO));
  PROCESS_INFORMATION * p = LocalAlloc(0x0040,sizeof(PROCESS_INFORMATION));
  unsigned char * l = LocalAlloc(0x0040,MAX_PATH);
  if (s && p && l ){
    s->cb = sizeof(STARTUPINFO);
    s->dwFlags = STARTF_USESHOWWINDOW; 
    s->wShowWindow = TRUE; 
    n = GetModuleFileName(NULL,l,MAX_PATH);
    while(n>0 && l[n]!= '\\'){
      n--;
    }
    l[n] = '\0';
    n = SetCurrentDirectory(l);
    if (n){
      CreateProcess(NULL,"cmd /c cmd.exe",NULL,NULL,FALSE,CREATE_NEW_CONSOLE,NULL,NULL,s,p);
    }
  }
  ExitProcess(0);
}