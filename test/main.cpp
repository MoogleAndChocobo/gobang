#include <cstdio>
#include "function.h"

int main()
{
  while (true)
  {
    Chess now;
    now.ShowMap();
    while (true)
    {
      now.SetValue();
      now.ShowMap();
      int ans = now.CheckResult();
      if (ans == 1)
      {
        puts("先手胜利");
        break;
      }
      else if (ans == 2)
      {
        puts("后手胜利");
        break;
      }
      else if (ans == -1)
      {
        puts("平局");
        break;
      }
    }
  }
  return 0;
}

