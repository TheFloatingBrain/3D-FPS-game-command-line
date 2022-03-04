#if defined(_WIN32) || defined(__CYGWIN__)
	#include <windows.h>
#else
	typedef long int LONG;
	typedef struct tagPOINT {
		LONG x;
		LONG y;
	} POINT;
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "settings.h"
#include "collision.h"
#include "keyboard.h"

POINT p;

extern double playerX;
extern double playerY;
extern double playerA;

extern double gunx;
extern double guny;
extern double ban;
extern double enx;
extern int shoot;
extern int shet;
extern int re;
extern int restart;
extern int se;
extern int EXIT;
extern char cs;

double cameraz = 3.00;

extern double radians (double a);

void cameramove(void){
    cameraz = cos(shet * 0.2) * 2 + 3;
}



void update(void){
        if(ReadKey(87) && collision(playerX + (speed * coloffset) * cos(radians(playerA)), playerY + speed * sin(radians(playerA)))){
            playerX += speed * cos(radians(playerA));
            playerY += speed * sin(radians(playerA));
            cameramove();
        }
        if(ReadKey(83) && collision(playerX - (speed * coloffset) * cos(radians(playerA)), playerY - speed * sin(radians(playerA)))){
            playerX -= speed * cos(radians(playerA));
            playerY -= speed * sin(radians(playerA));
            cameramove();
        }
        if(ReadKey(65) && collision(playerX + (speed * coloffset) * cos(radians(playerA)), playerY - speed * sin(radians(playerA)))){
            playerX += speed * sin(radians(playerA));
            playerY -= speed * cos(radians(playerA));
            cameramove();
        }
        if(ReadKey(68) && collision(playerX - (speed * coloffset) * cos(radians(playerA)), playerY + speed * sin(radians(playerA)))){
            playerX -= speed * sin(radians(playerA));
            playerY += speed * cos(radians(playerA));
            cameramove();
        }
        if(ReadKey(32)){
            if(!shoot && !re && !restart){
                shoot = 1;
                se = 1;
            }
        }
        if(ReadKey('B') && cs == 's')
            ban = 1;
        if(ReadKey(EXIT_CODE))
            EXIT = 1;
}



