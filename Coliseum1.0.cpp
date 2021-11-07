// Coliseum.cpp
//Ryan Swint
//www.github.com/ryswint/Coliseum
//A battle simulator using classes and ascii animation


#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>
using namespace std;

//======================================================================================= VARIABLES & CONSTANTS =====================================================================================//
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

string randomName(int length);
const int typeTime = 50;
const int waitTime = 2000;
int hurry = 0;

string spacer = R"(                                                                                                                  )";
string opponent1_0 = R"(                 )";
string opponent1_1 = R"(  ,/         \.  )";
string opponent1_2 = R"( ((           )) )";
string opponent1_3 = R"(  \`.       ,'/  )";
string opponent1_4 = R"(   )')     (`(   )";
string opponent1_5 = R"( ,'`/       \,`. )";
string opponent1_6 = R"((`-(         )-'))";
string opponent1_7 = R"( \-'\,-'"`-./`-/ )";
string opponent1_8 = R"(  \-')     (`-/  )";
string opponent1_9 = R"(  /`'       `'\  )";
string opponent1_10 = R"( (  _       _  ) )";
string opponent1_11 = R"( | ( \     / ) | )";
string opponent1_12 = R"( |  `.\   /,'  | )";
string opponent1_13 = R"( |    `\ /'    | )";
string opponent1_14 = R"( (             ) )";
string opponent1_15 = R"(  \           /  )";
string opponent1_16 = R"(   \         /   )";
string opponent1_17 = R"(    `.     ,'    )";
string opponent1_18 = R"(      `-.-'      )";
string opponent1_19 = R"(                 )";

string Opponent[] = { opponent1_0, opponent1_1, opponent1_2, opponent1_3, opponent1_4,opponent1_5,opponent1_6,opponent1_7,opponent1_8,opponent1_9,opponent1_10,opponent1_11,opponent1_12,opponent1_13,opponent1_14,opponent1_15,opponent1_16,opponent1_17,opponent1_18, opponent1_19 };



string announcer1 = R"(   .------\ /------.   )";
string announcer2 = R"(   |       -       |   )";
string announcer3 = R"(   |               |   )";
string announcer4 = R"(   |               |   )";
string announcer5 = R"(   |               |   )";
string announcer6 = R"(_______________________)";
string announcer7 = R"(===========.===========)";
string announcer8 = R"(  / ~~~~~     ~~~~~ \  )";
string announcer9 = R"( /|  .  |     |  .  |\ )";
string announcer10 = R"( W   ---  / \  ---   W )";
string announcer11 = R"( \.      |o o|      ./ )";
string announcer12 = R"(  |                 |  )";
string announcer13 = R"(  \    #########    /  )";
string announcer14 = R"(   \  ## ----- ##  /   )";
string announcer15 = R"(    \##         ##/    )";
string announcer16 = R"(     \_____v_____/     )";

string Announcer[] = { announcer1,announcer2,announcer3,announcer4,announcer5, announcer6,announcer7, announcer8,announcer9,announcer10,announcer11,announcer12,announcer13,announcer14,announcer15,announcer16 };

string announcert1 = R"(   .------\ /------.   )";
string announcert2 = R"(   |       -       |   )";
string announcert3 = R"(   |               |   )";
string announcert4 = R"(   |               |   )";
string announcert5 = R"(   |               |   )";
string announcert6 = R"(_______________________)";
string announcert7 = R"(===========.===========)";
string announcert8 = R"(  / ~~~~~     ~~~~~ \  )";
string announcert9 = R"( /|  .  |     |  .  |\ )";
string announcert10 = R"( W   ---  / \  ---   W )";
string announcert11 = R"( \.      |o o|      ./ )";
string announcert12 = R"(  |                 |  )";
string announcert13 = R"(  \    #########    /  )";
string announcert14 = R"(   \  ##(_____)##  /   )";
string announcert15 = R"(    \##         ##/    )";
string announcert16 = R"(     \_____v_____/     )";

string Announcert[] = { announcert1,announcert2,announcert3,announcert4,announcert5, announcert6,announcert7, announcert8,announcert9,announcert10,announcert11,announcert12,announcert13,announcert14,announcert15,announcert16 };

string announcerb1 = R"(   .------\ /------.   )";
string announcerb2 = R"(   |       -       |   )";
string announcerb3 = R"(   |               |   )";
string announcerb4 = R"(   |               |   )";
string announcerb5 = R"(   |               |   )";
string announcerb6 = R"(_______________________)";
string announcerb7 = R"(===========.===========)";
string announcerb8 = R"(  / ~~~~~     ~~~~~ \  )";
string announcerb9 = R"( /|_____|     |_____|\ )";
string announcerb10 = R"( W   ---  / \  ---   W )";
string announcerb11 = R"( \.      |o o|      ./ )";
string announcerb12 = R"(  |                 |  )";
string announcerb13 = R"(  \    #########    /  )";
string announcerb14 = R"(   \  ## ----- ##  /   )";
string announcerb15 = R"(    \##         ##/    )";
string announcerb16 = R"(     \_____v_____/     )";

