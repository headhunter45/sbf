$Debug
' Setup
Randomize Timer

Const FALSE = 0
Const TRUE = Not FALSE

Const DISCIPLINE_POINTS = 3
Const BACKGROUND_POINTS = 5
Const VIRTUE_POINTS = 7
Const INITIAL_GENERATION = 13

' Each set of these index constants "NAME_*" should start at 1 and go up to NAMES_COUNT without leaving any holes.
' This also goes the same for sub indexes like NAME_GROUP_SUBGROUP_* each NAME_GROUP_* set should have GetNumNamesInGroup(NAME_GROUP) items.
Const CLAN_ANARCH = 1
Const CLAN_ASSAMITE = 2
Const CLAN_BAALI = 3
Const CLAN_BRUJAH = 4
Const CLAN_CAITIFF = 5
Const CLAN_CAPPADOCIAN = 6
Const CLAN_GANGREL = 7
Const CLAN_GIOVANNI = 8
Const CLAN_INCONNU = 9
Const CLAN_LASOMBRA = 10
Const CLAN_MALKAVIAN = 11
Const CLAN_NOSFERATU = 12
Const CLAN_RAVANOS = 13
Const CLAN_SETTITE = 14
Const CLAN_TREMERE = 15
Const CLAN_TOREADOR = 16
Const CLAN_TZISMICE = 17
Const CLAN_VENTRUE = 18
Const CLANS_COUNT = 18
Dim Shared Clans(1 To CLANS_COUNT) As String

Const ARCHETYPE_ARCHITECT = 1
Const ARCHETYPE_AUTOCRAT = 2
Const ARCHETYPE_BARBARIAN = 3
Const ARCHETYPE_BON_VIVANT = 4
Const ARCHETYPE_BRAVO = 5
Const ARCHETYPE_CAREGIVER = 6
Const ARCHETYPE_CARETAKER = 7
Const ARCHETYPE_CELEBRANT = 8
Const ARCHETYPE_CHILD = 9
Const ARCHETYPE_CONFORMIST = 10
Const ARCHETYPE_CONNIVER = 11
Const ARCHETYPE_CURMUDGEON = 12
Const ARCHETYPE_DEFENDER = 13
Const ARCHETYPE_DEVIANT = 14
Const ARCHETYPE_DIRECTOR = 15
Const ARCHETYPE_FANATIC = 16
Const ARCHETYPE_GALLANT = 17
Const ARCHETYPE_INNOVATOR = 18
Const ARCHETYPE_JESTER = 19
Const ARCHETYPE_JUDGE = 20
Const ARCHETYPE_LONER = 21
Const ARCHETYPE_MARTYR = 22
Const ARCHETYPE_MONSTER = 23
Const ARCHETYPE_PENITENT = 24
Const ARCHETYPE_REBEL = 25
Const ARCHETYPE_ROGUE = 26
Const ARCHETYPE_SURVIVOR = 27
Const ARCHETYPE_TRADITIONALIST = 28
Const ARCHETYPE_TYRANT = 29
Const ARCHETYPE_VISIONARY = 30
Const ARCHETYPES_COUNT = 30
Dim Shared Archetypes(1 To ARCHETYPES_COUNT) As String

Const DISCIPLINE_ANIMALISM = 1
Const DISCIPLINE_AUSPEX = 2
Const DISCIPLINE_BARDO = 3
Const DISCIPLINE_CELERITY = 4
Const DISCIPLINE_CHIMESTRY = 5
Const DISCIPLINE_DEMENTATION = 6
Const DISCIPLINE_DOMINATE = 7
Const DISCIPLINE_FORTITUDE = 8
Const DISCIPLINE_MELPOMINEE = 9
Const DISCIPLINE_MORTIS = 10
Const DISCIPLINE_MYTHERCERIA = 11
Const DISCIPLINE_NECROMANCY = 12
Const DISCIPLINE_OBEAH = 13
Const DISCIPLINE_OBFUSCATE = 14
Const DISCIPLINE_OBTENEBRATION = 15
Const DISCIPLINE_POTENCE = 16
Const DISCIPLINE_PRESENCE = 17
Const DISCIPLINE_PROTEAN = 18
Const DISCIPLINE_QUIETUS = 19
Const DISCIPLINE_SERPENTIS = 20
Const DISCIPLINE_SPIRITUS = 21
Const DISCIPLINE_THANANTOSIS = 22
Const DISCIPLINE_THAUMATURGY = 23
Const DISCIPLINE_VICISSITUDE = 24
Const DISCIPLINES_COUNT = 24
Dim Shared Disciplines(1 To DISCIPLINES_COUNT) As String

' Virtues
Const VIRTUE_SELF_CONTROL = 1
Const VIRTUE_COURAGE = 2
Const VIRTUE_CONSCIENCE = 3
Const VIRTUES_COUNT = 3
Dim Shared Virtues(1 To VIRTUES_COUNT) As String

' These should probably be renamed like PHYSICAL_ATTRIBUTE_STRENGTH instead.
Const ATTRIBUTE_STRENGTH = 1
Const ATTRIBUTE_DEXTERITY = 2
Const ATTRIBUTE_STAMINA = 3
Const PHYSICAL_ATTRIBUTES_COUNT = 3
Dim Shared PhysicalAttributes(1 To PHYSICAL_ATTRIBUTES_COUNT) As String
Dim Shared PhysicalAttributeAbbreviations(1 To PHYSICAL_ATTRIBUTES_COUNT) As String

Const ATTRIBUTE_CHARISMA = 1
Const ATTRIBUTE_MANIPULATION = 2
Const ATTRIBUTE_APPEARANCE = 3
Const SOCIAL_ATTRIBUTES_COUNT = 3
Dim Shared SocialAttributes(1 To SOCIAL_ATTRIBUTES_COUNT) As String
Dim Shared SocialAttributeAbbreviations(1 To SOCIAL_ATTRIBUTES_COUNT) As String

Const ATTRIBUTE_INTELLIGENCE = 1
Const ATTRIBUTE_PERCEPTION = 2
Const ATTRIBUTE_WITS = 3
Const MENTAL_ATTRIBUTES_COUNT = 3
Dim Shared MentalAttributes(1 To MENTAL_ATTRIBUTES_COUNT) As String
Dim Shared MentalAttributeAbbreviations(1 To MENTAL_ATTRIBUTES_COUNT) As String

Const ATTRIBUTE_GROUP_PHYSICAL = 1
Const ATTRIBUTE_GROUP_SOCIAL = 2
Const ATTRIBUTE_GROUP_MENTAL = 3
Const ATTRIBUTE_GROUPS_COUNT = 3
Dim Shared AttributeGroups(1 To ATTRIBUTE_GROUPS_COUNT) As String

Const ABILITY_GROUP_TALENTS = 1
Const ABILITY_GROUP_SKILLS = 2
Const ABILITY_GROUP_KNOWLEDGES = 3
Const ABILITY_GROUPS_COUNT = 3
Dim Shared AbilityGroups(1 To ABILITY_GROUPS_COUNT) As String

Const TALENT_ACTING = 1
Const TALENT_ALERTNESS = 2
Const TALENT_ATHLETICS = 3
Const TALENT_BRAWL = 4
Const TALENT_DODGE = 5
Const TALENT_EMPATHY = 6
Const TALENT_INTIMIDATION = 7
Const TALENT_LEADERSHIP = 8
Const TALENT_STREETWISE = 9
Const TALENT_SUBTERFUGE = 10
Const TALENTS_COUNT = 10
Dim Shared Talents(1 To TALENTS_COUNT) As String

Const SKILL_ANIMAL_KEN = 1
Const SKILL_DRIVE = 2
Const SKILL_ETIQUETTE = 3
Const SKILL_FIREARMS = 4
Const SKILL_MELEE = 5
Const SKILL_MUSIC = 6
Const SKILL_REPAIR = 7
Const SKILL_SECURITY = 8
Const SKILL_STEALTH = 9
Const SKILL_SURVIVAL = 10
Const SKILLS_COUNT = 10
Dim Shared Skills(1 To SKILLS_COUNT) As String

Const KNOWLEDGE_BUREAUCRACY = 1
Const KNOWLEDGE_COMPUTER = 2
Const KNOWLEDGE_FINANCE = 3
Const KNOWLEDGE_INVESTIGATION = 4
Const KNOWLEDGE_LAW = 5
Const KNOWLEDGE_LINGUISTICS = 6
Const KNOWLEDGE_MEDICINE = 7
Const KNOWLEDGE_OCCULT = 8
Const KNOWLEDGE_POLITICS = 9
Const KNOWLEDGE_SCIENCE = 10
Const KNOWLEDGES_COUNT = 10
Dim Shared Knowledges(1 To KNOWLEDGES_COUNT) As String

Const BACKGROUND_ALLIES = 1
Const BACKGROUND_CONTACTS = 2
Const BACKGROUND_FAME = 3
Const BACKGROUND_GENERATION = 4
Const BACKGROUND_HERD = 5
Const BACKGROUND_INFLUENCE = 6
Const BACKGROUND_MENTOR = 7
Const BACKGROUND_RESOURCES = 8
Const BACKGROUND_RETAINERS = 9
Const BACKGROUND_STATUS = 10
Const BACKGROUNDS_COUNT = 10
Dim Shared Backgrounds(1 To BACKGROUNDS_COUNT) As String

Const GENDER_MALE = 1
Const GENDER_FEMALE = 2
Const GENDER_TRANS_MALE = 3
Const GENDER_TRANS_FEMALE = 4
Const GENDER_NON_BINARY = 5
Const GENDERS_COUNT = 5
Dim Shared Genders(1 To GENDERS_COUNT) As String

