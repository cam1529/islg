#ifndef SCREENS_H
#define SCREENS_H

#include <string>
#include <vector>

#define GAMEQCOUNT 1

using namespace std;

string getKeyInputLine (int y, string currentWord, int maxCharSize, int charIndent) ///intro: y = TOP+217, charIndent = 220
{
    Colour bg = PALETTE().at("PALEBLUE");
    Colour c = PALETTE().at("PALEPINK");
    string wordsofar = currentWord, last2Char="";
    STYLES().at("TS2").outText(bg, PALETTE().at("PALEPINK"),LEFT+60, y+80, "Press <ENT> to leave the textbox. Then click 'ENTER' to confirm."); //SHOW

    STYLES().at("TS1").outText(c, PALETTE().at("SALMON"), LEFT+60+charIndent, y, wordsofar); //usual LEFT = LEFT+60,
    while (wordsofar.size()<MAXCHARSIZE && last2Char!=EMPTY_STRING())
    {
        wordsofar=getKeyInput(wordsofar);
        c.setFill(SOLID_FILL);
        bar(LEFT+60, y-15, RIGHT-60, y-15+87); //clear bar;
        if (wordsofar.size()>2) last2Char = wordsofar.substr(wordsofar.size()-EMPTY_STRING().size(), wordsofar.size());
        if (last2Char!=EMPTY_STRING()) STYLES().at("TS1").outText(c, PALETTE().at("SALMON"), LEFT+60+charIndent, y, wordsofar);
    }
    wordsofar = wordsofar.substr(0, wordsofar.size()-last2Char.size());
    STYLES().at("TS1").outText(c, PALETTE().at("SALMON"), LEFT+60+charIndent, y, wordsofar);
    STYLES().at("TS2").outText(bg, PALETTE().at("PALEBLUE"),LEFT+60, y+80, "Press <ENT> to leave the textbox. Then click 'ENTER' to confirm."); //HIDE
    return wordsofar;
}

//***************************************
// BACKGROUND GRAPHICS
//***************************************

void showBackground()
{
    PALETTE().at("SALMON").setFill(SLASH_FILL, PALETTE().at("SOFTSCARLET"));
    bar(0, 0, MAXRIGHT, MAXBOTTOM/3);
    PALETTE().at("SOFTSCARLET").setFill(SLASH_FILL, PALETTE().at("DEEPRED"));
    bar(0, MAXBOTTOM/3, MAXRIGHT, 2*(MAXBOTTOM/3));
    PALETTE().at("DEEPRED").setFill(SLASH_FILL, PALETTE().at("DEEPRED"));
    bar(0, 2*(MAXBOTTOM/3), MAXRIGHT, MAXBOTTOM);
    PALETTE().at("DEEPRED").setFill(SOLID_FILL);
    PALETTE().at("DEEPRED").setClr();
    roundedRectangle(40, Dimensions(LEFT-20, TOP, RIGHT+20, BOTTOM));
    PALETTE().at("DARKRED").setFill(SOLID_FILL);
    PALETTE().at("DARKRED").setClr();
    roundedRectangle(40, Dimensions(LEFT-10, TOP+10, RIGHT+10, BOTTOM-10));
    PALETTE().at("SALMON").setFill(SOLID_FILL);
    bar(LEFT, TOP, RIGHT, BOTTOM);
    STYLES().at("TS5").outText(PALETTE().at("DARKRED"), PALETTE().at("SOFTSCARLET"), (MAXRIGHT/2)-200, BOTTOM+7, "D O R A B O T - S P A N I S H  H E L P E R");
}

//***************************************
// SCREEN BACKGROUNDS
//***************************************

