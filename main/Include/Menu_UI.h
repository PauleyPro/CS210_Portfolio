/* <<<<<<<<<<<<< Menu_UI.h >>>>>>>>>>>>>
* @author Jeremy R Pauley
* @brief Declares the menu user interface function used to display the main Corner Grocer menu.
<<<<<<<<<<<<<<<<<_>>>>>>>>>>>>>>>>> */

#ifndef MENU_UI_H
#define MENU_UI_H

/* ===========================
*      Function Declarations
=========================== */

// ___________________ DisplayMenu _________________________
/* @brief Displays the main menu options in a clear numbered format. 
* 
* We center the spacing of the title dynamically by:
*
* + ((bar size - title size) / 2) 
and inserting ' ' for each missing space.
*
* @note Location: Menus/Stages/Menu_UI.cpp
*/
void DisplayMenu();

#endif