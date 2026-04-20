# Menu Listed Requirement

This requirement covers Menu Option Two from the project scope. The program must print every grocery item and the number of times that item appears in the input data.

## Scope Alignment

- Output a comprehensive list of all grocery item names.
- Pair each item with its numeric purchase frequency.
- Use the processed data created from the source grocery input file.

## Rubric Alignment

- Directly addresses `Menu Option Two: Overall Frequency`.
- Supports clear output formatting by pairing each item name with its count on screen.
- Supports maintainability by using shared tracker data rather than duplicating counting logic in the menu stage.

## Current Implementation

- `RunListOption()` loops through the frequency map returned by `GroceryTracker::getFrequencies()`.
- Each item is printed once with its matching numeric count.
- The output is generated from the processed grocery data loaded at program startup.

## Related Files

- `Menus/Stages/Menu_Listed.cpp`
- `Data_Management/GroceryTracker.cpp`
- `Include/Menu_Listed.h`