// NOTE: compile with g++ filename.cpp -std=c++11  
#include <stdio.h>	//<iostream>
#include <math.h>	//<cmath>
#include <stdlib.h>	//<cstdlib>

#define DIM 1024 	//256*4
#define DM1 (DIM-1) 
#define _sq(x) ((x)*(x)) // square 
#define _cb(x) abs((x)*(x)*(x)) // absolute value of cube 
#define _cr(x) (unsigned char)(pow ((x),1.0/3.0)) // cube root
 
unsigned char GR(int,int);
unsigned char BL(int,int);
 
unsigned char RD(int i,int j){
	//j-512或i-512	使图像奇点位于色卡中心
	//atan(j/i) 	反正切函数，取值范围(-pi/2, +pi/2) ; 对象限不敏感
	//atan2(j,i) 	四象限反正切函数，取值范围(-pi, pi); 对象限敏感，相当于从x轴转的角度，也就是极角θ，这样得到的图像是一个“四射发散”的图像。
	//atan2(j-512,i-512)/2 就是取值范围(-pi/2, +pi/2)的连续数值,在数轴上画出来，是i=(-512, +512),j=(-512, +512)围起来的正方形上每个点到原点的弧度。
	//cos(-pi/2~+pi/2)就是0->1->0不断变化的值
	//则cos()*255就是0->0xFF->0不断变化的值
	//而_sq( cos() )*255 从实际效果上看到的是颜色过度更加平滑、柔和。			
	return (char) (_sq(cos(atan2(j-512,i-512)/2))*255);
	//return 0x55;
}
unsigned char GR(int i,int j){
	//类似于RD的计算，先有(cos(atan2(j-512,i-512)/2))*255
	//但这样会得到和RD相同峰值的位置，图上显示会有白色，所以将其相位调整120°(-2pi/3)
	//但调整了相位之后，cos就会出现负值，对应到图像上就会有2块渐变色，所以使用_sq将其变为正值且连续。
	return (char) (_sq(cos(atan2(j-512,i-512)/2-2*acos (-1)/3))*255);
	//return 0xAA;
}
unsigned char BL(int i,int j){
	//与GR计算同理，只是将相位调整为正的120°，这样3个颜色各相差120°
	return (char) (_sq(cos(atan2(j-512,i-512)/2+2*acos (-1)/3))*255);
	//return 0xAA;
}
 
void pixel_write(int,int);
FILE *fp;
int main (){
    fp = fopen("MathPic.ppm","wb");
    fprintf(fp, "P6\n%d %d\n255\n", DIM, DIM);
    for(int j=0;j<DIM;j++)
        for(int i=0;i<DIM;i++)
            pixel_write(i,j);
    fclose(fp);
    return 0;
}
void pixel_write(int i, int j){
    static unsigned char color[3];
    color[0] = RD(i,j)&255;
    color[1] = GR(i,j)&255;
    color[2] = BL(i,j)&255;
    fwrite(color, 1, 3, fp);
}
