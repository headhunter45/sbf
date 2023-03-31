#ifndef DERANGEMENTS_H__
#define DERANGEMENTS_H__
#include "Colors.h"
#include <string>
#include <vector>

namespace SBF {
    struct DerangementType {
        int id;
        std::wstring label;
        std::wstring description;
        uint8_t textColor;
    };

    const int kDerangementAmnesiaId = 1;
    const uint8_t kDerangementAmnesiaTextColor= kColorDarkRed;
    const std::wstring kDerangementAmnesiaLabel = L"Amnesia";
    const std::wstring kDerangementAmnesiaDescription = LR"---(You forget a segment of your past. Additionally in some cases a character can forget abilities and be unable to use them for the duration.)---";
    const int kDerangementDelusionsOfGrandeurId = 2;
    const uint8_t kDerangementDelusionsOfGrandeurTextColor= kColorDarkMagenta;
    const std::wstring kDerangementDelusionsOfGrandeurLabel = L"Delusions of Grandeur";
    const std::wstring kDerangementDelusionsOfGrandeurDescription = LR"---(You imagine you are better than you are.)---";
    const int kDerangementFantasyId = 3;
    const uint8_t kDerangementFantasyTextColor= kColorDarkOrange;
    const std::wstring kDerangementFantasyLabel = L"Fantasy";
    const std::wstring kDerangementFantasyDescription = LR"---(You enter a self-created world where you are the forgotten hero.)---";
    const int kDerangementManicDepressionId = 4;
    const uint8_t kDerangementManicDepressionTextColor= kColorDarkWhite;
    const std::wstring kDerangementManicDepressionLabel = L"Manic-Depression";
    const std::wstring kDerangementManicDepressionDescription = LR"---(You sink into deep and fitful depressions, showing no interest in anything which used to captivate your interests. You will go along with others rather than use the energy to resist. Occasional fits of great energy grab hold of you, and you will work for hours or even days on your projects. During this time you will resist even the need for sleep as you burn up blood and Willpower on your schemes.)---";
    const int kDerangementMultiplePersonalitiesId = 5;
    const uint8_t kDerangementMultiplePersonalitiesTextColor= kColorDarkBlue;
    const std::wstring kDerangementMultiplePersonalitiesLabel = L"Multiple Personalities";
    const std::wstring kDerangementMultiplePersonalitiesDescription = LR"---(You possess a number of new personalities. You have amore than one Mature, and will switch between them. Thus you regain Willpower points in defferent ways at defferent times)---";
    const int kDerangementObsessionId = 6;
    const uint8_t kDerangementObsessionTextColor= kColorBrightGreen;
    const std::wstring kDerangementObsessionLabel = L"Obsession";
    const std::wstring kDerangementObsessionDescription = LR"---(You become obsessed with some interest or fetish.)---";
    const int kDerangementOvercompensationId = 7;
    const uint8_t kDerangementOvercompensationTextColor= kColorBrightCyan;
    const std::wstring kDerangementOvercompensationLabel = L"Overcompensation";
    const std::wstring kDerangementOvercompensationDescription = LR"---(You make up for your moral weaknesses by playing up your strengths to an extreme. You don't think you can frenzy and won't stop it.)---";
    const int kDerangementParanoiaId = 8;
    const uint8_t kDerangementParanoiaTextColor= kColorBrightRed;
    const std::wstring kDerangementParanoiaLabel = L"Paranoia";
    const std::wstring kDerangementParanoiaDescription = LR"---(You are convinced that you are being hunted. You hold even your closest Friends under suspicion.)---";
    const int kDerangementPerfectionId = 9;
    const uint8_t kDerangementPerfectionTextColor= kColorBrightMagenta;
    const std::wstring kDerangementPerfectionLabel = L"Perfection";
    const std::wstring kDerangementPerfectionDescription = LR"---(All your energy is directed toward preventing anything from going wong. When it does you must make a self-control roll or frenzy.)---";
    const int kDerangementRegressionId = 10;
    const uint8_t kDerangementRegressionTextColor= kColorBrightYellow;
    const std::wstring kDerangementRegressionLabel = L"Regression";
    const std::wstring kDerangementRegressionDescription = LR"---(You become childlike retreating to an earlier time when less was expected of you Willpower is regained inthe way a Child's is.)---";
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

    const std::wstring kDerangementLabels[] = {
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

    const std::wstring kDerangementDescriptions[] = {
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

    const DerangementType& GetDerangement(int derangementId);
    void FillDerangements(std::vector<DerangementType> derangements);
} // End namespace SBF
#endif // End !defined DERANGEMENTS_H__
