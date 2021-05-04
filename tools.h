#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

template <typename T> string toString(T val)
{
    stringstream stream;
    stream << val;
    return stream.str();
}

int toInt(string s)
{
    int n;
    if ( ! (istringstream(s) >> n) ) n = 0;
    return n;
}

int rNG(int minVal, int maxVal)
{
    return minVal + (rand() % (maxVal - minVal) + 1);
}

string toUppercase(string text)
{
    string newtxt;
    for (int i=0; i<(int)text.size(); i++)
    {
        if (text.at(i)>='a' && text.at(i)<='z') newtxt+=text.at(i)-('a'-'A');
        else newtxt+=text.at(i);
    }
    return newtxt;
}

string toLowercase(string text)
{
    string newtxt;
    for (int i=0; i<(int)text.size(); i++)
    {
        if (text.at(i)>='A' && text.at(i)<='Z') newtxt+=text.at(i)+('a'-'A');
        else newtxt+=text.at(i);
    }
    return newtxt;
}

bool isCorrectAnswer (string userInput, string trueAnswer)
{
    if (userInput==trueAnswer) return true;
    return false;
}

//******************************************
// string formatted line -> structure type
//******************************************

VerbType processVerbLine (string line)
{
    string term="", term2="", term3="";
    int i=-1;
    while(++i<(int)line.size() && line.at(i)!=';') term+=line.at(i);
    while(++i<(int)line.size() && line.at(i)!=';') term2+=line.at(i);
    while(++i<(int)line.size() && line.at(i)!=';') term3+=line.at(i);

    if (term3=="") return VerbType(term,term2);
    else if (term3=="true"||term3=="false")
    {
        if (term3=="true") return VerbType(term, term2, true);
        else return VerbType(term, term2, false);
    }
    return VerbType(term,term2,term3);
}

VocabType processVocabLine(string line)
{
    //cout<<"\n\nMETOKUR";
    string term="", term2="";
    int i=-1;
    while(++i<(int)line.size() && line.at(i)!=';') term+=line.at(i);
    while(++i<(int)line.size() && line.at(i)!=';') term2+=line.at(i);

    return VocabType(term,term2);
}

//***************************************
// string filename -> vector<verbType>
//***************************************

vector<VerbType> fileToVerbList(string fnStr, vector<VerbType> currList)
{
    vector<VerbType> verbDict = currList;
    char fileName[fnStr.size()+1];
    strcpy(fileName, fnStr.c_str()); //string -> char array

    ifstream inFile; //input file variable
    inFile.open(fileName, ios_base::in| ios_base::app); //file name
    if (!inFile.is_open()) cerr<<fileName<<" file cannot be opened.\n";

    char ch;
    string fileContents="";

    while(inFile.get(ch))
    {
        //cout<<"BOSSANOVA";
        if (ch=='\n' && fileContents!="")
        {
            verbDict.push_back(processVerbLine(fileContents));
            fileContents="";
        }
        else fileContents+=ch; //read file and add to s
    }

    inFile.close();
    return verbDict;
}

vector<VocabType> fileToVocabList(string fnStr, vector<VocabType> currList) ///NOT WORKING
{
    vector<VocabType> vocabDict = currList; ///
    char fileName[fnStr.size()+1];
    strcpy(fileName, fnStr.c_str()); //string -> char array

    ifstream inFile; //input file variable
    inFile.open(fileName, ios_base::in| ios_base::app); //file name
    if (!inFile.is_open()) cerr<<fileName<<" file cannot be opened.\n";

    char ch;
    string fileContents="";

    while(inFile.get(ch))
    {
        if (ch=='\n' && fileContents!="")
        {
            VocabType line = processVocabLine(fileContents);
            vocabDict.push_back(line); ///
            fileContents="";
        }
        else fileContents+=ch; //read file and add to s
    }
    inFile.close();
    return vocabDict;
}

//***************************************
// initialize dictionaries
//***************************************

vector<VerbType> initializeVerbDict()
{
    vector<VerbType> newDict;
    for (int i = 0; i < (int)VERB_FILENAMES().size(); i++) {newDict = fileToVerbList(VERB_FILENAMES().at(i), newDict);}
    return newDict;
}

vector<VocabType> initializeVocabDict()
{
    vector<VocabType> newDict;
    for (int i = 0; i < (int)VOCAB_FILENAMES().size(); i++) {newDict = fileToVocabList(VOCAB_FILENAMES().at(i), newDict);}
    return newDict;
}

#endif // TOOLS_H

