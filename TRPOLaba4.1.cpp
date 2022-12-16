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

void searсhQuote(string t);

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
        cout << "1. Ввести текст\n";
        cout << "2. Использовать уже существующий текст\n";
        cout << "\nВыберите: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            system("cls");
            cout << "Введите текст, состоящий из несольких предложений:\n";
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
        cout << "\t\t\t\t-----МЕНЮ-----\n\n";
        cout << "1. По нажатию произвольной клавиши поочередно выделяет каждое\n   слово текста, содержащее минимальное количество символов и определяет\n   количество таких слов в тексте;\n\n";
        cout << "2. Выводит предложения, определяет в каждом из них самое длинное\n   симметричное слово;\n\n";
        cout << "3. Для заданного в первом предложении в десятичной системе счисления\n   натурального числа m определяет такое натуральное п, что двоичная запись\n   п получается из двоичной записи m изменением порядка цифр на обратный\n\n";
        cout << "4. Для текста последнего предложения, являющегося правильной записью\n   римскими цифрами целого числа от 1 до 1999, получает это число;\n\n";
        cout << "5. Выводит предложения, заключенные в кавычки, т.е. цитаты, слова\n   которых упорядочены по алфавиту;\n\n";

        cout << "\n0. Выход;\n";

        cout << "\n\nВаш выбор: ";
    }

    void Ex1(string text)
    {

        vector<string> minWords = MinWordsArray(text);

        char choice = ' ';
        int index = 0;

        do
        {
            system("cls");

            cout << "--------------------------------------------------------\n\n";

            cout << "Текущее слово (c минимальный размером, всего их " << "): " << minWords[index] << endl;

            cout << "Если вы хотите выйти, нажмите 'e', а если нет, то нажмите любую клавишу;\n";

            choice = _getch();

            if (index == minWords.size() - 1)
            {
                cout << "\nТекст закончился. Принудительный выход.\n";
                break;

            }
            if (choice != 'E') index++;

        } while (choice != 'E');

        cout << "Слов с минимальным размером: " << minWords.size() << endl << endl;
    }