#include <iostream>
#include <conio.h>
#include <ctime>


using namespace std;
bool gameOver;
const int width = 30;
const int height = 15;
int x,y,foodX,foodY,score;
enum sDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
sDirection dir;
int tailX[100],tailY[100];
int snackLen;

void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width/2;
    y = height/2;
    foodX  = rand()%width;
    foodY = rand()%height;
    score = 0;
}
void Draw(){
 system("cls");
 for(int i=0;i<width+2;i++)
    cout<<"#";
 cout<<endl;

for(int i=0;i<height;i++){
     for(int j=0;j<width;j++){
         if(j == 0)
            cout<<"#";
         if(i==y && j==x)
            cout<<"0";
         else if(i==foodY && j==foodX)
            cout<<"F";
         else
         {
             bool print = false;
           for(int k=0;k<snackLen;k++){
               //
            if(tailX[k]==j && tailY[k]==i){
                cout<<"0";
                print = true;
            }

           }
             if(!print)
             cout<<" ";

         }


         if(j==width-1)
            cout<<"#";
     }
     cout<<endl;
 }

 for(int i=0;i<width+2;i++)
    cout<<"#";

 cout<<endl;

}
void Input()
{
  if(_kbhit()){
    switch(_getch())
    {
  case 'a':
    dir = LEFT;
     break;

  case 'w':
    dir = UP;
    break;
  case 'd':
    dir = RIGHT;
    break;
  case 's':
    dir = DOWN;
    break;
  case 'q':
    gameOver = true;
    break;
    }
  }


}
void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X,prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for(int i=1;i<snackLen;i++){
        prev2X  = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

   switch(dir)
   {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case DOWN:
        y++;
        break;
    case UP:
        y--;
        break;
    default:
        break;
   }
   if(x > width || x < 0 || y > height || y < 0)
      gameOver = true;

   if(x==foodX && y == foodY){
     score++;
    foodX  = rand()%width;
    foodY = rand()%height;
    snackLen++;
   }
}

int main()
{
   Setup();
   while(!gameOver){
//     sleep(10000);
    Draw();
    Input();
    Logic();
    //Sleep()
 }

   return 0;

}
