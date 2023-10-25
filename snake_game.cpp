#include<iostream>
#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
bool gameover;
const int width=30;
const int height=30;
int x,y,fx,fy,score;
int tailx[100],taily[100];
int Ltail;

enum edirection{STOP=0, LEFT, RIGHT, UP, DOWN};
edirection dir;

void Setup()
{
    gameover=false;
    dir=STOP;
    x=width/2;
    y=height/2;
    fx=rand()%width;
    fy=rand()%height;
    score=0;
}

void Draw()
{
    system("cls");
    cout<<"\n\n      S N A K E  G A M E \n\n"<<endl;

    for(int i=0;i<width+2;i++)
    {
        cout<<"#";
    }
    cout<<endl;

    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(j==0)
              {
                 cout<<"#";
              }

            if(i==y && j==x)
            {
                cout<<"O";
            }
            else if(i==fy && j==fx)
            {
                cout<<"@";
            }
            else{
                bool print=false;
                for(int k=0;k<Ltail;k++){
                    if(tailx[k]==j && taily[k]==i)
                    {
                        cout<<"o";
                        print=true;
                    }
                }
                if(!print)
                   cout<<" ";
            }

            if(j==width-1){
                cout<<"#";
            }
        }
        cout<<endl;
    }

    for(int i=0;i<width+2;i++)
    {
        cout<<"#";
    }
    cout<<endl;
    cout<<"SCORE: "<<score<<endl;
}

void Input()
{
  if(_kbhit())
  {
      switch(_getch())
      {
           case 'a': dir=LEFT; break;
           case 'd': dir=RIGHT; break;
           case 'w': dir=UP; break;
           case 's': dir=DOWN; break;
           case 'x': gameover=true; break;
      }
  }
}

void Logic()
{
   int pre_x=tailx[0];
   int pre_y=taily[0];
   int p_2x,p_2y;
   tailx[0]=x;
   taily[0]=y;
   for(int i=1;i<Ltail;i++)
   {
       p_2x=tailx[i];
       p_2y=taily[i];
       tailx[i]=pre_x;
       taily[i]=pre_y;
       pre_x=p_2x;
       pre_y=p_2y;
   }


   switch(dir)
        {
            case LEFT: x--; break;
            case RIGHT: x++; break;
            case UP: y--; break;
            case DOWN: y++; break;
            default: break;
        }
   if(x>=width)
      {
          x=0;
      }
   else if(x<0){
        x=width-1;
      }

   if(y>=height)
    {
          y=0;
      }
   else if(y<0){
        y=height-1;
      }

  for(int i=0;i<Ltail;i++){
    if(tailx[i]==x && taily[i]==y)
      {
          gameover=true;
      }
    }
    if(x==fx && y==fy)
    {
        score+=10;
        fx=rand()%width;
        fy=rand()%height;
        Ltail++;
    }
}

int main()
{
    Setup();
    while(!gameover)
    {
        Draw();
        Input();
        Logic();
        Sleep(100);
    }
}
