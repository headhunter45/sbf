#ifndef ARCHETYPES_H__
#define ARCHETYPES_H__
#include <string>
#include <vector>

namespace SBF {
    const int kArchetypeArchitectId = 1;
    const std::string kArchetypeArchitectLabel = "Architect";
    const int kArchetypeAutocratId = 2;
    const std::string kArchetypeAutocratLabel = "Autocrat";
    const int kArchetypeBarbarianId = 3;
    const std::string kArchetypeBarbarianLabel = "Barbarian";
    const int kArchetypeBonVivantId = 4;
    const std::string kArchetypeBonVivantLabel = "Bon Vivant";
    const int kArchetypeBravoId = 5;
    const std::string kArchetypeBravoLabel = "Bravo";
    const int kArchetypeCaregiverId = 6;
    const std::string kArchetypeCaregiverLabel = "Caregiver";
    const int kArchetypeCaretakerId = 7;
    const std::string kArchetypeCaretakerLabel = "Caretaker";
    const int kArchetypeCelebrantId = 8;
    const std::string kArchetypeCelebrantLabel = "Celebrant";
    const int kArchetypeChildId = 9;
    const std::string kArchetypeChildLabel = "Child";
    const int kArchetypeConformist = 10;
    const std::string kArchetypeConformistLabel = "Conformist";
    const int kArchetypeConniverId = 11;
    const std::string kArchetypeConniverLabel = "Conniver";
    const int kArchetypeCurmudgeonId = 12;
    const std::string kArchetypeCurmudgeonLabel = "Curmudgeon";
    const int kArchetypeDefenderId = 13;
    const std::string kArchetypeDefenderLabel = "Defender";
    const int kArchetypeDeviantId = 14;
    const std::string kArchetypeDeviantLabel = "Deviant";
    const int kArchetypeDirectorId = 15;
    const std::string kArchetypeDirectorLabel = "Director";
    const int kArchetypeFanaticId = 16;
    const std::string kArchetypeFanaticLabel = "Fanatic";
    const int kArchetypeGallantId = 17;
    const std::string kArchetypeGallantLabel = "Gallant";
    const int kArchetypeInnovatorId = 18;
    const std::string kArchetypeInnovatorLabel = "Innovator";
    const int kArchetypeJesterId = 19;
    const std::string kArchetypeJesterLabel = "Jester";
    const int kArchetypeJudgeId = 20;
    const std::string kArchetypeJudgeLabel = "Judge";
    const int kArchetypeLoanerId = 21;
    const std::string kArchetypeLoanerLabel = "Loaner";
    const int kArchetypeMartyrId = 22;
    const std::string kArchetypeMartyrLabel = "Martyr";
    const int kArchetypeMonsterId = 23;
    const std::string kArchetypeMonsterLabel = "Monster";
    const int kArchetypePenitentId = 24;
    const std::string kArchetypePenitentLabel = "Penitent";
    const int kArchetypeRebelId = 25;
    const std::string kArchetypeRebelLabel = "Rebel";
    const int kArchetypeRogueId = 26;
    const std::string kArchetypeRogueLabel = "Rogue";
    const int kArchetypeSurvivorId = 27;
    const std::string kArchetypeSurvivorLabel = "Survivor";
    const int kArchetypeTraditionalistId = 28;
    const std::string kArchetypeTraditionalistLabel = "Traditionalist";
    const int kArchetypeTyrantId = 29;
    const std::string kArchetypeTyrantLabel = "Tyrant";
    const int kArchetypeVisionaryId = 30;
    const std::string kArchetypeVisionaryLabel = "Visionary";
    const int kArchetypesCount = 30;
    const std::string kArchetypes[] = {
        "",
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

    const std::string& GetArchetypeLabel(int archetypeId);
    void FillArchetypeLabels(std::vector<std::string> archetypeLabels);
} // End namespace SBF
#endif // End !defined ARCHETYPES_H__
