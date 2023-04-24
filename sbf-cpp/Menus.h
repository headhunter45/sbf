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

#include "Colors.h"

namespace SBF {
class MenuStyle;
class MenuItem;
}  // namespace SBF

// End forward declarations
#include <cstdint>
#include <string>

/** \addtogroup Menus
 * @{
 */
namespace SBF {
using std::string;

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
  int id_width;
  int label_width;
  int value_width;
  int screen_width;
  string random_item_name;
  int random_item_id;
  uint8_t random_item_color;
  string cancel_item_name;
  int cancel_item_id;
  uint8_t cancel_item_color;
  string id_label_separator;
  string label_value_separator;
  string menu_item_spacer;
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
  string label;
  int id;
  int value;
  uint8_t color;
  bool is_visible;
  bool include_in_random;
};

// TODO: Make a menu class to hold GetRandomMenuItemId, the various BuildMenu* methods, and possibly PrintMenu.
int GetRandomMenuItemId(std::vector<MenuItem> items);
std::vector<MenuItem> BuildMenu(std::vector<string> labels);
void BuildMenuWithValues(std::vector<MenuItem> items, std::vector<string> labels, std::vector<int> values);
void BuildMenuWithColors(std::vector<MenuItem> items, std::vector<string> labels, std::vector<uint8_t> colors);
std::ostream& PrintMenu(std::ostream& os, std::vector<MenuItem> items, MenuStyle style);
string GetTitle(MenuItem item, MenuStyle style);
string GetTitleWithoutValue(MenuItem item, MenuStyle style);
std::ostream& PrintWithMaybeColor(std::ostream& os,
                                  const std::string& text,
                                  uint8_t text_color = kColorDefaultForeground,
                                  bool use_colors = false);

}  // End namespace SBF

/** @}*/
#endif  // !defined MENUS_H__
