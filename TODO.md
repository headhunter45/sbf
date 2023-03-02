# High Priority
* Calculate conviction.
* Calculate instinct.
* Calculate roadValue aka humanity in VtM, and something else in WtA.
* Calculate willpower.
* Input/Print derangements. These are only for Malkavian vampires.
    * If the clan is malk then ask to pick a derangement. Maybe more than one?
    * Print any derangements on the character on the character sheet.
        * This section is the last section with dummy text.
    * Figure out how to support something like this for various rulesets.
    * VtDA has malks so it would need this.
    * WtA doesn't obviously have them, but it may have something else that requires a specific question/addition to CharacterType.
    * Make this generic if possible.

# Low Priority
* Add freebie points see page 92 VtM
    * After other generation steps allow spending the freebie points on adding dots to the sheet. This should be a nested menu like "What do you want to spend points on? -> Which of those things do you want to add a dot to?
    * We probably want to show the character sheet before asking or give the user a way to display it in the main menu of this section.
* Rename items, abilities/abilities, abilityGroups rename the shared arrays and constants too
* Change CharacterType to use fields like attribute_1_1 instead of attr_strength
    * Same for abilities like knowledge_computer -> ability_3_2, background_allies -> background_1, and discipline_obeah -> discipline_13.
    * This would let us hard-code a given number of those fields so other format plugins can use up to that number at least.
* See if other combinations of clan and other variables cause missed questions.
* Add blood pool to sheet and figure out what should replace it for non-vampires.
    * Generation affects blood pool page 173 VtM.
* Create a way to choose between VtM, VtDA, and WtA then load the appropriate lookup tables.
    * Completely generic plugin support would be great, but not possible.
    * Have specific predefined rulsets in the app.
    * Make the user pick one when loading the app or maybe when choosing a top level menu item.
    * Try to allow for creating a random character from a random ruleset.
    * Try to find a way for the character sheet display/saved files use a different format per ruleset.
    * Maybe support sub rulesets as additions to an existing ruleset.
        * VtDA would be an addition to VtM so VtM+VtDA would also be a ruleset.
        * Add additional abilities/attributes /clans/disciplines/background/roads/whatever exists to arrays and character sheets.
        * Ideally this would let you create an ancient character in a modern system using a clan only available in the older system.
        * Would be a neat thing to do it by character age where an old enough VtM character either gets additional access to VtDA stuff or for certain things only has access to VtDA stuff.
        * Allowing them to also spend points on any of the VtDA talents/skills/knowledges/backgrounds/disciplines, but only let them choose VtDA clans.
* Extract the menu stuff to it's own bas file.
    * https://qb64.com/wiki/TYPE
    * https://qb64.com/wiki/$INCLUDE
        * lib.BI - Type definitions. Include at the beginning of program.
            * Include any dim, const, shared, or data.
        * lib.BM - Sub/Function definitions. Include at the end of program.
    * pm, PrintMenu, PrintMenuWithValues
    * MenuItem/NewMenuItem
    * MenuStyle/NewMenuStyle
    * GetRandomMenuItem
    * GetChoice?
    * GetRandomInt?    
* Extract each of the top-level menu items into their own files.
* Extract CharacterType and it's associated funcs/subs to their own files. (CharacterType.bi, CharacterType.bm)
* Extract show character sheet and save character to their own files or maybe put them in the CharacterType files.
* Extract the ui utility funcs/subs into their own files. MakeFit*, itos$, ...
* Add support for roads.
    * VtM only has one. Humanity.
        * If there is only one like this then choose it and don't ask.
        * If there are none do something sensible so it doesn't output to the character sheet and we don't ask for a value.
    * VtDA has a handfull and I don't think any are humanity.
    * I don't know what WtA has, but I think it has something comparable.
* Move initializers, getters, setters, fillers, and other utility methods for a type together.
    * Probably not next to the type definition.
    * Look into pulling out these "classes" into separate bas files as appropriate.
    * I want to get this definition clutter out of the main bas.
* Make empty strings show as "blank lines" on the character sheet so they can be filled in by hand.

# Super-Low Priority
* Make GetAttributePointsForRank and GetAbilityPointsForRank use a formula maybe.
* GetAbilityValue/SetAbilityValue use a select case and individual GetTalent, GetSkill, ... functions. Try to find a way around this.
    * Maybe not possible without abstracting further in CharacterType and maybe also not possible to support the array defined stuff.
    * Same for GetAttributeValue/SetAttribute.
