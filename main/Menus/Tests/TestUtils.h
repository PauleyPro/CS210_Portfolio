/* <<<<<<<<<<<<< TestUtils.h >>>>>>>>>>>>>
* Author: Jeremy R Pauley
* Purpose: Declares shared testing helpers for redirecting input,
* capturing output, and asserting expected test behavior.
<<<<<<<<<<<<<<<<<_>>>>>>>>>>>>>>>>> */

#ifndef TESTUTILS_H
#define TESTUTILS_H

/* ===========================
*      Include Statements
=========================== */
#include <functional>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

/* ===========================
*      Helper Classes
=========================== */

class ScopedInputRedirect {
public:
    /* ___________________ ScopedInputRedirect _________________________
    * @brief Redirects standard input to a string stream for test cases.
    *
    * @param input (Simulated input text for the test.)
    ________________________________________________________________ */
    explicit ScopedInputRedirect(const std::string& input)
        : inputStream(input), originalBuffer(std::cin.rdbuf(inputStream.rdbuf())) {}

    /* ___________________ ~ScopedInputRedirect _________________________
    * @brief Restores the original standard input buffer.
    ________________________________________________________________ */
    ~ScopedInputRedirect() {
        std::cin.rdbuf(originalBuffer);
    }

private:
    std::istringstream inputStream;
    std::streambuf* originalBuffer;
};

class ScopedOutputCapture {
public:
    /* ___________________ ScopedOutputCapture _________________________
    * @brief Redirects standard output to a string stream for test cases.
    ________________________________________________________________ */
    ScopedOutputCapture()
        : originalBuffer(std::cout.rdbuf(outputStream.rdbuf())) {}

    /* ___________________ ~ScopedOutputCapture _________________________
    * @brief Restores the original standard output buffer.
    ________________________________________________________________ */
    ~ScopedOutputCapture() {
        std::cout.rdbuf(originalBuffer);
    }

    /* ___________________ str _________________________
    * @brief Returns the captured standard output text.
    *
    * @return Returns the captured output text.
    ________________________________________________________________ */
    std::string str() const {
        return outputStream.str();
    }

private:
    std::ostringstream outputStream;
    std::streambuf* originalBuffer;
};

/* ===========================
*      Assertion Helpers
=========================== */

/* ___________________ Expect _________________________
* @brief Throws a test failure when a condition is false.
*
* @param condition (Test condition being evaluated.)
* @param message (Error message for a failed expectation.)
________________________________________________________________ */
inline void Expect(bool condition, const std::string& message) {
    if (!condition) {
        throw std::runtime_error(message);
    }
}

/* ___________________ ExpectContains _________________________
* @brief Checks whether one string contains another expected value.
*
* @param text (Full text being inspected.)
* @param expected (Required substring.)
________________________________________________________________ */
inline void ExpectContains(const std::string& text, const std::string& expected) {
    if (text.find(expected) == std::string::npos) {
        throw std::runtime_error("Expected output to contain: " + expected + "\nActual output:\n" + text);
    }
}

/* ___________________ RunTestSuite _________________________
* @brief Executes one test suite and reports pass or fail output.
*
* @param suiteName (Name of the test suite being run.)
* @param testBody (Test logic to execute.)
*
* @return Returns 0 for pass and 1 for fail.
________________________________________________________________ */
inline int RunTestSuite(const std::string& suiteName, const std::function<void()>& testBody) {
    try {
        testBody();
        std::cout << "[PASS] " << suiteName << '\n';
        return 0;
    }
    catch (const std::exception& error) {
        std::cerr << "[FAIL] " << suiteName << ": " << error.what() << '\n';
        return 1;
    }
}

#endif