void showIntroScreen()
{
    Colour bg = PALETTE().at("PALEBLUE");
    Colour c = PALETTE().at("PALEPINK");
    bg.setFill(SOLID_FILL);
    bar(LEFT, TOP, RIGHT, BOTTOM);
    STYLES().at("TS1").outText(bg, c, (MAXRIGHT/2)-280, ((TOP+BOTTOM)/2)-40-20, "Hola, ¿cómo te llamas?");
    showStars(WHITE, DIMLIST().at("SCREEN"));

    c.setFill(SOLID_FILL); //MODEL1
    roundedRectangle(30, Dimensions(LEFT+60, TOP+250-20, RIGHT-60, BOTTOM-120-20));
    STYLES().at("TS5").outText(bg, PALETTE().at("PALESTBLUE"), RIGHT-120, BOTTOM-30, "E N T E R");
}

void showSelectionScreen()
{
    Colour c = PALETTE().at("PALEPINK");
    Colour bg = PALETTE().at("DIMBLUE");
    bg.setFill(SOLID_FILL);
    bar(LEFT, TOP, RIGHT, BOTTOM);
    STYLES().at("TS1").outText(bg, c, (MAXRIGHT/2)-210, ((TOP+BOTTOM)/2)-27, "Select an activity.");
    STYLES().at("TS5").outText(bg, PALETTE().at("WHITE"), RIGHT-108, TOP + 11, "Q U I T X");
    showStars(WHITE, DIMLIST().at("SCREEN"));
    c.setFill(SOLID_FILL);

    roundedRectangle(5, Dimensions((MAXRIGHT/2)+35, TOP+130-10, (MAXRIGHT/2)+225, TOP+170-10)); ///FLASH CARDS
    roundedRectangle(5, Dimensions((MAXRIGHT/2)-225, TOP+130-10, (MAXRIGHT/2)-5, TOP+170-10)); ///TIME TEST
    roundedRectangle(5, Dimensions((MAXRIGHT/2)+35, ((TOP+BOTTOM)/2)+34+10, (MAXRIGHT/2)+225, ((TOP+BOTTOM)/2)+74+10)); ///NUMBER TEST
    roundedRectangle(5, Dimensions((MAXRIGHT/2)-225, ((TOP+BOTTOM)/2)+34+10, (MAXRIGHT/2)-5, ((TOP+BOTTOM)/2)+74+10)); ///VERB TEST

    STYLES().at("TS5").outText(c, PALETTE().at("WHITE"), (MAXRIGHT/2)-191, ((TOP+BOTTOM)/2)-61-10, "FLASH CARDS");
    STYLES().at("TS5").outText(c, PALETTE().at("WHITE"), (MAXRIGHT/2)-197, ((TOP+BOTTOM)/2)+46+10, "NUMBER TEST");
    STYLES().at("TS5").outText(c, PALETTE().at("WHITE"), (MAXRIGHT/2)+64, ((TOP+BOTTOM)/2)-61-10, "TIME TEST");
    STYLES().at("TS5").outText(c, PALETTE().at("WHITE"), (MAXRIGHT/2)+64, ((TOP+BOTTOM)/2)+46+10, "VERB TEST");
}

