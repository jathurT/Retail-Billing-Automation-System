#include <iostream>
#include "Admin.h"
#include "user.h"
#include "Guest.h"
using namespace std;

int main()
{
    admin ad;
    User usr;
    Guest gh;
    

    int choice;

    cout << "\n\n\n\t\t\t     __________________________________________________\n\n\n";
    cout << "\t\t\t                          Welcome                    \n\n\n";
    cout << "\t\t\t    ------------>> Faculty of Engineering  <<------------ \n\n\n";
    cout << "\t\t\t           ---->>  University  of  Ruhuna   <<---- \n\n\n";
    cout << "\t\t\t          >> Retail Billing Automation System << \n\n\n";
    cout << "\t\t\t                     Instruction Manu                  \n\n\n";
    cout << "\t\t\t         |press 1 if you are a admin                  |\n";
    cout << "\t\t\t         |press 2 if you are a user                   |\n";
    cout << "\t\t\t         |press 3 if you are a Guest                  |\n";
    cout << "\t\t\t         |press 4 to Exit                             |\n\n\n";
    try {
        cout << "\t\t\t         please enter your choice : ";
        cin >> choice;
        cout << endl;

        if (cin.fail()) {  // cin.fail() checks if the value in the cin
            // stream is the correct type, if not it returns true,
            // otherwise it returns false.
            throw runtime_error("\n\n\n\t\t\t            Input is not an integer!       \n\n\n");
        }
    }

    catch (runtime_error& e) {
        cout << e.what() << endl;
        cin.clear();  // reset the error flag on cin (so that future I/O operations will work correctly)
        cin.ignore(1000, '\n');  // ignore last input
    }

    switch (choice)
    {
    case 1:
        ad.adminlogin();
        break;
    case 2:
        usr.userlogin();
        break;
    case 3:
        gh.buy_by_Guest();

    case 4:
        cout << "\t\t\t                  Thank you            \n\n";
        break;

    default:
        cout << "\n\n\n\t\t\t                Invalid Choice!        \n";
        cout << "\n\n\n\t\t\t                   Try again        \n\n\n";
        cin.get();
        system("cls");
        main();
        break;

    }
}