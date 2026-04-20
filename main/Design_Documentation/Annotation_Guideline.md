# Annotation Guideline

## Purpose

This document defines the annotation standard for Project Three. The goal is clean and consistent annotation across the whole project without forcing every file or function to use the same amount of detail.

This project uses a hybrid Doxygen-style annotation format. Since VS Code was explicitly identified as the IDE for this project, this approach gives the best balance of readability, hover support, and clean source files. Full function documentation lives in the matching header file when one exists, so hovering over a function name in code displays its description without bloating the implementation file.

In practice, the project uses:

* Doxygen tags such as `@brief`, `@param`, `@return`, `@note`, `@attention`, and `@remark` inside header-file function comments
* visual divider lines as separate `//` comments above function annotations and definitions
* concise `.cpp` file annotations focused on file purpose, scope lists, and section organization rather than repeating the full header documentation

The core rule is simple:

* start with the smallest useful annotation
* add the next step only when it improves readability, navigation, or grading clarity
* omit any step that would only add noise

<br>

---
## General Rules

Use these rules across every annotation type:

* Prefer the shortest annotation that still explains the code clearly.
* If a section would only say `None`, leave it out.
* Blank `*` spacer lines should appear only between sections that are actually present.
* If an annotation contains a list, place each item on its own line and end each item with `;`.
* Keep wording direct, specific, and tied to actual code behavior.
* When a source file has a matching `.h` file, place the full function annotation in the header file and avoid duplicating it in the `.cpp` file.
* Keep the decorative function-name banner as a separate `//` comment so it does not appear in the VS Code hover preview.
* Use Doxygen tags only where they add value. In this project, `@brief` is the default summary tag, while `@param`, `@return`, `@note`, `@attention`, and `@remark` are optional support tags.
* Use `@note Location:` only when it meaningfully helps you find a definition that is not already obvious from the local file context. Use repo-relative paths with no leading slash.
* Do not force one large annotation format onto every file or function.

<br>

---
## 1. File Header Annotation

Use file headers to identify what the file is for and, when needed, what it runs inside its own scope and what it runs for the rest of the project.

<br>

### Step 1. Minimal File Header

Use this for `.h` files only. Keep the header short and use `@author` plus `@brief` for the main description.

```cpp
/* <<<<<<<<<<<<< File Name >>>>>>>>>>>>>
* @author
* @brief Purpose:
<<<<<<<<<<<<<<<<<_>>>>>>>>>>>>>>>>> */
```

<br>

### Step 2. Add Clarifying Detail

Use this for `.cpp` files whenever the file has meaningful exports and/or internal helpers to document.

<br>

If a `.cpp` file has `@Self-Scoped`, `@Project-Scoped`, or both, use the detailed list form here. If one section does not apply, leave it out.
* `@Self-Scoped` should list internal helpers defined and used within the file.
* `@Project-Scoped` should list functions or declarations that matter to the rest of the project.
* Keep the file header summary itself under `@brief`, and use the scope lists only for quick navigation.

<br>

```cpp
/* <<<<<<<<<<<<< File Name >>>>>>>>>>>>>
* @author
* @brief Purpose:
*
* @Self-Scoped
* CountMatchingCharacters; 
* FindClosestMatchingItem; 
*
* @Project-Scoped
* GroceryTracker;
*/
```

<br>

Rules:
* `.h` files use Step 1 only.
* `.cpp` files use Step 2 when file contains meaningful functions or declarations.
* If a `.cpp` file has `@Project-Scoped` but no `@Self-Scoped`, include only `@Project-Scoped`.
* If a `.cpp` file has `@Self-Scoped` but no `@Project-Scoped`, include only `@Self-Scoped`.
* If neither section adds value, do not force them in, instead revert to Step 1.

<br>

---
## 2. Section Header Annotation

Use section dividers to separate major logic areas inside a file.

<br>

### Step 1. Minimal Section Divider

Use this for the normal case.

```cpp
/* ======================================================
*                      Section Title
====================================================== */
```

Examples:

```cpp
/* ======================================================
*                   Include Statements
====================================================== */
```
```cpp
/* ======================================================
*                   Identifier Scope
====================================================== */
```
```cpp
/* ======================================================
*                   Class Declaration
====================================================== */
```
<br>

### Step 2. Detailed Headers

Use this when a section title needs one short supporting note. Put the extra explanation under `@note` to avoid inline clutter.

```cpp
/* ============================================================
*                    Include Header Files
*
* @note Declared-use annotations are found below each #Include. 
============================================================ */
```

