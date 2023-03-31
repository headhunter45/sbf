#ifndef DISCIPLINES_H__
#define DISCIPLINES_H__
#include <string>
#include <vector>

namespace SBF {
    const int kDisciplinePoints = 3;
    const int kDisciplineAnimalismId = 1;
    const std::wstring kDisciplineAnimalismLabel = L"Animalism";
    const int kDisciplineAuspexId = 2;
    const std::wstring kDisciplineAuspexLabel = L"Auspex";
    const int kDisciplineBardoId = 3;
    const std::wstring kDisciplineBardoLabel = L"Bardo";
    const int kDisciplineCelerityId = 4;
    const std::wstring kDisciplineCelerityLabel = L"Celerity";
    const int kDisciplineChimestryId = 5;
    const std::wstring kDisciplineChimestryLabel = L"Chimestry";
    const int kDisciplineDementationId = 6;
    const std::wstring kDisciplineDementationLabel = L"Dementation";
    const int kDisciplineDominateId = 7;
    const std::wstring kDisciplineDominateLabel = L"Dominate";
    const int kDisciplineFortitudeId = 8;
    const std::wstring kDisciplineFortitudeLabel = L"Fortitude";
    const int kDisciplineMelpomineeId = 9;
    const std::wstring kDisciplineMelpomineeLabel = L"Melpominee";
    const int kDisciplineMortisId = 10;
    const std::wstring kDisciplineMortisLabel = L"Mortis";
    const int kDisciplineMytherceriaId = 11;
    const std::wstring kDisciplineMytherceriaLabel = L"Mytherceria";
    const int kDisciplineNecromancyId = 12;
    const std::wstring kDisciplineNecromancyLabel = L"Necromancy";
    const int kDisciplineObeahId = 13;
    const std::wstring kDisciplineObeahLabel = L"Obeah";
    const int kDisciplineObfuscateId = 14;
    const std::wstring kDisciplineObfuscateLabel = L"Obfuscate";
    const int kDisciplineObtenebrationId = 15;
    const std::wstring kDisciplineObtenebrationLabel = L"Obtenebration";
    const int kDisciplinePotenceId = 16;
    const std::wstring kDisciplinePotenceLabel = L"Potence";
    const int kDisciplinePresenceId = 17;
    const std::wstring kDisciplinePresenceLabel = L"Presence";
    const int kDisciplineProteanId = 18;
    const std::wstring kDisciplineProteanLabel = L"Protean";
    const int kDisciplineQuietusId = 19;
    const std::wstring kDisciplineQuietusLabel = L"Quietus";
    const int kDisciplineSerpentisId = 20;
    const std::wstring kDisciplineSerpentisLabel = L"Serpentis";
    const int kDisciplineSpiritusId = 21;
    const std::wstring kDisciplineSpiritusLabel = L"Spiritus";
    const int kDisciplineThanantosisId = 22;
    const std::wstring kDisciplineThanantosisLabel = L"Thanantosis";
    const int kDisciplineThaumaturgyId = 23;
    const std::wstring kDisciplineThaumaturgyLabel = L"Thaumaturgy";
    const int kDisciplineVicissitudeId = 24;
    const std::wstring kDisciplineVicissitudeLabel = L"Vicissitude";
    const int kDisciplinesCount = 24;
    const std::wstring kDisciplines[] = {
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
    const std::wstring GetDisciplineLabel(int disciplineId);
    void FillDisciplineLabels(std::vector<std::wstring> disciplineLabels);
} // End namespace SBF
#endif // End !defined DISCIPLINES_H__
