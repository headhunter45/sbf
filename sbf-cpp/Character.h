#ifndef CHARACTER_H__
#define CHARACTER_H__
#include "Colors.h"
#include <string>
#include <cstdint>
#include <vector>

namespace SBF {
    using std::wstring;

    const int kRankPrimaryId = 1;
    const wstring kRankPrimaryLabel = L"Primary";
    const int kRankSecondaryId = 2;
    const wstring kRankSecondaryLabel = L"Secondary";
    const int kRankTertiaryId = 3;
    const wstring kRankTertiaryLabel = L"Tertiary";
    const int kRanksCount = 3;
    struct RankType {
        int id;
        wstring label;
    };
    const RankType kRanks[] {
        {0, L""},
        {kRankPrimaryId, kRankPrimaryLabel},
        {kRankSecondaryId, kRankSecondaryLabel},
        {kRankTertiaryId, kRankTertiaryLabel},
    };

    const int kClanAnarch = 1;
    const wstring kClanAnarchLabel = L"Anarch";
    const int kClanAssamite = 2;
    const wstring kClanAssamiteLabel = L"Assamite";
    const int kClanBaali = 3;
    const wstring kClanBaaliLabel = L"Baali";
    const int kClanBrujah = 4;
    const wstring kClanBrujahLabel = L"Brujah";
    const int kClanCaitiff = 5;
    const wstring kClanCaitiffLabel = L"Caitiff";
    const int kClanCappadocian = 6;
    const wstring kClanCappadocianLabel = L"Cappadocian";
    const int kClanGangrel = 7;
    const wstring kClanGangrelLabel = L"Gangrel";
    const int kClanGiovanni = 8;
    const wstring kClanGiovanniLabel = L"Giovanni";
    const int kClanInconnu = 9;
    const wstring kClanInconnuLabel = L"Inconnu";
    const int kClanLasombra = 10;
    const wstring kClanLasombraLabel = L"Lasombra";
    const int kClanMalkavian = 11;
    const wstring kClanMalkavianLabel = L"Malkavian";
    const int kClanNosferatu = 12;
    const wstring kClanNosferatuLabel = L"Nosferatu";
    const int kClanRavanos = 13;
    const wstring kClanRavanosLabel = L"Ravanos";
    const int kClanSettite = 14;
    const wstring kClanSettiteLabel = L"Settite";
    const int kClanToreador = 15;
    const wstring kClanToreadorLabel = L"Toreador";
    const int kClanTremere = 16;
    const wstring kClanTremereLabel = L"Tremere";
    const int kClanTzismice = 17;
    const wstring kClanTzismiceLabel = L"Tzismice";
    const int kClanVentrue = 18;
    const wstring kClanVentrueLabel = L"Ventrue";
    const int kClansCount = 18;
    const wstring kClans[] = {
        L"",
        kClanAnarchLabel,
        kClanAssamiteLabel,
        kClanBaaliLabel,
        kClanBrujahLabel,
        kClanCaitiffLabel,
        kClanCappadocianLabel,
        kClanGiovanniLabel,
        kClanInconnuLabel,
        kClanLasombraLabel,
        kClanMalkavianLabel,
        kClanNosferatuLabel,
        kClanRavanosLabel,
        kClanSettiteLabel,
        kClanToreadorLabel,
        kClanTremereLabel,
        kClanVentrueLabel,
    };

