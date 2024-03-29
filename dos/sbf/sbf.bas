$Debug
' Setup
Randomize Timer

Const FALSE = 0
Const TRUE = Not FALSE
Const isDebugging = TRUE

Const INITIAL_GENERATION = 13

'$include: 'colors.bi'
'$include: 'menus.bi'
'$include: 'character.bi'

Const RANK_PRIMARY = 1
Const RANK_PRIMARY_LABEL = "Primary"
Const RANK_SECONDARY = 2
Const RANK_SECONDARY_LABEL = "Secondary"
Const RANK_TERTIARY = 3
Const RANK_TERTIARY_LABEL = "Tertiary"
Const RANKS_COUNT = 3

Type RankType
    id As Integer
    label As String
End Type
Dim Shared Ranks(1 To RANKS_COUNT) As RankType

Type AbilityType
    id As Integer
    singular As String
    plural As String
End Type

Const ABILITY_TALENTS_ID = 1
Const ABILITY_TALENTS_SINGULAR = "Talent"
Const ABILITY_TALENTS_PLURAL = "Talents"
Const ABILITY_SKILLS_ID = 2
Const ABILITY_SKILLS_SINGULAR = "Skill"
Const ABILITY_SKILLS_PLURAL = "Skills"
Const ABILITY_KNOWLEDGES_ID = 3
Const ABILITY_KNOWLEDGES_SINGULAR = "Knowledge"
Const ABILITY_KNOWLEDGES_PLURAL = "Knowledges"
Const ABILITIES_COUNT = 3
Dim Shared Abilities(1 To ABILITIES_COUNT) As AbilityType

Call InitializeMemory

' Run "tests" at startup. Uncomment the end instruction to see the output and not run the rest of the program.
Call Test
Call SplashScreen
Call MainMenu

' This initializes shared variables.
Sub InitializeMemory
    Call Initialize_Character_Lib

    Dim rank As RankType
    Call NewRank(rank, RANK_PRIMARY, RANK_PRIMARY_LABEL)
    Ranks(RANK_PRIMARY) = rank
    Call NewRank(rank, RANK_SECONDARY, RANK_SECONDARY_LABEL)
    Ranks(RANK_SECONDARY) = rank
    Call NewRank(rank, RANK_TERTIARY, RANK_TERTIARY_LABEL)
    Ranks(RANK_TERTIARY) = rank

    Dim ability As AbilityType
    Call NewAbility(ability, ABILITY_TALENTS_ID, ABILITY_TALENTS_SINGULAR, ABILITY_TALENTS_PLURAL)
    Abilities(ABILITY_TALENTS_ID) = ability
    Call NewAbility(ability, ABILITY_SKILLS_ID, ABILITY_SKILLS_SINGULAR, ABILITY_SKILLS_PLURAL)
    Abilities(ABILITY_SKILLS_ID) = ability
    Call NewAbility(ability, ABILITY_KNOWLEDGES_ID, ABILITY_SKILLS_SINGULAR, ABILITY_SKILLS_PLURAL)
    Abilities(ABILITY_KNOWLEDGES_ID) = ability
End Sub

Sub NewAbility (ability As AbilityType, id As Integer, singular As String, plural As String)
    ability.id = id
    ability.singular = singular
    ability.plural = plural
End Sub

Sub NewRank (rank As RankType, id As Integer, label As String)
    rank.id = id
    rank.label = label
End Sub

Sub SplashScreen
    ' Splash screen
    MaybeCls
    '     "                                                                                "
    Print "Welcome to Tom's Storyteller's Best Friend. This is a program that is meant to"
    Print "aid storytellers in running Vampire: the Masquerade Chronicles and Vampire: the"
    Print "Dark Ages Chronicles. This program could aid in running campaigns for other"
    Print "role-playing games especially those from White Wolf(tm). If you would like"
    Print "anything added please open a github issue. https://github.com/headhunter45/sbf"
    Print "     Press any key to continue"
    While InKey$ = ""
    Wend
End Sub

Sub MainMenu
    ' Main menu
    choice = 0
    Do
        MaybeCls
        Print "浜様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様融"
        Print "� What are you going to do?                                                    �"
        Print "�        1 = Character Generator                                               �"
        Print "�        2 = Character Generator for Dummies                                   �"
        Print "�        3 = Combat Computer                                                   �"
        Print "�        4 = Dice Roller                                                       �"
        Print "�        5 = Random Character Generator                                        �"
        Print "�        6 =                                                                   �"
        Print "�        7 = Vehicle Generator                                                 �"
        Print "�                                                                              �"
        Print "�                                                                              �"
        Print "�                                                                              �"
        Print "�                                                                              �"
        Print "�                                                                              �"
        Print "�                                                                              �"
        Print "�                                                                              �"
        Print "�                                                                              �"
        Print "�                                                                              �"
        Print "�                                                                              �"
        Print "�                                                                              �"
        Print "�        0 = End                                                               �"
        Print "�                                                                              �"
        Print "藩様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様夕"
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
End Sub

' This sub is not called. It is here so it can be copied whenever I need to make a new bordered screen.
Sub BlankScreen
    Print "浜様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様融"
    Print "�                                                                              �"
    Print "�                                                                              �"
    Print "�                                                                              �"
    Print "�                                                                              �"
    Print "�                                                                              �"
    Print "�                                                                              �"
    Print "�                                                                              �"
    Print "�                                                                              �"
    Print "�                                                                              �"
    Print "�                                                                              �"
    Print "�                                                                              �"
    Print "�                                                                              �"
    Print "�                                                                              �"
    Print "�                                                                              �"
    Print "�                                                                              �"
    Print "�                                                                              �"
    Print "�                                                                              �"
    Print "�                                                                              �"
    Print "�                                                                              �"
    Print "�                                                                              �"
    Print "�                                                                              �"
    Print "藩様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様夕"
End Sub

Function GetChoice (min As Integer, max As Integer)
    Dim choice
    Do
        Input choice
    Loop Until choice <= max And choice >= min
    GetChoice = choice
End Function

