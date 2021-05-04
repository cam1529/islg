#include<iostream>
#include <string>
#include <graphics.h>
#include <conio.h>
#include <cstdlib>
#include <bits/stdc++.h>
#include <windows.h>
#include <map>

#include "structures.h"
#include "preferences.h"
#include "tools.h"
#include "game.h"
#include "graphics_tools.h"
#include "screens.h"

using namespace std;

int main()
{
    srand(time(NULL));
    initwindow(MAXRIGHT, MAXBOTTOM);

    UserStats user;
	int nextPageNum = loadPage(1, &user); //Intro
	while (nextPageNum!=0) nextPageNum = loadPage(nextPageNum, &user);

    getch();
    return 0;
}
