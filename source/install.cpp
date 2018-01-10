#include <iostream>
#include <windows.h>
#include <strsafe.h>
#define SELF_REMOVE_STRING  TEXT("cmd.exe /C ping 1.1.1.1 -n 1 -w 3000 > Nul & Del \"%s\"")
void DelMe() // deletes the current file
{
  TCHAR szModuleName[MAX_PATH];
  TCHAR szCmd[2 * MAX_PATH];
  STARTUPINFO si = {0};
  PROCESS_INFORMATION pi = {0};
  GetModuleFileName(NULL, szModuleName, MAX_PATH);
  StringCbPrintf(szCmd, 2 * MAX_PATH, SELF_REMOVE_STRING, szModuleName);
  CreateProcess(NULL, szCmd, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
  CloseHandle(pi.hThread);
  CloseHandle(pi.hProcess);
}
BOOL IsUserAdmin(VOID) // checks if the user is running this program as admin
{
  BOOL b;
  SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;
  PSID AdministratorsGroup; 
  b = AllocateAndInitializeSid(
    &NtAuthority,
    2,
    SECURITY_BUILTIN_DOMAIN_RID,
    DOMAIN_ALIAS_RID_ADMINS,
    0, 0, 0, 0, 0, 0,
    &AdministratorsGroup); 
  if(b) 
  {
    if (!CheckTokenMembership( NULL, AdministratorsGroup, &b)) 
    {
      b = FALSE;
    }
  FreeSid(AdministratorsGroup); 
  }
  return(b);
}
// now you may code the windows installer
int main(int argc, char** argv)
{
  if (IsUserAdmin()) {
    system("mkdir \"C:\\Program Files\\EZ\"");
    system("copy \"help.ez\" \"C:\\Program Files\\EZ\" && del \"help.ez\"");
    system("copy \"creator.ez\" \"C:\\Program Files\\EZ\" && del \"creator.ez\"");
    system("copy \"sauce.ez\" \"C:\\Program Files\\EZ\" && del \"sauce.ez\"");
    system("copy \"all.ez\" \"C:\\Program Files\\EZ\" && del \"all.ez\"");
    system("del \"ez.mac\" && del \"ezr.mac\"");
    system("del \"ez.out\" && del \"ezr.out\"");
    system("del \"eznix_install.bash\"");
    DelMe();
  }
  return 0;
}