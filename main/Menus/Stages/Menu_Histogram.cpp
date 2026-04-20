/* <<<<<<<<<<<<< Menu_Histogram.cpp >>>>>>>>>>>>>
* @author Jeremy R Pauley
* @brief Contains the menu option 3 logic for displaying grocery item frequencies as a text-based histogram.
*
* @Project-Scoped
* RunHistogramOption;
<<<<<<<<<<<<<<<<<_>>>>>>>>>>>>>>>>> */

/* ===========================
*      Include Statements
=========================== */
#include <iostream>

using namespace std;

/* ============================================================
*                    Include Header Files
============================================================ */
#include "../../Include/Menu_Histogram.h"
// ^^^^ RunHistogramOption ^^^^^
#include "../../Include/Menu_Handling.h"
// ^^^^ printWithSpacing ^^^^^

/* ===========================
*      Histogram Logic
=========================== */

// ___________________ RunHistogramOption _________________________

void RunHistogramOption(const GroceryTracker& groceryTracker) {
    printWithSpacing("Grocery Item Histogram", 0, 1);

    size_t histogramSpacing = 0;

    for (const auto& entry : groceryTracker.getFrequencies()) {
        const size_t currentSpacing = entry.first.length() + 1;
        if (currentSpacing > histogramSpacing) {
            histogramSpacing = currentSpacing;
        }
    }

    for (const auto& entry : groceryTracker.getFrequencies()) {
        const size_t printSpaces = histogramSpacing - entry.first.length();

        cout << entry.first;
        for (size_t index = 0; index < printSpaces; ++index) {
            cout << ' ';
        }
        for (int index = 0; index < entry.second; ++index) {
            cout << '*';
        }
        cout << '\n';
    }
}