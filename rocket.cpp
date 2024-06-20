
#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<graphics.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ENTER 13
int lives = 3;
int score=0;
class rocket
 {
  public:
  int  cp, init, op1, op2, op3;
  rocket::rocket()
   {
    cp = 300;
    init = 0;
    op1 = 0;
    op2 = -20;
    op3 = -40;
}
}
rocket;
 int randx( void )
 {
 int x = random( 55*8  );
 if ( x < 25*8 )
 {
 x = x + ( 25 *8 );
 }
return ( x );
}
void right()
 {
 if ( rocket.cp < 420 )
 {
 rocket.cp += 10;
 }
 return ;
 }
 void left()
 {
 if ( rocket.cp > 180 )
{
 rocket.cp -= 10;
 }
 return ;
}
void bgmove()
{
 if (rocket.init > 5) {
 rocket.init = 1;
 }
setcolor(WHITE);
 for (int i = 0; i < 50; i++)
 {
 int x = random(640), y = random(350);
 putpixel(x, y, WHITE);
}
setcolor(YELLOW);
setfillstyle(SOLID_FILL, BLACK);
rectangle(rocket.cp + 10, 330, rocket.cp + 30, 350);
setfillstyle(SOLID_FILL, YELLOW);
floodfill(rocket.cp + 20, 340, YELLOW);

setcolor(RED);
setfillstyle(SOLID_FILL, RED);
line(rocket.cp + 20, 350, rocket.cp + 15, 360);
line(rocket.cp + 15, 360, rocket.cp + 20, 370);
line(rocket.cp + 20, 370, rocket.cp + 25, 360);
line(rocket.cp + 25, 360, rocket.cp + 20, 350);
floodfill(rocket.cp + 20, 360, RED);

setcolor(YELLOW);
setfillstyle(SOLID_FILL, RED);
pieslice(rocket.cp + 20, 330, 0, 180, 10);

 for (i = rocket.init; i < 70; i += 5) {
 setcolor(LIGHTGRAY);
 setfillstyle(1, LIGHTGRAY);
 bar(16 * 8, i * 8, 20 * 8, (i + 2) * 8);
 bar(60 * 8, i * 8, 64 * 8, (i + 2) * 8);
 delay(1);
 }
setcolor(WHITE);
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
outtextxy(0,10 , "Score:");
char score_str[10];
itoa(score, score_str, 10);
outtextxy(90, 10, score_str);

    outtextxy(getmaxx() - 120, 10, "Lives:");
    char lives_str[2];
    itoa(lives, lives_str, 10);
    outtextxy(getmaxx() - 30, 10, lives_str);
}
void opp1( int x1 )
 {
 if ( rocket.op1 < 600 )
 {
 rocket.op1 += 10;
 setfillstyle( 1, LIGHTGRAY );
 bar( x1, rocket.op1, x1 + 30, rocket.op1 + 30);
 }
	else
	{
rocket.op1 = 0;
delay(10);
score++;
	}
	return ;
    }
    void opp2( int x2 )
    {
	if ( rocket.op2 < 600 )
	{
	rocket.op2 += 10;
	setfillstyle( 1, LIGHTGRAY );
	bar( x2, rocket.op2, x2 + 30, rocket.op2 + 30);
	}
	else
	{
	rocket.op2 = 0;
	delay(10);
score++;
	}
	return ;
    }
    void opp3( int x3 )
    {
	if ( rocket.op3 < 600 )
	{
	rocket.op3 += 10;
	setfillstyle( 1, LIGHTGRAY );
	bar( x3, rocket.op3, x3 + 30, rocket.op3 + 30);
	}
	else
	{
	rocket.op3 = 0;
	delay(10);
score++;
	}
	return ;
    }
    int check( int x, int op, int cp )
    {
	int a[ 31 ], b[ 31 ], c[ 40 ], d[ 50 ];
	for ( int i = 0;i < 30;i++ )
	{
	a[ i ] = x + i;
	}
	for ( i = 0;i < 30;i++ )
	{
	b[ i ] = op + i;
	}
	for ( i = 0;i < 40;i++ )
	{
	c[ i ] = cp + i;
	}

	for ( i = 0;i < 50;i++ )
	{
	d[ i ] = 300 + i;
	}
	for ( i = 0;i < 40;i++ )
	{
	for ( int j = 0;j < 50;j++ )
	{
	    for ( int k = 0;k < 30;k++ )
	    {
		if ( a[ k ] == c[ i ] && b[ k ] == d[ j ] )
		    return 1;
	    }
	}
	}
	return 0;
    }


    void over( void )
    {
	for ( int i = 1;i < 35;i++ )
	{
	cleardevice();
	delay( 20 );
	settextstyle( 1, 0, 6 );
	setcolor( RED );
	outtextxy( 150, 100, "!!!GAME OVER!!!" );
      cout << "Final Score: "<<score<< endl;

	delay( 20 );
	}
	delay( 200 );
	cleardevice();
	getch();
	return ;
    }

    int play( void )
    {
	int life = 3, m, x1, x2, x3, s;

    re:
	while ( life )
	{
	cleardevice();
	if ( rocket.op1 == 0 )
	{
	    x1 = randx();
	    rocket.op1++;
	}
	else
	{
	    opp1( x1 );
	}
	if ( rocket.op2 == 0 )
	{
	    x2 = randx();
	    rocket.op2++;
	}
	else if ( rocket.op2 < 1 )
	{
	rocket.op2++;
	}
	else
	{
	    opp2( x2 );
	}
	if ( rocket.op3 == 0 )
	{
	    x3 = randx();
	    rocket.op3++;
	}
	else if ( rocket.op3 < 1 )
	{rocket.op3++;}
	else
	{
	    opp3( x3 );
	}
	setcolor( 10 );
	bgmove();
	if ( check( x2, rocket.op2, rocket.cp ) || check( x1, rocket.op1, rocket.cp ) || check( x3, rocket.op3, rocket.cp ) )
	{
    lives--;
    if (lives == 0)
    {
        over();
    }
    rocket.op1 = 1;
    rocket.op2 = -16;
    rocket.op3 = -32;
    goto re;
}
	if ( kbhit() )
	{
	    m = getch();
	    switch ( m )
	    {
	    case LEFT: left();
		break;
	    case RIGHT: right();
		break;
	    case 'q': exit( 0 );
	    }
	}
	else
	{
	    delay( 100 );
	}
	}
	getch();
	return ( 0 );
    }
    void menu()
    {
	int s = 1, t = 0, a, p = 140;
      do
	{
	do
	{
	    cleardevice();
	    setcolor( YELLOW );
	    settextstyle( 1, 0, 4 );
	    outtextxy( 230, 30, "MENU" );
	    settextstyle( 1, 0, 1 );
	    setcolor( 10 );
	    outtextxy( 220, 137, "PLAY GAME" );
	    outtextxy( 220,167, "EXIT" );
	    setcolor( RED );
	    rectangle( 200, p, 350, p + 20 );
	    a = getch();
	    switch ( a )
	    {
	    case UP: if ( p > 140 )
		{
		    p -= 30;
		    s--;

		}
		break;
	    case DOWN: if ( p < 180 )
		{
		    p += 30;
		    s++;
		};
		break;
	    case ENTER: a = 1;
		break;
	    default: break;
	    }
	}
	while ( a != 1 );
	switch ( s )
	{
	case 1: play();
		 break;

	case 2: exit( 0 );
		 break;
	}
	}
	while ( t == 0 );
     }
void main()
    {
	int gd = DETECT, gm;
	initgraph( &gd, &gm, "C:\\TURBOC3\\bgi" );
	cleardevice();
	menu();
	getch();
}
