$Debug
' Setup
' TODO: See if other combinations of clan and other variables cause sub questions.
' TODO: Calculate generation
' TODO: Calculate conscience
' TODO: Calculate conviction
' TODO: Calculate instinct
' TODO: Calculate self-control
' TODO: Calculate courage
' TODO: Calculate humanity/road
' TODO: Calculate willpower
' TODO: Add blood pool to sheet
' TODO: Input/Print derangements
' TODO: Some input prompts/messages have an extra space before the numeric variable in the string. Why? e.g. Which thingy to you want to spend 1 of your  3 remaining points on.
' TODO: Abstract the ALL_* stuff some more to support differences in VtDA and WtA stuff.
Randomize Timer

'Call Test
'End

' TODO: maybe make these some kind of typedef with an id and a label. Constants or enums would be great.
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

Const All_Attributes_Count = 3
Dim Shared All_Attributes(1 To All_Attributes_Count) As String
All_Attributes(1) = "Physical"
All_Attributes(2) = "Social"
All_Attributes(3) = "Mental"

Const All_Abilities_Count = 3
Dim Shared All_Abilities(1 To All_Attributes_Count) As String
All_Abilities(1) = "Talents"
All_Abilities(2) = "Skills"
All_Abilities(3) = "Knowledges"

Const All_Talents_Count = 10
Dim Shared All_Talents(1 To All_Talents_Count) As String
All_Talents(1) = "Acting"
All_Talents(2) = "Alertness"
All_Talents(3) = "Athletics"
All_Talents(4) = "Brawl"
All_Talents(5) = "Dodge"
All_Talents(6) = "Empathy"
All_Talents(7) = "Intimidation"
All_Talents(8) = "Leadership"
All_Talents(9) = "Streetwise"
All_Talents(10) = "Subterfuge"

Const All_Skills_Count = 10
Dim Shared All_Skills(1 To All_Skills_Count) As String
All_Skills(1) = "Animal Ken"
All_Skills(2) = "Drive"
All_Skills(3) = "Etiquette"
All_Skills(4) = "Firearms"
All_Skills(5) = "Melee"
All_Skills(6) = "Music"
All_Skills(7) = "Repair"
All_Skills(8) = "Security"
All_Skills(9) = "Stealth"
All_Skills(10) = "Survival"

Const All_Knowledges_Count = 10
Dim Shared All_Knowledges(1 To All_Knowledges_Count) As String
All_Knowledges(1) = "Bureaucracy"
All_Knowledges(2) = "Computer"
All_Knowledges(3) = "Finance"
All_Knowledges(4) = "Investigation"
All_Knowledges(5) = "Law"
All_Knowledges(6) = "Linguistics"
All_Knowledges(7) = "Medicine"
All_Knowledges(8) = "Occult"
All_Knowledges(9) = "Politics"
All_Knowledges(10) = "Science"

