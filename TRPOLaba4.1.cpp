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

void sear�hQuote(string t);

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
        cout << "1. ������ �����\n";
        cout << "2. ������������ ��� ������������ �����\n";
        cout << "\n��������: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            system("cls");
            cout << "������� �����, ��������� �� ��������� �����������:\n";
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
    cout << "\t\t\t\t-----����-----\n\n";
    cout << "1. �� ������� ������������ ������� ���������� �������� ������\n   ����� ������, ���������� ����������� ���������� �������� � ����������\n   ���������� ����� ���� � ������;\n\n";
    cout << "2. ������� �����������, ���������� � ������ �� ��� ����� �������\n   ������������ �����;\n\n";
    cout << "3. ��� ��������� � ������ ����������� � ���������� ������� ���������\n   ������������ ����� m ���������� ����� ����������� �, ��� �������� ������\n   � ���������� �� �������� ������ m ���������� ������� ���� �� ��������\n\n";
    cout << "4. ��� ������ ���������� �����������, ����������� ���������� �������\n   �������� ������� ������ ����� �� 1 �� 1999, �������� ��� �����;\n\n";
    cout << "5. ������� �����������, ����������� � �������, �.�. ������, �����\n   ������� ����������� �� ��������;\n\n";

    cout << "\n0. �����;\n";

    cout << "\n\n��� �����: ";
}

void Ex1(string text)
{
    /*������� �����, �� ������� ������������ ������� ���������� �������� ������ ����� ������,
    ���������� ����������� ���������� �������� � ���������� ���������� ����� ���� � ������;*/

    vector<string> minWords = MinWordsArray(text);

    char choice = ' ';
    int index = 0;

    do
    {
        system("cls");
        cout << text << endl << endl;

        cout << "--------------------------------------------------------\n\n";

        cout << "������� ����� (c ����������� ��������, ����� �� " << minWords.size() << "): " << minWords[index] << endl << endl << endl;

        cout << "���� �� ������ �����, ������� 'e', � ���� ���, �� ������� ����� �������;\n";

        choice = _getch();
        choice = toupper(choice);

        if (index == minWords.size() - 1)
        {
            cout << "\n����� ����������. �������������� �����.\n";
            break;

        }
        if (choice != 'E') index++;

    } while (choice != 'E');

    cout << "���� � ����������� ��������: " << minWords.size() << endl << endl;
}

void Ex2(string text)
{
    /*������� �����������, ���������� � ������ �� ��� ����� �������
    ������������ �����;*/
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
    /*3. ��� ��������� � ������ ����������� � ���������� ������� ��������� ������������ ����� m
    ���������� ����� ����������� ����� n, ��� �������� ������ ����� n ���������� �� �������� ������ m ����������
    ������� ���� �� ��������.*/

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

void Ex4(string text)
{
    /*��� ������ ���������� �����������, ����������� ���������� ������� �������� ������� ������ �����
    �� 1 �� 1999, �������� ��� �����;*/
    vector<string> sentencies = SplitToEachSentence(text);
    vector<string> words = SplitToWords(sentencies[sentencies.size() - 1]);

    cout << sentencies[sentencies.size() - 1] << endl << endl;

    for (int i = 0; i < words.size(); i++)
    {
        int number = searchRomanNumbers(words[i]);

        if (number != -1) {
            cout << words[i] << ": " << number << endl;
        }
    }
    cout << endl;
    system("pause");
}

void Ex5(string text)
{
    bool isQuote = false;
    string temp = "";
    vector<string> quote = {};

    std::cout << "�����:\n";
    std::cout << std::endl;
    std::cout << text << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < text.length(); i++)
    {
        if (isQuote) {
            temp += text[i];
        }

        if (text[i] == '\"' && !isQuote)
        {
            isQuote = true;
            temp += text[i];
        }
        else if (text[i] == '\"' && isQuote)
        {
            isQuote = false;
            quote.push_back(temp);
            temp.clear();
        }
    }

    cout << "Quote:\n";

    for (size_t i = 0; i < quote.size(); i++)
    {
        std::cout << i + 1 << ". " << quote[i] << std::endl;
    }

    system("pause");
}

