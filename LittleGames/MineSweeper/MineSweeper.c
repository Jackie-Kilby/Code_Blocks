#include <stdio.h>

#define ROW    10    
#define COL    10

char map[ROW][COL] = {}; 

void init_map(void)
{
    char i=0, j=0;
    for (i=0; i<ROW; i++) {
        for (j=0; j<COL; j++) {
            map[i][j] = '*';
        }
    }
}

void refresh_map(void)
{
    char i=0, j=0;
    printf("\t");
    for (j=0; j<COL; j++) {
        printf("%d ", j);
    }
    printf("\r\n");
    for (i=0; i<ROW; i++) {
        printf("%d\t", i);
        for (j=0; j<COL; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\r\n");
    }
}



int main(void)
{
    int x;
    init_map();
    //Init field
    printf("Hello, Mine Sweeper!\r\n");

    while (1) {
        //Ask user to input position to discover
        printf("Please input a num:");
        scanf("%d", &x);
        //Check mine in field
        //Refresh map
        refresh_map();
    }
    return 0;
}
