#include "Abilities.h"
#include <string>
#include <iostream>

namespace SBF {
    using std::string;
    using std::ostream;
    using std::vector;

    ostream& operator<<(ostream& os, const AbilityType& abilityGroup) {
        os << "AbilityGroup: {id: " << abilityGroup.id 
           << ", singular: \"" << abilityGroup.singular 
           << "\", plural: \"" << abilityGroup.plural << "\"}";
        return os;
    }

    bool operator==(const AbilityType& left, const AbilityType& right) {
        return left.id == right.id &&
               left.singular == right.singular &&
               left.plural == right.plural;
    }

    bool operator!=(const AbilityType& left, const AbilityType& right) {
        return !(left == right);
    }

    void FillAbilities(vector<AbilityType>& abilities) {
        abilities.clear();
        abilities.push_back(kAbilityGroupTalents);
        abilities.push_back(kAbilityGroupSkills);
        abilities.push_back(kAbilityGroupKnowledges);
    }

    void FillAbilitiesForAbilityGroup(vector<string>& abilities, int abilityGroupId) {
        abilities.clear();
        int numAbilities = GetNumItemsForAbilityGroup(abilityGroupId);
        switch (abilityGroupId) {
            case kAbilityTalentsId:
                for (int talentId = 0; talentId <= numAbilities; talentId++) {
                    if (talentId >= 0 && talentId <= kTalentsCount) {
                        abilities.push_back(kTalents[talentId]);
                    }
                }
                break;
            case kAbilitySkillsId:
                for (int skillId = 0; skillId <= numAbilities; skillId++) {
                    if (skillId >= 0 && skillId <= kSkillsCount) {
                        abilities.push_back(kSkills[skillId]);
                    }
                }
                break;
            case kAbilityKnowledgesId:
                for (int knowledgeId = 0; knowledgeId <= numAbilities; knowledgeId++) {
                    if (knowledgeId >= 0 && knowledgeId <= kKnowledgesCount) {
                        abilities.push_back(kKnowledges[knowledgeId]);
                    }
                }
                break;
        }
    }

    void FillAbilityLabels(vector<string>& labels, int abilityGroupId) {
        labels.clear();
        switch (abilityGroupId) {
            case kAbilityTalentsId:
                FillTalentLabels(labels);
                break;
            case kAbilitySkillsId:
                FillSkillLabels(labels);
                break;
            case kAbilityKnowledgesId:
                FillKnowledgeLabels(labels);
                break;
        }
    }

    void FillKnowledgeLabels(vector<string>& labels) {
        labels.clear();
        int numAbilities = GetNumItemsForAbilityGroup(kAbilityKnowledgesId);
        for (int knowledgeId = 0; knowledgeId <= numAbilities; knowledgeId++) {
            if (knowledgeId >= 0 && knowledgeId <= kKnowledgesCount) {
                labels.push_back(kKnowledges[knowledgeId]);
            }
        }
    }

    void FillSkillLabels(vector<string>& labels) {
        labels.clear();
        int numAbilities = GetNumItemsForAbilityGroup(kAbilitySkillsId);
        for (int skillId = 0; skillId <= numAbilities; skillId++) {
            if (skillId >= 0 && skillId <= kSkillsCount) {
                labels.push_back(kSkills[skillId]);
            }
        }
    }
    
    void FillTalentLabels(vector<string>& labels) {
        labels.clear();
        int numAbilities = GetNumItemsForAbilityGroup(kAbilityTalentsId);
        for (int talentId = 0; talentId <= numAbilities; talentId++) {
            if (talentId >= 0 && talentId <= kTalentsCount) {
                labels.push_back(kTalents[talentId]);
            }
        }
    }

    const AbilityType& GetAbility(int abilityGroupId) {
        switch(abilityGroupId) {
            case kAbilityTalentsId:
                return kAbilityGroupTalents;
            case kAbilitySkillsId:
                return kAbilityGroupSkills;
            case kAbilityKnowledgesId:
                return kAbilityGroupKnowledges;
        };
        return kAbilityGroupUnknown;
    }

    const string GetAbilityLabel(int abilityGroupId, int abilityId) {
        switch (abilityGroupId) {
            case kAbilityTalentsId:
                return GetTalentLabel(abilityId);
            case kAbilitySkillsId:
                return GetSkillLabel(abilityId);
            case kAbilityKnowledgesId:
                return GetKnowledgeLabel(abilityId);
        };
        return "";
    }

    const std::string GetKnowledgeLabel(int talentId){
        if (talentId > 0 && talentId <= kKnowledgesCount) {
            return kKnowledges[talentId];    
        }
        return "";
    }

    int GetNumItemsForAbilityGroup(int abilityGroupId) {
        switch (abilityGroupId) {
            case kAbilityTalentsId:
                return kTalentsCount;
            case kAbilitySkillsId:
                return kSkillsCount;
            case kAbilityKnowledgesId:
                return kKnowledgesCount;
        }
        return 0;
    }
    
    const std::string GetSkillLabel(int skillId) {
        if (skillId > 0 && skillId <= kSkillsCount) {
            return kSkills[skillId];
        }
        return "";
    }

    const std::string GetTalentLabel(int talentId) {
        if (talentId > 0 && talentId <= kTalentsCount) {
            return kTalents[talentId];
        }
        return "";
    }
    
} // End namespace SBF
