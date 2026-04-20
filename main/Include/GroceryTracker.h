/* <<<<<<<<<<<<< GroceryTracker.h >>>>>>>>>>>>>
* @author Jeremy R Pauley
* @brief Declares the GroceryTracker class interface used for grocery 
data loading, one-item lookup, backup creation, and menu-stage support.
<<<<<<<<<<<<<<<<<_>>>>>>>>>>>>>>>>> */

#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

/* ===========================
*      Include Statements
=========================== */
#include <string>
#include <map>

/* ======================================================
*                   Class Declaration
====================================================== */

// ___________________ GroceryTracker _________________________
/* @brief Stores grocery item frequencies and provides 
* file loading, lookup, and backup support for the 
* Corner Grocer program.
*
* Public:
* loadFromFile; writeBackup; getItemCount; getFrequencies;
*
* Private:
* freq; normalize;
*
* @note Location: Data_Management/GroceryTracker.cpp
*/
class GroceryTracker {
public:
    // ___________________ GroceryTracker _________________________
    /* @brief Creates a GroceryTracker object with an empty frequency map.
    *
    * @note Location: Data_Management/GroceryTracker.cpp
    */
    GroceryTracker();

    // ___________________ loadFromFile _________________________
    /* @brief Reads grocery purchase items from an input file and stores
    * normalized item frequencies in the tracker map.
    *
    * @param const std::string& path (Path to the grocery input file.)
    *
    * @return Returns true when the file loads successfully.
    *
    * @note Location: Menus/Stages/GroceryTracker.cpp
    */
    bool loadFromFile(const std::string& path);

    // ___________________ writeBackup _________________________
    /* @brief Writes the current grocery item frequencies to frequency.dat.
    *
    * @param const std::string& path (Path to the backup output file.)
    *
    * @note Location: Menus/Stages/GroceryTracker.cpp
    */
    void writeBackup(const std::string& path = "Data_Management/frequency.dat") const;

    // ___________________ getItemCount _________________________
    /* @brief Searches the frequency map for one grocery item entered
    * by the user.
    *
    * @param const std::string& item (Grocery item name entered by the user.)
    *
    * @return Returns the item frequency if found, otherwise 0.
    *
    * @note Location: Menus/Stages/GroceryTracker.cpp
    */
    int getItemCount(const std::string& item) const;

    // ___________________ getFrequencies _________________________
    /* @brief Provides read-only access to all tracked grocery item
    * frequencies for menu output stages.
    *
    * @return Returns the grocery frequency map.
    *
    * @note Location: Menus/Stages/GroceryTracker.cpp
    */
    const std::map<std::string, int>& getFrequencies() const;

private:

    /* ===========================
    *       Private Members
    =========================== */

    std::map<std::string,int> freq;

    // ___________________ normalize _________________________
    /* @brief Converts a grocery item name into a normalized form for
    * consistent storage and lookup.
    *
    * @param const std::string& s (Original item name.)
    *
    * @return Returns the normalized item name.
    *
    * @note Location: Menus/Stages/GroceryTracker.cpp
    */
    static std::string normalize(const std::string& s);
};

/* ===========================
*      Helper Functions
=========================== */

// ___________________ InitializeGroceryTracker _________________________
/* @brief Loads grocery purchase data, creates the backup frequency
* file, and displays the startup message before the menu loop begins.
*
* @param GroceryTracker& groceryTracker (Tracker object that stores grocery frequency data.)
* @param const std::string& inputFileName (Path to the grocery input file.)
* @param const std::string& backupFileName (Path to the backup output file.)
*
* @return Returns true when initialization finishes successfully.
*
* @note Location: Menus/Stages/GroceryTracker.cpp
*/
bool InitializeGroceryTracker(
    GroceryTracker& groceryTracker,
    const std::string& inputFileName,
    const std::string& backupFileName
);

#endif
