/* <<<<<<<<<<<<< Menu_Exit_Test.cpp >>>>>>>>>>>>>
* Author: Jeremy R Pauley
* Purpose: Validates the exit menu behavior and confirms the closing
* message and exit signal are both produced.
<<<<<<<<<<<<<<<<<_>>>>>>>>>>>>>>>>> */

/* ===========================
*      Include Statements
=========================== */
#include <string>

/* ============================================================
*                    Include Header Files
============================================================ */
#include "TestUtils.h"
// ^^^^ RunTestSuite; ScopedOutputCapture; Expect; ExpectContains ^^^^^
#include "../../Include/Menu_Exit.h"
// ^^^^ RunExitOption ^^^^^

/* ===========================
*        Test Runner
=========================== */

/* ___________________ main _________________________
* @brief Runs automated validation for the exit option behavior.
*
* @return Returns the overall exit test suite result.
________________________________________________________________ */

int main() {
	return RunTestSuite("Menu Exit", []() {
		ScopedOutputCapture output;
		const bool shouldExit = RunExitOption();

		const std::string text = output.str();
		Expect(shouldExit, "RunExitOption should return true");
		ExpectContains(text, "Closing program. Goodbye.");
	});
}