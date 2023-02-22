$Debug
' Setup
' TODO: See if other combinations of clan and other variables cause sub questions.
Randomize Timer

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
Const All_Natures_Count = 30
Dim Shared All_Natures(1 To All_Natures_Count) As String
All_Natures(1) = "Architect"
All_Natures(2) = "Autocrat"
All_Natures(3) = "Barbarian"
All_Natures(4) = "Bon Vivant"
All_Natures(5) = "Bravo"
All_Natures(6) = "Caregiver"
All_Natures(7) = "Caretaker"
All_Natures(8) = "Celebrant"
All_Natures(9) = "Child"
All_Natures(10) = "Conformist"
All_Natures(11) = "Conniver"
All_Natures(12) = "Curmudgeon"
All_Natures(13) = "Defender"
All_Natures(14) = "Deviant"
All_Natures(15) = "Director"
All_Natures(16) = "Fanatic"
All_Natures(17) = "Gallant"
All_Natures(18) = "Innovator"
All_Natures(19) = "Jester"
All_Natures(20) = "Judge"
All_Natures(21) = "Loner"
All_Natures(22) = "Martyr"
All_Natures(23) = "Monster"
All_Natures(24) = "Penitent"
All_Natures(25) = "Rebel"
All_Natures(26) = "Rogue"
All_Natures(27) = "Survivor"
All_Natures(28) = "Traditionalist"
All_Natures(29) = "Tyrant"
All_Natures(30) = "Visionary"

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
        Print MakeFit$(Str$(i), index_length, " ") + " = " + MakeFitR$(items(i), max_item_length, " ");
    Next
    Print MakeFit$("0", index_length, " ") + " = " + MakeFitR$("Random", max_item_length, " ")
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
        Print MakeFit$(Str$(i), max_index_length, " ") + " = " + MakeFitR$(items(i), max_item_length, " ") + MakeFit$(Str$(values(i)), max_value_length, " ");
    Next
    Print MakeFit$("0", index_length, " ") + " = " + MakeFitR$("Random", max_item_length, " ")
End Sub

Function MakeFit$ (text As String, length As Integer, pad As String)
    MakeFit = Right$(String$(length, pad) + text, length)
End Function

Function MakeFitR$ (text As String, length As Integer, pad As String)
    MakeFitR = Left$(text + String$(length, pad), length)
End Function

Function MaxI (val1 As Integer, val2 As Integer)
    If (val1 > val2) Then
        MaxI = val1
    Else
        MaxI = val2
    End If
End Function