Const COLOR_DARK_BLACK = 0
Const COLOR_DARK_BLUE = 1
Const COLOR_DARK_GREEN = 2
Const COLOR_DARK_CYAN = 3
Const COLOR_DARK_RED = 4
Const COLOR_DARK_MAGENTA = 5
Const COLOR_DARK_ORANGE = 6
Const COLOR_DARK_YELLOW = 6
Const COLOR_DARK_WHITE = 7
Const COLOR_BRIGHT_BLACK = 8
Const COLOR_BRIGHT_BLUE = 9
Const COLOR_BRIGHT_GREEN = 10
Const COLOR_BRIGHT_CYAN = 11
Const COLOR_BRIGHT_RED = 12
Const COLOR_BRIGHT_MAGENTA = 13
Const COLOR_BRIGHT_ORANGE = 14
Const COLOR_BRIGHT_YELLOW = 14
Const COLOR_BRIGHT_WHITE = 15

Const DERANGEMENTS_COUNT = 10
Const DERANGEMENT_ID_AMNESIA = 1
Const DERANGEMENT_ID_DELUSIONS_OF_GRANDEUR = 2
Const DERANGEMENT_ID_FANTASY = 3
Const DERANGEMENT_ID_MANIC_DEPRESSION = 4
Const DERANGEMENT_ID_MULTIPLE_PERSONALITIES = 5
Const DERANGEMENT_ID_OBSESSION = 6
Const DERANGEMENT_ID_OVERCOMPENSATION = 7
Const DERANGEMENT_ID_PARANOIA = 8
Const DERANGEMENT_ID_PERFECTION = 9
Const DERANGEMENT_ID_REGRESSION = 10
Dim Shared Derangements(1 To DERANGEMENTS_COUNT) As DerangementType
Dim Shared DerangementColors(1 To DERANGEMENTS_COUNT) As Integer

Dim Shared DerangementLabels(1 To DERANGEMENTS_COUNT) As String
Const DERANGEMENT_LABEL_AMNESIA = "Amnesia"
Const DERANGEMENT_LABEL_DELUSIONS_OF_GRANDEUR = "Delusions of Grandeur"
Const DERANGEMENT_LABEL_FANTASY = "Fantasy"
Const DERANGEMENT_LABEL_MANIC_DEPRESSION = "Manic-Depression"
Const DERANGEMENT_LABEL_MULTIPLE_PERSONALITIES = "Multiple Personalities"
Const DERANGEMENT_LABEL_OBSESSION = "Obsession"
Const DERANGEMENT_LABEL_OVERCOMPENSATION = "Overcompensation"
Const DERANGEMENT_LABEL_PARANOIA = "Paranoia"
Const DERANGEMENT_LABEL_PERFECTION = "Perfection"
Const DERANGEMENT_LABEL_REGRESSION = "Regression"

Dim Shared DerangementDescriptions(1 To DERANGEMENTS_COUNT) As String
Const DERANGEMENT_DESCRIPTION_AMNESIA = "You forget a segment of your past. Additionally in some cases a character can forget abilities and be unable to use them for the duration."
Const DERANGEMENT_DESCRIPTION_DELUSIONS_OF_GRA = "You imagine you are better than you are."
Const DERANGEMENT_DESCRIPTION_FANTASY = "You enter a self-created world where you are the forgotten hero."
Const DERANGEMENT_DESCRIPTION_MANIC_DEPRESSION = "You sink into deep and fitful depressions, showing no interest in anything which used to captivate your interests. You will go along with others rather than use the energy to resist. Occasional fits of great energy grab hold of you, and you will work for hours or even days on your projects. During this time you will resist even the need for sleep as you burn up blood and Willpower on your schemes."
Const DERANGEMENT_DESCRIPTION_MULTIPLE_PERSONA = "You possess a number of new personalities. You have amore than one Mature, and will switch between them. Thus you regain Willpower points in defferent ways at defferent times"
Const DERANGEMENT_DESCRIPTION_OBSESSION = "You become obsessed with some interest or fetish."
Const DERANGEMENT_DESCRIPTION_OVERCOMPENSATION = "You make up for your moral weaknesses by playing up your strengths to an extreme. You don't think you can frenzy and won't stop it."
Const DERANGEMENT_DESCRIPTION_PARANOIA = "You are convinced that you are being hunted. You hold even your closest Friends under suspicion."
Const DERANGEMENT_DESCRIPTION_PERFECTION = "All your energy is directed toward preventing anything from going wong. When it does you must make a self-control roll or frenzy."
Const DERANGEMENT_DESCRIPTION_REGRESSION = "You become childlike retreating to an earlier time when less was expected of you Willpower is regained inthe way a Child's is."

Dim Shared ScreenColor As Integer
ScreenColor = COLOR_DARK_WHITE

Type CharacterType
    name As String
    player As String
    chronicle As String
    haven As String
    concept As String
    age As String
    gender As Integer
    clan As Integer
    nature As Integer
    demeanor As Integer
    conscience As Integer
    selfControl As Integer
    courage As Integer
    generation As Integer
    roadName As String
    roadValue As Integer
    willpower As Integer
    bloodPool As Integer
    derangementId As Integer
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

Type MenuStyle
    idWidth As Integer
    labelWidth As Integer
    valueWidth As Integer
    screenWidth As Integer
    randomItemName As String
    randomItemId As Integer
    idLabelSeparator As String
    labelValueSeparator As String
    menuItemSpacer As String
    showRandom As Integer
    useColors As Integer
End Type

Type MenuItem
    label As String
    id As Integer
    value As Integer
    color As Integer
    isVisible As Integer
End Type

Type DerangementType
    id As Integer
    label As String
    description As String
    textColor As Integer
End Type

Call InitializeMemory

' Run "tests" at startup. Uncomment the end instruction to see the output and not run the rest of the program.
Call Test
Call SplashScreen
Call MainMenu

