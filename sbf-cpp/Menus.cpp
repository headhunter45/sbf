#include "Menus.h"

#include <iostream>
#include <vector>

#include "Colors.h"
#include "Random.h"
#include "Utils.h"

namespace SBF {
namespace {
using std::cout;
using std::endl;
using std::ostream;
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
      max_id_width = std::max(max_id_width, itos(menu_item.id).size());
      max_item_width = std::max(max_item_width, (menu_item.label + label_value_separator).size());
      max_value_width = std::max(max_value_width, itos(menu_item.value).size());
    }
  });
  if (show_random) {
    max_id_width = std::max(max_id_width, itos(random_item_id).size());
    max_item_width = std::max(max_item_width, random_item_name.size());
  }
  if (show_cancel) {
    max_id_width = std::max(max_id_width, itos(cancel_item_id).size());
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
            item_text = make_fit_l(
                right_trim(item_text) + style.menu_item_spacer, text_length + style.menu_item_spacer.size(), ' ');
          }
        }
        string label = make_fit_c(item_text, column_width, ' ');
        PrintWithMaybeColor(os, label, item.color, style.use_colors);
        column = (column + 1) % items_per_row;
        if (column == 0) {
          cout << endl;
        }
      }
    }
    if (style.show_cancel) {
      string title = make_fit_c(GetTitleWithoutValue(cancel_item, style), column_width, ' ');
      PrintWithMaybeColor(os, title, cancel_item.color, style.use_colors) << endl;
    }
    if (style.show_random) {
      string title = make_fit_c(GetTitleWithoutValue(random_item, style), column_width, ' ');
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

int GetRandomMenuItemId(vector<MenuItem> items) {
  int num_visible_items = 0;
  size_t count = items.size();
  vector<int> visible_item_ids;
  for (int i = 1; i <= count; i++) {
    if (items[i].is_visible && items[i].include_in_random) {
      visible_item_ids.push_back(i);
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
  string id_string = make_fit_r(itos(item.id), style.id_width, ' ');
  int label_width = style.label_width + style.value_width + style.label_value_separator.size();
  string label_string = make_fit_l(item.label, label_width, ' ');
  return id_string + style.id_label_separator + label_string;
}

string GetTitle(MenuItem item, MenuStyle style) {
  string id = itos(item.id);
  string label = item.label;
  // cout << "GetTitle item.id: " << item.id << ", item.label: " << item.label << ", style.id_width: " << style.id_width
  // << ", style.label_width: " << style.label_width << ", style.value_width: " << style.value_width << endl;
  if (style.value_width > 0) {
    label += style.label_value_separator;
  }
  string value = itos(item.value);
  string formatted_id = make_fit_r(id, style.id_width);
  string formatted_label = make_fit_l(label, style.label_width);
  string formatted_value = make_fit_r(value, style.value_width);
  return formatted_id + style.id_label_separator + formatted_label + formatted_value;
}

}  // End namespace SBF

/*
Function GetRandomMenuItemId (items() As MenuItem, count As Integer)
    numVisibleItems = 0
    Dim visibleItems(count) As Integer
    For i = 1 To count
        If items(i).isVisible Then
            visibleItems(numVisibleItems) = i
            numVisibleItems = numVisibleItems + 1
        End If
    Next
    i = GetRandomInt(0, numVisibleItems - 1)
    GetRandomMenuItemId = visibleItems(i)
End Function

Sub BuildMenu (items() As MenuItem, labels() As String, count As Integer)
    For i = 1 To count
        Dim mi As MenuItem
        Call NewMenuItem(mi, labels(i), i)
        items(i) = mi
    Next
End Sub


Sub BuildMenuWithValues (items() As MenuItem, labels() As String, values() As Integer, count As Integer)
    For i = 1 To count
        Dim mi As MenuItem
        Call NewMenuItemWithValue(mi, labels(i), i, values(i))
        items(i) = mi
    Next
End Sub

Sub BuildMenuWithColors (items() As MenuItem, labels() As String, colors() As Integer)
    ' Check array bounds
    If LBound(items) <> 1 Or LBound(colors) <> 1 Or UBound(items) <> UBound(colors) Then End

    count = UBound(items)
    For i = 1 To count
        Dim mi As MenuItem
        Call NewMenuItemWithColor(mi, labels(i), colors(i), i)
        items(i) = mi
    Next
End Sub

Sub AdjustMenuStyle (style As MenuStyle, items() As MenuItem, count As Integer, ignoreValue As Integer)
    maxIdWidth = 0
    maxItemWidth = 0
    maxValueWidth = 0

    For i = 1 To count
        If items(i).isVisible Then
            maxIdWidth = MaxI(maxIdWidth, Len(itos$(items(i).id)))
            maxItemWidth = MaxI(maxItemWidth, Len(items(i).label + style.labelValueSeparator))
            maxValueWidth = MaxI(maxValueWidth, Len(itos$(items(i).value)))
        End If
    Next
    If style.showRandom Then
        maxIdWidth = MaxI(maxIdWidth, Len("0"))
        maxItemWidth = MaxI(maxItemWidth, Len(style.randomItemName))
    End If
    style.idWidth = maxIdWidth
    style.labelWidth = maxItemWidth
    If Not ignoreValue Then style.valueWidth = maxValueWidth Else style.valueWidth = 0
End Sub

Sub PrintMenu (items() As MenuItem, count As Integer, style As MenuStyle)
    Dim randomItem As MenuItem
    Call NewMenuItem(randomItem, style.randomItemName, style.randomItemId)
    If count <= 10 Then
        For i = 1 To count
            If items(i).isVisible Then
                If style.useColors Then
                    oldColor = GetColor
                    SetColor (items(i).color)
                End If
                Print GetTitle$(items(i), style)
                If style.useColors Then
                    Call SetColor(oldColor)
                End If
            End If
        Next
        If style.showRandom Then
            Print GetTitleWithoutValue$(randomItem, style)
        End If
    Else
        Dim emptyItem As MenuItem
        Call NewMenuItem(emptyItem, "", 0)
        itemWidth = Len(GetTitle$(emptyItem, style))
        itemsPerRow = style.screenWidth \ (itemWidth + Len(style.menuItemSpacer))
        columnWidth = style.screenWidth \ itemsPerRow

        column = 0
        For i = 1 To count
            If items(i).isVisible Then
                itemText$ = GetTitle$(items(i), style)
                If column <> (itemsPerRow - 1) Then
                    If i <> count Or style.showRandom Then
                        textLength = Len(itemText$)
                        itemText$ = make_fit_l$(right_trim$(itemText$) + style.menuItemSpacer, textLength +
Len(style.menuItemSpacer), ' ') End If End If Print make_fit_c$(itemText$, columnWidth, ' '); End If column = (column +
1) Mod itemsPerRow If column = 0 Then Print "" Next If style.showRandom Then Print
make_fit_c$(GetTitleWithoutValue$(randomItem, style), columnWidth, ' ') End If End If End Sub



Function GetTitleWithoutValue$ (mi As MenuItem, ms As MenuStyle)
    GetTitleWithoutValue$ = MakeFitR$(itos(mi.id), ms.idWidth, ' ') + ms.idLabelSeparator + make_fit_l$(mi.label,
ms.labelWidth + ms.valueWidth + Len(ms.labelValueSeparator), ' ') End Function

Sub NewMenuStyle (ms As MenuStyle)
    ms.idWidth = 0
    ms.labelWidth = 0
    ms.valueWidth = 0
    ms.screenWidth = 80
    ms.randomItemName = "Random"
    ms.randomItemId = 0
    ms.idLabelSeparator = " = "
    ms.labelValueSeparator = ": "
    ms.menuItemSpacer = ", "
    ms.showRandom = TRUE
    ms.useColors = FALSE
End Sub

Sub NewMenuItem (mi As MenuItem, label As String, id As Integer)
    mi.id = id
    mi.label = label
    mi.value = 0
    mi.color = COLOR_DEFAULT
    mi.isVisible = TRUE
End Sub

Sub NewMenuItemWithValue (mi As MenuItem, label As String, id As Integer, value As Integer)
    mi.id = id
    mi.label = label
    mi.value = value
    mi.color = COLOR_DEFAULT
    mi.isVisible = TRUE
End Sub

Sub NewMenuItemWithColor (mi As MenuItem, label As String, textColor As Integer, id As Integer)
    mi.id = id
    mi.label = label
    mi.value = 0
    mi.color = textColor
    mi.isVisible = TRUE
End Sub
*/
