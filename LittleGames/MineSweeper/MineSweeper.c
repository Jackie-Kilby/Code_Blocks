#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW    10    
#define COL    10
#define MINE_NUM_SET    10

char map[ROW][COL] = {};
char field[ROW][COL] = {};

void init_map(void)
{
    char i=0, j=0;
    for (i=0; i<ROW; i++) {
        for (j=0; j<COL; j++) {
            map[i][j] = '*';
        }
    }
}

void init_field(void)
{
    char i=0, j=0;
    char mine_cnt = 0;
    
    srand(time(NULL));
        
    //Init field with blank
    for (i=0; i<ROW; i++) {
        for (j=0; j<COL; j++) {
            field[i][j] = ' ';
        }
    }
    //Set mines
    for (mine_cnt=0; mine_cnt<MINE_NUM_SET; ) {
        i = rand() % ROW;
        j = rand() % COL;
        if (field[i][j] != 'X') {
            field[i][j] = 'X';
            mine_cnt ++;
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

void refresh_field(void)
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
            printf("%c ", field[i][j]);
        }
        printf("\r\n");
    }
}

int main(void)
{
    int x;
    init_map();
    init_field();
    printf("Hello, Mine Sweeper!\r\n");
    refresh_field();        //For debug.

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
