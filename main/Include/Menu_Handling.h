/* <<<<<<<<<<<<< Menu_Handling.h >>>>>>>>>>>>>
* @author Jeremy R Pauley
* @brief Declares the menu input validation functions used for menu choice handling, unmatched search behavior, and shared print spacing.
<<<<<<<<<<<<<<<<<_>>>>>>>>>>>>>>>>> */

#ifndef MENU_HANDLING_H
#define MENU_HANDLING_H

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

// |||||||||||||||||| printWithSpacing ||||||||||||||||||
/* @brief Prints one text value followed by a configurable number of blank
 lines before or after the text. 
* 
* Function has default values added to numOfSpacesAppended and
 numOfSpacesPreceding as = 0.
*
*  Declared defaults live in the Menu_Handling.h File.
*
* @attention Additional Feature: printWithSpacing;
*
* @param const std::string& toPrint (Text value to print.)
* @param int numOfSpacesAppended (Number of blank lines to print after the text.)
* @param int numOfSpacesPreceding (Number of blank lines to print before the text.)
*
* @note Location: Menus/Stages/Menu_Handling.cpp
*/
void printWithSpacing(
	const std::string& toPrint,
	int numOfSpacesAppended = 0,
	int numOfSpacesPreceding = 0
);

// ___________________ GetValidatedMenuChoice _________________________
/* @brief Reads and validates the user's menu selection, only whole-number choices between 1 and 4 are accepted.
*
* + On successful validation, the function returns the user's menu choice as an integer. 
*
* - On failed validation, the function prompts the user to enter a valid choice until successful input is received.
*
* @return Returns a validated menu selection from 1 to 4.
*
* @note Location: Menus/Stages/Menu_Handling.cpp
*/
int GetValidatedMenuChoice();

// |||||||||||||||||| HandleUnmatchedSearch ||||||||||||||||||
/* @brief Checks whether a searched grocery item exists.
* 
* + On successful search, the function returns false and the search result is printed in the calling function.
*
* - On failed search, the function calls a helper to find the closest matching
 grocery item and prints to the user the search item with frequency 0, 
 then prints closest matching item found on the list.
*
* @attention Additional Feature: HandleUnmatchedSearch 
*
* @param const GroceryTracker& groceryTracker (Tracker containing all grocery items.)
* @param const std::string& searchItem (Item name entered by the user.)
*
* @return Returns true when the search item is missing.
*
* @note Location: Menus/Stages/Menu_Handling.cpp
*/
bool HandleUnmatchedSearch(const GroceryTracker& groceryTracker, const std::string& searchItem);

#endif