void showGame1Screen()
{
    Colour bg = PALETTE().at("PALEBLUE");
    Colour c = PALETTE().at("PALEPINK");
    bg.setFill(SOLID_FILL);
    bar(LEFT, TOP, RIGHT, BOTTOM);
    STYLES().at("TS1").outText(bg, c, LEFT+50, ((TOP+BOTTOM)/2)-40-20, "¿Cómo se dice...?");
    showStars(WHITE, DIMLIST().at("SCREEN"));
    c.setFill(SOLID_FILL);

    roundedRectangle(5, Dimensions((MAXRIGHT/2)+10, ((TOP+BOTTOM)/2)-140+20, (MAXRIGHT/2)+210, ((TOP+BOTTOM)/2)+20));
    roundedRectangle(5, Dimensions((MAXRIGHT/2)+10+230, ((TOP+BOTTOM)/2)-140+20, (MAXRIGHT/2)+210+230, ((TOP+BOTTOM)/2)+20));

    //rounded rectangle
    roundedRectangle(30, Dimensions(LEFT+60, TOP+250-20+40, RIGHT-60, BOTTOM-120-20+40));

    //buttons
    STYLES().at("TS5").outText(bg, PALETTE().at("PALESTBLUE"), RIGHT-120, BOTTOM-30, "E N T E R"); //at TOP q u i t x
    STYLES().at("TS5").outText(bg, PALETTE().at("PALESTBLUE"), RIGHT-108, TOP + 11, "Q U I T X");
}
void showGame2Screen()
{
    Colour bg = PALETTE().at("PALEBLUE");
    Colour c = PALETTE().at("PALEPINK");
    bg.setFill(SOLID_FILL);
    bar(LEFT, TOP, RIGHT, BOTTOM);
    STYLES().at("TS1").outText(bg, c, RIGHT-440, ((TOP+BOTTOM)/2)-60, "¿Qué hora es?");
    showStars(WHITE, DIMLIST().at("SCREEN"));

    PALETTE().at("DEEPRED").setFill(SOLID_FILL); ///CLOCK
    roundedRectangle(36, Dimensions(LEFT+100, ((TOP+BOTTOM)/2)-60, LEFT+50+460, ((TOP+BOTTOM)/2)-15));

    c.setFill(SOLID_FILL);
    roundedRectangle(30, Dimensions(LEFT+60, TOP+250-20+40, RIGHT-60, BOTTOM-120-20+40)); ///S1

    STYLES().at("TS5").outText(bg, PALETTE().at("PALESTBLUE"), RIGHT-120, BOTTOM-30, "E N T E R"); //at TOP q u i t x
    STYLES().at("TS5").outText(bg, PALETTE().at("PALESTBLUE"), RIGHT-108, TOP + 11, "Q U I T X");
}
void showGame3Screen()
{
    Colour bg = PALETTE().at("PALEBLUE");
    Colour c = PALETTE().at("PALEPINK");
    bg.setFill(SOLID_FILL);
    bar(LEFT, TOP, RIGHT, BOTTOM);
    STYLES().at("TS1").outText(bg, c, LEFT+50, ((TOP+BOTTOM)/2)-40-20, "¿Cómo se dice...?");
    showStars(WHITE, DIMLIST().at("SCREEN"));
    c.setFill(SOLID_FILL);

    roundedRectangle(5, Dimensions((MAXRIGHT/2)+10, ((TOP+BOTTOM)/2)-120+20, (MAXRIGHT/2)+210, ((TOP+BOTTOM)/2)+20)); ///FLASH CARD
    roundedRectangle(30, Dimensions(LEFT+60, TOP+250-20+40, RIGHT-60, BOTTOM-120-20+40)); ///s1

    STYLES().at("TS5").outText(bg, PALETTE().at("PALESTBLUE"), RIGHT-120, BOTTOM-30, "E N T E R"); //at TOP q u i t x
    STYLES().at("TS5").outText(bg, PALETTE().at("PALESTBLUE"), RIGHT-108, TOP + 11, "Q U I T X");
}
void showGame4Screen()
{
    Colour bg = PALETTE().at("PALEBLUE");
    Colour c = PALETTE().at("PALEPINK");
    bg.setFill(SOLID_FILL);
    bar(LEFT, TOP, RIGHT, BOTTOM);
    STYLES().at("TS1").outText(bg, c, LEFT+50, ((TOP+BOTTOM)/2)-40-20, "¿Cómo se dice...?");
    showStars(WHITE, DIMLIST().at("SCREEN"));
    c.setFill(SOLID_FILL);

    roundedRectangle(30, Dimensions(LEFT+60, TOP+250-20+40, RIGHT-60, BOTTOM-120-20+40)); ///s1

    STYLES().at("TS5").outText(bg, PALETTE().at("PALESTBLUE"), RIGHT-120, BOTTOM-30, "E N T E R"); //at TOP q u i t x
    STYLES().at("TS5").outText(bg, PALETTE().at("PALESTBLUE"), RIGHT-108, TOP + 11, "Q U I T X");
}

