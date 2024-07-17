#pragma once
#include <iostream>
#include <fstream> //because here we are going to use file handling
#include <stdlib.h>
#include <string>
#include <list>

using namespace std;

class User {
 
private:
    int pcode;
    float price;
    float dis;
    string pname;
  
public:

    void userlogin() {
        int choice;

        system("cls");

        cout << "\n\n\n\t\t\t__________________________________________________\n\n\n";
        cout << "\t\t\t   Welcome to user login and registration system      \n\n\n";
        cout << "\t\t\t                Instruction Manu                  \n\n\n";
        cout << "\t\t\t         |press 1 to Login                  |\n";
        cout << "\t\t\t         |press 2 to Register               |\n";
        cout << "\t\t\t         |press 3 to forgot your password   |\n";
        cout << "\t\t\t         |press 4 to Exit                   |\n\n\n";




        try {
            cout << "\t\t\t         please enter your choice : ";
            cin >> choice;
            cout << endl;
            if (cin.fail()) {  // cin.fail() checks if the value in the cin
                // stream is the correct type, if not it returns true,
                // otherwise it returns false.
                throw runtime_error("\t\t\t            Input is not an integer!       \n\n\n");
            }
        }
        catch (runtime_error& e) {
            cout << e.what() << endl;
            cin.clear();  // reset the error flag on cin (so that future I/O operations will work correctly)
            cin.ignore(1000, '\n');  // ignore last input
        }

        if (1 <= choice && choice <= 4) {
            switch (choice)
            {
            case 1:
                login();
                break;
            case 2:
                registerUser();
                break;

            case 3:
                forgotpw();
                break;

            case 4:
                cout << "\t\t\t            Thank you            \n\n";
                //main();
                break;

            default:
                cout << "\n\n\n\t\t\t                Invalid Choice!        \n";
                cout << "\n\n\n\t\t\t                   Try again        \n\n\n";
                break;

            }
        }

        else
        {
            cout << "\n\n\n\t\t\t                Invalid Choice!        \n";
            cout << "\n\n\n\t\t\t                   Try again        \n\n\n";

            cin.get();
            cin.get();
            system("cls");
            userlogin();
        }
    }

    void login() {
        int status = 0;
        string username;
        string password;
        string un;
        string pw;

        system("cls");

        cout << "\t\t\t    please enter the username and password ( WITHOUT SPACES )   \n\n\n";
        cout << "\tUsername : ";
        cin >> username;
        cout << "\tPassword : ";
        cin >> password;

        ifstream input("data.txt");

        while (input >> un >> pw) {
            if (un == username && pw == password) {
                status = 1;
            }
        }
        input.close();

        if (status == 1) //if login goes wrong user name and password is incorrect
        {
            cout << "\t\t\t        Successfully Logged in to " << username << " \n\n";
            cout << "\t\t\t            Thank you for login\n\n";
            cin.get();
            cin.get();
            system("cls");
            Buy_byLogIN();
            //main();

            //This is a Windows-specific command, which tells the OS to run the pause
            // program. This program waits to be terminated, and halts the execution of the parent C++ program. 
        }
        else //if success then return 1 or proceed further
        {
            cout << "\t\t\t                    Invalid Log in             \n\n";
            cout << "\t\t\t         please check your username and password\n\n";
            cin.get();
            cin.get();
            system("cls");
            userlogin();
        }
    }

