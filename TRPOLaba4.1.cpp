#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <conio.h>
#include <format>
#include <algorithm>
#include <regex>
using namespace std;

void Menu();
void MenuText();

void Ex1(string text);
void Ex2(string text);
void Ex3(string text);
void Ex4(string text);
void Ex5(string text);

vector<int> searchNumbers(string text);
vector<string> SplitToEachSentence(string text);
vector<string> SplitToWords(string text);
vector<string> MinWordsArray(string text);

string FindPalindroms(string text);
string toBinary(int value);
string returnReverseString(string str);

int SearchTheMinWord(string text);
int romanToInt(string text);
int searchRomanNumbers(string text);
int toDecimal(int number);

void searñhQuote(string t);

int main()
{
    system("chcp 1251");
    setlocale(LC_ALL, "ru");

    Menu();

    return 0;
}

void Menu()
{
    system("cls");

    int choice = 0;
    string text;

    do
    {
        cout << "1. Ââåñòè òåêñò\n";
        cout << "2. Èñïîëüçîâàòü óæå ñóùåñòâóþùèé òåêñò\n";
        cout << "\nÂûáåðèòå: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            system("cls");
            cout << "Ââåäèòå òåêñò, ñîñòîÿùèé èç íåñîëüêèõ ïðåäëîæåíèé:\n";
            cin.ignore();
            getline(cin, text);
            choice = 0;
            break;
        }
        case 2:
        {
            text = "Lorem abcd ada ipsum \"afgfa dolor 8 sit 187 amet\". Consectetur abcdcba 13 adipiscing aba 34 elit. \"Sed do eiusmod tempor incididunt ut 87 labore et VI dolore XIV magna aliqua. Lorem ipsum VI dolor XIV sit amet\".";
            choice = 0;
            break;
        }
        default:
            system("cls");
            cout << "Incorrect data;\n";
            system("pause");
            break;
              }
    } while (choice != 0);

    do   
    {
        MenuText();
        cin >> choice;

        system("cls");

        switch (choice)
        {
        case 0:
            break;
        case 1:
            Ex1(text);
            break;
        case 2:
            Ex2(text);
            break;
        case 3:
            Ex3(text);
            break;
        case 4:
            Ex4(text);
            break;
        case 5:
            Ex5(text);
            break;
        default:
            cout << "\t\t!!!-ERROR-!!!\nAction with this index not found. Try again.\n\n";
            system("pause");
            break;
        }
    } while (choice != 0);
}

    void MenuText()
    {
        system("cls");
        cout << "\t\t\t\t-----ÌÅÍÞ-----\n\n";
        cout << "1. Ïî íàæàòèþ ïðîèçâîëüíîé êëàâèøè ïîî÷åðåäíî âûäåëÿåò êàæäîå\n   ñëîâî òåêñòà, ñîäåðæàùåå ìèíèìàëüíîå êîëè÷åñòâî ñèìâîëîâ è îïðåäåëÿåò\n   êîëè÷åñòâî òàêèõ ñëîâ â òåêñòå;\n\n";
        cout << "2. Âûâîäèò ïðåäëîæåíèÿ, îïðåäåëÿåò â êàæäîì èç íèõ ñàìîå äëèííîå\n   ñèììåòðè÷íîå ñëîâî;\n\n";
        cout << "3. Äëÿ çàäàííîãî â ïåðâîì ïðåäëîæåíèè â äåñÿòè÷íîé ñèñòåìå ñ÷èñëåíèÿ\n   íàòóðàëüíîãî ÷èñëà m îïðåäåëÿåò òàêîå íàòóðàëüíîå ï, ÷òî äâîè÷íàÿ çàïèñü\n   ï ïîëó÷àåòñÿ èç äâîè÷íîé çàïèñè m èçìåíåíèåì ïîðÿäêà öèôð íà îáðàòíûé\n\n";
        cout << "4. Äëÿ òåêñòà ïîñëåäíåãî ïðåäëîæåíèÿ, ÿâëÿþùåãîñÿ ïðàâèëüíîé çàïèñüþ\n   ðèìñêèìè öèôðàìè öåëîãî ÷èñëà îò 1 äî 1999, ïîëó÷àåò ýòî ÷èñëî;\n\n";
        cout << "5. Âûâîäèò ïðåäëîæåíèÿ, çàêëþ÷åííûå â êàâû÷êè, ò.å. öèòàòû, ñëîâà\n   êîòîðûõ óïîðÿäî÷åíû ïî àëôàâèòó;\n\n";

        cout << "\n0. Âûõîä;\n";

        cout << "\n\nÂàø âûáîð: ";
    }

    void Ex1(string text)
    {
        /*âûâîäèò òåêñò, ïî íàæàòèþ ïðîèçâîëüíîé êëàâèøè ïîî÷åðåäíî âûäåëÿåò êàæäîå ñëîâî òåêñòà,
        ñîäåðæàùåå ìèíèìàëüíîå êîëè÷åñòâî ñèìâîëîâ è îïðåäåëÿåò êîëè÷åñòâî òàêèõ ñëîâ â òåêñòå;*/

        vector<string> minWords = MinWordsArray(text);

        char choice = ' ';
        int index = 0;

        do
          {
            system("cls");
            cout << text << endl << endl;

            cout << "--------------------------------------------------------\n\n";

            cout << "Òåêóùåå ñëîâî (c ìèíèìàëüíûé ðàçìåðîì, âñåãî èõ " << minWords.size() << "): " << minWords[index] << endl << endl << endl;

            cout << "Åñëè âû õîòèòå âûéòè, íàæìèòå 'e', à åñëè íåò, òî íàæìèòå ëþáóþ êëàâèøó;\n";

            choice = _getch();
            choice = toupper(choice);

            if (index == minWords.size() - 1)
              {
                cout << "\nÒåêñò çàêîí÷èëñÿ. Ïðèíóäèòåëüíûé âûõîä.\n";
                break;

            }
            if (choice != 'E') index++;

        } while (choice != 'E');

        cout << "Ñëîâ ñ ìèíèìàëüíûì ðàçìåðîì: " << minWords.size() << endl << endl;
    } 

    void Ex2(string text)
    {
        /*âûâîäèò ïðåäëîæåíèÿ, îïðåäåëÿåò â êàæäîì èç íèõ ñàìîå äëèííîå
        ñèììåòðè÷íîå ñëîâî;*/
        system("cls");

        cout << text << endl << endl;
        cout << "--------------------------------------------------------\n";

        vector<string> sentencies = SplitToEachSentence(text);

        cout << "Palindroms:\n\n";
        for (int i = 0; i < sentencies.size(); i++)
        {
            //system("cls");
            cout << "Sentence " << i + 1 << ": " << FindPalindroms(sentencies[i]) << "\n";
        }
        cout << endl;
        system("pause");
    }
    void Ex3(string text)
{
    /*3. äëÿ çàäàííîãî â ïåðâîì ïðåäëîæåíèè â äåñÿòè÷íîé ñèñòåìå ñ÷èñëåíèÿ íàòóðàëüíîãî ÷èñëà m
    îïðåäåëÿåò òàêîå íàòóðàëüíîå ÷èñëî n, ÷òî äâîè÷íàÿ çàïèñü ÷èñëà n ïîëó÷àåòñÿ èç äâîè÷íîé çàïèñè m èçìåíåíèåì
    ïîðÿäêà öèôð íà îáðàòíûé.*/

    //n = 001 100
    //m = 100 001

    vector<int> numbers = searchNumbers(text);
    vector<int> decimals = {};

    cout << "Numbers from sentence:" << endl;
    for (int num : numbers) {
        cout << num << " ";
        decimals.push_back(toDecimal(stoi(returnReverseString(toBinary(num)))));
    }

    cout << "\nReversed to binary & converted to decimal:" << endl;
    for (int decimal : decimals) {
        cout << decimal << " ";
    }

    cout << endl;
    system("pause");


}
