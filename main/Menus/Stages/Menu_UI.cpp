/* <<<<<<<<<<<<< Menu_UI.cpp >>>>>>>>>>>>>
* @author Jeremy R Pauley
* @brief Contains the user interface display logic for the Corner Grocer menu system.
*
* @Project-Scoped
* DisplayMenu;
<<<<<<<<<<<<<<<<<_>>>>>>>>>>>>>>>>> */

/* ===========================
*      Include Statements
=========================== */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* ============================================================
*                    Include Header Files
============================================================ */
#include "../../Include/Menu_UI.h"
// ^^^^ DisplayMenu ^^^^^
#include "../../Include/Menu_Handling.h"
// ^^^^ printWithSpacing ^^^^^

/* ===========================
*      Function Definitions
=========================== */

// ___________________ DisplayMenu _________________________

void DisplayMenu() {
    vector<string> menuLines = {
        "========================================",
        "Corner Grocer Main Menu",
        "========================================",
        "1. Search for an item frequency",
        "2. Display all item frequencies",
        "3. Display histogram",
        "4. Exit",
        "========================================"
    };

    const size_t centerTitleIndex = (menuLines[0].size() - menuLines[1].size()) / 2;
    menuLines[1] = string(centerTitleIndex, ' ') + menuLines[1];

    string stringMenu;

    for (size_t i = 0; i < menuLines.size(); ++i) {
        stringMenu += menuLines[i];

        if (i != menuLines.size() - 1) {
            stringMenu += "\n";
        }
    }

    printWithSpacing(stringMenu);
}