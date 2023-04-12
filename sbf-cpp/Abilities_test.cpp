#include "Abilities.h"
#include "test.h"
#include <iostream>
using namespace SBF;
using namespace Test;
using namespace std;

namespace Test::Abilities {
 TestResults test_GetNumItemsForAbilityGroup();
 TestResults test_GetAbility();
 TestResults test_FillAbilities();
 TestResults test_GetTalentLabel();
 TestResults test_GetSkillLabel();
 TestResults test_GetKnowledgeLabel();
 TestResults test_GetAbilityLabel();
 TestResults test_FillTalentLabels();
 TestResults test_FillSkillLabels();
 TestResults test_FkilKnowledgeLabels();

} // End namespace Test::Abilities
using namespace Test::Abilities;

namespace Test {
    extern TestResults do_the_other_thing();
}

// TODO: Find a way to put this in Test::Abilities or at least Test.
TestResults main_test_Abilities(int argc, char** argv) {
    TestResults results;

    // results = results + test_GetNumItemsForAbilityGroup();
    // results = results + test_GetAbility();
    // results = results + test_FillAbilities();
    // results = results + test_GetTalentLabel();
    // results = results + test_GetSkillLabel();
    // results = results + test_GetKnowledgeLabel();
    // results = results + test_GetAbilityLabel();
    // results = results + test_FillTalentLabels();
    // results = results + test_FillSkillLabels();
    // results = results + test_FkilKnowledgeLabels();

    results = do_the_other_thing();
    
    return results;
}

namespace Test::Abilities {
    TestResults test_GetNumItemsForAbilityGroup() {
        // return test_fn(
        //     L"/SBF/Abilities/GetNumItemsForAbilityGroup",
        //     GetNumItemsForAbilityGroup,
        //     vector({
        //         pair(kTalentsCount, make_tuple(kAbilityTalentsId)),
        //         pair(kSkillsCount, make_tuple(kAbilitySkillsId)),
        //         pair(kKnowledgesCount, make_tuple(kAbilityKnowledgesId)),
        //         pair(0, make_tuple(0)),
        //         pair(0, make_tuple(99)),
        //     }));
        return TestResults();
    }

    TestResults test_GetAbility() {
        // return test_fn(
        //     L"/SBF/Abilities/GetAbility",
        //     GetAbility,
        //     vector({
        //         pair(kAbilityKnowledges, make_tuple(kAbilityKnowledgesId)),
        //     }));
        return TestResults();
    }
    TestResults test_FillAbilities() {
        return TestResults();
    }
    TestResults test_GetTalentLabel() {
        return TestResults();
    }
    TestResults test_GetSkillLabel() {
        return TestResults();
    }
    TestResults test_GetKnowledgeLabel() {
        return TestResults();
    }
    TestResults test_GetAbilityLabel() {
        return TestResults();
    }
    TestResults test_FillTalentLabels() {
        return TestResults();
    }
    TestResults test_FillSkillLabels() {
        return TestResults();
    }
    TestResults test_FkilKnowledgeLabels() {
        return TestResults();
    }
 
 
    // TestResults test_GetNumItemsForAbilityGroup() {
    //     return std::make_tuple(1, 0);
    // }

    //     results = results + test_fn(L"get_substring", get_substring, vector({
    //         pair(L"234", make_tuple(L"1234567890", 1, 3)),
    //         pair(L"Paris", make_tuple(L"Where is Paris?", 10-1, 5)),
    //     }));


} // End namespace Test::Abilities