//***************************************
// SCREEN TEXTS
//***************************************

void showGame1Text(int qNum, string Question, string Answer, string Input)
{
    Colour bg = PALETTE().at("PALEBLUE");
    Colour c = PALETTE().at("PALEPINK");
    STYLES().at("TS2").outText(bg, c, LEFT+91, TOP+217-30, "Vocabulary Test | Question "+toString(qNum)); //subtitle
    STYLES().at("TS3").outText(c, PALETTE().at("SALMON"), (MAXRIGHT/2)+10, ((TOP+BOTTOM)/2)-140+80, Question);
    STYLES().at("TS3").outText(c, PALETTE().at("SALMON"), (MAXRIGHT/2)+10+230, ((TOP+BOTTOM)/2)-140+80, Answer);
    STYLES().at("TS1").outText(c, bg, LEFT+60, TOP+217+38, Input);
}
void showGame2Text(int qNum, string Question, string Input)
{
    Colour bg = PALETTE().at("PALEBLUE");
    Colour c = PALETTE().at("PALEPINK");
    STYLES().at("TS2").outText(bg, c, RIGHT-406, TOP+217-30, "Time Test | Question "+toString(qNum)); //subtitle
    STYLES().at("TS4").outText(PALETTE().at("DARKRED"), PALETTE().at("SALMON"), LEFT+195, ((TOP+BOTTOM)/2)-140+80, Question);
    STYLES().at("TS1").outText(c, bg, LEFT+60, TOP+217+38, Input);
}
void showGame3Text(int qNum, string Question, string Input)
{
    Colour bg = PALETTE().at("PALEBLUE");
    Colour c = PALETTE().at("PALEPINK");
    STYLES().at("TS2").outText(bg, c, LEFT+91, TOP+217-30, "Number Test | Question "+toString(qNum)); //subtitle
    STYLES().at("TS4").outText(c, PALETTE().at("SALMON"), (MAXRIGHT/2)+20, ((TOP+BOTTOM)/2)-140+80, Question);
    STYLES().at("TS1").outText(c, bg, LEFT+60, TOP+217+38, Input);
}
void showGame4Text(int qNum, string Question, string Input)
{
    Colour bg = PALETTE().at("PALEBLUE");
    Colour c = PALETTE().at("PALEPINK");
    STYLES().at("TS2").outText(bg, c, LEFT+91, TOP+217-30, "Verb Test | Question "+toString(qNum)); //subtitle
    STYLES().at("TS3").outText(bg, PALETTE().at("WHITE"), (MAXRIGHT/2)+10, ((TOP+BOTTOM)/2)-120+80, Question);
    STYLES().at("TS1").outText(c, bg, LEFT+60, TOP+217+38, Input);
}

//***************************************
// ALL SCREENS - NO FORMATTING
//***************************************

int playIntro(UserStats *U)
{
    showIntroScreen();

    PageStats introPageStats;
    introPageStats.addLink(Dimensions(LEFT+60, TOP+200, RIGHT-60, TOP+200+90), 11); ///S1 INPUT BAR (NOT ACCURATE) -> ACTIVATE BAR AGAIN
    introPageStats.addLink(Dimensions(RIGHT-120, BOTTOM-30, RIGHT-120+100, BOTTOM-30+22), 2); ///TS5 ENTER BUTTON -> GO TO PAGE 2

    string userAnswer=getKeyInputLine(TOP+217, "Me llamo...", 15, 0);

    int toDoNext = activateClick(introPageStats);
    while(toDoNext!=2) ///WHILE 'CONFIRM ENTER' NOT PRESSED
        {
            if(toDoNext==11) {userAnswer=getKeyInputLine(TOP+217, userAnswer, 15, 0);} ///INPUT BAR PRESSED
            toDoNext=activateClick(introPageStats);
        }
    (*U).username = userAnswer;
    return 2;
}

