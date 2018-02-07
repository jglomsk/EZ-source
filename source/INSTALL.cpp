#include <iostream>
#include <cstdlib>
#if defined(_WIN32)
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
#else
#define SELF_REMOVE_STRING_UNIX "sudo rm -rf install.out && sudo rm -rf install.mac && sudo rm -rf install.exe"
#include <unistd.h>
#endif

// now you may code the windows installer
int main(int argc, char** argv)
{
	#ifdef SELF_REMOVE_STRING
	if (IsUserAdmin()) {
		system("mkdir \"C:\\Program Files\\EZ\"");
		system("copy \"help.ez\" \"C:\\Program Files\\EZ\" && del \"help.ez\"");
		system("copy \"creator.ez\" \"C:\\Program Files\\EZ\" && del \"creator.ez\"");
		system("copy \"sauce.ez\" \"C:\\Program Files\\EZ\" && del \"sauce.ez\"");
		system("copy \"all.ez\" \"C:\\Program Files\\EZ\" && del \"all.ez\"");
		system("copy \"class.ez\" \"C:\\Program Files\\EZ\" && del \"class.ez\"");
		system("copy \"basketeer.ez\" \"C:\\Program Files\\EZ\" && del \"basketeer.ez\"");
		system("del \"ez.mac\" && del \"ezr.mac\"");
		system("del \"ez.out\" && del \"ezr.out\"");
		system("del \"install.out\" && del \"install.mac\"");
		DelMe();
  }
	#else
	if (geteuid() != 0) {
		std::cout << "Please don't run without being admin/sudo.\n";
		exit(1);
	}
	else {
		system("sudo chmod +x ez.out");
		system("sudo chmod +x ez.mac");
		system("sudo mkdir /usr/local/bin &>/dev/null");
		system("sudo mkdir /usr/local/share &>/dev/null");
		system("sudo mkdir /usr/local/share/ez &>/dev/null");
		system("sleep .5s");
		system("sudo cp help.ez /usr/local/share/ez/ && sudo rm -rf help.ez");
		system("sudo cp creator.ez /usr/local/share/ez/ && sudo rm -rf creator.ez");
		system("sudo cp sauce.ez /usr/local/share/ez/ && sudo rm -rf sauce.ez");
		system("sudo cp all.ez /usr/local/share/ez/ && sudo rm -rf all.ez");
		system("sudo cp class.ez /usr/local/share/ez/ && sudo rm -rf class.ez");
		system("sudo cp basketeer.ez /usr/local/share/ez/ && sudo rm -rf basketeer.ez");
		system("sudo rm -rf ez.exe");
		system("sudo rm -rf ezr.exe");
		system("sudo rm -rf install.exe");
		char y_or_n = '\0';
		std::cout << "Would you like to delete the original interpreter? [y,n]: ";
		std::cin >> y_or_n;
		if (y_or_n != 'y') {
			std::cout << "Deletion declined.\n";
		}
		#if __linux__
		system("sudo cp ez.out /usr/local/bin/ez");
		system("sudo cp ezr.out /usr/local/bin/ezr");
		system("sudo rm -rf ezr.mac");
		system("sudo rm -rf ez.mac");
		if (y_or_n == 'y') {
			system("sudo rm -rf ezr.out");
			system("sudo rm -rf ez.out");
		}
		#elif __APPLE__
		system("sudo cp ez.mac /usr/local/bin/ez");
		system("sudo cp ezr.mac /usr/local/bin/ezr");
		system("sudo rm -rf ezr.out");
		system("sudo rm -rf ez.out");
		if (y_or_n == 'y') {
			system("sudo rm -rf ezr.mac");
			system("sudo rm -rf ez.mac");
		}
		#endif
		std::cout << "Command: ezr\n";
		std::cout << "Description: \n\n";
		std::cout << "Uses the ez interpreter as an interactive shell.\n\n";
		std::cout << "Command: ez\n";
		std::cout << "Usage: ez <ez-file>\n";
		std::cout << "Description: \n\n";
		std::cout << "Uses the ez interpreter to run a .ez file.\n\n";
		std::cout << "Install completed successfully.\n";
		std::cout << "This install file will now self-destruct.\n";
		system("sudo rm -rf install.out && sudo rm -rf install.mac");
	}
	#endif
	return 0;
}
