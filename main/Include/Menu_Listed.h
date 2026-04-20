/* <<<<<<<<<<<<< Menu_Listed.h >>>>>>>>>>>>>
* @author Jeremy R Pauley
* @brief Declares the menu option 2 function used to display all
 grocery item frequencies.
<<<<<<<<<<<<<<<<<_>>>>>>>>>>>>>>>>> */

#ifndef MENU_LISTED_H
#define MENU_LISTED_H

/* ============================================================
*                    Include Header Files
*
* Note: Declared-use annotations are found below each #include.
============================================================ */

#include "GroceryTracker.h"
// ^^^^ GroceryTracker ^^^^^

/* ===========================
*      Function Declarations
=========================== */

// ___________________ RunListOption _________________________
/* @brief Runs menu option 2 to print all grocery item frequencies.
*
* + Each item is printed with the first letter of each word capitalized
*
* + Followed by ' ' and its frequency count
*
* @param const GroceryTracker& groceryTracker (Tracker containing the grocery frequency data.)
*
* @note Location: Menus/Stages/Menu_Listed.cpp
*/
void RunListOption(const GroceryTracker& groceryTracker);

#endif