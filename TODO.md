# High Priority
* Add freebie points see page 92 VtM
    * After other generation steps allow spending the freebie points on adding dots to the sheet. This should be a nested menu like "What do you want to spend points on? -> Which of those things do you want to add a dot to?
    * We probably want to show the character sheet before asking or give the user a way to display it in the main menu of this section.
* Add blood pool to sheet and figure out what should replace it for non-vampires.
    * Generation affects blood pool page 173 VtM.
* Make empty strings show as "blank lines" on the character sheet so they can be filled in by hand.
* Rename items, abilities/abilities, abilityGroups rename the shared arrays and constants too
* See if other combinations of clan and other variables cause missed questions.

# Low Priority
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
* Add support for roads.
    * VtM only has one. Humanity.
        * If there is only one like this then choose it and don't ask.
        * If there are none do something sensible so it doesn't output to the character sheet and we don't ask for a value.
    * VtDA has a handfull and I don't think any are humanity.
    * I don't know what WtA has, but I think it has something comparable.
* Change CharacterType to use fields like attribute_1_1 instead of attr_strength
    * Same for abilities like knowledge_computer -> ability_3_2, background_allies -> background_1, and discipline_obeah -> discipline_13.
    * This would let us hard-code a given number of those fields so other format plugins can use up to that number at least.
* Extract the menu stuff to it's own bas file.
    * GetChoice?
    * GetRandomInt?    
* Extract each of the top-level menu items into their own files.
* Extract show character sheet and save character to their own files or maybe put them in the CharacterType files.
* Extract the ui utility funcs/subs into their own files. MakeFit*, itos$, ...

# Super-Low Priority
* Make GetAttributePointsForRank and GetAbilityPointsForRank use a formula maybe.
* GetAbilityValue/SetAbilityValue use a select case and individual GetTalent, GetSkill, ... functions. Try to find a way around this.
    * Maybe not possible without abstracting further in CharacterType and maybe also not possible to support the array defined stuff.
    * Same for GetAttributeValue/SetAttribute.
* Make PrintMenu and MenuStyle let you print inside of ascii art boxes like the main menu screen.
* Make PrintMenu and MenuStyle let you print menus like the main menu both full screen and wrap_content width and/or height. Hell maybe let you center them vertically/horizontally and still take up a full screen.
* Find a way to support PrintMenu(Disciplines(), DISCIPLINES_COUNT, ch, ...)
    * Ideally this would be PrintMenu(Disciplines(), DISCIPLINES_COUNT, ch, (id as Integer, ch as CharacterType) { return ch.getDisciplineValue(id);}), but we don't have anonymous functions, function pointers, or inheritance.
    * Maybe something like PrintMenu(Disciplines(), DISCIPLINES_COUNT, ch, VALUE_DISCIPLINE)
        * This would call something like BuildValues(ch, VALUE_DISCIPLINE) internally before doing the actual print.
    * Instead of PrintMenuWithValues(Disciplines(), disciplineValues(), DISCIPLINES_COUNT)
    * This would use the extra params to inspect ch for the discipline values instead of building a separate array.
    * This should also work for backgrounds.
    * Probably attributes/abilities too. Specifically things with more than 1 dimension.
        * PrintMenuWithValues(Attributes(), attributeCount, ch, attrGroup)
        * PrintMenuWithValues(PhysicalAttributes(), PHYSICAL_ATTRIBUTES_COUNT, ch, 1)
        * PrintMenuWithValues(PROP_ATTRIBUTES, ch, ATTRIBUTE_PHYSICAL)
        * All of these would do something like build a MenuItem for each with an id of the attribute id const, a label of the attribute name, and a value of ch(attrGroup, attrIndex)
    * This will probably just go away by converting to pm over PrintMenu and PrintMenuWithValues, because we'll be creating an array of MenuItems for each one. We still have to fill the array each time, but we can look into making that suck less afterwards.
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
* Check input types/validation on the old app.
    * Is age a freeform string or not.
    * How are the saved characters getting things like "lllllll" for a demeanor.
    * How are the saved characters getting blank lines "________" for age/name/nature/demeanor/clan/...?
    * What happens if you choose physical as your primary, secondary, and tertiray attribute? Probably something bad.
