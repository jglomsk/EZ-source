#include <iostream>
int main()
{
  system("mkdir \"C:\\Program Files\\EZ\"");
  system("copy \"help.ez\" \"C:\\Program Files\\EZ\"");
  system("del \"help.ez\"");
  return 0;
}