<br>

## 3. Header File Annotation

Use this for project header includes when you want to show exactly which imported declarations are being used in the current file.

Inline Annotation Example:
```cpp
#include "../../Include/Menu_Handling.h"
// ^^^^ printWithSpacing; HandleUnmatchedSearch ^^^^^
```

Rules:

* Use this only below project headers, not standard library includes.
* List only the declarations from that header that are actually used in the current file.
* Keep the list in the order the declarations are first used in the file.
* Use `;` as a delimiter if multiple declarations exist.
* This helper line is a visual reference only and is not part of the Doxygen hover content.

<br>

---
## 4. Function Annotation

Use function annotations while trying to keep to the minimal requirements for clarity. If the file has a matching header, the full function annotation should live in the `.h` file so that hover text remains available in VS Code without bloating the `.cpp` implementation. In the `.cpp` file, the function definition usually keeps only the decorative divider line unless a local note adds real value.

<br>

### Step 1. Minimal Annotation

Use when the function name is already clear and the behavior is simple. In this format, the summary is written with `@brief`. For files with a header, place this annotation above the declaration in the header file.

Keep the decorative function-name line as a separate `//` comment above the Doxygen block. This keeps the visual divider out of the hover preview while still preserving the section label in the source file.
```cpp
// ___________________ NormalizeItemName _________________________
/* @brief Normalizes a grocery item name for consistent comparison.
*
* @note Location: Menus/Stages/GroceryTracker.cpp
*/
```

<br>

### Step 2. Add `@param` and `@return` When Useful

Use this when inputs or returned values need explanation. Write one `@param` entry for each parameter, keep the main behavior summary under `@brief`, and place the full block in the header file whenever one exists.

You may also add short plain-text lines between tags when they help explain what the function does on success and on failure.

In this project, use:
* `+` for what happens on success
* `-` for what happens on failure

```cpp
// ___________________ GetValidatedMenuChoice _________________________
/* @brief Reads and validates the user's menu selection, only whole-number choices between 1 and 4 are accepted.
*
* + On successful validation, the function returns the user's menu choice as an integer.
*
* - On failed validation, the function prompts the user again until successful input is received.
*
* @return Returns a validated menu selection from 1 to 4.
*
* @note Location: Menus/Stages/Menu_Handling.cpp
*/
```

Parameter-heavy functions may also include a short lead-in note before the `@param` lines when that improves readability.
```cpp
// |||||||||||||||||| printWithSpacing ||||||||||||||||||
/* @brief Prints one text value followed by a configurable number of blank lines before or after the text.
*
* @attention Additional Feature: printWithSpacing;
*
* @remark String to print, blank lines following string, blank lines preceding string.
* @param const std::string& toPrint (Text value to print.)
* @param int numOfSpacesAppended (Number of blank lines to print after the text.)
* @param int numOfSpacesPreceding (Number of blank lines to print before the text.)
*
* @note Location: Menus/Stages/Menu_Handling.cpp
*/
```
<br>

### Step 3. Add `@note Location:` and Optional Feature Tags When Useful

For `@Self-Scoped` functions, the location note will usually be omitted unless it meaningfully improves navigation.

Only use it if the definition is far from the call site or the hover and navigation benefit clearly outweighs the extra comment noise.

If the function is intentionally outside the core assignment scope, you may also add `@attention Additional Feature:` to label that choice.

```cpp
// |||||||||||||||||| HandleUnmatchedSearch ||||||||||||||||||
/* @brief Checks whether a searched grocery item exists.
*
* + On successful search, the function returns false and the search result is printed in the calling function.
*
* - On failed search, the function prints the missing item details and closest match guidance.
*
* @attention Additional Feature: HandleUnmatchedSearch;
*
* @param const GroceryTracker& groceryTracker (Tracker containing all grocery items.)
* @param const std::string& searchItem (Item name entered by the user.)
*
* @return Returns true when the search item is missing.
*
* @note Location: Menus/Stages/Menu_Handling.cpp
*/
```

<br>

---
## 5. Class Object Annotation

Use this for class declarations and object-purpose notes when a class is central to the project design.

Class annotation normally belongs in the header file above the class declaration. Do not repeat large class descriptions in the implementation file. For this project, the class block should follow this order:

* `@brief` to define the class purpose
* `Public` to list the key public-facing items or responsibilities
* `Private` to list the important internal data or helpers
* `@note Location:` to show where the implementation lives