    const int kArchetypeArchitectId = 1;
    const wstring kArchetypeArchitectLabel = L"Architect";
    const int kArchetypeAutocratId = 2;
    const wstring kArchetypeAutocratLabel = L"Autocrat";
    const int kArchetypeBarbarianId = 3;
    const wstring kArchetypeBarbarianLabel = L"Barbarian";
    const int kArchetypeBonVivantId = 4;
    const wstring kArchetypeBonVivantLabel = L"Bon Vivant";
    const int kArchetypeBravoId = 5;
    const wstring kArchetypeBravoLabel = L"Bravo";
    const int kArchetypeCaregiverId = 6;
    const wstring kArchetypeCaregiverLabel = L"Caregiver";
    const int kArchetypeCaretakerId = 7;
    const wstring kArchetypeCaretakerLabel = L"Caretaker";
    const int kArchetypeCelebrantId = 8;
    const wstring kArchetypeCelebrantLabel = L"Celebrant";
    const int kArchetypeChildId = 9;
    const wstring kArchetypeChildLabel = L"Child";
    const int kArchetypeConformist = 10;
    const wstring kArchetypeConformistLabel = L"Conformist";
    const int kArchetypeConniverId = 11;
    const wstring kArchetypeConniverLabel = L"Conniver";
    const int kArchetypeCurmudgeonId = 12;
    const wstring kArchetypeCurmudgeonLabel = L"Curmudgeon";
    const int kArchetypeDefenderId = 13;
    const wstring kArchetypeDefenderLabel = L"Defender";
    const int kArchetypeDeviantId = 14;
    const wstring kArchetypeDeviantLabel = L"Deviant";
    const int kArchetypeDirectorId = 15;
    const wstring kArchetypeDirectorLabel = L"Director";
    const int kArchetypeFanaticId = 16;
    const wstring kArchetypeFanaticLabel = L"Fanatic";
    const int kArchetypeGallantId = 17;
    const wstring kArchetypeGallantLabel = L"Gallant";
    const int kArchetypeInnovatorId = 18;
    const wstring kArchetypeInnovatorLabel = L"Innovator";
    const int kArchetypeJesterId = 19;
    const wstring kArchetypeJesterLabel = L"Jester";
    const int kArchetypeJudgeId = 20;
    const wstring kArchetypeJudgeLabel = L"Judge";
    const int kArchetypeLoanerId = 21;
    const wstring kArchetypeLoanerLabel = L"Loaner";
    const int kArchetypeMartyrId = 22;
    const wstring kArchetypeMartyrLabel = L"Martyr";
    const int kArchetypeMonsterId = 23;
    const wstring kArchetypeMonsterLabel = L"Monster";
    const int kArchetypePenitentId = 24;
    const wstring kArchetypePenitentLabel = L"Penitent";
    const int kArchetypeRebelId = 25;
    const wstring kArchetypeRebelLabel = L"Rebel";
    const int kArchetypeRogueId = 26;
    const wstring kArchetypeRogueLabel = L"Rogue";
    const int kArchetypeSurvivorId = 27;
    const wstring kArchetypeSurvivorLabel = L"Survivor";
    const int kArchetypeTraditionalistId = 28;
    const wstring kArchetypeTraditionalistLabel = L"Traditionalist";
    const int kArchetypeTyrantId = 29;
    const wstring kArchetypeTyrantLabel = L"Tyrant";
    const int kArchetypeVisionaryId = 30;
    const wstring kArchetypeVisionaryLabel = L"Visionary";
    const int kArchetypesCount = 30;
    const wstring kArchetypes[] = {
        L"",
        kArchetypeArchitectLabel,
        kArchetypeAutocratLabel,
        kArchetypeBarbarianLabel,
        kArchetypeBonVivantLabel,
        kArchetypeBravoLabel,
        kArchetypeCaregiverLabel,
        kArchetypeCaretakerLabel,
        kArchetypeCelebrantLabel,
        kArchetypeChildLabel,
        kArchetypeConformistLabel,
        kArchetypeConniverLabel,
        kArchetypeCurmudgeonLabel,
        kArchetypeDefenderLabel,
        kArchetypeDeviantLabel,
        kArchetypeDirectorLabel,
        kArchetypeFanaticLabel,
        kArchetypeGallantLabel,
        kArchetypeInnovatorLabel,
        kArchetypeJesterLabel,
        kArchetypeJudgeLabel,
        kArchetypeLoanerLabel,
        kArchetypeMartyrLabel,
        kArchetypeMonsterLabel,
        kArchetypePenitentLabel,
        kArchetypeRebelLabel,
        kArchetypeRogueLabel,
        kArchetypeSurvivorLabel,
        kArchetypeTraditionalistLabel,
        kArchetypeTyrantLabel,
        kArchetypeVisionaryLabel,
    };

