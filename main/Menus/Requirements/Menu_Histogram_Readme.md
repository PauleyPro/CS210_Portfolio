# Menu Histogram Requirement

This requirement covers Menu Option Three from the project scope. The program must display the same grocery frequency data in a text-based histogram using asterisks or another special character.

## Scope Alignment

- Print each grocery item name.
- Print one asterisk per counted purchase for that item.
- Use the same processed frequency data that supports the full list output.

## Rubric Alignment

- Directly addresses `Menu Option Three: Histogram`.
- Supports output clarity by presenting the numeric frequency information in graphical text form.
- Supports best practices by keeping histogram rendering separate from data-loading logic.

## Current Implementation

- `RunHistogramOption()` loops through `GroceryTracker::getFrequencies()`.
- Each item is printed with a star bar whose length matches the stored frequency.
- The current implementation also aligns the histogram output based on the longest item name so the visual layout is easier to read. This is an additional presentation improvement beyond the minimum requirement.

## Related Files

- `Menus/Stages/Menu_Histogram.cpp`
- `Data_Management/GroceryTracker.cpp`
- `Include/Menu_Histogram.h`