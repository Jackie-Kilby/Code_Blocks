// NOTE: compile with gcc filename.c  
#include <stdio.h>	//<iostream>
#include <math.h>	//<cmath>
#include <stdlib.h>	//<cstdlib>
#include <time.h>

#define DIM 1024 
#define DM1 (DIM-1) 
#define _sq(x) ((x)*(x)) // square 
#define _cb(x) abs((x)*(x)*(x)) // absolute value of cube 
#define _cr(x) (unsigned char)(pow ((x),1.0/3.0)) // cube root
 
unsigned char GR(int,int);
unsigned char BL(int,int);
 
unsigned char RD(int i,int j){
	static int initialized_flag = 0;
	if (!initialized_flag) {
		srand(time(NULL));
		initialized_flag = 1;
	}

#define r(n) (rand()%n) 
	static char c[1024][1024] = {0};
	//!A?B?C:D:E = !A ? (B?C:D) : E
	//如果A则E，对应如果c[i][j]有值，则返回c[i][j]
	//如果!A，则c[i][j]还没有赋值，那么就要给c[i][j]赋值
	//(B?C:D)的逻辑，如果r(999)==0，则c[i][j]=r(256)，这是个低概率事件;
	//               如果r(999)!=0，则嵌套执行RD
	//此时RD有4种可能：
	//		RD(i+0, j+0) 仍然是这个点，会再次嵌套
	//		RD(i+0, j+1), RD(i+1, j+0), RD(i+1, j+1) 是相邻点的值
	//直到某一个点RD(i+N, j+M)时发生r(999)==0，获取到一个c[i+N, j+M]=r(256)的非零值，则嵌套回去的一串RD(i,j)都是这个r(256)，形成色块。
	//所以r(999)==0的概率对应了一个色块的大小，调整r(N)中的N值，可以看到色块大小的变化。
	//return !c[i][j]?c[i][j]=!r(2)?r(256):RD ((i+r(2))%1024,(j+r(2))%1024):c[i][j];  //颗粒纹理
	//return !c[i][j]?c[i][j]=!r(50000)?r(256):RD ((i+r(2))%1024,(j+r(2))%1024):c[i][j]; //栈调用过深，程序异常
	//RD(i+r(N)%1024, j+r(M)%1024)中的M/N代表斜率，M,N的值影响色块的宽度（isotropic，各向同性）
	return !c[i][j]?c[i][j]=!r(999)?r(256):RD ((i+r(2))%1024,(j+r(2))%1024):c[i][j];
	return 0x0;
	}
unsigned char GR(int i,int j){
	static char c[1024][1024];
	return !c[i][j]?c[i][j]=!r(999)?r(256):GR ((i+r(2))%1024,(j+r(2))%1024):c[i][j];
	return 0x0;
}
unsigned char BL(int i,int j){
	static char c[1024][1024];
	//return !c[i][j]?c[i][j]=!r(999)?r(256):BL ((i-r(2))%1024,(j+r(2))%1024):c[i][j];  //相当于增加了一个斜率为1的蓝色浪潮透镜
	//return !c[i][j]?c[i][j]=r(999)?BL((i+r(5)+1022)%1024,(j+r(5)+1022)%1024):r(256):c[i][j];  //树叶形状的斑驳色块
	return !c[i][j]?c[i][j]=!r(999)?r(256):BL ((i+r(2))%1024,(j+r(2))%1024):c[i][j];
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
