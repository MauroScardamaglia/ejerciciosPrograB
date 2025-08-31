#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    If (x == 4)
      y = 7;
    else
      if (x == 5)
        y = 9;
      else
        if(x == 9)
          y = 14;
        else
          y = 22;
 */

    int x,y;
    x=0;
    scanf("%d",&x);

    switch (x){
    case 4: y=7;
        break;
    case 5: y=9;
        break;
    case 9: y=14;
        break;
    default: y=22;
    }

    printf("como x vale %d, y vale %d",x,y);

    return 0;
}