Function GetMenuChoice (items() As MenuItem, style As MenuStyle, count As Integer)
    ' Only allow random id or an id from a visible menuitem.
    choice = -1
    acceptChoice = FALSE
    Do
        Input choice
        If style.showRandom And choice = style.randomItemId Then acceptChoice = TRUE
        If style.showCancel And choice = style.cancelItemId Then acceptChoice = TRUE
        For i = 1 To count
            If choice = items(i).id And items(i).isVisible Then
                acceptChoice = TRUE
                Exit For
            End If
        Next
    Loop Until acceptChoice
    GetMenuChoice = choice
End Function

Function GetRandomInt (min As Integer, max As Integer)
    GetRandomInt = Int(Rnd * (max - min + 1)) + min
End Function

Function MaxI (val1 As Integer, val2 As Integer)
    If (val1 > val2) Then
        MaxI = val1
    Else
        MaxI = val2
    End If
End Function

Function ChooseStringId (labels() As String, style As MenuStyle, count As Integer, prompt As String)
    MaybeCls
    ReDim mnuItems(1 To count) As MenuItem
    Call BuildMenu(mnuItems(), labels(), count)
    Call AdjustMenuStyle(style, mnuItems(), count, TRUE)
    Print prompt
    Call PrintMenu(mnuItems(), count, style)
    choice = GetMenuChoice(mnuItems(), style, count)
    If choice = style.randomItemId Then choice = GetRandomMenuItemId(mnuItems(), count)
    ChooseStringId = choice
End Function

Function ChooseStringIdWithValues (labels() As String, values() As Integer, style As MenuStyle, count As Integer, prompt As String)
    MaybeCls
    Dim mnuItems(1 To count) As MenuItem
    Call BuildMenuWithValues(mnuItems(), labels(), values(), count)
    Call AdjustMenuStyle(style, mnuItems(), count, FALSE)
    Print prompt
    Call PrintMenu(mnuItems(), count, style)
    choice = GetMenuChoice(mnuItems(), style, count)
    If choice = style.randomItemId Then choice = GetRandomMenuItemId(mnuItems(), count)
    ChooseStringIdWithValues = choice
End Function

Function ChooseStringIdWithColors (labels() As String, colors() As Integer, style As MenuStyle, prompt As String)
    MaybeCls
    ' Check array bounds
    If LBound(labels) <> 1 Or LBound(colors) <> 1 Or UBound(labels) <> UBound(colors) Then
        ChooseStringIdWithColors = -1
        End
    End If

    count = UBound(labels)
    Dim mnuItems(1 To count) As MenuItem
    Call BuildMenuWithColors(mnuItems(), labels(), colors())
    Call AdjustMenuStyle(style, mnuItems(), count, TRUE)
    Print prompt
    Call PrintMenu(mnuItems(), count, style)
    choice = GetMenuChoice(mnuItems(), style, count)
    If choice = style.randomItemId Then choice = GetRandomMenuItemId(mnuItems(), count)
    ChooseStringIdWithColors = choice
End Function

Function ChooseMenuItemId (items() As MenuItem, style As MenuStyle, count As Integer, prompt As String, ignoreValue As Integer)
    MaybeCls
    Call AdjustMenuStyle(style, items(), count, ignoreValue)
    Print prompt
    Call PrintMenu(items(), count, style)
    choice = GetMenuChoice(items(), style, count)
    If choice = style.randomItemId Then choice = GetRandomMenuItemId(items(), count)
    ChooseMenuItemId = choice
End Function

Sub CGGetHeader (ch As CharacterType)
    MaybeCls
    Dim ms As MenuStyle
    Call NewMenuStyle(ms)
    Input "What is the character's name? ", ch.name
    Input "Who is the player? ", ch.player
    Input "What chronicle is the character going to be used for? ", ch.chronicle
    Input "What is the character's Haven? ", ch.haven
    Input "What is the character's concept? ", ch.concept
    Input "How old is the character? ", ch.age
    ch.gender = ChooseStringId(Genders(), ms, GENDERS_COUNT, "What is the character's gender?")
    ch.clan = ChooseStringId(Clans(), ms, CLANS_COUNT, "What clan is the character from?")
    ch.nature = ChooseStringId(Archetypes(), ms, ARCHETYPES_COUNT, "What is the character's nature?")
    ch.demeanor = ChooseStringId(Archetypes(), ms, ARCHETYPES_COUNT, "What is the character's demeanor?")
End Sub

Sub CGGetDisciplines (ch As CharacterType)
    ' Spend discipline points.
    Dim ms As MenuStyle
    Call NewMenuStyle(ms)
    disciplinePoints = GetDisciplinePoints
    Dim disciplineValues(1 To DISCIPLINES_COUNT) As Integer
    While disciplinePoints > 0
        MaybeCls
        Call FillDisciplines(ch, disciplineValues())
        discipline = ChooseStringIdWithValues(Disciplines(), disciplineValues(), ms, DISCIPLINES_COUNT, "Which discipline do you want to spend 1 of your " + itos$(disciplinePoints) + " points on?")
        Call SetDiscipline(ch, discipline, GetDiscipline(ch, discipline) + 1)
        disciplinePoints = disciplinePoints - 1
    Wend
End Sub

