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

#if !defined(DEBUG)
#include <iostream>
#endif

#include "Colors.h"

namespace SBF {
class MenuStyle;
class MenuItem;
}  // namespace SBF

// End forward declarations
#include <cstdint>
#include <string>
#include <utility>
#include <vector>

/** \addtogroup Menus
 * @{
 */
namespace SBF {
class MenuStyleBuilder {
 public:
  MenuStyleBuilder();
  MenuStyleBuilder& SetScreenWidth(int screen_width);
  MenuStyleBuilder& SetRandomItemName(const std::string& name);
  MenuStyleBuilder& SetRandomItemId(int id);
  MenuStyleBuilder& SetRandomItemColor(uint8_t color);
  MenuStyleBuilder& SetCancelItemName(const std::string& name);
  MenuStyleBuilder& SetCancelItemId(int id);
  MenuStyleBuilder& SetCancelItemColor(uint8_t color);
  MenuStyleBuilder& SetIdLabelSeparator(const std::string& separator);
  MenuStyleBuilder& SetLabelValueSeparator(const std::string& separator);
  MenuStyleBuilder& SetMenuItemSeparator(const std::string& separator);
  MenuStyleBuilder& SetShowRandom(bool show_random);
  MenuStyleBuilder& SetShowCancel(bool show_cancel);
  MenuStyleBuilder& SetUseColors(bool use_colors);
  MenuStyle Build();
};

class MenuStyle {
 public:
  MenuStyle();
  void Adjust(std::vector<MenuItem> menu_items, bool ignore_value = true);
  friend std::ostream& operator<<(std::ostream& os, const MenuStyle& style);
  bool operator==(const MenuStyle& other);
  bool operator!=(const MenuStyle& other);
  int id_width;
  int label_width;
  int value_width;
  int screen_width;
  std::string random_item_name;
  int random_item_id;
  uint8_t random_item_color;
  std::string cancel_item_name;
  int cancel_item_id;
  uint8_t cancel_item_color;
  std::string id_label_separator;
  std::string label_value_separator;
  std::string menu_item_spacer;
  bool show_random;
  bool show_cancel;
  bool use_colors;
};

class MenuItem {
 public:
  MenuItem();
  MenuItem(std::string label, int id);
  MenuItem(std::string label, int id, int value);
  MenuItem(std::string label, int id, uint8_t color);
  friend std::ostream& operator<<(std::ostream& os, const MenuItem& item);
  bool operator==(const MenuItem& other);
  bool operator!=(const MenuItem& other);
  std::string label;
  int id;
  int value;
  uint8_t color;
  bool is_visible;
  bool include_in_random;
};

// TODO: Make a menu class to hold GetRandomMenuItemId, the various BuildMenu* methods, and possibly PrintMenu.
int GetRandomMenuItemId(std::vector<MenuItem> items);
std::vector<MenuItem> BuildMenu(std::vector<std::string> labels);
std::vector<MenuItem> BuildMenuWithValues(std::vector<std::pair<std::string, int>> items);
std::vector<MenuItem> BuildMenuWithValues(std::vector<std::string> labels, std::vector<int> values);
std::vector<MenuItem> BuildMenuWithColors(std::vector<std::pair<std::string, uint8_t>> items);
std::vector<MenuItem> BuildMenuWithColors(std::vector<std::string> labels, std::vector<uint8_t> colors);
std::ostream& PrintMenu(std::ostream& os, std::vector<MenuItem> items, MenuStyle style);
std::string GetTitle(MenuItem item, MenuStyle style);
std::string GetTitleWithoutValue(MenuItem item, MenuStyle style);
std::ostream& PrintWithMaybeColor(std::ostream& os,
                                  const std::string& text,
                                  uint8_t text_color = kColorDefaultForeground,
                                  bool use_colors = false);
int ChooseStringId(std::vector<std::string> labels, MenuStyle style, const std::string& prompt);
bool ChooseYesOrNo(std::string prompt);
int GetChoice(int min, int max);
int GetChoice();
int GetMenuChoice(std::vector<MenuItem> menu_items, MenuStyle style);
std::string GetString(std::string prompt);
int ChooseStringIdWithValues(std::vector<std::string> labels,
                             std::vector<int> values,
                             MenuStyle style,
                             const std::string& prompt);
int ChooseMenuItemId(std::vector<MenuItem> menu_items, MenuStyle style, const std::string& prompt, bool ignore_value);
int ChooseStringIdWithColors(std::vector<std::string> labels,
                             std::vector<uint8_t> colors,
                             MenuStyle style,
                             const std::string& prompt);
void WaitForKeypress();

/// Clears the screen if not a debug build.
inline void MaybeClearScreen() {
#if !defined(DEBUG)
  std::cout << "\033[1;1H\033[2J";
#endif
}
}  // End namespace SBF

/** @}*/
#endif  // !defined MENUS_H__
