#include <iostream>
int main()
{
  system("mkdir \"C:\\Program Files\\EZ\"");
  system("copy \"help.ez\" \"C:\\Program Files\\EZ\" && del \"help.ez\"");
  system("copy \"creator.ez\" \"C:\\Program Files\\EZ\" && del \"creator.ez\"");
  system("copy \"sauce.ez\" \"C:\\Program Files\\EZ\" && del \"sauce.ez\"");
  system("copy \"all.ez\" \"C:\\Program Files\\EZ\" && del \"all.ez\"");
  return 0;
}