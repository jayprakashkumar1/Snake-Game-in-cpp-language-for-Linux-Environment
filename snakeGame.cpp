// header files 
#include<iostream>
#include<time.h>
#include"headerFile/getchInLinux.h"            // for getch() in linux
#include"headerFile/kbhit3.h"                 // for kbhit() in Linux
#include<cstdlib>            // for exit()      

using namespace std;

// class 
 class snake
 {
// by default private

     int borderX,borderY;
     int foodX,foodY;
     int x,y,score;
     int totalSegment;
     int snakeTail[2][100];          // 
     string name;

public:
        snake();                    // constructor
        void showBorder();
        void foodGenerate();
        int readEnteredKey();
        int changeDirectcion(int);
        int eatingCheck();            // if food eaten by snake return 1 , else return 0
        void increaseScore();
        void showScore();
        int checkBoundryCollision();
        void addSegment();
        int checkOverlap();
        void delay1();
 };

 snake:: snake()
{
      system("clear");
      cout<<"Enter Your Good Name: ";
      cin>>name;
      system("clear");
      cout<<"\n               SNAKE .................GAME !               \n\n";

    cout<<"                 RULE OF THIS GAME                 \n";
    cout<<"\n1.You can move snake in up,Down,Left or Right only by arrow key ";
    cout<<"\nMove Up   : by Up arrow key ";
    cout<<"\nMove Down : by Down arrow key";
    cout<<"\nMove Left : by Left arrow key";
    cout<<"\nMove Right: by Right arrow key";

    cout<<"\n\n2.You can exit the game at any time by pressing 'E' or 'e' ";
    cout<<"\n3.For each eaten food You will be awared a 5 point ";
    cout<<"\n\n         Happy gaming , Good Luck\n";
   
    cout<<"\nEnter any key to start.....  : ";
  
      score=0;            // initial zero 
      borderX=90;
      borderY=30;

      x=borderX/2;
      y=borderY/2;

      totalSegment=0;       // snake segment

}
void snake:: showScore()
{
    cout<<"your score: "<<score<<endl<<endl;
}
void snake:: showBorder()
{
     system("clear");
     cout<<"           SNAKE  GAME           ";
    cout<<"\n\nWelcome   "<<name<<"    ,       ";
    showScore();

      for(int i=1;i<=borderY;i++)
    {    for(int j=1;j<=borderX;j++)
           if((i==1 || i==borderY )|| (j==1 || j== borderX))
             cout<<".";
                else if(j==foodX && i==foodY)
                    cout<<"F";
                else if(checkBoundryCollision())
                {}
                    else if(j==x && i==y)
                      cout<<"@";
                      else if(eatingCheck())
                    {
                        foodGenerate();         // generate new food for snake
                        increaseScore();               // increase score       
                        delay1();
                        delay1();
                        delay1();
                        delay1();
                        delay1();
                        addSegment();            // to add segmments
                    }
                        else                   // printing snake segments
                    {  int temp=0;
                       for(int k=1;k<=totalSegment;k++)
                       if(j==snakeTail[0][k] && i==snakeTail[1][k])
                     {  cout<<"o";
                        temp=1;
                      }
                            if(!temp)
                            cout<<" "; 
                    }  
                         cout<<endl;
     } 
}
void snake:: foodGenerate()
{
   delay1();
   delay1();
   delay1();
   delay1();
   
    srand(time(NULL));                 
    while(1)
    {     foodX=rand()%(borderX);          // randomly 
          foodY=rand()%(borderY);
        if(foodX>1 && foodY>1)
        break;
    }
    totalSegment++;          // segments increased by one 
}
// Reads the user input character and return ascii value of that
int snake::readEnteredKey()  
{
        char c;
            c = getchInLinux();
            if(c==27 || c==91)       // this is just for scan code 
         {  c = getchInLinux();
             if(c==27 || c==91)     // also for scan code 
              c=getchInLinux();
         }
    return c;
}
int snake::changeDirectcion(int key)
{
    switch(key)
    {
         case 69:                  // ascii of E
                        
            case 101:                 // ascii of e
                        cout<<"\a\a\a\a\a\a\n     Thanks for Playing ! \n\a";
                        cout<<"\nHit 'Enter' to exit the game \n";
                        key=readEnteredKey();
                        exit(0);               

            
            case 65:          // arrow up
                        y--;
                        return 1;   
                    
            case 66:          // arrow down
                        y++;
                        return 1;   

            case 67:            // arrow  right
                        x++;
                        return 1;
            case 68:             // arrow left
                        x--;
                        return 1;
            default:
                      
                    //   cout<<"\n\n      \a\a❌ Not Allowed \a\a\a\a");
                        return 0;
    }
}

int snake::checkBoundryCollision()
{ 
    if(x<=1 || x>=borderX || y<=1 || y>=borderY)
    {   system("clear");
        cout<<"\nGame Over !     ";
        showScore();
        delay1();
        delay1();
        exit(0);
    }
    return 0;
}
int snake::eatingCheck()
{
    if(foodX==x && foodY==y)
    return 1;
    return 0;

}

void snake::increaseScore()
{
  score+=5;
}
void snake:: addSegment()
{
    // idea is that , each snake segments will follow its front  snake.
    // i.e 
    // first segment will follow snake's HEAD
    // 2nd segment "       "     1st segment
    // 3rd segment "       "     2nd segment

     int prev1X=snakeTail[0][0];
    int prev1Y=snakeTail[1][0];
    
    int current1X;
    int current1Y;
   
    snakeTail[0][0]=x;
    snakeTail[1][0]=y;

    for(int i=1;i<totalSegment;i++)
    {
        current1X=snakeTail[0][i];
        current1Y=snakeTail[1][i];
       
        snakeTail[0][i]=prev1X;
        snakeTail[1][i]=prev1Y;

        prev1X=current1X;
        prev1Y=current1Y;         
    }
}

int snake:: checkOverlap()
{
 int i;
for(i=0;i<totalSegment;i++)
if(x==snakeTail[0][i] && y==snakeTail[1][i])
break;

if(i<totalSegment)
{
        system("clear");
        cout<<"\nGame Over !     ";
        showScore();
        delay1();
        delay1();
        exit(0);
}
  return 0;
}

void snake::delay1()
{
    for(int i=1;i<=10000;i++)
    for(int j=1;j<=1000;j++);
}
               
int main()                // main function 
{
      int key,d;
       snake s1;
       int x=s1.readEnteredKey();
       x=s1.readEnteredKey();
    
       system("clear");

       s1.foodGenerate();
       s1.showBorder();
       key=s1.readEnteredKey();
       s1.delay1();
       s1.delay1();
    
    while(1)
  {  
    while(!kbhitInLinux())
    {
        s1.showBorder();               
        d=s1.changeDirectcion(key);
        
        s1.checkOverlap();
        
        s1.addSegment();            // to add snake segmments

        s1.delay1();
         s1.delay1();
          s1.delay1();
           s1.delay1();
            s1.delay1();
              s1.delay1();
        
        system("clear");
    }
            s1.showBorder();
            key=s1.readEnteredKey();
             s1.delay1();
             s1.delay1();
             s1.delay1();
              s1.delay1();
              s1.delay1();
        
              d=s1.changeDirectcion(key);

              s1.checkOverlap();
              
              s1.addSegment();            // to add segmments
  }
        return 0;        //  return from main  
}
