#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
 
using namespace std;
 
 

{
    string login_new;
    string password_new;
}
users[100];
 
void main()
{
	    setlocale(LC_ALL, "rus");
	    cout << "1 - Вход от имени пользователя" << endl;
	    cout << "2 - Вход от имени администратора" << endl;
	    int a;
	    cin >> a;
	    switch (a)
    {
 
    case 1: vhod();
    case 2: admin();
 
 
    }
 
}
void vhod()
{
    
    bool flag = false;
 
    string login, password;
    cout << "Введите логин: " << endl;
    cin >> login;
    cout << "Введите пароль: " << endl;
    cin >> password;
    flag = check(login, password);
    if (flag == true)
    {
        cout << "Вы вошли в систему!" << endl;
    }
    else
    {
        system("cls");
        cout << "Неверный пароль. Попробуйте еще раз." << endl;
        main();
        
    }
    
    
    system("pause");
 
 
 
}
 
 
bool check(string login, string password)
 
{
    
    if  (login == "lera_burko" && password == "valerka1997")
    {
        return true;
    }
    else
    {
        return false;
    }
} 
////////////////////////////////////////////////////////////////////////////////////
 
void admin()
{
    bool flag_1 = false;
 
    string login_admin, password_admin;
    cout << "Введите логин: " << endl;
    cin >> login_admin;
    cout << "Введите пароль: " << endl;
    cin >> password_admin;
 
    flag_1 = check_1(login_admin, password_admin);
    if (flag_1 == true)
    {
        cout << "Вы вошли в систему от имени администратора!" << endl;
    }
    else
    {
        system("cls");
        cout << "Неверный пароль. Попробуйте еще раз." << endl;
        main();
    }
 
    /////////////////////////////////////////////////////////////////////////////////////
    cout << "1 - Зарегестрировать нового пользователя: " << endl;
    cout << "2 - Выйти: " << endl;
    int a1;
    cin >> a1;
    switch (a1)
    {
    case 1: register_1();
    case 2: main();
    }
 
    }
    bool check_1(string login_admin, string password_admin)
    {
        if (login_admin == "andreiburko99" && password_admin == "android1999")
        {
            return true;
        }
        else
        {
            return false;
        }
    } 
 
    ////////////////////////////////////////////////////////////////////////////////////////////
    
 
   
 
    void login()
    {
        string login_new, password_new;
        cout << "Введите логин: " << endl;
        cin >> login_new;
        cout << "Введите пароль: " << endl;
        cin >> password_new;
        read(login_new, password_new);
        for (int i = 0; i < 100; i++)
        {
            if (login_new == users[1].login_new && password_new == users[1].password_new)
            {
                cout << "Вход успешен!" << endl; }
	}
    }
