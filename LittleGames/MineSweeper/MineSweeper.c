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


void show_map(char pmap[][COL], char rows, char cols)
{
    char i=0, j=0;
    printf("\t");
    for (j=0; j<cols; j++) {
        printf("%d ", j);
    }
    printf("\r\n");
    for (i=0; i<rows; i++) {
        printf("%d\t", i);
        for (j=0; j<cols; j++) {
            printf("%c ", pmap[i][j]);
        }
        printf("\r\n");
    }
}

void check_mine(int row, int col)
{
    if ('X' == field[row][col]) {
        map[row][col] = 'X';
    } else {
        //Calculate surrounding mines
        //map[row][col] = ' ';
        //map[row][col] = field[row-1][col-1] + \
        //                field[row-1][col] + \
        //                field[row-1][col+1] + \
        //                field[row][col-1] + \
        //                field[row][col+1] + \
        //                field[row+1][col-1] + \
        //                field[row+1][col] + \
        //                field[row+1][col+1];
        char i=0, j=0;
        //for (i=row-1; i<=row+1; i++) {
        //    for (j=col-1; j<=col+1; j++) {
        //    }
        //}
        map[row][col] = '0';
        for (i=(row?(row-1):row); i<=((row==9)?row:(row+1)); i++) {
            for (j=(col?(col-1):col); j<=((col==9)?col:(col+1)); j++) {
                //printf("Field[%d][%d] = %c\r\n", i, j, field[i][j]);
                if ('X' == field[i][j]) {
                    map[row][col]++;
                }
            }
        }
    }
}

int main(void)
{
    int x=0, y=0;
    init_map();
    init_field();
    printf("Hello, Mine Sweeper!\r\n");
    show_map(field, ROW, COL);        //For debug.

    while (1) {
        //Ask user to input position to discover
        printf("Please input position as \"row col\":");
        scanf("%d %d", &x, &y);
        //Check mine in field
        printf("Input row: %d, col: %d.\r\n", x, y);
        check_mine(x, y);
        //Refresh map
        show_map(map, ROW, COL);
    }
    return 0;
}
