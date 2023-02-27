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
Const Clans_Count = 18
Dim Shared Clans(1 To Clans_Count) As String
Clans(1) = "Anarch"
Clans(2) = "Assamite"
Clans(3) = "Baali"
Clans(4) = "Brujah"
Clans(5) = "Caitiff"
Clans(6) = "Cappadocian"
Clans(7) = "Gangrel"
Clans(8) = "Giovanni"
Clans(9) = "Inconnu"
Clans(10) = "Lasombra"
Clans(11) = "Malkavian"
Clans(12) = "Nosferatu"
Clans(13) = "Ravanos"
Clans(14) = "Settite"
Clans(15) = "Tremere"
Clans(16) = "Toreador"
Clans(17) = "Tzismice"
Clans(18) = "Ventrue"

Const Archetypes_Count = 30
Dim Shared Archetypes(1 To Archetypes_Count) As String
Archetypes(1) = "Architect"
Archetypes(2) = "Autocrat"
Archetypes(3) = "Barbarian"
Archetypes(4) = "Bon Vivant"
Archetypes(5) = "Bravo"
Archetypes(6) = "Caregiver"
Archetypes(7) = "Caretaker"
Archetypes(8) = "Celebrant"
Archetypes(9) = "Child"
Archetypes(10) = "Conformist"
Archetypes(11) = "Conniver"
Archetypes(12) = "Curmudgeon"
Archetypes(13) = "Defender"
Archetypes(14) = "Deviant"
Archetypes(15) = "Director"
Archetypes(16) = "Fanatic"
Archetypes(17) = "Gallant"
Archetypes(18) = "Innovator"
Archetypes(19) = "Jester"
Archetypes(20) = "Judge"
Archetypes(21) = "Loner"
Archetypes(22) = "Martyr"
Archetypes(23) = "Monster"
Archetypes(24) = "Penitent"
Archetypes(25) = "Rebel"
Archetypes(26) = "Rogue"
Archetypes(27) = "Survivor"
Archetypes(28) = "Traditionalist"
Archetypes(29) = "Tyrant"
Archetypes(30) = "Visionary"

Const Disciplines_Count = 24
Dim Shared Disciplines(1 To Disciplines_Count) As String
Disciplines(1) = "Animalism"
Disciplines(2) = "Auspex"
Disciplines(3) = "Bardo"
Disciplines(4) = "Celerity"
Disciplines(5) = "Chimestry"
Disciplines(6) = "Dementation"
Disciplines(7) = "Dominate"
Disciplines(8) = "Fortitude"
Disciplines(9) = "Melpominee"
Disciplines(10) = "Mortis"
Disciplines(11) = "Mytherceria"
Disciplines(12) = "Necromancy"
Disciplines(13) = "Obeah"
Disciplines(14) = "Obfuscate"
Disciplines(15) = "Obtenebration"
Disciplines(16) = "Potence"
Disciplines(17) = "Presence"
Disciplines(18) = "Protean"
Disciplines(19) = "Quietus"
Disciplines(20) = "Serpentis"
Disciplines(21) = "Spiritus"
Disciplines(22) = "Thanantosis"
Disciplines(23) = "Thaumaturgy"
Disciplines(24) = "Vicissitude"

Const AttributeGroups_Count = 3
Dim Shared AttributeGroups(1 To AttributeGroups_Count) As String
AttributeGroups(1) = "Physical"
AttributeGroups(2) = "Social"
AttributeGroups(3) = "Mental"

Const Abilities_Count = 3
Dim Shared Abilities(1 To Abilities_Count) As String
Abilities(1) = "Talents"
Abilities(2) = "Skills"
Abilities(3) = "Knowledges"

Const Talents_Count = 10
Dim Shared Talents(1 To Talents_Count) As String
Talents(1) = "Acting"
Talents(2) = "Alertness"
Talents(3) = "Athletics"
Talents(4) = "Brawl"
Talents(5) = "Dodge"
Talents(6) = "Empathy"
Talents(7) = "Intimidation"
Talents(8) = "Leadership"
Talents(9) = "Streetwise"
Talents(10) = "Subterfuge"

Const Skills_Count = 10
Dim Shared Skills(1 To Skills_Count) As String
Skills(1) = "Animal Ken"
Skills(2) = "Drive"
Skills(3) = "Etiquette"
Skills(4) = "Firearms"
Skills(5) = "Melee"
Skills(6) = "Music"
Skills(7) = "Repair"
Skills(8) = "Security"
Skills(9) = "Stealth"
Skills(10) = "Survival"

