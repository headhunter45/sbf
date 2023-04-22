#ifndef MENUS_H__
#define MENUS_H__

/***************************************************************************************
 * @file Menus.h
 *
 * @brief Defines constants and functions for working with menus.
 * @copyright
 * Copyright 2023 Tom Hicks
 * Licensed under the MIT license see the LICENSE file for details.
 ***************************************************************************************/

namespace SBF {
struct MenuStyle;
struct MenuItem;
}  // namespace SBF

// End forward declarations
#include <cstdint>
#include <string>

/** \addtogroup Menus
 * @{
 */
namespace SBF {
using std::string;

struct MenuStyle {
  int idWidth;
  int labelWidth;
  int valueWidth;
  int screenWidth;
  string randomItemName;
  int randomItemId;
  string idLabelSeparator;
  string labelValueSeparator;
  string menuItemSpacer;
  bool showRandom;
  bool useColors;
};

struct MenuItem {
  string label;
  int id;
  int value;
  int color;
  bool isVisible;
};

int GetRandomMenuItemId(std::vector<MenuItem> items);
void BuildMenu(std::vector<MenuItem> items, std::vector<string> labels);
void BuildMenuWithValues(std::vector<MenuItem> items, std::vector<string> labels, std::vector<int> values);
void BuildMenuWithColors(std::vector<MenuItem> items, std::vector<string> labels, std::vector<uint8_t> colors);
void AdjustMenuStyle(MenuStyle& style, std::vector<MenuItem> items, bool ignoreValue);
void PrintMenu(std::vector<MenuItem> items, MenuStyle style);
string GetTitle(MenuItem item, MenuStyle style);
string GetTitleWithoutValue(MenuItem item, MenuStyle style);
void NewMenuStyle(MenuStyle& style);
void NewMenuItem(MenuItem& item, string label, int id);
void NewMenuItemWithValue(MenuItem& item, string label, int id, int value);
void NewMenuItemWithColor(MenuItem& item, string label, int id, uint8_t color);

}  // End namespace SBF

/** @}*/
#endif  // !defined MENUS_H__
