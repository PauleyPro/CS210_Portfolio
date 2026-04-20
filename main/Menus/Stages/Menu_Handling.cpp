/* <<<<<<<<<<<<< Menu_Handling.cpp >>>>>>>>>>>>>
* @author Jeremy R Pauley
* @brief Contains the menu input and validation logic for the Corner Grocer program.
*
* @Self-Scoped
* CountMatchingCharacters;
* FindClosestMatchingItem;
*
* @Project-Scoped
* printWithSpacing;
* GetValidatedMenuChoice;
* HandleUnmatchedSearch;
<<<<<<<<<<<<<<<<<_>>>>>>>>>>>>>>>>> */

/* ===========================
*      Include Statements
=========================== */
#include <algorithm>
#include <cctype>
#include <map>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

/* ============================================================
*                    Include Header Files
============================================================ */
#include "../../Include/Menu_Handling.h"
// ^^^^ printWithSpacing; GetValidatedMenuChoice; HandleUnmatchedSearch ^^^^^

/* ======================================================
*                  Self-Scoped Functions
====================================================== */

// |||||||||||||||||| CountMatchingCharacters |||||||||||||||||||||||
/* @brief Counts the overlapping characters between the user's search
 text and one tracked grocery item, the goal is to parse the users 
 input, find the closest match and feed it back to the parent function.
* 
* @attention Additional Feature:  CountMatchingCharacters
* 
* @param const string& searchItem (Item name entered by the user.)
* @param const string& candidateItem (Tracked grocery item being compared.)
*
* @return Returns the number of matching characters.
*/
int CountMatchingCharacters(const string& searchItem, const string& candidateItem) {
    map<char, int> searchCharacterCounts;
    map<char, int> candidateCharacterCounts;
    int matchingCharacterCount = 0;

    for (char character : searchItem) {
        if (!isspace(static_cast<unsigned char>(character))) {
            ++searchCharacterCounts[static_cast<char>(tolower(static_cast<unsigned char>(character)))];
        }
    }

    for (char character : candidateItem) {
        if (!isspace(static_cast<unsigned char>(character))) {
            ++candidateCharacterCounts[static_cast<char>(tolower(static_cast<unsigned char>(character)))];
        }
    }

    for (const auto& entry : searchCharacterCounts) {
        const auto candidateMatch = candidateCharacterCounts.find(entry.first);
        if (candidateMatch != candidateCharacterCounts.end()) {
            matchingCharacterCount += min(entry.second, candidateMatch->second);
        }
    }

    return matchingCharacterCount;
}

// |||||||||||||||||| FindClosestMatchingItem  |||||||||||||||||||||||
/* @brief Finds the grocery item with the highest character overlap
 between {Input} when menu option 1 does not find the user's search entry
 and {grocery list}. Match is determined by the highest count of shared 
 characters, ignoring spaces and case.
*
* @attention Additional Feature: FindClosestMatchingItem 
* 
* @param const GroceryTracker& groceryTracker (Tracker containing all grocery items.)
* @param const string& searchItem (Item name entered by the user.)
*
* @return Returns the closest matching grocery item name.
*/
string FindClosestMatchingItem(const GroceryTracker& groceryTracker, const string& searchItem) {
    string closestMatch;
    int highestMatchCount = -1;

    for (const auto& entry : groceryTracker.getFrequencies()) {
        const int currentMatchCount = CountMatchingCharacters(searchItem, entry.first);

        if (currentMatchCount > highestMatchCount) {
            highestMatchCount = currentMatchCount;
            closestMatch = entry.first;
        }
    }

    return closestMatch;
}

/* ======================================================
*                 Project-Scoped Functions
====================================================== */

// |||||||||||||||||| printWithSpacing ||||||||||||||||||

void printWithSpacing(const string& toPrint, int numOfSpacesAppended, int numOfSpacesPreceding) {
    for (int index = 0; index < numOfSpacesPreceding; ++index) {
        cout << endl;
    }

    cout << toPrint << endl;

    for (int index = 0; index < numOfSpacesAppended; ++index) {
        cout << endl;
    }
}

// ___________________ GetValidatedMenuChoice _________________________

int GetValidatedMenuChoice() {
    int menuChoice = 0;

    while (true) {
        cout << "Enter your choice (1-4): ";
        cin >> menuChoice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            string failedInput = "Invalid input. Please enter a whole number from 1 to 4.";
            printWithSpacing(failedInput, 1, 1);

            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (menuChoice >= 1 && menuChoice <= 4) {
            return menuChoice;
        }

        string invalidChoice = "Invalid choice. Please select a number from 1 to 4.";
        printWithSpacing(invalidChoice, 1, 1);
    }
}

// |||||||||||||||||| HandleUnmatchedSearch |||||||||||||||||||||||

bool HandleUnmatchedSearch(const GroceryTracker& groceryTracker, const string& searchItem) {
    if (groceryTracker.getItemCount(searchItem) > 0) {
        return false;
    }

    string output = "Item: " + searchItem + "\nFrequency: 0" + "\nThis item is not found in the current list.";
    printWithSpacing(output, 0, 1);

    const string closestMatch = FindClosestMatchingItem(groceryTracker, searchItem);
    if (!closestMatch.empty()) {
        string output = "Closest Match Found: " + closestMatch;
        printWithSpacing(output, 1, 1);
    }

    return true;
}