Const Knowledges_Count = 10
Dim Shared Knowledges(1 To Knowledges_Count) As String
Knowledges(1) = "Bureaucracy"
Knowledges(2) = "Computer"
Knowledges(3) = "Finance"
Knowledges(4) = "Investigation"
Knowledges(5) = "Law"
Knowledges(6) = "Linguistics"
Knowledges(7) = "Medicine"
Knowledges(8) = "Occult"
Knowledges(9) = "Politics"
Knowledges(10) = "Science"

Const Backgrounds_Count = 10
Dim Shared Backgrounds(1 To Backgrounds_Count) As String
Backgrounds(1) = "Allies"
Backgrounds(2) = "Contacts"
Backgrounds(3) = "Fame"
Backgrounds(4) = "Generation"
Backgrounds(5) = "Herd"
Backgrounds(6) = "Influence"
Backgrounds(7) = "Mentor"
Backgrounds(8) = "Resources"
Backgrounds(9) = "Retainers"
Backgrounds(10) = "Status"

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
    For index = 1 To Disciplines_Count
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
    For index = 1 To Backgrounds_Count
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
    For index = 1 To Disciplines_Count
        Call SetDiscipline(ch, index, 0)
    Next
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
    For index = 1 To Talents_Count
        Call SetTalent(ch, index, 0)
    Next
    ' Skills
    For index = 1 To Skills_Count
        Call SetSkill(ch, index, 0)
    Next
    ' Knowledges
    For index = 1 To Knowledges_Count
        Call SetKnowledge(ch, index, 0)
    Next
    ' Backgrounds
    For index = 1 To Backgrounds_Count
        Call SetBackground(ch, index, 0)
    Next
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
    Call PrintMenu(Clans(), Clans_Count)
    ch.clan = GetChoice(0, Clans_Count)
    If ch.clan > Clans_Count Or ch.clan < 1 Then ch.clan = GetRandomInt(1, Clans_Count)
    Cls
    Print "What is your character's Nature?"
    Call PrintMenu(Archetypes(), Archetypes_Count)
    ch.nature = GetChoice(0, Archetypes_Count)
    If ch.nature > Archetypes_Count Or ch.nature < 1 Then ch.nature = GetRandomInt(1, Archetypes_Count)
    Cls
    Print "What is your character's Demeanor?"
    Call PrintMenu(Archetypes(), Archetypes_Count)
    ch.demeanor = GetChoice(0, Archetypes_Count)
    If ch.demeanor > Archetypes_Count Or ch.demeanor < 1 Then ch.demeanor = GetRandomInt(1, Archetypes_Count)

    ' The character starts with 3 discipline points and they can spend them on one or more disciplines
    DisciplinePoints = 3

    ' I don't like having to build an empty array for return values here. Ideally PrintMenuWithValues could take the character and a mapping fn(index) that
    ' calls GetDiscipline(ch, index) to fetch the value. At least for BASIC this seems like a better solution. PrintMenuWithValues does piss me off though.
    ' I don't want it to exist. I want a formatting function there that takes the character and the index then prints "1 = Bullshit: 3" or something like that.
    ' But we can't have nice things like nested custom types, arrays in custom types, or function objects/pointers.
    ' TODO: Try to find a better way to do this.
    Dim TempDisciplines(Disciplines_Count) As Integer
    While DisciplinePoints > 0
        Cls
        Print "Which discipline do you want to spend 1 of your " + Str$(DisciplinePoints) + " discipline points on?"
        Call FillDisciplines(ch, TempDisciplines())
        Call PrintMenuWithValues(Disciplines(), TempDisciplines(), Disciplines_Count)
        discipline = GetChoice(0, Disciplines_Count)
        If discipline = 0 Then discipline = GetRandomInt(1, Disciplines_Count)
        Call SetDiscipline(ch, discipline, GetDiscipline(ch, discipline) + 1)
        DisciplinePoints = DisciplinePoints - 1
    Wend

    ' This would work, but I want a Print... function to print something like a sparse array to hide the already selected option.
    ' It seems like a lot of work to support other sets of attributes and the code is only reused once for abilities.
    'Const AttributeGroups_Count = 3
    'Dim AttributeGroups(1 To AttributeGroups_Count) As String
    'Const ATTRIBUTE_GROUP_PHYSICAL = 1
    'Const ATTRIBUTE_GROUP_SOCIAL = 2
    'Const ATTRIBUTE_GROUP_MENTAL = 3
    'AttributeGroups(ATTRIBUTE_GROUP_PHYSICAL) = "Physical"
    'AttributeGroups(ATTRIBUTE_GROUP_SOCIAL) = "Social"
    'AttributeGroups(ATTRIBUTE_GROUP_MENTAL) = "Mental"
    'Const ATTRIBUTE_STRENGTH = 1
    'Const ATTRIBUTE_DEXTERITY = 2
    'Const ATTRIBUTE_STAMINA = 3
    'Const ATTRIBUTE_APPEARANCE = 1
    'Const ATTRIBUTE_CHARISMA = 2
    'Const ATTRIBUTE_MANIPULATION = 3
    'Const ATTRIBUTE_INTELLIGENCE = 1
    'Const ATTRIBUTE_PERCEPTION = 2
    'Const ATTRIBUTE_WITS = 3
    'Dim PrimaryAttributeGroup As Integer
    'Do
    '    Cls
    '    For index = 1 To AttributeGroups_Count
    '        Print Str$(index) + " = " + AttributeGroups(index) + " ";
    '    Next
    '    Print "0 = Random"
    '    Input "Choose your primary attribute?", PrimaryAttribute
    '    If PrimaryAttribute = 0 Then PrimaryAttribute = GetRandomInt(1, AttributeGroups_Count)
    'Loop While PrimaryAttribute > AttributeGroups_Count And PrimaryAttribute < 1


    'SetAttribute(ch, group, attr, value)

    ' TODO: Find a more general form for this that stores the chosen attributes in an array
    ' Most of the way this works just pisses me off. The second do loop is the worst part. I want it to be 1 = ..., 2 = ..., 0 = Random
    ' If I can't have that then maybe at least something with less code or less reliance on there being 3 attribute groups.
    Dim PrimaryAttribute As Integer
    Do
        Cls
        Print "1 = " + AttributeGroups(1) + " ";
        Print "2 = " + AttributeGroups(2) + " ";
        Print "3 = " + AttributeGroups(3) + " ";
        Print "0 = Random"
        Input "Choose your primary attribute?", PrimaryAttribute
        If PrimaryAttribute = 0 Then PrimaryAttribute = GetRandomInt(1, AttributeGroups_Count)
    Loop While (PrimaryAttribute > AttributeGroups_Count And PrimaryAttribute < 1)

    Dim SecondaryAttribute As Integer
    Dim TertiaryAttribute As Integer
    Do
        Cls
        If PrimaryAttribute <> 1 Then Print "1 = " + AttributeGroups(1) + " ";
        If PrimaryAttribute <> 2 Then Print "2 = " + AttributeGroups(2) + " ";
        If PrimaryAttribute <> 3 Then Print "3 = " + AttributeGroups(3) + " ";
        Print "0 = Random"
        Input "Choose your secondary attribute?", SecondaryAttribute
        If SecondaryAttribute = 0 Or SecondaryAttribute = PrimaryAttribute Then
            SecondaryAttribute = GetRandomInt(1, AttributeGroups_Count - 1)
            If SecondaryAttribute >= PrimaryAttribute Then
                SecondaryAttribute = SecondaryAttribute + 1
            End If
        End If
    Loop Until SecondaryAttribute >= 1 And SecondaryAttribute <= 3 And SecondaryAttribute <> PrimaryAttribute
    ' General formula for last choice is
    ' Sum(1..AllAttributesCount)-Sum(Choice[1]..Choice[AllAttributesCount-1])
    TertiaryAttribute = 2 * AttributeGroups_Count - PrimaryAttribute - SecondaryAttribute

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
        ' TODO: Make this less hard-coded. Attribute names should be pulled from const arrays. The menu should be printed with PrintMenu.
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

    ' Something like this might work better
    'attr_group_index = 0 ' for 1 to all_attribute_groups_count
    'Points = 0
    'Do
    '    Cls
    '    attr_count = GetAttributeCountInAttributeGroup(attr_group_index)
    '    Dim attrs(attr_count) As String
    '    Call FillAttributesFromGroup(attrs, attr_group_index)
    '    Print "Which attribute would you like to spend 1 of your " + Str$(Points) + " points on?"
    '    PrintMenuWithValues(attrs, values, states, showRandom)
    '    attr = GetChoice(states, showRandom)
    '    if (attr = 0 then attr = GetRandomIndex(1, attr_count, states)
    '    SetAttribute(ch, attr_group_index, attr, GetAttribute(ch, attr_group_index, attr) + 1)
    '    points = points - 1
    'Loop While Points > 0

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
        Print "1 = " + Abilities(1) + " ";
        Print "2 = " + Abilities(2) + " ";
        Print "3 = " + Abilities(3) + " ";
        Print "0 = Random"
        Input "Choose your primary ability?", PrimaryAbility
        If PrimaryAbility = 0 Then PrimaryAbility = GetRandomInt(1, Abilities_Count)
    Loop While (PrimaryAbility > Abilities_Count And PrimaryAbility < 1)

    Dim SecondaryAbility As Integer
    Dim TertiaryAbility As Integer
    Do
        Cls
        If PrimaryAbility <> 1 Then Print "1 = " + Abilities(1) + " ";
        If PrimaryAbility <> 2 Then Print "2 = " + Abilities(2) + " ";
        If PrimaryAbility <> 3 Then Print "3 = " + Abilities(3) + " ";
        Print "0 = Random"
        Input "Choose your secondary ability?", SecondaryAbility
        If SecondaryAbility = 0 Or SecondaryAbility = PrimaryAbility Then
            SecondaryAbility = GetRandomInt(1, Abilities_Count - 1)
            If SecondaryAbility >= PrimaryAbility Then
                SecondaryAbility = SecondaryAbility + 1
            End If
        End If
    Loop Until SecondaryAbility >= 1 And SecondaryAbility <= 3 And SecondaryAbility <> PrimaryAbility
    TertiaryAbility = 2 * Abilities_Count - PrimaryAbility - SecondaryAbility

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
        For index = 1 To Talents_Count
            Print MakeFitR$(Str$(index), 2, " ") + " = " + MakeFitL$(Talents(index) + ":", 20, " ") + " " + MakeFitR$(Str$(GetTalent(ch, index)), 3, " ")
        Next
        talent = GetChoice(0, Talents_Count)
        If talent = 0 Then talent = GetRandomInt(1, Talents_Count)
        Call SetTalent(ch, talent, GetTalent(ch, talent) + 1)
        TalentPoints = TalentPoints - 1
    Loop While TalentPoints > 0

    ' Spend skill points
    Do
        Cls
        Print "Which skill would you like to spend 1 of your " + Str$(SkillPoints) + " points on?"
        Print " 0 = Random"
        For index = 1 To Skills_Count
            Print MakeFitR$(Str$(index), 2, " ") + " = " + MakeFitL$(Skills(index) + ":", 20, " ") + " " + MakeFitR$(Str$(GetSkill(ch, index)), 3, " ")
        Next
        skill = GetChoice(0, Skills_Count)
        If skill = 0 Then skill = GetRandomInt(1, Skills_Count)
        Call SetSkill(ch, skill, GetSkill(ch, skill) + 1)
        SkillPoints = SkillPoints - 1
    Loop While SkillPoints > 0

    'Spend knowledge points
    Do
        Cls
        Print "Which knowledge would you like to spend 1 of your " + Str$(KnowledgePoints) + " points on?"
        Print " 0 = Random"
        For index = 1 To Knowledges_Count
            Print MakeFitR$(Str$(index), 2, " ") + " = " + MakeFitL$(Knowledges(index) + ":", 20, " ") + " " + MakeFitR$(Str$(GetKnowledge(ch, index)), 3, " ")
        Next
        knowledge = GetChoice(0, Knowledges_Count)
        If knowledge = 0 Then knowledge = GetRandomInt(1, Knowledges_Count)
        Call SetKnowledge(ch, knowledge, GetKnowledge(ch, knowledge) + 1)
        KnowledgePoints = KnowledgePoints - 1
    Loop While KnowledgePoints > 0

    ' Spend background points
    BackgroundPoints = 5
    Dim TempBackgrounds(Backgrounds_Count) As Integer
    While BackgroundPoints > 0
        Cls
        Print "Which background do you want to spend 1 of your " + Str$(BackgroundPoints) + " background points on?"
        Call FillBackgrounds(ch, TempBackgrounds())
        Call PrintMenuWithValues(Backgrounds(), TempBackgrounds(), Backgrounds_Count)
        background = GetChoice(0, Backgrounds_Count)
        If background = 0 Then background = GetRandomInt(1, Backgrounds_Count)
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

    ' TODO: figure out how to actually calculate generation; seems like a combination of 13 or 15 depending on clan and your generation background count
    generation$ = "13"
    If ch.sex = 1 Then sex_string$ = "Male" Else sex_string$ = "Female"
    clan_string$ = Clans(ch.clan)

    Dim discipline_strings(3) As String
    discipline_strings_index = 0
    For index = 1 To Disciplines_Count
        If TempDisciplines(index) > 0 Then
            suffix$ = ""
            If TempDisciplines(index) > 1 Then
                suffix$ = " x" + Str$(TempDisciplines(index))
            End If
            discipline_strings(discipline_strings_index) = Disciplines(index) + suffix$
        End If
    Next

    Dim background_strings(5) As String
    background_strings_index = 0
    For index = 1 To Backgrounds_Count
        If TempBackgrounds(index) > 0 Then
            suffix$ = ""
            If TempBackgrounds(index) > 1 Then
                suffix$ = " x" + Str$(TempBackgrounds(index))
            End If
            background_strings$(background_strings_index) = Backgrounds(index) + suffix$
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
    Print "บ " + MakeFitL$(discipline_strings(0), 36, " ") + " บ _____________________________________ บ"
    Print "บ " + MakeFitL$(discipline_strings(1), 36, " ") + " บ _____________________________________ บ"
    Print "บ " + MakeFitL$(discipline_strings(2), 36, " ") + " บ _____________________________________ บ"
    Print "ฬออออออออออออออออออออออออออออออออออออออฮอออออออออออออออออออออออออออออออออออออออน"
    Print "บ Typhon:  7                           บ Nature: " + MakeFitL$(Archetypes(ch.nature), 29, " ") + " บ"
    Print "บ Willpower: 3                         บ Demeanor: " + MakeFitL$(Archetypes(ch.demeanor), 27, " ") + " บ"
    Print "ฬออออออออออออออออออออออออออออออออออออออสอออออออออออออออออออออออออออออออออออออออน"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ                        <<PRESS ANY KEY TO CONTINUE>>                         บ"
    Print "ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ"
    Input A
    Print "ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป"
    Print "บ " + MakeFitC$("Abilities", 76, " ") + " บ"
    Print "บ " + MakeFitC$("Talents", 25, " ") + " " + MakeFitC$("Skills", 25, " ") + " " + MakeFitC$("Knowledges", 24, " ") + " บ"
    For index = 1 To 10
        Print "บ " + MakeFitC(MakeFitL$(Talents(index) + ":", 14, " ") + Str$(GetTalent(ch, index)), 25, " ") + " " + MakeFitC(MakeFitL$(Skills(index) + ":", 14, " ") + Str$(GetSkill(ch, index)), 25, " ") + " " + MakeFitC(MakeFitL$(Knowledges(index) + ":", 14, " ") + Str$(GetKnowledge(ch, index)), 24, " ") + " บ"
    Next
    Print "ฬออออออออออออออออออออออออออออออออออออออหอออออออออออออออออออออออออออออออออออออออน"
    Print "บ Backgrounds:                         บ Virtues:                              บ"
    Print "บ " + MakeFitL$(background_strings(0), 36, " ") + " บ " + MakeFitL$(MakeFitL$("Conscience:", 14, " ") + MakeFitR$(Str$(ch.conscience), 2, " "), 37, " ") + " บ"
    Print "บ " + MakeFitL$(background_strings(1), 36, " ") + " บ " + MakeFitL$(MakeFitR$("Conviction:", 14, " ") + MakeFitR$(Str$(ch.conviction), 2, " "), 37, " ") + " บ"
    Print "บ " + MakeFitL$(background_strings(2), 36, " ") + " บ " + MakeFitL$(MakeFitR$("Instinct:", 14, " ") + MakeFitR$(Str$(ch.instinct), 2, " "), 37, " ") + " บ"
    Print "บ " + MakeFitL$(background_strings(3), 36, " ") + " บ " + MakeFitL$(MakeFitR$("Self-Control:", 14, " ") + MakeFitR$(Str$(ch.selfControl), 2, " "), 37, " ") + " บ"
    Print "บ " + MakeFitL$(background_strings(4), 36, " ") + " บ " + MakeFitL$(MakeFitR$("Courage:", 14, " ") + MakeFitR$(Str$(ch.courage), 2, " "), 37, " ") + " บ"
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