vector<int> searchNumbers(string text)
{
    vector<string> words = SplitToWords(text);
    vector<int> numbers = {};

    for (int i = 0; i < words.size(); i++)
    {
        if (words[i][0] >= 48 && words[i][0] <= 57) {
            numbers.push_back(atoi(words[i].c_str()));
        }
    }

    return numbers;
}

vector<string> SplitToEachSentence(string text)
{
    vector<string> sentencies = {};
    string sentence, temp_sentence;

    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentence += text[i];
            sentencies.push_back(sentence);
            sentence = "";
            if (text[i + 1] == ' ') {
                i++;
            }
        }
        else if (i == text.length() - 1) {
            sentence += text[i];
            sentencies.push_back(sentence);
        }
        else {
            sentence += text[i];
        }
    }

    return sentencies;
}

vector<string> SplitToWords(string text)
{
    vector<string> words = {};
    string word;

    for (int i = 0; i < text.length(); i++)
    {
        if (i == text.length() - 1 && text[i] == '.' || i == text.length() - 1 && text[i] == ' ' || i == text.length() - 1 && text[i] == '!' || i == text.length() - 1 && text[i] == '?') {
            words.push_back(word);
        }
        else if (text[i] == ' ') {
            words.push_back(word);
            word = "";
        }
        else if (text[i] == '!' || text[i] == '.' || text[i] == '?' || text[i] == ',') {
            continue;
        }
        else {
            word += text[i];
        }
    }

    return words;
}

vector<string> MinWordsArray(string text)
{
    int minLength = SearchTheMinWord(text);

    char del[] = "0123456789";

    for (unsigned i = 0; i < strlen(del); i++)
    {
        text.erase(std::remove(text.begin(), text.end(), del[i]), text.end());
    }

    string temp;

    for (unsigned i = 0; i < text.length(); i++)
    {
        if (text[i] == ' ' && text[i + 1] == ' ' && i + 1 < text.length()) {
            temp += ' ';
            i++;
        }
        else if (i == text.length() - 1 && text[i] == ' ') {
            // ������ ������������� ��������� ������, ���� �� �����!
        }
        else {
            temp += text[i];
        }
    }

    vector<string> minWords = {};
    vector<string> words = SplitToWords(temp);

    for (int i = 0; i < words.size(); i++)
    {
        if (words[i].length() == minLength)
        {
            minWords.push_back(words[i]);
        }
    }

    return minWords;
}

