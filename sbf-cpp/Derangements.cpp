#include "Derangements.h"

#include <ostream>

namespace SBF {
namespace {
using std::ostream;
using std::string;
using std::vector;
}  // End namespace

const uint8_t kDerangementAmnesiaTextColor = kColorDarkRed;
const std::string kDerangementAmnesiaLabel = "Amnesia";
const std::string kDerangementAmnesiaDescription =
    R"---(You forget a segment of your past. Additionally in some cases a character can forget abilities and be unable to use them for the duration.)---";
const uint8_t kDerangementDelusionsOfGrandeurTextColor = kColorDarkMagenta;
const std::string kDerangementDelusionsOfGrandeurLabel = "Delusions of Grandeur";
const std::string kDerangementDelusionsOfGrandeurDescription = R"---(You imagine you are better than you are.)---";
const uint8_t kDerangementFantasyTextColor = kColorDarkYellow;
const std::string kDerangementFantasyLabel = "Fantasy";
const std::string kDerangementFantasyDescription =
    R"---(You enter a self-created world where you are the forgotten hero.)---";
const uint8_t kDerangementManicDepressionTextColor = kColorDarkWhite;
const std::string kDerangementManicDepressionLabel = "Manic-Depression";
const std::string kDerangementManicDepressionDescription =
    R"---(You sink into deep and fitful depressions, showing no interest in anything which used to captivate your interests. You will go along with others rather than use the energy to resist. Occasional fits of great energy grab hold of you, and you will work for hours or even days on your projects. During this time you will resist even the need for sleep as you burn up blood and Willpower on your schemes.)---";
const uint8_t kDerangementMultiplePersonalitiesTextColor = kColorDarkBlue;
const std::string kDerangementMultiplePersonalitiesLabel = "Multiple Personalities";
const std::string kDerangementMultiplePersonalitiesDescription =
    R"---(You possess a number of new personalities. You have amore than one Mature, and will switch between them. Thus you regain Willpower points in defferent ways at defferent times)---";
const uint8_t kDerangementObsessionTextColor = kColorBrightGreen;
const std::string kDerangementObsessionLabel = "Obsession";
const std::string kDerangementObsessionDescription = R"---(You become obsessed with some interest or fetish.)---";
const uint8_t kDerangementOvercompensationTextColor = kColorBrightCyan;
const std::string kDerangementOvercompensationLabel = "Overcompensation";
const std::string kDerangementOvercompensationDescription =
    R"---(You make up for your moral weaknesses by playing up your strengths to an extreme. You don't think you can frenzy and won't stop it.)---";
const uint8_t kDerangementParanoiaTextColor = kColorBrightRed;
const std::string kDerangementParanoiaLabel = "Paranoia";
const std::string kDerangementParanoiaDescription =
    R"---(You are convinced that you are being hunted. You hold even your closest Friends under suspicion.)---";
const uint8_t kDerangementPerfectionTextColor = kColorBrightMagenta;
const std::string kDerangementPerfectionLabel = "Perfection";
const std::string kDerangementPerfectionDescription =
    R"---(All your energy is directed toward preventing anything from going wong. When it does you must make a self-control roll or frenzy.)---";
const uint8_t kDerangementRegressionTextColor = kColorBrightYellow;
const std::string kDerangementRegressionLabel = "Regression";
const std::string kDerangementRegressionDescription =
    R"---(You become childlike retreating to an earlier time when less was expected of you Willpower is regained inthe way a Child's is.)---";
const DerangementType kDerangementUnknown = {0, "", "", 0};
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

const std::string kDerangementLabels[] = {
    "",
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

const std::string kDerangementDescriptions[] = {
    "",
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
    {0, "", "", 0},
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

bool operator==(const DerangementType& left, const DerangementType& right) {
  return left.description == right.description && left.id == right.id && left.label == right.label
      && left.textColor == right.textColor;
}

bool operator!=(const DerangementType& left, const DerangementType& right) {
  return !(left == right);
}

ostream& operator<<(ostream& os, const DerangementType& derangement) {
  os << "Derangement: {id: " << derangement.id << ", label: \"" << derangement.label << "\", description: \""
     << derangement.description << "\", textColor: " << (int)derangement.textColor << "}";
  return os;
}

DerangementType GetDerangement(int derangementId) {
  if (derangementId > 0 && derangementId <= kDerangementsCount) {
    return kDerangements[derangementId];
  }
  return kDerangementUnknown;
}

void FillDerangements(vector<DerangementType>& derangements) {
  derangements.clear();
  for (int id = 1; id <= kDerangementsCount; id++) {
    derangements.push_back(GetDerangement(id));
  }
}

vector<string> GetDerangementLabels() {
  vector<string> labels;

  for (int id = 1; id <= kDerangementsCount; id++) {
    labels.push_back(kDerangementLabels[id]);
  }

  return labels;
}

vector<uint8_t> GetDerangementColors() {
  vector<uint8_t> colors;

  for (int id = 1; id <= kDerangementsCount; id++) {
    colors.push_back(kDerangementTextColors[id]);
  }

  return colors;
}
}  // End namespace SBF
