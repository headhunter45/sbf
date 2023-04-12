#include "Abilities.h"
#include <string>
#include <iostream>

namespace SBF {
    using std::wstring;


    // template<typename T>
    // T r(int a, int b) {
    //     auto s = [](int a, int b){return (T)nullptr;}
    //     auto t = wstring(L"asdf");
    //     return s(a,b);
    // }

    void testMe() {
        auto l = [](int a, int b){return;};
        l(1,2);
        // std::cout << "l: " << l(1,2) << std::endl;
        // auto q = r<void>(1, 2);
        // std::cout << "q: " << q(1,2) << std::endl;
    }
    const wstring GetAbilityLabel(int abilityGroupId, int abilityId) {
        switch (abilityGroupId) {
            case kAbilityTalentsId:
                return kTalents[abilityId];
            case kAbilitySkillsId:
                return kSkills[abilityId];
            case kAbilityKnowledgesId:
                return kKnowledges[abilityId];
        };
        return wstring() + L"";
    }
} // End namespace SBF