string Announcerb[] = { announcerb1,announcerb2,announcerb3,announcerb4,announcerb5, announcerb6,announcerb7, announcerb8,announcerb9,announcerb10,announcerb11,announcerb12,announcerb13,announcerb14,announcerb15,announcerb16 };

string announcerl1 = R"(   .------\ /------.   )";
string announcerl2 = R"(   |       -       |   )";
string announcerl3 = R"(   |               |   )";
string announcerl4 = R"(   |               |   )";
string announcerl5 = R"(   |               |   )";
string announcerl6 = R"(_______________________)";
string announcerl7 = R"(===========.===========)";
string announcerl8 = R"(  / ~~~~~     ~~~~~ \  )";
string announcerl9 = R"( /|.    |     |.    |\ )";
string announcerl10 = R"( W   ---  / \  ---   W )";
string announcerl11 = R"( \.      |o o|      ./ )";
string announcerl12 = R"(  |                 |  )";
string announcerl13 = R"(  \    #########    /  )";
string announcerl14 = R"(   \  ## ----- ##  /   )";
string announcerl15 = R"(    \##         ##/    )";
string announcerl16 = R"(     \_____v_____/     )";

string Announcerl[] = { announcerl1,announcerl2,announcerl3,announcerl4,announcerl5, announcerl6,announcerl7, announcerl8,announcerl9,announcerl10,announcerl11,announcerl12,announcerl13,announcerl14,announcerl15,announcerl16 };

string announcerr1 = R"(   .------\ /------.   )";
string announcerr2 = R"(   |       -       |   )";
string announcerr3 = R"(   |               |   )";
string announcerr4 = R"(   |               |   )";
string announcerr5 = R"(   |               |   )";
string announcerr6 = R"(_______________________)";
string announcerr7 = R"(===========.===========)";
string announcerr8 = R"(  / ~~~~~     ~~~~~ \  )";
string announcerr9 = R"( /|    .|     |    .|\ )";
string announcerr10 = R"( W   ---  / \  ---   W )";
string announcerr11 = R"( \.      |o o|      ./ )";
string announcerr12 = R"(  |                 |  )";
string announcerr13 = R"(  \    #########    /  )";
string announcerr14 = R"(   \  ## ----- ##  /   )";
string announcerr15 = R"(    \##         ##/    )";
string announcerr16 = R"(     \_____v_____/     )";

string Announcerr[] = { announcerr1,announcerr2,announcerr3,announcerr4,announcerr5, announcerr6,announcerr7, announcerr8,announcerr9,announcerr10,announcerr11,announcerr12,announcerr13,announcerr14,announcerr15,announcerr16 };

string banner0 = R"(_________        .__  .__                                )";
string banner1 = R"(\_   ___ \  ____ |  | |__| ______ ____  __ __  _____     )";
string banner2 = R"(/    \  \/ /  _ \|  | |  |/  ___// __ \|  |  \/     \    )";
string banner3 = R"(\     \___(  <_> )  |_|  |\___ \\  ___/|  |  /  Y Y  \   )";
string banner4 = R"( \______  /\____/|____/__/____  >\___  >____/|__|_|  /   )";
string banner5 = R"(        \/                    \/     \/            \/    )";
string banner6 = R"(_________ .__                          .__               )";
string banner7 = R"(\_   ___ \|  |__ _____    _____ ______ |__| ____   ____  )";
string banner8 = R"(/    \  \/|  |  \\__  \  /     \\____ \|  |/  _ \ /    \ )";
string banner9 = R"(\     \___|   Y  \/ __ \|  Y Y  \  |_> >  (  <_> )   |  \)";
string banner10 = R"( \______  /___|  (____  /__|_|  /   __/|__|\____/|___|  /)";
string banner11 = R"(        \/     \/     \/      \/|__|                  \/ )";

string Banner[] = { banner0, banner1 ,banner2, banner3, banner4, banner5, banner6, banner7, banner8, banner9, banner10, banner11 };
//======================================================================================== FUNCTION PROTOTYPES ======================================================================================//
class Enemy;
void setCursorPosition(int x, int y);
void PrintAnnouncer();
void PrintAnnouncerT();
void PrintAnnouncerB();
void PrintAnnouncerL();
void PrintAnnouncerR();
void ClearAnnouncer();
void SetDamageColor(int type);
void CombatD(int incoming, Enemy* Attacker, Enemy* Defender);
string DamageTypeString(int type);
int CombatDamage(Enemy* Attacker, Enemy* Defender);
void CombatReport(string report, int line);
void Report(string report, bool newLine);
void Resize(int width, int height);
void PrintFrame();
void PrintBattleFrame();
void PrintBattleFrameText();
void ClearBattleFrame();
void Winner(Enemy* winner);
void StartScreen();
void Announce(Enemy* Opponent1, Enemy* Opponent2, int round);
void ShowConsoleCursor(bool showFlag);
Enemy* Battle(Enemy* Opponent1, Enemy* Opponent2);

