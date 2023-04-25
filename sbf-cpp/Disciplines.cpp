#include "Disciplines.h"

#include <string>
#include <vector>

namespace SBF {
using std::string;
using std::vector;

const std::string kDisciplineAnimalismLabel = "Animalism";
const std::string kDisciplineAuspexLabel = "Auspex";
const std::string kDisciplineBardoLabel = "Bardo";
const std::string kDisciplineCelerityLabel = "Celerity";
const std::string kDisciplineChimestryLabel = "Chimestry";
const std::string kDisciplineDementationLabel = "Dementation";
const std::string kDisciplineDominateLabel = "Dominate";
const std::string kDisciplineFortitudeLabel = "Fortitude";
const std::string kDisciplineMelpomineeLabel = "Melpominee";
const std::string kDisciplineMortisLabel = "Mortis";
const std::string kDisciplineMytherceriaLabel = "Mytherceria";
const std::string kDisciplineNecromancyLabel = "Necromancy";
const std::string kDisciplineObeahLabel = "Obeah";
const std::string kDisciplineObfuscateLabel = "Obfuscate";
const std::string kDisciplineObtenebrationLabel = "Obtenebration";
const std::string kDisciplinePotenceLabel = "Potence";
const std::string kDisciplinePresenceLabel = "Presence";
const std::string kDisciplineProteanLabel = "Protean";
const std::string kDisciplineQuietusLabel = "Quietus";
const std::string kDisciplineSerpentisLabel = "Serpentis";
const std::string kDisciplineSpiritusLabel = "Spiritus";
const std::string kDisciplineThanantosisLabel = "Thanantosis";
const std::string kDisciplineThaumaturgyLabel = "Thaumaturgy";
const std::string kDisciplineVicissitudeLabel = "Vicissitude";
const int kDisciplinesCount = 24;
const std::string kDisciplines[] = {
    "",
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

string GetDisciplineLabel(int disciplineId) {
  if (disciplineId > 0 && disciplineId <= kDisciplinesCount) {
    return kDisciplines[disciplineId];
  }

  return "";
}

void FillDisciplineLabels(vector<string>& labels) {
  labels.clear();
  for (int id = 1; id <= kDisciplinesCount; id++) {
    labels.push_back(GetDisciplineLabel(id));
  }
}

int GetNumDisciplines() {
  return kDisciplinesCount;
}
}  // End namespace SBF
