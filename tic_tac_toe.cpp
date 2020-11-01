#include<iostream.h>
#include<graphics.h>
#include<dos.h>
#include<stdio.h>
#include<conio.h>

char arr[10]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
int player1=1,player2;
int won=0;
int midX,midY;

void printTitle()
{
  setcolor(10);
  settextstyle(1,0,4);
  outtextxy(midX-90,30,"TIC TAC TOE");

  setcolor(14);
  settextstyle(3,0,1);
  outtextxy(40,midY-90,"PLAYER 1  ( X )");
  outtextxy(midX+140,midY-90,"PLAYER 2  ( 0 )");
}

void drawCase()
{
  int s1=80,s2=27;
  setcolor(15);
  setlinestyle(0,0,3);
  settextstyle(3,0,3);
  line(midX-s1,midY-s2,midX+s1,midY-s2);
  line(midX-s1,midY+s2,midX+s1,midY+s2);
  line(midX-s2,midY-s1,midX-s2,midY+s1);
  line(midX+s2,midY-s1,midX+s2,midY+s1);
}

char * valueOf(char ch)
{
  char str[3];
  //str[0]=ch;
  sprintf(str,"%c",ch);
  //str[1]='\0';
  return str;
}

void setValue()
{
  setcolor(10);

  outtextxy(midX-62,midY-70,valueOf(arr[0]));
  outtextxy(midX-7,midY-70,valueOf(arr[1]));
  outtextxy(midX+45,midY-70,valueOf(arr[3]));

  outtextxy(midX-62,midY-13,valueOf(arr[4]));
  outtextxy(midX-7,midY-13,valueOf(arr[5]));
  outtextxy(midX+45,midY-13,valueOf(arr[6]));

  outtextxy(midX-62,midY+40,valueOf(arr[7]));
  outtextxy(midX-7,midY+40,valueOf(arr[8]));
  outtextxy(midX+45,midY+40,valueOf(arr[9]));
}

void getValue()
{
  setcolor(9);
  settextstyle(3,0,1);

  for(int i=1;i<=15;i++)
    cprintf("\n");

  if(player1){
   outtextxy(30,midY-7,"Enter Position : ");
   for(int i=1;i<=21;i++)
    cprintf("\t");
  }
  else{
   outtextxy(midX+130,midY-7,"Enter Position : ");
   for(int i=1;i<=74;i++)
    cprintf("\t");
  }

  int pos;
  cin>>pos;

  if(pos>=1 && pos<=9 && arr[pos-1]==' ')
  {
    if(player1){
     arr[pos-1]='X';
     player1=0;
    }
    else{
     arr[pos-1]='O';
     player1=1;
    }
  }
  else{
   outtextxy(50,midY+150,"Already Done, Enter Position in Number between 1 to 9.");
   delay(3000);
  }

}

char checkMatch()
{
 char ch;

 ch=arr[0];
 if(arr[0]==ch && arr[1]==ch && arr[2]==ch)
  return ch;
 if(arr[0]==ch && arr[3]==ch && arr[6]==ch)
  return ch;
 if(arr[0]==ch && arr[4]==ch && arr[8]==ch)
  return ch;

 ch=arr[1];
 if(arr[1]==ch && arr[4]==ch && arr[7]==ch)
  return ch;

 ch=arr[2];
 if(arr[2]==ch && arr[5]==ch && arr[8]==ch)
  return ch;
 if(arr[2]==ch && arr[4]==ch && arr[6]==ch)
  return ch;

 ch=arr[3];
 if(arr[3]==ch && arr[4]==ch && arr[5]==ch)
  return ch;

 ch=arr[6];
 if(arr[6]==ch && arr[7]==ch && arr[8]==ch)
  return ch;

 return ' ';
}

int isMatch()
{
 char ch = checkMatch();
 if(ch=='X'){
  won=1;
  return 1;
 }
 else if(ch=='O'){
  won=2;
  return 1;
 }
 return 0;
}

void result()
{
  setcolor(3);
  settextstyle(3,0,3);
  if(won==1)
   outtextxy(midX-45,100,"PLAYER 1");
  else if(won==2)
   outtextxy(midX-45,100,"PLAYER 2");
  else
   outtextxy(midX-65,100,"MATCH DRAW");
}

int isEmpty()
{
 for(int i=0;i<9;i++)
 {
  if(arr[i]==' ')
    return 1;
 }
 return 0;
}

void outline()
{
  int mx=getmaxx();
  int my=getmaxy();
  setcolor(10);
  line(0,0,mx,0);
  line(mx,0,mx,my);
  line(0,my,mx,my);
  line(0,0,0,my);
}

int main()
{
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"C:\\TC\\BGI");

  midX=getmaxx()/2;
  midY=getmaxy()/2;
  int i=1;
  while(i++<=5)
  {
   outline();
   printTitle();
   drawCase();
   getValue();
   setValue();
  // if(isMatch()) break;
   delay(1000);
   cleardevice();
  }
   outline();
   printTitle();
   drawCase();
   setValue();
   result();

  getch();
  closegraph();
  getch();
 return 0;
}
