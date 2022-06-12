#include <stdio.h>
#include <stdlib.h>
#include <time.h>
short int m[11][11],b,c,r,d[11][11],x,y,ok,s,i,j,f;
char o;

void draw(){
 system("clear");
 if(f>9||f<0)printf(" \033[33;2m%d\033[0m",f);
 else printf(" \033[33;2m%d\033[0m ",f);
 for(i=1;i<=c;i++)printf("  %d ",i);

 printf("\n   ");
 for(i=1;i<=c;i++)printf("+---");
 printf("+\n");
 
 for(i=1;i<=r;i++)
 {  printf(" %d ",i);
    for(j=1;j<=c;j++)
    { if(d[i][j]==0)printf("|\033[7;2m%d %d\033[0m",i,j);
	 else if(d[i][j]>=32) printf("| F ");
	 else if(m[i][j]==0) printf("|   ");
	 else printf("|\033[%d;7;1m %d \033[0m",37-m[i][j],m[i][j]);
    }
    printf("|\n   ");
    for(j=1;j<=c;j++)printf("+---");
    printf("+\n");
 }
}

int main(){
 srand(time(0));
 printf("Please enter number of rows and columns (MAX 9): ");
 scanf("%hd %hd",&r,&c);
 printf("Please enter the number of bombs: ");
 scanf("%hd",&b);
 f=b;
 //printf("%d %d",r,c);
 i=0;
 while(i<b)
 { x=rand()%r+1;
   y=rand()%c+1;
   if(m[x][y]==0)i++,m[x][y]=-32;
 }
 draw();
 printf("X - row Y - column. Type dXY for digging, fXY for flagging a square. The coordinates are also displayed in each box. \n");
 scanf(" %c%1hd%1hd",&o,&x,&y);
 if(o=='d')
 { d[x][y]=1;
   if(m[x][y]<0)
   {   m[x][y]=0;
       short x2=rand()%r+1, y2=rand()%c+1;
       while(m[x2][y2]<0||(x2==x&&y2==y))x2=rand()%r+1,y2=rand()%c+1;
       m[x2][y2]=-32;
   }
 }
 else d[x][y]=32;

 for(i=1;i<=r;i++)
    for(j=1;j<=c;j++)
      if(m[i][j]<0)m[i-1][j-1]++,m[i-1][j]++,m[i-1][j+1]++,m[i][j-1]++,m[i][j+1]++,m[i+1][j-1]++,m[i+1][j]++,m[i+1][j+1]++;

 if(m[x][y]!=0)d[x][y]=2;
 while(b!=0 || f!=b)
 { ok=r+c;
   while(ok)
   { ok--;
     for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)	   
        { if(d[i][j]>=1&&m[i][j]==0)d[i-1][j-1]=2,d[i-1][j]=2,d[i-1][j+1]=2,d[i][j-1]=2,d[i][j+1]=2,d[i+1][j-1]=2,d[i+1][j]=2,d[i+1][j+1]=2;
	}
   } //NEEDS REWORKED, instead of finding out when it finnished emptying out all the squares, the while just keeps looping for the length of r+c

   draw();
   printf("X - row Y - column. Type dXY for digging, fXY for flagging a square and rXY for removing a flag. The coordinates are also displayed in each box. \n");
   scanf(" %c%1hd%1hd",&o,&x,&y);

   if(o=='d')
   { if(m[x][y]<0)
     { printf("\n\n\n     _.-^^---....,,--\n _--                  --_\n<           YOU          >)\n|          LOSE           |\n \\._                   _./\n    ```--. . , ; .--'''\n          | |   |\n       .-=||  | |=-.\n       `-=#$%&%$#=-'\n          | ;  :|\n _____.,-#%&$@%#&#~,._____ ");
       return 0;
     }
     d[x][y]=1;
   }
   else if(o=='f')
   { if(m[x][y]<0&&d[x][y]==0)b--;
     if(d[x][y]==0)f--;	   
     d[x][y]=32;
   }
   else 
   { if(m[x][y]<0&&d[x][y]==32)b++;
     if(d[x][y]==32)f++;	   
     d[x][y]=0;
   }
 }
 draw();
 printf("\n░░                                        \n░░                                        \n░░░░                                      \n  ░░████                                  \n  ██░░░░████████  ██████████              \n  ██░░░░░░████████▒▒▒▒▒▒████████          \n    ██░░░░████████▒▒▒▒██████████████      \n    ██████████████▒▒▒▒████████████████    \n    ████████████▒▒▒▒██████████████████    \n    ████████████▒▒▒▒████████████████████  \n      ██████▒▒▒▒▒▒██████████████████████  \n    ██▒▒▒▒▒▒▒▒▒▒████     █████▒▒▒▒████████\n    ██▒▒▒▒▒▒████████ YOU █▒▒▒▒████████████\n    ██▒▒████████████     ▒████████████████\n    ████████████████ WIN █████████████████\n    ██████████████▒▒     █████████████████\n      ██████████▒▒██████████████████████  \n      ██████████▒▒██████████████████████  \n        ██████████▒▒██████████████████    \n        ████████████▒▒▒▒▒▒▒▒██████████    \n          ██████████████████████████      \n              ██████████████████          \n                  ██████████              \n");
 return 0;
}
