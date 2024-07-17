#pragma once
#include <iostream>
#include <fstream> //because here we are going to use file handling
#include <stdlib.h>
#include <string>
#include <list>
#include"Admin.h"
using namespace std;

class Guest
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:

    void buy_by_Guest()
    {

        int choice;

        system("cls");

        cout << "\n\n\n\t\t\t__________________________________________________\n\n\n";
        cout << "\t\t\t                Welcome to Guest Log in page         \n\n\n";
        cout << "\t\t\t                Instruction Manu                  \n\n\n";
        cout << "\t\t\t         |press 1 to Purchase Products      |\n";
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
                guest_receipt();
                break;
       
            case 2:
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
        }
        buy_by_Guest();
    }


    void Guest_list()
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

    void guest_receipt()
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
            Guest_list();
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
                        cout << "\n" << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t\t" << amount << "\t\t";

                    }
                    data >> pcode >> pname >> price;
                }

            }
            data.close();
        }
        cout << "\n\n|______________________________________________________\n";
        cout << "\n Total Amount : " << total;
    }

};