# Reference
* QB64 Wiki [https://qb64.com/wiki]

# Charcter Creation Process from VtDA
## Step One
* Concept
* Clan
* Nature
* Demeanor
* Road

## Step Two
* Attribute Priorities
    * Physical/Social/Mental
    * 7/5/3 Points
* Spend Ability Points

## Step Three
* Ability Priorities
    * Talents/Skills/Knowledges
    * 13/9/5
    * No ability higher than e

## Step Four
* Disciplines (4)
* Backgrounds (5)
* Virtues (7)

## Step Five
* Calculate These
    * Via
    * Willpower
    * Blood Pool

# Archetypes (from page 102)
* Autocrat: Stability requires order. Bring it about.
* Barbarian: Civilization is a joke; honor is everything. Caretaker: Suffering is everywhere; you must temper it with love. Celebrant: Something fills you with joy, and you cannot hide that pleasure.
* Child: You?re young, or at least appear to be so.
* Defender: The meek must be protected from the wicked by the strong.
* Fanatic: Your cause is everything to you.
* Gallant: Grace is all that counts; romance is your ideal, and God?s (or the Devil?s) will your pleasure.
* Innovator: There is always a better way to do something. Your task is to bring it about.
* Jester: There is too much pain in the world to endure without laughter. You make a mockery of sadness.
* Judge: You seek justice for everyone.
* Loner: You?ve never fit in and never will.
* Monster: God has demanded that you play the beast; who are you to argue?
* Penitent: Your sins can only be forgiven after you prove your true worth.
* Rebel: You?re sick of being ordered around! Hide your feelings well and work for the time of change.
* Rogue: To hell with rules, to hell with everyone! Life (or unlife) is yours to plunder.
* Survivor: No matter what storms sweep through, you will always prevail.
* Tyrant: The only way to get things done is to do them your way! All other paths are folly.

# Sample Concepts (from page 102)
* Artisan ? limner, musician, embroiderer, weaponmaster
* Beggar ? cripple, escaped slave, debtor, mutilated felon, veteran
* Clergy ? monk, priest, bishop, nun, laity, servant, student, mystic
* Craftsman ? smith, tailor/seamstress, stonecutter, armorer
* Dispossessed ? refugee, Jew, Moor, foreigner, Celt, disinherited noble, slave
* Heretic ? pagan, unorthodox Christian, Infernalist, witch, occultist, sorcerer
* Knight ? squire, errant, courtier, poor knight
* Lowlife ? drunkard, prostitute, moneylender, traveling player, brawler, defrocked clergyman
* Nobility ? baron(ess), royal heir, crusader, bastard, rake
* Outlander ? barbarian, Oriental, traveler, Moslem, spy, slave, caravaner
* Peasant ? servant, farmer, shepherd, stablehand, tavern girl, serf
* Pilgrim ? crusader, penitent, mad monk, palmer
* Retainer ? huntsman, ranger, seneschal, bard, sergeant- at-arms, torturer, lady-in-waiting, steward, diplomat
* Scholar ? student, scribe, physician, alchemist, sage, theologian
* Soldier ? man-at-arms, mercenary, grizzled vet, guard, assassin
* Tradesman ? bard, innkeeper, traveling trader, animal trainer
* Wanderer ? vagabond, thief, bard, exile, camp follower
* Youth ? runaway, child, apprentice, heir, squire, urchin

## Roads (from page 102, see page 113)
* Road of the Beast: Feed the Beast, that it will not break its chains.
* Road of Blood: Vampiric blood grants the power for revenge.
* Road of Chivalry: Treat your equals with honor and your betters with respect.
* Road of the Devil: We are created evil and must play our part.
* Road of Heaven: God made us vampires to exact His wrath.
* Road of Humanity: The struggle to maintain one?s humanity.
* Road of Paradox: Existence is a lie; change reality for the better.
* Road of Typhon: Sin and corruption are the keys to under- standing.

## Clans (from page 103)
*  Assamites: The mysterious ?Saracens? of the Middle East have perfected the art of the silent kill.
*  Brujah: Philosophers, scholars and athletes, the fractious ?zealots? pursue their dream of a perfect society.
*  Cappadocians: Seeking the wisdom of the grave, the ?graverob- bers? call on the spirits of the dead for enlightenment.
*  Followers of Set: Originally hailing from Egypt, the ?serpents? spread corruption and vice in their path.
*  Gangrel: Wanderers and rustics, the ?animals? are closer to the beasts of the forests than to any of their Cainite kin.
*  Lasombra: Masters of darkness and shadows, the ?magisters? seek to control mortal and vampiric society alike.
*  Malkavians: Cursed with insanity, the ?madmen? enjoy a surreal and disturbing insight.
*  Nosferatu: Hideous beyond words, the ostracized ?lepers? are spies and informants without equal.
*  Ravnos: Wandering vagabonds and hucksters, the ?charlatans? gleefully practice their arts of deception and theft.
*  Toreador: Lovers of art and beauty, the ?artisans? freely indulge their tastes for the aesthetic.
*  Tremere: A recent and insular clan, the sorcerous ?usurpers? are struggling to establish themselves.
*  Tzimisce: Terrible Slavic fleshcrafters, the ?fiends? mercilessly rule over their mortal subjects.
*  Ventrue: Imperious and commanding, the ?patricians? consider it their duty to lead vampiric society.
*  Caitiff: The rare and luckless Cainites with no clan are outcasts and disgraced.

## Backgrounds (from page 103)
*  Allies: Human confederates, usually family or friends.
*  Contacts: The number of information sources the character possesses.
*  Generation: How far removed from Caine the character is.
*  Herd: The vessels to which the character has free and safe access.
*  Influence: The character?s political power within mortal society.
*  Mentor: The Cainite patron who advises and supports the character.
*  Resources: Wealth, belongings and monthly income.
*  Retainers: Followers, guards and servants.
*  Status: The character?s standing in undead society.

## Disciplines (from page 103)
*  Animalism: Supernatural affinity with and control of animals.
*  Auspex: Extrasensory perception, awareness and premonitions.
*  Celerity: Supernatural quickness and reflexes.
*  Chimerstry: The ability to create illusions and hallucinations.
*  Dementation: The ability to pass madness on to a victim.
*  Dominate: Mind control practiced through the piercing gaze.
*  Fortitude: Unearthly toughness, even to the point of resisting fire and sunlight.
*  Mortis: The supernatural power to control the process of death.
*  Obfuscate: The ability to remain obscure and unseen, even in crowds.
*  Obtenebration: The unearthly control over shadows.
*  Potence: The Discipline of physical vigor and strength.
*  Presence: The ability to attract, sway and control crowds.
*  Protean: Shapechanging ? from growing claws to melding with the earth.
*  Quietus: The Assamites? arts of the silent kill.
*  Serpentis: The reptilian, corruptive Discipline of the Followers of Set.
*  Thaumaturgy: The study and practice of sorcery.
*  Vicissitude: The Tzimisce art of flesh-shaping.

## Freebie Points (from page 103)
|Trait|Cost|
|-|-|
|Attributes|5 per dot|
|Abilities|2 per dot|
|Backgrounds|1 per dot|
|Willpower|1 per dot|
|Disciplines|7 per dot|
|Virtues|2 per dot|
|Roads|1 per dot|

## Experience Costs

|Trait|Cost|
|-|-|
|New Ability|3|
|New Thaumaturgy Path|7|
|New Discipline|10|
|Willpower|Current Rating|
|Road|Current Rating x2|
|Ability|Current Rating x2|
|Attribute|Current Rating x4|
|Thaumaturgy Path (primary)|Current Rating x4|
|Thaumaturgy Path (secondary)|Current Rating x5|
|Clan Discipline|Current Rating x5|
|Other Discipline|Current Rating x7|

# Questions and Answers (from pages 107-100)
* How old are you?
    * When were you born?
    * When were you embraced?
* What was your mortal life like?
* When did you first meet a vampire?
* Who was your sire?
* How do you feel about mortals?
* How did you begin to look at yourself?
* How did you meet the rest of your coterie?
* Where is your territory?
* What drives you?


* Example Filled In Character Sheet page 106
* Archetype descriptions pages 109-113
* Road descriptions pages 113-117
* Attribute descriptions pages 117-119
* Ability descriptions pages 119-128
    * Talents pages 119-122
    * Skills pages 122-125
    * Knowledges pages 125-128
* Backgrounds pages 128-130
* Virtues pages 130-132
* Roads 

# Character Creation VtM (from page 87)
* Step One: Character Concept
    * Concept
    * Clan
    * Nature
    * Demeanor
* Step Two: Choose Attributes
    * Physical/Social/Mental
    * 7/5/3
* Step Three: Choose Abilities
    * Priorities
    * Spend Points
        * Talents/Skills/Knowledges
        * 13/9/7
* Step Four: Choose Advantags
    * Disciplines
    * Backgrounds
    * Virtues
* Step Five: Last Touches
    * Willpower
    * Humanity
    * Blood Pool

## Concepts (from page 87)

* Criminal - jailbird, mafioso, cat burglar, drug dealer, bandit
* Dilettante - artist, writer, intellectual, gambler, student
* Drifter - hobo, cowboy, prostitute, hermit, pilgrim
* Entertainer - comic, musician, movie star, clown
* Investigator - detective, cop, government agent, inquisitor
* Kid - hild, runaway, nerd, gang member, street urchin
* Outsider - aborigine,ThirdWorldresident,homosexual
* Politician -  judge, mayor, senator, public official, governor
* Professional - engineer, doctor, mortician, scholar
* Punk - club crawler, masher, skinhead, classic '70s punk
* Reporter - anchorperson, newspaper, paparazzo, town crier
* Soldier - bodyguard, mercenary, Green Beret, knight
* Worker - trucker, farmer, wage slave, servant, serf

## Clans (from page 87)
*Brujah: Respecting no authority and acknowledging no leaders, the "rabble" consider themselves free.
? Gangrel: Loners and rustics, the "outlanders" are the only Kindred who dare venture outside the cities.
? Malkavian: Commonly (and correctly) believed to be insane, the "kooks" nonetheless possess an uncanny
VISion and wisdom.
? Nosferatu: Ostracizedand misunderstood by others, the hideous "sewerrats" ltve out their sordid existences in hiding.
? Toreador: Known for their hedonistic ways, the "degenerates" prefer to think of themselves as artists.
? Tremere: Wizards descended from an ancient legacy, the "warlocks" work together to increase their influence and power.
? Ventrue: Aristocrats of rarefied taste and manner, the "blue bloods" are leaders of cool cunning.
? Caitiff: Those with no clan - the outcasts and the disgraced.

## Advantages (from pages -90)
* No ability highr than 3
* Talents/Skills/Knowledges)
* 3/5/7

