/* <<<<<<<<<<<<< Menu_Search.cpp >>>>>>>>>>>>>
* @author Jeremy R Pauley
* @brief Contains the menu option 1 logic for searching for one grocery item frequency and displaying the result.
*
* @Self-Scoped
* GetSearchItemFromUser;
*
* @Project-Scoped
* RunSearchOption;
<<<<<<<<<<<<<<<<<_>>>>>>>>>>>>>>>>> */

/* ===========================
*      Include Statements
=========================== */
#include <iostream>
#include <string>

using namespace std;

/* ============================================================
*                    Include Header Files
============================================================ */
#include "../../Include/Menu_Search.h"
// ^^^^ RunSearchOption ^^^^^
#include "../../Include/Menu_Handling.h"
// ^^^^ printWithSpacing; HandleUnmatchedSearch ^^^^^

/* ======================================================
*                  Self-Scoped Functions
====================================================== */

// ___________________ GetSearchItemFromUser _________________________
/* @brief Prompts the user to enter the grocery item for menu option 1.
*
* @return Returns the grocery item name entered by the user.
________________________________________________________________ */
string GetSearchItemFromUser() {
    string itemName;

    cout << "Enter the grocery item you want to search for: ";
    getline(cin, itemName);

    return itemName;
}


/* ======================================================
*                 Project-Scoped Functions
====================================================== */

// ___________________ RunSearchOption _________________________

void RunSearchOption(const GroceryTracker& groceryTracker) {
    const string searchItem = GetSearchItemFromUser();

    if (searchItem.find_first_not_of(" \t\n\r\f\v") == string::npos) {
        printWithSpacing("No items name was typed, Please run step 1 again and insert name to attempt proper look up.", 1, 1);
        return;
    }

    if (HandleUnmatchedSearch(groceryTracker, searchItem)) {
        return;
    }

    const int itemFrequency = groceryTracker.getItemCount(searchItem);

    printWithSpacing("Item: " + searchItem, 0, 1);
    cout << "Frequency: " << itemFrequency << endl;
}