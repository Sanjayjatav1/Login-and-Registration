#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;
void login();
void registration();
void forgot();


int main()
{
    int c;
    cout << endl;
    cout << "\t\t\t _______________________________________________________________ " << endl;
    cout << "\t\t\t|                                                               |" << endl;
    cout << "\t\t\t|                 Welcome To Login Page                         |" << endl;
    cout << "\t\t\t|                       M E N U                                 |" << endl;
    cout << "\t\t\t|       Press 1 for Login.                                      |" << endl;
    cout << "\t\t\t|       Press 2 for Register.                                   |" << endl;
    cout << "\t\t\t|       Press 3 for Forgot Password.                            |" << endl;
    cout << "\t\t\t|       Press 4 for Exit.                                       |" << endl;
    cout << "\t\t\t|                                                               |" << endl;
    cout << "\t\t\t|                                                               |" << endl;
    cout << "\t\t\t|_______________________________________________________________|" << endl;
    cout << endl;
    cout << "\t\tPlease Enter your Choice : ";
    cin >> c;

    switch(c)
    {
    case 1:
        login();
        break;
    case 2:
        registration();
        break;
    case 3:
        forgot();
        break;
    case 4:
        cout << "\t\t Thank you!!\n\n";
        break;
    default:
        cout << "Please select the number from given option: ";
        main();

    }

}
 void login()
{
    int count = 0;
    string userId, password,id, pass;

    cout << "\t\t\t Please enter the username and password :" <<endl;
    cout << "\t\t\t USERNAME ";
    cin >> userId;
    cout << "\t\t\t PASSWORD ";
    cin >> password;

    ifstream input("records.txt");

    while(input>>id>>pass)
    {
        if(id==userId && pass==password)
        {

            count == 1;

        }
    }
    input.close();
    if(count == 1)
    {
        cout <<userId<< "\n Your LOGIN is successful \n Thanks for logging in ! \n";
        main();
    }
    else
    {

        cout << "\n LOGIN ERROR  \n  Please check your username and password\n";
        main();
        system("cls");
    }
}

void registration()
{
    string ruserId, rpassword,rid,rpass;

    cout << "\t\t Enter the username :";
    cin >> ruserId;
    cout << "\t\t Enter the password :";
    cin >> rpassword;

    ofstream f1("records.txt",ios::app);
    f1<<ruserId<< " "<< rpassword<<endl;

    cout << "\n\t\t\t Registration is successful! \n";
    main();


}
void forgot()
{
    int option;

    cout << "\t\t\t You forgot the password? No worries \n";
    cout << "Press 1 to search your id by username " << endl;
    cout << "Press 2 to go back to the main menu " << endl;
    cout << "\t\t\t Enter your choice :";
    cin >> option;
    switch(option)
    {
    case 1 :
        {
            int count = 0;
            string suserId, sid,spass;
            cout << "\n\t\t\tEnter the username which you remembered :";
            cin >> suserId;

            ifstream f2("records.txt");
            while(f2>>sid>>spass)
            {
                if(sid==suserId)
                {
                    count == 1;
                }
            }
            f2.close();
            if(count == 1)
            {
                cout << "\n\n Your account is found! \n";
                cout << "\n\n Your password is : "<<spass;
                main();
            }
            else
            {
                cout << "\n\t  Sorry your account is not found! \n";
                main();
            }
            break;
        }
    case 2:
        {
            main();
        }
    default :
        cout << "\t\t\t Wrong choice ! Please try again \n";
        forgot();

    }
  }