Const All_Backgrounds_Count = 10
Dim Shared All_Backgrounds(1 To All_Backgrounds_Count) As String
All_Backgrounds(1) = "Allies"
All_Backgrounds(2) = "Contacts"
All_Backgrounds(3) = "Fame"
All_Backgrounds(4) = "Generation"
All_Backgrounds(5) = "Herd"
All_Backgrounds(6) = "Influence"
All_Backgrounds(7) = "Mentor"
All_Backgrounds(8) = "Resources"
All_Backgrounds(9) = "Retainers"
All_Backgrounds(10) = "Status"

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
    conscience As Integer
    selfControl As Integer
    courage As Integer
    ' Special but don't know why
    conviction As Integer
    instinct As Integer
    ' Disciplines
    discipline_animalism As Integer
    discipline_auspex As Integer
    discipline_bardo As Integer
    discipline_celerity As Integer
    discipline_chimestry As Integer
    discipline_dementation As Integer
    discipline_dominate As Integer
    discipline_fortitude As Integer
    discipline_melpominee As Integer
    discipline_mortis As Integer
    discipline_mytherceria As Integer
    discipline_necromancy As Integer
    discipline_obeah As Integer
    discipline_obfuscate As Integer
    discipline_obtenebration As Integer
    discipline_potence As Integer
    discipline_presence As Integer
    discipline_protean As Integer
    discipline_quietus As Integer
    discipline_serpentis As Integer
    discipline_spiritus As Integer
    discipline_thanantosis As Integer
    discipline_thaumaturgy As Integer
    discipline_vicissitude As Integer
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
    ' Talents
    talent_acting As Integer
    talent_alertness As Integer
    talent_athletics As Integer
    talent_brawl As Integer
    talent_dodge As Integer
    talent_empathy As Integer
    talent_intimidation As Integer
    talent_leadership As Integer
    talent_streetwise As Integer
    talent_subterfuge As Integer
    ' Skills
    skill_animalKen As Integer
    skill_drive As Integer
    skill_etiquette As Integer
    skill_firearms As Integer
    skill_melee As Integer
    skill_music As Integer
    skill_repair As Integer
    skill_security As Integer
    skill_stealth As Integer
    skill_survival As Integer
    ' Knowledges
    knowledge_bureaucracy As Integer
    knowledge_computer As Integer
    knowledge_finance As Integer
    knowledge_investigation As Integer
    knowledge_law As Integer
    knowledge_linguistics As Integer
    knowledge_medicine As Integer
    knowledge_occult As Integer
    knowledge_politics As Integer
    knowledge_science As Integer
    ' Backgrounds
    background_allies As Integer
    background_contacts As Integer
    background_fame As Integer
    background_generation As Integer
    background_herd As Integer
    background_influence As Integer
    background_mentor As Integer
    background_resources As Integer
    background_retainers As Integer
    background_status As Integer
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
    Print "╔══════════════════════════════════════════════════════════════════════════════╗"
    Print "║ What are you going to do?                                                    ║"
    Print "║        1 = Character Generator                                               ║"
    Print "║        2 = Character Generator for Dummies                                   ║"
    Print "║        3 = Combat Computer                                                   ║"
    Print "║        4 = Dice Roller                                                       ║"
    Print "║        5 = Random Character Generator                                        ║"
    Print "║        6 =                                                                   ║"
    Print "║        7 = Vehicle Generator                                                 ║"
    Print "║                                                                              ║"
    Print "║                                                                              ║"
    Print "║                                                                              ║"
    Print "║                                                                              ║"
    Print "║                                                                              ║"
    Print "║                                                                              ║"
    Print "║                                                                              ║"
    Print "║                                                                              ║"
    Print "║                                                                              ║"
    Print "║                                                                              ║"
    Print "║                                                                              ║"
    Print "║        0 = End                                                               ║"
    Print "║                                                                              ║"
    Print "╚══════════════════════════════════════════════════════════════════════════════╝"
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
    Print "╔══════════════════════════════════════════════════════════════════════════════╗"
    Print "║                                                                              ║"
    Print "║                                                                              ║"
    Print "║                                                                              ║"
    Print "║                                                                              ║"
    Print "║                                                                              ║"
    Print "║                                                                              ║"
    Print "║                                                                              ║"
    Print "║                                                                              ║"
    Print "║                                                                              ║"
    Print "║                                                                              ║"
    Print "║                                                                              ║"
    Print "║                                                                              ║"
    Print "║                                                                              ║"
    Print "║                                                                              ║"
    Print "║                                                                              ║"
    Print "║                                                                              ║"
    Print "║                                                                              ║"
    Print "║                                                                              ║"
    Print "║                                                                              ║"
    Print "║                                                                              ║"
    Print "║                                                                              ║"
    Print "╚══════════════════════════════════════════════════════════════════════════════╝"
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
    ' TODO: allow printing inside of a box ║ 1 = item ║.
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
    ' TODO: Make a better separation between index, item, value triples
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

Sub SetDiscipline (ch As CharacterType, index As Integer, value As Integer)
    Select Case index
        Case 1
            ch.discipline_animalism = value
        Case 2
            ch.discipline_auspex = value
        Case 3
            ch.discipline_bardo = value
        Case 4
            ch.discipline_celerity = value
        Case 5
            ch.discipline_chimestry = value
        Case 6
            ch.discipline_dementation = value
        Case 7
            ch.discipline_dominate = value
        Case 8
            ch.discipline_fortitude = value
        Case 9
            ch.discipline_melpominee = value
        Case 10
            ch.discipline_mortis = value
        Case 11
            ch.discipline_mytherceria = value
        Case 12
            ch.discipline_necromancy = value
        Case 13
            ch.discipline_obeah = value
        Case 14
            ch.discipline_obfuscate = value
        Case 15
            ch.discipline_obtenebration = value
        Case 16
            ch.discipline_potence = value
        Case 17
            ch.discipline_presence = value
        Case 18
            ch.discipline_protean = value
        Case 19
            ch.discipline_quietus = value
        Case 20
            ch.discipline_serpentis = value
        Case 21
            ch.discipline_spiritus = value
        Case 22
            ch.discipline_thanantosis = value
        Case 23
            ch.discipline_thaumaturgy = value
        Case 24
            ch.discipline_vicissitude = value
    End Select