    void Buy_byLogIN()
    {

        int choice;

        system("cls");

        cout << "\n\n\n\t\t\t__________________________________________________\n\n\n";
        cout << "\t\t\t                Welcome to User Log in page         \n\n\n";
        cout << "\t\t\t                Instruction Manu                  \n\n\n";
        cout << "\t\t\t         |press 1 to Purchase Products      |\n";
        cout << "\t\t\t         |press 2 to Main menu              |\n";
        cout << "\t\t\t         |press 3 to Exit                   |\n\n\n";


        try {
            cout << "\t\t\t         please enter your choice : ";
            cin >> choice;
            cout << endl;
            if (cin.fail()) {  // cin.fail() checks if the value in the cin
                // stream is the correct type, if not it returns true,
                // otherwise it returns false.
                throw runtime_error("\t\t\t            Input is not an integer!       \n\n\n");
            }
        }
        catch (runtime_error& e) {
            cout << e.what() << endl;
            cin.clear();  // reset the error flag on cin (so that future I/O operations will work correctly)
            cin.ignore(1000, '\n');  // ignore last input
        }

        if (1 <= choice && choice <= 3) {
            switch (choice)
            {
            case 1:
                receipt();
                break;
            case 2:
                login();
                break;           

            case 3:
                cout << "\t\t\t            Thank you            \n\n";
                break;

            default:
                cout << "\n\n\n\t\t\t                Invalid Choice!        \n";
                cout << "\n\n\n\t\t\t                   Try again        \n\n\n";
                break;

            }
        }

        else
        {
            cout << "\n\n\n\t\t\t                Invalid Choice!        \n";
            cout << "\n\n\n\t\t\t                   Try again        \n\n\n";

            cin.get();
            cin.get();
            system("cls");
            login();
        }
    }

  
    void list()
    {
        fstream data;
        data.open("database.txt", ios::in);
        cout << "\n\n|______________________________________________________\n";
        cout << "proNo\t\tName\t\tPrice\n";
        cout << "\n\n|______________________________________________________\n";
        data >> pcode >> pname >> price >> dis;

        while (!data.eof())
        {
            cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
    }

    void receipt()
    {
        fstream data;

        int arrc[100];
        int arrq[100];
        char choice;
        int c = 0;
        float amount = 0;
        float dis = 0;
        float total = 0;
     

        cout << "\n\n\t\t\t RECEIPT";
        data.open("database.txt", ios::in);
        if (!data)
        {
            cout << "\n\n Empty database";
        }

        else {
            data.close();

        m:
            list();
            cout << "\n\n|______________________________________________________\n";
            cout << "\n\n|                                                      \n";
            cout << "\n\n|                  Please place the order              \n";
            cout << "\n\n|                                                      \n";
            cout << "\n\n|______________________________________________________\n";
            do
            {
                cout << "\n\nEnter Product code :";
                cin >> arrc[c];
                cout << "\n\nEnter the product quantity :";
                cin >> arrq[c];
                for (int i = 0; i < c; i++)
                {
                    if (arrc[c] == arrc[i])
                    {
                        cout << "\n\n Duplicate product code. Please try again!";
                        goto m;
                    }
                }
                c++;
                cout << "\n\n Do you want to buy another product? if yes then press y else no";
                cin >> choice;
            } while (choice == 'y');

            cout << "\n\n\t\t\t________________________________RECEIPT______________________________________\n";
            cout << "\nProduct No\t Product Name\t Product quantity\tprice\tAmount\tAmount with discount\n";

            for (int i = 0; i < c; i++)
            {
                data.open("database.txt", ios::in);
                data >> pcode >> pname >> price >> dis;
                while (!data.eof())
                {
                    if (pcode == arrc[i])
                    {
                        amount = price * arrq[i];
                        dis = amount - (amount * dis / 100);
                        total = total + dis;
                        cout << "\n" << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t\t" << amount << "\t\t" << dis;

                    }
                    data >> pcode >> pname >> price >> dis;
                }

            }
            data.close();
        }
        cout << "\n\n|______________________________________________________\n";
        cout << "\n Total Amount : " << total;
    }
   
    void registerUser() {
        int status = 0;
        string username;
        string password;
        string un;
        string pw;

        system("cls");

        cout << "\t\t\t    please enter the username and password ( WITHOUT SPACES )    \n\n\n";
        cout << "\tUsername : ";
        cin >> username;

        //getline(cin, username);

        for (int i = 0; i < username.size(); i++) {
            if (username[i] == ' ') {
                cout << "\n\n\n\t\t\tplease recheck wether your username contains a space and try again\n\n\n";
                cin.get();
                cin.get();
                registerUser();
            }
        }

        cout << "\tPassword : ";
        cin >> password;

        //getline(cin, password);

        for (int i = 0; i < password.size(); i++) {
            if (password[i] == ' ') {
                cout << "\n\n\n\t\t\tplease recheck wether your password contains a space and try again\n\n\n";
                cin.get();
                cin.get();
                registerUser();
            }
        }

        ifstream input("data.txt");

        while (input >> un >> pw) {
            if (un == username && pw == password) {
                status = 1;
            }
        }
        input.close();

        if (status == 1) //if login goes wrong user name and password is incorrect
        {
            cout << "\t\t\t            username already exist \n\n";
            cout << "\t\t\t                   Try again \n\n";
            cin.get();
            cin.get();
            registerUser();

            //This is a Windows-specific command, which tells the OS to run the pause
            // program. This program waits to be terminated, and halts the execution of the parent C++ program. 
        }
        else //if success then return 1 or proceed further
        {
            ofstream fi("data.txt", ios::app);
            fi << username << ' ' << password << endl;


            cout << "\n\n\n\t\t\t           Registration is successful       \n\n\n";
            cin.get();
            cin.get();
            system("cls");

            userlogin();
        }


    }

    void forgotpw() {

        int option;
        system("cls");

        cout << "\n\n\n\t\t\t                Forgot password Manu                  \n\n\n";
        cout << "\t\t\t         |press 1 to Search it by username    |\n";
        cout << "\t\t\t         |press 2 to Return to login Manu     |\n\n\n";



        try {
            cout << "\t\t\t         please enter your choice : ";
            cin >> option;
            cout << endl;
            if (cin.fail()) {  // cin.fail() checks if the value in the cin
                // stream is the correct type, if not it returns true,
                // otherwise it returns false.
                throw runtime_error("\t\t\t              Input is not an integer!  \n\n");
            }
        }
        catch (runtime_error& e) {
            cout << e.what() << endl;
            cin.clear();  // reset the error flag on cin (so that future I/O operations will work correctly)
            cin.ignore(1000, '\n');  // ignore last input
        }

        if (option == 1 || option == 2)
        {
            switch (option)
            {
            case 1:
            {
                int count = 0;
                string username;
                string un;
                string pw;

                cout << "\t\t\t    enter the username that you remember : ";
                cin >> username;
                ifstream f2("data.txt");
                while (f2 >> un >> pw) {
                    if (un == username) {
                        count = 1;
                        break;
                    }
                }
                f2.close();
                if (count == 1) {
                    cout << "\n\n\n\n";
                    cout << "\t\t\t          Congradulations!  \n\n";
                    cout << "\t\t\t    we have found your account!  \n\n\n\n";
                    cout << "\t\t\t    your password is : " << pw << endl;
                    cin.get();
                    cin.get();
                    system("cls");
                    userlogin();
                }


                else {
                    cout << "\t\t\t                  Sorry we cannot find your account\n";
                    cout << "\t\t\t     Please check whether you entered the username correctly \n\n\n";
                    cin.get();
                    cin.get();
                    system("cls");
                    userlogin();
                }
                break;
            }
            case 2:
            {
                system("cls");
                userlogin();
                break;
            }
            }
        }
        else
        {
            cout << "\t\t\t          invalid choice      \n\n\n";
            cout << "\t\t\t         Please try again      \n\n\n";
            cin.get();
            cin.get();
            system("cls");
            forgotpw();
            //system("cls");
        }
    }

  

};