/* <<<<<<<<<<<<< Menu_Search.h >>>>>>>>>>>>>
* @author Jeremy R Pauley
* @brief Declares the menu option 1 function used to search for one grocery item frequency.
<<<<<<<<<<<<<<<<<_>>>>>>>>>>>>>>>>> */

#ifndef MENU_SEARCH_H
#define MENU_SEARCH_H

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

// ___________________ RunSearchOption _________________________
/* @brief Runs menu option 1 for one from user input.
*
* Grocery item frequency search, Checking for unmatched input.
*
* + On Success: Printing the item frequency result
*
* - On Failure: Printing the item frequency as 0, Then suggesting the closest matching item found in the list.
*
* @param const GroceryTracker& groceryTracker (Tracker containing the grocery frequency data.)
*
* @note Location: Menus/Stages/Menu_Search.cpp
*/
void RunSearchOption(const GroceryTracker& groceryTracker);

#endif