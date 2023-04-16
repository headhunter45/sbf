#ifndef VIRTUES_H__
#define VIRTUES_H__
/***************************************************************************************
* @file Virtues.h
*
* @brief Defines constants and functions for working with virtues.
* @copyright
* Copyright 2023 Tom Hicks
* Licensed under the MIT license see the LICENSE file for details.
***************************************************************************************/
#include <string>
#include <vector>

/** \addtogroup Virtues
 * @{
*/
namespace SBF {
    const int kVirtuePoints = 7;
    const int kVirtueSelfControlId = 1;
    const std::string kVirtueSelfControlLabel = "Self-Control";
    const int kVirtueCourageId = 2;
    const std::string kVirtueCourageLabel = "Courage";
    const int kVirtueConscienceId = 3;
    const std::string kVirtueConscienceLabel = "Conscience";
    const int kVirtuesCount = 3;
    const std::string kVirtues[] = {
        "",
        kVirtueSelfControlLabel,
        kVirtueCourageLabel,
        kVirtueConscienceLabel,
    };
    const std::string GetVirtueLabel(int virtueId);
    void FillVirtueLabels(std::vector<std::string> virtueLabels);
} // End namespace SBF
/** @}*/
#endif // End !defined VIRTUES_H__
