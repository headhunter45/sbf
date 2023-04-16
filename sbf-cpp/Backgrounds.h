#ifndef BACKGROUNDS_H__
#define BACKGROUNDS_H__
/***************************************************************************************
* @file Backgrounds.h
*
* @brief Defines constants and funcions for working with backgrounds.
* @copyright
* Copyright 2023 Tom Hicks
* Licensed under the MIT license see the LICENSE file for details.
***************************************************************************************/
#include <string>
#include <vector>

/** \addtogroup Backgrounds
 * @{
*/
namespace SBF {
    const int kBackgroundPoints = 5;
    const int kBackgroundAlliesId = 1;
    const std::string kBackgroundAlliesLabel = "Allies";
    const int kBackgroundContactsId = 2;
    const std::string kBackgroundContactsLabel = "Contacts";
    const int kBackgroundFameId = 3;
    const std::string kBackgroundFameLabel = "Fame";
    const int kBackgroundGenerationId = 4;
    const std::string kBackgroundGenerationLabel = "Generation";
    const int kBackgroundHerdId = 5;
    const std::string kBackgroundHerdLabel = "Herd";
    const int kBackgroundInfluenceId = 6;
    const std::string kBackgroundInfluenceLabel = "Influence";
    const int kBackgroundMentorId = 7;
    const std::string kBackgroundMentorLabel = "Mentor";
    const int kBackgroundResourcesId = 8;
    const std::string kBackgroundResourcesLabel = "Resources";
    const int kBackgroundRetainersId = 9;
    const std::string kBackgroundRetainersLabel = "Retainers";
    const int kBackgroundStatusId = 10;
    const std::string kBackgroundStatusLabel = "Status";
    const int kBackgroundsCount = 10;
    const std::string kBackgroundLabels[] = {
        "",
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
    std::string GetBackgroundLabel(int backgroundId);
    void FillBackgroundLabels(std::vector<std::string>& backgroundLabels);
} // End namespace SBF
/** @}*/
#endif // End !defined BACKGROUNDS_H__