int playSelection(UserStats *U)
{
    PageStats selectPageStats; ///PAGE STATS
    selectPageStats.addLink(Dimensions((MAXRIGHT/2)+35, TOP+130-10, (MAXRIGHT/2)+225, TOP+170-10), 4); ///time test
    selectPageStats.addLink(Dimensions((MAXRIGHT/2)-225, TOP+130-10, (MAXRIGHT/2)-5, TOP+170-10), 3); ///flash cards
    selectPageStats.addLink(Dimensions((MAXRIGHT/2)+35, ((TOP+BOTTOM)/2)+34+10, (MAXRIGHT/2)+225, ((TOP+BOTTOM)/2)+74+10), 6); ///verb test
    selectPageStats.addLink(Dimensions((MAXRIGHT/2)-225, ((TOP+BOTTOM)/2)+34+10, (MAXRIGHT/2)-5, ((TOP+BOTTOM)/2)+74+10), 5); ///number test
    selectPageStats.addLink(Dimensions(RIGHT-120, TOP, RIGHT-120+100, TOP+26), 7); ///TS5 QUIT BUTTON -> GO TO ENDSCREEN

    showSelectionScreen(); ///GRAPHICS

    return activateClick(selectPageStats);
}

int playGame1(UserStats *U) ///SHOULD HAVE NO FORMATTING IN HERE, ALL FORMATTING SENT TO THE GRAPHICS PART
{
    showGame1Screen();

    PageStats game1Stats(GAMEQCOUNT); ///SHOULD BE 25
    game1Stats.addLink(Dimensions(LEFT+60, TOP+240, RIGHT-60, TOP+240+90), 32); ///S1 INPUT BAR (ACCURATE) -> ACTIVATE BAR AGAIN
    game1Stats.addLink(Dimensions(RIGHT-120, BOTTOM-30, RIGHT-120+100, BOTTOM-30+22), 31); ///TS5 ENTER BUTTON -> GO TO ANSWER DISPLAY
    game1Stats.addLink(Dimensions(RIGHT-120, TOP, RIGHT-120+100, TOP+26), 2); ///TS5 QUIT BUTTON -> GO TO MENU SELECTION SCREEN

    vector<QuestionType> AllQuestions = generateG1QA(GAMEQCOUNT);

    for (int i = 0; i < game1Stats.qCount; i++)
    {
        string ques = AllQuestions.at(i).question;
        string ans = AllQuestions.at(i).answer;
        showGame1Text(i+1, ques, "?", "Type answer here");
        string userAnswer=getKeyInputLine(TOP+255, "", 15, 0);

        int toDoNext = activateClick(game1Stats);
        while(toDoNext!=31) ///WHILE 'CONFIRM ENTER' NOT PRESSED
        {
            if(toDoNext==32) {userAnswer=getKeyInputLine(TOP+255, userAnswer, 15, 0);} ///INPUT BAR PRESSED
            else if(toDoNext==2) {displayQuitScreenBox(); return 2;} ///EXIT TO SCREEN SELECTION PRESSED
            toDoNext=activateClick(game1Stats);
        }

        displayAnswerBool(userAnswer, ans, LEFT+60, BOTTOM-60);
        game1Stats.aRight+=(int)(userAnswer==ans);
        showGame1Text(i+1, ques, ans, userAnswer);

        delay(3000); cleardevice();
        showBackground(); showGame1Screen();
    }
    (*U).updateStats(game1Stats.qCount, game1Stats.aRight);
    return 2;
}