End Sub

Function GetDiscipline (ch As CharacterType, index As Integer)
    Select Case index
        Case 1
            GetDiscipline = ch.discipline_animalism
        Case 2
            GetDiscipline = ch.discipline_auspex
        Case 3
            GetDiscipline = ch.discipline_bardo
        Case 4
            GetDiscipline = ch.discipline_celerity
        Case 5
            GetDiscipline = ch.discipline_chimestry
        Case 6
            GetDiscipline = ch.discipline_dementation
        Case 7
            GetDiscipline = ch.discipline_dominate
        Case 8
            GetDiscipline = ch.discipline_fortitude
        Case 9
            GetDiscipline = ch.discipline_melpominee
        Case 10
            GetDiscipline = ch.discipline_mortis
        Case 11
            GetDiscipline = ch.discipline_mytherceria
        Case 12
            GetDiscipline = ch.discipline_necromancy
        Case 13
            GetDiscipline = ch.discipline_obeah
        Case 14
            GetDiscipline = ch.discipline_obfuscate
        Case 15
            GetDiscipline = ch.discipline_obtenebration
        Case 16
            GetDiscipline = ch.discipline_potence
        Case 17
            GetDiscipline = ch.discipline_presence
        Case 18
            GetDiscipline = ch.discipline_protean
        Case 19
            GetDiscipline = ch.discipline_quietus
        Case 20
            GetDiscipline = ch.discipline_serpentis
        Case 21
            GetDiscipline = ch.discipline_spiritus
        Case 22
            GetDiscipline = ch.discipline_thanantosis
        Case 23
            GetDiscipline = ch.discipline_thaumaturgy
        Case 24
            GetDiscipline = ch.discipline_vicissitude
    End Select
End Function

Sub FillDisciplines (ch As CharacterType, disciplines() As Integer)
    For index = 1 To All_Disciplines_Count
        disciplines(index) = GetDiscipline(ch, index)
    Next
End Sub

Sub SetTalent (ch As CharacterType, index As Integer, value As Integer)
    Select Case index
        Case 1
            ch.talent_acting = value
        Case 2
            ch.talent_alertness = value
        Case 3
            ch.talent_athletics = value
        Case 4
            ch.talent_brawl = value
        Case 5
            ch.talent_dodge = value
        Case 6
            ch.talent_empathy = value
        Case 7
            ch.talent_intimidation = value
        Case 8
            ch.talent_leadership = value
        Case 9
            ch.talent_streetwise = value
        Case 10
            ch.talent_subterfuge = value
    End Select
End Sub

Function GetTalent (ch As CharacterType, index As Integer)
    Select Case index
        Case 1
            GetTalent = ch.talent_acting
        Case 2
            GetTalent = ch.talent_alertness
        Case 3
            GetTalent = ch.talent_athletics
        Case 4
            GetTalent = ch.talent_brawl
        Case 5
            GetTalent = ch.talent_dodge
        Case 6
            GetTalent = ch.talent_empathy
        Case 7
            GetTalent = ch.talent_intimidation
        Case 8
            GetTalent = ch.talent_leadership
        Case 9
            GetTalent = ch.talent_streetwise
        Case 10
            GetTalent = ch.talent_subterfuge
    End Select
End Function

Sub SetSkill (ch As CharacterType, index As Integer, value As Integer)
    Select Case index
        Case 1
            ch.skill_animalKen = value
        Case 2
            ch.skill_drive = value
        Case 3
            ch.skill_etiquette = value
        Case 4
            ch.skill_firearms = value
        Case 5
            ch.skill_melee = value
        Case 6
            ch.skill_music = value
        Case 7
            ch.skill_repair = value
        Case 8
            ch.skill_security = value
        Case 9
            ch.skill_stealth = value
        Case 10
            ch.skill_survival = value
    End Select
End Sub

Function GetSkill (ch As CharacterType, index As Integer)
    Select Case index
        Case 1
            GetSkill = ch.skill_animalKen
        Case 2
            GetSkill = ch.skill_drive
        Case 3
            GetSkill = ch.skill_etiquette
        Case 4
            GetSkill = ch.skill_firearms
        Case 5
            GetSkill = ch.skill_melee
        Case 6
            GetSkill = ch.skill_music
        Case 7
            GetSkill = ch.skill_repair
        Case 8
            GetSkill = ch.skill_security
        Case 9
            GetSkill = ch.skill_stealth
        Case 10
            GetSkill = ch.skill_survival
    End Select
