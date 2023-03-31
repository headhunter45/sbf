#ifndef ARCHETYPES_H__
#define ARCHETYPES_H__
#include <string>
#include <vector>

namespace SBF {
    const int kArchetypeArchitectId = 1;
    const std::wstring kArchetypeArchitectLabel = L"Architect";
    const int kArchetypeAutocratId = 2;
    const std::wstring kArchetypeAutocratLabel = L"Autocrat";
    const int kArchetypeBarbarianId = 3;
    const std::wstring kArchetypeBarbarianLabel = L"Barbarian";
    const int kArchetypeBonVivantId = 4;
    const std::wstring kArchetypeBonVivantLabel = L"Bon Vivant";
    const int kArchetypeBravoId = 5;
    const std::wstring kArchetypeBravoLabel = L"Bravo";
    const int kArchetypeCaregiverId = 6;
    const std::wstring kArchetypeCaregiverLabel = L"Caregiver";
    const int kArchetypeCaretakerId = 7;
    const std::wstring kArchetypeCaretakerLabel = L"Caretaker";
    const int kArchetypeCelebrantId = 8;
    const std::wstring kArchetypeCelebrantLabel = L"Celebrant";
    const int kArchetypeChildId = 9;
    const std::wstring kArchetypeChildLabel = L"Child";
    const int kArchetypeConformist = 10;
    const std::wstring kArchetypeConformistLabel = L"Conformist";
    const int kArchetypeConniverId = 11;
    const std::wstring kArchetypeConniverLabel = L"Conniver";
    const int kArchetypeCurmudgeonId = 12;
    const std::wstring kArchetypeCurmudgeonLabel = L"Curmudgeon";
    const int kArchetypeDefenderId = 13;
    const std::wstring kArchetypeDefenderLabel = L"Defender";
    const int kArchetypeDeviantId = 14;
    const std::wstring kArchetypeDeviantLabel = L"Deviant";
    const int kArchetypeDirectorId = 15;
    const std::wstring kArchetypeDirectorLabel = L"Director";
    const int kArchetypeFanaticId = 16;
    const std::wstring kArchetypeFanaticLabel = L"Fanatic";
    const int kArchetypeGallantId = 17;
    const std::wstring kArchetypeGallantLabel = L"Gallant";
    const int kArchetypeInnovatorId = 18;
    const std::wstring kArchetypeInnovatorLabel = L"Innovator";
    const int kArchetypeJesterId = 19;
    const std::wstring kArchetypeJesterLabel = L"Jester";
    const int kArchetypeJudgeId = 20;
    const std::wstring kArchetypeJudgeLabel = L"Judge";
    const int kArchetypeLoanerId = 21;
    const std::wstring kArchetypeLoanerLabel = L"Loaner";
    const int kArchetypeMartyrId = 22;
    const std::wstring kArchetypeMartyrLabel = L"Martyr";
    const int kArchetypeMonsterId = 23;
    const std::wstring kArchetypeMonsterLabel = L"Monster";
    const int kArchetypePenitentId = 24;
    const std::wstring kArchetypePenitentLabel = L"Penitent";
    const int kArchetypeRebelId = 25;
    const std::wstring kArchetypeRebelLabel = L"Rebel";
    const int kArchetypeRogueId = 26;
    const std::wstring kArchetypeRogueLabel = L"Rogue";
    const int kArchetypeSurvivorId = 27;
    const std::wstring kArchetypeSurvivorLabel = L"Survivor";
    const int kArchetypeTraditionalistId = 28;
    const std::wstring kArchetypeTraditionalistLabel = L"Traditionalist";
    const int kArchetypeTyrantId = 29;
    const std::wstring kArchetypeTyrantLabel = L"Tyrant";
    const int kArchetypeVisionaryId = 30;
    const std::wstring kArchetypeVisionaryLabel = L"Visionary";
    const int kArchetypesCount = 30;
    const std::wstring kArchetypes[] = {
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

    const std::wstring& GetArchetypeLabel(int archetypeId);
    void FillArchetypeLabels(std::vector<std::wstring> archetypeLabels);
} // End namespace SBF
#endif // End !defined ARCHETYPES_H__