' This initializes shared variables.
Sub InitializeMemory
    ' For all of these lookup tables they should look something like this to know the mapping is correct
    ' Names(NAME_ITEM1) = "Item1"
    ' The index constants should start at 1 and go up to NAMES_COUNT without leaving any holes.

    ' Clans
    Clans(CLAN_ANARCH) = "Anarch"
    Clans(CLAN_ASSAMITE) = "Assamite"
    Clans(CLAN_BAALI) = "Baali"
    Clans(CLAN_BRUJAH) = "Brujah"
    Clans(CLAN_CAITIFF) = "Caitiff"
    Clans(CLAN_CAPPADOCIAN) = "Cappadocian"
    Clans(CLAN_GANGREL) = "Gangrel"
    Clans(CLAN_GIOVANNI) = "Giovanni"
    Clans(CLAN_INCONNU) = "Inconnu"
    Clans(CLAN_LASOMBRA) = "Lasombra"
    Clans(CLAN_MALKAVIAN) = "Malkavian"
    Clans(CLAN_NOSFERATU) = "Nosferatu"
    Clans(CLAN_RAVANOS) = "Ravanos"
    Clans(CLAN_SETTITE) = "Settite"
    Clans(CLAN_TREMERE) = "Tremere"
    Clans(CLAN_TOREADOR) = "Toreador"
    Clans(CLAN_TZISMICE) = "Tzismice"
    Clans(CLAN_VENTRUE) = "Ventrue"

    ' Archetypes
    Archetypes(ARCHETYPE_ARCHITECT) = "Architect"
    Archetypes(ARCHETYPE_AUTOCRAT) = "Autocrat"
    Archetypes(ARCHETYPE_BARBARIAN) = "Barbarian"
    Archetypes(ARCHETYPE_BON_VIVANT) = "Bon Vivant"
    Archetypes(ARCHETYPE_BRAVO) = "Bravo"
    Archetypes(ARCHETYPE_CAREGIVER) = "Caregiver"
    Archetypes(ARCHETYPE_CARETAKER) = "Caretaker"
    Archetypes(ARCHETYPE_CELEBRANT) = "Celebrant"
    Archetypes(ARCHETYPE_CHILD) = "Child"
    Archetypes(ARCHETYPE_CONFORMIST) = "Conformist"
    Archetypes(ARCHETYPE_CONNIVER) = "Conniver"
    Archetypes(ARCHETYPE_CURMUDGEON) = "Curmudgeon"
    Archetypes(ARCHETYPE_DEFENDER) = "Defender"
    Archetypes(ARCHETYPE_DEVIANT) = "Deviant"
    Archetypes(ARCHETYPE_DIRECTOR) = "Director"
    Archetypes(ARCHETYPE_FANATIC) = "Fanatic"
    Archetypes(ARCHETYPE_GALLANT) = "Gallant"
    Archetypes(ARCHETYPE_INNOVATOR) = "Innovator"
    Archetypes(ARCHETYPE_JESTER) = "Jester"
    Archetypes(ARCHETYPE_JUDGE) = "Judge"
    Archetypes(ARCHETYPE_LONER) = "Loner"
    Archetypes(ARCHETYPE_MARTYR) = "Martyr"
    Archetypes(ARCHETYPE_MONSTER) = "Monster"
    Archetypes(ARCHETYPE_PENITENT) = "Penitent"
    Archetypes(ARCHETYPE_REBEL) = "Rebel"
    Archetypes(ARCHETYPE_ROGUE) = "Rogue"
    Archetypes(ARCHETYPE_SURVIVOR) = "Survivor"
    Archetypes(ARCHETYPE_TRADITIONALIST) = "Traditionalist"
    Archetypes(ARCHETYPE_TYRANT) = "Tyrant"
    Archetypes(ARCHETYPE_VISIONARY) = "Visionary"

    ' Disciplines
    Disciplines(DISCIPLINE_ANIMALISM) = "Animalism"
    Disciplines(DISCIPLINE_AUSPEX) = "Auspex"
    Disciplines(DISCIPLINE_BARDO) = "Bardo"
    Disciplines(DISCIPLINE_CELERITY) = "Celerity"
    Disciplines(DISCIPLINE_CHIMESTRY) = "Chimestry"
    Disciplines(DISCIPLINE_DEMENTATION) = "Dementation"
    Disciplines(DISCIPLINE_DOMINATE) = "Dominate"
    Disciplines(DISCIPLINE_FORTITUDE) = "Fortitude"
    Disciplines(DISCIPLINE_MELPOMINEE) = "Melpominee"
    Disciplines(DISCIPLINE_MORTIS) = "Mortis"
    Disciplines(DISCIPLINE_MYTHERCERIA) = "Mytherceria"
    Disciplines(DISCIPLINE_NECROMANCY) = "Necromancy"
    Disciplines(DISCIPLINE_OBEAH) = "Obeah"
    Disciplines(DISCIPLINE_OBFUSCATE) = "Obfuscate"
    Disciplines(DISCIPLINE_OBTENEBRATION) = "Obtenebration"
    Disciplines(DISCIPLINE_POTENCE) = "Potence"
    Disciplines(DISCIPLINE_PRESENCE) = "Presence"
    Disciplines(DISCIPLINE_PROTEAN) = "Protean"
    Disciplines(DISCIPLINE_QUIETUS) = "Quietus"
    Disciplines(DISCIPLINE_SERPENTIS) = "Serpentis"
    Disciplines(DISCIPLINE_SPIRITUS) = "Spiritus"
    Disciplines(DISCIPLINE_THANANTOSIS) = "Thanantosis"
    Disciplines(DISCIPLINE_THAUMATURGY) = "Thaumaturgy"
    Disciplines(DISCIPLINE_VICISSITUDE) = "Vicissitude"

    ' Virtues
    Virtues(VIRTUE_SELF_CONTROL) = "Self-Control"
    Virtues(VIRTUE_COURAGE) = "Courage"
    Virtues(VIRTUE_CONSCIENCE) = "Conscience"

    ' Physical Attributes
    PhysicalAttributes(ATTRIBUTE_STRENGTH) = "Strength"
    PhysicalAttributeAbbreviations(ATTRIBUTE_STRENGTH) = "Str."
    PhysicalAttributes(ATTRIBUTE_DEXTERITY) = "Dexterity"
    PhysicalAttributeAbbreviations(ATTRIBUTE_DEXTERITY) = "Dex."
    PhysicalAttributes(ATTRIBUTE_STAMINA) = "Stamina"
    PhysicalAttributeAbbreviations(ATTRIBUTE_STAMINA) = "Sta."

    ' Social Attributes
    SocialAttributes(ATTRIBUTE_CHARISMA) = "Charisma"
    SocialAttributeAbbreviations(ATTRIBUTE_CHARISMA) = "Cha."
    SocialAttributes(ATTRIBUTE_MANIPULATION) = "Manipulation"
    SocialAttributeAbbreviations(ATTRIBUTE_MANIPULATION) = "Man."
    SocialAttributes(ATTRIBUTE_APPEARANCE) = "Appearance"
    SocialAttributeAbbreviations(ATTRIBUTE_APPEARANCE) = "App."

    ' Mental Attributes
    MentalAttributes(ATTRIBUTE_INTELLIGENCE) = "Intelligence"
    MentalAttributeAbbreviations(ATTRIBUTE_INTELLIGENCE) = "Int."
    MentalAttributes(ATTRIBUTE_PERCEPTION) = "Perception"
    MentalAttributeAbbreviations(ATTRIBUTE_PERCEPTION) = "Per."
    MentalAttributes(ATTRIBUTE_WITS) = "Wits"
    MentalAttributeAbbreviations(ATTRIBUTE_WITS) = "Wits"

    ' Attribute Groups
    AttributeGroups(ATTRIBUTE_GROUP_PHYSICAL) = "Physical"
    AttributeGroups(ATTRIBUTE_GROUP_SOCIAL) = "Social"
    AttributeGroups(ATTRIBUTE_GROUP_MENTAL) = "Mental"

    ' Abilities
    AbilityGroups(ABILITY_GROUP_TALENTS) = "Talents"
    AbilityGroups(ABILITY_GROUP_SKILLS) = "Skills"
    AbilityGroups(ABILITY_GROUP_KNOWLEDGES) = "Knowledges"

    ' Talents
    Talents(TALENT_ACTING) = "Acting"
    Talents(TALENT_ALERTNESS) = "Alertness"
    Talents(TALENT_ATHLETICS) = "Athletics"
    Talents(TALENT_BRAWL) = "Brawl"
    Talents(TALENT_DODGE) = "Dodge"
    Talents(TALENT_EMPATHY) = "Empathy"
    Talents(TALENT_INTIMIDATION) = "Intimidation"
    Talents(TALENT_LEADERSHIP) = "Leadership"
    Talents(TALENT_STREETWISE) = "Streetwise"
    Talents(TALENT_SUBTERFUGE) = "Subterfuge"

    ' Skills
    Skills(SKILL_ANIMAL_KEN) = "Animal Ken"
    Skills(SKILL_DRIVE) = "Drive"
    Skills(SKILL_ETIQUETTE) = "Etiquette"
    Skills(SKILL_FIREARMS) = "Firearms"
    Skills(SKILL_MELEE) = "Melee"
    Skills(SKILL_MUSIC) = "Music"
    Skills(SKILL_REPAIR) = "Repair"
    Skills(SKILL_SECURITY) = "Security"
    Skills(SKILL_STEALTH) = "Stealth"
    Skills(SKILL_SURVIVAL) = "Survival"

    ' Knowwledges
    Knowledges(KNOWLEDGE_BUREAUCRACY) = "Bureaucracy"
    Knowledges(KNOWLEDGE_COMPUTER) = "Computer"
    Knowledges(KNOWLEDGE_FINANCE) = "Finance"
    Knowledges(KNOWLEDGE_INVESTIGATION) = "Investigation"
    Knowledges(KNOWLEDGE_LAW) = "Law"
    Knowledges(KNOWLEDGE_LINGUISTICS) = "Linguistics"
    Knowledges(KNOWLEDGE_MEDICINE) = "Medicine"
    Knowledges(KNOWLEDGE_OCCULT) = "Occult"
    Knowledges(KNOWLEDGE_POLITICS) = "Politics"
    Knowledges(KNOWLEDGE_SCIENCE) = "Science"

    ' Backgrounds
    Backgrounds(BACKGROUND_ALLIES) = "Allies"
    Backgrounds(BACKGROUND_CONTACTS) = "Contacts"
    Backgrounds(BACKGROUND_FAME) = "Fame"
    Backgrounds(BACKGROUND_GENERATION) = "Generation"
    Backgrounds(BACKGROUND_HERD) = "Herd"
    Backgrounds(BACKGROUND_INFLUENCE) = "Influence"
    Backgrounds(BACKGROUND_MENTOR) = "Mentor"
    Backgrounds(BACKGROUND_RESOURCES) = "Resources"
    Backgrounds(BACKGROUND_RETAINERS) = "Retainers"
    Backgrounds(BACKGROUND_STATUS) = "Status"

    ' Genders
    Genders(GENDER_MALE) = "Male"
    Genders(GENDER_FEMALE) = "Female"
    Genders(GENDER_TRANS_MALE) = "Trans-Male"
    Genders(GENDER_TRANS_FEMALE) = "Trans-Female"
    Genders(GENDER_NON_BINARY) = "Non-Binary"

    DerangementColors(DERANGEMENT_ID_AMNESIA) = COLOR_DARK_RED
    DerangementColors(DERANGEMENT_ID_DELUSIONS_OF_GRANDEUR) = COLOR_DARK_MAGENTA
    DerangementColors(DERANGEMENT_ID_FANTASY) = COLOR_DARK_ORANGE
    DerangementColors(DERANGEMENT_ID_MANIC_DEPRESSION) = COLOR_DARK_WHITE
    DerangementColors(DERANGEMENT_ID_MULTIPLE_PERSONALITIES) = COLOR_DARK_BLUE
    DerangementColors(DERANGEMENT_ID_OBSESSION) = COLOR_BRIGHT_GREEN
    DerangementColors(DERANGEMENT_ID_OVERCOMPENSATION) = COLOR_BRIGHT_CYAN
    DerangementColors(DERANGEMENT_ID_PARANOIA) = COLOR_BRIGHT_RED
    DerangementColors(DERANGEMENT_ID_PERFECTION) = COLOR_BRIGHT_MAGENTA
    DerangementColors(DERANGEMENT_ID_REGRESSION) = COLOR_BRIGHT_YELLOW

    DerangementLabels(DERANGEMENT_ID_AMNESIA) = DERANGEMENT_LABEL_AMNESIA
    DerangementLabels(DERANGEMENT_ID_DELUSIONS_OF_GRANDEUR) = DERANGEMENT_LABEL_DELUSIONS_OF_GRANDEUR
    DerangementLabels(DERANGEMENT_ID_FANTASY) = DERANGEMENT_LABEL_FANTASY
    DerangementLabels(DERANGEMENT_ID_MANIC_DEPRESSION) = DERANGEMENT_LABEL_MANIC_DEPRESSION
    DerangementLabels(DERANGEMENT_ID_MULTIPLE_PERSONALITIES) = DERANGEMENT_LABEL_MULTIPLE_PERSONALITIES
    DerangementLabels(DERANGEMENT_ID_OBSESSION) = DERANGEMENT_LABEL_OBSESSION
    DerangementLabels(DERANGEMENT_ID_OVERCOMPENSATION) = DERANGEMENT_LABEL_OVERCOMPENSATION
    DerangementLabels(DERANGEMENT_ID_PARANOIA) = DERANGEMENT_LABEL_PARANOIA
    DerangementLabels(DERANGEMENT_ID_PERFECTION) = DERANGEMENT_LABEL_PERFECTION
    DerangementLabels(DERANGEMENT_ID_REGRESSION) = DERANGEMENT_LABEL_REGRESSION

    DerangementDescriptions(DERANGEMENT_ID_AMNESIA) = DERANGEMENT_DESCRIPTION_AMNESIA
    DerangementDescriptions(DERANGEMENT_ID_DELUSIONS_OF_GRANDEUR) = DERANGEMENT_DESCRIPTION_DELUSIONS_OF_GRA
    DerangementDescriptions(DERANGEMENT_ID_FANTASY) = DERANGEMENT_DESCRIPTION_FANTASY
    DerangementDescriptions(DERANGEMENT_ID_MANIC_DEPRESSION) = DERANGEMENT_DESCRIPTION_MANIC_DEPRESSION
    DerangementDescriptions(DERANGEMENT_ID_MULTIPLE_PERSONALITIES) = DERANGEMENT_DESCRIPTION_MULTIPLE_PERSONA
    DerangementDescriptions(DERANGEMENT_ID_OBSESSION) = DERANGEMENT_DESCRIPTION_OBSESSION
    DerangementDescriptions(DERANGEMENT_ID_OVERCOMPENSATION) = DERANGEMENT_DESCRIPTION_OVERCOMPENSATION
    DerangementDescriptions(DERANGEMENT_ID_PARANOIA) = DERANGEMENT_DESCRIPTION_PARANOIA
    DerangementDescriptions(DERANGEMENT_ID_PERFECTION) = DERANGEMENT_DESCRIPTION_PERFECTION
    DerangementDescriptions(DERANGEMENT_ID_REGRESSION) = DERANGEMENT_DESCRIPTION_REGRESSION

    For i = LBound(Derangements) To UBound(Derangements)
        Call NewDerangement(Derangements(i), i, DerangementLabels(i), DerangementColors(i), DerangementDescriptions(i))
    Next
