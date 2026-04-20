/* <<<<<<<<<<<<< Menu_Search_Test.cpp >>>>>>>>>>>>>
* Author: Jeremy R Pauley
* Purpose: Validates the menu search workflow for successful searches
* and missing-item suggestion behavior.
<<<<<<<<<<<<<<<<<_>>>>>>>>>>>>>>>>> */

/* ===========================
*      Include Statements
=========================== */
#include <string>

/* ============================================================
*                    Include Header Files
*
* Note: Declared-use annotations are found below each #include.
============================================================ */
#include "TestUtils.h"
// ^^^^ RunTestSuite; Expect; ScopedInputRedirect; ScopedOutputCapture; ExpectContains ^^^^^
#include "../../Include/GroceryTracker.h"
// ^^^^ GroceryTracker ^^^^^
#include "../../Include/Menu_Search.h"
// ^^^^ RunSearchOption ^^^^^

/* ===========================
*        Test Runner
=========================== */

/* ___________________ main _________________________
* @brief Runs automated validation for search success and unmatched
* search edge cases.
*
* @return Returns the overall search test suite result.
________________________________________________________________ */

int main() {
	return RunTestSuite("Menu Search", []() {
		GroceryTracker groceryTracker;
		Expect(groceryTracker.loadFromFile("Data_Management/CS210_Project_Three_Input_File.txt"), "Failed to load CS210_Project_Three_Input_File.txt");

		{
			ScopedInputRedirect input("Peas\n");
			ScopedOutputCapture output;

			RunSearchOption(groceryTracker);

			const std::string text = output.str();
			ExpectContains(text, "Enter the grocery item you want to search for:");
			ExpectContains(text, "Item: Peas");
			ExpectContains(text, "Frequency: 8");
		}

		{
			ScopedInputRedirect input("dragonfruit\n");
			ScopedOutputCapture output;

			RunSearchOption(groceryTracker);

			const std::string text = output.str();
			ExpectContains(text, "dragonfruit is not found.");
			ExpectContains(text, "Closest Match Found: cauliflower");
		}

		{
			ScopedInputRedirect input("\n");
			ScopedOutputCapture output;

			RunSearchOption(groceryTracker);

			const std::string text = output.str();
			ExpectContains(text, "No items name was typed, Please run step 1 again and insert name to attempt proper look up.");
		}
	});
}