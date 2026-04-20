# Menu UI Requirement

This stage supports the Corner Grocer scenario by presenting the program features in a clear menu so the user can search one item, print all frequencies, print the histogram, or exit the program.

## Scope Alignment

- Present the four required options in a readable numbered format.
- Support repeated use of the program by returning control to the menu after each completed option.
- Keep the interface organized so the program communicates clearly to the intended audience.

## Rubric Alignment

- Supports Menu Option One through Menu Option Four by making each required action available from the main program flow.
- Supports Clear Communication by keeping the program interaction organized and easy to follow.
- Supports Industry Standard Best Practices through separation of interface display from data-processing logic.

## Current Implementation

- `DisplayMenu()` prints the four required options.
- `main.cpp` calls the menu inside the program loop so the user can continue working until exit is selected.
- Menu choice validation is handled separately in `Menu_Handling.cpp` to keep responsibilities clear.

## Related Files

- `Menus/Stages/Menu_UI.cpp`
- `main.cpp`
- `Menus/Stages/Menu_Handling.cpp`