End Sub

Sub SplashScreen
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
End Sub

Sub MainMenu
    ' Main menu
    choice = 0
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
End Sub

' This sub is not called. It is here so it can be copied whenever I need to make a new bordered screen.
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

Function GetMenuChoice (items() As MenuItem, style As MenuStyle, count As Integer)
    ' Only allow random id or an id from a visible menuitem.
    choice = -1
    acceptChoice = FALSE
    Do
        Input choice
        If style.showRandom And choice = style.randomItemId Then acceptChoice = TRUE
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

Function GetRandomMenuItemId (items() As MenuItem, count As Integer)
    numVisibleItems = 0
    Dim visibleItems(count) As Integer
    For i = 1 To count
        If items(i).isVisible Then
            visibleItems(numVisibleItems) = i
            numVisibleItems = numVisibleItems + 1
        End If
    Next
    i = GetRandomInt(0, numVisibleItems - 1)
    GetRandomMenuItemId = visibleItems(i)
End Function

Function MaxI (val1 As Integer, val2 As Integer)
    If (val1 > val2) Then
        MaxI = val1
    Else
        MaxI = val2
    End If
End Function

Sub SetVirtue (ch As CharacterType, index As Integer, value As Integer)
    Select Case index
        Case VIRTUE_SELF_CONTROL
            ch.selfControl = value
        Case VIRTUE_COURAGE
            ch.courage = value
        Case VIRTUE_CONSCIENCE
            ch.conscience = value
    End Select
End Sub

Sub SetDiscipline (ch As CharacterType, index As Integer, value As Integer)
    Select Case index
        Case DISCIPLINE_ANIMALISM
            ch.discipline_animalism = value
        Case DISCIPLINE_AUSPEX
            ch.discipline_auspex = value
        Case DISCIPLINE_BARDO
            ch.discipline_bardo = value
        Case DISCIPLINE_CELERITY
            ch.discipline_celerity = value
        Case DISCIPLINE_CHIMESTRY
            ch.discipline_chimestry = value
        Case DISCIPLINE_DEMENTATION
            ch.discipline_dementation = value
        Case DISCIPLINE_DOMINATE
            ch.discipline_dominate = value
        Case DISCIPLINE_FORTITUDE
            ch.discipline_fortitude = value
        Case DISCIPLINE_MELPOMINEE
            ch.discipline_melpominee = value
        Case DISCIPLINE_MORTIS
            ch.discipline_mortis = value
        Case DISCIPLINE_MYTHERCERIA
            ch.discipline_mytherceria = value
        Case DISCIPLINE_NECROMANCY
            ch.discipline_necromancy = value
        Case DISCIPLINE_OBEAH
            ch.discipline_obeah = value
        Case DISCIPLINE_OBFUSCATE
            ch.discipline_obfuscate = value
        Case DISCIPLINE_OBTENEBRATION
            ch.discipline_obtenebration = value
        Case DISCIPLINE_POTENCE
            ch.discipline_potence = value
        Case DISCIPLINE_PRESENCE
            ch.discipline_presence = value
        Case DISCIPLINE_PROTEAN
            ch.discipline_protean = value
        Case DISCIPLINE_QUIETUS
            ch.discipline_quietus = value
        Case DISCIPLINE_SERPENTIS
            ch.discipline_serpentis = value
        Case DISCIPLINE_SPIRITUS
            ch.discipline_spiritus = value
        Case DISCIPLINE_THANANTOSIS
            ch.discipline_thanantosis = value
        Case DISCIPLINE_THAUMATURGY
            ch.discipline_thaumaturgy = value
        Case DISCIPLINE_VICISSITUDE
            ch.discipline_vicissitude = value
    End Select
End Sub

Function GetAllDerangementsLine$ (ch As CharacterType)
    Dim allDerangements(1) As DerangementType
    Call FillDerangements(ch, allDerangements())
    allDerangementsString$ = ""
    For i = 0 To UBound(allDerangements) - 1
        allDerangementsString$ = allDerangementsString$ + allDerangements(i).label + ", "
    Next
    GetAllDerangementsLine$ = allDerangementsString$
End Function

Function GetVirtue (ch As CharacterType, index As Integer)
    value = 0
    Select Case index
        Case VIRTUE_SELF_CONTROL
            value = ch.selfControl
        Case VIRTUE_COURAGE
            value = ch.courage
        Case VIRTUE_CONSCIENCE
            value = ch.conscience
    End Select
    GetVirtue = value
End Function

Function GetDiscipline (ch As CharacterType, index As Integer)
    Select Case index
        Case DISCIPLINE_ANIMALISM
            GetDiscipline = ch.discipline_animalism
        Case DISCIPLINE_AUSPEX
            GetDiscipline = ch.discipline_auspex
        Case discipline_barde
            GetDiscipline = ch.discipline_bardo
        Case DISCIPLINE_CELERITY
            GetDiscipline = ch.discipline_celerity
        Case DISCIPLINE_CHIMESTRY
            GetDiscipline = ch.discipline_chimestry
        Case DISCIPLINE_DEMENTATION
            GetDiscipline = ch.discipline_dementation
        Case DISCIPLINE_DOMINATE
            GetDiscipline = ch.discipline_dominate
        Case DISCIPLINE_FORTITUDE
            GetDiscipline = ch.discipline_fortitude
        Case DISCIPLINE_MELPOMINEE
            GetDiscipline = ch.discipline_melpominee
        Case DISCIPLINE_MORTIS
            GetDiscipline = ch.discipline_mortis
        Case DISCIPLINE_MYTHERCERIA
            GetDiscipline = ch.discipline_mytherceria
        Case DISCIPLINE_NECROMANCY
            GetDiscipline = ch.discipline_necromancy
        Case DISCIPLINE_OBEAH
            GetDiscipline = ch.discipline_obeah
        Case DISCIPLINE_OBFUSCATE
            GetDiscipline = ch.discipline_obfuscate
        Case DISCIPLINE_OBTENEBRATION
            GetDiscipline = ch.discipline_obtenebration
        Case DISCIPLINE_POTENCE
            GetDiscipline = ch.discipline_potence
        Case DISCIPLINE_PRESENCE
            GetDiscipline = ch.discipline_presence
        Case DISCIPLINE_PROTEAN
            GetDiscipline = ch.discipline_protean
        Case DISCIPLINE_QUIETUS
            GetDiscipline = ch.discipline_quietus
        Case DISCIPLINE_SERPENTIS
            GetDiscipline = ch.discipline_serpentis
        Case DISCIPLINE_SPIRITUS
            GetDiscipline = ch.discipline_spiritus
        Case DISCIPLINE_THANANTOSIS
            GetDiscipline = ch.discipline_thanantosis
        Case DISCIPLINE_THAUMATURGY
            GetDiscipline = ch.discipline_thaumaturgy
        Case DISCIPLINE_VICISSITUDE
            GetDiscipline = ch.discipline_vicissitude
    End Select
End Function

Sub FillDerangements (ch As CharacterType, myDerangements() As DerangementType)
    count = 1
    ReDim myDerangements(count) As DerangementType
    myDerangements(0) = Derangements(ch.derangementId)
End Sub

Sub FillDisciplines (ch As CharacterType, disciplines() As Integer)
    ReDim disciplines(1 To DISCIPLINES_COUNT) As Integer
    For index = 1 To DISCIPLINES_COUNT
        disciplines(index) = GetDiscipline(ch, index)
    Next