End Function

Sub SetKnowledge (ch As CharacterType, index As Integer, value As Integer)
    Select Case index
        Case 1
            ch.knowledge_bureaucracy = value
        Case 2
            ch.knowledge_computer = value
        Case 3
            ch.knowledge_finance = value
        Case 4
            ch.knowledge_investigation = value
        Case 5
            ch.knowledge_law = value
        Case 6
            ch.knowledge_linguistics = value
        Case 7
            ch.knowledge_medicine = value
        Case 8
            ch.knowledge_occult = value
        Case 9
            ch.knowledge_politics = value
        Case 10
            ch.knowledge_science = value
    End Select
End Sub

Function GetKnowledge (ch As CharacterType, index As Integer)
    Select Case index
        Case 1
            GetKnowledge = ch.knowledge_bureaucracy
        Case 2
            GetKnowledge = ch.knowledge_computer
        Case 3
            GetKnowledge = ch.knowledge_finance
        Case 4
            GetKnowledge = ch.knowledge_investigation
        Case 5
            GetKnowledge = ch.knowledge_law
        Case 6
            GetKnowledge = ch.knowledge_linguistics
        Case 7
            GetKnowledge = ch.knowledge_medicine
        Case 8
            GetKnowledge = ch.knowledge_occult
        Case 9
            GetKnowledge = ch.knowledge_politics
        Case 10
            GetKnowledge = ch.knowledge_science
    End Select
End Function

Sub SetBackground (ch As CharacterType, index As Integer, value As Integer)
    Select Case index
        Case 1
            ch.background_allies = value
        Case 2
            ch.background_contacts = value
        Case 3
            ch.background_fame = value
        Case 4
            ch.background_generation = value
        Case 5
            ch.background_herd = value
        Case 6
            ch.background_influence = value
        Case 7
            ch.background_mentor = value
        Case 8
            ch.background_resources = value
        Case 9
            ch.background_retainers = value
        Case 10
            ch.background_status = value
    End Select
End Sub

Function GetBackground (ch As CharacterType, index As Integer)
    Select Case index
        Case 1
            GetBackground = ch.background_allies
        Case 2
            GetBackground = ch.background_contacts
        Case 3
            GetBackground = ch.background_fame
        Case 4
            GetBackground = ch.background_generation
        Case 5
            GetBackground = ch.background_herd
        Case 6
            GetBackground = ch.background_influence
        Case 7
            GetBackground = ch.background_mentor
        Case 8
            GetBackground = ch.background_resources
        Case 9
            GetBackground = ch.background_retainers
        Case 10
            GetBackground = ch.background_status
    End Select
End Function

Sub FillBackgrounds (ch As CharacterType, backgrounds() As Integer)
    For index = 1 To All_Backgrounds_Count
        backgrounds(index) = GetBackground(ch, index)
    Next
End Sub

