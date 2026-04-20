/* <<<<<<<<<<<<< main.cpp >>>>>>>>>>>>>
* Author: Jeremy R Pauley
* Purpose: Serves as the main entry point for Project Three.
*
* @Project-Scoped
* main; (int; starts program flow and routes each menu option)
<<<<<<<<<<<<<<<<<_>>>>>>>>>>>>>>>>> */

/* ===========================
*      Include Statements
=========================== */

#include <iostream>
#include <string>

/* ============================================================
*                    Include Header Files
*
* Note: Declared-use annotations are found below each #include.
============================================================ */
#include "Include/GroceryTracker.h"
// ^^^^ GroceryTracker; InitializeGroceryTracker ^^^^^
#include "Include/Menu_UI.h"
// ^^^^ DisplayMenu ^^^^^
#include "Include/Menu_Handling.h"
// ^^^^ GetValidatedMenuChoice ^^^^^
#include "Include/Menu_Search.h"
// ^^^^ RunSearchOption ^^^^^
#include "Include/Menu_Listed.h"
// ^^^^ RunListOption ^^^^^
#include "Include/Menu_Histogram.h"
// ^^^^ RunHistogramOption ^^^^^
#include "Include/Menu_Exit.h"
// ^^^^ RunExitOption ^^^^^

/* ===========================
*     Identifier Scope
=========================== */
using namespace std;

/* ===========================
*         Main Program
=========================== */

// ___________________ main _________________________
/* @brief Starts the program, initializes grocery purchase data,
* displays the main menu, and routes each menu option to its stage logic.
*
* @return: Returns 0 when the program exits successfully or 1 if initialization fails.
*/
int main() {
    const string inputFileName = "Data_Management/CS210_Project_Three_Input_File.txt";
    const string backupFileName = "Data_Management/frequency.dat";

    GroceryTracker groceryTracker;
    bool isProgramRunning = true;

    if (!InitializeGroceryTracker(groceryTracker, inputFileName, backupFileName)) {
        return 1;
    }

    while (isProgramRunning) {
        DisplayMenu();

        switch (GetValidatedMenuChoice()) {
            case 1:
                RunSearchOption(groceryTracker);
                break;

            case 2:
                RunListOption(groceryTracker);
                break;

            case 3:
                RunHistogramOption(groceryTracker);
                break;

            case 4:
                isProgramRunning = !RunExitOption();
                break;
        }
    }

    return 0;
}