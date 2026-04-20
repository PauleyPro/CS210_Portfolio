# Project Three Pseudocode

## Purpose

This document outlines the pseudocode for the Corner Grocer grocery-tracking program. It breaks the program into numbered steps and explains the purpose of each section so the design is easy to follow before coding begins.

---

## 1. Start Program

```text
1. Start the program.
2. Create an object from the GroceryTracker class.
3. Load item data from the input file.
4. Create the backup frequency data file.
```

**Functionality Explanation**

This section initializes the program. The program begins by creating the main tracking object that will manage grocery item data. It then reads the original input file so item frequencies can be counted and stored. After the data is processed, the backup file is created automatically to satisfy the assignment requirement.

---

## 2. Load Input File Data

```text
1. Open the input file.
2. Check if the file opened successfully.
3. While there are still items to read from the file:
   a. Read one item name.
   b. Search for the item in the frequency collection.
   c. If the item already exists, increase its count by 1.
   d. If the item does not exist, add it with a count of 1.
4. Close the input file.
```

**Functionality Explanation**

This section handles reading the grocery purchase records. Each word in the file represents an item purchased during the day. The program counts how many times each item appears by storing the values in a frequency collection, such as a map. This creates the core data used by all menu options.

---

## 3. Create Backup Data File

```text
1. Open the output file named frequency.dat.
2. Check if the file opened successfully.
3. For each item in the frequency collection:
   a. Write the item name to the file.
   b. Write the frequency beside the item name.
4. Close the output file.
```

**Functionality Explanation**

This section creates the required backup file. The file stores every grocery item and its total frequency. It is generated automatically after the input data is processed so the user does not need to manually create it.

---

## 4. Display Main Menu

```text
1. Show the user the menu options:
   1. Search for one item frequency.
   2. Display all item frequencies.
   3. Display histogram.
   4. Exit the program.
2. Prompt the user to enter a menu choice.
3. Read the user’s input.
```

**Functionality Explanation**

This section provides the main menu interface. The user can choose which action to perform. The menu should be clearly formatted so the options are easy to understand and use.

---

## 5. Process Menu Choice

```text
1. If the user selects option 1:
   a. Run the individual frequency search.
2. Else if the user selects option 2:
   a. Print all item frequencies.
3. Else if the user selects option 3:
   a. Print the histogram.
4. Else if the user selects option 4:
   a. End the program loop.
5. Else:
   a. Display an error message for invalid input.
```

**Functionality Explanation**

This section controls the flow of the program. Based on the user’s menu selection, the program calls the matching function. Input validation is included so invalid menu choices can be handled cleanly without crashing the program.

---

## 6. Search for One Item Frequency

```text
1. Prompt the user to enter the name of the grocery item.
2. Read the item name.
3. Search the frequency collection for that item.
4. If the item exists:
   a. Display the item name.
   b. Display the number of times it was purchased.
5. Else:
   a. Display that the item was not found or has a frequency of 0.
```

**Functionality Explanation**

This section supports menu option one. It allows the user to search for a specific grocery item and see how many times it was purchased. This helps the store quickly check the popularity of one product without reviewing the full list.

---

## 7. Display All Item Frequencies

```text
1. Loop through all items in the frequency collection.
2. For each item:
   a. Print the item name.
   b. Print its frequency beside it.
```

**Functionality Explanation**

This section supports menu option two. It prints a complete list of all grocery items and their frequencies. This gives the store a full view of item popularity for the day.

---

## 8. Display Histogram

```text
1. Loop through all items in the frequency collection.
2. For each item:
   a. Print the item name.
   b. Print a symbol, such as an asterisk, repeated for the item’s frequency.
3. Move to the next line after each item.
```

**Functionality Explanation**

This section supports menu option three. It provides a visual representation of the same frequency data by using symbols instead of only numbers. This makes it easier to compare item popularity at a glance.

---

## 9. Repeat Menu Until Exit

```text
1. After completing the selected option, return to the main menu.
2. Continue showing the menu until the user selects option 4.
```

**Functionality Explanation**

This section keeps the program running so the user can perform multiple actions in one session. The program only ends when the user chooses the exit option.

---

## 10. End Program

```text
1. Display a closing message.
2. End the program.
```

**Functionality Explanation**

This final section closes the program in a clean and user-friendly way once the exit option is selected.

---

## Suggested Class Structure

```text
Class Name: GroceryTracker

Private Data:
- frequency collection storing item names and counts

Public Functions:
- load file data
- create backup file
- search item frequency
- print all frequencies
- print histogram
```

**Functionality Explanation**

This class design keeps the program organized by placing the grocery-processing logic inside one class. The data remains protected in the private section, while the public functions allow the main program to call the needed features through the menu.