Sub InitializeCharacter (ch As CharacterType)
    ch.name = ""
    ch.player = ""
    ch.chronicle = ""
    ch.haven = ""
    ch.concept = ""
    ch.age = ""
    ch.sex = 0
    ch.clan = 0
    ch.nature = 0
    ch.demeanor = 0
    ch.conscience = 0
    ch.selfControl = 0
    ch.courage = 0
    ch.conviction = 0
    ch.instinct = 0
    ' Disciplines
    ch.discipline_animalism = 0
    ch.discipline_auspex = 0
    ch.discipline_bardo = 0
    ch.discipline_celerity = 0
    ch.discipline_chimestry = 0
    ch.discipline_dementation = 0
    ch.discipline_dominate = 0
    ch.discipline_fortitude = 0
    ch.discipline_melpominee = 0
    ch.discipline_mortis = 0
    ch.discipline_mytherceria = 0
    ch.discipline_necromancy = 0
    ch.discipline_obeah = 0
    ch.discipline_obfuscate = 0
    ch.discipline_obtenebration = 0
    ch.discipline_potence = 0
    ch.discipline_presence = 0
    ch.discipline_protean = 0
    ch.discipline_quietus = 0
    ch.discipline_serpentis = 0
    ch.discipline_spiritus = 0
    ch.discipline_thanantosis = 0
    ch.discipline_thaumaturgy = 0
    ch.discipline_vicissitude = 0
    ' Attributes
    ch.attr_strength = 1
    ch.attr_dexterity = 1
    ch.attr_stamina = 1
    ch.attr_appearance = 1
    ch.attr_charisma = 1
    ch.attr_manipulation = 1
    ch.attr_intelligence = 1
    ch.attr_perception = 1
    ch.attr_wits = 1
    ' Talents
    ch.talent_acting = 0
    ch.talent_alertness = 0
    ch.talent_athletics = 0
    ch.talent_brawl = 0
    ch.talent_dodge = 0
    ch.talent_empathy = 0
    ch.talent_intimidation = 0
    ch.talent_leadership = 0
    ch.talent_streetwise = 0
    ch.talent_subterfuge = 0
    ' Skills
    ch.skill_animalKen = 0
    ch.skill_drive = 0
    ch.skill_etiquette = 0
    ch.skill_firearms = 0
    ch.skill_melee = 0
    ch.skill_music = 0
    ch.skill_repair = 0
    ch.skill_security = 0
    ch.skill_stealth = 0
    ch.skill_survival = 0
    ' Knowledges
    ch.knowledge_bureaucracy = 0
    ch.knowledge_computer = 0
    ch.knowledge_finance = 0
    ch.knowledge_investigation = 0
    ch.knowledge_law = 0
    ch.knowledge_linguistics = 0
    ch.knowledge_medicine = 0
    ch.knowledge_occult = 0
    ch.knowledge_politics = 0
    ch.knowledge_science = 0
    ' Backgrounds
    ch.background_allies = 0
    ch.background_contacts = 0
    ch.background_fame = 0
    ch.background_generation = 0
    ch.background_herd = 0
    ch.background_influence = 0
    ch.background_mentor = 0
    ch.background_resources = 0
    ch.background_retainers = 0
    ch.background_status = 0
End Sub

