#pragma once
#include <iostream>
#include <fstream> //because here we are going to use file handling
#include <stdlib.h>
#include <string>
#include "Singly_Linked_List.h"
#include"User.h"
#include"Guest.h"

using namespace std;

class admin {

private:
    int pcode;
    float price;
    float dis;
    string pname;

    void userinfo() {
        Singly_Linked_List sll;
        ifstream file;
        file.open("data.txt");
        string line;
        while (getline(file, line))
        {
            sll.insertLast(line);

        }
        file.close();
        cout << "\n\n\n\t\t\there are the usernames and passwords of the users\n\n\n";

        sll.print();

        cin.get();
        cin.get();
        system("cls");
        adminlogin();
    }

    void manageUser() {
        int choice;

        system("cls");

        cout << "\n\n\n\t\t\t__________________________________________________\n\n\n";
        cout << "\t\t\t                Welcome to Admin           \n\n\n";
        cout << "\t\t\t                Instruction Manu                  \n\n\n";
        cout << "\t\t\t         |press 1 to remove a user             |\n";
        cout << "\t\t\t         |press 2 to make a user admin         |\n";
        cout << "\t\t\t         |press 3 clear all users              |\n";
        cout << "\t\t\t         |press 4 to Main menu                 |\n\n\n";



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
            {
                string user;
                cout << "enter the username of the user to be removed" << endl;
                cin >> user;
                rmvuser(user);
                break;
            }
            case 2:
            {
                string user;
                cout << "enter the username of the user to be promoted" << endl;
                cin >> user;
                adminUser(user);
                break;
            }

            case 3:
                remove("data.txt");
                cout << "\n\n\n\t\t\tuser data cleared\n\n\n" << endl;
                cin.get();
                cin.get();
                adminlogin();
                break;


            case 4:
                cout << "\t\t\t            Thank you            \n\n";
                cin.get();
                cin.get();
                adminlogin();
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
            adminlogin();
        }
    }

    void rmvuser(string user) {
        string line;
        string uname, pword, un, pw;
        int status = 0;

        // Open file for read
        ifstream is("data.txt");

        // Open temp file for write
        ofstream ofs("temp.txt");

        // Checking if user exist
        while (getline(is, line))
        {
            // Split line in file
            uname = line.substr(0, line.find(' '));
            pword = line.substr(line.find(' ') + 1);

            // Compare username
            if (user != uname)
            {
                ofs << uname << " " << pword << endl;
            }
        }

        // Close both files
        is.close();
        ofs.close();

        // Remove old file
        remove("data.txt");

        // Rename new file to old file
        rename("temp.txt", "data.txt");

        ifstream input("data.txt");

        while (input >> un >> pw) {
            if (un != user) {
                status = 1;
            }
        }
        input.close();

        if (status == 1) //if login goes wrong user name and password is incorrect
        {
            cout << "\t\t\t                username not exist \n\n";
            cout << "\t\t\t                   Try again \n\n";
            cin.get();
            cin.get();
            manageUser();

        }
        else {
            cout << "\t\t\t  User deleted successfully...\n\n\n";

            cin.get();
            cin.get();
            system("cls");
            manageUser();
        }



    }

    void adminUser(string user) {
        int count = 0;
        string pass;
        string un;
        string pw;

        ifstream f2("data.txt");
        while (f2 >> un >> pw) {
            if (un == user) {
                count = 1;
                break;
            }
        }
        f2.close();
        if (count == 1) {
            pass = pw;
        }

        if (count == 0) //if login goes wrong user name and password is incorrect
        {
            cout << "\t\t\t                username not exist \n\n";
            cout << "\t\t\t                   Try again \n\n";
            cin.get();
            cin.get();
            manageUser();

        }

        else {
            ofstream fi("admin.txt", ios::app);
            fi << user << ' ' << pass << endl;
            system("cls");

            cout << "\t\t\t  User promoted to admin successfully...\n\n\n";

            cin.get();
            cin.get();
            system("cls");

            manageUser();
        }



    }

