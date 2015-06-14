/* This is a silly modification 
   of Toyoda Masashi's SL package
   that removes the train and adds doge instead
   Original github repo is at: 
   https://github.com/mtoyoda/sl
*/

#include <stdlib.h>
#include <curses.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include "sl.h"

void add_smoke(int y, int x);
void add_man(int y, int x);
int add_doge(int x);
void option(char *str);
int my_mvaddstr(int y, int x, char *str);

int my_mvaddstr(int y, int x, char *str)
{
    for ( ; x < 0; ++x, ++str)
        if (*str == '\0')  return ERR;
    for ( ; *str != '\0'; ++str, ++x)
        if (mvaddch(y, x, *str) == ERR)  return ERR;
    return OK;
}

int main(int argc, char *argv[])
{
    int x, i;

    initscr();
    signal(SIGINT, SIG_IGN);
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    leaveok(stdscr, TRUE);
    scrollok(stdscr, FALSE);

    for (x = COLS - 1; ; --x) {
        if(add_doge(x) == ERR) break;
        getch();
        refresh();
        usleep(30000);
    }

    mvcur(0, COLS - 1, LINES - 1, 0);
    endwin();
    system("clear");
}

int add_doge(int x)
{
  if(x < -50) return ERR;
  static char *doge[22] 
    = { DOGESTR1,  DOGESTR2,  DOGESTR3,  DOGESTR4,  DOGESTR5,  DOGESTR6,
        DOGESTR7,  DOGESTR8,  DOGESTR9,  DOGESTR10, DOGESTR11, DOGESTR12,
        DOGESTR13, DOGESTR14, DOGESTR15, DOGESTR16, DOGESTR17, DOGESTR18,
        DOGESTR19, DOGESTR20, DOGESTR21, DOGESTR22 };
  for (int i = 0; i < 21; i++) {
    my_mvaddstr(i + 2, x, doge[i]);
  }
  return OK;
}
