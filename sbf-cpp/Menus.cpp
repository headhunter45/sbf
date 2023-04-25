#include "Menus.h"

#include <cstdint>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "Colors.h"
#include "Random.h"
#include "Utils.h"

namespace SBF {
namespace {
using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::pair;
using std::string;
using std::to_string;
using std::vector;
}  // End namespace

void BuildMenuWithValues(vector<MenuItem> items, vector<string> labels, vector<int> values);
void BuildMenuWithColors(vector<MenuItem> items, vector<string> labels, vector<uint8_t> colors);
void AdjustMenuStyle(MenuStyle& style, vector<MenuItem> items, bool ignoreValue);
string GetTitle(MenuItem item, MenuStyle style);
string GetTitleWithoutValue(MenuItem item, MenuStyle style);
void NewMenuStyle(MenuStyle& style);
void NewMenuItem(MenuItem& item, string label, int id);
void NewMenuItemWithValue(MenuItem& item, string label, int id, int value);
void NewMenuItemWithColor(MenuItem& item, string label, int id, uint8_t color);

void MenuStyle::Adjust(vector<MenuItem> menu_items, bool ignore_value) {
  size_t max_id_width = 0;
  size_t max_item_width = 0;
  size_t max_value_width = 0;
  for_each(menu_items.begin(), menu_items.end(), [&](MenuItem menu_item) {
    if (menu_item.is_visible) {
      max_id_width = std::max(max_id_width, to_string(menu_item.id).size());
      max_item_width = std::max(max_item_width, (menu_item.label + label_value_separator).size());
      max_value_width = std::max(max_value_width, to_string(menu_item.value).size());
    }
  });
  if (show_random) {
    max_id_width = std::max(max_id_width, to_string(random_item_id).size());
    max_item_width = std::max(max_item_width, random_item_name.size());
  }
  if (show_cancel) {
    max_id_width = std::max(max_id_width, to_string(cancel_item_id).size());
    max_item_width = std::max(max_item_width, cancel_item_name.size());
  }
  id_width = max_id_width;
  label_width = max_item_width;
  value_width = ignore_value ? 0 : max_value_width;
}

ostream& PrintMenu(ostream& os, vector<MenuItem> items, MenuStyle style) {
  MenuItem random_item = MenuItem(style.random_item_name, style.random_item_id, style.random_item_color);
  MenuItem cancel_item = MenuItem(style.cancel_item_name, style.cancel_item_id, style.cancel_item_color);
  size_t actual_count = 0;
  for_each(items.begin(), items.end(), [&actual_count](MenuItem item) {
    if (item.is_visible) {
      actual_count++;
    }
  });
  if (style.show_cancel) {
    actual_count++;
  }
  if (style.show_random) {
    actual_count++;
  }
  if (actual_count <= 10) {
    for_each(items.begin(), items.end(), [&style, &os](MenuItem item) {
      if (item.is_visible) {
        string title = GetTitle(item, style);
        PrintWithMaybeColor(os, title, item.color, style.use_colors) << endl;
      }
    });
    if (style.show_cancel) {
      string title = GetTitleWithoutValue(cancel_item, style);
      PrintWithMaybeColor(os, title, cancel_item.color, style.use_colors) << endl;
    }
    if (style.show_random) {
      string title = GetTitleWithoutValue(random_item, style);
      PrintWithMaybeColor(os, title, random_item.color, style.use_colors) << endl;
    }
  } else {
    MenuItem empty_item;
    size_t item_width = GetTitle(empty_item, style).size();
    size_t items_per_row = style.screen_width / (item_width + style.menu_item_spacer.size());
    size_t column_width = style.screen_width / items_per_row;

    const size_t count = items.size();
    int column = 0;
    for (int i = 0; i < count; i++) {
      const MenuItem& item = items[i];
      if (item.is_visible) {
        string item_text = GetTitle(item, style);
        if (column != items_per_row - 1) {
          if (i != count || style.show_random || style.show_cancel) {
            size_t text_length = item_text.size();
            item_text = MakeFitL(
                RightTrim(item_text) + style.menu_item_spacer, text_length + style.menu_item_spacer.size(), ' ');
          }
        }
        string label = MakeFitC(item_text, column_width, ' ');
        PrintWithMaybeColor(os, label, item.color, style.use_colors);
        column = (column + 1) % items_per_row;
        if (column == 0) {
          cout << endl;
        }
      }
    }
    if (style.show_cancel) {
      string title = MakeFitC(GetTitleWithoutValue(cancel_item, style), column_width, ' ');
      PrintWithMaybeColor(os, title, cancel_item.color, style.use_colors) << endl;
    }
    if (style.show_random) {
      string title = MakeFitC(GetTitleWithoutValue(random_item, style), column_width, ' ');
      PrintWithMaybeColor(os, title, random_item.color, style.use_colors) << endl;
    }
  }
  return os;
}

vector<MenuItem> BuildMenu(vector<string> labels) {
  vector<MenuItem> menu_items;
  int id = 1;
  for_each(
      labels.begin(), labels.end(), [&menu_items, &id](string label) { menu_items.push_back(MenuItem(label, id++)); });
  return menu_items;
}

vector<MenuItem> BuildMenuWithValues(vector<pair<string, int>> items) {
  vector<MenuItem> menu_items;
  size_t id = 1;
  for (auto pr : items) {
    menu_items.push_back(MenuItem(pr.first, id, pr.second));
  }
  return menu_items;
}

vector<MenuItem> BuildMenuWithValues(vector<string> labels, vector<int> values) {
  vector<MenuItem> menu_items;
  size_t count = std::min(labels.size(), values.size());
  for (size_t i = 0; i < count; i++) {
    menu_items.push_back(MenuItem(labels.at(i), i + 1, values.at(i)));
  }
  return menu_items;
}

vector<MenuItem> BuildMenuWithColors(vector<pair<string, uint8_t>> items) {
  vector<MenuItem> menu_items;
  size_t id = 1;
  for (auto pr : items) {
    menu_items.push_back(MenuItem(pr.first, id, pr.second));
  }
  return menu_items;
}

vector<MenuItem> BuildMenuWithColors(vector<string> labels, vector<uint8_t> colors) {
  vector<MenuItem> menu_items;
  size_t count = std::min(labels.size(), colors.size());
  for (size_t i = 0; i < count; i++) {
    menu_items.push_back(MenuItem(labels.at(i), i + 1, colors.at(i)));
  }
  return menu_items;
}

int GetRandomMenuItemId(vector<MenuItem> items) {
  int num_visible_items = 0;
  size_t count = items.size();
  vector<int> visible_item_ids;
  for (int i = 0; i < count; i++) {
    MenuItem item = items.at(i);
    if (item.is_visible && item.include_in_random) {
      visible_item_ids.push_back(item.id);
      num_visible_items++;
    }
  }
  return visible_item_ids[GetRandomInt(0, num_visible_items - 1)];
}

MenuStyle::MenuStyle()
    : id_width(0),
      label_width(0),
      value_width(0),
      screen_width(80),
      random_item_name("Random"),
      random_item_id(0),
      random_item_color(kColorDefaultForeground),
      cancel_item_name("Cancel"),
      cancel_item_id(-1),
      cancel_item_color(kColorDefaultForeground),
      id_label_separator(" = "),
      label_value_separator(": "),
      menu_item_spacer(", "),
      show_random(true),
      show_cancel(false),
      use_colors(false) {}

MenuItem::MenuItem()
    : label(""), id(0), value(0), color(kColorDefaultForeground), is_visible(true), include_in_random(true) {}

MenuItem::MenuItem(string label, int id)
    : label(label), id(id), value(0), color(kColorDefaultForeground), is_visible(true), include_in_random(true) {}

MenuItem::MenuItem(string label, int id, int value)
    : label(label), id(id), value(value), color(kColorDefaultForeground), is_visible(true), include_in_random(true) {}

MenuItem::MenuItem(string label, int id, uint8_t color)
    : label(label), id(id), value(0), color(color), is_visible(true), include_in_random(true) {}

ostream& PrintWithMaybeColor(ostream& os, const string& text, uint8_t text_color, bool use_colors) {
  uint8_t previous_color = GetForegroundColor();
  if (use_colors) {
    SetForegroundColor(text_color);
    os << ForegroundColor;
  }
  os << text;
  if (use_colors) {
    SetForegroundColor(previous_color);
    os << ForegroundColor;
  }
  return os;
}

string GetTitleWithoutValue(MenuItem item, MenuStyle style) {
  string id_string = MakeFitR(to_string(item.id), style.id_width, ' ');
  int label_width = style.label_width + style.value_width + style.label_value_separator.size();
  string label_string = MakeFitL(item.label, label_width, ' ');
  return id_string + style.id_label_separator + label_string;
}

string GetTitle(MenuItem item, MenuStyle style) {
  string id = to_string(item.id);
  string label = item.label;
  if (style.value_width > 0) {
    label += style.label_value_separator;
  }
  string value = to_string(item.value);
  string formatted_id = MakeFitR(id, style.id_width);
  string formatted_label = MakeFitL(label, style.label_width);
  string formatted_value = MakeFitR(value, style.value_width);
  return formatted_id + style.id_label_separator + formatted_label + formatted_value;
}

std::ostream& operator<<(std::ostream& os, const MenuStyle& style) {
  os << "MenuStyle {id_width: " << style.id_width << ", label_width: " << style.label_width
     << ", value_width: " << style.value_width << ", screen_width: " << style.screen_width
     << ", show_random: " << (style.show_random ? "true" : "false") << ", random_item_id: " << style.random_item_id
     << ", random_item_name: " << style.random_item_name << ", random_item_color: " << (int)style.random_item_color
     << ", show_cancel: " << (style.show_cancel ? "true" : "false") << ", cancel_item_id: " << style.cancel_item_id
     << ", cancel_item_name: " << style.cancel_item_name << ", cancel_item_color: " << (int)style.cancel_item_color
     << ", id_label_separator: \"" << style.id_label_separator << "\", label_value_separator: \""
     << style.label_value_separator << "\", menu_item_spacer: \"" << style.menu_item_spacer
     << "\", use_colors: " << (style.use_colors ? "true" : "false") << "}";
  return os;
}

std::ostream& operator<<(std::ostream& os, const MenuItem& item) {
  os << "MenuItem {id: " << item.id << ", label: \"" << item.label << "\", value: " << item.value
     << ", color: " << (int)item.color << ", is_visible: " << (item.is_visible ? "true" : "false")
     << ", include_in_random: " << (item.include_in_random ? "true" : "false") << "}";
  return os;
}

bool MenuStyle::operator==(const MenuStyle& other) {
  return cancel_item_color == other.cancel_item_color && cancel_item_id == other.cancel_item_id
      && cancel_item_name == other.cancel_item_name && id_label_separator == other.id_label_separator
      && id_width == other.id_width && label_value_separator == other.label_value_separator
      && label_width == other.label_width && menu_item_spacer == other.menu_item_spacer
      && random_item_color == other.random_item_color && random_item_id == other.random_item_id
      && random_item_name == other.random_item_name && screen_width == other.screen_width
      && show_cancel == other.show_cancel && show_random == other.show_random && use_colors == other.use_colors
      && value_width == other.value_width;
}

bool MenuStyle::operator!=(const MenuStyle& other) {
  return !(*this == other);
}

bool MenuItem::operator==(const MenuItem& other) {
  return color == other.color && id == other.id && include_in_random == other.include_in_random
      && is_visible == other.is_visible && label == other.label && value == other.value;
}

bool MenuItem::operator!=(const MenuItem& other) {
  return !(*this == other);
}

int GetChoice(int min, int max) {
  int choice;
  do {
    choice = GetChoice();
  } while (choice < min || choice > max);
  return choice;
}

int GetChoice() {
  int choice;
  string line;
  bool has_error;
  do {
    has_error = false;
    getline(cin, line);
    try {
      if (line.empty()) {
        return 0;
      }
      choice = stoi(line);
    } catch (...) {
      has_error = true;
    }
  } while (has_error);
  return choice;
}

int GetMenuChoice(vector<MenuItem> menu_items, MenuStyle style) {
  int choice;
  while (true) {
    choice = GetChoice();
    if (style.show_random && choice == style.random_item_id) {
      return choice;
    }
    if (style.show_cancel && choice == style.cancel_item_id) {
      return choice;
    }
    for (MenuItem item : menu_items) {
      if (item.id == choice) {
        return choice;
      }
    }
  }
}

string GetString(string prompt) {
  cout << prompt << endl;
  string response;
  getline(cin, response);
  return response;
}

int ChooseStringId(vector<string> labels, MenuStyle style, const string& prompt) {
  MaybeClearScreen();
  vector<MenuItem> menu_items = BuildMenu(labels);
  style.Adjust(menu_items);
  cout << prompt << endl;
  PrintMenu(cout, menu_items, style);
  int choice = GetMenuChoice(menu_items, style);
  if (choice == style.random_item_id) {
    choice = GetRandomMenuItemId(menu_items);
  }
  return choice;
}

bool ChooseYesOrNo(string prompt) {
  MenuStyle style;
  style.show_random = false;
  vector<MenuItem> menu_items = BuildMenu({"Yes", "No"});
  style.Adjust(menu_items, true);
  cout << prompt << endl;
  PrintMenu(cout, menu_items, style);
  int choice = GetMenuChoice(menu_items, style);
  if (choice == style.random_item_id) {
    choice = GetRandomMenuItemId(menu_items);
  }
  return choice == 1;
}

int ChooseStringIdWithValues(vector<string> labels, vector<int> values, MenuStyle style, const string& prompt) {
  MaybeClearScreen();
  vector<MenuItem> menu_items = BuildMenuWithValues(labels, values);
  style.Adjust(menu_items, false);
  cout << prompt << endl;
  PrintMenu(cout, menu_items, style);
  int choice = GetMenuChoice(menu_items, style);
  if (choice == style.random_item_id) {
    choice = GetRandomMenuItemId(menu_items);
  }
  return choice;
}

int ChooseStringIdWithColors(vector<string> labels, vector<uint8_t> colors, MenuStyle style, const string& prompt) {
  MaybeClearScreen();
  // Check array bounds
  vector<MenuItem> menu_items = BuildMenuWithColors(labels, colors);
  style.Adjust(menu_items);
  cout << prompt << endl;
  PrintMenu(cout, menu_items, style);
  int choice = GetMenuChoice(menu_items, style);
  if (choice == style.random_item_id) {
    choice = GetRandomMenuItemId(menu_items);
  }
  return choice;
}

int ChooseMenuItemId(vector<MenuItem> menu_items, MenuStyle style, const string& prompt, bool ignore_value) {
  MaybeClearScreen();
  style.Adjust(menu_items, ignore_value);
  cout << prompt << endl;
  PrintMenu(cout, menu_items, style);
  int choice = GetMenuChoice(menu_items, style);
  if (choice == style.random_item_id) {
    choice = GetRandomMenuItemId(menu_items);
  }
  return choice;
}

void WaitForKeypress() {
  // TODO: Make this press any key to continue.
}

}  // End namespace SBF