Sub CGGetAttributes (ch As CharacterType)
    Dim msWithoutValues As MenuStyle
    Call NewMenuStyle(msWithoutValues)
    Dim msWithValues As MenuStyle
    Call NewMenuStyle(msWithValues)
    Dim attributeRanks(1 To ATTRIBUTE_GROUPS_COUNT) As Integer

    ' Attribute groups menu (physical/social/mental)
    Dim mnuAttributeGroups(1 To ATTRIBUTE_GROUPS_COUNT) As MenuItem
    Dim mi As MenuItem
    For i = 1 To ATTRIBUTE_GROUPS_COUNT
        Call NewMenuItem(mi, AttributeGroups(i), i)
        mnuAttributeGroups(i) = mi
    Next

    ' Choose attribute group priorities.
    groupSum = 0
    rankSum = 1
    For i = 1 To ATTRIBUTE_GROUPS_COUNT - 1
        nextGroup = ChooseMenuItemId(mnuAttributeGroups(), msWithoutValues, ATTRIBUTE_GROUPS_COUNT, "Choose your " + LCase$(Ranks(i).label) + " attribute?", TRUE)
        mnuAttributeGroups(nextGroup).isVisible = FALSE
        attributeRanks(nextGroup) = i
        rankSum = rankSum + i + 1
        groupSum = groupSum + nextGroup
    Next
    ' General formula for last choice given 1 to count based indexing is this
    ' (Sum from 1 to count) - (Sum of all previous choice IDs)
    ' Sum(1..AllAttributesCount)-Sum(Choice[1]..Choice[AllAttributesCount-1])
    lastGroup = rankSum - groupSum
    attributeRanks(lastGroup) = ATTRIBUTE_GROUPS_COUNT

    ' Spend attribute points
    For group = 1 To ATTRIBUTE_GROUPS_COUNT
        count = GetNumAttributesInGroup(group)
        ReDim attributes(1 To count) As String
        Call FillAttributesInGroup(group, attributes())
        rank = attributeRanks(group)
        ReDim values(1 To count) As Integer
        For attrPoints = GetAttributePointsForRank(rank) To 1 Step -1
            Call FillAttributeValues(ch, values(), group)
            attribute = ChooseStringIdWithValues(attributes(), values(), msWithValues, count, "Which " + LCase$(AttributeGroups(group)) + " attribute do you want to spend 1 of your " + itos$(attrPoints) + " points on?")
            Call SetAttributeValue(ch, group, attribute, GetAttributeValue(ch, group, attribute) + 1)
        Next
    Next
End Sub

Sub CGGetAbilities (ch As CharacterType)
    Dim msWithoutValues As MenuStyle
    Call NewMenuStyle(msWithoutValues)
    Dim msWithValues As MenuStyle
    Call NewMenuStyle(msWithValues)
    Dim abilityRanks(1 To ABILITY_GROUPS_COUNT) As Integer

    ' Ability groups menu (talents/skills/knowledges)
    Dim mnuAbilityGroups(1 To ABILITY_GROUPS_COUNT) As MenuItem
    Dim mi As MenuItem
    For i = 1 To ABILITY_GROUPS_COUNT
        Call NewMenuItem(mi, AbilityGroups(i), i)
        mnuAbilityGroups(i) = mi
    Next

    ' Choose ability group priorities
    groupSum = 0
    rankSum = 1
    For i = 1 To ABILITY_GROUPS_COUNT - 1
        nextAbility = ChooseMenuItemId(mnuAbilityGroups(), msWithoutValues, ABILITY_GROUPS_COUNT, "Choose your " + LCase$(Ranks(i).label) + " ability?", TRUE)
        mnuAbilityGroups(nextAbility).isVisible = FALSE
        abilityRanks(nextAbility) = i
        rankSum = rankSum + i + 1
        groupSum = groupSum + nextAbility
    Next
    ' General formula for last choice given 1 to count based indexing is this
    ' (Sum from 1 to count) - (Sum of all previous choice IDs)
    ' Sum(1..AllAttributesCount)-Sum(Choice[1]..Choice[AllAttributesCount-1])
    lastGroup = rankSum - groupSum
    abilityRanks(lastGroup) = ABILITY_GROUPS_COUNT

    ' Spend ability points
    For group = 1 To ABILITY_GROUPS_COUNT
        count = GetNumItemsForAbilityGroup(group)
        ReDim abilityNames(1 To count) As String
        Call FillAbilitiesForAbilityGroup(group, abilityNames())
        rank = abilityRanks(group)
        ReDim values(1 To count) As Integer
        For abilityPoints = GetAbilityPointsForRank(rank) To 1 Step -1
            Call FillAbilityValues(ch, values(), group)
            ability = ChooseStringIdWithValues(abilityNames(), values(), msWithValues, count, "Which " + LCase$(Abilities(i).singular) + " would you like to spend 1 of your " + itos$(abilityPoints) + " points on?")
            Call SetAbilityValue(ch, group, ability, GetAbilityValue(ch, group, ability) + 1)
        Next
    Next
End Sub

Sub CGGetBackgrounds (ch As CharacterType)
    ' Spend background points
    Dim ms As MenuStyle
    Call NewMenuStyle(ms)
    backgroundPoints = GetBackgroundPoints
    Dim backgroundValues(1 To BACKGROUNDS_COUNT) As Integer
    While backgroundPoints > 0
        MaybeCls
        Call FillBackgrounds(ch, backgroundValues())
        background = ChooseStringIdWithValues(Backgrounds(), backgroundValues(), ms, BACKGROUNDS_COUNT, "Which background do you want to spend 1 of your " + itos$(backgroundPoints) + " points on?")
        Call SetBackground(ch, background, GetBackground(ch, background) + 1)
        backgroundPoints = backgroundPoints - 1
    Wend
End Sub

Sub CGGetRoad (ch As CharacterType)
    ch.roadName = "Humanity"
End Sub

Sub CGSpendVirtuePoints (ch As CharacterType)
    ' Spend virtue points
    Dim ms As MenuStyle
    Call NewMenuStyle(ms)
    virtuePoints = GetVirtuePoints

    Dim values(1 To VIRTUES_COUNT) As Integer
    While virtuePoints > 0
        Call FillVirtues(ch, values())
        virtue = ChooseStringIdWithValues(Virtues(), values(), ms, VIRTUES_COUNT, "Which virtue do you want to spend 1 of your " + itos$(virtuePoints) + " points on?")
        Call SetVirtue(ch, virtue, GetVirtue(ch, virtue) + 1)
        virtuePoints = virtuePoints - 1
    Wend
End Sub

Sub CGGetDerangement (ch As CharacterType)
    If ch.clan = CLAN_MALKAVIAN Then
        ' If the clan is malkavian then pick a derangement.
        Dim ms As MenuStyle
        Call NewMenuStyle(ms)
        ms.useColors = TRUE

        ch.derangementId = ChooseStringIdWithColors(DerangementLabels(), DerangementColors(), ms, "Which derangement do you want?")
    End If
End Sub

