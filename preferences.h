#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <string>
#include <vector>
#include <map>

using namespace std;

int MaxRight() {return 1200;}
int MaxBottom() {return 800;}

string EMPTY_STRING(){return "//";}

vector<string> VERB_FILENAMES()
{
    vector<string> filenames;
     filenames.push_back("verbDict.txt");
    return filenames;
}

vector<string> VOCAB_FILENAMES()
{
    vector<string> filenames;
    filenames.push_back("expressionDict.txt");
    filenames.push_back("nounDict.txt");
    filenames.push_back("verbDict.txt");
    return filenames;
}

map<string, Dimensions> DIMLIST()
{
    map<string, Dimensions> d;
    d["MAX"]=Dimensions(0, 0, 1200, 600);
    d["SCREEN"]=Dimensions(100, 100, 1100, 500);
    return d;
}

map<string,Colour> PALETTE()
{
    map<string, Colour> p;

    p["PALEPINK"]=Colour(255,204,204);
    p["SALMON"]=Colour(255,153,153);
    p["SOFTSCARLET"]=Colour(242,90,87);
    p["DEEPRED"]=Colour(224,68,64);
    p["DARKRED"]=Colour(192,0,0);
    p["BURGUNDY"]=Colour(129,35,35);
    p["WHITE"]=Colour(255,255,255);
    p["PALESTBLUE"]=Colour(217,226,243);
    p["PALEBLUE"]=Colour(32,50,76); ///p["PALEBLUE"]=Colour(180,198,231);
    p["DIRTYAQUA"]=Colour(84,117,144);
    p["DIMBLUE"]=Colour(0,0,0); ///p["DIMBLUE"]=Colour(32,50,76);

    return p;
}

map<string,TextStyle> STYLES ()
{
    map<string, TextStyle> s;

    s["TS1"]=TextStyle(SANS_SERIF_FONT, 6);
    s["TS4"]=TextStyle(SMALL_FONT, 28);
    s["TS3"]=TextStyle(SCRIPT_FONT, 3);
    s["TS2"]=TextStyle(SMALL_FONT, 8);
    s["TS5"]=TextStyle(SMALL_FONT, 7);

    return s;
}

#endif // PREFERENCES_H