//======================================================================================= CLASSES =============================================================================================//
class Enemy
{
public:
    Enemy(int health = 10, int damage = 10, int damageType = 0, string name = "Enemy");
    void SetHealth(int setHealth);
    void GetHealth();
    void GetDamage();
    int GetDamageInt();
    string GetName();
    int GetDamageType();
    void SetupTempValues();
    void PrintOpponent();
    void DeadPrintOpponent();
    void PrintStats();
    void Presence();
    void AttackAni();
    int CombatA();

    bool left;
    int tempHealth;

private:
    string name;
    int health;
    int damage;
    int damageType;
};

void Enemy::GetHealth()
{
    cout << health << endl;
}

void Enemy::SetHealth(int setHealth)
{
    health = setHealth;
}

void Enemy::GetDamage()
{
    cout << damage << endl;
}

int Enemy::GetDamageInt()
{
    return damage;
}

string Enemy::GetName()
{
    return name;
}

int Enemy::GetDamageType()
{
    return damageType;
}

void Enemy::SetupTempValues()
{
    tempHealth = health;

}

void Enemy::PrintOpponent()
{
    int start;
    SetDamageColor(damageType);

    if (left)
    {
        start = 5;
    }
    else
    {
        start = 113;
    }

    for (int i = 1; i < 20; i++)
    {
        setCursorPosition(start, i + 1);
        cout << Opponent[i - 1];
    }

    SetConsoleTextAttribute(hConsole, 7);
}

void Enemy::DeadPrintOpponent()
{
    int start;
    SetConsoleTextAttribute(hConsole, 64);

    if (left)
    {
        start = 5;
    }
    else
    {
        start = 113;
    }

    for (int i = 1; i < 20; i++)
    {
        setCursorPosition(start, i + 1);
        cout << Opponent[i - 1];
    }
    Sleep(100);
    PrintOpponent();
    Sleep(100);
    SetConsoleTextAttribute(hConsole, 64);
    for (int i = 1; i < 20; i++)
    {
        setCursorPosition(start, i + 1);
        cout << Opponent[i - 1];
    }
    Sleep(100);
    PrintOpponent();
    Sleep(100);

    for (int i = 1; i < 20; i++)
    {
        setCursorPosition(start, i + 1);
        cout << Opponent[i - 1];
    }
    Sleep(100);
    for (int i = 1; i < 20; i++)
    {
        setCursorPosition(start, i + 1);
        cout << "                 ";
    }
    SetConsoleTextAttribute(hConsole, 7);
}

void Enemy::Presence()
{
    switch (damageType)
    {
    case 1:
        system("color 40");
        Sleep(25);
        system("color 04");
        Sleep(25);
        system("color 40");
        Sleep(25);
        system("color 04");
        Sleep(25);
        system("color 40");
        Sleep(25);
        system("color 04");
        Sleep(25);
        system("color 40");
        Sleep(25);
        system("color 07");
        Sleep(25);
        break;
    case 2:
        system("color 30");
        Sleep(25);
        system("color 03");
        Sleep(25);
        system("color 30");
        Sleep(25);
        system("color 03");
        Sleep(25);
        system("color 30");
        Sleep(25);
        system("color 03");
        Sleep(25);
        system("color 30");
        Sleep(25);
        system("color 07");
        Sleep(25);
        break;
    case 3:
        system("color E0");
        Sleep(25);
        system("color 0E");
        Sleep(25);
        system("color E0");
        Sleep(25);
        system("color 0E");
        Sleep(25);
        system("color E0");
        Sleep(25);
        system("color 0E");
        Sleep(25);
        system("color E0");
        Sleep(25);
        system("color 07");
        Sleep(25);
        break;
    case 4:
        system("color 90");
        Sleep(25);
        system("color 09");
        Sleep(25);
        system("color 90");
        Sleep(25);
        system("color 09");
        Sleep(25);
        system("color 90");
        Sleep(25);
        system("color 09");
        Sleep(25);
        system("color 90");
        Sleep(25);
        system("color 07");
        Sleep(25);
        break;
    }
    PrintFrame();
    
}