Sub CGSpendFreebiePoints (ch As CharacterType)
    freebiePoints = GetFreebiePoints(ch)
    Dim ms As MenuStyle
    Call NewMenuStyle(ms)
    While (freebiePoints > 0)
        MaybeCls
        Call MaybePrint("freebiePoints = " + itos$(freebiePoints))
        ' Build the menu
        ReDim availableFreebies(1 To FREEBIES_COUNT) As FreebieType
        numAvailableFreebies = 0
        For index = 1 To FREEBIES_COUNT
            If Freebies(index).cost <= freebiePoints Then
                numAvailableFreebies = numAvailableFreebies + 1
                availableFreebies(numAvailableFreebies) = Freebies(index)
            End If
        Next

        ReDim menuItems(1 To numAvailableFreebies) As MenuItem
        For index = 1 To numAvailableFreebies
            Dim mi As MenuItem
            Call NewMenuItem(mi, availableFreebies(index).label, availableFreebies(index).id)
            If index = FREEBIE_SHOW_CHARACTER_SHEET_ID Then mi.includeInRandom = FALSE
            menuItems(index) = mi
        Next

        prompt$ = "You have " + itos$(freebiePoints) + " freebie points remaining what would you like to spend the points on?"
        id = ChooseMenuItemId(menuItems(), ms, numAvailableFreebies, prompt$, TRUE)

        Select Case id
            Case FREEBIE_DISCIPLINE_ID
                Call CGSpendDisciplinePoint(ch)
            Case FREEBIE_ATTRIBUTE_ID
                Call CGSpendAttributePoint(ch)
            Case FREEBIE_ABILITY_ID
                Call CGSpendAbilityPoint(ch)
            Case FREEBIE_VIRTUE_ID
                Call CGSpendVirtuePoint(ch)
            Case FREEBIE_HUMANITY_ID
                Call CGSpendHumanityPoint(ch)
            Case FREEBIE_BACKGROUND_ID
                Call CGSpendBackgroundPoint(ch)
            Case FREEBIE_SHOW_CHARACTER_SHEET_ID
                Call ShowCharacterSheet(ch)
        End Select

        freebiePoints = GetFreebiePoints(ch)
        Call MaybePrint("Auspex: " + itos$(GetDiscipline(ch, DISCIPLINE_AUSPEX)))
        Call MaybePrint("Strength: " + itos$(GetAttributeValue(ch, ATTRIBUTE_GROUP_PHYSICAL, ATTRIBUTE_STRENGTH)))
        Call MaybePrint("Acting: " + itos$(GetAbilityValue(ch, ABILITY_TALENTS_ID, TALENT_ACTING)))
        Call MaybePrint("Conscience: " + itos$(GetVirtue(ch, VIRTUE_CONSCIENCE)))
        Call MaybePrint("Humanity: " + itos$(GetRoadValue(ch)))
        Call MaybePrint("Generation (Background): " + itos$(GetBackground(ch, BACKGROUND_GENERATION)))
        Call MaybePrint("Generation: " + itos$(GetGeneration(ch)))
    Wend
End Sub

Sub CGSpendDisciplinePoint (ch As CharacterType)
    MaybeCls
    Dim ms As MenuStyle
    Call NewMenuStyle(ms)
    ms.showCancel = TRUE
    ms.cancelItemId = DISCIPLINES_COUNT + 1
    Dim disciplineValues(1 To DISCIPLINES_COUNT) As Integer
    Call FillDisciplines(ch, disciplineValues())
    prompt$ = "Which discipline do you want to spend 1 of your " + itos$(disciplinePoints) + " points on?"
    id = ChooseStringIdWithValues(Disciplines(), disciplineValues(), ms, DISCIPLINES_COUNT, prompt$)
    If id <> ms.cancelItemId Then
        Call SetDiscipline(ch, id, GetDiscipline(ch, id) + 1)
        Call SetFreebiePoints(ch, GetFreebiePoints(ch) - FREEBIE_DISCIPLINE_COST)
    End If
End Sub

Type GroupedStatReference
    id As Integer
    groupIndex As Integer
    itemIndex As Integer
End Type

Sub NewGroupedStatReference (ref As GroupedStatReference, id As Integer, groupIndex As Integer, itemIndex As Integer)
    ref.id = id
    ref.groupIndex = groupIndex
    ref.itemIndex = itemIndex
End Sub

Sub CGSpendAttributePoint (ch As CharacterType)
    MaybeCls
    Dim ms As MenuStyle
    Call NewMenuStyle(ms)
    ms.showCancel = TRUE
    numAttributes = 0
    Dim numAttributesInGroup(1 To ATTRIBUTE_GROUPS_COUNT) As Integer

    For attributeGroupIndex = 1 To ATTRIBUTE_GROUPS_COUNT
        numAttributesInGroup(attributeGroupIndex) = GetNumAttributesInGroup(attributeGroupIndex)
        numAttributes = numAttributes + numAttributesInGroup(attributeGroupIndex)
    Next

    Dim attributes(1 To numAttributes) As GroupedStatReference
    Dim labels(1 To numAttributes) As String
    Dim values(1 To numAttributes) As Integer

    attributeIndex = 1
    For attributeGroupIndex = 1 To ATTRIBUTE_GROUPS_COUNT
        For index = 1 To numAttributesInGroup(attributeGroupIndex)
            Dim attribute As GroupedStatReference
            Call NewGroupedStatReference(attribute, attributeIndex, attributeGroupIndex, index)
            attributes(attributeIndex) = attribute
            labels(attributeIndex) = GetAttributeName$(attributeGroupIndex, index)
            values(attributeIndex) = GetAttributeValue(ch, attributeGroupIndex, index)
            attributeIndex = attributeIndex + 1
        Next
    Next

    ' TODO: Make this show values.
    prompt$ = "Which attribute do you want to add one dot to?"
    ms.cancelItemId = numAttributes + 1
    id = ChooseStringIdWithValues(labels(), values(), ms, numAttributes, prompt$)
    If id <> ms.cancelItemId Then
        Dim attr As GroupedStatReference
        attr = attributes(id)
        Call SetAttributeValue(ch, attr.groupIndex, attr.itemIndex, GetAttributeValue(ch, attr.groupIndex, attr.itemIndex) + 1)
        Call SetFreebiePoints(ch, GetFreebiePoints(ch) - FREEBIE_ATTRIBUTE_COST)
    End If
