# Menu Search Requirement

This requirement covers Menu Option One from the project scope. The program must prompt the user for one item name and return the numeric frequency for that specific grocery item.

## Scope Alignment

- Prompt the user to input the item, or word, they want to search for.
- Process the grocery purchase data already loaded from the input file.
- Return the numeric frequency for the requested grocery item.

## Rubric Alignment

- Directly addresses `Menu Option One: Individual Frequency`.
- Supports the optional input validation challenge through unmatched-search handling.
- Supports Industry Standard Best Practices by separating user interaction from map-based data access.

## Current Implementation

- `RunSearchOption()` prompts the user for the grocery item name.
- `GroceryTracker::getItemCount()` returns the stored frequency for the requested item.
- `HandleUnmatchedSearch()` prints a not-found message when the item does not exist.
- The current project also includes a closest-match suggestion when the item is not found. This goes beyond the required baseline behavior.

## Related Files

- `Menus/Stages/Menu_Search.cpp`
- `Menus/Stages/Menu_Handling.cpp`
- `Data_Management/GroceryTracker.cpp`
- `Include/Menu_Search.h`