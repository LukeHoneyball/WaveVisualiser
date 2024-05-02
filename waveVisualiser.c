/*

-----Angle Visualiser-----
-----By Luke Honeyball----
--------4/29/2024---------
*/
#include <stdio.h>
#include <windows.h>
#define _USE_MATH_DEFINES
#include <math.h> //imports
#define PI  3.1
#define width 200 //you can set your own width and height of the output here
#define height 30
int map[width][height];
int amplitude = 15;
int freq = 6;

void drawPixels(){
    for(int y = 0; y < height; y++){
        for(int x = 0; x< width;x++){
        if(map[x][y] == 1){
                printf("X");
            }else{
                printf(".");
            }
        
    }
    printf("\n");
    }
    
}

void drawWave(){//f this its so hard bruh
    for(int x = 0; x< width; x++){
        
        int y = amplitude * sin(2*PI * (x/(amplitude / freq)));
        
        map[x][(height / 2) + y] = 1;
    }
}

void setPixelsZero(){
    for(int x = 0; x< width;x++){
        for(int y = 0; y < height; y++){
            map[x][y] = 0;
        }
    }
}



void main(){
    
    setPixelsZero();
    int f;
    int a ;
    printf("Enter a frequency from 0 - 1000 hz: ");
    scanf("%d",&f);
    printf("Enter amplitude from 1-3:");
    scanf("%d",&a);
    amplitude = 12 + a;
    freq = ((f+90)/80);

    drawWave();
    drawPixels();



}
