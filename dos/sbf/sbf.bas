$Debug
' Setup
' TODO: See if other combinations of clan and other variables cause sub questions.
Randomize Timer

'Call Test
'End


' TODO: maybe make these some kind of typedef with an id and a label constants or enums would be great
Const All_Clans_Count = 18
Dim Shared All_Clans(1 To All_Clans_Count) As String
All_Clans(1) = "Anarch"
All_Clans(2) = "Assamite"
All_Clans(3) = "Baali"
All_Clans(4) = "Brujah"
All_Clans(5) = "Caitiff"
All_Clans(6) = "Cappadocian"
All_Clans(7) = "Gangrel"
All_Clans(8) = "Giovanni"
All_Clans(9) = "Inconnu"
All_Clans(10) = "Lasombra"
All_Clans(11) = "Malkavian"
All_Clans(12) = "Nosferatu"
All_Clans(13) = "Ravanos"
All_Clans(14) = "Settite"
All_Clans(15) = "Tremere"
All_Clans(16) = "Toreador"
All_Clans(17) = "Tzismice"
All_Clans(18) = "Ventrue"

' TODO: Find a word that encapsulates both nature and demeanor. There is probably one in the book.
Const All_Archetypes_Count = 30
Dim Shared All_Archetypes(1 To All_Archetypes_Count) As String
All_Archetypes(1) = "Architect"
All_Archetypes(2) = "Autocrat"
All_Archetypes(3) = "Barbarian"
All_Archetypes(4) = "Bon Vivant"
All_Archetypes(5) = "Bravo"
All_Archetypes(6) = "Caregiver"
All_Archetypes(7) = "Caretaker"
All_Archetypes(8) = "Celebrant"
All_Archetypes(9) = "Child"
All_Archetypes(10) = "Conformist"
All_Archetypes(11) = "Conniver"
All_Archetypes(12) = "Curmudgeon"
All_Archetypes(13) = "Defender"
All_Archetypes(14) = "Deviant"
All_Archetypes(15) = "Director"
All_Archetypes(16) = "Fanatic"
All_Archetypes(17) = "Gallant"
All_Archetypes(18) = "Innovator"
All_Archetypes(19) = "Jester"
All_Archetypes(20) = "Judge"
All_Archetypes(21) = "Loner"
All_Archetypes(22) = "Martyr"
All_Archetypes(23) = "Monster"
All_Archetypes(24) = "Penitent"
All_Archetypes(25) = "Rebel"
All_Archetypes(26) = "Rogue"
All_Archetypes(27) = "Survivor"
All_Archetypes(28) = "Traditionalist"
All_Archetypes(29) = "Tyrant"
All_Archetypes(30) = "Visionary"

Const All_Disciplines_Count = 24
Dim Shared All_Disciplines(1 To All_Disciplines_Count) As String
All_Disciplines(1) = "Animalism"
All_Disciplines(2) = "Auspex"
All_Disciplines(3) = "Bardo"
All_Disciplines(4) = "Celerity"
All_Disciplines(5) = "Chimestry"
All_Disciplines(6) = "Dementation"
All_Disciplines(7) = "Dominate"
All_Disciplines(8) = "Fortitude"
All_Disciplines(9) = "Melpominee"
All_Disciplines(10) = "Mortis"
All_Disciplines(11) = "Mytherceria"
All_Disciplines(12) = "Necromancy"
All_Disciplines(13) = "Obeah"
All_Disciplines(14) = "Obfuscate"
All_Disciplines(15) = "Obtenebration"
All_Disciplines(16) = "Potence"
All_Disciplines(17) = "Presence"
All_Disciplines(18) = "Protean"
All_Disciplines(19) = "Quietus"
All_Disciplines(20) = "Serpentis"
All_Disciplines(21) = "Spiritus"
All_Disciplines(22) = "Thanantosis"
All_Disciplines(23) = "Thaumaturgy"
All_Disciplines(24) = "Vicissitude"