Sub CharacterGenerator ()
    Input "What is the character's name? ", name$
    Input "Who is the player? ", player$
    Input "What chronicle is the character going to be used for? ", chronicle$
    Input "What is the character's Haven? ", haven$
    Input "What is the character's concept? ", concept$
    Input "How old is the character? ", age$
    Print "What is the sex of the character? 1 = Male  2 = Female 0 = Random"
    sex = GetChoice(0, 2)
    If sex > 2 Or sex < 1 Then sex = GetRandomInt(1, 2)
    Cls
    Print "What Clan is the character from?"
    Call PrintMenu(All_Clans(), All_Clans_Count)
    clan = GetChoice(0, All_Clans_Count)
    If clan > All_Clans_Count Or clan < 1 Then clan = GetRandomInt(1, All_Clans_Count)
    Cls
    Print "What is your character's Nature?"
    Call PrintMenu(All_Natures(), All_Natures_Count)
    nature = GetChoice(0, All_Natures_Count)
    If nature > All_Natures_Count Or nature < 1 Then nature = GetRandomInt(1, All_Natures_Count)
    Cls
    Print "What is your character's Demeanor?"
    Call PrintMenu(All_Natures(), All_Natures_Count)
    demeanor = GetChoice(0, All_Natures_Count)
    If demeanor > All_Natures_Count Or demeanor < 1 Then demeanor = GetRandomInt(1, All_Natures_Count)

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

    ' TODO: Choose primary/secondary/tertiary attributes
    'Print "1 = Physical 2 = Social   3 = Mental 0 = Random"
    'Print "Which is your primary Attribute? "
    'Print "Which is your secondary attribute? "
    'Print "Which is your tertiary attribute? "

    ' TODO: Spend attribute points order should be physical mental social not primary secondary tertiary
    'Print "Your mental attributes are:"
    'Print "Intelligence 1 Perception 1 Wits 1"
    'Print "Which would you like to add 1 of your 7 points to?"
    'Print "1 = Intelligence 2 = Perception   3 = Wits         0 = Random"

    'Print "Your physical attributes are:"
    'Print "Strength 1 Dexterity 1 Stamina 1"
    'Print "Which would you like to add 1 of your 5 points to?"
    'Print "1 = Strength     2 = Dexterity    3 = Stamina      0 = Random"

    'Print "Your social attributes are:"
    'Print "Appearance 1 Charisma 1 Manipulation 1"
    'Print "Which would you like to add 1 of your 3 points to?"
    'Print "1 = Appearance   2 = Charisma     3 = Manipulation 0 = Random"

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
    'ษออออออออออออออออออออออออออออออออออออออหอออออออออออออออออออออออออออออออออออออออป
    'บ Name: Steve                          บ Sex: Male Generation 13               บ
    'บ Clan: Giovanni                       บ Age: 182                              บ
    'ฬออออออออออออออออออออออออออออออออออออออน Player: kevin                         บ
    'บ              Attributes              บ Chronicle: chron                      บ
    'บ   Physical     Social      Mental    บ Haven: haven                          บ
    'บ Str. 3       App. 3       Int. 4     บ Concept: concept                      บ
    'บ Dex. 3       Cha. 1       Per. 4     ฬอออออออออออออออออออออออออออออออออออออออน
    'บ Sta. 2       Man. 2       Wit. 2     บ Derangements:                         บ
    'ฬออออออออออออออออออออออออออออออออออออออน _______                               บ
    'บ Disciplines:                         บ _______                               บ
    'บ Thaumaturgy                          บ _______                               บ
    'บ Fortitude                            บ _______                               บ
    'บ Celerity                             บ _______                               บ
    'ฬออออออออออออออออออออออออออออออออออออออฮอออออออออออออออออออออออออออออออออออออออน
    'บ Heaven: 6                            บ Nature: Architect                     บ
    'บ Willpower: 4                         บ Demeanor: Autocrat                    บ
    'ฬออออออออออออออออออออออออออออออออออออออสอออออออออออออออออออออออออออออออออออออออน
    'บ                                                                              บ
    'บ                                                                              บ
    'บ                                                                              บ
    'บ                        <<PRESS ANY KEY TO CONTINUE>>                         บ
    'ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ

    '|------------------------------------------------------------------------------|
    '|                              Abilities                                       |
    '|   Talents                    Skills                  Knowledges
    '| Acting: 0       Animal Ken: 0 Bureaucracy: 0
    '| Alertness: 0    Drive: 0      Computer: 0
    '| Athletics: 0    Etiquette: 0  Finance: 0
    '| Brawl: 0        Firearms: 0   Investigation: 0
    '| Dodge: 0        Melee: 0      Law: 0
    '| Empathy: 0      Music: 0      Linguistics: 0
    '| Intimidation: 0 Repair: 0     Medicine: 0
    '| Leadership: 0   Security: 0   Occult: 0
    '| Streetwise: 0   Stealth: 0    Politics: 0
    '| Subterfuge: 0   Survival: 0   Science: 0
    '|---|---|
    '| Backgrounds: | Virtues:
    '| Status       | Conscience: 3
    '| Resources    | Conviction: 0
    '| Status       | Instinct: 0
    '| Contacts     | Self-Control: 3
    '| Retainers    | Courage: 4
    '|------|---|
    '| <<PRESS ANY KEY TO CONTINUE>>
    '|----|
    ' Do you want to save the character to a file? (Y/N)
    ' Where do you want the file to be saved? (default is C:\Windows\Desktop)?
    ' What do you want the file to be called? (default is CHAR1)?




















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