End Sub

Sub CGSpendAbilityPoint (ch As CharacterType)
    Dim ms As MenuStyle
    Call NewMenuStyle(ms)
    ms.showCancel = TRUE
    done = FALSE
    While Not done
        MaybeCls
        ms.cancelItemId = ABILITY_GROUPS_COUNT + 1
        abilityGroupIndex = ChooseStringId(AbilityGroups(), ms, ABILITY_GROUPS_COUNT, "What kind of ability would you like to add 1 dot to?")
        If abilityGroupIndex = ms.cancelItemId Then Exit Sub

        numAbilities = GetNumItemsForAbilityGroup(abilityGroupIndex)
        Dim labels(1 To numAbilities) As String
        Call FillAbilitiesForAbilityGroup(abilityGroupIndex, labels())
        ms.cancelItemId = numAbilities + 1
        abilityIndex = ChooseStringId(labels(), ms, numAbilities, "What ability would you like to add 1 dot to?")
        If abilityIndex <> ms.cancelItemId Then
            Call SetAbilityValue(ch, abilityGroupIndex, abilityIndex, GetAbilityValue(ch, abilityGroupIndex, abilityIndex) + 1)
            Call SetFreebiePoints(ch, GetFreebiePoints(ch) - FREEBIE_ABILITY_COST)
            done = TRUE
        End If
    Wend
End Sub

Sub CGSpendVirtuePoint (ch As CharacterType)
    Dim ms As MenuStyle
    Call NewMenuStyle(ms)
    ms.showCancel = TRUE
    ms.cancelItemId = VIRTUES_COUNT + 1
    prompt$ = "What virtue would you like to add 1 dot to?"
    id = ChooseStringId(Virtues(), ms, VIRTUES_COUNT, prompt$)
    If id <> ms.cancelItemId Then
        Call SetVirtue(ch, id, GetVirtue(ch, id) + 1)
        Call SetFreebiePoints(ch, GetFreebiePoints(ch) - FREEBIE_ABILITY_COST)
    End If
End Sub

Sub CGSpendHumanityPoint (ch As CharacterType)
    numLabels = 2
    Dim labels(1 To numLabels) As String
    labels(1) = "Yes"
    labels(2) = "No"
    Dim ms As MenuStyle
    Call NewMenuStyle(ms)
    ms.showRandom = FALSE
    prompt$ = "Are you sure you want to add a dot to " + GetRoadName$(ch) + "?"
    id = ChooseStringId(labels(), ms, numLabels, prompt$)
    If id = 1 Then
        Call SetRoadValue(ch, GetRoadValue(ch) + 1)
        Call SetFreebiePoints(ch, GetFreebiePoints(ch) - FREEBIE_HUMANITY_COST)
    End If
End Sub

Sub CGSpendBackgroundPoint (ch As CharacterType)
    Dim ms As MenuStyle
    Call NewMenuStyle(ms)
    ms.showCancel = TRUE
    ms.cancelItemId = BACKGROUNDS_COUNT + 1
    prompt$ = "Which background would you like to add 1 dot to?"
    id = ChooseStringId(Backgrounds(), ms, BACKGROUNDS_COUNT, prompt$)
    If id <> ms.cancelItemId Then
        Call SetBackground(ch, id, GetBackground(ch, id) + 1)
        Call SetFreebiePoints(ch, GetFreebiePoints(ch) - FREEBIE_BACKGROUND_COST)
    End If
End Sub