void Enemy::PrintStats()
{
    int x;
    int y;

    if (left)
    {
        x = 0;
        y = 22;
    }
    else
    {
        x = 113;
        y = 22;
    }
    SetConsoleTextAttribute(hConsole, 07);
    setCursorPosition(x + 8, y);
    cout << name;
    setCursorPosition(x + 10, y + 2);
    if (tempHealth < 0)
    {
        cout << setfill('0') << setw(3) << 0;
    }
    else
    {
        cout << setfill('0') << setw(3) << tempHealth;
    }
    setCursorPosition(x + 10, y + 4);
    cout << setfill('0') << setw(3) << damage;
    setCursorPosition(x + 8, y + 6);
    switch (damageType)
    {
    case 1:
        SetConsoleTextAttribute(hConsole, 12);
        cout << "Fire";
        SetConsoleTextAttribute(hConsole, 07);
        break;
    case 2:
        SetConsoleTextAttribute(hConsole, 11);
        cout << "Wind";
        SetConsoleTextAttribute(hConsole, 07);
        break;
    case 3:
        SetConsoleTextAttribute(hConsole, 14);
        cout << "Thunder";
        SetConsoleTextAttribute(hConsole, 07);
        break;
    case 4:
        SetConsoleTextAttribute(hConsole, 9);
        cout << "Water";
        SetConsoleTextAttribute(hConsole, 7);
        break;
    }
    setCursorPosition(0, 32);
}

void Enemy::AttackAni()
{
    int start;
    switch (damageType)
    {
    case 1:
        SetConsoleTextAttribute(hConsole, 12);
        break;
    case 2:
        SetConsoleTextAttribute(hConsole, 11);
        break;
    case 3:
        SetConsoleTextAttribute(hConsole, 14);
        break;
    case 4:
        SetConsoleTextAttribute(hConsole, 9);
        break;
    }

    if (left)
    {
        start = 5;
        for (int j = 0; j < 92; j++)
        {
            for (int i = 1; i < 20; i++)
            {
                setCursorPosition((start + j) - 1, i + 1);
                cout << "                ";
            }

            for (int i = 1; i < 20; i++)
            {
                setCursorPosition((start + j), i + 1);
                cout << Opponent[i - 1];
            }

        }

    }
    else
    {
        start = 113;
        for (int j = 0; j < 92; j++)
        {
            for (int i = 1; i < 20; i++)
            {
                setCursorPosition((start - j) + 1, i + 1);
                cout << "                 ";
            }

            for (int i = 1; i < 20; i++)
            {
                setCursorPosition((start - j), i + 1);
                cout << Opponent[i - 1];
            }

        }
    }
    Sleep(5);
}

int Enemy::CombatA() //Move into battle()
{
    if ((rand() % 4 + 1) == 4)
    {
        return 0;
    }
    else
    {
        return (rand() % damage + 1);
    }

}


Enemy::Enemy(int health, int damage, int damageType, string name) :
    health(health),
    damage(damage),
    damageType(damageType),
    name(name),
    left(true),
    tempHealth(health)
{}


//======================================================================================= MAIN FUNCTION ========================================================================================//
int main()
{   
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, NULL);
    PrintFrame();
    StartScreen();
    PrintFrame();
    Enemy* winner;
    string name;
    int damageType;
    srand(time(NULL)); //Seed RNG with current time
    Enemy Opponent1(((rand() % 10 + 1) * 10), ((rand() % 10 + 1) * 10), (rand() % 4 + 1), (randomName(rand() % 9 + 3)));
    Enemy Opponent2(((rand() % 10 + 1) * 10), ((rand() % 10 + 1) * 10), (rand() % 4 + 1), (randomName(rand() % 9 + 3)));

    Announce(&Opponent1, &Opponent2, 1);
    PrintBattleFrame();
    Opponent1.PrintStats();
    Opponent2.PrintStats();
    Sleep(1000);

    winner = Battle(&Opponent1, &Opponent2);
    PrintFrame();
    winner->PrintOpponent();
    name = winner->GetName();
    Report(name + " WINS!!!", 1);
    PrintFrame();
    PrintBattleFrame();
    Enemy Opponent3(((rand() % 10 + 1) * 10), ((rand() % 10 + 1) * 10), (rand() % 4 + 1), (randomName(rand() % 9 + 3)));

    winner->SetupTempValues();
    ClearBattleFrame();
    Announce(winner, &Opponent3, 2);
    PrintBattleFrame();
    winner->PrintStats();
    Opponent3.PrintStats();
    Sleep(1000);

    winner = Battle(winner, &Opponent3);
    PrintFrame();
    winner->PrintOpponent();
    name = winner->GetName();
    Report(name + " WINS!!!", 1);
    PrintFrame();
    PrintBattleFrame();

    Enemy Opponent4(((rand() % 10 + 1) * 10), ((rand() % 10 + 1) * 10), (rand() % 4 + 1), (randomName(rand() % 9 + 3)));

    winner->SetupTempValues();
    ClearBattleFrame();
    Announce(winner, &Opponent4, 3);
    PrintBattleFrame();
    winner->PrintStats();
    Opponent4.PrintStats();
    Sleep(1000);

    winner = Battle(winner, &Opponent4);
    PrintFrame();
    winner->PrintOpponent();
    name = winner->GetName();
    Report(name + " WINS!!!", 1);
    PrintFrame();
    PrintBattleFrame();

    Enemy Opponent5(((rand() % 10 + 1) * 10), ((rand() % 10 + 1) * 10), (rand() % 4 + 1), (randomName(rand() % 9 + 3)));

    winner->SetupTempValues();
    ClearBattleFrame();
    Announce(winner, &Opponent5, 4);
    PrintBattleFrame();
    winner->PrintStats();
    Opponent5.PrintStats();
    Sleep(1000);

    winner = Battle(winner, &Opponent5);
    PrintFrame();
    winner->PrintOpponent();
    name = winner->GetName();
    Report(name + " WINS!!!", 1);
    PrintFrame();
    ClearBattleFrame();
    Winner(winner);
    return 0;


}
//======================================================================================= FUNCTIONS =============================================================================================//

