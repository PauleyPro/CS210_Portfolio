/* <<<<<<<<<<<<< Menu_Listed.cpp >>>>>>>>>>>>>
* @author Jeremy R Pauley
* @brief Contains the menu option 2 logic for displaying
 all grocery item frequencies in a complete list.
*
* @Project-Scoped
* RunListOption;
<<<<<<<<<<<<<<<<<_>>>>>>>>>>>>>>>>> */

/* ===========================
*      Include Statements
=========================== */
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

/* ============================================================
*                    Include Header Files
============================================================ */
#include "../../Include/Menu_Listed.h"
// ^^^^ RunListOption ^^^^^
#include "../../Include/Menu_Handling.h"
// ^^^^ printWithSpacing ^^^^^


/* ===========================
*      Listing Logic
=========================== */

// ___________________ RunListOption _________________________

void RunListOption(const GroceryTracker& groceryTracker) {
    printWithSpacing("All Grocery Item Frequencies", 0, 1);

    for (const auto& entry : groceryTracker.getFrequencies()) {
        string formattedItemName = entry.first;
        bool capitalizeNextLetter = true;

        for (char& character : formattedItemName) {
            if (isspace(static_cast<unsigned char>(character))) {
                capitalizeNextLetter = true;
            }
            else if (capitalizeNextLetter) {
                character = static_cast<char>(toupper(static_cast<unsigned char>(character)));
                capitalizeNextLetter = false;
            }
        }

        string printValue = formattedItemName + " " + to_string(entry.second);
        printWithSpacing(printValue, 0, 0);
    }
    cout << endl;
}