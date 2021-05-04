#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <string>
#include <vector>
#include <math.h>

using namespace std;

struct VerbType
{
    string infinitive;
    string english;
    bool isRegular;
    string stemChange;

    VerbType(){}
    VerbType(string v, string e):infinitive(v), english(e), isRegular(true), stemChange(""){}
    VerbType(string v, string e, bool reg):infinitive(v), english (e), isRegular(reg), stemChange(""){}
    VerbType(string v, string e, string sc):infinitive(v), english (e), isRegular(true), stemChange(sc){}

    string toString()
    {
        cout<<"\nVERBTYPE OBJECT...";
        cout<<"\ninfinitive: "<<infinitive;
        cout<<"\nenglish: "<<english;
        cout<<"\nisRegular? "<<isRegular;
        cout<<"\nstemChange: "<<stemChange;
    };
};

struct VocabType
{
    string spanish;
    string english;

    VocabType():spanish(""), english(""){}
    VocabType(string s, string e):spanish(s), english(e){}

    string toString()
    {
        cout<<"\nVOCABTYPE OBJECT...";
        cout<<"\nspanish: "<<spanish;
        cout<<"\nenglish: "<<english;
    };
};

struct QuestionType
{
    string question;
    string answer;

    QuestionType():question(""), answer(""){}
    QuestionType(string q, string a):question(q), answer(a){}
};

struct Dimensions
{
    int left;
    int top;
    int right;
    int bottom;
    Dimensions(){}
    Dimensions(int l, int t, int r, int b):left(l), top(t), right(r), bottom(b){}

    bool contains(int x, int y) {return (x>=left && x<=right && y>=top && y<=bottom);};
};

struct Colour
{
    int r;
    int g;
    int b;

    Colour(){}
    Colour(int red, int green, int blue):r(red), g(green), b(blue){}

    void setBg() {setbkcolor(RGB(r,g,b));};
    void setClr() {setcolor(RGB(r,g,b));};
    void setFill(int fillStyle)
    {
        setClr();
        setfillstyle(fillStyle, RGB(r,g,b));
    };
    void setFill(int style, Colour bg)
    {
        bg.setBg();
        setFill(style);
    };
};

struct TextStyle
{
    int font;
    int fontSize;

    TextStyle(){}
    TextStyle(int f, int fs):font(f),fontSize(fs){}

    void setThis() {settextstyle(font, HORIZ_DIR, fontSize);};
    void setThis(Colour c) {c.setClr(); setThis();};
    void setThis(Colour bg, Colour c) {bg.setBg(); setThis(c);};
    void outText(int x, int y, string text)
    {
        char t[text.size()+1];
        strcpy(t, text.c_str());
        outtextxy(x, y, t);
    };
    void outText(Colour bg, Colour c, int x, int y, string text)
    {
        setThis(bg, c);
        outText(x,y,text);
    };
};

struct UserStats
{
    string username;
    int qCount; //over all games
    int aRight;

    UserStats():username(""), qCount(0), aRight(0){}
    UserStats(string name):username(name), qCount(0), aRight(0){}

    double getAverage() {return (aRight*100.0)/qCount;};

    void updateStats(int qCount, int aRight)
    {
        (*this).qCount += qCount;
        (*this).aRight += aRight;
    };
};

struct PageStats
{
    int qCount; //over one game
    int aRight;
    vector<Dimensions> linkDimensions;
    vector<int> toPage;

    PageStats():qCount(0), aRight(0){}
    PageStats(int qC):qCount(qC), aRight(0){}

    void addLink(Dimensions d, int pageNum)
    {
        linkDimensions.push_back(d);
        toPage.push_back(pageNum);
    };
};


#endif // STRUCTURES_H