End Sub

Sub FillVirtues (ch As CharacterType, values() As Integer)
    ReDim values(1 To VIRTUES_COUNT) As Integer
    For index = 1 To VIRTUES_COUNT
        values(index) = GetVirtue(ch, index)
    Next
End Sub

Sub SetTalent (ch As CharacterType, index As Integer, value As Integer)
    Select Case index
        Case TALENT_ACTING
            ch.talent_acting = value
        Case TALENT_ALERTNESS
            ch.talent_alertness = value
        Case TALENT_ATHLETICS
            ch.talent_athletics = value
        Case TALENT_BRAWL
            ch.talent_brawl = value
        Case TALENT_DODGE
            ch.talent_dodge = value
        Case TALENT_EMPATHY
            ch.talent_empathy = value
        Case TALENT_INTIMIDATION
            ch.talent_intimidation = value
        Case TALENT_LEADERSHIP
            ch.talent_leadership = value
        Case TALENT_STREETWISE
            ch.talent_streetwise = value
        Case TALENT_SUBTERFUGE
            ch.talent_subterfuge = value
    End Select
End Sub

Function GetTalent (ch As CharacterType, index As Integer)
    Select Case index
        Case TALENT_ACTING
            GetTalent = ch.talent_acting
        Case TALENT_ALERTNESS
            GetTalent = ch.talent_alertness
        Case TALENT_ATHLETICS
            GetTalent = ch.talent_athletics
        Case TALENT_BRAWL
            GetTalent = ch.talent_brawl
        Case TALENT_DODGE
            GetTalent = ch.talent_dodge
        Case TALENT_EMPATHY
            GetTalent = ch.talent_empathy
        Case TALENT_INTIMIDATION
            GetTalent = ch.talent_intimidation
        Case TALENT_LEADERSHIP
            GetTalent = ch.talent_leadership
        Case TALENT_STREETWISE
            GetTalent = ch.talent_streetwise
        Case TALENT_SUBTERFUGE
            GetTalent = ch.talent_subterfuge
    End Select
End Function

Sub SetSkill (ch As CharacterType, index As Integer, value As Integer)
    Select Case index
        Case SKILL_ANIMAL_KEN
            ch.skill_animalKen = value
        Case SKILL_DRIVE
            ch.skill_drive = value
        Case SKILL_ETIQUETTE
            ch.skill_etiquette = value
        Case SKILL_FIREARMS
            ch.skill_firearms = value
        Case SKILL_MELEE
            ch.skill_melee = value
        Case SKILL_MUSIC
            ch.skill_music = value
        Case SKILL_REPAIR
            ch.skill_repair = value
        Case SKILL_SECURITY
            ch.skill_security = value
        Case SKILL_STEALTH
            ch.skill_stealth = value
        Case SKILL_SURVIVAL
            ch.skill_survival = value
    End Select
End Sub

Function GetSkill (ch As CharacterType, index As Integer)
    Select Case index
        Case SKILL_ANIMAL_KEN
            GetSkill = ch.skill_animalKen
        Case SKILL_DRIVE
            GetSkill = ch.skill_drive
        Case SKILL_ETIQUETTE
            GetSkill = ch.skill_etiquette
        Case SKILL_FIREARMS
            GetSkill = ch.skill_firearms
        Case SKILL_MELEE
            GetSkill = ch.skill_melee
        Case SKILL_MUSIC
            GetSkill = ch.skill_music
        Case SKILL_REPAIR
            GetSkill = ch.skill_repair
        Case SKILL_SECURITY
            GetSkill = ch.skill_security
        Case SKILL_STEALTH
            GetSkill = ch.skill_stealth
        Case SKILL_SURVIVAL
            GetSkill = ch.skill_survival
    End Select
End Function

Sub SetKnowledge (ch As CharacterType, index As Integer, value As Integer)
    Select Case index
        Case KNOWLEDGE_BUREAUCRACY
            ch.knowledge_bureaucracy = value
        Case KNOWLEDGE_COMPUTER
            ch.knowledge_computer = value
        Case KNOWLEDGE_FINANCE
            ch.knowledge_finance = value
        Case KNOWLEDGE_INVESTIGATION
            ch.knowledge_investigation = value
        Case KNOWLEDGE_LAW
            ch.knowledge_law = value
        Case KNOWLEDGE_LINGUISTICS
            ch.knowledge_linguistics = value
        Case KNOWLEDGE_MEDICINE
            ch.knowledge_medicine = value
        Case KNOWLEDGE_OCCULT
            ch.knowledge_occult = value
        Case KNOWLEDGE_POLITICS
            ch.knowledge_politics = value
        Case KNOWLEDGE_SCIENCE
            ch.knowledge_science = value
    End Select
End Sub

Function GetKnowledge (ch As CharacterType, index As Integer)
    Select Case index
        Case KNOWLEDGE_BUREAUCRACY
            GetKnowledge = ch.knowledge_bureaucracy
        Case KNOWLEDGE_COMPUTER
            GetKnowledge = ch.knowledge_computer
        Case KNOWLEDGE_FINANCE
            GetKnowledge = ch.knowledge_finance
        Case KNOWLEDGE_INVESTIGATION
            GetKnowledge = ch.knowledge_investigation
        Case KNOWLEDGE_LAW
            GetKnowledge = ch.knowledge_law
        Case KNOWLEDGE_LINGUISTICS
            GetKnowledge = ch.knowledge_linguistics
        Case KNOWLEDGE_MEDICINE
            GetKnowledge = ch.knowledge_medicine
        Case KNOWLEDGE_OCCULT
            GetKnowledge = ch.knowledge_occult
        Case KNOWLEDGE_POLITICS
            GetKnowledge = ch.knowledge_politics
        Case KNOWLEDGE_SCIENCE
            GetKnowledge = ch.knowledge_science
    End Select
End Function

Sub SetBackground (ch As CharacterType, index As Integer, value As Integer)
    Select Case index
        Case BACKGROUND_ALLIES
            ch.background_allies = value
        Case BACKGROUND_CONTACTS
            ch.background_contacts = value
        Case BACKGROUND_FAME
            ch.background_fame = value
        Case BACKGROUND_GENERATION
            ch.background_generation = value
        Case BACKGROUND_HERD
            ch.background_herd = value
        Case BACKGROUND_INFLUENCE
            ch.background_influence = value
        Case BACKGROUND_MENTOR
            ch.background_mentor = value
        Case BACKGROUND_RESOURCES
            ch.background_resources = value
        Case BACKGROUND_RETAINERS
            ch.background_retainers = value
        Case BACKGROUND_STATUS
            ch.background_status = value
    End Select
End Sub

Function GetBackground (ch As CharacterType, index As Integer)
    Select Case index
        Case BACKGROUND_ALLIES
            GetBackground = ch.background_allies
        Case BACKGROUND_CONTACTS
            GetBackground = ch.background_contacts
        Case BACKGROUND_FAME
            GetBackground = ch.background_fame
        Case BACKGROUND_GENERATION
            GetBackground = ch.background_generation
        Case BACKGROUND_HERD
            GetBackground = ch.background_herd
        Case BACKGROUND_INFLUENCE
            GetBackground = ch.background_influence
        Case BACKGROUND_MENTOR
            GetBackground = ch.background_mentor
        Case BACKGROUND_RESOURCES
            GetBackground = ch.background_resources
        Case BACKGROUND_RETAINERS
            GetBackground = ch.background_retainers
        Case BACKGROUND_STATUS
            GetBackground = ch.background_status
    End Select
End Function

Sub FillBackgrounds (ch As CharacterType, backgrounds() As Integer)
    For index = 1 To BACKGROUNDS_COUNT
        backgrounds(index) = GetBackground(ch, index)
    Next
End Sub

Sub SetAttributeValue (ch As CharacterType, AttributeGroupIndex As Integer, AttributeIndex As Integer, Value As Integer)
    Select Case AttributeGroupIndex
        Case ATTRIBUTE_GROUP_PHYSICAL
            Select Case AttributeIndex
                Case ATTRIBUTE_STRENGTH
                    ch.attr_strength = Value
                Case ATTRIBUTE_DEXTERITY
                    ch.attr_dexterity = Value
                Case ATTRIBUTE_STAMINA
                    ch.attr_stamina = Value
            End Select
        Case ATTRIBUTE_GROUP_SOCIAL
            Select Case AttributeIndex
                Case ATTRIBUTE_CHARISMA
                    ch.attr_charisma = Value
                Case ATTRIBUTE_MANIPULATION
                    ch.attr_manipulation = Value
                Case ATTRIBUTE_APPEARANCE
                    ch.attr_appearance = Value
            End Select
        Case ATTRIBUTE_GROUP_MENTAL
            Select Case AttributeIndex
                Case ATTRIBUTE_INTELLIGENCE
                    ch.attr_intelligence = Value
                Case ATTRIBUTE_PERCEPTION
                    ch.attr_perception = Value
                Case ATTRIBUTE_WITS
                    ch.attr_wits = Value
            End Select
    End Select
End Sub

Sub SetAbilityValue (ch As CharacterType, groupIndex As Integer, index As Integer, value As Integer)
    Select Case groupIndex
        Case ABILITY_GROUP_TALENTS
            Call SetTalent(ch, index, value)
        Case ABILITY_GROUP_SKILLS
            Call SetSkill(ch, index, value)
        Case ABILITY_GROUP_KNOWLEDGES
            Call SetKnowledge(ch, index, value)
    End Select
End Sub

