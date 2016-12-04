#include <stdlib.h>
#include <string.h>
#include <stdio.h>

const int W      = 12;         // ширина рабочего поля
const int H      =  8;         // высота рабочего поля
const char WALL   = '#';         // непроходимая ячейка
const char BLANK  = '.';         // свободная непомеченная ячейка
const char DOG = '@';         //ячейка с монстром

int px[W * H], py[W * H];      // координаты ячеек, входящих в путь
int len;                       // длина пути
char map[H][W];                // рабочее поле


// Перед вызовом lee() массив map заполнен значениями WALL и BLANK

void init(){
int i, j;

for(i = 0; i < H; i++)

{
    for(j = 0; j < H; j++ ) scanf("%c",&map[i][j]);
}
}

int lee(int ax, int ay, int bx, int by)   // поиск пути из ячейки (ax, ay) в ячейку (bx, by)
{
    int dx[4] = {1, 0, -1, 0};   // смещения, соответствующие соседям ячейки
    int dy[4] = {0, 1, 0, -1};   // справа, снизу, слева и сверху
    int d, x, y, k;
    int stop;
    
    if (map[ay][ax] == WALL || map[by][bx] == WALL) return -1;  // ячейка (ax, ay) или (bx, by) - стена
    
    // распространение волны
    d = 0;
    map[ay][ax] = 0;            // стартовая ячейка помечена 0
    do {
        stop = 1;               // предполагаем, что все свободные клетки уже помечены
        for ( y = 0; y < H; ++y )
            for ( x = 0; x < W; ++x )
                if ( map[y][x] == d )                         // ячейка (x, y) помечена числом d
                {
                    for ( k = 0; k < 4; ++k )                    // проходим по всем непомеченным соседям
                    {
                        int iy=y + dy[k], ix = x + dx[k];
                        if ( iy >= 0 && iy < H && ix >= 0 && ix < W &&
                            map[iy][ix] == BLANK )
                        {
                            stop = 0;              // найдены непомеченные клетки
                            map[iy][ix] = d + 1;      // распространяем волну
                        }
                    }
                }
        d++;
    } while ( !stop && map[by][bx] == BLANK );
    
    if (map[by][bx] == BLANK) return -1;  // путь не найден
    
    // восстановление пути
    len = map[by][bx];            // длина кратчайшего пути из (ax, ay) в (bx, by)
    x = bx;
    y = by;
    d = len;
    while ( d > 0 )
    {
        px[d] = x;
        py[d] = y;                   // записываем ячейку (x, y) в путь
        d--;
        for (k = 0; k < 4; ++k)
        {
            int iy=y + dy[k], ix = x + dx[k];
            if ( iy >= 0 && iy < H && ix >= 0 && ix < W &&
                map[iy][ix] == d)
            {
                x = x + dx[k];
                y = y + dy[k];           // переходим в ячейку, которая на 1 ближе к старту
                break;
            }
        }
    }
    px[0] = ax;
    py[0] = ay;                    // теперь px[0..len] и py[0..len] - координаты ячеек пути
    int i;
    for(i=0;i<len;i++){
        printf("%c %c",px[i],py[i]);
    }
    return 0;
}

int main(){
    init();
    lee(3, 6, 3, 0);                 // поиск пути из ячейки (3,6) в ячейку (3, 0) (см. рис.)
}