Type CharacterType
    name As String
    player As String
    chronicle As String
    haven As String
    concept As String
    age As String
    sex As Integer
    clan As Integer
    nature As Integer
    demeanor As Integer
    'disciplines() as integer
    ' Attributes
    attr_strength As Integer
    attr_dexterity As Integer
    attr_stamina As Integer
    attr_appearance As Integer
    attr_charisma As Integer
    attr_manipulation As Integer
    attr_intelligence As Integer
    attr_perception As Integer
    attr_wits As Integer
End Type


' Splash screen
Cls
Print "  Welcome to Tom's Storyteller's Best Friend.  This is a program  that is meant"
Print "to aid Storytellers in running Vampire: the Masquerade Chronicles and Vampire:"
Print "the Dark Ages Chronicles.  It is distributed as freeware until I think it is"
Print "worth something.This program could aid in running campaigns for other"
Print "role-playing games especially those from White Wolf(tm).  If you would like"
Print "anything added please e-mail me at locutus2001@hotmail.com."
Print "     Press any key to continue"
While InKey$ = ""
Wend

' Main menu
Let choice = 0
Do
    Cls
    Print "ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป"
    Print "บ What are you going to do?                                                    บ"
    Print "บ        1 = Character Generator                                               บ"
    Print "บ        2 = Character Generator for Dummies                                   บ"
    Print "บ        3 = Combat Computer                                                   บ"
    Print "บ        4 = Dice Roller                                                       บ"
    Print "บ        5 = Random Character Generator                                        บ"
    Print "บ        6 =                                                                   บ"
    Print "บ        7 = Vehicle Generator                                                 บ"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ        0 = End                                                               บ"
    Print "บ                                                                              บ"
    Print "ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ"
    choice = GetChoice(0, 7)
    Select Case choice
        Case 1
            CharacterGenerator
        Case 2
            CharacterGeneratorForDummies
        Case 3
            CombatComputer
        Case 4
            DiceRoller
        Case 5
            RandomCharacterGenerator
        Case 7
            VehicleGenerator
    End Select
Loop Until choice = 0

Sub BlankScreen
    Print "ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ"
End Sub

Function GetChoice (min As Integer, max As Integer)
    Dim choice
    Do
        Input choice
    Loop Until choice <= max And choice >= min
    GetChoice = choice
End Function

Function GetRandomInt (min As Integer, max As Integer)
    GetRandomInt = Int(Rnd * (max - min + 1)) + min
End Function

Sub PrintMenu (items() As String, num_items As Integer)
    ' TODO: allow opting out of the random item.
    ' TODO: allow printing inside of a box บ 1 = item บ.
    index_length = Len(Str$(num_items))
    max_item_length = Len("Random")
    For i = 1 To num_items
        max_item_length = MaxI(max_item_length, Len(items(i)))
    Next

    For i = 1 To num_items
        Print MakeFitR$(Str$(i), index_length, " ") + " = " + MakeFitL$(items(i), max_item_length, " ");
    Next
    Print MakeFitR$("0", index_length, " ") + " = " + MakeFitL$("Random", max_item_length, " ")
End Sub

Sub PrintMenuWithValues (items() As String, values() As Integer, num_items As Integer)
    ' TODO: @see PrintMenu
    max_index_length = Len(Str$(num_items))
    max_item_length = Len("Random")
    max_value_length = 0
    For i = 1 To num_items
        max_item_length = MaxI(max_item_length, Len(items(i)))
        max_value_length = MaxI(max_value_length, Len(Str$(values(i))))
    Next

    For i = 1 To num_items
        Print MakeFitR$(Str$(i), max_index_length, " ") + " = " + MakeFitL$(items(i), max_item_length, " ") + MakeFitR$(Str$(values(i)), max_value_length, " ");
    Next
    Print MakeFitR$("0", index_length, " ") + " = " + MakeFitL$("Random", max_item_length, " ")
End Sub

