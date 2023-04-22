#include "Menus.h"

namespace SBF {

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
                        itemText$ = MakeFitL$(RTrim$(itemText$) + style.menuItemSpacer, textLength +
Len(style.menuItemSpacer), " ") End If End If Print MakeFitC$(itemText$, columnWidth, " "); End If column = (column + 1)
Mod itemsPerRow If column = 0 Then Print "" Next If style.showRandom Then Print
MakeFitC$(GetTitleWithoutValue$(randomItem, style), columnWidth, " ") End If End If End Sub

Function GetTitle$ (mi As MenuItem, ms As MenuStyle)
    id$ = itos$(mi.id)
    label$ = mi.label
    If ms.valueWidth > 0 Then label$ = label$ + ms.labelValueSeparator
    value$ = itos$(mi.value)
    GetTitle$ = MakeFitR$(id$, ms.idWidth, " ") + ms.idLabelSeparator + MakeFitL$(label$, ms.labelWidth, " ") +
MakeFitR$(value$, ms.valueWidth, " ") End Function

Function GetTitleWithoutValue$ (mi As MenuItem, ms As MenuStyle)
    GetTitleWithoutValue$ = MakeFitR$(itos(mi.id), ms.idWidth, " ") + ms.idLabelSeparator + MakeFitL$(mi.label,
ms.labelWidth + ms.valueWidth + Len(ms.labelValueSeparator), " ") End Function

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