Sub SaveCharacterSheet (ch As CharacterType)
    Call MaybePrint("TODO: Fill in SaveCharacterSheet")
    Call MaybePrint(ch.name)
    ' Where do you want the file to be saved? (default is C:\Windows\Desktop)?
    ' What do you want the file to be called? (default is CHAR1)?

    'CHAR1.TXT
    '/------------------------------------------------------------------------------\
    '| Name: sadf                           | Sex: Male       Generation: 12        |
    '| Clan: Brujah                         | Age: mmmmmm                           |
    '|--------------------------------------| Player: fdsa                          |
    '|              Attributes              | Chronicle: jfjf                       |
    '|   Physical     Social      Mental    | Haven: kkkkkk                         |
    '| Str. 5       App. 2       Int. 1     | Concept: llllll                       |
    '| Dex. 3       Cha. 2       Per. 1     |---------------------------------------|
    '| Sta. 2       Man. 4       Wit. 4     | Derangementss:                         |
    '|--------------------------------------| _____________________________________ |
    '| Disciplines:                         | _____________________________________ |
    '| Obtenebration                        | _____________________________________ |
    '| Obtenebration                        | _____________________________________ |
    '| Obtenebration                        | _____________________________________ |
    '|------------------------------------------------------------------------------|
    '| Beast:  8                            | Nature: Fanatic                       |
    '| Willpower: 2                         | Demeanor: Architect                   |
    '|------------------------------------------------------------------------------|
    '|                                  Abilities                                   |
    '|          Talents                  Skills                  Knowledges         |
    '| Acting:       6            Animal Ken: 2              Bureaucracy:   1       |
    '| Alertness:    2            Drive:      2              Computer:      2       |
    '| Athletics:    2            Etiquette:  2              Finance:       1       |
    '| Brawl:        1            Firearms:   1              Investigation: 1       |
    '| Dodge:        1            Melee:      1              Law:           0       |
    '| Empathy:      1            Music:      1              Linguistics:   0       |
    '| Intimidation: 0            Repair:     0              Medecine:      0       |
    '| Leadership:   0            Security:   0              Occult:        0       |
    '| Streetwise:   0            Stealth:    0              Politics:      0       |
    '| Subterfuge:   0            Survival:   0              Science:       0       |
    '|------------------------------------------------------------------------------|
    '| Backgrounds:                         | Virtues:                              |
    '| Allies                               | Conscience:   0                       |
    '| Contacts                             | Conviction:   3                       |
    '| Contacts                             | Instinct:     5                       |
    '| Fame                                 | Self-Control: 0                       |
    '| Generation                           | Courage:      2                       |
    '|--------------------------------------/                                       |
    '|                                                                              |
    '\------------------------------------------------------------------------------/
    'CHAR2.TXT
    '/------------------------------------------------------------------------------\
    '| Name: _______________________________| Sex: Female     Generation: 13        |
    '| Clan: Lasombra                       | Age: ________________________________ |
    '|--------------------------------------| Player: _____________________________ |
    '|              Attributes              | Chronicle: __________________________ |
    '|   Physical     Social      Mental    | Haven: ______________________________ |
    '| Str. 2       App. 3       Int. 3     | Concept: ____________________________ |
    '| Dex. 1       Cha. 2       Per. 5     |---------------------------------------|
    '| Sta. 3       Man. 3       Wit. 2     | Derangements:                         |
    '|--------------------------------------| _____________________________________ |
    '| Disciplines:                         | _____________________________________ |
    '| Vicissitude                          | _____________________________________ |
    '| Spiritus                             | _____________________________________ |
    '| Auspex                               | _____________________________________ |
    '|------------------------------------------------------------------------------|
    '| Chivalry:  7                         | Nature: Autocrat                      |
    '| Willpower: 3                         | Demeanor: Defender                    |
    '|------------------------------------------------------------------------------|
    '|                                  Abilities                                   |
    '|          Talents                  Skills                  Knowledges         |
    '| Acting:       0            Animal Ken: 0              Bureaucracy:   2       |
    '| Alertness:    2            Drive:      0              Computer:      3       |
    '| Athletics:    1            Etiquette:  1              Finance:       2       |
    '| Brawl:        1            Firearms:   1              Investigation: 1       |
    '| Dodge:        2            Melee:      1              Law:           0       |
    '| Empathy:      0            Music:      0              Linguistics:   2       |
    '| Intimidation: 1            Repair:     1              Medecine:      1       |
    '| Leadership:   0            Security:   1              Occult:        1       |
    '| Streetwise:   0            Stealth:    0              Politics:      0       |
    '| Subterfuge:   2            Survival:   0              Science:       1       |
    '|------------------------------------------------------------------------------|
    '| Backgrounds:                         | Virtues:                              |
    '| Contacts                             | Conscience:   2                       |
    '| Influence                            | Conviction:   0                       |
    '| Allies                               | Instinct:     0                       |
    '| Herd                                 | Self-Control: 5                       |
    '| Status                               | Courage:      3                       |
    '|--------------------------------------/                                       |
    '|                                                                              |
    '\------------------------------------------------------------------------------/
    'RANDY.TXT
    '/------------------------------------------------------------------------------\
    '| Name: Randy                          | Sex: Female     Generation: 12        |
    '| Clan: Gangrel                        | Age: ________________________________ |
    '|--------------------------------------| Player: _____________________________ |
    '|              Attributes              | Chronicle: __________________________ |
    '|   Physical     Social      Mental    | Haven: ______________________________ |
    '| Str. 3       App. 1       Int. 2     | Concept: ____________________________         |
    '| Dex. 6       Cha. 3       Per. 3     |---------------------------------------|
    '| Sta. 1       Man. 2       Wit. 3     | Derangements:                         |
    '|--------------------------------------| _____________________________________ |
    '| Disciplines:                         | _____________________________________ |
    '| Animalism                            | _____________________________________ |
    '| Celerity                             | _____________________________________ |
    '| Mortis                               | _____________________________________ |
    '|------------------------------------------------------------------------------|
    '| Devil:  7                            | Nature: Traditionalist                |
    '| Willpower: 3                         | Demeanor: Bon vivant                  |
    '|------------------------------------------------------------------------------|
    '|                                  Abilities                                   |
    '|          Talents                  Skills                  Knowledges         |
    '| Acting:       1            Animal Ken: 0              Bureaucracy:   1       |
    '| Alertness:    2            Drive:      0              Computer:      0       |
    '| Athletics:    1            Etiquette:  0              Finance:       1       |
    '| Brawl:        1            Firearms:   0              Investigation: 3       |
    '| Dodge:        1            Melee:      0              Law:           1       |
    '| Empathy:      1            Music:      0              Linguistics:   3       |
    '| Intimidation: 1            Repair:     0              Medecine:      0       |
    '| Leadership:   0            Security:   2              Occult:        2       |
    '| Streetwise:   0            Stealth:    1              Politics:      2       |
    '| Subterfuge:   1            Survival:   2              Science:       0       |
    '|------------------------------------------------------------------------------|
    '| Backgrounds:                         | Virtues:                              |
    '| Retainers                            | Conscience:   0                       |
    '| Contacts                             | Conviction:   2                       |
    '| Retainers                            | Instinct:     5                       |
    '| Generation                           | Self-Control: 0                       |
    '| Herd                                 | Courage:       3                      |
    '|--------------------------------------/                                       |
    '|                                                                              |
    '\------------------------------------------------------------------------------/


End Sub

Sub CharacterGenerator ()
    Dim ch As CharacterType
    Call NewCharacter(ch)
    Call CGGetHeader(ch)
    Call CGGetDisciplines(ch)
    Call CGGetAttributes(ch)
    Call CGGetAbilities(ch)
    Call CGGetBackgrounds(ch)
    Call CGGetRoad(ch)
    Call CGSpendVirtuePoints(ch)
    Call CGGetDerangement(ch)

    ' Generation starts at 13 and goes down 1 point per point of the "generation" background.
    ch.generation = INITIAL_GENERATION - GetBackground(ch, BACKGROUND_GENERATION)

    ' Willpower
    ch.willpower = ch.courage
    ' Humanity
    ch.roadValue = ch.conscience + ch.selfControl
    ' Blood Pool - The only die roll.
    ch.bloodPool = GetRandomInt(1, 10)

    ' Spend freebie points
    Call CGSpendFreebiePoints(ch)

    Call SaveCharacterSheet(ch)
    Call ShowCharacterSheet(ch)
End Sub