    const int kDisciplinePoints = 3;
    const int kDisciplineAnimalismId = 1;
    const wstring kDisciplineAnimalismLabel = L"Animalism";
    const int kDisciplineAuspexId = 2;
    const wstring kDisciplineAuspexLabel = L"Auspex";
    const int kDisciplineBardoId = 3;
    const wstring kDisciplineBardoLabel = L"Bardo";
    const int kDisciplineCelerityId = 4;
    const wstring kDisciplineCelerityLabel = L"Celerity";
    const int kDisciplineChimestryId = 5;
    const wstring kDisciplineChimestryLabel = L"Chimestry";
    const int kDisciplineDementationId = 6;
    const wstring kDisciplineDementationLabel = L"Dementation";
    const int kDisciplineDominateId = 7;
    const wstring kDisciplineDominateLabel = L"Dominate";
    const int kDisciplineFortitudeId = 8;
    const wstring kDisciplineFortitudeLabel = L"Fortitude";
    const int kDisciplineMelpomineeId = 9;
    const wstring kDisciplineMelpomineeLabel = L"Melpominee";
    const int kDisciplineMortisId = 10;
    const wstring kDisciplineMortisLabel = L"Mortis";
    const int kDisciplineMytherceriaId = 11;
    const wstring kDisciplineMytherceriaLabel = L"Mytherceria";
    const int kDisciplineNecromancyId = 12;
    const wstring kDisciplineNecromancyLabel = L"Necromancy";
    const int kDisciplineObeahId = 13;
    const wstring kDisciplineObeahLabel = L"Obeah";
    const int kDisciplineObfuscateId = 14;
    const wstring kDisciplineObfuscateLabel = L"Obfuscate";
    const int kDisciplineObtenebrationId = 15;
    const wstring kDisciplineObtenebrationLabel = L"Obtenebration";
    const int kDisciplinePotenceId = 16;
    const wstring kDisciplinePotenceLabel = L"Potence";
    const int kDisciplinePresenceId = 17;
    const wstring kDisciplinePresenceLabel = L"Presence";
    const int kDisciplineProteanId = 18;
    const wstring kDisciplineProteanLabel = L"Protean";
    const int kDisciplineQuietusId = 19;
    const wstring kDisciplineQuietusLabel = L"Quietus";
    const int kDisciplineSerpentisId = 20;
    const wstring kDisciplineSerpentisLabel = L"Serpentis";
    const int kDisciplineSpiritusId = 21;
    const wstring kDisciplineSpiritusLabel = L"Spiritus";
    const int kDisciplineThanantosisId = 22;
    const wstring kDisciplineThanantosisLabel = L"Thanantosis";
    const int kDisciplineThaumaturgyId = 23;
    const wstring kDisciplineThaumaturgyLabel = L"Thaumaturgy";
    const int kDisciplineVicissitudeId = 24;
    const wstring kDisciplineVicissitudeLabel = L"Vicissitude";
    const int kDisciplinesCount = 24;
    const wstring kDisciplines[] = {
        L"",
        kDisciplineAnimalismLabel,
        kDisciplineAuspexLabel,
        kDisciplineBardoLabel,
        kDisciplineCelerityLabel,
        kDisciplineChimestryLabel,
        kDisciplineDementationLabel,
        kDisciplineDominateLabel,
        kDisciplineFortitudeLabel,
        kDisciplineMelpomineeLabel,
        kDisciplineMortisLabel,
        kDisciplineMytherceriaLabel,
        kDisciplineNecromancyLabel,
        kDisciplineObeahLabel,
        kDisciplineObfuscateLabel,
        kDisciplineObtenebrationLabel,
        kDisciplinePotenceLabel,
        kDisciplinePresenceLabel,
        kDisciplineProteanLabel,
        kDisciplineQuietusLabel,
        kDisciplineSerpentisLabel,
        kDisciplineSpiritusLabel,
        kDisciplineThanantosisLabel,
        kDisciplineThaumaturgyLabel,
        kDisciplineVicissitudeLabel,
    };

    const int kVirtuePoints = 7;
    const int kVirtueSelfControlId = 1;
    const wstring kVirtueSelfControlLabel = L"Self-Control";
    const int kVirtueCourageId = 2;
    const wstring kVirtueCourageLabel = L"Courage";
    const int kVirtueConscienceId = 3;
    const wstring kVirtueConscienceLabel = L"Conscience";
    const int kVirtuesCount = 3;
    const wstring kVirtues[] = {
        L"",
        kVirtueSelfControlLabel,
        kVirtueCourageLabel,
        kVirtueConscienceLabel,
    };

    const int kPhysicalAttributeStrengthId = 1;
    const wstring kPhysicalAttributeStrengthLabel = L"Strength";
    const wstring kPhysicalAttributeStrengthAbbreviation = L"Str.";
    const int kPhysicalAttributeDexterityId = 2;
    const wstring kPhysicalAttributeDexterityLabel = L"Dexterity";
    const wstring kPhysicalAttributeDexterityAbbreviation = L"Dex.";
    const int kPhysicalAttributeStaminaId = 3;
    const wstring kPhysicalAttributeStaminaLabel = L"Stamina";
    const wstring kPhysicalAttributeStaminaAbbreviation = L"Sta.";
    const int kPhysicalAttributesCount = 3;
    const wstring kPhysicalAttributeLabels[] = {
        L"",
        kPhysicalAttributeStrengthLabel,
        kPhysicalAttributeDexterityLabel,
        kPhysicalAttributeStaminaLabel,
    };
    const wstring kPhysicalAttributeAbbreviations[] = {
        L"",
        kPhysicalAttributeStrengthAbbreviation,
        kPhysicalAttributeDexterityAbbreviation,
        kPhysicalAttributeStaminaAbbreviation,
    };