Function MakeFitL$ (text As String, length As Integer, pad As String)
    MakeFitL = Left$(text + String$(length, pad), length)
End Function

Function MakeFitC$ (text As String, length As Integer, pad As String)
    'Chop text if necessary
    TextLength = Len(text)
    LeftPadLength = MaxI(0, length - TextLength) \ 2
    RightPadLength = MaxI(0, length - TextLength - LeftPadLength)
    LeftPad$ = String$(LeftPadLength, pad)
    RightPad$ = String$(RightPadLength, pad)
    TotalChop = MaxI(0, TextLength - length)
    LeftChop = TotalChop \ 2 + 1
    MakeFitC = LeftPad$ + Mid$(text, LeftChop, length) + RightPad$
End Function

Function MakeFitR$ (text As String, length As Integer, pad As String)
    MakeFitR = Right$(String$(length, pad) + text, length)
End Function

Function MaxI (val1 As Integer, val2 As Integer)
    If (val1 > val2) Then
        MaxI = val1
    Else
        MaxI = val2
    End If
End Function

Sub CharacterGenerator ()
    Dim ch As CharacterType

    Input "What is the character's name? ", ch.name
    Input "Who is the player? ", ch.player
    Input "What chronicle is the character going to be used for? ", ch.chronicle
    Input "What is the character's Haven? ", ch.haven
    Input "What is the character's concept? ", ch.concept
    Input "How old is the character? ", ch.age
    Print "What is the sex of the character? 1 = Male  2 = Female 0 = Random"
    ch.sex = GetChoice(0, 2)
    If ch.sex > 2 Or ch.sex < 1 Then ch.sex = GetRandomInt(1, 2)
    Cls
    Print "What Clan is the character from?"
    Call PrintMenu(All_Clans(), All_Clans_Count)
    ch.clan = GetChoice(0, All_Clans_Count)
    If ch.clan > All_Clans_Count Or ch.clan < 1 Then ch.clan = GetRandomInt(1, All_Clans_Count)
    Cls
    Print "What is your character's Nature?"
    Call PrintMenu(All_Archetypes(), All_Archetypes_Count)
    ch.nature = GetChoice(0, All_Archetypes_Count)
    If ch.nature > All_Archetypes_Count Or ch.nature < 1 Then ch.nature = GetRandomInt(1, All_Archetypes_Count)
    Cls
    Print "What is your character's Demeanor?"
    Call PrintMenu(All_Archetypes(), All_Archetypes_Count)
    ch.demeanor = GetChoice(0, All_Archetypes_Count)
    If ch.demeanor > All_Archetypes_Count Or ch.demeanor < 1 Then ch.demeanor = GetRandomInt(1, All_Archetypes_Count)

    ' The character starts with 3 discipline points and they can spend them on one or more disciplines
    Dim disciplines(1 To All_Disciplines_Count) As Integer
    For i = 1 To All_Disciplines_Count
        disciplines(i) = 0
    Next
    discipline_points = 3

    While discipline_points > 0
        Cls
        Print "Which discipline do you want to spend " + Str$(discipline_points) + " discipline points on?"
        Call PrintMenuWithValues(All_Disciplines(), disciplines(), All_Disciplines_Count)
        discipline = GetChoice(0, All_Disciplines_Count)
        If discipline = 0 Then discipline = GetRandomInt(1, All_Disciplines_Count)
        disciplines(discipline) = disciplines(discipline) + 1
        discipline_points = discipline_points - 1
    Wend

    Const All_Attributes_Count = 3
    Dim All_Attributes(1 To All_Attributes_Count) As String
    All_Attributes(1) = "Physical"
    All_Attributes(2) = "Social"
    All_Attributes(3) = "Mental"

    ' TODO: Find a more general form for this that stores the chosen attributes in an array
    Dim PrimaryAttribute As Integer
    Do
        Cls
        Print "1 = " + All_Attributes(1) + " ";
        Print "2 = " + All_Attributes(2) + " ";
        Print "3 = " + All_Attributes(3) + " ";
        Print "0 = Random"
        Input "Choose your primary attribute?"; PrimaryAttribute
        If PrimaryAttribute = 0 Then PrimaryAttribute = GetRandomInt(1, All_Attributes_Count)
    Loop While (PrimaryAttribute > All_Attributes_Count And PrimaryAttribute < 1)

    Dim SecondaryAttribute As Integer
    Dim TertiaryAttribute As Integer
    Do
        Cls
        If PrimaryAttribute <> 1 Then Print "1 = " + All_Attributes(1) + " ";
        If PrimaryAttribute <> 2 Then Print "2 = " + All_Attributes(2) + " ";
        If PrimaryAttribute <> 3 Then Print "3 = " + All_Attributes(3) + " ";
        Print "0 = Random"
        Input "Choose your secondary attribute?"; SecondaryAttribute
        If SecondaryAttribute = 0 Or SecondaryAttribute = PrimaryAttribute Then
            SecondaryAttribute = GetRandomInt(1, All_Attributes_Count - 1)
            If SecondaryAttribute >= PrimaryAttribute Then
                PrimaryAttribute = PrimaryAttribute + 1
            End If
        End If
    Loop Until SecondaryAttribute >= 1 And SecondaryAttribute <= 3
    ' General formula for last choice is
    ' Sum(1..AllAttributesCount)-Sum(Choice[1]..Choice[AllAttributesCount-1])
    TertiaryAttribute = 2 * All_Attributes_Count - PrimaryAttribute - SecondaryAttribute

    ' Initialize all attributes to 1
    ch.attr_strength = 1
    ch.attr_dexterity = 1
    ch.attr_stamina = 1
    ch.attr_appearance = 1
    ch.attr_charisma = 1
    ch.attr_manipulation = 1
    ch.attr_intelligence = 1
    ch.attr_perception = 1
    ch.attr_wits = 1

    ' Initialize physical, social, and mental points
    Select Case PrimaryAttribute
        Case 1
            PhysicalPoints = 7
        Case 2
            SocialPoints = 7
        Case 3
            MentalPoints = 7
    End Select
    Select Case SecondaryAttribute
        Case 1
            PhysicalPoints = 5
        Case 2
            SocialPoints = 5
        Case 3
            MentalPoints = 5
    End Select
    Select Case TertiaryAttribute
        Case 1
            PhysicalPoints = 3
        Case 2
            SocialPoints = 3
        Case 3
            MentalPoints = 3
    End Select

    ' Spend physical points
    Do
        Cls
        Print "Your physical attributes are:"
        Print "Strength " + Str$(ch.attr_strength) + ", Dexterity " + Str$(ch.attr_dexterity) + ", Stamina " + Str$(ch.attr_stamina)
        Print "Which attribute would you like to add 1 of your " + Str$(PhysicalPoints) + " points to?"
        Print "1 = Strength     2 = Dexterity    3 = Stamina      0 = Random"
        attr = GetChoice(0, 3)
        If attr = 0 Then attr = GetRandomInt(1, 3)
        Select Case attr
            Case 1
                ch.attr_strength = ch.attr_strength + 1
            Case 2
                ch.attr_dexterity = ch.attr_dexterity + 1
            Case 3
                ch.attr_stamina = ch.attr_stamina + 1
        End Select
        PhysicalPoints = PhysicalPoints - 1
    Loop While PhysicalPoints > 0

    ' Spend social points
    Do
        Cls
        Print "Your social attributes are:"
        Print "Appearance " + Str$(appearance) + ", Charisma " + Str$(charisma) + ", Manipulation " + Str$(manipulation)
        Print "Which attribute would you like to add 1 of your " + Str$(SocialPoints) + " points to?"
        Print "1 = Appearance   2 = Charisma     3 = Manipulation 0 = Random"
        attr = GetChoice(0, 3)
        If attr = 0 Then attr = GetRandomInt(1, 3)
        Select Case attr
            Case 1
                ch.attr_appearance = ch.attr_appearance + 1
            Case 2
                ch.attr_charisma = ch.attr_charisma + 1
            Case 3
                ch.attr_manipulation = ch.attr_manipulation + 1
        End Select
        SocialPoints = SocialPoints - 1
    Loop While SocialPoints > 0

    ' Spend mental points
    Do
        Cls
        Print "Your mental attributes are:"
        Print "Intelligence " + Str$(intelligence) + ", Perception " + Str$(perception) + ", Wits " + Str$(wits)
        Print "Which attribute would you like to add 1 of you " + Str$(MentalPoints) + " points to?"
        Print "1 = Intelligence 2 = Perception   3 = Wits         0 = Random"
        attr = GetChoice(0, 3)
        If attr = 0 Then attr = GetRandomInt(1, 3)
        Select Case attr
            Case 1
                ch.attr_intelligence = ch.attr_intelligence + 1
            Case 2
                ch.attr_perception = ch.attr_perception + 1
            Case 3
                ch.attr_wits = ch.attr_wits + 1
        End Select
        MentalPoints = MentalPoints - 1
    Loop While MentalPoints > 0

    ' TODO: Choose priorities for talents/skills/knowledges
    'Print "1 = Talents    2 = Skills    3 = Knowledges 0 = Random"
    'Print "Which is your primary Ability? "
    'Print "Which is your secondary Ability? "
    'Print "Which is your tertiary Ability? "

    ' TODO: Spend talent points
    'Your Talents are:
    ' 1 = Acting: 0
    ' 2 = Alertness: 0
    ' 3 = Athletics: 0
    ' 4 = Brawl: 0
    ' 5 = Dodge: 0
    ' 6 = Empathy: 0
    ' 7 = Intimidation: 0
    ' 8 = Leadership: 0
    ' 9 = Streetwise: 0
    '10 = Subterfuge: 0
    'Which would you like to add 1 of your 5 points to?

    ' TODO: Spend skill points
    'Your Skills are:
    ' 1 = Animal Ken: 0
    ' 2 = Drive: 0
    ' 3 = Etiquette: 0
    ' 4 = Firearms: 0
    ' 5 = Melee: 0
    ' 6 = Music: 0
    ' 7 = Repair: 0
    ' 8 = Security: 0
    ' 9 = Stealth: 0
    '10 = Survival: 0
    'Which would you like to add 1 of your 13 points to?

    ' TODO: Spend knowledge points
    'Your Knowledges are:
    ' 1 = Bureaucracy: 0
    ' 2 = Computer: 0
    ' 3 = Finance: 0
    ' 4 = Investigation: 0
    ' 5 = Law: 0
    ' 6 = Linguistics: 0
    ' 7 = Medicine: 0
    ' 8 = Occult: 0
    ' 9 = Politics: 0
    '10 = Science: 0
    'Which would you like to add 1 of your 9 points to?

    ' TODO: Spend background points
    ' 1 = Allies     0
    ' 2 = Contacts   0
    ' 3 = Fame       0
    ' 4 = Generation 0
    ' 5 = Herd       0
    ' 6 = Influence  0
    ' 7 = Mentor     0
    ' 8 = Resources  0
    ' 9 = Retainers  0
    '10 = Status     0
    'Which Background would you like to spend 1 of your remaining 5 on?

    ' TODO: Choose your road
    '1 = Road of the Beast - Feed the beast so it will not break loose.
    '2 = Road of Blood - Blood grants the power for revenge.
    '3 = Road of Chivalry - Treat your equals with honor and your betters with respect.
    '4 = Road of the Devil - We are created evil and must play our part.
    '5 = Road of Heaven - God made us vampires to exact his wrath.
    '6 = Road of Humanity - The struggle to maintain one's humanity.
    '7 = Road of Paradox - Existence is a lie change reality for the better.
    '8 = Road of Typhon - Sin and corruption are the keys to understanding.
    'Which road does the character follow?

    ' TODO: Spend virtue points
    'Conscience   1
    'Self-Control 1
    'Courage      1
    'Which virtue do you wish to add one of your 7 points to?

    '... 0123456789
    '160  กขฃคฅฆงจฉ
    '170 ชซฌญฎฏฐฑฒณ
    '180 ดตถทธนบปผฝ
    '190 พฟภมยรฤลฦว
    '200 ศษสหฬอฮฯะั
    '210 าำิีึืฺุูÛ
    '220 ÜÝÞ฿เแโใไๅๅ
    '230 ๆ็่้๊๋2์ํ๎๏
    ' Where do you want the file to be saved? (default is C:\Windows\Desktop)?
    ' What do you want the file to be called? (default is CHAR1)?

    ' enquote forms s/^([ษบศอฬ].*[ปบผน])$/print "$1"/g
    Input a
    ' TODO: figure out how to actually calculate generation
    generation$ = "13"
    If ch.sex = 1 Then sex_string$ = "Male" Else sex_string$ = "Female"
    clan_string$ = All_Clans(ch.clan)

    Dim discipline_strings$(3)
    discipline_1_string$ = ""
    discipline_2_string$ = ""
    discipline_3_string$ = ""
    discipline_strings_index = 0
    For index = 1 To All_Disciplines_Count
        If disciplines(index) > 0 Then
            suffix$ = ""
            If disciplines(index) > 1 Then
                suffix$ = " x" + Str$(disciplines(index))
            End If
            discipline_strings$(discipline_strings_index) = All_Disciplines(index) + suffix$
        End If
    Next

    Cls
    Print "ษออออออออออออออออออออออออออออออออออออออหอออออออออออออออออออออออออออออออออออออออป"
    Print "บ Name: " + MakeFitL$(ch.name, 30, " ") + " บ Sex: " + MakeFitL$(sex_string$, 10, " ") + " Generation: " + MakeFitL$(generation$, 9, " ") + " บ"
    Print "บ Clan: " + MakeFitL$(clan_string$, 30, " ") + " บ Age: " + MakeFitL$(age$, 32, " ") + " บ"
    Print "ฬออออออออออออออออออออออออออออออออออออออน Player: " + MakeFitL$(player$, 29, " ") + " บ"
    Print "บ              Attributes              บ Chronicle: " + MakeFitL$(chronicle$, 26, " ") + " บ"
    Print "บ   Physical     Social      Mental    บ Haven: " + MakeFitL$(haven$, 30, " ") + " บ"
    Print "บ Str. " + MakeFitL$(Str$(ch.attr_strength), 7, " ") + " App. " + MakeFitL$(Str$(ch.attr_appearance), 7, " ") + " Int. " + MakeFitL$(Str$(ch.attr_intelligence), 5, " ") + " บ Concept: " + MakeFitL$(concept$, 28, " ") + " บ"
    Print "บ Dex. " + MakeFitL$(Str$(ch.attr_dexterity), 7, " ") + " Cha. " + MakeFitL$(Str$(ch.attr_charisma), 7, " ") + " Per. " + MakeFitL$(Str$(ch.attr_perception), 5, " ") + " ฬอออออออออออออออออออออออออออออออออออออออน"
    Print "บ Sta. " + MakeFitL$(Str$(ch.attr_stamina), 7, " ") + " Man. " + MakeFitL$(Str$(ch.attr_manipulation), 7, " ") + " Wit. " + MakeFitL$(Str$(ch.attr_wits), 5, " ") + " บ Derangements:                         บ"
    Print "ฬออออออออออออออออออออออออออออออออออออออน Regression,__________________________ บ"
    Print "บ Disciplines:                         บ _____________________________________ บ"
    Print "บ " + MakeFitL$(discipline_strings$(0), 36, " ") + " บ _____________________________________ บ"
    Print "บ " + MakeFitL$(discipline_strings$(1), 36, " ") + " บ _____________________________________ บ"
    Print "บ " + MakeFitL$(discipline_strings$(2), 36, " ") + " บ _____________________________________ บ"
    Print "ฬออออออออออออออออออออออออออออออออออออออฮอออออออออออออออออออออออออออออออออออออออน"
    Print "บ Typhon:  7                           บ Nature: " + MakeFitL$(All_Archetypes(ch.nature), 29, " ") + " บ"
    Print "บ Willpower: 3                         บ Demeanor: " + MakeFitL$(All_Archetypes(ch.demeanor), 27, " ") + " บ"
    Print "ฬออออออออออออออออออออออออออออออออออออออสอออออออออออออออออออออออออออออออออออออออน"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ                        <<PRESS ANY KEY TO CONTINUE>>                         บ"
    Print "ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ"
    Input a
    Print "ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป"
    Print "บ                                  Abilities                                   บ"
    Print "บ          Talents                  Skills                  Knowledges         บ"
    Print "บ Acting:       2            Animal Ken: 1              Bureaucracy:   0       บ"
    Print "บ Alertness:    1            Drive:      1              Computer:      1       บ"
    Print "บ Athletics:    1            Etiquette:  0              Finance:       0       บ"
    Print "บ Brawl:        2            Firearms:   2              Investigation: 0       บ"
    Print "บ Dodge:        3            Melee:      0              Law:           0       บ"
    Print "บ Empathy:      0            Music:      0              Linguistics:   2       บ"
    Print "บ Intimidation: 0            Repair:     2              Medecine:      1       บ"
    Print "บ Leadership:   1            Security:   1              Occult:        0       บ"
    Print "บ Streetwise:   1            Stealth:    2              Politics:      1       บ"
    Print "บ Subterfuge:   2            Survival:   0              Science:       0       บ"
    Print "ฬออออออออออออออออออออออออออออออออออออออหอออออออออออออออออออออออออออออออออออออออน"
    Print "บ Backgrounds:                         บ Virtues:                              บ"
    Print "บ Allies                               บ Conscience:   0                       บ"
    Print "บ Allies                               บ Conviction:   4                       บ"
    Print "บ Contacts                             บ Instinct:     3                       บ"
    Print "บ Resources                            บ Self-Control: 0                       บ"
    Print "บ Status                               บ Courage:      3                       บ"
    Print "ฬออออออออออออออออออออออออออออออออออออออสอออออออออออออออออออออออออออออออออออออออน"
    Print "บ                        <<PRESS ANY KEY TO CONTINUE>>                         บ"
    Print "ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ"



















    While InKey$ = "": Wend
