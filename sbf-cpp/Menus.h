#ifndef MENUS_H__
#define MENUS_H__
namespace SBF {
    struct MenuStyle;
    struct MenuItem;
}
// End forward declarations
#include <string>
#include <cstdint>

namespace SBF {
    using std::wstring;

    struct MenuStyle {
        int idWidth;
        int labelWidth;
        int valueWidth;
        int screenWidth;
        wstring randomItemName;
        int randomItemId;
        wstring idLabelSeparator;
        wstring labelValueSeparator;
        wstring menuItemSpacer;
        bool showRandom;
        bool useColors;
    };

    struct MenuItem {
        wstring label;
        int id;
        int value;
        int color;
        bool isVisible;
    };

    int GetRandomMenuItemId (std::vector<MenuItem> items);
    void BuildMenu(std::vector<MenuItem> items, std::vector<wstring> labels);
    void BuildMenuWithValues(std::vector<MenuItem> items, std::vector<wstring> labels, std::vector<int> values);
    void BuildMenuWithColors(std::vector<MenuItem> items, std::vector<wstring> labels, std::vector<uint8_t> colors);
    void AdjustMenuStyle(MenuStyle& style, std::vector<MenuItem> items, bool ignoreValue);
    void PrintMenu(std::vector<MenuItem> items, MenuStyle style);
    wstring GetTitle(MenuItem item, MenuStyle style);
    wstring GetTitleWithoutValue(MenuItem item, MenuStyle style);
    void NewMenuStyle(MenuStyle& style);
    void NewMenuItem(MenuItem& item, wstring label, int id);
    void NewMenuItemWithValue(MenuItem& item, wstring label, int id, int value);
    void NewMenuItemWithColor(MenuItem& item, wstring label, int id, uint8_t color);

} // End namespace SBF

#endif // !defined MENUS_H__