    const int kSocialAttributeCharismaId = 1;
    const wstring kSocialAttributeCharismaLabel = L"Charisma";
    const wstring kSocialAttributeCharismaAbbreviation = L"Cha.";
    const int kSocialAttributeManipulationId = 2;
    const wstring kSocialAttributeManipulationLabel = L"Manipulation";
    const wstring kSocialAttributeManipulationAbbreviation = L"Man.";
    const int kSocialAttributeAppearanceId = 3;
    const wstring kSocialAttributeAppearanceLabel = L"Appearance";
    const wstring kSocialAttributeAppearanceAbbreviation = L"App.";
    const int kSocialAttributesCount = 3;
    const wstring kSocialAttributeLabels[] = {
        L"",
        kSocialAttributeCharismaLabel,
        kSocialAttributeManipulationLabel,
        kSocialAttributeAppearanceLabel,
    };
    const wstring kSocialAttributeAbbreviations[] = {
        L"",
        kSocialAttributeCharismaAbbreviation,
        kSocialAttributeManipulationAbbreviation,
        kSocialAttributeAppearanceAbbreviation,
    };

    const int kMentalAttributeIntelligenceId = 1;
    const wstring kMentalAttributeIntelligenceLabel = L"Intelligence";
    const wstring kMentalAttributeIntelligenceAbbreviation = L"Int.";
    const int kMentalAttributePerceptionId = 2;
    const wstring kMentalAttributePerceptionLabel = L"Perception";
    const wstring kMentalAttributePerceptionAbbreviation = L"Per.";
    const int kMentalAttributeWitsId = 3;
    const wstring kMentalAttributeWitsLabel = L"Wits";
    const wstring kMentalAttributeWitsAbbreviation = L"Wits";
    const int kMentalAttributesCount = 3;
    const wstring kMentalAttributeLabels[] = {
        L"",
        kMentalAttributeIntelligenceLabel,
        kMentalAttributePerceptionLabel,
        kMentalAttributeWitsLabel,
    };
    const wstring kMentalAttributeAbbreviations[] = {
        L"",
        kMentalAttributeIntelligenceLabel,
        kMentalAttributePerceptionAbbreviation,
        kMentalAttributeWitsAbbreviation,
    };

    const int kAttributeGroupPhysicalId = 1;
    const wstring kAttributeGroupPhysicalLabel = L"Physical";
    const int kAttributeGroupSocialId = 2;
    const wstring kAttributeGroupSocialLabel = L"Social";
    const int kAttributeGroupMentalId = 3;
    const wstring kAttributeGroupMentalLabel = L"Mental";
    const int kAttributeGroupsCount = 3;
    const wstring kAttributeGroups[] = {
        L"",
        kAttributeGroupPhysicalLabel,
        kAttributeGroupSocialLabel,
        kAttributeGroupMentalLabel,
    };

    const int kAbilityGroupTalentsId = 1;
    const wstring kAbilityGroupTalentsSingular = L"Talent";
    const wstring kAbilityGroupTalentsPlural = L"Talents";
    const int kAbilityGroupSkillsId = 2;
    const wstring kAbilityGroupSkillsSingular = L"Skill";
    const wstring kAbilityGroupSkillsPlural = L"Skills";
    const int kAbilityGroupKnowledgesId = 3;
    const wstring kAbilityGroupKnowledgesSingular = L"Skill";
    const wstring kAbilityGroupKnowledgesPlural = L"Skills";
    const int kAbilityGroupsCount = 3;
    struct AbilityType {
        int id;
        wstring singular;
        wstring plural;
    };
    const AbilityType kAbilityGroups[] {
        {0, L"", L""},
        {kAbilityGroupTalentsId, kAbilityGroupTalentsSingular, kAbilityGroupTalentsPlural},
        {kAbilityGroupSkillsId, kAbilityGroupSkillsSingular, kAbilityGroupSkillsPlural},
        {kAbilityGroupKnowledgesId, kAbilityGroupKnowledgesSingular, kAbilityGroupKnowledgesPlural},
    };

    const int kTalentActingId = 1;
    const wstring kTalentActingLabel = L"Acting";
    const int kTalentAlertnessId = 2;
    const wstring kTalentAlertnessLabel = L"Alertness";
    const int kTalentAthleticsId = 3;
    const wstring kTalentAthleticsLabel = L"Athletics";
    const int kTalentBrawlId = 4;
    const wstring kTalentBrawlLabel = L"Brawl";
    const int kTalentDodgeId = 5;
    const wstring kTalentDodgeLabel = L"Dodge";
    const int kTalentEmpathyId = 6;
    const wstring kTalentEmpathyLabel = L"Empathty";
    const int kTalentIntimidationId = 7;
    const wstring kTalentIntimidationLabel = L"Intimidation";
    const int kTalentLeadershipId = 8;
    const wstring kTalentLeadershipLabel = L"Leadership";
    const int kTalentStreetwiseId = 9;
    const wstring kTalentStreetwiseLabel = L"Streetwise";
    const int kTalentSubterfugeId = 10;
    const wstring kTalentSubterfugeLabel = L"Subterfuge";
    const int kTalentsCount = 10;
    const wstring kTalents[] = {
        L"",
        kTalentActingLabel,
        kTalentAlertnessLabel,
        kTalentAthleticsLabel,
        kTalentBrawlLabel,
        kTalentDodgeLabel,
        kTalentEmpathyLabel,
        kTalentIntimidationLabel,
        kTalentLeadershipLabel,
        kTalentStreetwiseLabel,
        kTalentSubterfugeLabel,
    };

