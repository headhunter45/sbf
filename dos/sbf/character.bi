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

Const DISCIPLINE_POINTS = 3
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
Const VIRTUE_POINTS = 7
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

Const BACKGROUND_POINTS = 5
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

Const DERANGEMENT_COLOR_AMNESIA = COLOR_DARK_RED
Const DERANGEMENT_COLOR_DELUSIONS_OF_GRANDEUR = COLOR_DARK_MAGENTA
Const DERANGEMENT_COLOR_FANTASY = COLOR_DARK_ORANGE
Const DERANGEMENT_COLOR_MANIC_DEPRESSION = COLOR_DARK_WHITE
Const DERANGEMENT_COLOR_MULTIPLE_PERSONALITIES = COLOR_DARK_BLUE
Const DERANGEMENT_COLOR_OBSESSION = COLOR_BRIGHT_GREEN
Const DERANGEMENT_COLOR_OVERCOMPENSATION = COLOR_BRIGHT_CYAN
Const DERANGEMENT_COLOR_PARANOIA = COLOR_BRIGHT_RED
Const DERANGEMENT_COLOR_PERFECTION = COLOR_BRIGHT_MAGENTA
Const DERANGEMENT_COLOR_REGRESSION = COLOR_BRIGHT_YELLOW
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

Const FREEBIES_COUNT = 7
Dim Shared FreebieCosts(1 To FREEBIES_COUNT) As Integer
Dim Shared FreebieLabels(1 To FREEBIES_COUNT) As String
Dim Shared FreebieNames(1 to FREEBIES_COUNT) As String
Dim Shared Freebies(1 To FREEBIES_COUNT) As FreebieType
Const FREEBIE_DISCIPLINE_ID = 1
Const FREEBIE_DISCIPLINE_COST = 7
Const FREEBIE_DISCIPLINE_NAME = "Discipline"
Const FREEBIE_DISCIPLINE_LABEL = "Add a discipline dot    7 points"

Const FREEBIE_ATTRIBUTE_ID = 2
Const FREEBIE_ATTRIBUTE_COST = 5
Const FREEBIE_ATTRIBUTE_NAME = "Attribute"
Const FREEBIE_ATTRIBUTE_LABEL = "Add an attribute dot    5 points"

Const FREEBIE_ABILITY_ID = 3
Const FREEBIE_ABILITY_COST = 2
Const FREEBIE_ABILITY_NAME = "Ability"
Const FREEBIE_ABILITY_LABEL = "Add an ability dot      2 points"

Const FREEBIE_VIRTUE_ID = 4
Const FREEBIE_VIRTUE_COST = 2
Const FREEBIE_VIRTUE_NAME = "Virtue"
Const FREEBIE_VIRTUE_LABEL = "Add a virtue dot        2 points"

' TODO: Make this configurable for VtDA
Const FREEBIE_HUMANITY_ID = 5
Const FREEBIE_HUMANITY_COST = 1
Const FREEBIE_HUMANITY_NAME = "Humanity"
Const FREEBIE_HUMANITY_LABEL = "Add a humanity dot      1 point"

Const FREEBIE_BACKGROUND_ID = 6
Const FREEBIE_BACKGROUND_COST = 1
Const FREEBIE_BACKGROUND_NAME = "Background"
Const FREEBIE_BACKGROUND_LABEL = "Add a background dot    1 point"

Const FREEBIE_SHOW_CHARACTER_SHEET_ID = 7
Const FREEBIE_SHOW_CHARACTER_SHEET_COST = 0
Const FREEBIE_SHOW_CHARACTER_SHEET_NAME = "Show character sheet"
Const FREEBIE_SHOW_CHARACTER_SHEET_LABEL = FREEBIE_SHOW_CHARACTER_SHEET_NAME

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
    freebiePoints As Integer
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

Type DerangementType
    id As Integer
    label As String
    description As String
    textColor As Integer
End Type

Type FreebieType
    id As Integer
    cost As Integer
    name As String * 32
    label As String * 32 
End Type