For local object instances inside a function, add a short inline note only when the object's role is not already obvious from the code.

<br>

### Step 1. Minimal Class Annotation

Use this when the class name already communicates most of the meaning and only one clear summary sentence is needed. Even in the minimal form, keep the order as brief, public, private, then location.

```cpp
// ___________________ GroceryTracker _________________________
/* @brief Stores grocery item frequencies and provides file loading, lookup, and backup support for the Corner Grocer program.
*
* Public:
* loadFromFile; writeBackup; getItemCount; getFrequencies;
*
* Private:
* freq; normalize;
*
* @note Location: Data_Management/GroceryTracker.cpp
*/
```
<br>

### Step 2. Constructor and Member Guidance

After the class-level summary, annotate constructors and public member functions using the normal function annotation rules from the previous section.

Under `Public:`, list the main public methods, constructors, or responsibilities that matter to the rest of the project. Under `Private:`, list the important internal data members or helpers. If the class has private data members, keep them grouped under a private-members section header in the code. Only add member-specific annotation when the member purpose is not already obvious.

```cpp
class GroceryTracker {
public:
    // ___________________ GroceryTracker _________________________
    /* @brief Creates a GroceryTracker object with an empty frequency map.
    *
    * @note Location: Data_Management/GroceryTracker.cpp
    */
    GroceryTracker();

private:
    /* ===========================
    *       Private Members
    =========================== */

    std::map<std::string, int> freq;
};
```

<br>

### Step 3. Local Object Instances

Do not force a full annotation block onto every object instance created inside a function. Most local objects are already clear from their type and variable name.

If extra clarity is needed, use a short inline note instead of a full Doxygen block.

```cpp
GroceryTracker groceryTracker; // Stores the active grocery frequency data for the program session.
```

Rules:

* Put the full class summary in the header file where the class is declared.
* Keep the class annotation order as `@brief`, `Public`, `Private`, then `@note Location:`.
* Use `@brief` to define what the class is responsible for in the project.
* Under `Public`, list the methods or responsibilities the rest of the project uses.
* Under `Private`, list the internal members or helpers only as needed for clarity.
* Reuse the normal function annotation format for constructors and public methods.
* Keep object-instance comments short and only add them when the purpose is not obvious.
* Do not annotate every private field unless doing so adds real clarity.

<br>

---

## 6. Outside of Scope Annotation

Use this only when you intentionally add a feature that goes beyond the current assignment or rubric requirements.

<br>

### Step 1. Outside-of-Scope Block

```cpp
// |||||||||||||||||| Outside of Project Scope |||||||||||||||||||||||
// |||||||||||||||||| HandleUnmatchedSearch ||||||||||||||||||
/* @brief Checks whether a searched grocery item exists and prints unmatched-search guidance when it does not.
*
* @attention Additional Feature: HandleUnmatchedSearch;
*
* @param const GroceryTracker& groceryTracker (Tracker containing all grocery items.)
* @param const std::string& searchItem (Item name entered by the user.)
*
* @return Returns true when the search item is missing.
*
* @note Location: Menus/Stages/Menu_Handling.cpp
*/
```

Rules:

* Use it only for genuinely extra features.
* Keep the outside-of-scope banner as a plain visual divider near the code it applies to.
* Use `@attention Additional Feature:` inside the function annotation when you want the hover text to call out the extra feature directly.
* Add `@param` and `@return` only when they improve clarity.
* Do not use it for required assignment behavior.

<br>

---
## 7. Final Standard Rules

This guide is decision-based, not template-based.

That means:

* not every annotation type uses all four steps
* not every function should have the same amount of detail
* consistency comes from applying the same decision rules everywhere, not from making every comment block identical

To keep annotations clean and consistent across the project:

* always start with Step 1 for the annotation type you are using
* use `@brief` as the default summary tag for function behavior
* place full function annotation in the header file whenever a matching `.h` file exists
* keep the function-name banner as a separate `//` line above the Doxygen block
* add `@param` and `@return` only when more explanation is actually needed
* use `+` lines to describe success behavior and `-` lines to describe failure behavior when that distinction adds value
* use `@attention` for genuine additional features, `@remark` for short explanatory context, and `@note Location:` for helpful navigation
* place class summaries in the header file and keep object-instance notes short unless extra clarity is needed
* keep `.cpp` function comments minimal when the header already documents the function well
* stop as soon as the annotation is clear

If two annotations explain the code equally well, choose the shorter one.