Sub CharacterGenerator ()
    Dim ch As CharacterType
    Call InitializeCharacter(ch)

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
    DisciplinePoints = 3

    ' I don't like having to build an empty array for return values here. Ideally PrintMenuWithValues could take the character and a mapping fn(index) that
    ' calls GetDiscipline(ch, index) to fetch the value. At least for BASIC this seems like a better solution. PrintMenuWithValues does piss me off though.
    ' I don't want it to exist. I want a formatting function there that takes the character and the index then prints "1 = Bullshit: 3" or something like that.
    ' But we can't have nice things like nested custom types, arrays in custom types, or function objects/pointers.
    ' TODO: Try to find a better way to do this.
    Dim disciplines(All_Disciplines_Count) As Integer
    While DisciplinePoints > 0
        Cls
        Print "Which discipline do you want to spend 1 of your " + Str$(DisciplinePoints) + " discipline points on?"
        Call FillDisciplines(ch, disciplines())
        Call PrintMenuWithValues(All_Disciplines(), disciplines(), All_Disciplines_Count)
        discipline = GetChoice(0, All_Disciplines_Count)
        If discipline = 0 Then discipline = GetRandomInt(1, All_Disciplines_Count)
        Call SetDiscipline(ch, discipline, GetDiscipline(ch, discipline) + 1)
        DisciplinePoints = DisciplinePoints - 1
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
        Input "Choose your primary attribute?", PrimaryAttribute
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
        Input "Choose your secondary attribute?", SecondaryAttribute
        If SecondaryAttribute = 0 Or SecondaryAttribute = PrimaryAttribute Then
            SecondaryAttribute = GetRandomInt(1, All_Attributes_Count - 1)
            If SecondaryAttribute >= PrimaryAttribute Then
                SecondaryAttribute = SecondaryAttribute + 1
            End If
        End If
    Loop Until SecondaryAttribute >= 1 And SecondaryAttribute <= 3 And SecondaryAttribute <> PrimaryAttribute
    ' General formula for last choice is
    ' Sum(1..AllAttributesCount)-Sum(Choice[1]..Choice[AllAttributesCount-1])
    TertiaryAttribute = 2 * All_Attributes_Count - PrimaryAttribute - SecondaryAttribute

    ' TODO: Make this less annoying. I want three assignments not three switches. I also want it to be tied to a const instead of 3.
    ' TODO: The point values themselves (7, 5, and 3) should be consts themselves or a formula.
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
        ' TODO: Make this less hard-coded. Attribute names should be pulled from All_* arrays. The menu should be printed with PrintMenu.
        ' We have 6 uses of this block and I want them to be 6 sub calls passing in arrays. Something like:
        ' Call SpendPoint(ch, attrGroup) that could lookup GetAllAttributesInGroup(group) to get Str, dex, sta, ...
        ' That could "return" an array filled with {index, value} pairs and then use PrintMenuWithValues to actually print the values
        ' Still need a way to handle GetChoice([0, 1, 3]) or whatever it looks like. Maybe an array of another struct like {index, hidden}.
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

    ' TODO: Find a more general form for this that stores the chosen abilities in an array
    Dim PrimaryAbility As Integer
    Do
        Cls
        Print "1 = " + All_Abilities(1) + " ";
        Print "2 = " + All_Abilities(2) + " ";
        Print "3 = " + All_Abilities(3) + " ";
        Print "0 = Random"
        Input "Choose your primary ability?", PrimaryAbility
        If PrimaryAbility = 0 Then PrimaryAbility = GetRandomInt(1, All_Abilities_Count)
    Loop While (PrimaryAbility > All_Abilities_Count And PrimaryAbility < 1)

    Dim SecondaryAbility As Integer
    Dim TertiaryAbility As Integer
    Do
        Cls
        If PrimaryAbility <> 1 Then Print "1 = " + All_Abilities(1) + " ";
        If PrimaryAbility <> 2 Then Print "2 = " + All_Abilities(2) + " ";
        If PrimaryAbility <> 3 Then Print "3 = " + All_Abilities(3) + " ";
        Print "0 = Random"
        Input "Choose your secondary ability?", SecondaryAbility
        If SecondaryAbility = 0 Or SecondaryAbility = PrimaryAbility Then
            SecondaryAbility = GetRandomInt(1, All_Abilities_Count - 1)
            If SecondaryAbility >= PrimaryAbility Then
                SecondaryAbility = SecondaryAbility + 1
            End If
        End If
    Loop Until SecondaryAbility >= 1 And SecondaryAbility <= 3 And SecondaryAbility <> PrimaryAbility
    TertiaryAbility = 2 * All_Abilities_Count - PrimaryAbility - SecondaryAbility

    ' Initialize talent, skill, knowledge points
    Select Case PrimaryAbility
        Case 1
            TalentPoints = 13
        Case 2
            SkillPoints = 13
        Case 3
            KnowledgePoints = 13
    End Select
    Select Case SecondaryAbility
        Case 1
            TalentPoints = 9
        Case 2
            SkillPoints = 9
        Case 3
            KnowledgePoints = 9
    End Select
    Select Case TertiaryAbility
        Case 1
            TalentPoints = 5
        Case 2
            SkillPoints = 5
        Case 3
            KnowledgePoints = 5
    End Select

    Print "Primary: " + Str$(PrimaryAbility) + ", Secondary: " + Str$(SecondaryAbility) + ", Tertiary: " + Str$(TertiaryAbility)
    Print "Talents: " + Str$(TalentPoints) + ", Skills: " + Str$(SkillPoints) + ", Knowledges: " + Str$(KnowledgePoints)
    Input A

    ' Spend talent points
    Do
        Cls
        Print "Which talent would you like to spend 1 of your " + Str$(TalentPoints) + " points on?"
        Print " 0 = Random"
        For index = 1 To All_Talents_Count
            Print MakeFitR$(Str$(index), 2, " ") + " = " + MakeFitL$(All_Talents(index) + ":", 20, " ") + " " + MakeFitR$(Str$(GetTalent(ch, index)), 3, " ")
        Next
        talent = GetChoice(0, All_Talents_Count)
        If talent = 0 Then talent = GetRandomInt(1, All_Talents_Count)
        Call SetTalent(ch, talent, GetTalent(ch, talent) + 1)
        TalentPoints = TalentPoints - 1
    Loop While TalentPoints > 0

    ' Spend skill points
    Do
        Cls
        Print "Which skill would you like to spend 1 of your " + Str$(SkillPoints) + " points on?"
        Print " 0 = Random"
        For index = 1 To All_Skills_Count
            Print MakeFitR$(Str$(index), 2, " ") + " = " + MakeFitL$(All_Skills(index) + ":", 20, " ") + " " + MakeFitR$(Str$(GetSkill(ch, index)), 3, " ")
        Next
        skill = GetChoice(0, All_Skills_Count)
        If skill = 0 Then skill = GetRandomInt(1, All_Skills_Count)
        Call SetSkill(ch, skill, GetSkill(ch, skill) + 1)
        SkillPoints = SkillPoints - 1
    Loop While SkillPoints > 0

    'Spend knowledge points
    Do
        Cls
        Print "Which knowledge would you like to spend 1 of your " + Str$(KnowledgePoints) + " points on?"
        Print " 0 = Random"
        For index = 1 To All_Knowledges_Count
            Print MakeFitR$(Str$(index), 2, " ") + " = " + MakeFitL$(All_Knowledges(index) + ":", 20, " ") + " " + MakeFitR$(Str$(GetKnowledge(ch, index)), 3, " ")
        Next
        knowledge = GetChoice(0, All_Knowledges_Count)
        If knowledge = 0 Then knowledge = GetRandomInt(1, All_Knowledges_Count)
        Call SetKnowledge(ch, knowledge, GetKnowledge(ch, knowledge) + 1)
        KnowledgePoints = KnowledgePoints - 1
    Loop While KnowledgePoints > 0

    ' Spend background points
    BackgroundPoints = 5
    Dim backgrounds(All_Backgrounds_Count) As Integer
    While BackgroundPoints > 0
        Cls
        Print "Which background do you want to spend 1 of your " + Str$(BackgroundPoints) + " background points on?"
        Call FillBackgrounds(ch, backgrounds())
        Call PrintMenuWithValues(All_Backgrounds(), backgrounds(), All_Backgrounds_Count)
        background = GetChoice(0, All_Backgrounds_Count)
        If background = 0 Then background = GetRandomInt(1, All_Backgrounds_Count)
        Call SetBackground(ch, background, GetBackground(ch, background) + 1)
        BackgroundPoints = BackgroundPoints - 1
    Wend

    ' TODO: Choose your road. This is only for dark ages so skip for now
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
    '160 áíóúñÑªº¿⌐
    '170 ¬½¼¡«»░▒▓│
    '180 ┤╡╢╖╕╣║╗╝╜
    '190 ╛┐└┴┬├─┼╞╟
    '200 ╚╔╩╦╠═╬╧╨╤
    '210 ╥╙╘╒╓╫╪┘┌█
    '220 ▄▌▐▀αßΓπΣσσ
    '230 µτΦΘΩδ2∞φε∩
    ' Where do you want the file to be saved? (default is C:\Windows\Desktop)?
    ' What do you want the file to be called? (default is CHAR1)?

    ' enquote forms s/^([╔║╚═╠].*[╗║╝╣])$/print "$1"/g

    ' TODO: figure out how to actually calculate generation; seems like a combination of 13 or 15 depending on clan and your generation background count
    generation$ = "13"
    If ch.sex = 1 Then sex_string$ = "Male" Else sex_string$ = "Female"
    clan_string$ = All_Clans(ch.clan)

    Dim discipline_strings(3) As String
    discipline_strings_index = 0
    For index = 1 To All_Disciplines_Count
        If disciplines(index) > 0 Then
            suffix$ = ""
            If disciplines(index) > 1 Then
                suffix$ = " x" + Str$(disciplines(index))
            End If
            discipline_strings(discipline_strings_index) = All_Disciplines(index) + suffix$
        End If
    Next

    Dim background_strings(5) As String
    background_strings_index = 0
    For index = 1 To All_Backgrounds_Count
        If backgrounds(index) > 0 Then
            suffix$ = ""
            If backgrounds(index) > 1 Then
                suffix$ = " x" + Str$(backgrounds(index))
            End If
            background_strings$(background_strings_index) = All_Backgrounds(index) + suffix$
        End If
    Next

    Cls
    Print "╔══════════════════════════════════════╦═══════════════════════════════════════╗"
    Print "║ Name: " + MakeFitL$(ch.name, 30, " ") + " ║ Sex: " + MakeFitL$(sex_string$, 10, " ") + " Generation: " + MakeFitL$(generation$, 9, " ") + " ║"
    Print "║ Clan: " + MakeFitL$(clan_string$, 30, " ") + " ║ Age: " + MakeFitL$(age$, 32, " ") + " ║"
    Print "╠══════════════════════════════════════╣ Player: " + MakeFitL$(player$, 29, " ") + " ║"
    Print "║              Attributes              ║ Chronicle: " + MakeFitL$(chronicle$, 26, " ") + " ║"
    Print "║   Physical     Social      Mental    ║ Haven: " + MakeFitL$(haven$, 30, " ") + " ║"
    Print "║ Str. " + MakeFitL$(Str$(ch.attr_strength), 7, " ") + " App. " + MakeFitL$(Str$(ch.attr_appearance), 7, " ") + " Int. " + MakeFitL$(Str$(ch.attr_intelligence), 5, " ") + " ║ Concept: " + MakeFitL$(concept$, 28, " ") + " ║"
    Print "║ Dex. " + MakeFitL$(Str$(ch.attr_dexterity), 7, " ") + " Cha. " + MakeFitL$(Str$(ch.attr_charisma), 7, " ") + " Per. " + MakeFitL$(Str$(ch.attr_perception), 5, " ") + " ╠═══════════════════════════════════════╣"
    Print "║ Sta. " + MakeFitL$(Str$(ch.attr_stamina), 7, " ") + " Man. " + MakeFitL$(Str$(ch.attr_manipulation), 7, " ") + " Wit. " + MakeFitL$(Str$(ch.attr_wits), 5, " ") + " ║ Derangements:                         ║"
    Print "╠══════════════════════════════════════╣ Regression,__________________________ ║"
    Print "║ Disciplines:                         ║ _____________________________________ ║"
    Print "║ " + MakeFitL$(discipline_strings(0), 36, " ") + " ║ _____________________________________ ║"
    Print "║ " + MakeFitL$(discipline_strings(1), 36, " ") + " ║ _____________________________________ ║"
    Print "║ " + MakeFitL$(discipline_strings(2), 36, " ") + " ║ _____________________________________ ║"
    Print "╠══════════════════════════════════════╬═══════════════════════════════════════╣"
    Print "║ Typhon:  7                           ║ Nature: " + MakeFitL$(All_Archetypes(ch.nature), 29, " ") + " ║"
    Print "║ Willpower: 3                         ║ Demeanor: " + MakeFitL$(All_Archetypes(ch.demeanor), 27, " ") + " ║"
    Print "╠══════════════════════════════════════╩═══════════════════════════════════════╣"
    Print "║                                                                              ║"
    Print "║                                                                              ║"
    Print "║                                                                              ║"
    Print "║                        <<PRESS ANY KEY TO CONTINUE>>                         ║"
    Print "╚══════════════════════════════════════════════════════════════════════════════╝"
    Input A
    Print "╔══════════════════════════════════════════════════════════════════════════════╗"
    Print "║ " + MakeFitC$("Abilities", 76, " ") + " ║"
    Print "║ " + MakeFitC$("Talents", 25, " ") + " " + MakeFitC$("Skills", 25, " ") + " " + MakeFitC$("Knowledges", 24, " ") + " ║"
    For index = 1 To 10
        Print "║ " + MakeFitC(MakeFitL$(All_Talents(index) + ":", 14, " ") + Str$(GetTalent(ch, index)), 25, " ") + " " + MakeFitC(MakeFitL$(All_Skills(index) + ":", 14, " ") + Str$(GetSkill(ch, index)), 25, " ") + " " + MakeFitC(MakeFitL$(All_Knowledges(index) + ":", 14, " ") + Str$(GetKnowledge(ch, index)), 24, " ") + " ║"
    Next
    Print "╠══════════════════════════════════════╦═══════════════════════════════════════╣"
    Print "║ Backgrounds:                         ║ Virtues:                              ║"
    Print "║ " + MakeFitL$(background_strings(0), 36, " ") + " ║ " + MakeFitL$(MakeFitL$("Conscience:", 14, " ") + MakeFitR$(Str$(ch.conscience), 2, " "), 37, " ") + " ║"
    Print "║ " + MakeFitL$(background_strings(1), 36, " ") + " ║ " + MakeFitL$(MakeFitR$("Conviction:", 14, " ") + MakeFitR$(Str$(ch.conviction), 2, " "), 37, " ") + " ║"
    Print "║ " + MakeFitL$(background_strings(2), 36, " ") + " ║ " + MakeFitL$(MakeFitR$("Instinct:", 14, " ") + MakeFitR$(Str$(ch.instinct), 2, " "), 37, " ") + " ║"
    Print "║ " + MakeFitL$(background_strings(3), 36, " ") + " ║ " + MakeFitL$(MakeFitR$("Self-Control:", 14, " ") + MakeFitR$(Str$(ch.selfControl), 2, " "), 37, " ") + " ║"
    Print "║ " + MakeFitL$(background_strings(4), 36, " ") + " ║ " + MakeFitL$(MakeFitR$("Courage:", 14, " ") + MakeFitR$(Str$(ch.courage), 2, " "), 37, " ") + " ║"
    Print "╠══════════════════════════════════════╩═══════════════════════════════════════╣"
    Print "║                        <<PRESS ANY KEY TO CONTINUE>>                         ║"
    Print "╚══════════════════════════════════════════════════════════════════════════════╝"

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