void setCursorPosition(int x, int y)
{
    x = x + 114 ;
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
    ShowConsoleCursor(false);
}

void PrintAnnouncer()
{
    for (int i = 1; i < 17; i++)
    {
        setCursorPosition(56, i + 1);
        cout << Announcer[i - 1];
    }
    //setCursorPosition(0, 0);

}

void PrintAnnouncerT()
{
    for (int i = 1; i < 17; i++)
    {
        setCursorPosition(56, i + 1);
        cout << Announcert[i - 1];
    }
    //setCursorPosition(0, 0);
}

void PrintAnnouncerB()
{
    for (int i = 1; i < 17; i++)
    {
        setCursorPosition(56, i + 1);
        cout << Announcerb[i - 1];
    }
    //setCursorPosition(0, 0);
}

void PrintAnnouncerL()
{
    for (int i = 1; i < 17; i++)
    {
        setCursorPosition(56, i + 1);
        cout << Announcerl[i - 1];
    }
    //setCursorPosition(0, 0);
}

void PrintAnnouncerR()
{
    for (int i = 1; i < 17; i++)
    {
        setCursorPosition(56, i + 1);
        cout << Announcerr[i - 1];
    }
    //setCursorPosition(0, 0);
}

void ClearAnnouncer()
{
    for (int i = 1; i < 17; i++)
    {
        setCursorPosition(56, i + 1);
        cout << "                         ";
    }

    //setCursorPosition(0, 0);
}

void CombatReport(string report, int line = 19)
{
    int startpos = 68 - (report.length() / 2);
    setCursorPosition(startpos, line);
    for (int i = 0; i < report.length(); i++)
    {
        setCursorPosition(startpos + i, line);
        cout << report[i];
        Sleep(25 - hurry);
    }
}

string DamageTypeString(int type)
{
    string typeString;
    switch (type)
    {
    case 1:
        typeString = "Fire";
        break;
    case 2:
        typeString = "Wind";
        break;
    case 3:
        typeString = "Thunder";
        break;
    case 4:
        typeString = "Water";
        break;
    }
    return typeString;
}

void SetDamageColor(int type)
{
    switch (type)
    {
    case 1:
        SetConsoleTextAttribute(hConsole, 12);
        break;
    case 2:
        SetConsoleTextAttribute(hConsole, 11);
        break;
    case 3:
        SetConsoleTextAttribute(hConsole, 14);
        break;
    case 4:
        SetConsoleTextAttribute(hConsole, 9);
        break;
    }
}

int CombatDamage(Enemy* Attacker, Enemy* Defender)
{
    int tempDamage;
    int damageType;
    string announce;
    string damageString;
    string combatString;
    string typeString = DamageTypeString(Attacker->GetDamageType());
    tempDamage = Attacker->CombatA();
    damageType = Attacker->GetDamageType();
    Attacker->AttackAni();

    if (tempDamage == 0)
    {
        PrintFrame();
        Attacker->PrintOpponent();
        Defender->PrintOpponent();
        Attacker->PrintStats();
        Defender->PrintStats();
        announce = Attacker->GetName() + "'s attack misses!!!";
        SetDamageColor(damageType);
        CombatReport(announce, 19);
    }
    else
    {
        Attacker->Presence();
        PrintBattleFrame();
        PrintFrame();
        Attacker->PrintOpponent();
        Defender->PrintOpponent();
        Attacker->PrintStats();
        Defender->PrintStats();
        tempDamage = (rand() % Attacker->GetDamageInt() + 1);
        damageString = to_string(tempDamage);
        combatString = Attacker->GetName() + " attacks with " + damageString + " " + typeString + " damage!";

        SetDamageColor(damageType);
        CombatReport(combatString, 19);

    }
    SetConsoleTextAttribute(hConsole, 07);
    return tempDamage;
}

