#ifndef MENU_H
#define MENU_H

typedef struct{
    int pilihan;
    int running;
} menu;


void pilihMenu(menu *state);

#endif