    const int kSkillAnimalKenId = 1;
    const wstring kSkillAnimalKenLabel = L"AnimalKen";
    const int kSkillDriveId = 2;
    const wstring kSkillDriveLabel = L"Drive";
    const int kSkillEtiquetteId = 3;
    const wstring kSkillEtiquetteLabel = L"Etiquette";
    const int kSkillFirearmsId = 4;
    const wstring kSkillFirearmsLabel = L"Firearms";
    const int kSkillMeleeId = 5;
    const wstring kSkillMeleeLabel = L"Melee";
    const int kSkillMusicId = 6;
    const wstring kSkillMusicLabel = L"Music";
    const int kSkillRepairId = 7;
    const wstring kSkillRepairLabel = L"Repair";
    const int kSkillSecurityId = 8;
    const wstring kSkillSecurityLabel = L"Security";
    const int kSkillStealthId = 9;
    const wstring kSkillStealthLabel = L"Stealth";
    const int kSkillSurvivalId = 10;
    const wstring kSkillSurvivalLabel = L"Survival";
    const int kSkillsCount = 10;
    const wstring kSkills[] = {
        L"",
        kSkillAnimalKenLabel,
        kSkillDriveLabel,
        kSkillEtiquetteLabel,
        kSkillFirearmsLabel,
        kSkillMeleeLabel,
        kSkillMusicLabel,
        kSkillRepairLabel,
        kSkillSecurityLabel,
        kSkillStealthLabel,
        kSkillSurvivalLabel,
    };

    const int kKnowledgeBureaucracyId = 1;
    const wstring kKnowledgeBureaucracyLabel = L"Bureaucracy";
    const int kKnowledgeComputerId = 2;
    const wstring kKnowledgeComputerLabel = L"Computer";
    const int kKnowledgeFinanceId = 3;
    const wstring kKnowledgeFinanceLabel = L"Finance";
    const int kKnowledgeInvestigationId = 4;
    const wstring kKnowledgeInvestigationLabel = L"Investigation";
    const int kKnowledgeLawId = 5;
    const wstring kKnowledgeLawLabel = L"Law";
    const int kKnowledgeLinguisticsId = 6;
    const wstring kKnowledgeLinguisticsLabel = L"Linguistics";
    const int kKnowledgeMedicineId = 7;
    const wstring kKnowledgeMedicineLabel = L"Medicine";
    const int kKnowledgeOccultId = 8;
    const wstring kKnowledgeOccultLabel = L"Occult";
    const int kKnowledgePoliticsId = 9;
    const wstring kKnowledgePoliticsLabel = L"Politics";
    const int kKnowledgeScienceId = 10;
    const wstring kKnowledgeScienceLabel = L"Science";
    const int kKnowledgesCount = 10;
    const wstring kKnowledges[] = {
        L"",
        kKnowledgeBureaucracyLabel,
        kKnowledgeComputerLabel,
        kKnowledgeFinanceLabel,
        kKnowledgeInvestigationLabel,
        kKnowledgeLawLabel,
        kKnowledgeLinguisticsLabel,
        kKnowledgeMedicineLabel,
        kKnowledgeOccultLabel,
        kKnowledgePoliticsLabel,
        kKnowledgeScienceLabel,
    };