Function GetAttributeValue (ch As CharacterType, attributeGroupIndex As Integer, attributeIndex As Integer)
    GetAttributeValue = 0
    Select Case attributeGroupIndex
        Case ATTRIBUTE_GROUP_PHYSICAL
            Select Case attributeIndex
                Case ATTRIBUTE_STRENGTH
                    GetAttributeValue = ch.attr_strength
                Case ATTRIBUTE_DEXTERITY
                    GetAttributeValue = ch.attr_dexterity
                Case ATTRIBUTE_STAMINA
                    GetAttributeValue = ch.attr_stamina
            End Select
        Case ATTRIBUTE_GROUP_SOCIAL
            Select Case attributeIndex
                Case ATTRIBUTE_CHARISMA
                    GetAttributeValue = ch.attr_charisma
                Case ATTRIBUTE_MANIPULATION
                    GetAttributeValue = ch.attr_manipulation
                Case ATTRIBUTE_APPEARANCE
                    GetAttributeValue = ch.attr_appearance
            End Select
        Case ATTRIBUTE_GROUP_MENTAL
            Select Case attributeIndex
                Case ATTRIBUTE_INTELLIGENCE
                    GetAttributeValue = ch.attr_intelligence
                Case ATTRIBUTE_PERCEPTION
                    GetAttributeValue = ch.attr_perception
                Case ATTRIBUTE_WITS
                    GetAttributeValue = ch.attr_wits
            End Select
    End Select
End Function

Function GetAbilityValue (ch As CharacterType, abilityIndex As Integer, itemIndex As Integer)
    GetAbilityValue = 0
    Select Case abilityIndex
        Case ABILITY_GROUP_TALENTS
            GetAbilityValue = GetTalent(ch, itemIndex)
        Case ABILITY_GROUP_SKILLS
            GetAbilityValue = GetSkill(ch, itemIndex)
        Case ABILITY_GROUP_KNOWLEDGES
            GetAbilityValue = GetKnowledge(ch, itemIndex)
    End Select
End Function

Function GetAttributePointsForRank (rank As Integer)
    GetAttributePointsForRank = 0
    Select Case rank
        Case 1
            GetAttributePointsForRank = 7
        Case 2
            GetAttributePointsForRank = 5
        Case 3
            GetAttributePointsForRank = 3
    End Select
End Function

Function GetAbilityPointsForRank (rank As Integer)
    GetAbilityPointsForRank = 0
    Select Case rank
        Case 1
            GetAbilityPointsForRank = 13
        Case 2
            GetAbilityPointsForRank = 9
        Case 3
            GetAbilityPointsForRank = 5
    End Select
End Function

Sub NewCharacter (ch As CharacterType)
    ' Scalars
    ch.name = ""
    ch.player = ""
    ch.chronicle = ""
    ch.haven = ""
    ch.concept = ""
    ch.age = ""
    ch.gender = 0
    ch.clan = 0
    ch.nature = 0
    ch.demeanor = 0
    ch.generation = 13
    ch.roadName = ""
    ch.roadValue = 0
    ch.willpower = 0
    ch.bloodPool = 0
    ch.derangementId = -1
    ' Virtues
    ch.selfControl = 1
    ch.courage = 1
    ch.conscience = 1

    ' Arrays/Objects
    ' Abilities (Talents/Skills/Knowledges)
    For groupIndex = 1 To ABILITY_GROUPS_COUNT
        For index = 1 To GetNumItemsForAbilityGroup(groupIndex)
            Call SetAbilityValue(ch, groupIndex, index, 0)
        Next
    Next
    ' Attributes
    For groupIndex = 1 To ATTRIBUTE_GROUPS_COUNT
        For index = 1 To GetNumAttributesInGroup(groupIndex)
            Call SetAttributeValue(ch, groupIndex, index, 1)
        Next
    Next
    ' Backgrounds
    For index = 1 To BACKGROUNDS_COUNT
        Call SetBackground(ch, index, 0)
    Next
    ' Disciplines
    For index = 1 To DISCIPLINES_COUNT
        Call SetDiscipline(ch, index, 0)
    Next
End Sub

Sub BuildMenu (items() As MenuItem, labels() As String, count As Integer)
    For i = 1 To count
        Dim mi As MenuItem
        Call NewMenuItem(mi, labels(i), i)
        items(i) = mi
    Next
End Sub

Sub BuildMenuWithValues (items() As MenuItem, labels() As String, values() As Integer, count As Integer)
    For i = 1 To count
        Dim mi As MenuItem
        Call NewMenuItemWithValue(mi, labels(i), i, values(i))
        items(i) = mi
    Next
End Sub

Sub BuildMenuWithColors (items() As MenuItem, labels() As String, colors() As Integer)
    ' Check array bounds
    If LBound(items) <> 1 Or LBound(colors) <> 1 Or UBound(items) <> UBound(colors) Then End

    count = UBound(items)
    For i = 1 To count
        Dim mi As MenuItem
        Call NewMenuItemWithColor(mi, labels(i), colors(i), i)
        items(i) = mi
    Next
End Sub

Function ChooseStringId (labels() As String, style As MenuStyle, count As Integer, prompt As String)
    Cls
    Dim mnuItems(1 To count) As MenuItem
    Call BuildMenu(mnuItems(), labels(), count)
    Call AdjustMenuStyle(style, mnuItems(), count, TRUE)
    Print prompt
    Call PrintMenu(mnuItems(), count, style)
    choice = GetMenuChoice(mnuItems(), style, count)
    If choice = style.randomItemId Then choice = GetRandomMenuItemId(mnuItems(), count)
    ChooseStringId = choice
End Function

Function ChooseStringIdWithValues (labels() As String, values() As Integer, style As MenuStyle, count As Integer, prompt As String)
    Cls
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
    Cls
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
    Cls
    Call AdjustMenuStyle(style, items(), count, ignoreValue)
    Print prompt
    Call PrintMenu(items(), count, style)
    choice = GetMenuChoice(items(), style, count)
    If choice = style.randomItemId Then choice = GetRandomMenuItemId(items(), count)
    ChooseMenuItemId = choice
End Function

Sub CGGetHeader (ch As CharacterType)
    Cls
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
    Dim disciplineValues(DISCIPLINES_COUNT) As Integer
    While disciplinePoints > 0
        Cls
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
    Dim ranks(1 To ATTRIBUTE_GROUPS_COUNT) As Integer

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
        ' TODO: Pull this from an array like ranks or rank_names so "Choose your primary attribute?" instead
        nextGroup = ChooseMenuItemId(mnuAttributeGroups(), msWithoutValues, ATTRIBUTE_GROUPS_COUNT, "Choose your next attribute?", TRUE)
        mnuAttributeGroups(nextGroup).isVisible = FALSE
        ranks(nextGroup) = i
        rankSum = rankSum + i + 1
        groupSum = groupSum + nextGroup
    Next
    ' General formula for last choice given 1 to count based indexing is this
    ' (Sum from 1 to count) - (Sum of all previous choice IDs)
    ' Sum(1..AllAttributesCount)-Sum(Choice[1]..Choice[AllAttributesCount-1])
    lastGroup = rankSum - groupSum
    ranks(lastGroup) = ATTRIBUTE_GROUPS_COUNT

    ' Spend attribute points
    For group = 1 To ATTRIBUTE_GROUPS_COUNT
        count = GetNumAttributesInGroup(group)
        ReDim attributes(1 To count) As String
        Call FillAttributesInGroup(group, attributes())
        rank = ranks(group)
        ReDim values(1 To count) As Integer
        For attrPoints = GetAttributePointsForRank(rank) To 1 Step -1
            Call FillAttributeValues(ch, values(), group)
            attribute = ChooseStringIdWithValues(attributes(), values(), msWithValues, count, "Which attribute do you want to spend 1 of your " + itos$(attrPoints) + " points on?")
            Call SetAttributeValue(ch, group, attribute, GetAttributeValue(ch, group, attribute) + 1)
        Next
    Next
End Sub

Sub CGGetAbilities (ch As CharacterType)
    Dim msWithoutValues As MenuStyle
    Call NewMenuStyle(msWithoutValues)
    Dim msWithValues As MenuStyle
    Call NewMenuStyle(msWithValues)
    Dim ranks(1 To ABILITY_GROUPS_COUNT) As Integer

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
        ' TODO: Pull this from an array like ranks or rank_names so "Choose your primary ability?" instead
        nextAbility = ChooseMenuItemId(mnuAbilityGroups(), msWithoutValues, ABILITY_GROUPS_COUNT, "Choose your next ability?", TRUE)
        mnuAbilityGroups(nextAbility).isVisible = FALSE
        ranks(nextAbility) = i
        rankSum = rankSum + i + 1
        groupSum = groupSum + nextAbility
    Next
    ' General formula for last choice given 1 to count based indexing is this
    ' (Sum from 1 to count) - (Sum of all previous choice IDs)
    ' Sum(1..AllAttributesCount)-Sum(Choice[1]..Choice[AllAttributesCount-1])
    lastGroup = rankSum - groupSum
    ranks(lastGroup) = ABILITY_GROUPS_COUNT

    ' Spend ability points
    For group = 1 To ABILITY_GROUPS_COUNT
        count = GetNumItemsForAbilityGroup(group)
        ReDim abilities(1 To count) As String
        Call FillAbilitiesForAbilityGroup(group, abilities())
        rank = ranks(group)
        ReDim values(1 To count) As Integer
        For abilityPoints = GetAbilityPointsForRank(rank) To 1 Step -1
            Call FillAbilityValues(ch, values(), group)
            ' TODO: Pull this from an array like AbilityGroupsSingle so "Which talent would you like to spend 1 of your 5 points on?"
            ability = ChooseStringIdWithValues(abilities(), values(), msWithValues, count, "Which ability would you like to spend 1 of your " + itos$(abilityPoints) + " points on?")
            Call SetAbilityValue(ch, group, ability, GetAbilityValue(ch, group, ability) + 1)
        Next
    Next
