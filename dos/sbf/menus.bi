Type MenuStyle
    idWidth As Integer
    labelWidth As Integer
    valueWidth As Integer
    screenWidth As Integer
    randomItemName As String
    randomItemId As Integer
    randomItemColor as integer
    cancelItemName As String
    cancelItemId As Integer
    cancelItemColor as integer
    idLabelSeparator As String
    labelValueSeparator As String
    menuItemSpacer As String
    showRandom As Integer
    showCancel as integer
    useColors As Integer
End Type

Type MenuItem
    label As String
    id As Integer
    value As Integer
    color As Integer
    isVisible As Integer
    includeInRandom as integer
End Type