    const int kBackgroundPoints = 5;
    const int kBackgroundAlliesId = 1;
    const wstring kBackgroundAlliesLabel = L"Allies";
    const int kBackgroundContactsId = 2;
    const wstring kBackgroundContactsLabel = L"Contacts";
    const int kBackgroundFameId = 3;
    const wstring kBackgroundFameLabel = L"Fame";
    const int kBackgroundGenerationId = 4;
    const wstring kBackgroundGenerationLabel = L"Generation";
    const int kBackgroundHerdId = 5;
    const wstring kBackgroundHerdLabel = L"Herd";
    const int kBackgroundInfluenceId = 6;
    const wstring kBackgroundInfluenceLabel = L"Influence";
    const int kBackgroundMentorId = 7;
    const wstring kBackgroundMentorLabel = L"Mentor";
    const int kBackgroundResourcesId = 8;
    const wstring kBackgroundResourcesLabel = L"Resources";
    const int kBackgroundRetainersId = 9;
    const wstring kBackgroundRetainersLabel = L"Retainers";
    const int kBackgroundStatusId = 10;
    const wstring kBackgroundStatusLabel = L"Status";
    const int kBackgroundsCount = 10;
    const wstring kBackgroundLabels[] = {
        L"",
        kBackgroundAlliesLabel,
        kBackgroundContactsLabel,
        kBackgroundFameLabel,
        kBackgroundGenerationLabel,
        kBackgroundHerdLabel,
        kBackgroundInfluenceLabel,
        kBackgroundMentorLabel,
        kBackgroundResourcesLabel,
        kBackgroundRetainersLabel,
        kBackgroundStatusLabel,
    };

    const int kGenderMaleId = 1;
    const wstring kGenderMaleLabel = L"Male";
    const int kGenderFemaleId = 2;
    const wstring kGenderFemaleLabel = L"Female";
    const int kGenderTransMaleId = 3;
    const wstring kGenderTransMaleLabel = L"Trans-Male";
    const int kGenderTransFemaleId = 4;
    const wstring kGenderTransFemaleLabel = L"Trans-Female";
    const int kGenderNonBinaryId = 5;
    const wstring kGenderNonBinaryLabel = L"Non-Binary";
    const int kGendersCount = 5;
    const wstring kGenderLabels[] = {
        L"",
        kGenderMaleLabel,
        kGenderFemaleLabel,
        kGenderTransMaleLabel,
        kGenderTransFemaleLabel,
        kGenderNonBinaryLabel,
    };

    struct DerangementType {
        int id;
        wstring label;
        wstring description;
        uint8_t textColor;
    };

