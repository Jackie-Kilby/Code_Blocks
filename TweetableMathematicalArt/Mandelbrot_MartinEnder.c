// NOTE: compile with gcc filename.c
#include <stdio.h>	//<iostream>
#include <math.h>	//<cmath>
#include <stdlib.h>	//<cstdlib>

#define DIM 1024 
#define DM1 (DIM-1) 
#define _sq(x) ((x)*(x)) // square 
#define _cb(x) abs((x)*(x)*(x)) // absolute value of cube 
#define _cr(x) (unsigned char)(pow ((x),1.0/3.0)) // cube root
 
unsigned char GR(int,int);
unsigned char BL(int,int);
 
unsigned char RD(int i,int j){
	float x=0,y=0;
	int k;
	for(k=0;k++<256;){
		float a=x*x-y*y+(i-768.0)/512;
		y=2*x*y+(j-512.0)/512;
		x=a;
		if(x*x+y*y>4)
			break;
	}
	return k>31?256:k*8;
}
unsigned char GR(int i,int j){
	float x=0,y=0;
	int k;
	for(k=0;k++<256;){
		//计算负数的平房，设Z=x+yi, 则Z*Z=x*x-y*y+2xyi
		//i,j为当前坐标，(i-768.0)/512与(j-512.0)/512，代表图像中心点在(768,512)位置
		//注意：(i-768.0)/512中768.0一定要写".0"才会被认为是浮点型，否则会出现虽然整体计算是浮点型，但先算(i-768)/512作为整形，得到0或+1.则图像错误。
		//所以，如果取图像中心点为(0,0)，则应写为
//		float a=x*x-y*y+(i-0.0)/512;
//		y=2*x*y+(j-0.0)/512;
		float a=x*x-y*y+(i-768.0)/512;
		y=2*x*y+(j-512.0)/512;
		x=a;
		//逃逸判据:当Z*Z>4时，认为该点不属于曼德勃罗特集合，停止迭代。
		//判据越大，则在逃逸范围之内的点越多，图像散射越厉害。
		if(x*x+y*y>4)
			break;
	}
	//k>N?A:B,其中N越大，图像边缘越清晰，A影响分型图内部的颜色，B影响分型图背景颜色
	//N代表满足逃逸时的迭代次数，则迭代次数越多，图像越清晰，放大后可以看到更多细节。
	return k>63?256:k*4;
}
unsigned char BL(int i,int j){
	float x=0,y=0;
	int k;
	for(k=0;k++<256;){
		float a=x*x-y*y+(i-768.0)/512;
		y=2*x*y+(j-512.0)/512;
		x=a;
		if(x*x+y*y>4)
			break;
	}
	//没有满足逃逸时的迭代次数，也就是对于蓝色没有迭代次数限制。则蓝色会产生无晕影的渐变效果。
	return k;
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
