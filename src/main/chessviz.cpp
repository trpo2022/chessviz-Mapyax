#include "move.h"
#include "print.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    char desk[desk_size][desk_size]
        = { {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
           {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
           {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
           {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'} };

    motion motion = { 0, 0, 0, 0 };
    printdesk(desk);
    string line;
    float turnnumber = 1;
    bool moveW = true;
    while (true) {
        printf("%d. ", (int)turnnumber);
        turnnumber += 0.5;
        getline(cin, line);
        if (turn(&line, motion, desk, moveW) != 0) {
            printf("Try again\n");
            turnnumber -= 0.5;
            continue;
        };
        printdesk(desk);
        printf("\n");
        if ((line.size() > 6) && (line.at(6) == '#') || (line.size() > 5) && (line.at(5) == '#')) {
            if (moveW == true)
                printf("Black Wins!\n");
            ;
            if (moveW == false)
                printf("White Wins!\n");
            break;
        }
        moveW = !moveW;
    }
    return 0;
}