string FindPalindroms(string text)
{
    vector<string> words = SplitToWords(text);
    string longestPalindrom = "", tempPalindrom;
    bool flag = true;

    for (int i = 0; i < words.size(); i++)
    {
        for (int j = 0, k = words[i].length() - 1; j < words[i].length() / 2; j++, k--)
        {
            if (words[i][j] != words[i][k]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            tempPalindrom = words[i];
        }

        if (longestPalindrom.length() < tempPalindrom.length()) {
            longestPalindrom = tempPalindrom;
        }

        flag = true;
    }

    if (longestPalindrom == "") {
        return "����� ��� �����������";
    }
    else {
        return longestPalindrom;
    }
}

string toBinary(int value)
{
    string binary;

    while (value != 0) {
        binary += (value % 2 == 0 ? "0" : "1");
        value /= 2;
    }

    reverse(binary.begin(), binary.end());

    return binary;
}

string returnReverseString(string str)
{
    int length = str.length();
    string reversed = str;

    for (int i = 0; i < length / 2; i++)
        swap(reversed[i], reversed[length - i - 1]);

    return reversed;
}

int SearchTheMinWord(string text)
{
    char del[] = "0123456789";

    for (unsigned i = 0; i < strlen(del); i++)
    {
        text.erase(std::remove(text.begin(), text.end(), del[i]), text.end());
    }

    string temp;

    for (unsigned i = 0; i < text.length(); i++)
    {
        if (text[i] == ' ' && text[i + 1] == ' ' && i + 1 < text.length()) {
            temp += ' ';
            i++;
        }
        else if (i == text.length() - 1 && text[i] == ' ') {
            // ������ ������������� ��������� ������, ���� �� �����!
        }
        else {
            temp += text[i];
        }
    }

    vector<string> words = SplitToWords(temp);
    int minLength = INT_MAX;

    for (int i = 1; i < words.size(); i++)
    {
        if (words[i].length() < minLength)
        {
            minLength = words[i].length();
        }
    }

    return minLength;
}

int romanToInt(string text)
{
    //������������� ���������, ������� ������ �� �������� (���� - ��������) � ��� ���������� ������ �������� ��������������� ����
    map<char, int> romanValues = { { 'I',1 }, { 'V',5 },{ 'X',10 },{ 'L',50 },{ 'C',100 },{ 'D',500 },{ 'M',1000 } };

    int limit = text.size();
    int retVal = 0;
    for (int i = 0; i < limit; i++)
    {
        auto valueIter = romanValues.find(text[i]);
        if (valueIter != romanValues.end())
        {
            int modifier = 1;
            if (((i + 1) < limit) && (valueIter->second < romanValues[text[i + 1]]))
            {
                modifier = -1;
            }
            retVal += valueIter->second * modifier;
        }
    }
    return retVal;
}

int searchRomanNumbers(string t)
{
    string r[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    int b, i; // ������ �������� ������� � ������ � ������ ������� ������� ����� � ������� r

    for (b = 0, i = 0; b < t.length() && i < 13; ++i)
    {
        int rl = r[i].length(); // ���������� �������� � �������� �������
        if (t.substr(b, rl) == r[i])
        {
            if (rl == 1 && i != 0)
            {
                int count = 1; // ���������� ��������
                while (++b < t.length() && t.substr(b, rl) == r[i]) ++count; // ������� � ������� ������������� ����
                if (count > 3)
                {
                    --b;
                    break;
                }
            }
            else b += rl;
        }
    }

    if (b < t.length()) {
        //�� ������� �����
        return -1;
    }
    else {
        //������� �����
        return romanToInt(t);
    }
}

int toDecimal(int number)
{
    int decimal = 0;
    int rem = 0;
    int i = 0;

    while (number != 0) {
        rem = number % 10;
        number /= 10;
        decimal += rem * pow(2, i);
        ++i;
    }

    return decimal;
}

void sear�hQuote(string t)
{
    // Lorem abcd ada ipsum "afgfa dolor 8 sit 187 amet". 
    // Consectetur abcdcba 13 adipiscing aba 34 elit. 
    // "Sed do eiusmod tempor incididunt ut 87 labore et VI dolore XIV magna aliqua. Lorem ipsum VI dolor XIV sit amet\".

    int counter = 0;
    bool isQuote = false;

    for (char ch : t)
    {
        if (ch == '\"')
            counter++;
    }

    if (counter % 2 != 0) {
        cout << "Error: Odd number of quotes! (" << counter << ")" << endl;
        system("pause");
        return;
    }

    vector<string> quotes = {};
    string temp;

    for (char ch : t) {
        if (ch == '\"' && !isQuote) {
            isQuote = true;
        }
        else if (ch == '\"' && isQuote) {
            isQuote = false;
            quotes.push_back(temp);
            temp = "";
        }

        if (ch != '\"' && isQuote) {
            temp += ch;
        }
    }

    cout << "Counter: " << counter << endl;
    cout << "Quotes:" << endl;

    for (string quote : quotes) {
        cout << quote << endl;
    }

    system("pause");
}