End Sub

Sub CGGetBackgrounds (ch As CharacterType)
    ' Spend background points
    Dim ms As MenuStyle
    Call NewMenuStyle(ms)
    backgroundPoints = GetBackgroundPoints
    Dim backgroundValues(BACKGROUNDS_COUNT) As Integer
    While backgroundPoints > 0
        Cls
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
        If virtue = 0 Then virtue = GetRandomInt(1, VIRTUES_COUNT)
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
        If ch.derangementId = 0 Then ch.derangementId = GetRandomInt(1, DERANGEMENTS_COUNT)
    End If
End Sub

Sub SetColor (c As Integer)
    ScreenColor = c
    Color c
End Sub

Function GetColor ()
    GetColor = ScreenColor
End Function

Sub CGSpendFreebiePoints (ch As CharacterType)
End Sub

' Ignore this warning ch is not used yet because the sub is not implemented yet.
Sub SaveCharacterSheet (ch As CharacterType)
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
    '| Sta. 2       Man. 4       Wit. 4     | Derangements:                         |
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
    Dim disciplineValues(DISCIPLINES_COUNT) As Integer
    Call FillDisciplines(ch, disciplineValues())

    Dim backgroundValues(BACKGROUNDS_COUNT) As Integer
    Call FillBackgrounds(ch, backgroundValues())

    '... 0123456789
    '160  กขฃคฅฆงจฉ
    '170 ชซฌญฎฏฐฑฒณ
    '180 ดตถทธนบปผฝ
    '190 พฟภมยรฤลฦว
    '200 ศษสหฬอฮฯะั
    '210 าำิีึืฺุูÛ
    '220 ÜÝÞ฿เแโใไๅๅ
    '230 ๆ็่้๊๋2์ํ๎๏
    ' enquote forms s/^([ษบศอฬ].*[ปบผน])$/print "$1"/g

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

    Cls
    Print "ษออออออออออออออออออออออออออออออออออออออหอออออออออออออออออออออออออออออออออออออออป"
    Print "บ Name: " + MakeFitL$(ch.name, 30, " ") + " บ Gender: " + MakeFitL$(Genders(ch.gender), 14, " ") + " Generation: " + MakeFitR$(itos$(ch.generation), 2, " ") + " บ"
    Print "บ Clan: " + MakeFitL$(Clans(ch.clan), 30, " ") + " บ Age: " + MakeFitL$(ch.age$, 32, " ") + " บ"
    Print "ฬออออออออออออออออออออออออออออออออออออออน Player: " + MakeFitL$(ch.player$, 29, " ") + " บ"
    Print "บ              Attributes              บ Chronicle: " + MakeFitL$(ch.chronicle$, 26, " ") + " บ"
    Print "บ   Physical     Social      Mental    บ Haven: " + MakeFitL$(ch.haven$, 30, " ") + " บ"
    Print "บ Str. " + MakeFitL$(itos$(ch.attr_strength), 7, " ") + " App. " + MakeFitL$(itos$(ch.attr_appearance), 7, " ") + " Int. " + MakeFitL$(itos$(ch.attr_intelligence), 5, " ") + " บ Concept: " + MakeFitL$(ch.concept$, 28, " ") + " บ"
    Print "บ Dex. " + MakeFitL$(itos$(ch.attr_dexterity), 7, " ") + " Cha. " + MakeFitL$(itos$(ch.attr_charisma), 7, " ") + " Per. " + MakeFitL$(itos$(ch.attr_perception), 5, " ") + " ฬอออออออออออออออออออออออออออออออออออออออน"
    Print "บ Sta. " + MakeFitL$(itos$(ch.attr_stamina), 7, " ") + " Man. " + MakeFitL$(itos$(ch.attr_manipulation), 7, " ") + " Wit. " + MakeFitL$(itos$(ch.attr_wits), 5, " ") + " บ Derangements:                         บ"
    Print "ฬออออออออออออออออออออออออออออออออออออออน " + derangementStrings(0) + " บ"
    Print "บ Disciplines:                         บ " + derangementStrings(1) + " บ"
    Print "บ " + MakeFitL$(disciplineStrings(0), 36, " ") + " บ " + MakeFitL$(derangementStrings(2), 37, "_") + " บ"
    Print "บ " + MakeFitL$(disciplineStrings(1), 36, " ") + " บ " + MakeFitL$(derangementStrings(3), 37, "_") + " บ"
    Print "บ " + MakeFitL$(disciplineStrings(2), 36, " ") + " บ " + MakeFitL$(derangementStrings(4), 37, "_") + " บ"
    Print "ฬออออออออออออออออออออออออออออออออออออออฮอออออออออออออออออออออออออออออออออออออออน"
    Print "บ " + MakeFitL$(ch.roadName + ": " + itos$(ch.roadValue), 36, " ") + " บ Nature: " + MakeFitL$(Archetypes(ch.nature), 29, " ") + " บ"
    Print "บ Willpower: " + MakeFitL$(itos$(ch.willpower), 25, " ") + " บ Demeanor: " + MakeFitL$(Archetypes(ch.demeanor), 27, " ") + " บ"
    Print "ฬออออออออออออออออออออออออออออออออออออออสอออออออออออออออออออออออออออออออออออออออน"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ                                                                              บ"
    Print "บ                        <<PRESS ANY KEY TO CONTINUE>>                         บ"
    Print "ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ"
    Call PressAnyKeyToContinue

    Print "ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป"
    Print "บ " + MakeFitC$("Abilities", 76, " ") + " บ"
    Print "บ " + MakeFitC$("Talents", 25, " ") + " " + MakeFitC$("Skills", 25, " ") + " " + MakeFitC$("Knowledges", 24, " ") + " บ"
    For index = 1 To 10
        Print "บ " + MakeFitC(MakeFitL$(Talents(index) + ":", 14, " ") + itos$(GetTalent(ch, index)), 25, " ") + " " + MakeFitC(MakeFitL$(Skills(index) + ":", 14, " ") + itos$(GetSkill(ch, index)), 25, " ") + " " + MakeFitC(MakeFitL$(Knowledges(index) + ":", 14, " ") + itos$(GetKnowledge(ch, index)), 24, " ") + " บ"
    Next
    Print "ฬออออออออออออออออออออออออออออออออออออออหอออออออออออออออออออออออออออออออออออออออน"
    Print "บ Backgrounds:                         บ Virtues:                              บ"
    Print "บ " + MakeFitL$(backgroundStrings(0), 36, " ") + " บ " + MakeFitB$("Conscience:", itos$(ch.conscience), 37, " ") + " บ"
    Print "บ " + MakeFitL$(backgroundStrings(1), 36, " ") + " บ " + MakeFitB$("Self-Control:", itos$(ch.selfControl), 37, " ") + " บ"
    Print "บ " + MakeFitL$(backgroundStrings(2), 36, " ") + " บ " + MakeFitB$("Courage:", itos$(ch.courage), 37, " ") + " บ"
    Print "บ " + MakeFitL$(backgroundStrings(3), 36, " ") + " บ " + MakeFitL$("", 37, " ") + " บ"
    Print "บ " + MakeFitL$(backgroundStrings(4), 36, " ") + " บ " + MakeFitL$("", 37, " ") + " บ"
    Print "ฬออออออออออออออออออออออออออออออออออออออสอออออออออออออออออออออออออออออออออออออออน"
    Print "บ                        <<PRESS ANY KEY TO CONTINUE>>                         บ"
    Print "ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ"
    Call PressAnyKeyToContinue
End Sub

Sub FillAttributeValues (ch As CharacterType, values() As Integer, groupIndex As Integer)
    count = GetNumAttributesInGroup(groupIndex)
    ReDim values(1 To count) As Integer
    For i = 1 To count
        values(i) = GetAttributeValue(ch, groupIndex, i)
    Next
End Sub

Sub FillAbilityValues (ch As CharacterType, values() As Integer, groupIndex As Integer)
    count = GetNumItemsForAbilityGroup(groupIndex)
    ReDim values(1 To count) As Integer
    For i = 1 To count
        values(i) = GetAbilityValue(ch, groupIndex, i)
    Next
End Sub

' Simpler character generator with fewer questions and more things done randomly without asking.
Sub CharacterGeneratorForDummies
    Print "CharacterGeneratorForDummies"
End Sub

' Maybe just remove this. It's kinda pointless. It asks some questions and calculates a contested roll.
' C1 dice pool, C1 difficulty, C2 dice pool, C2 difficulty, then rolls all the dice and does the math.
' In practice it's just slower than rolling the dice
Sub CombatComputer
    Print "CombatComputer"
End Sub

' Asks for a number of dice and a difficulty. Rolls the dice, calculates botches and successes.
Sub DiceRoller
    Print "DiceRoller"
End Sub

' Like the character generator if you choose random for everything. Should do random names/ages too, but doesn't yet.
Sub RandomCharacterGenerator
    Print "RandomCharacterGenerator"
End Sub

' This had a function at one point but got taken out. Will only come back if the disassembly can figure it out.
Sub Choice6
    Print "Unnamed choice 6"
End Sub

' Like the character generator but for vehicles. Much simpler with fewer questions. Prints a vehicle sheet when done. Never finished and crashes mid way through currently.
Sub VehicleGenerator
    Print "VehicleGenerator"
End Sub

Sub PressAnyKeyToContinue ()
    While InKey$ = "": Wend
