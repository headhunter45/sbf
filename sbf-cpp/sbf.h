#ifndef SBF_H__
#define SBF_H__
/***************************************************************************************
 * @file sbf.h
 *
 * @brief Holds code copied from the BASIC version that hasn't been relocated yet.
 * @copyright
 * Copyright 2023 Tom Hicks
 * Licensed under the MIT license see the LICENSE file for details.
 ***************************************************************************************/
#include <string>

/** \addtogroup Unsorted
 * @{
 */
namespace SBF {
using std::string;
/*
' This sub is not called. It is here so it can be copied whenever I need to make a new bordered screen.
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


    '... 0123456789
    '160 áíóúñÑªº¿⌐
    '170 ¬½¼¡«»░▒▓│
    '180 ┤╡╢╖╕╣║╗╝╜
    '190 ╛┐└┴┬├─┼╞╟
    '200 ╚╔╩╦╠═╬╧╨╤
    '210 ╥╙╘╒╓╫╪┘┌█
    '220 ▄▌▐▀αßΓπΣσσ
    '230 µτΦΘΩδ2∞φε∩
    ' enquote forms s/^([╔║╚═╠].*[╗║╝╣])$/print "$1"/g
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

' Like the character generator but for vehicles. Much simpler with fewer questions. Prints a vehicle sheet when done.
Never finished and crashes mid way through currently. Sub VehicleGenerator Call MaybePrint("VehicleGenerator") End Sub

Sub MaybePrint (message As String)
    If isDebugging Then Print message
End Sub

*/
}  // End namespace SBF

/** #}*/
#endif  // End !defined SBF_H__
