/* <<<<<<<<<<<<< Menu_Exit.cpp >>>>>>>>>>>>>
* @author Jeremy R Pauley
* @brief Contains the menu option 4 logic for closing the Corner Grocer program cleanly when the user selects exit.
*
* @Project-Scoped
* RunExitOption;
<<<<<<<<<<<<<<<<<_>>>>>>>>>>>>>>>>> */

/* ===========================
*      Include Statements
=========================== */
#include <iostream>

using namespace std;

/* ============================================================
*                    Include Header Files
============================================================ */
#include "../../Include/Menu_Exit.h"
// ^^^^ RunExitOption ^^^^^
#include "../../Include/Menu_Handling.h"
// ^^^^ printWithSpacing ^^^^^

/* ===========================
*       Exit Logic
=========================== */

// ___________________ RunExitOption _________________________

bool RunExitOption() {
    printWithSpacing("Closing program. Goodbye.", 0, 1);
    return true;
}