int playGame2(UserStats *U)
{
    showGame2Screen();
    PageStats game2Stats(GAMEQCOUNT); ///SHOULD BE 25

    game2Stats.addLink(Dimensions(LEFT+60, TOP+240, RIGHT-60, TOP+240+90), 42); ///S1 INPUT BAR (ACCURATE) -> ACTIVATE BAR AGAIN
    game2Stats.addLink(Dimensions(RIGHT-120, BOTTOM-30, RIGHT-120+100, BOTTOM-30+22), 41); ///TS5 ENTER BUTTON -> GO TO ANSWER DISPLAY
    game2Stats.addLink(Dimensions(RIGHT-120, TOP, RIGHT-120+100, TOP+26), 2); ///TS5 QUIT BUTTON -> GO TO MENU SELECTION SCREEN

    vector<QuestionType> AllQuestions = generateG2QA(GAMEQCOUNT);

    for (int i = 0; i < game2Stats.qCount; i++)
    {
        string ques = AllQuestions.at(i).question;
        string ans = AllQuestions.at(i).answer;
        showGame2Text(i+1, ques, "Type answer here");
        string userAnswer=getKeyInputLine(TOP+255, "", 15, 0);

        int toDoNext = activateClick(game2Stats);
        while(toDoNext!=41) ///WHILE 'CONFIRM ENTER' NOT PRESSED
        {
            if(toDoNext==42) {userAnswer=getKeyInputLine(TOP+255, userAnswer, 15, 0);} ///INPUT BAR PRESSED
            else if(toDoNext==2) {displayQuitScreenBox(); return 2;} ///EXIT TO SCREEN SELECTION PRESSED
            toDoNext=activateClick(game2Stats);
        }

        displayAnswerBool(userAnswer, ans, LEFT+60, BOTTOM-60);
        game2Stats.aRight+=(int)(userAnswer==ans);
        showGame2Text(i+1, ques, userAnswer);

        delay(3000); cleardevice();
        showBackground(); showGame2Screen();
    }
    (*U).updateStats(game2Stats.qCount, game2Stats.aRight);
    return 2;

    //cout<<"playGame2";
}

int playGame3(UserStats *U)
{
    //cout<<"playGame3";
    showGame3Screen();

    PageStats game3Stats(GAMEQCOUNT); ///SHOULD BE 25
    game3Stats.addLink(Dimensions(LEFT+60, TOP+240, RIGHT-60, TOP+240+90), 52); ///S1 INPUT BAR (ACCURATE) -> ACTIVATE BAR AGAIN
    game3Stats.addLink(Dimensions(RIGHT-120, BOTTOM-30, RIGHT-120+100, BOTTOM-30+22), 51); ///TS5 ENTER BUTTON -> GO TO ANSWER DISPLAY
    game3Stats.addLink(Dimensions(RIGHT-120, TOP, RIGHT-120+100, TOP+26), 2); ///TS5 QUIT BUTTON -> GO TO MENU SELECTION SCREEN

    vector<QuestionType> AllQuestions = generateG3QA(GAMEQCOUNT);

    for (int i = 0; i < game3Stats.qCount; i++)
    {
        string ques = AllQuestions.at(i).question;
        string ans = AllQuestions.at(i).answer;
        showGame3Text(i+1, ques, "Type answer here");
        string userAnswer=getKeyInputLine(TOP+255, "", 15, 0);

        int toDoNext = activateClick(game3Stats);
        while(toDoNext!=51) ///WHILE 'CONFIRM ENTER' NOT PRESSED
        {
            if(toDoNext==52) {userAnswer=getKeyInputLine(TOP+255, userAnswer, 15, 0);} ///INPUT BAR PRESSED
            else if(toDoNext==2) {displayQuitScreenBox(); return 2;} ///EXIT TO SCREEN SELECTION PRESSED
            toDoNext=activateClick(game3Stats);
        }

        displayAnswerBool(userAnswer, ans, LEFT+60, BOTTOM-60);
        game3Stats.aRight+=(int)(userAnswer==ans);
        showGame3Text(i+1, ques, userAnswer);

        delay(3000); cleardevice();
        showBackground(); showGame3Screen();
    }
    (*U).updateStats(game3Stats.qCount, game3Stats.aRight);
    return 2;
}