End Sub

Function GetNumAttributesInGroup (index As Integer)
    Select Case index
        Case ATTRIBUTE_GROUP_PHYSICAL
            count = PHYSICAL_ATTRIBUTES_COUNT
        Case ATTRIBUTE_GROUP_SOCIAL
            count = SOCIAL_ATTRIBUTES_COUNT
        Case ATTRIBUTE_GROUP_MENTAL
            count = MENTAL_ATTRIBUTES_COUNT
        Case Else
            count = 0
    End Select
    GetNumAttributesInGroup = count
End Function

Function GetNumItemsForAbilityGroup (index As Integer)
    Select Case index
        Case ABILITY_GROUP_TALENTS
            count = TALENTS_COUNT
        Case ABILITY_GROUP_SKILLS
            count = SKILLS_COUNT
        Case ABILITY_GROUP_KNOWLEDGES
            count = KNOWLEDGES_COUNT
        Case Else
            count = 0
    End Select
    GetNumItemsForAbilityGroup = count
End Function

Function GetAttributeName$ (groupIndex As Integer, attributeIndex As Integer)
    attributeName$ = ""
    Select Case groupIndex
        Case ATTRIBUTE_GROUP_PHYSICAL
            attributeName$ = PhysicalAttributes(attributeIndex)
        Case ATTRIBUTE_GROUP_SOCIAL
            attributeName$ = SocialAttributes(attributeIndex)
        Case ATTRIBUTE_GROUP_MENTAL
            attributeName$ = MentalAttributes(attributeIndex)
    End Select
    GetAttributeName = attributeName$
End Function

Function GetAbilityName$ (groupIndex As Integer, abilityIndex As Integer)
    abilityName$ = ""
    Select Case groupIndex
        Case ABILITY_GROUP_TALENTS
            abilityName$ = Talents(abilityIndex)
        Case ABILITY_GROUP_SKILLS
            abilityName$ = Skills(abilityIndex)
        Case ABILITY_GROUP_KNOWLEDGES
            abilityName$ = Knowledges(abilityIndex)
    End Select
    GetAbilityName = abilityName$
End Function

Sub FillAttributesInGroup (group As Integer, attributes() As String)
    count = GetNumAttributesInGroup(group)
    If count > 0 Then
        ReDim attributes(1 To count) As String
    Else
        ReDim attributes(0) As String
    End If
    Select Case group
        Case ATTRIBUTE_GROUP_PHYSICAL
            For i = 1 To count
                attributes(i) = PhysicalAttributes(i)
            Next
        Case ATTRIBUTE_GROUP_SOCIAL
            For i = 1 To count
                attributes(i) = SocialAttributes(i)
            Next
        Case ATTRIBUTE_GROUP_MENTAL
            For i = 1 To count
                attributes(i) = MentalAttributes(i)
            Next
    End Select
End Sub

Sub FillAbilitiesForAbilityGroup (ability As Integer, items() As String)
    count = GetNumItemsForAbilityGroup(ability)
    ReDim items(1 To count) As String
    If count > 0 Then
        ReDim items(1 To count) As String
    Else
        ReDim items(0) As String
    End If
    Select Case ability
        Case ABILITY_GROUP_TALENTS
            For i = 1 To count
                items(i) = Talents(i)
            Next
        Case ABILITY_GROUP_SKILLS
            For i = 1 To count
                items(i) = Skills(i)
            Next
        Case ABILITY_GROUP_KNOWLEDGES
            For i = 1 To count
                items(i) = Knowledges(i)
            Next
    End Select
End Sub

Sub FillAttributeAbbreviationsInGroup (group As Integer, abbreviations() As String, count As Integer)
    count = GetNumAttributesInGroup(group)
    If count > 0 Then
        ReDim abbreviations(1 To count) As String
    Else
        ReDim abbreviations(0) As String
    End If
    Select Case group
        Case ATTRIBUTE_GROUP_PHYSICAL
            For i = 1 To count
                abbreviations(i) = PhysicalAttributeAbbreviations(i)
            Next
        Case ATTRIBUTE_GROUP_SOCIAL
            For i = 1 To count
                abbreviations(i) = SocialAttributeAbbreviations(i)
            Next
        Case ATTRIBUTE_GROUP_MENTAL
            For i = 1 To count
                abbreviations(i) = MentalAttributeAbbreviations(i)
            Next
    End Select
End Sub


Sub AdjustMenuStyle (style As MenuStyle, items() As MenuItem, count As Integer, ignoreValue As Integer)
    maxIdWidth = 0
    maxItemWidth = 0
    maxValueWidth = 0

    For i = 1 To count
        If items(i).isVisible Then
            maxIdWidth = MaxI(maxIdWidth, Len(itos$(items(i).id)))
            maxItemWidth = MaxI(maxItemWidth, Len(items(i).label + style.labelValueSeparator))
            maxValueWidth = MaxI(maxValueWidth, Len(itos$(items(i).value)))
        End If
    Next
    If style.showRandom Then
        maxIdWidth = MaxI(maxIdWidth, Len("0"))
        maxItemWidth = MaxI(maxItemWidth, Len(style.randomItemName))
    End If
    style.idWidth = maxIdWidth
    style.labelWidth = maxItemWidth
    If Not ignoreValue Then style.valueWidth = maxValueWidth Else style.valueWidth = 0
End Sub

Sub PrintMenu (items() As MenuItem, count As Integer, style As MenuStyle)
    Dim randomItem As MenuItem
    Call NewMenuItem(randomItem, style.randomItemName, style.randomItemId)
    If count <= 10 Then
        For i = 1 To count
            If items(i).isVisible Then
                If style.useColors Then
                    oldColor = GetColor
                    SetColor (items(i).color)
                End If
                Print GetTitle$(items(i), style)
                If style.useColors Then
                    Call SetColor(oldColor)
                End If
            End If
        Next
        If style.showRandom Then
            Print GetTitleWithoutValue$(randomItem, style)
        End If
    Else
        Dim emptyItem As MenuItem
        Call NewMenuItem(emptyItem, "", 0)
        itemWidth = Len(GetTitle$(emptyItem, style))
        itemsPerRow = style.screenWidth \ (itemWidth + Len(style.menuItemSpacer))
        columnWidth = style.screenWidth \ itemsPerRow

        column = 0
        For i = 1 To count
            If items(i).isVisible Then
                itemText$ = GetTitle$(items(i), style)
                If column <> (itemsPerRow - 1) Then
                    If i <> count Or style.showRandom Then
                        textLength = Len(itemText$)
                        itemText$ = MakeFitL$(RTrim$(itemText$) + style.menuItemSpacer, textLength + Len(style.menuItemSpacer), " ")
                    End If
                End If
                Print MakeFitC$(itemText$, columnWidth, " ");
            End If
            column = (column + 1) Mod itemsPerRow
            If column = 0 Then Print ""
        Next
        If style.showRandom Then
            Print MakeFitC$(GetTitleWithoutValue$(randomItem, style), columnWidth, " ")
        End If
    End If
End Sub

Function GetTitle$ (mi As MenuItem, ms As MenuStyle)
    id$ = itos$(mi.id)
    label$ = mi.label
    If ms.valueWidth > 0 Then label$ = label$ + ms.labelValueSeparator
    value$ = itos$(mi.value)
    GetTitle$ = MakeFitR$(id$, ms.idWidth, " ") + ms.idLabelSeparator + MakeFitL$(label$, ms.labelWidth, " ") + MakeFitR$(value$, ms.valueWidth, " ")
End Function

Function GetTitleWithoutValue$ (mi As MenuItem, ms As MenuStyle)
    GetTitleWithoutValue$ = MakeFitR$(itos(mi.id), ms.idWidth, " ") + ms.idLabelSeparator + MakeFitL$(mi.label, ms.labelWidth + ms.valueWidth + Len(ms.labelValueSeparator), " ")
End Function

Sub NewMenuStyle (ms As MenuStyle)
    ms.idWidth = 0
    ms.labelWidth = 0
    ms.valueWidth = 0
    ms.screenWidth = 80
    ms.randomItemName = "Random"
    ms.randomItemId = 0
    ms.idLabelSeparator = " = "
    ms.labelValueSeparator = ": "
    ms.menuItemSpacer = ", "
    ms.showRandom = TRUE
    ms.useColors = FALSE
End Sub

Sub NewMenuItem (mi As MenuItem, label As String, id As Integer)
    mi.id = id
    mi.label = label
    mi.value = 0
    mi.color = COLOR_DEFAULT
    mi.isVisible = TRUE
End Sub

Sub NewMenuItemWithValue (mi As MenuItem, label As String, id As Integer, value As Integer)
    mi.id = id
    mi.label = label
    mi.value = value
    mi.color = COLOR_DEFAULT
    mi.isVisible = TRUE
End Sub

Sub NewMenuItemWithColor (mi As MenuItem, label As String, textColor As Integer, id As Integer)
    mi.id = id
    mi.label = label
    mi.value = 0
    mi.color = textColor
    mi.isVisible = TRUE
End Sub

Sub NewDerangement (derangement As DerangementType, id As Integer, label As String, textColor As Integer, description As String)
    derangement.id = id
    derangement.label = label
    derangement.textColor = textColor
    derangement.description = description
End Sub

Function GetDisciplinePoints ()
    GetDisciplinePoints = DISCIPLINE_POINTS
End Function

Function GetBackgroundPoints ()
    GetBackgroundPoints = BACKGROUND_POINTS
End Function

Function GetVirtuePoints ()
    GetVirtuePoints = VIRTUE_POINTS
End Function

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

Sub Test
    'End
End Sub

