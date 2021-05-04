#ifndef GRAPHICS_TOOLS_H
#define GRAPHICS_TOOLS_H

#include <string>
#include <vector>
#include <windows.h>
#include <winuser.h>

#define MAXCHARSIZE 64
#define MAXRIGHT 1200
#define MAXBOTTOM 600
#define LEFT 100
#define TOP 100
#define RIGHT 1100
#define BOTTOM 500

using namespace std;

roundedRectangle (int diameter, Dimensions d)
{
    int left = d.left, top = d.top, right = d.right, bottom = d.bottom;
	bar(left-diameter, top, right+diameter, bottom);
	bar(left, top-diameter, right, bottom+diameter);
	fillellipse(left, top, diameter, diameter); //TL
	fillellipse(right,top, diameter,diameter); //TR
	fillellipse(left,bottom,diameter,diameter); //BL
	fillellipse(right,bottom,diameter,diameter); //BR
}

string getKeyInput(string s)
{
    char g = getch();
    string newStr=s;
    //cout<<" welliminhere ";
    if (g=='\r') return newStr + EMPTY_STRING();
    if (g==8&&s.size()<=1) return ""; //BACKSPace
    else if (g==8 &&s.size()>1)
        return newStr=newStr.substr(0,newStr.size()-1); //BACKSPACE

    else if ((g>='A' && g<='Z')||(g>='a' && g<='z')||g==' ') newStr+=g; //regular letter
    else if (g=='/' || g=='~') //accent
    {
        char prevLetter = s.at(s.size()-1);
        if (g=='~' && prevLetter=='n') g='ñ';
        else //not good. will go here if g=~ and prev not n.
        {
            switch(prevLetter)
            {
                case 'a' : g='á'; break;
                case 'e' : g='é'; break;
                case 'i' : g='í'; break;
                case 'o' : g='ó'; break;
                case 'u' : g='ú'; break;
                default : return newStr; //no changes
            }
        }
        return newStr.substr(0,newStr.size()-1)+g;
    }
    return newStr;
}

int activateClick(PageStats page)
{
    int xpos;
    int ypos;
    vector<Dimensions> dimensionOptions = page.linkDimensions;
    vector<int> toPage = page.toPage;

    while(1) //continuously check for mouse coordinates
    {
        while (ismouseclick(WM_MOUSEMOVE))
        {
            getmouseclick(WM_MOUSEMOVE, xpos, ypos); //windows.h
            delay(10);
        }
        for (int i = 0; i < (int)dimensionOptions.size(); i++)
        {
            Dimensions dim = dimensionOptions.at(i);
            if(dim.contains(xpos, ypos)) //hovering over actionable dimension
            {
                if(GetAsyncKeyState(VK_LBUTTON)) {return toPage[i];}
            }
        }
    }
}

void displayAnswerBool (string userInput, string trueAnswer, int x, int y)
{
    PALETTE().at("PALEBLUE").setBg();
    PALETTE().at("SOFTSCARLET").setClr();
    if (userInput==trueAnswer) STYLES().at("TS3").outText(x,y,"CORRECT!");
    else STYLES().at("TS3").outText(x,y,"WRONG, the correct answer was: "+trueAnswer);
}

void displayQuitScreenBox()
{
    PALETTE().at("SOFTSCARLET").setBg();
    PALETTE().at("WHITE").setClr();
    STYLES().at("TS3").outText(LEFT+355,TOP+200,"...QUITTING SCREEN...");
    delay(5000);
}

void showStars (int colour, Dimensions d)
{
    int Left = d.left, Top = d.top, Right = d.right, Bottom = d.bottom;
    int i, x, y;
    for(i=0; i<=400; i++) //400 stars
    {
        x = rNG(Left, Right);
        y = rNG(Top, Bottom);
        putpixel(x,y,colour);
    }
}

#endif // GRAPHICS_TOOLS_H
