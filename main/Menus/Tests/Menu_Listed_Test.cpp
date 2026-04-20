/* <<<<<<<<<<<<< Menu_Listed_Test.cpp >>>>>>>>>>>>>
* Author: Jeremy R Pauley
* Purpose: Validates the full grocery frequency list output and checks
* expected item counts loaded from the grocery data file.
<<<<<<<<<<<<<<<<<_>>>>>>>>>>>>>>>>> */

/* ===========================
*      Include Statements
=========================== */
#include <string>

/* ============================================================
*                    Include Header Files
============================================================ */
#include "TestUtils.h"
// ^^^^ RunTestSuite; Expect; ScopedOutputCapture; ExpectContains ^^^^^
#include "../../Include/GroceryTracker.h"
// ^^^^ GroceryTracker ^^^^^
#include "../../Include/Menu_Listed.h"
// ^^^^ RunListOption ^^^^^

/* ===========================
*        Test Runner
=========================== */

/* ___________________ main _________________________
* @brief Runs automated validation for the full grocery frequency list.
*
* @return Returns the overall listed-output test suite result.
________________________________________________________________ */

int main() {
	return RunTestSuite("Menu Listed", []() {
		GroceryTracker groceryTracker;
		Expect(groceryTracker.loadFromFile("Data_Management/CS210_Project_Three_Input_File.txt"), "Failed to load CS210_Project_Three_Input_File.txt");
		Expect(groceryTracker.getFrequencies().size() == 20, "Expected 20 unique grocery items");

		ScopedOutputCapture output;
		RunListOption(groceryTracker);

		const std::string text = output.str();
		ExpectContains(text, "All Grocery Item Frequencies");
		ExpectContains(text, "Apples 4");
		ExpectContains(text, "Broccoli 7");
		ExpectContains(text, "Cranberries 10");
		ExpectContains(text, "Cucumbers 9");
		ExpectContains(text, "Peas 8");
		ExpectContains(text, "Zucchini 10");
	});
}