End Sub

Sub CharacterGeneratorForDummies
    Print "CharacterGeneratorForDummies"
End Sub

Sub CombatComputer
    Print "CombatComputer"
End Sub

Sub DiceRoller
    Print "DiceRoller"
End Sub

Sub RandomCharacterGenerator
    Print "RandomCharacterGenerator"
End Sub

Sub Choice6
    Print "Unnamed choice 6"
End Sub

Sub VehicleGenerator
    Print "VehicleGenerator"
End Sub

Sub Test
    Print "|" + MakeFitL$("a left aligned string", 50, " ") + "|"
    Print "|" + MakeFitC$("a center aligned string", 50, " ") + "|"
    Print "|" + MakeFitR$("a right aligned string", 50, " ") + "|"
    Print "test"
    Print "|" + MakeFitC$("This is a long string", 10, " ") + "|"
    Print "|" + MakeFitC$("hello", 10, " ") + "|"
    Print "|" + MakeFitC$("1234567890", 10, " ") + "|"
    Print "|" + Mid$("1234567890", 1, 10) + "|" '  123456789
    Print "|" + Mid$("12345678901", 1, 10) + "|" ' 123456789
    Print "|" + Mid$("A1234567890", 2, 10) + "|" ' A123456789
    Print "|" + Mid$("A1234567890Z", 2, 10) + "|" 'A123456789

End Sub