Sub ShowCharacterSheet (ch As CharacterType)
    Dim disciplineValues(1 To DISCIPLINES_COUNT) As Integer
    Call FillDisciplines(ch, disciplineValues())

    Dim backgroundValues(1 To BACKGROUNDS_COUNT) As Integer
    Call FillBackgrounds(ch, backgroundValues())

    '... 0123456789
    '160 �、�ぅΗ┤
    '170 ������葦桶
    '180 患況弦沙悉
    '190 梢請唾津毒
    '200 班碧麺力佰
    '210 厶壞嶐慵无
    '220 槿渤珀矣粤�
    '230 肄蓍裨2跋鈿
    ' enquote forms s/^([漂藩�].*[産執])$/print "$1"/g

    Dim disciplineStrings(3) As String
    disciplineStringsIndex = 0
    For index = 1 To DISCIPLINES_COUNT
        If disciplineValues(index) > 0 Then
            suffix$ = ""
            If disciplineValues(index) > 1 Then
                suffix$ = " x" + itos$(disciplineValues(index))
            End If
            disciplineStrings(disciplineStringsIndex) = Disciplines(index) + suffix$
            disciplineStringsIndex = disciplineStringsIndex + 1
        End If
    Next

    Dim backgroundStrings(5) As String
    backgroundStringsIndex = 0
    For index = 1 To BACKGROUNDS_COUNT
        If backgroundValues(index) > 0 Then
            suffix$ = ""
            If backgroundValues(index) > 1 Then
                suffix$ = " x" + itos$(backgroundValues(index))
            End If
            backgroundStrings$(backgroundStringsIndex) = Backgrounds(index) + suffix$
            backgroundStringsIndex = backgroundStringsIndex + 1
        End If
    Next
    Dim derangementStrings(5) As String
    allDerangementsLine$ = GetAllDerangementsLine$(ch)

    Call MakeWrapLines(derangementStrings(), allDerangementsLine$, 37, 5)

    MaybeCls
    Print "浜様様様様様様様様様様様様様様様様様様曜様様様様様様様様様様様様様様様様様様様融"
    Print "� Name: " + MakeFitL$(ch.name, 30, " ") + " � Gender: " + MakeFitL$(Genders(ch.gender), 14, " ") + " Generation: " + MakeFitR$(itos$(ch.generation), 2, " ") + " �"
    Print "� Clan: " + MakeFitL$(Clans(ch.clan), 30, " ") + " � Age: " + MakeFitL$(ch.age$, 32, " ") + " �"
    Print "麺様様様様様様様様様様様様様様様様様様郵 Player: " + MakeFitL$(ch.player$, 29, " ") + " �"
    Print "�              Attributes              � Chronicle: " + MakeFitL$(ch.chronicle$, 26, " ") + " �"
    Print "�   Physical     Social      Mental    � Haven: " + MakeFitL$(ch.haven$, 30, " ") + " �"
    Print "� Str. " + MakeFitL$(itos$(ch.attr_strength), 7, " ") + " App. " + MakeFitL$(itos$(ch.attr_appearance), 7, " ") + " Int. " + MakeFitL$(itos$(ch.attr_intelligence), 5, " ") + " � Concept: " + MakeFitL$(ch.concept$, 28, " ") + " �"
    Print "� Dex. " + MakeFitL$(itos$(ch.attr_dexterity), 7, " ") + " Cha. " + MakeFitL$(itos$(ch.attr_charisma), 7, " ") + " Per. " + MakeFitL$(itos$(ch.attr_perception), 5, " ") + " 麺様様様様様様様様様様様様様様様様様様様�"
    Print "� Sta. " + MakeFitL$(itos$(ch.attr_stamina), 7, " ") + " Man. " + MakeFitL$(itos$(ch.attr_manipulation), 7, " ") + " Wit. " + MakeFitL$(itos$(ch.attr_wits), 5, " ") + " � Derangements:                         �"
    Print "麺様様様様様様様様様様様様様様様様様様郵 " + derangementStrings(0) + " �"
    Print "� Disciplines:                         � " + derangementStrings(1) + " �"
    Print "� " + MakeFitL$(disciplineStrings(0), 36, " ") + " � " + MakeFitL$(derangementStrings(2), 37, "_") + " �"
    Print "� " + MakeFitL$(disciplineStrings(1), 36, " ") + " � " + MakeFitL$(derangementStrings(3), 37, "_") + " �"
    Print "� " + MakeFitL$(disciplineStrings(2), 36, " ") + " � " + MakeFitL$(derangementStrings(4), 37, "_") + " �"
    Print "麺様様様様様様様様様様様様様様様様様様洋様様様様様様様様様様様様様様様様様様様郵"
    Print "� " + MakeFitL$(ch.roadName + ": " + itos$(ch.roadValue), 36, " ") + " � Nature: " + MakeFitL$(Archetypes(ch.nature), 29, " ") + " �"
    Print "� Willpower: " + MakeFitL$(itos$(ch.willpower), 25, " ") + " � Demeanor: " + MakeFitL$(Archetypes(ch.demeanor), 27, " ") + " �"
    Print "麺様様様様様様様様様様様様様様様様様様擁様様様様様様様様様様様様様様様様様様様郵"
    Print "�                                                                              �"
    Print "�                                                                              �"
    Print "�                                                                              �"
    Print "�                        <<PRESS ANY KEY TO CONTINUE>>                         �"
    Print "藩様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様夕"
    Call PressAnyKeyToContinue

    Print "浜様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様融"
    Print "� " + MakeFitC$("Abilities", 76, " ") + " �"
    Print "� " + MakeFitC$("Talents", 25, " ") + " " + MakeFitC$("Skills", 25, " ") + " " + MakeFitC$("Knowledges", 24, " ") + " �"
    For index = 1 To 10
        Print "� " + MakeFitC(MakeFitL$(Talents(index) + ":", 14, " ") + itos$(GetTalent(ch, index)), 25, " ") + " " + MakeFitC(MakeFitL$(Skills(index) + ":", 14, " ") + itos$(GetSkill(ch, index)), 25, " ") + " " + MakeFitC(MakeFitL$(Knowledges(index) + ":", 14, " ") + itos$(GetKnowledge(ch, index)), 24, " ") + " �"
    Next
    Print "麺様様様様様様様様様様様様様様様様様様曜様様様様様様様様様様様様様様様様様様様郵"
    Print "� Backgrounds:                         � Virtues:                              �"
    Print "� " + MakeFitL$(backgroundStrings(0), 36, " ") + " � " + MakeFitB$("Conscience:", itos$(ch.conscience), 37, " ") + " �"
    Print "� " + MakeFitL$(backgroundStrings(1), 36, " ") + " � " + MakeFitB$("Self-Control:", itos$(ch.selfControl), 37, " ") + " �"
    Print "� " + MakeFitL$(backgroundStrings(2), 36, " ") + " � " + MakeFitB$("Courage:", itos$(ch.courage), 37, " ") + " �"
    Print "� " + MakeFitL$(backgroundStrings(3), 36, " ") + " � " + MakeFitL$("", 37, " ") + " �"
    Print "� " + MakeFitL$(backgroundStrings(4), 36, " ") + " � " + MakeFitL$("", 37, " ") + " �"
    Print "麺様様様様様様様様様様様様様様様様様様擁様様様様様様様様様様様様様様様様様様様郵"
    Print "�                        <<PRESS ANY KEY TO CONTINUE>>                         �"
    Print "藩様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様夕"
    Call PressAnyKeyToContinue