## Disciplines
* See pages 156-171
? Animalism: Supernatural affinity with, and control
of, animals.
? Auspex: Extrasensory perception, awareness and
premonitions.
? Celerity: Supernatural quickness and reflexes.
? Dominate: Mind control practiced through the
piercing gaze.
? Fortitude: Unearthly toughness, even to the point
of resisting fire and sunlight.
? Obfuscate: The ability to remain obscure and un-
seen, even in crowds.
? Potence: The Discipline of physical vigor and
strength.
? Presence: The ability to attract, sway and control crowds.
? Protean: Shapechanging- from growing claws to melding with the earth.
? Thaumaturgy: The study and practice ofsorcery.

## Bafckgrounds (page 91)

* Allies: Human confederates, usually family or fnends.
* Contacts: The number of information sources the character possesses.
* Fame: The character's renown in the mortal world. Generation : How far removed from Caine the character is.
* Herd: The vessels to which the character has free and safe access.
* Influence: The character's political power within mortal society.
* Mentor: The Cainite patron who advises and supports the character.
* Resources: W ealth, belongings, and monthly income.
* Retainers: Followers, guards and servants. Status:Thecharacter'sstandinginundeadsociety.

## Freebie Points (page 92, 15 points)

Point Pool Costs
|Trait|Cost|
|-|-|
|Disciplines (any)7 points per dot|
|Attributes|5 points per dot|
|Abilities|2 points per dot|
|Virtues|2 points per dot|
|Willpower|2 points per dot|
|Humanity|1 point per dot|
|Backgrounds|1 point per dot|

