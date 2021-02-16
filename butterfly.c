/*

    Program:        butterfly.c
    Architecture:   Commodore X16 , MOS 6502
    Author:         Ulf Hellstrom, oramininute@gmail.com, Februari 2021
    Puropse:        Just for Fun!!
    
    Note: You need installed the cc65 cross compiler.
    https://github.com/cc65/cc65

    On Mac you can install with Homebrew (INCLUDING NEW M1 MACS) with brew install cc65
    Or you can build c65 yourself directly from github repo.


In October 2010 I was bored and desided to write a small graphical demo in C64 Basic.
I even did a Youtube video about this program and promised a assembler version of it.
The assmebler version i never got around to. Recently I have done some retro programming
again now mainly in CC65 and thought to myself that portin my old Basic demo should be
easy. One for the C64 that is really straight forward and one for the Commander X16

So here comes...
The original Butterfly Basic program 
Implementation in C for the Commander X16.
It runs allot faster then the old C64 Basic Demo did.


The original C64 Basic Code below in the video at
https://www.youtube.com/watch?v=2mOywBhDr94


10 print chr$(147)
20 ca=1024:cp=54272:row=25:col=40
30 poke 53280,0:poke 53281,0
40 forw=3to50:fori=1to12:forj=0to12:k=i+j
50 c=j+j+j/(i+3)+i*w/12
60 k1=ca+i+(col*k):i1=ca+k+(col*i):c1=cp+k1:c2=cp+i1
70 k2=ca+(col-i)+(col*(row-k)):i2=ca+(col-k)+(col*(row-i)):c3=cp+k2:c4=cp+i2
80 k3=ca+(col-i)+(col*k):c5=cp+k3:i3=ca+k+(col*(row-i)):c6=cp+i3
90 k4=ca+(col-k)+(col*i):c7=cp+k4:i4=ca+i+(col*(row-k)):c8=cp+i4
100 pokek1,81:pokec1,c:pokei1,81:pokec2,c
110 pokek2,81:pokec3,c:pokei2,81:pokec4,c
120 pokek3,81:pokec5,c:pokei3,81:pokec6,c
130 pokek4,81:pokec7,c:pokei4,81:pokec8,c
1000 next j,i,w
1100 goto 10

*/

#include <stdlib.h>
#include <stdio.h> 
#include <string.h>
#include <conio.h>

unsigned char XSize, YSize;

void setupvideomode(void) 
{

    // User petscii fonts 
    cbm_k_bsout(CH_FONT_UPPER);
    videomode(VIDEOMODE_40x30);
    //get screensize
    screensize(&XSize, &YSize);

}

void introscreen(void) 
{

    textcolor(COLOR_WHITE);
    bordercolor(COLOR_BLACK);
    bgcolor(COLOR_BLACK);
    cursor (0);
    clrscr();
    gotoxy((XSize/4),YSize/2);
    cprintf("butterfly.\n");
    gotoxy(XSize/4,(YSize/2)+1);
    cprintf("press any key to continue..");
    getchar();

}

void setdefaultvideomode(void) 
{

    videomode(VIDEOMODE_80x60);
    bgcolor(COLOR_BLUE);
    bordercolor(COLOR_BLUE);
    textcolor(COLOR_WHITE);
    clrscr();
    cursor(1);

}

void butterfly(void) 
{
    unsigned int c, w, i ,j, k;

    clrscr();

    for ( w = 3; w < 50; w++)
    {
        for ( i = 1; i < 12; i++ )
        {
            for (j = 0; j < 12; j++)
            {
                k = i + j;
                c = (j + j + j) / (i + 3) + i*w / 12;
                gotoxy(i,k); textcolor(c); printf("%c",113);
                gotoxy(k,i); textcolor(c); printf("%c",113);
                gotoxy(40-i,25-k); textcolor(c); printf("%c",113);
                gotoxy(40-k,25-i); textcolor(c); printf("%c",113);
                gotoxy(k,25-i); textcolor(c); printf("%c",113);
                gotoxy(40-i,k); textcolor(c); printf("%c",113);
                gotoxy(i,25-k); textcolor(c); printf("%c",113);
                gotoxy(40-k,i); textcolor(c); printf("%c",113);
            }
        }
    }
}

int main(void) 
{
    setupvideomode();
    introscreen();
    butterfly();
    setdefaultvideomode();
    return 0;
}