End Sub

' Simpler character generator with fewer questions and more things done randomly without asking.
Sub CharacterGeneratorForDummies
    Call MaybePrint("CharacterGeneratorForDummies")
End Sub

' Maybe just remove this. It's kinda pointless. It asks some questions and calculates a contested roll.
' C1 dice pool, C1 difficulty, C2 dice pool, C2 difficulty, then rolls all the dice and does the math.
' In practice it's just slower than rolling the dice
Sub CombatComputer
    Call MaybePrint("CombatComputer")
End Sub

' Asks for a number of dice and a difficulty. Rolls the dice, calculates botches and successes.
Sub DiceRoller
    Call MaybePrint("DiceRoller")
End Sub

' Like the character generator if you choose random for everything. Should do random names/ages too, but doesn't yet.
Sub RandomCharacterGenerator
    Call MaybePrint("RandomCharacterGenerator")
End Sub

' This had a function at one point but got taken out. Will only come back if the disassembly can figure it out.
Sub Choice6
    Call MaybePrint("Unnamed choice 6")
End Sub

' Like the character generator but for vehicles. Much simpler with fewer questions. Prints a vehicle sheet when done. Never finished and crashes mid way through currently.
Sub VehicleGenerator
    Call MaybePrint("VehicleGenerator")
End Sub

Sub PressAnyKeyToContinue ()
    While InKey$ = "": Wend
End Sub

' String functions
Function itos$ (num As Integer)
    itos$ = LTrim$(Str$(num))
End Function

Function MakeFitL$ (text As String, length As Integer, pad As String)
    MakeFitL = Left$(text + String$(length, pad), length)
End Function

Function MakeFitC$ (text As String, length As Integer, pad As String)
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

Function MakeFitB$ (prefix As String, suffix As String, length As Integer, pad As String)
    MakeFitB$ = MakeFitL$(MakeFitL$(prefix, length - Len(suffix), pad) + suffix, length, pad)
End Function

Function GetIndexOf (fullString As String, targetString As String, startIndex As Integer)
    GetIndexOf = -1
    targetLength = Len(targetString)
    If targetLength <= 0 Then
        GetIndexOf = startIndex
        Exit Function
    End If

    position = startIndex + 1
    length = Len(fullString)
    Do
        currString$ = Mid$(fullString, position, targetLength)
        position = position + 1
    Loop While position <= length And currString$ <> targetString
    If currString$ = targetString Then GetIndexOf = position - 2
End Function

Function GetCharAt$ (text As String, index As Integer)
    length = Len(text)
    If length <= 0 Or index < 0 Or index >= length Then
        GetCharAt$ = ""
        Exit Function
    End If
    GetCharAt$ = Mid$(text, index + 1, 1)
End Function

Function GetSubstring$ (text As String, start As Integer, length As Integer)
    GetSubstring$ = Mid$(text, start + 1, length)
End Function

Sub MakeWrapLines (lines() As String, text As String, maxWidth As Integer, maxLines As Integer)
    ReDim lines(maxLines) As String
    lineCount = 0
    thisLine$ = ""
    nextChunk$ = ""
    thisLineStartPosition = 0
    thisLineCurrentPosition = 0
    nextSpace = -1
    textLength = Len(text)

    While (lineCount < maxLines)
        nextSpace = GetIndexOf(text, " ", thisLineCurrentPosition)
        If nextSpace < 0 Then nextSpace = textLength
        nextChunk$ = GetSubstring(text, thisLineCurrentPosition, nextSpace - thisLineCurrentPosition)
        nextChunkLength = Len(nextChunk$)
        If nextChunkLength > 0 Then
            needsSpace = Len(thisLine$) > 0
            If needsSpace Then
                thisLine$ = thisLine$ + " "
            End If
            thisLineLength = Len(thisLine$)
            If nextChunkLength > maxWidth Then
                nextChunk$ = GetSubstring(text, thisLineCurrentPosition, maxWidth - thisLineLength)
                nextSpace = thisLineStartPosition + maxWidth
                thisLine$ = thisLine$ + nextChunk$
                thisLineCurrentPosition = nextSpace
            ElseIf thisLineLength + nextChunkLength > maxWidth Then
                thisLine$ = MakeFitL$(thisLine$, maxWidth, " ")
            Else
                thisLine$ = thisLine$ + nextChunk$
                thisLineCurrentPosition = nextSpace + 1
            End If
            thisLineLength = Len(thisLine$)
        Else
            thisLineCurrentPosition = nextSpace + 1
        End If
        If thisLineLength >= maxWidth Or thisLineCurrentPosition > textLength Then
            thisLine$ = MakeFitL$(thisLine$, maxWidth, "_")
            lines(lineCount) = thisLine$
            lineCount = lineCount + 1
            thisLine$ = ""
            thisLineLength = Len(thisLine$)
            thisLineStartPosition = thisLineCurrentPosition
        End If
    Wend
End Sub

Sub MaybeCls ()
    If Not isDebugging Then Cls
End Sub

Sub MaybePrint (message As String)
    If isDebugging Then Print message
End Sub

'$include: 'colors.bm'
'$include: 'menus.bm'
'$include: 'character.bm'

Sub Test
    'End
End Sub