void CombatD(int incoming, Enemy* Attacker, Enemy* Defender)
{
    int x;
    int y;
    int damageDone = 0;
    int d = Defender->GetDamageType();
    int a = Attacker->GetDamageType();
    int spreadTime;
    string damageString;
    string combatString;
    string typeString = DamageTypeString(Attacker->GetDamageType());
    string extra;
    string res = "";
    string combatString0;
    string combatString1;
    string combatString2;
    string combatString3;
    string combatString4;
    string combatString5;
    string combatString6;
    if (incoming == 0)
    {
        string attackerName = Attacker->GetName();
        int startpos = 68 - ((attackerName.length() + 19) / 2);
        Sleep(1000);
        setCursorPosition(startpos, 19);
        for (int i = 0; i < attackerName.length() + 29; i++)
        {
            cout << " ";
        }
    }
    else
    {
        if (d == a)
        {
            damageDone = incoming * 0.25;
            extra = to_string(incoming - damageDone);
            res = "(-" + extra + ") " + typeString + " Immunity";
        }
        else if ((a + 1) == d || ((a == 4) && (d == 1)))
        {
            damageDone = incoming * 1.25;
            extra = to_string(damageDone - incoming);
            res = "(+" + extra + ") " + typeString + " Weakness";
        }
        else if (((a - 1) == d) || ((a == 1) && (d == 4)))
        {
            damageDone = incoming * 0.75;
            extra = to_string(incoming - damageDone);
            res = "(-" + extra + ") " + typeString + " Resistance";
        }
        else
        {
            damageDone = incoming;
        }
        damageString = to_string(damageDone);

        combatString0 = Defender->GetName();
        combatString1 = " takes ";
        combatString2 = damageString;
        combatString3 = " ";
        combatString4 = typeString;
        combatString5 = " damage! ";
        combatString6 = res;

        combatString = combatString0 + combatString1 + combatString2 + combatString3 + combatString4 + combatString5 + combatString6;
        SetDamageColor(d);

        spreadTime = 3000 / (damageDone + 1);


        int startpos = 68 - (combatString.length() / 2);
        int endpos;
        setCursorPosition(startpos, 20);
        for (int i = 0; i < combatString0.length(); i++)
        {
            cout << combatString0[i];
            Sleep(25 - hurry);
        }
        for (int i = 0; i < combatString1.length(); i++)
        {
            cout << combatString1[i];
            Sleep(25 - hurry);
        }
        SetDamageColor(a);
        for (int i = 0; i < combatString2.length(); i++)
        {
            cout << combatString2[i];
            Sleep(25 - hurry);
        }
        for (int i = 0; i < combatString3.length(); i++)
        {
            cout << combatString3[i];
            Sleep(25 - hurry);
        }
        for (int i = 0; i < combatString4.length(); i++)
        {
            cout << combatString4[i];
            Sleep(25 - hurry);
        }
        SetDamageColor(d);
        for (int i = 0; i < combatString5.length(); i++)
        {
            cout << combatString5[i];
            Sleep(25 - hurry);
        }

        for (int i = 0; i < combatString6.length(); i++)
        {
            cout << combatString6[i];
            Sleep(25 - hurry);
        }
        
        SetDamageColor(a);
        for (int i = 0; i < damageDone; i++)
        {
            if (Defender->left)
            {
                x = 0;
                y = 22;
            }
            else
            {
                x = 113;
                y = 22;
            }
            setCursorPosition(x + 10, y + 2);
            if (Defender->tempHealth - i < 0)
            {
                cout << setfill('0') << setw(3) << 0;
                break;
            }
            else
            {
                cout << setfill('0') << setw(3) << (Defender->tempHealth - i);
            }

            Sleep(spreadTime);
        }

        for (int j = 0; j < 2; j++)
        {
            setCursorPosition(startpos - 10, 19 + j);
            for (int i = 0; i < combatString.length() + 20; i++)
            {
                cout << " ";
            }
        }
    }
    SetConsoleTextAttribute(hConsole, 07);
    Defender->tempHealth = Defender->tempHealth - damageDone;
}

void Report(string report, bool pause = false)
{
    SetConsoleTextAttribute(hConsole, 7);
    bool flap = true;
    int startpos = 68 - (report.length() / 2);
    PrintAnnouncer();
    setCursorPosition(startpos, 19);

    for (int i = 0; i < report.length(); i++)
    {
        setCursorPosition(startpos + i, 19);
        cout << report[i];
        Sleep(typeTime);
        if (flap)
        {
            PrintAnnouncer();
            flap = !flap;
        }
        else
        {
            PrintAnnouncerT();
            flap = !flap;
        }
    }

    PrintAnnouncer();
    Sleep(250);
    PrintAnnouncerB();
    Sleep(250);
    PrintAnnouncer();
    Sleep(250);

    if (pause)
    {
        setCursorPosition(52, 20);
        system("pause");
        setCursorPosition(52, 20);
        cout << "                                ";
    }
    for (int i = 0; i < report.length(); i++)
    {
        setCursorPosition(startpos + i, 19);
        cout << " ";

    }
}

void Resize(int width, int height)
{
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, width, height, TRUE);

    setCursorPosition(0, 0);

}

