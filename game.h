#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>

using namespace std;

//***************************************
// GENERAL TOOLS
//***************************************

string num2S (int n) //pass number, return spanish translation
{
    string n_s = toString(n), go3String; //toString
    int thisDigit =0, nextNum =0; //tool variables
    string losdigitos[10]={"", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve"};
    string lasdecenas[10]={"", "diez", "veinte", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa"};
    string lascentenas[10]={"", "ciento", "doscientos", "trescientos", "cuatrocientos", "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos"};

    if (n<10) //1-9
    {
        if (n==0) return "cero";
        return losdigitos[n];
    }

    thisDigit = -'0'+(int)n_s.at(0); //first digit
    nextNum = toInt(toString(n).substr(1, toString(n).size())); //remaining digits

    if (n>=10 && n<100) //10-99
    {
        if (n>=11 && n<=15) //exception numbers
        {
            if (n==11) return "once";
            else if (n==12) return "doce";
            else if (n==13) return "trece";
            else if (n==14) return "catorce";
            else if (n==15) return "quince";
        }
        if (nextNum!=0) return lasdecenas[thisDigit]+" y "+num2S(nextNum);
        return lasdecenas[thisDigit];
    }
    else if (n>=100 && n <1000) //100-999
    {
        if (n==100) return "cien";
        if (nextNum!=0) return lascentenas[thisDigit]+" "+num2S(nextNum);
        return lascentenas[thisDigit];
    }

    int go3Count = ceil(n_s.size()/3.0); //A. make a groups of 3 string. ex. 1234 = 001234, 1 = 001
    for(int i = 0; i<(go3Count*3)-(int)n_s.size(); i++) go3String+="0";
    go3String+=n_s;
    string largeNum = ""; //B. split into groups and create large num
    for (int i=1; i<=go3Count; i++)
    {
        int currentNum = toInt(go3String.substr((i-1)*3, (i*3)));
        if (currentNum>1) largeNum+=num2S(currentNum)+" ";
        if (i<go3Count) largeNum+="mil ";
    }
    if (largeNum.substr(largeNum.size()-1)==" ") largeNum = largeNum.substr(0, largeNum.size()-1);
    return largeNum;
}

//***************************************
// GAME 2 TOOLS
//***************************************

string timeToClockFmt(int h, int m, string de)
{
    string t = "";
    if (h<10) t+="0";
    t+=toString(h)+":";
    if (m<10) t+="0";
    t+=toString(m)+de;
    return t;
}


///ERRORS... 11:46 PM = 12 - 14 de la tarde...
string readTime(int h, int m, string de) //return sentence telling time... MAKE GRAPHIC OF CLOCK?
{
    string t = "";

    if (m>=45)
    {
        if (h==12) h=1;
        else h+=1; ///most likely due to this line
    }

    if (h==1) t+="Es la una";
    else t+="Son las " + num2S(h);

    if (m>=45)
    {
        t+=" menos ";
        m=60-m;
    }
    else if (m!=0) t+=" y ";

    if (m==15) t+="cuarto";
    else if (m==30) t+="media";
    else if (m!=0) t+=num2S(m);

    if (toUppercase(de)=="AM" && h>=6 && h<=11) t+= " de la mañana"; ///ñ not available
    else if (toUppercase(de)=="PM" && ((h>=1 && h<=7) || h==12)) t+=" de la tarde";
    else t+=" de la noche";

    return t;
}

//***************************************
// GAME 4 TOOLS
//***************************************

string conjugate(string subject, VerbType v) //given subj, conjugate to pres tense ... ONLY SUPPORTS REGULAR VERBS
{
    map<string, int> subjIndex;
    subjIndex["yo"]=0;          subjIndex["tu"]=1;
    subjIndex["él"]=2;          subjIndex["ella"]=3;        subjIndex["usted"]=4;
    subjIndex["nosotros"]=5;    subjIndex["vosotros"]=6;
    subjIndex["ellos"]=7;       subjIndex["ellas"]=8;       subjIndex["ustedes"]=9;

    string regEndAR[10]={"o","as","a","a","a","amos", "áis", "an", "an", "an"}; //future: feature to check where to include accent
    string regEndER[10]={"o","es","e","e","e","emos", "éis", "en", "en", "en"};
    string regEndIR[10]={"o","es","e","e","e","imos", "ís", "en", "en", "en"};
    vector<string> AR_end;  AR_end.assign(regEndAR, regEndAR+10);
    vector<string> ER_end;  ER_end.assign(regEndER, regEndER+10);
    vector<string> IR_end;  IR_end.assign(regEndIR, regEndIR+10);

    map<string, vector<string> > findEnding; //notice how space between > > is NECESSARY!!
    findEnding["ar"] = AR_end;  findEnding["er"] = ER_end;  findEnding["ir"] = IR_end;
    string stem[10]={""};

    for(int i = 0; i<10; i++) stem[i] = v.infinitive.substr(0, v.infinitive.size()-2); //base stems
    if (!v.isRegular) //dealing w irregular verbs
    {
        if (v.infinitive=="estar")
        {
            string conjgESTAR[10]={"estoy","estas","está","está","está","estamos","estáis","estan","estan","estan"};
            return subject + " " + conjgESTAR[subjIndex[subject]];
        }
        else if (v.infinitive=="ir")
        {
            string conjgIR[10]={"voy","vas","va","va","va","vamos","vais","van","van","van"};
            return subject + " " + conjgIR[subjIndex[subject]];
        }
        else if (v.infinitive=="ser")
        {
            string conjgSER[10]={"soy","eres","es","es","es","somos","sois","son","son","son"};
            return subject + " " + conjgSER[subjIndex[subject]];
        }
        else if (v.infinitive=="tener" || v.infinitive=="venir")
        {
            string conjgTENER[10]={"eng","ien","ien","ien","ien","en","en","ien","ien","ien"};
            return subject + " " + v.infinitive.at(0) + conjgTENER[subjIndex[subject]] + findEnding[v.infinitive.substr(v.infinitive.size()-2)].at(subjIndex[subject]);
        }
    }
    ///regular verbs
    if (v.stemChange.find("STEM:")!=string::npos) //stem change scenario
    {
        string afterStr;
        string splitThis = v.stemChange.substr(v.stemChange.find("STEM:")+5, v.stemChange.find("STEM:")+6);
        char beforeChar = splitThis.at(0); //find this
        if (v.stemChange.find("1POV:")!=string::npos) afterStr = splitThis.substr(splitThis.find("_")+1, splitThis.find(",")-2);
        else afterStr = splitThis.substr(splitThis.find("_")+1); //replace w this
        for (int x = 0; x<10; x++) //assign to all subj except 1st 2nd person plural (#5,6 in index)
        {
            if (x != 5 && x != 6) stem[x].replace(stem[x].rfind(beforeChar), 1, afterStr); //use r find to find the rightmost character (ex. 2nd e in preferir)
        }
    }
    if (v.stemChange.find("1POV:")!=string::npos) //irreg first person scenario
    {
        string op;
        string irregkun = v.stemChange.substr(v.stemChange.find("1POV:")+5);
        if (stem[0].find(irregkun)!=string::npos) op = stem[0].substr(0, stem[0].rfind(irregkun));
        else if (stem[0].at(stem[0].size()-1)=='n' || stem[0].at(stem[0].size()-1)=='l') op = stem[0].substr(0,stem[0].size());
        else op = stem[0].substr(0,stem[0].size()-1);
        stem[0] = op +irregkun;
    }
    return subject + " " + stem[subjIndex[subject]] + findEnding[v.infinitive.substr(v.infinitive.size()-2)].at(subjIndex[subject]);
}

//***************************************
// GAMES
//***************************************

vector<QuestionType> generateG1QA (int numQ)
{
    vector<QuestionType> QA;
    vector<VocabType> vocabList = initializeVocabDict();
    string inEng, inSpn;
    for (int i = 0; i < numQ; i++)
    {
        VocabType vocab = vocabList.at(rNG(0, vocabList.size()));
        QA.push_back(QuestionType(vocab.english, vocab.spanish));
    }
    return QA;
}

vector<QuestionType> generateG2QA (int numQ)
{
    vector<QuestionType> QA;
    int hour, minute;
    string tOD[2]={"AM", "PM"}, timeOfDay; //time of Day
    for (int i = 0; i < numQ; i++)
    {
        hour = rNG(1,12);
        minute = rNG(0,59);
        timeOfDay = tOD[rNG(0,1)];
        QA.push_back(QuestionType(timeToClockFmt(hour,minute,timeOfDay), readTime(hour,minute,timeOfDay)));
    }
    return QA;
}

vector<QuestionType> generateG3QA (int numQ)
{
    int n;
    vector<QuestionType> QA;
    for (int i = 0; i < numQ; i++)
    {
        n = rNG(0,1253);
        QA.push_back(QuestionType(toString(n), num2S(n)));
    }
    return QA;
}

vector<QuestionType> generateG4QA (int numQ)
{
    vector<QuestionType> QA;

    vector<VerbType> verbList = initializeVerbDict();
    string engSubj[10] = {"I", "you", "he", "she", "you (formal)", "we", "you (pl)", "they (m)", "they (f)", "you (formal) (pl)"};
    string subj[10] = {"yo", "tu", "él", "ella", "usted", "nosotros", "vosotros", "ellos", "ellas", "ustedes"};
    int subjChoice;
    string inEng, inSpn;


    for (int i = 0; i < numQ; i++)
    {
        VerbType verb = verbList.at(rNG(0,verbList.size()-1));

        subjChoice = rNG(0,9);

        inEng = engSubj[subjChoice] + " - " + verb.english;
        inSpn = conjugate(subj[subjChoice], verb); //might be "verb.conjugate(subj[subjChoice])"

        QA.push_back(QuestionType(inEng, inSpn));
    }
    return QA;
}

#endif // GAME_H