int playGame4(UserStats *U)
{
    //cout<<"playGame4";
    showGame4Screen();

    PageStats game4Stats(GAMEQCOUNT); ///SHOULD BE 25
    game4Stats.addLink(Dimensions(LEFT+60, TOP+240, RIGHT-60, TOP+240+90), 62); ///S1 INPUT BAR (ACCURATE) -> ACTIVATE BAR AGAIN
    game4Stats.addLink(Dimensions(RIGHT-120, BOTTOM-30, RIGHT-120+100, BOTTOM-30+22), 61); ///TS5 ENTER BUTTON -> GO TO ANSWER DISPLAY
    game4Stats.addLink(Dimensions(RIGHT-120, TOP, RIGHT-120+100, TOP+26), 2); ///TS5 QUIT BUTTON -> GO TO MENU SELECTION SCREEN

    vector<QuestionType> AllQuestions = generateG4QA(GAMEQCOUNT);
    //cout<<"lonelymessing";

    for (int i = 0; i < game4Stats.qCount; i++)
    {
        string ques = AllQuestions.at(i).question;
        string ans = AllQuestions.at(i).answer;
        showGame4Text(i+1, ques, "Type answer here");
        string userAnswer=getKeyInputLine(TOP+255, "", 15, 0);

        int toDoNext = activateClick(game4Stats);
        while(toDoNext!=61) ///WHILE 'CONFIRM ENTER' NOT PRESSED
        {
            if(toDoNext==62) {userAnswer=getKeyInputLine(TOP+255, userAnswer, 15, 0);} ///INPUT BAR PRESSED
            else if(toDoNext==2) {displayQuitScreenBox(); return 2;} ///EXIT TO SCREEN SELECTION PRESSED
            toDoNext=activateClick(game4Stats);
        }

        displayAnswerBool(userAnswer, ans, LEFT+60, BOTTOM-60);
        game4Stats.aRight+=(int)(userAnswer==ans);
        showGame4Text(i+1, ques, userAnswer);

        delay(3000); cleardevice();
        showBackground(); showGame4Screen();
    }
    (*U).updateStats(game4Stats.qCount, game4Stats.aRight);
    return 2;
}

int playEndScreen(UserStats *U)
{
    //cout<<"playEndScreen"; ///delete

    Colour c = PALETTE().at("PALEPINK");
    Colour bg = PALETTE().at("DIMBLUE");
    bg.setFill(SOLID_FILL);
    bar(LEFT, TOP, RIGHT, BOTTOM);

    STYLES().at("TS1").outText(bg, c, LEFT+20, ((TOP+BOTTOM)/2)-27, (*U).username); //*U.getAverage()
    string finalScore = "Final Average : "+toString((*U).getAverage())+" %";
    STYLES().at("TS2").outText(bg, c, LEFT+20, ((TOP+BOTTOM)/2)+20, finalScore);
    STYLES().at("TS2").outText(bg, c, LEFT+20, ((TOP+BOTTOM)/2)+42, "Questions answered: "+toString((*U).qCount));
    STYLES().at("TS2").outText(bg, c, LEFT+20, ((TOP+BOTTOM)/2)+64, "Correct answers: "+toString((*U).aRight));
    STYLES().at("TS5").outText(bg, c, (MAXRIGHT/2)-240, BOTTOM-20, "Thanks for playing! PRESS ANY KEY TO EXIT.");
    showStars(WHITE, DIMLIST().at("SCREEN"));
    c.setFill(SOLID_FILL);
    return 0;
}

//***************************************
// LOAD PAGES
//***************************************

int loadPage(int pageNum, UserStats *U)
{
    delay(100);
    cleardevice();
    showBackground();
    switch(pageNum)
    {
        case 1:
            return playIntro(U); break;
        case 2:
            return playSelection(U); break;
        case 3:
            return playGame1(U); break;
        case 4:
            return playGame2(U); break;
        case 5:
            return playGame3(U); break;
        case 6:
            return playGame4(U); break;
        case 7:
            return playEndScreen(U);
        default:
            return 0;
    }
}

#endif // SCREENS_H