void PrintFrame()
{
    setCursorPosition(0, 0);
    SetConsoleTextAttribute(hConsole, 4);
    cout << endl;
cout << spacer << R"(=======================================================================================================================================)" << endl;
cout << spacer << R"(||                                                                                                                                   ||)" << endl;
cout << spacer << R"(||                                                                                                                                   ||)" << endl;
cout << spacer << R"(||                                                                                                                                   ||)" << endl;
cout << spacer << R"(||                                                                                                                                   ||)" << endl;
cout << spacer << R"(||                                                                                                                                   ||)" << endl;
cout << spacer << R"(||                                                                                                                                   ||)" << endl;
cout << spacer << R"(||                                                                                                                                   ||)" << endl;
cout << spacer << R"(||                                                                                                                                   ||)" << endl;
cout << spacer << R"(||                                                                                                                                   ||)" << endl;
cout << spacer << R"(||                                                                                                                                   ||)" << endl;
cout << spacer << R"(||                                                                                                                                   ||)" << endl;
cout << spacer << R"(||                                                                                                                                   ||)" << endl;
cout << spacer << R"(||                                                                                                                                   ||)" << endl;
cout << spacer << R"(||                                                                                                                                   ||)" << endl;
cout << spacer << R"(||                                                                                                                                   ||)" << endl;
cout << spacer << R"(||                                                                                                                                   ||)" << endl;
cout << spacer << R"(||                                                                                                                                   ||)" << endl;
cout << spacer << R"(||                                                                                                                                   ||)" << endl;
cout << spacer << R"(||                                                                                                                                   ||)" << endl;
cout << spacer << R"(=======================================================================================================================================)";
    SetConsoleTextAttribute(hConsole, 7);
}

void PrintBattleFrame()
{
    setCursorPosition(0, 21);
    SetConsoleTextAttribute(hConsole, 4);
cout << endl;
cout << spacer << R"(||Name:             ||                                                                                           ||Name:             ||)" << endl;
cout << spacer << R"(||==================||                                                                                           ||==================||)" << endl;
cout << spacer << R"(||Health:           ||                                                                                           ||Health:           ||)" << endl;
cout << spacer << R"(||==================||                                                                                           ||==================||)" << endl;
cout << spacer << R"(||Damage:           ||                                                                                           ||Damage:           ||)" << endl;
cout << spacer << R"(||==================||                                                                                           ||==================||)" << endl;
cout << spacer << R"(||Type:             ||                                                                                           ||Type:             ||)" << endl;
cout << spacer << R"(======================                                                                                           ======================)";
    PrintBattleFrameText();
}

void PrintBattleFrameText()
{
    SetConsoleTextAttribute(hConsole, 7);
    setCursorPosition(2, 22);
    cout << "Name:";
    setCursorPosition(2, 24);
    cout << "Health:";
    setCursorPosition(2, 26);
    cout << "Damage:";
    setCursorPosition(2, 28);
    cout << "Type:";
    setCursorPosition(115, 22);
    cout << "Name:";
    setCursorPosition(115, 24);
    cout << "Health:";
    setCursorPosition(115, 26);
    cout << "Damage:";
    setCursorPosition(115, 28);
    cout << "Type:";
}

void ClearBattleFrame()
{
    setCursorPosition(0, 22);
    for (int j = 0; j < 10; j++)
    {
        setCursorPosition(0, 22 + j);
        for (int i = 0; i < 300; i++)
        {
            cout << " ";
        }
    }
}

void Announce(Enemy* Opponent1, Enemy* Opponent2, int round)
{
    string name1 = (Opponent1->GetName());
    string name1Announce;
    string name2 = (Opponent2->GetName());
    string name2Announce;
    string colorstr;
    int type1 = (Opponent1->GetDamageType());
    int type2 = (Opponent2->GetDamageType());
    int color = 0;
       
    switch (round)
    {
    case 1:
        Report("Welcome to the Demon Coliseum!");
        Report("The greatest To-The-Death fights you can witness!!!");
        Report("Today will consist of 4 battles.");
        Report("The winner from the each battle will move on...");
        Report("and face a new challenger in the next battle.");
        Report("The last demon alive will be the Champion of the Coliseum!!!!");
        break;
    case 2:
        Report("Welcome to Round 2!!!", 1);
        break;
    case 3:
        Report("So far we've had 2 deadly rounds of bloody goodness!", 1);
        Report("Now on to Round 3!!!");
        break;
    case 4:
        Report("Round after bloody round brings us to the FINAL ROUND!!!", 1);
        Report("This round will determine the Champion of the Coliseum!!!");
        break;
    case 9:
        break;
    }

    Report("In the Left Corner...");
    if (round > 1)
    {
        Report("The Winner from the last round...");
    }
    switch (type1)
    {
    case 1:
        Report("A Fire Demon from the debths of Hades...");
        break;
    case 2:
        Report("A Wind Demon from the dark skies...");
        break;
    case 3:
        Report("A Thunder Demon from a furious storm...");
        break;
    case 4:
        Report("A Water Demon from the dark abyss...");
        break;

    }
    name1Announce = name1 + "!!!";
    Report(name1Announce, 0);
    Opponent1->left = true;
    PrintAnnouncerL();
    Sleep(1000);
    Opponent1->Presence();
    PrintBattleFrame();
    PrintAnnouncerL();
    Opponent1->PrintOpponent();
    Opponent1->SetupTempValues();
    Opponent1->PrintStats();
    Sleep(1000);

    Report("In the Right Corner...");
    switch (type2)
    {
    case 1:
        Report("A Fire Demon from the debths of Hades...");
        break;
    case 2:
        Report("A Wind Demon from the dark skies...");
        break;
    case 3:
        Report("A Thunder Demon from a furious storm...");
        break;
    case 4:
        Report("A Water Demon from the dark abyss...");
        break;
    }
    name2Announce = name2 + "!!!";
    Report(name2Announce, 0);
    Opponent2->left = false;
    PrintAnnouncerR();
    Sleep(1000);
    Opponent2->Presence();
    PrintBattleFrame();
    PrintAnnouncerR();
    Opponent2->PrintOpponent();
    Opponent1->PrintOpponent();
    Opponent2->SetupTempValues();
    Opponent1->PrintStats();
    Opponent2->PrintStats();
    Sleep(1000);
}

