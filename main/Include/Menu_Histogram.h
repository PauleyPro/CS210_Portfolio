/* <<<<<<<<<<<<< Menu_Histogram.h >>>>>>>>>>>>>
* @author Jeremy R Pauley
* @brief Declares the menu option 3 function used to display the grocery frequency histogram.
<<<<<<<<<<<<<<<<<_>>>>>>>>>>>>>>>>> */

#ifndef MENU_HISTOGRAM_H
#define MENU_HISTOGRAM_H

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

// ___________________ RunHistogramOption _________________________
/* @brief Runs menu option 3 to print the grocery histogram
*
* + Detemines the largest item name length for listed items
*
* + Prints each grocery item with aligned spacing followed
 by one asterisk per counted purchase.
*
* @param const GroceryTracker& groceryTracker (Tracker containing the grocery frequency data.)
*
* @note Location: Menus/Stages/Menu_Histogram.cpp
*/
void RunHistogramOption(const GroceryTracker& groceryTracker);

#endif