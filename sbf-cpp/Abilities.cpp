#include "Abilities.h"
#include <string>

namespace SBF {
    using std::wstring;

    const wstring& GetAbilityLabel(int abilityGroupId, int abilityId) {
        switch (abilityGroupId) {
            case kAbilityTalentsId:
                return kTalents[abilityId];
            case kAbilitySkillsId:
                return kSkills[abilityId];
            case kAbilityKnowledgesId:
                return kKnowledges[abilityId];
        }
        return L"";
    }
} // End namespace SBF