Enemy* Battle(Enemy* Opponent1, Enemy* Opponent2)
{
    int whoFirst = (rand() % 2 + 1);
    int tempDamage;
    int damageType;
    int tempType;
    bool turn = true;
    string damageString;
    string combatString;
    string typeString;
    string name;
    string announce;
    Enemy* first;
    Enemy* second;

    if (whoFirst == 1)
    {
        first = Opponent1;
        second = Opponent2;
    }
    else
    {
        first = Opponent2;
        second = Opponent1;
    }
    announce = first->GetName() + " goes first!";
    Report(announce);
    Report("Ready...", 1);
    Report("FIGHT!!!");
    ClearAnnouncer();
    Sleep(1000);

    do
    {
        if (turn)
        {
            turn = !turn;
            tempDamage = CombatDamage(first, second);
            CombatD(tempDamage, first, second);

        }
        else
        {
            turn = !turn;
            tempDamage = CombatDamage(second, first);
            CombatD(tempDamage, second, first);
        }
        first->PrintStats();
        second->PrintStats();

        Sleep(1000);
        hurry = +1;
        if (hurry < 23) hurry = 23;
    } while (first->tempHealth > 0 && second->tempHealth > 0);

    hurry = 0;
    if (first->tempHealth > 0)
    {
        second->DeadPrintOpponent();
        return first;
    }
    else
        first->DeadPrintOpponent();
    return second;
}

void Winner(Enemy* winner)
{
    string name;

    ClearBattleFrame();
    PrintFrame();
   
    for (int i = 0; i < 12; i++)
    {
        setCursorPosition(20, 6 + i);
        cout << Banner[i];
    }
    winner->left = false;
    Sleep(1000);
    winner->PrintOpponent();
    winner->Presence();
    winner->PrintOpponent();
    SetDamageColor(winner->GetDamageType());
    setCursorPosition(3, 2);
    for (int i = 0; i < 12; i++)
    {
        setCursorPosition(20, 6 + i);
        cout << Banner[i];
    }

    name = winner->GetName();
    cout << name;
    Sleep(5000);
    setCursorPosition(180, 29);
}

void StartScreen()
{
    system("color 07");
    for (int k = 0; k < 58; k++)
    {
        for (int i = 0; i < 6; i++)
        {
            setCursorPosition(133 - k, 8 + i);
            for (int j = 0; j < k; j++)
            {

                cout << Banner[i][j];
            }
        }       
        Sleep(50);
    }

    for (int j = 0; j < 35; j++)
    {
        for (int i = 0; i < 6; i++)
        {
            setCursorPosition(75 - j, 8 + i);
            cout << Banner[i];
        }
      
        Sleep(50);
    }
    system("color 40");
    Sleep(25);
    system("color 04");
    Sleep(25);
    system("color 40");
    Sleep(25);
    system("color 04");
    Sleep(25);
    system("color 40");
    Sleep(25);
    system("color 04");
    Sleep(25);
    setCursorPosition(52, 20);
    system("pause");
    system("color 07");

}

inline void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

string randomName(int length) {

    char consonents[] = { 'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z' };
    char vowels[] = { 'a','e','i','o','u','y' };

    string name = "";

    int random = rand() % 2;
    int count = 0;

    for (int i = 0; i < length; i++) {

        if (random < 2 && count < 2) {
            name = name + consonents[rand() % 19];
            count++;
        }
        else {
            name = name + vowels[rand() % 5];
            count = 0;
        }
        random = rand() % 2;
    }
    name[0] = toupper(name[0]);
    return name;
}