    const int kDerangementAmnesiaId = 1;
    const uint8_t kDerangementAmnesiaTextColor= kColorDarkRed;
    const wstring kDerangementAmnesiaLabel = L"Amnesia";
    const wstring kDerangementAmnesiaDescription = LR"---(You forget a segment of your past. Additionally in some cases a character can forget abilities and be unable to use them for the duration.)---";
    const int kDerangementDelusionsOfGrandeurId = 2;
    const uint8_t kDerangementDelusionsOfGrandeurTextColor= kColorDarkMagenta;
    const wstring kDerangementDelusionsOfGrandeurLabel = L"Delusions of Grandeur";
    const wstring kDerangementDelusionsOfGrandeurDescription = LR"---(You imagine you are better than you are.)---";
    const int kDerangementFantasyId = 3;
    const uint8_t kDerangementFantasyTextColor= kColorDarkOrange;
    const wstring kDerangementFantasyLabel = L"Fantasy";
    const wstring kDerangementFantasyDescription = LR"---(You enter a self-created world where you are the forgotten hero.)---";
    const int kDerangementManicDepressionId = 4;
    const uint8_t kDerangementManicDepressionTextColor= kColorDarkWhite;
    const wstring kDerangementManicDepressionLabel = L"Manic-Depression";
    const wstring kDerangementManicDepressionDescription = LR"---(You sink into deep and fitful depressions, showing no interest in anything which used to captivate your interests. You will go along with others rather than use the energy to resist. Occasional fits of great energy grab hold of you, and you will work for hours or even days on your projects. During this time you will resist even the need for sleep as you burn up blood and Willpower on your schemes.)---";
    const int kDerangementMultiplePersonalitiesId = 5;
    const uint8_t kDerangementMultiplePersonalitiesTextColor= kColorDarkBlue;
    const wstring kDerangementMultiplePersonalitiesLabel = L"Multiple Personalities";
    const wstring kDerangementMultiplePersonalitiesDescription = LR"---(You possess a number of new personalities. You have amore than one Mature, and will switch between them. Thus you regain Willpower points in defferent ways at defferent times)---";
    const int kDerangementObsessionId = 6;
    const uint8_t kDerangementObsessionTextColor= kColorBrightGreen;
    const wstring kDerangementObsessionLabel = L"Obsession";
    const wstring kDerangementObsessionDescription = LR"---(You become obsessed with some interest or fetish.)---";
    const int kDerangementOvercompensationId = 7;
    const uint8_t kDerangementOvercompensationTextColor= kColorBrightCyan;
    const wstring kDerangementOvercompensationLabel = L"Overcompensation";
    const wstring kDerangementOvercompensationDescription = LR"---(You make up for your moral weaknesses by playing up your strengths to an extreme. You don't think you can frenzy and won't stop it.)---";
    const int kDerangementParanoiaId = 8;
    const uint8_t kDerangementParanoiaTextColor= kColorBrightRed;
    const wstring kDerangementParanoiaLabel = L"Paranoia";
    const wstring kDerangementParanoiaDescription = LR"---(You are convinced that you are being hunted. You hold even your closest Friends under suspicion.)---";
    const int kDerangementPerfectionId = 9;
    const uint8_t kDerangementPerfectionTextColor= kColorBrightMagenta;
    const wstring kDerangementPerfectionLabel = L"Perfection";
    const wstring kDerangementPerfectionDescription = LR"---(All your energy is directed toward preventing anything from going wong. When it does you must make a self-control roll or frenzy.)---";
    const int kDerangementRegressionId = 10;
    const uint8_t kDerangementRegressionTextColor= kColorBrightYellow;
    const wstring kDerangementRegressionLabel = L"Regression";
    const wstring kDerangementRegressionDescription = LR"---(You become childlike retreating to an earlier time when less was expected of you Willpower is regained inthe way a Child's is.)---";
    const DerangementType kDerangementAmnesia = {
        kDerangementAmnesiaId,
        kDerangementAmnesiaLabel,
        kDerangementAmnesiaDescription,
        kDerangementAmnesiaTextColor,
    };
    const DerangementType kDerangementDelusionsOfGrandeur = {
        kDerangementDelusionsOfGrandeurId,
        kDerangementDelusionsOfGrandeurLabel,
        kDerangementDelusionsOfGrandeurDescription,
        kDerangementDelusionsOfGrandeurTextColor,
    };
    const DerangementType kDerangementFantasy = {
        kDerangementFantasyId,
        kDerangementFantasyLabel,
        kDerangementFantasyDescription,
        kDerangementFantasyTextColor,
    };
    const DerangementType kDerangementManicDepression = {
        kDerangementManicDepressionId,
        kDerangementManicDepressionLabel,
        kDerangementManicDepressionDescription,
        kDerangementManicDepressionTextColor,
    };
    const DerangementType kDerangementMultiplePersonalities = {
        kDerangementMultiplePersonalitiesId,
        kDerangementMultiplePersonalitiesLabel,
        kDerangementMultiplePersonalitiesDescription,
        kDerangementMultiplePersonalitiesTextColor,
    };
    const DerangementType kDerangementObsession = {
        kDerangementObsessionId,
        kDerangementObsessionLabel,
        kDerangementObsessionDescription,
        kDerangementObsessionTextColor,
    };
    const DerangementType kDerangementOvercompensation = {
        kDerangementOvercompensationId,
        kDerangementOvercompensationLabel,
        kDerangementOvercompensationDescription,
        kDerangementOvercompensationTextColor,
    };
    const DerangementType kDerangementParanoia = {
        kDerangementParanoiaId,
        kDerangementParanoiaLabel,
        kDerangementParanoiaDescription,
        kDerangementParanoiaTextColor,
    };
    const DerangementType kDerangementPerfection = {
        kDerangementPerfectionId,
        kDerangementPerfectionLabel,
        kDerangementPerfectionDescription,
        kDerangementPerfectionTextColor,
    };
    const DerangementType kDerangementRegression = {
        kDerangementRegressionId,
        kDerangementRegressionLabel,
        kDerangementRegressionDescription,
        kDerangementRegressionTextColor,
    };
    const int kDerangementsCount = 10;

    const uint8_t kDerangementTextColors[] = {
        0,
        kDerangementAmnesiaTextColor,
        kDerangementDelusionsOfGrandeurTextColor,
        kDerangementFantasyTextColor,
        kDerangementManicDepressionTextColor,
        kDerangementMultiplePersonalitiesTextColor,
        kDerangementObsessionTextColor,
        kDerangementOvercompensationTextColor,
        kDerangementParanoiaTextColor,
        kDerangementPerfectionTextColor,
        kDerangementRegressionTextColor,
    };

    const wstring kDerangementLabels[] = {
        L"",
        kDerangementAmnesiaLabel,
        kDerangementDelusionsOfGrandeurLabel,
        kDerangementFantasyLabel,
        kDerangementManicDepressionLabel,
        kDerangementMultiplePersonalitiesLabel,
        kDerangementObsessionLabel,
        kDerangementOvercompensationLabel,
        kDerangementParanoiaLabel,
        kDerangementPerfectionLabel,
        kDerangementRegressionLabel,
    };

    const wstring kDerangementDescriptions[] = {
        L"",
        kDerangementAmnesiaDescription,
        kDerangementDelusionsOfGrandeurDescription,
        kDerangementFantasyDescription,
        kDerangementManicDepressionDescription,
        kDerangementMultiplePersonalitiesDescription,
        kDerangementObsessionDescription,
        kDerangementOvercompensationDescription,
        kDerangementParanoiaDescription,
        kDerangementPerfectionDescription,
        kDerangementRegressionDescription,
    };