* Make pm and MenuStyle and thus PrintMenu and PrintMenuWithValues let you print inside of ascii art boxes like the main menu screen.
* Make pm and MenuStyle let you print menus like the main menu both full screen and wrap_content width and/or height. Hell maybe let you center them vertically/horizontally and still take up a full screen.
* Find a way to support PrintMenuWithValues(Disciplines(), DISCIPLINES_COUNT, ch, ...)
    * Instead of PrintMenuWithValues(Disciplines(), disciplineValues(), DISCIPLINES_COUNT)
    * This would use the extra params to inspect ch for the discipline values instead of building a separate array.
    * This should also work for backgrounds.
    * Probably attributes/abilities too. Specifically things with more than 1 dimension.
        * PrintMenuWithValues(Attributes(), attributeCount, ch, attrGroup)
        * PrintMenuWithValues(PhysicalAttributes(), PHYSICAL_ATTRIBUTES_COUNT, ch, 1)
        * PrintMenuWithValues(PROP_ATTRIBUTES, ch, ATTRIBUTE_PHYSICAL)
        * All of these would do something like build a MenuItem for each with an id of the attribute id const, a label of the attribute name, and a value of ch(attrGroup, attrIndex)
    * This will probably just go away by converting to pm over PrintMenu and PrintMenuWithValues, because we'll be creating an array of MenuItems for each one. We still have to fill the array each time, but we can look into making that suck less afterwards.
* Get attribute/ability/rank names from arrays when to print them (plural and singular) in loops like "Choose your tertiary attribute?" and "Which talent would you like to spend 1 of your 6 points on?"
* Reorganize functions/subs so the order/grouping makes more sense. move all global dims together and group them with their constants.
* Consider supporting freeform gender strings.
    * The main reason for not doing this is limiting the string length.
    * We don't do it for other strings, but we don't want to add more until we have a good way to handle them.
    * Should we let you know on input that it's too long.
    * How/where can se store the specific length in a way that allows for multiple character sheet formats.
    * Maybe just say fuck it and leave that up to the user to know it's too long when it gets cut off.
    * We also like keeping it like this because it suggests "other" genders better than a freeform string.
        * In a text-based ui it may seem like male/female are the expected options and users would likely not even consider that there are other options.
* Move the ruleset dims/constants/getters/setters out into separate bi/bm files.
    * Probably 1 pair of files per system
    * Really wish we had function pointers so each ruleset object could be a bunch of fn pointers instead of each stub method being a giant ass select case.
    * Maybe keep stubs for the functions in the main bas that call the rulset specific versions.
        * This would work if we can't sanely load/unload the other bas files at runtime.
        * Create a Rulesets array and RULESET_* constants.
        * Make all of these methods take a RULESET_* constant in addition to their current params.
        * Make each ruleset variant of these methods be prefixed with the ruleset code (vtm, vtda, wta, ...).
        * Have the stubs use a select case to call the specific ruleset variant based on the RULESET_* constant passed in.
        * Maybe only load the ruleset bas files as they are required to save memory. If we can't unload this could still suck.
            * Imagine telling someone you've created to many classes of character. You need to close and reopen the program if you want to create any new classes, but you can create more of the old ones.

# Uncategorized
* Remove count being passed in and instead check UBOUND and LBOUND.
    * Add an assert for when labels() and values() arrays don't have the same bounds.
* Look into DECLARE LIBRARY to add ruleset plugin support.
* Consider using _MEM to put arrays into CharacterType for things like attributes, abilities, disciplines, backgrounds, ...
* Add an icon with $EXEICON
* Look into _TITLE.
    * Assuming it lets us set the window title.
    * Wiki page currently 404's
        * https://qb64.com/wiki/_TITLE
        * https://qb64.com/wiki/_TITLE$
* Add version info with $VERSIONINFO:key=value
    * Keys are
        * Comments
        * CompanyName
        * FileDescription
        * FileVersion
        * InternalName
        * LegalCopyright
        * LegalTrademarks
        * OriginalFilename
        * ProductName
        * ProductVersion
        * Web
        * FILEVERSION#
        * PRODUCTVERSION#
        * `$VERSIONINFO:CompanyName=Your company name goes here`
        * `$VERSIONINFO:FILEVERSION#=1,0,0,0`
        * `$VERSIONINFO:PRODUCTVERSION#=1,0,0,0`
* Look into error logging.
    * Ideally create an abstracted LogError sub that throws an error in debug mode but silently does nothing in a non-debug build.
    * _ASSERT
    * https://qb64.com/wiki/ERROR
    * https://qb64.com/wiki/ERROR-Codes
    * Custom error codes from 100 to 199
    * Maybe use 27 - Out of paper.
* Use LogError in all of the SELECT CASE blocks without a CASE ELSE to throw an unknown index error.
* Sort virtues better on the character sheet.
    * Why are conviction and instinct between them?
* Start work on ports
    * Mainly the C++ port.
    * Consider a python port to refresh my python skills.
    * Assembly port?
        * For what arch though? x86, x86_64, aarch64
    * NDS/3DS
    * PSP/PSVita
    * Wii/WiiU
    * Xbox One
    * PS4/PS5? Not sure if there's an easily available dev mode.
    * Switch hehe
    * Maybe nes, but text input will suck.
    * Add a GUI. ick.
* MakeFitS
    * Spread inputs
    * `MakeFitS$(strings$ as string, length as integer, padChar as string)
    * No real good way to use this without array literals.
    * Building an array of strings to call it just makes the code less readable
* Consider removing the pad parameter from all the MakeFit* functions.
    * We're only ever using a single space char.
* Support other screen sizes and running in a proper resizable terminal.

# Reference
* QB64 Wiki [https://qb64.com/wiki]
