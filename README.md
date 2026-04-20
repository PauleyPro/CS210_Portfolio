# Corner Grocer Item Tracking Program

## Overview

The Corner Grocer Item Tracking Program is a modular C++ application designed to analyze retail transaction logs and convert raw purchase data into meaningful insights. The program reads a daily input file, calculates item frequencies, and presents results through a structured menu interface.

This solution eliminates manual data review and enables store managers to make informed, data driven decisions about product placement and demand trends.

<br>

## Features

* Item search that returns the frequency of a specific grocery item
* Frequency list displaying all items with purchase counts
* Histogram visualization using text based output
* Automatic backup file generation (frequency.dat)
* Input validation to handle invalid and empty user input
* Fuzzy matching suggestions for misspelled items

<br>

## Technologies Used

* C++ (C++17)
* STL (std::map) for efficient data storage and sorting
* File input and output for reading and writing data
* Modular architecture with multiple source and header files

<br>

## Key Design Highlights

* Separation of concerns between data management, user interface, and program control
* Object oriented design using a dedicated GroceryTracker class
* Clean and maintainable code with consistent naming conventions
* Doxygen style documentation for readability and scalability
* Incremental development and testing for reliability

<br>

## How to Run

Compile using:

```bash
g++ -std=c++17 -Wall -Wextra -o grocery_tracker_app \
main.cpp \
Data_Management/GroceryTracker.cpp \
Menus/Stages/Menu_UI.cpp \
Menus/Stages/Menu_Handling.cpp \
Menus/Stages/Menu_Search.cpp \
Menus/Stages/Menu_Listed.cpp \
Menus/Stages/Menu_Histogram.cpp \
Menus/Stages/Menu_Exit.cpp
```

Run:

```bash
./grocery_tracker_app
```

<br>

## Reflection

This project strengthened my ability to design structured and maintainable C++ applications while applying real world problem solving strategies. I focused on modular design, input validation, and clear documentation to ensure the program is scalable and easy to understand.

Challenges such as histogram alignment and safe character handling were resolved through iterative testing and research, reinforcing strong debugging and development practices.

<br>

## Full Documentation

For a full breakdown please review:
See [Technical Design Document](main/CS210_Documentation.docx)

<br>

## Author

Jeremy R. Pauley
Southern New Hampshire University
CS 210 Programming Languages
