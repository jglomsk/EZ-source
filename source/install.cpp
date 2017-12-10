#include <iostream>
int main()
{
  system("mkdir \"C:\\Program Files\\EZ\"");
  system("copy \"help.ez\" \"C:\\Program Files\\EZ\"");
  system("copy \"creator.ez\" \"C:\\Program Files\\EZ\"");
  system("copy \"sauce.ez\" \"C:\\Program Files\\EZ\"");
  system("copy \"all.ez\" \"C:\\Program Files\\EZ\"");
  system("del \"help.ez\"");
  system("del \"creator.ez\"");
  system("del \"sauce.ez\"");
  system("del \"all.ez\"");
  return 0;
}