# Original App
* Roads are after backgrounds and before conscience/self-control/courage.
* Derangements are in bright bold colors
    * Dark Red
    * Dark purple
    * Dark orang
    * Grey/White Maybe dark white
    * Dark blue
    * Bright Green
    * Bright Cyan
    * Bright Orange
    * Bright Pink/Magenta
    * Bright Yellow

## Derangements - Malkavian Only (from page ?)

|Name|Description|Color|
|-|-|-|
|Amnesia|You forget a segment of your past. Additionally in some cases a character can forget abilities and be unable to use them for the duration.|Dark Red|
|Delusions of Grandeur|You imagine you are better than you are.|Dark Magenta|
|Fantasy|You enter a self-created world where you are the forgotten hero.|Dark Orange|
|Manic-Depression|You sink into deep and fitful depressions, showing no interest in anything which used to captivate your interests. You will go along with others rather than use the energy to resist. Occasional fits of great energy grab hold of you, and you will work for hours or even days on your projects. During this time you will resist even the need for sleep as you burn up blood and Willpower on your schemes.|Dark White|
|Multiple Personalities|You possess a number of new personalities. You have amore than one Mature, and will switch between them. Thus you regain Willpower points in defferent ways at defferent times|Dark Blue|
|Obsession|You become obsessed with some interest or fetish.|Bright Green|
|Overcompensation|You make up for your moral weaknesses by playing up your strengths to an extreme. You don't think you can frenzy and won't stop it.|Bright Cyan|
|Paranoia|You are convinced that you are being hunted. You hold even your closest Friends under suspicion|Bright Red|
|Perfection|All your energy is directed toward preventing anything from going wong. When it does you must make a self-control roll or frenzy.|Bright Magenta|
|Regression|You become childlike retreating to an earlier time when less was expected of you Willpower is regained inthe way a Child's is.|Bright Yellow|


