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
    const std::string kVirtueUnknownLabel = "";
    const int kVirtueSelfControlId = 1;
    const std::string kVirtueSelfControlLabel = "Self-Control";
    const int kVirtueCourageId = 2;
    const std::string kVirtueCourageLabel = "Courage";
    const int kVirtueConscienceId = 3;
    const std::string kVirtueConscienceLabel = "Conscience";
    const int kVirtuesCount = 3;
    const std::string kVirtueLabels[] = {
        kVirtueUnknownLabel,
        kVirtueSelfControlLabel,
        kVirtueCourageLabel,
        kVirtueConscienceLabel,
    };
    
    /// @brief Gets the label for virtue with the specified id.
    /// @param virtue_id The id of the virtue to find.
    /// @return The label for the specified virtue or an empty string if virtue_id is invalid.
    const std::string GetVirtueLabel(int virtue_id);

    /// @brief Fills the vector with all of the valid virtue labels.
    /// @param virtue_labels The vector to fill. It will be cleared first.
    void FillVirtueLabels(std::vector<std::string>& virtue_labels);
} // End namespace SBF
/** @}*/
#endif // End !defined VIRTUES_H__
