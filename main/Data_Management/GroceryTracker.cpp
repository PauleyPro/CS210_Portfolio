/* <<<<<<<<<<<<< GroceryTracker.cpp >>>>>>>>>>>>>
* @author: Jeremy R Pauley
* @brief Implements grocery tracking logic for reading purchase data,
* counting item frequencies, writing the backup file, and supporting menu output.
*
* @Self-Scoped
* to_lower_copy;
*
* @Project-Scoped
* GroceryTracker;
* InitializeGroceryTracker;
<<<<<<<<<<<<<<<<<_>>>>>>>>>>>>>>>>> */

/* ===========================
*      Include Statements
=========================== */
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>

/* ============================================================
*                    Include Header Files
*
* Note: Declared-use annotations are found below each #include.
============================================================ */
#include "../Include/GroceryTracker.h"
// ^^^^ GroceryTracker; InitializeGroceryTracker ^^^^^

/* ===========================
*      Local Helper Logic
=========================== */

// ___________________ GroceryTracker _________________________

GroceryTracker::GroceryTracker() = default;

// ___________________ to_lower_copy _________________________
/* @brief Creates a lowercase copy of the provided string.
*
* @param const std::string& s (Original text to convert.)
*
* @return Returns the lowercase version of the input string.
________________________________________________________________ */
static std::string to_lower_copy(const std::string& s) {
    std::string out = s;
    std::transform(out.begin(), out.end(), out.begin(), [](unsigned char c){ return std::tolower(c); });
    return out;
}

/* ===========================
*      Data Processing Logic
=========================== */

// ___________________ normalize _________________________

std::string GroceryTracker::normalize(const std::string& s) {
    return to_lower_copy(s);
}

// ___________________ loadFromFile _________________________

bool GroceryTracker::loadFromFile(const std::string& path) {
    std::ifstream in(path);
    if (!in) return false;
    std::string token;
    while (in >> token) {
        std::string key = normalize(token);
        ++freq[key];
    }
    return true;
}

/* ===========================
*      Output Functions
=========================== */

// ___________________ writeBackup _________________________

void GroceryTracker::writeBackup(const std::string& path) const {
    std::ofstream out(path);
    if (!out) {
        std::cerr << "Failed to write backup file: " << path << "\n";
        return;
    }
    for (const auto& p : freq) {
        out << p.first << ' ' << p.second << '\n';
    }
}

// ___________________ getItemCount _________________________

int GroceryTracker::getItemCount(const std::string& item) const {
    std::string key = normalize(item);
    auto it = freq.find(key);
    return it == freq.end() ? 0 : it->second;
}

// ___________________ getFrequencies _________________________

const std::map<std::string, int>& GroceryTracker::getFrequencies() const {
    return freq;
}

// ___________________ InitializeGroceryTracker _________________________

bool InitializeGroceryTracker(
    GroceryTracker& groceryTracker,
    const std::string& inputFileName,
    const std::string& backupFileName
) {
    if (!groceryTracker.loadFromFile(inputFileName)) {
        std::cerr << "Failed to open input file: " << inputFileName << std::endl;
        return false;
    }

    groceryTracker.writeBackup(backupFileName);
    std::cout << "Welcome to the Corner Grocer Item Tracking Program." << std::endl;
    return true;
}