    const DerangementType kDerangements[] = {
        {0, L"", L"", 0},
        kDerangementAmnesia,
        kDerangementDelusionsOfGrandeur,
        kDerangementFantasy,
        kDerangementManicDepression,
        kDerangementMultiplePersonalities,
        kDerangementObsession,
        kDerangementOvercompensation,
        kDerangementParanoia,
        kDerangementPerfection,
        kDerangementRegression,
    };

    int GetDisciplinePoints();
    int GetNumItemsForAbilityGroup(int abilityGroupId);

    class CharacterType {
        public:
            CharacterType();
            void FillAbilityValues(std::vector<int>abilityValues, int abilityGroupId) const;
            void FillAttributeValues(std::vector<int> attributeValues, int groupId) const;
            void FillBackgroundValues(std::vector<int> backgroundValues) const;
            void FillDisciplineValues(std::vector<int> disciplineValues) const;
            void FillDerangements(std::vector<DerangementType> derangements) const;
            void FillVirtueValues(std::vector<int> virtueValues) const;
            int GetAbilityValue(int abilityGroupId, int abilityId) const;
            int GetAttributeValue(int attributeGroupId, int abilityId) const;
            int GetBackgroundValue(int backgroundId) const;
            wstring GetAllDerangementsLine() const;
            int GetDisciplineValue(int disciplineId) const;
            int GetKnowledgeValue(int knowledgeId) const;
            int GetSkillValue(int skillId) const;
            int GetTalentValue(int talentId) const;
            int GetVirtueValue(int virtueId) const;
            void SetAbilityValue(int abilityGroupId, int abilityId, int value);
            void SetAttributeValue(int attributeGroupId, int attributeId, int value);
            void SetBackgroundValue(int backgroundId, int value);
            void SetDisciplineValue(int disciplineId, int value);
            void SetKnowledgeValue(int knowledgeId, int value);
            void SetSkillValue(int skillId, int value);
            void SetTalentValue(int talentId, int value);
            void SetVirtueValue(int virtueId, int value);
            
            wstring name;
            wstring player;
            wstring chronicle;
            wstring haven;
            wstring concept;
            wstring age;
            int genderId;
            int clanId;
            int natureId;
            int demeanorId;
            int conscience;
            int selfControl;
            int courage;
            int generation;
            wstring roadName;
            int roadValue;
            int willpower;
            int bloodPool;
            int derangementId;

        private:
            // Disciplines
            int discipline_animalism;
            int discipline_auspex;
            int discipline_bardo;
            int discipline_celerity;
            int discipline_chimestry;
            int discipline_dementation;
            int discipline_dominate;
            int discipline_fortitude;
            int discipline_melpominee;
            int discipline_mortis;
            int discipline_mytherceria;
            int discipline_necromancy;
            int discipline_obeah;
            int discipline_obfuscate;
            int discipline_obtenebration;
            int discipline_potence;
            int discipline_presence;
            int discipline_protean;
            int discipline_quietus;
            int discipline_serpentis;
            int discipline_spiritus;
            int discipline_thanantosis;
            int discipline_thaumaturgy;
            int discipline_vicissitude;

            // Attributes
            int attr_strength;
            int attr_dexterity;
            int attr_stamina;
            int attr_appearance;
            int attr_charisma;
            int attr_manipulation;
            int attr_intelligence;
            int attr_perception;
            int attr_wits;

            // Talents
            int talent_acting;
            int talent_alertness;
            int talent_athletics;
            int talent_brawl;
            int talent_dodge;
            int talent_empathy;
            int talent_intimidation;
            int talent_leadership;
            int talent_streetwise;
            int talent_subterfuge;

            // Skills
            int skill_animalKen;
            int skill_drive;
            int skill_etiquette;
            int skill_firearms;
            int skill_melee;
            int skill_music;
            int skill_repair;
            int skill_security;
            int skill_stealth;
            int skill_survival;

            // Knowledges
            int knowledge_bureaucracy;
            int knowledge_computer;
            int knowledge_finance;
            int knowledge_investigation;
            int knowledge_law;
            int knowledge_linguistics;
            int knowledge_medicine;
            int knowledge_occult;
            int knowledge_politics;
            int knowledge_science;

            // Backgrounds
            int background_allies;
            int background_contacts;
            int background_fame;
            int background_generation;
            int background_herd;
            int background_influence;
            int background_mentor;
            int background_resources;
            int background_retainers;
            int background_status;
    };

    int GetVirtuePoints();

} // End namespace SBF

#endif // !defined CHARACTER_H__