public:
    /* ---------------------- 01. Directed to Admin portal --------------------------*/
    void adminlogin() {
        int choice;
        system("cls");
        cout << "\n\n\n\t\t\t__________________________________________________\n\n\n";
        cout << "\t\t\t  Welcome to admin login and registration system  \n\n\n";
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
                alogin();
                break;
            case 2:
                aregisterUser();
                break;

            case 3:
                aforgotpw();
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
            adminlogin();
        }
    }

   /* If and only if admin log in to the page, then he can edit the product details (Maintained Security)*/
    
    void alogin() {
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

        ifstream input("admin.txt"); // All details of admins are stored here

        while (input >> un >> pw) { 
            if (un == username && pw == password) {
                status = 1;
            }
        }
        input.close(); // After reading data from it, In C++, it's a good practice to close a file explicitly when you are done using it.

        if (status == 1) //if login goes wrong user name and password is incorrect
        {
            cout << "\t\t\t        Successfully Logged in to " << username << " \n\n";
            cout << "\t\t\t            Thank you for login\n\n";
            cin.get();
            cin.get();
            int choice;

            system("cls"); // to clear the console screen in a command-line interface

            cout << "\n\n\n\t\t\t__________________________________________________\n\n\n";
            cout << "\t\t\t                Welcome to Admin           \n\n\n";
            cout << "\t\t\t                Instruction Manu                  \n\n\n";
            cout << "\t\t\t         |press 1 to User management           |\n";
            cout << "\t\t\t         |press 2 to Product management        |\n";
            cout << "\t\t\t         |press 3 to Main menu                 |\n";
            cout << "\t\t\t         |press 4 to Exit                      |\n\n\n";


            try {
                cout << "\t\t\t         Please enter your choice : ";
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
                    User_Management();
                    break;
                case 2:
                    Product_Management();
                    break;

                case 3:
                    cout << "\t\t\t            Thank you            \n\n";
                    adminlogin();
                    break;

                case 4:
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
                alogin();
            }

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
            adminlogin();
        }
    }

    void User_Management()
    {
      
        int choice;

        system("cls");

        cout << "\n\n\n\t\t\t__________________________________________________\n\n\n";
        cout << "\t\t\t                Welcome to User management          \n\n\n";
        cout << "\t\t\t                Instruction Manu                  \n\n\n";
        cout << "\t\t\t         |press 1 to users' information        |\n";
        cout << "\t\t\t         |press 2 to manage user               |\n";
        cout << "\t\t\t         |press 3 to Main menu                 |\n";
        cout << "\t\t\t         |press 4 to Exit                      |\n\n\n";


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
                userinfo();
                break;
            case 2:
                manageUser();
                break;

            case 3:
                cout << "\t\t\t            Thank you            \n\n";
                adminlogin();
                break;

            case 4:
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
            alogin();
        }
    }

    void alist()
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

    void Product_Management()
    {
       
        cin.get();
        cin.get();
        int choice;

        system("cls");

        cout << "\n\n\n\t\t\t__________________________________________________\n\n\n";
        cout << "\t\t\t                Welcome to Product management          \n\n\n";
        cout << "\t\t\t                Instruction Manu                  \n\n\n";
        cout << "\t\t\t         |press 1 to Add Product               |\n";
        cout << "\t\t\t         |press 2 to Edit the product          |\n";
        cout << "\t\t\t         |press 3 to Remove the product        |\n";
        cout << "\t\t\t         |press 4 to Display the product       |\n";
        cout << "\t\t\t         |press 5 to Main menu                 |\n";
        cout << "\t\t\t         |press 6 to Exit                      |\n\n\n";


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

        if (1 <= choice && choice <= 6) {
            switch (choice)
            {
            case 1:
                add_Product();
                break;
            case 2:
                Edit_Product();
                break;

            case 3:
                Remove_Product();
                break;

            case 4:
                cout << "\t\t\t            Thank you            \n\n";
                adminlogin();
                break;

            case 5:
                cout << "\t\t\t            Thank you            \n\n";
                break;

            case 6:
                alist();
                

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
            alogin();
        }

    }

    void add_Product()
    {
    m:
        fstream data; // Creates an object of fstream class
        int c;
        int token = 0;
        float p;
        float d;
        string n;

        cout << "\n\n\t\t\t  Add new product ";
        cout << "\n\n\t Product code of the product  ";
        cin >> pcode;
        cout << "\n\n\t Name of the product: ";
        cin >> pname;
        cout << "\n\n\t Price of the product: ";
        cin >> price;
        cout << "\n\n\t discount on the product: ";
        cin >> dis;

        data.open("database.txt"); // Open the database file in reading mode

        if (!data) { // If the database file doesn't exist
            data.open("database.txt", ios::app | ios::out); // Here we append and write the data
            data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            data.close();
        }
        else {
            data >> c >> n >> p >> d;


            while (!data.eof()) // Check until the end of the data
            {
                if (c == pcode)
                {
                    token++; // to mention the duplicity 
                }
                data >> c >> n >> p >> d;
            }
            data.close();


            if (token == 1)
                goto m; // Directed to add_Profuct
            else {
                data.open("database.txt", ios::app | ios::out);
                data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
                data.close();
            }
        }
        cout << "\n\n\t\t Record inserted !";
        Product_Management();

    }

    void Edit_Product()
    {
        fstream data, data1;
        int pkey;
        int token = 0;
        int c;
        float p;
        float d;
        string n;

        cout << "\n\n\t\t\t  Modify the record ";
        cout << "\n\n\t Product code ";
        cin >> pkey;
        cout << "\n\n\t Name of the product: ";
        cin >> pname;
        cout << "\n\n\t Price of the product: ";
        cin >> price;
        cout << "\n\n\t discount on the product: ";
        cin >> dis;

        data.open("database.txt", ios::in);

        if (!data)
        {
            cout << "\n\nFile doesn't exist! ";
        }
        else {
            data1.open("database1.txt", ios::app | ios::out);
            data >> pcode >> pname >> price >> dis;

            while (!data.eof())
            {
                if (pkey == pcode)
                {
                    cout << "\n\t\t Product new code : ";
                    cin >> c;
                    cout << "\n\t\t Name of the product : ";
                    cin >> n;
                    cout << "\n\t\t Price";
                    cin >> p;
                    cout << "\n\t\t Discount : ";
                    cin >> d;
                    data1 << " " << c << " " << n << " " << p << " " << d << "\n";
                    cout << "\n\n\t\t Record edited";
                    token++;
                }
                else
                {
                    data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n"; 
                    /* To write the modified or unmodified product information back to 
                    the temporary file(database1.txt) during the process of editing a product record.*/
                }
                data1 >> pcode >> pname >> price >> dis; // Reading the file
            }
            data.close();
            data1.close();

            remove("database.txt");
            rename("database1.txt","database.txt");


            if (token == 0)
            {
                cout << "\n\n Record not found sorry!";
            }
        }
        Product_Management();
    }

    void Remove_Product()
    {
        fstream data, data1;
        int pkey;
        int token = 0;

        cout << "\n\n\t\t\t Delete product ";
        cout << "\n\n\t Product code ";
        cin >> pkey;
        data.open("database.txt", ios::in);

        if (!data) // If the database file doesn't exist
        {
            cout << "\n\nFile doesn't exist! ";
        }
        else {
            data1.open("database1.txt", ios::app | ios::out);

            data >> pcode >> pname >> price >> dis;
            while (!data.eof())
            {
                if (pcode == pkey)
                {
                    cout << "\n\t\t Product deleted successfully ";
                    token++;
                }
                else
                {
                    // If the record is not being modified, it is copied unchanged to the temporary file.
                    data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
                }
                data >> pcode >> pname >> price >> dis; // Read the next set of product information from the original file
            }

            data.close();
            data1.close();

            remove("database.txt");
            rename("database1.txt","database.txt");

            if (token == 0)
            {
                cout << "\n\n Record not found ";
            }
        }
        Product_Management();
    }


    void aregisterUser() {
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
                aregisterUser();
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
                aregisterUser();
            }
        }

        ifstream input("admin.txt");

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
            aregisterUser();

            //This is a Windows-specific command, which tells the OS to run the pause
            // program. This program waits to be terminated, and halts the execution of the parent C++ program. 
        }
        else //if success then return 1 or proceed further
        {
            ofstream fi("admin.txt", ios::app);
            fi << username << ' ' << password << endl;


            cout << "\t\t\t           Registration is successful       \n\n\n";
            cin.get();
            cin.get();
            system("cls");

            adminlogin();
        }


    }

    void aforgotpw() {

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
                throw runtime_error("\t\t\t            Input is not an integer!\n\n");
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
                ifstream f2("admin.txt");
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
                    adminlogin();
                }


                else {
                    cout << "\t\t\t                  Sorry we cannot find your account\n";
                    cout << "\t\t\t     Please check whether you entered the username correctly \n\n\n";
                    cin.get();
                    cin.get();
                    system("cls");
                    adminlogin();
                }
                break;
            }
            case 2:
            {
                system("cls");
                adminlogin();
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
            aforgotpw();
            //system("cls");
        }
    }
};
