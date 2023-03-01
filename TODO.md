# High Priority
* Calculate generation.
* Calculate conscience.
* Calculate conviction.
* Calculate instinct.
* Calculate self-control.
* Calculate courage.
* Calculate roadValue aka humanity in VtM, and something else in WtA.
* Calculate willpower.
* Input/Print derangements. These are only for Malkavian vampires.
    * Figure out how to support something like this for various rulesets.
    * VtDA has malks so it would need this.
    * WtA doesn't obviously have them, but it may have something else that requires a specific question/addition to CharacterType.
    * Make this generic if possible.
* Replace all uses of PrintMenu and PrintMenuWithValues use pm and specific MenuStyles
    * Rename pm to PrintMenu after this is done.
* Spending virtue points
* Support genders other than male/female.
    * Change all references to sex to gender instead.

# Low Priority
* Calculating values not directly queried for.
    * Conviction
    * Instinct
    * Generation
    * Willpower
    * Humanity/RoadValue
* Change character initializer to use abilityGroups/abilities instead of individual setTalent, setSkill, setKnowledge
* Rename items, abilities/abilities, abilityGroups rename the shared arrays and constants too
* Change CharacterType to use fields like attribute_1_1 instead of attr_strength
    * Same for abilities like knowledge_computer -> ability_3_2, background_allies -> background_1, and discipline_obeah -> discipline_13.
    * This would let us hard-code a given number of those fields so other format plugins can use up to that number at least.
* See if other combinations of clan and other variables cause missed questions.
* Add blood pool to sheet and figure out what should replace it for non-vampires.
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
    * pm, PrintMenu, PrintMenuWithValues
    * MenuItem/NewMenuItem
    * MenuStyle/NewMenuStyle
    * GetRandomMenuItem
    * GetChoice?
    * GetRandomInt?    
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

# Uncategorized
* Move the ruleset dims/constants/getters/setters out into separate bas files.
    * Probably 1 file per system
    * Maybe keep stubs for the functions in the main bas that call the rulset specific versions.
        * This would work if we can't sanely load/unload the other bas files at runtime.
        * Create a Rulesets array and RULESET_* constants.
        * Make all of these methods take a RULESET_* constant in addition to their current params.
        * Make each ruleset variant of these methods be prefixed with the ruleset code (vtm, vtda, wta, ...).
        * Have the stubs use a select case to call the specific ruleset variant based on the RULESET_* constant passed in.
        * Maybe only load the ruleset bas files as they are required to save memory. If we can't unload this could still suck.
            * Imagine telling someone you've created to many classes of character. You need to close and reopen the program if you want to create any new classes, but you can create more of the old ones.
