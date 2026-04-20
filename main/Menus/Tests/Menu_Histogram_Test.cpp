/* <<<<<<<<<<<<< Menu_Histogram_Test.cpp >>>>>>>>>>>>>
* Author: Jeremy R Pauley
* Purpose: Validates the histogram menu output for populated grocery
* data and the empty-tracker edge case.
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
#include "../../Include/Menu_Histogram.h"
// ^^^^ RunHistogramOption ^^^^^

/* ===========================
*        Test Runner
=========================== */

/* ___________________ main _________________________
* @brief Runs automated validation for histogram output and empty
* histogram edge-case behavior.
*
* @return Returns the overall histogram test suite result.
________________________________________________________________ */

int main() {
	return RunTestSuite("Menu Histogram", []() {
		GroceryTracker groceryTracker;
		Expect(groceryTracker.loadFromFile("Data_Management/CS210_Project_Three_Input_File.txt"), "Failed to load CS210_Project_Three_Input_File.txt");

		{
			ScopedOutputCapture output;
			RunHistogramOption(groceryTracker);

			const std::string text = output.str();
			ExpectContains(text, "Grocery Item Histogram");
			ExpectContains(text, "apples      ****");
			ExpectContains(text, "broccoli    *******");
			ExpectContains(text, "cranberries **********");
			ExpectContains(text, "peas        ********");
			ExpectContains(text, "zucchini    **********");
		}

		{
			GroceryTracker emptyTracker;
			ScopedOutputCapture output;

			RunHistogramOption(emptyTracker);

			const std::string text = output.str();
			ExpectContains(text, "Grocery Item Histogram");
			Expect(text.find("*") == std::string::npos, "Empty histogram should not print any bars");
		}
	});
}