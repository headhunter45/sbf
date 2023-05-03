#include "Abilities.h"

#include <iostream>
#include <sstream>

#include "test.h"

namespace {
using namespace SBF;
using namespace Test;
using namespace std;
}  // End namespace

const int kAbilityGroupUnknownId = 0;
const std::string kAbilityGroupUnknownLabel = "";
const std::string kAbilityGroupTalentsSingular = "Talent";
const std::string kAbilityGroupTalentsPlural = "Talents";
const std::string kAbilityGroupSkillsSingular = "Skill";
const std::string kAbilityGroupSkillsPlural = "Skills";
const std::string kAbilityGroupKnowledgesSingular = "Knowledge";
const std::string kAbilityGroupKnowledgesPlural = "Knowledges";

const AbilityGroup kAbilityGroupUnknown =
    AbilityGroup(kAbilityGroupUnknownId, kAbilityGroupUnknownLabel, kAbilityGroupUnknownLabel);
const AbilityGroup kAbilityGroupTalents =
    AbilityGroup(kAbilityGroupTalentsId, kAbilityGroupTalentsSingular, kAbilityGroupTalentsPlural);
const AbilityGroup kAbilityGroupSkills =
    AbilityGroup(kAbilityGroupSkillsId, kAbilityGroupSkillsSingular, kAbilityGroupSkillsPlural);
const AbilityGroup kAbilityGroupKnowledges =
    AbilityGroup(kAbilityGroupKnowledgesId, kAbilityGroupKnowledgesSingular, kAbilityGroupKnowledgesPlural);
const vector kAbilityGroups = {kAbilityGroupTalents, kAbilityGroupSkills, kAbilityGroupKnowledges};

const int kAbilityUnknownId = 0;
const std::string kAbilityUnknownLabel = "";
const Ability kAbilityUnknown = Ability(kAbilityUnknownId, kAbilityGroupUnknownId, kAbilityUnknownLabel);

const std::string kTalentActingLabel = "Acting";
const std::string kTalentAlertnessLabel = "Alertness";
const std::string kTalentAthleticsLabel = "Athletics";
const std::string kTalentBrawlLabel = "Brawl";
const std::string kTalentDodgeLabel = "Dodge";
const std::string kTalentEmpathyLabel = "Empathy";
const std::string kTalentIntimidationLabel = "Intimidation";
const std::string kTalentLeadershipLabel = "Leadership";
const std::string kTalentStreetwiseLabel = "Streetwise";
const std::string kTalentSubterfugeLabel = "Subterfuge";
const vector kTalentLabels = {
    kTalentActingLabel,
    kTalentAlertnessLabel,
    kTalentAthleticsLabel,
    kTalentBrawlLabel,
    kTalentDodgeLabel,
    kTalentEmpathyLabel,
    kTalentIntimidationLabel,
    kTalentLeadershipLabel,
    kTalentStreetwiseLabel,
    kTalentSubterfugeLabel,
};
const Ability kTalentActing = Ability(kTalentActingId, kAbilityGroupTalentsId, kTalentActingLabel);
const Ability kTalentAlertness = Ability(kTalentAlertnessId, kAbilityGroupTalentsId, kTalentAlertnessLabel);
const Ability kTalentAthletics = Ability(kTalentAthleticsId, kAbilityGroupTalentsId, kTalentAthleticsLabel);
const Ability kTalentBrawl = Ability(kTalentBrawlId, kAbilityGroupTalentsId, kTalentBrawlLabel);
const Ability kTalentDodge = Ability(kTalentDodgeId, kAbilityGroupTalentsId, kTalentDodgeLabel);
const Ability kTalentEmpathy = Ability(kTalentEmpathyId, kAbilityGroupTalentsId, kTalentEmpathyLabel);
const Ability kTalentIntimidation = Ability(kTalentIntimidationId, kAbilityGroupTalentsId, kTalentIntimidationLabel);
const Ability kTalentLeadership = Ability(kTalentLeadershipId, kAbilityGroupTalentsId, kTalentLeadershipLabel);
const Ability kTalentStreetwise = Ability(kTalentStreetwiseId, kAbilityGroupTalentsId, kTalentStreetwiseLabel);
const Ability kTalentSubterfuge = Ability(kTalentSubterfugeId, kAbilityGroupTalentsId, kTalentSubterfugeLabel);
const vector kTalents = {
    kTalentActing,
    kTalentAlertness,
    kTalentAthletics,
    kTalentBrawl,
    kTalentDodge,
    kTalentEmpathy,
    kTalentIntimidation,
    kTalentLeadership,
    kTalentStreetwise,
    kTalentSubterfuge,
};

const std::string kSkillAnimalKenLabel = "Animal Ken";
const std::string kSkillDriveLabel = "Drive";
const std::string kSkillEtiquetteLabel = "Etiquette";
const std::string kSkillFirearmsLabel = "Firearms";
const std::string kSkillMeleeLabel = "Melee";
const std::string kSkillMusicLabel = "Music";
const std::string kSkillRepairLabel = "Repair";
const std::string kSkillSecurityLabel = "Security";
const std::string kSkillStealthLabel = "Stealth";
const std::string kSkillSurvivalLabel = "Survival";
const vector kSkillLabels = {
    kSkillAnimalKenLabel,
    kSkillDriveLabel,
    kSkillEtiquetteLabel,
    kSkillFirearmsLabel,
    kSkillMeleeLabel,
    kSkillMusicLabel,
    kSkillRepairLabel,
    kSkillSecurityLabel,
    kSkillStealthLabel,
    kSkillSurvivalLabel,
};
const Ability kSkillAnimalKen = Ability(kSkillAnimalKenId, kAbilityGroupSkillsId, kSkillAnimalKenLabel);
const Ability kSkillDrive = Ability(kSkillDriveId, kAbilityGroupSkillsId, kSkillDriveLabel);
const Ability kSkillEtiquette = Ability(kSkillEtiquetteId, kAbilityGroupSkillsId, kSkillEtiquetteLabel);
const Ability kSkillFirearms = Ability(kSkillFirearmsId, kAbilityGroupSkillsId, kSkillFirearmsLabel);
const Ability kSkillMelee = Ability(kSkillMeleeId, kAbilityGroupSkillsId, kSkillMeleeLabel);
const Ability kSkillMusic = Ability(kSkillMusicId, kAbilityGroupSkillsId, kSkillMusicLabel);
const Ability kSkillRepair = Ability(kSkillRepairId, kAbilityGroupSkillsId, kSkillRepairLabel);
const Ability kSkillSecurity = Ability(kSkillSecurityId, kAbilityGroupSkillsId, kSkillSecurityLabel);
const Ability kSkillStealth = Ability(kSkillStealthId, kAbilityGroupSkillsId, kSkillStealthLabel);
const Ability kSkillSurvival = Ability(kSkillSurvivalId, kAbilityGroupSkillsId, kSkillSurvivalLabel);
const vector kSkills = {
    kSkillAnimalKen,
    kSkillDrive,
    kSkillEtiquette,
    kSkillFirearms,
    kSkillMelee,
    kSkillMusic,
    kSkillRepair,
    kSkillSecurity,
    kSkillStealth,
    kSkillSurvival,
};

const std::string kKnowledgeBureaucracyLabel = "Bureaucracy";
const std::string kKnowledgeComputerLabel = "Computer";
const std::string kKnowledgeFinanceLabel = "Finance";
const std::string kKnowledgeInvestigationLabel = "Investigation";
const std::string kKnowledgeLawLabel = "Law";
const std::string kKnowledgeLinguisticsLabel = "Linguistics";
const std::string kKnowledgeMedicineLabel = "Medicine";
const std::string kKnowledgeOccultLabel = "Occult";
const std::string kKnowledgePoliticsLabel = "Politics";
const std::string kKnowledgeScienceLabel = "Science";
const vector kKnowledgeLabels = {
    kKnowledgeBureaucracyLabel,
    kKnowledgeComputerLabel,
    kKnowledgeFinanceLabel,
    kKnowledgeInvestigationLabel,
    kKnowledgeLawLabel,
    kKnowledgeLinguisticsLabel,
    kKnowledgeMedicineLabel,
    kKnowledgeOccultLabel,
    kKnowledgePoliticsLabel,
    kKnowledgeScienceLabel,
};
const Ability kKnowledgeBureaucracy =
    Ability(kKnowledgeBureaucracyId, kAbilityGroupKnowledgesId, kKnowledgeBureaucracyLabel);
const Ability kKnowledgeComputer = Ability(kKnowledgeComputerId, kAbilityGroupKnowledgesId, kKnowledgeComputerLabel);
const Ability kKnowledgeFinance = Ability(kKnowledgeFinanceId, kAbilityGroupKnowledgesId, kKnowledgeFinanceLabel);
const Ability kKnowledgeInvestigation =
    Ability(kKnowledgeInvestigationId, kAbilityGroupKnowledgesId, kKnowledgeInvestigationLabel);
const Ability kKnowledgeLaw = Ability(kKnowledgeLawId, kAbilityGroupKnowledgesId, kKnowledgeLawLabel);
const Ability kKnowledgeLinguistics =
    Ability(kKnowledgeLinguisticsId, kAbilityGroupKnowledgesId, kKnowledgeLinguisticsLabel);
const Ability kKnowledgeMedicine = Ability(kKnowledgeMedicineId, kAbilityGroupKnowledgesId, kKnowledgeMedicineLabel);
const Ability kKnowledgeOccult = Ability(kKnowledgeOccultId, kAbilityGroupKnowledgesId, kKnowledgeOccultLabel);
const Ability kKnowledgePolitics = Ability(kKnowledgePoliticsId, kAbilityGroupKnowledgesId, kKnowledgePoliticsLabel);
const Ability kKnowledgeScience = Ability(kKnowledgeScienceId, kAbilityGroupKnowledgesId, kKnowledgeScienceLabel);
const vector kKnowledges = {
    kKnowledgeBureaucracy,
    kKnowledgeComputer,
    kKnowledgeFinance,
    kKnowledgeInvestigation,
    kKnowledgeLaw,
    kKnowledgeLinguistics,
    kKnowledgeMedicine,
    kKnowledgeOccult,
    kKnowledgePolitics,
    kKnowledgeScience,
};

TestResults test_AbilityGroup_constructor() {
  auto fnToTest = []() { return AbilityGroup(); };
  return execute_suite(make_test_suite(
      "SBF::AbilityGroup::AbilityGroup()",
      fnToTest,
      {
          make_test("should construct the default unknown instance", kAbilityGroupUnknown, make_tuple()),
      }));
}

TestResults test_AbilityGroup_constructor_int_string_string() {
  AbilityGroup invalid_group;
  invalid_group.id(12);
  invalid_group.plural("plural form");
  invalid_group.singular("singular form");

  auto fnToTest = [](int id, const char* singular, const char* plural) { return AbilityGroup(id, singular, plural); };
  return execute_suite(make_test_suite(
      "SBF::AbilityGroup::AbilityGroup(int, string, string)",
      fnToTest,
      {
          make_test(
              "should construct an invalid instance", invalid_group, make_tuple(12, "singular form", "plural form")),
          make_test("should construct knowledges", kAbilityGroupKnowledges, make_tuple(3, "Knowledge", "Knowledges")),
          make_test("should construct skills", kAbilityGroupSkills, make_tuple(2, "Skill", "Skills")),
          make_test("should construct talents", kAbilityGroupTalents, make_tuple(1, "Talent", "Talents")),
          make_test("should construct the unknown instance", kAbilityGroupUnknown, make_tuple(0, "", "")),
      }));
}

TestResults test_AbilityGroup_GetAbilityCount() {
  auto fnToTest = [](const AbilityGroup& group) { return group.GetAbilityCount(); };
  return execute_suite(
      make_test_suite("SBF::AbilityGroup::GetAbilityCount()",
                      fnToTest,
                      {
                          make_test("should get 0 for an invalid instance", 0, make_tuple(kAbilityGroupUnknown)),
                          make_test("should get 10 for knowledges", 10, make_tuple(kAbilityGroupKnowledges)),
                          make_test("should get 10 for skills", 10, make_tuple(kAbilityGroupSkills)),
                          make_test("should get 10 for talents", 10, make_tuple(kAbilityGroupTalents)),
                      }));
}

TestResults test_AbilityGroup_GetAbilityLabels() {
  string no_errors = "no errors";
  auto fnToTest = [no_errors](vector<string> expected, const AbilityGroup& group) {
    ostringstream error_message;
    vector actual = group.GetAbilityLabels();
    compare(error_message, expected, actual);
    string error = error_message.str();
    if (error.size() > 0) {
      return error;
    }
    return no_errors;
  };
  return execute_suite(make_test_suite(
      "SBF::AbilityGroup::GetAbilityLabels()",
      fnToTest,
      {
          make_test("should get knowledges",
                    no_errors,
                    make_tuple(kKnowledgeLabels, AbilityGroup::FromId(kAbilityGroupKnowledgesId))),
          make_test(
              "should get skills", no_errors, make_tuple(kSkillLabels, AbilityGroup::FromId(kAbilityGroupSkillsId))),
          make_test(
              "should get talents", no_errors, make_tuple(kTalentLabels, AbilityGroup::FromId(kAbilityGroupTalentsId))),
          make_test("should get empty for an invalid instance",
                    no_errors,
                    make_tuple(vector<string>(), AbilityGroup::FromId(15))),
      }));
}

TestResults test_AbilityGroup_id_getter() {
  auto fnToTest = [](int id) {
    AbilityGroup ability_group(id, "", "");
    return ability_group.id();
  };
  return execute_suite(make_test_suite("SBF::AbilityGroup::id()",
                                       fnToTest,
                                       {
                                           make_test("should get 12", 12, make_tuple(12)),
                                           make_test("should get -1", -1, make_tuple(-1)),
                                           make_test("should get 2", 2, make_tuple(2)),
                                       }));
}

TestResults test_AbilityGroup_id_setter() {
  auto fnToTest = [](int id) {
    AbilityGroup ability;
    ability.id(id);
    return ability.id();
  };
  return execute_suite(make_test_suite("SBF::AbilityGroup::id(int)",
                                       fnToTest,
                                       {
                                           make_test("should set 16", 16, make_tuple(16)),
                                           make_test("should set -99", -99, make_tuple(-99)),
                                           make_test("should set 3", 3, make_tuple(3)),
                                       }));
}

TestResults test_AbilityGroup_plural_getter() {
  auto fnToTest = [](const char* plural) {
    AbilityGroup ability(-1, "singular", plural);
    return ability.plural();
  };
  return execute_suite(make_test_suite("SBF::AbilityGroup::plural()",
                                       fnToTest,
                                       {
                                           make_test("should get Talents", string("Talents"), make_tuple("Talents")),
                                           make_test("should get birds", string("birds"), make_tuple("birds")),
                                           make_test("should get an empty string", string(""), make_tuple("")),
                                       }));
}

TestResults test_AbilityGroup_plural_setter() {
  auto fnToTest = [](const char* plural) {
    AbilityGroup ability(-1, "singular", "plural");
    ability.plural(plural);
    return ability.plural();
  };
  return execute_suite(make_test_suite("SBF::AbilityGroup::plural(string)",
                                       fnToTest,
                                       {
                                           make_test("should set Talents", string("Talents"), make_tuple("Talents")),
                                           make_test("should set birds", string("birds"), make_tuple("birds")),
                                           make_test("should set an empty string", string(""), make_tuple("")),
                                       }));
}

TestResults test_AbilityGroup_singular_getter() {
  auto fnToTest = [](const char* singular) {
    AbilityGroup ability(-1, singular, "plural");
    return ability.singular();
  };
  return execute_suite(make_test_suite("SBF::AbilityGroup::singular()",
                                       fnToTest,
                                       {
                                           make_test("should get Talents", string("Talents"), make_tuple("Talents")),
                                           make_test("should get birds", string("birds"), make_tuple("birds")),
                                           make_test("should get an empty string", string(""), make_tuple("")),
                                       }));
}

TestResults test_AbilityGroup_singular_setter() {
  auto fnToTest = [](const char* singular) {
    AbilityGroup ability(-1, "singular", "plural");
    ability.singular(singular);
    return ability.singular();
  };
  return execute_suite(make_test_suite("SBF::AbilityGroup::singular(string)",
                                       fnToTest,
                                       {
                                           make_test("should set Talents", string("Talents"), make_tuple("Talents")),
                                           make_test("should set birds", string("birds"), make_tuple("birds")),
                                           make_test("should set an empty string", string(""), make_tuple("")),
                                       }));
}

TestResults test_AbilityGroup_operator_equal_to() {
  AbilityGroup skills = AbilityGroup::FromId(kAbilityGroupSkillsId);
  AbilityGroup talents = AbilityGroup::FromId(kAbilityGroupTalentsId);
  return execute_suite(make_test_suite(
      "SBF::AbilityGroup::operator==",
      [](const AbilityGroup& left, const AbilityGroup& right) { return left == right; },
      {
          make_test("should return true when comparing an ability group to itself", true, make_tuple(talents, talents)),
          make_test("should return true when comparing two different instances created with the same values",
                    true,
                    make_tuple(skills, AbilityGroup({skills.id(), skills.singular(), skills.plural()}))),
          make_test(
              "should return false when comparing two different ability gropus",
              false,
              make_tuple(AbilityGroup::FromId(kAbilityGroupKnowledgesId), AbilityGroup::FromId(kAbilityGroupSkillsId))),
      }));
}

TestResults test_AbilityGroup_operator_not_equal_to() {
  AbilityGroup skills = AbilityGroup::FromId(kAbilityGroupSkillsId);
  return execute_suite(make_test_suite(
      "SBF::AbilityGroup::operator!=",
      [](const AbilityGroup& left, const AbilityGroup& right) { return left != right; },
      {
          make_test(
              "should return false when comparing an ability group to itself",
              false,
              make_tuple(AbilityGroup::FromId(kAbilityGroupTalentsId), AbilityGroup::FromId(kAbilityGroupTalentsId))),
          make_test("should return false when comparing two different instances created with the same values",
                    false,
                    make_tuple(skills, AbilityGroup({skills.id(), skills.singular(), skills.plural()}))),
          make_test(
              "should return true when comparing two different ability gropus",
              true,
              make_tuple(AbilityGroup::FromId(kAbilityGroupKnowledgesId), AbilityGroup::FromId(kAbilityGroupSkillsId))),
      }));
}

TestResults test_AbilityGroup_static_FromId() {
  return execute_suite(
      make_test_suite("SBF::AbilityGroup::FromId(int)",
                      AbilityGroup::FromId,
                      {
                          make_test("should get the unknown group for id 0", kAbilityGroupUnknown, make_tuple(0)),
                          make_test("should get knowledges for id 3", kAbilityGroupKnowledges, make_tuple(3)),
                          make_test("should get skills for id 2", kAbilityGroupSkills, make_tuple(2)),
                          make_test("should get talents for id 1", kAbilityGroupTalents, make_tuple(1)),
                          make_test("should get the unknown group for id 4", kAbilityGroupUnknown, make_tuple(4)),
                      }));
}

TestResults test_AbilityGroup_static_GetPluralLabels() {
  string no_errors = "no errors";
  auto fnToTest = [no_errors]() {
    vector expected = {kAbilityGroupTalentsPlural, kAbilityGroupSkillsPlural, kAbilityGroupKnowledgesPlural};
    vector actual = AbilityGroup::GetPluralLabels();
    ostringstream error_message;

    compare(error_message, expected, actual);
    string error = error_message.str();
    if (error.size() > 0) {
      return error;
    }
    return no_errors;
  };
  return execute_suite(make_test_suite("SBF::AbilityGroup::GetPluralLabels()",
                                       fnToTest,
                                       {
                                           make_test("should get plural labels", no_errors, make_tuple()),
                                       }));
}

TestResults test_AbilityGroup_static_GetAbilityLabels() {
  string no_errors = "no errors";
  auto fnToTest = [no_errors](vector<string> expected, int id) {
    vector actual = AbilityGroup::GetAbilityLabels(id);
    ostringstream error_message;

    compare(error_message, expected, actual);
    string error = error_message.str();
    if (error.size() > 0) {
      return error;
    }
    return no_errors;
  };
  return execute_suite(
      make_test_suite("SBF::AbilityGroup::GetAbilityLabels(int)",
                      fnToTest,
                      {
                          make_test("should get an empty vector for an invalid id that is too small",
                                    no_errors,
                                    make_tuple(vector<string>(), 0)),
                          make_test("should get knowledges", no_errors, make_tuple(kKnowledgeLabels, 3)),
                          make_test("should get skills", no_errors, make_tuple(kSkillLabels, 2)),
                          make_test("should get talents", no_errors, make_tuple(kTalentLabels, 1)),
                          make_test("should get an empty vector for an invalid id that is too big",
                                    no_errors,
                                    make_tuple(vector<string>(), 4)),
                      }));
}

TestResults test_AbilityGroup_static_GetCount() {
  return execute_suite(make_test_suite("SBF::AbilityGroup::GetCount()",
                                       AbilityGroup::GetCount,
                                       {
                                           make_test("should get 3", 3, make_tuple()),
                                       }));
}

TestResults test_AbilityGroup_friend_operator_extract() {
  return execute_suite(
      make_test_suite("SBF::AbilityGroup::operator<<",
                      [](const AbilityGroup& ability) {
                        ostringstream os;
                        os << ability;
                        return os.str();
                      },
                      {
                          make_test<string>("should print talents",
                                            "AbilityGroup: {id: 1, singular: \"Talent\", plural: \"Talents\"}",
                                            make_tuple(AbilityGroup::FromId(kAbilityGroupTalentsId))),
                          make_test<string>("should print skills",
                                            "AbilityGroup: {id: 2, singular: \"Skill\", plural: \"Skills\"}",
                                            make_tuple(AbilityGroup::FromId(kAbilityGroupSkillsId))),
                          make_test<string>("should print knowledges",
                                            "AbilityGroup: {id: 3, singular: \"Knowledge\", plural: \"Knowledges\"}",
                                            make_tuple(AbilityGroup::FromId(kAbilityGroupKnowledgesId))),
                          make_test<string>("should print an unknown ability group",
                                            "AbilityGroup: {id: 0, singular: \"\", plural: \"\"}",
                                            make_tuple(AbilityGroup::FromId(0))),
                      }));
}

TestResults test_Ability_constructor() {
  auto fnToTest = []() { return Ability(); };
  return execute_suite(
      make_test_suite("SBF::Ability::Ability()",
                      fnToTest,
                      {
                          make_test("should construct the default unknown instance", kAbilityUnknown, make_tuple()),
                      }));
}

TestResults test_Ability_constructor_int_int_string() {
  Ability invalid_ability;
  invalid_ability.id(-12);
  invalid_ability.group_id(74);
  invalid_ability.label("Custom");
  auto fnToTest = [](int id, int group_id, const string& label) { return Ability(id, group_id, label); };
  return execute_suite(make_test_suite(
      "SBF::Ability::Ability(int, int, string)",
      fnToTest,
      {
          make_test("should construct the unknown ability", kAbilityUnknown, make_tuple(0, 0, "")),
          make_test("should construct the acting talent",
                    kTalentActing,
                    make_tuple(kTalentActing.id(), kTalentActing.group_id(), kTalentActing.label().c_str())),
          make_test("should construct an invalid ability", invalid_ability, make_tuple(-12, 74, "Custom")),
      }));
}

TestResults test_Ability_group_id_getter() {
  auto fnToTest = [](int id) {
    Ability ability(0, id, "");
    return ability.group_id();
  };
  return execute_suite(make_test_suite("SBF::Ability::group_id()",
                                       fnToTest,
                                       {
                                           make_test("should get 12", 12, make_tuple(12)),
                                           make_test("should get -1", -1, make_tuple(-1)),
                                           make_test("should get 2", 2, make_tuple(2)),
                                       }));
}

TestResults test_Ability_group_id_setter() {
  auto fnToTest = [](int id) {
    Ability ability(-1, -2, "label");
    ability.group_id(id);
    return ability.group_id();
  };
  return execute_suite(make_test_suite("SBF::Ability::id(int)",
                                       fnToTest,
                                       {
                                           make_test("should set 16", 16, make_tuple(16)),
                                           make_test("should set -99", -99, make_tuple(-99)),
                                           make_test("should set 3", 3, make_tuple(3)),
                                       }));
}

TestResults test_Ability_id_getter() {
  auto fnToTest = [](int id) {
    Ability ability(id, 0, "");
    return ability.id();
  };
  return execute_suite(make_test_suite("SBF::Ability::id()",
                                       fnToTest,
                                       {
                                           make_test("should get 12", 12, make_tuple(12)),
                                           make_test("should get -1", -1, make_tuple(-1)),
                                           make_test("should get 2", 2, make_tuple(2)),
                                       }));
}

TestResults test_Ability_id_setter() {
  auto fnToTest = [](int id) {
    Ability ability(-1, -2, "label");
    ability.id(id);
    return ability.id();
  };
  return execute_suite(make_test_suite("SBF::Ability::id(int)",
                                       fnToTest,
                                       {
                                           make_test("should set 16", 16, make_tuple(16)),
                                           make_test("should set -99", -99, make_tuple(-99)),
                                           make_test("should set 3", 3, make_tuple(3)),
                                       }));
}

TestResults test_Ability_label_getter() {
  auto fnToTest = [](const string& label) {
    Ability ability(0, 0, label);
    return ability.label();
  };
  return execute_suite(make_test_suite("SBF::Ability::label()",
                                       fnToTest,
                                       {
                                           make_test("should get Talents", string("Talents"), make_tuple("Talents")),
                                           make_test("should get birds", string("birds"), make_tuple("birds")),
                                           make_test("should get an empty string", string(""), make_tuple("")),
                                       }));
}

TestResults test_Ability_label_setter() {
  auto fnToTest = [](const string& label) {
    Ability ability(-1, -2, "label");
    ability.label(label);
    return ability.label();
  };
  return execute_suite(make_test_suite("SBF::Ability::label(string)",
                                       fnToTest,
                                       {
                                           make_test("should set Acting", string("Acting"), make_tuple("Acting")),
                                           make_test("should set birds", string("birds"), make_tuple("birds")),
                                           make_test("should set an empty string", string(), make_tuple("")),
                                       }));
}

TestResults test_Ability_operator_equal_to() {
  Ability security = Ability::FromIds(kSkillSecurityId, kAbilityGroupSkillsId);
  Ability acting = Ability::FromIds(kTalentActingId, kAbilityGroupTalentsId);
  return execute_suite(make_test_suite(
      "SBF::Ability::operator==",
      [](const Ability& left, const Ability& right) { return left == right; },
      vector({
          make_test("should return true when comparing an ability to itself", true, make_tuple(acting, acting)),
          make_test("should return true when comparing two different instances created with the same values",
                    true,
                    make_tuple(security, Ability({security.id(), security.group_id(), security.label()}))),
          make_test("should return false when comparing two different ability gropus",
                    false,
                    make_tuple(Ability::FromIds(kKnowledgeComputerId, kAbilityGroupKnowledgesId),
                               Ability::FromIds(kKnowledgeScienceId, kAbilityGroupKnowledgesId))),
      })));
}

TestResults test_Ability_operator_not_equal_to() {
  Ability security = Ability::FromIds(kSkillSecurityId, kAbilityGroupSkillsId);
  Ability acting = Ability::FromIds(kTalentActingId, kAbilityGroupTalentsId);
  return execute_suite(make_test_suite(
      "SBF::Ability::operator!=",
      [](const Ability& left, const Ability& right) { return left != right; },
      vector({
          make_test("should return fale when comparing an ability to itself", false, make_tuple(acting, acting)),
          make_test("should return false when comparing two different instances created with the same values",
                    false,
                    make_tuple(security, Ability({security.id(), security.group_id(), security.label()}))),
          make_test("should return true when comparing two different ability gropus",
                    true,
                    make_tuple(Ability::FromIds(kKnowledgeComputerId, kAbilityGroupKnowledgesId),
                               Ability::FromIds(kKnowledgeScienceId, kAbilityGroupKnowledgesId))),
      })));
}

TestResults test_Ability_static_FromIds() {
  return execute_suite(make_test_suite(
      "SBF::Ability::FromIds(int, int)",
      Ability::FromIds,
      {
          make_test("should get knowledge bureaucracy",
                    kKnowledgeBureaucracy,
                    make_tuple(kKnowledgeBureaucracyId, kAbilityGroupKnowledgesId)),
          make_test("should get knowledge computer",
                    kKnowledgeComputer,
                    make_tuple(kKnowledgeComputerId, kAbilityGroupKnowledgesId)),
          make_test("should get knowledge finance",
                    kKnowledgeFinance,
                    make_tuple(kKnowledgeFinanceId, kAbilityGroupKnowledgesId)),
          make_test("should get knowledge investigation",
                    kKnowledgeInvestigation,
                    make_tuple(kKnowledgeInvestigationId, kAbilityGroupKnowledgesId)),
          make_test("should get knowledge law", kKnowledgeLaw, make_tuple(kKnowledgeLawId, kAbilityGroupKnowledgesId)),
          make_test("should get knowledge linguistics",
                    kKnowledgeLinguistics,
                    make_tuple(kKnowledgeLinguisticsId, kAbilityGroupKnowledgesId)),
          make_test("should get knowledge medicine",
                    kKnowledgeMedicine,
                    make_tuple(kKnowledgeMedicineId, kAbilityGroupKnowledgesId)),
          make_test("should get knowledge occult",
                    kKnowledgeOccult,
                    make_tuple(kKnowledgeOccultId, kAbilityGroupKnowledgesId)),
          make_test("should get knowledge politics",
                    kKnowledgePolitics,
                    make_tuple(kKnowledgePoliticsId, kAbilityGroupKnowledgesId)),
          make_test("should get knowledge science",
                    kKnowledgeScience,
                    make_tuple(kKnowledgeScienceId, kAbilityGroupKnowledgesId)),
          make_test(
              "should get skill animalKen", kSkillAnimalKen, make_tuple(kSkillAnimalKenId, kAbilityGroupSkillsId)),
          make_test("should get skill drive", kSkillDrive, make_tuple(kSkillDriveId, kAbilityGroupSkillsId)),
          make_test(
              "should get skill etiquette", kSkillEtiquette, make_tuple(kSkillEtiquetteId, kAbilityGroupSkillsId)),
          make_test("should get skill firearms", kSkillFirearms, make_tuple(kSkillFirearmsId, kAbilityGroupSkillsId)),
          make_test("should get skill melee", kSkillMelee, make_tuple(kSkillMeleeId, kAbilityGroupSkillsId)),
          make_test("should get skill music", kSkillMusic, make_tuple(kSkillMusicId, kAbilityGroupSkillsId)),
          make_test("should get skill repair", kSkillRepair, make_tuple(kSkillRepairId, kAbilityGroupSkillsId)),
          make_test("should get skill security", kSkillSecurity, make_tuple(kSkillSecurityId, kAbilityGroupSkillsId)),
          make_test("should get skill stealth", kSkillStealth, make_tuple(kSkillStealthId, kAbilityGroupSkillsId)),
          make_test("should get skill survival", kSkillSurvival, make_tuple(kSkillSurvivalId, kAbilityGroupSkillsId)),
          make_test("should get talent acting", kTalentActing, make_tuple(kTalentActingId, kAbilityGroupTalentsId)),
          make_test(
              "should get talent alertness", kTalentAlertness, make_tuple(kTalentAlertnessId, kAbilityGroupTalentsId)),
          make_test(
              "should get talent athletics", kTalentAthletics, make_tuple(kTalentAthleticsId, kAbilityGroupTalentsId)),
          make_test("should get talent brawl", kTalentBrawl, make_tuple(kTalentBrawlId, kAbilityGroupTalentsId)),
          make_test("should get talent dodge", kTalentDodge, make_tuple(kTalentDodgeId, kAbilityGroupTalentsId)),
          make_test("should get talent empathy", kTalentEmpathy, make_tuple(kTalentEmpathyId, kAbilityGroupTalentsId)),
          make_test("should get talent intimidation",
                    kTalentIntimidation,
                    make_tuple(kTalentIntimidationId, kAbilityGroupTalentsId)),
          make_test("should get talent leadership",
                    kTalentLeadership,
                    make_tuple(kTalentLeadershipId, kAbilityGroupTalentsId)),
          make_test("should get talent streetwise",
                    kTalentStreetwise,
                    make_tuple(kTalentStreetwiseId, kAbilityGroupTalentsId)),
          make_test("should get talent subterfuge",
                    kTalentSubterfuge,
                    make_tuple(kTalentSubterfugeId, kAbilityGroupTalentsId)),
          make_test("should get unknown for an invalid id too small", kAbilityUnknown, make_tuple(0, 1)),
          make_test("should get unknown for an invalid id too large", kAbilityUnknown, make_tuple(11, 1)),
          make_test("should get unknown for an invalid group_id too small", kAbilityUnknown, make_tuple(1, 0)),
          make_test("should get unknown for an invalid group_id too large", kAbilityUnknown, make_tuple(1, 4)),
          make_test("should get unknown for an invalid id and group_id", kAbilityUnknown, make_tuple(-1, -1)),
      }));
}

TestResults test_Ability_static_FromKnowledgeId() {
  return execute_suite(make_test_suite(
      "SBF::Ability::FromKnowledgeId(int)",
      Ability::FromKnowledgeId,
      {
          make_test("should bureaucracy", kKnowledgeBureaucracy, make_tuple(kKnowledgeBureaucracyId)),
          make_test("should computer", kKnowledgeComputer, make_tuple(kKnowledgeComputerId)),
          make_test("should finance", kKnowledgeFinance, make_tuple(kKnowledgeFinanceId)),
          make_test("should investigation", kKnowledgeInvestigation, make_tuple(kKnowledgeInvestigationId)),
          make_test("should law", kKnowledgeLaw, make_tuple(kKnowledgeLawId)),
          make_test("should linguistics", kKnowledgeLinguistics, make_tuple(kKnowledgeLinguisticsId)),
          make_test("should medicine", kKnowledgeMedicine, make_tuple(kKnowledgeMedicineId)),
          make_test("should occult", kKnowledgeOccult, make_tuple(kKnowledgeOccultId)),
          make_test("should politics", kKnowledgePolitics, make_tuple(kKnowledgePoliticsId)),
          make_test("should science", kKnowledgeScience, make_tuple(kKnowledgeScienceId)),
          make_test("should get unknown for an invalid id too small", kAbilityUnknown, make_tuple(0)),
          make_test("should get unknown for an invalid negative id", kAbilityUnknown, make_tuple(-2)),
          make_test("should get unknown for an invalid id too large", kAbilityUnknown, make_tuple(11)),
      }));
}

TestResults test_Ability_static_FromSkillId() {
  return execute_suite(
      make_test_suite("SBF::Ability::FromSkillId(int)",
                      Ability::FromSkillId,
                      {
                          make_test("should animalKen", kSkillAnimalKen, make_tuple(kSkillAnimalKenId)),
                          make_test("should drive", kSkillDrive, make_tuple(kSkillDriveId)),
                          make_test("should etiquette", kSkillEtiquette, make_tuple(kSkillEtiquetteId)),
                          make_test("should firearms", kSkillFirearms, make_tuple(kSkillFirearmsId)),
                          make_test("should melee", kSkillMelee, make_tuple(kSkillMeleeId)),
                          make_test("should music", kSkillMusic, make_tuple(kSkillMusicId)),
                          make_test("should repair", kSkillRepair, make_tuple(kSkillRepairId)),
                          make_test("should security", kSkillSecurity, make_tuple(kSkillSecurityId)),
                          make_test("should stealth", kSkillStealth, make_tuple(kSkillStealthId)),
                          make_test("should survival", kSkillSurvival, make_tuple(kSkillSurvivalId)),
                          make_test("should get unknown for an invalid id too small", kAbilityUnknown, make_tuple(0)),
                          make_test("should get unknown for an invalid negative id", kAbilityUnknown, make_tuple(-2)),
                          make_test("should get unknown for an invalid id too large", kAbilityUnknown, make_tuple(11)),
                      }));
}

TestResults test_Ability_static_FromTalentId() {
  return execute_suite(
      make_test_suite("SBF::Ability::FromTalentId(int)",
                      Ability::FromTalentId,
                      {
                          make_test("should acting", kTalentActing, make_tuple(kTalentActingId)),
                          make_test("should alertness", kTalentAlertness, make_tuple(kTalentAlertnessId)),
                          make_test("should athletics", kTalentAthletics, make_tuple(kTalentAthleticsId)),
                          make_test("should brawl", kTalentBrawl, make_tuple(kTalentBrawlId)),
                          make_test("should dodge", kTalentDodge, make_tuple(kTalentDodgeId)),
                          make_test("should empathy", kTalentEmpathy, make_tuple(kTalentEmpathyId)),
                          make_test("should intimidation", kTalentIntimidation, make_tuple(kTalentIntimidationId)),
                          make_test("should leadership", kTalentLeadership, make_tuple(kTalentLeadershipId)),
                          make_test("should streetwise", kTalentStreetwise, make_tuple(kTalentStreetwiseId)),
                          make_test("should subterfuge", kTalentSubterfuge, make_tuple(kTalentSubterfugeId)),
                          make_test("should get unknown for an invalid id too small", kAbilityUnknown, make_tuple(0)),
                          make_test("should get unknown for an invalid negative id", kAbilityUnknown, make_tuple(-2)),
                          make_test("should get unknown for an invalid id too large", kAbilityUnknown, make_tuple(11)),
                      }));
}

TestResults test_Ability_static_GetCount() {
  return execute_suite(
      make_test_suite("SBF::Ability::GetCount(int)",
                      Ability::GetCount,
                      {
                          make_test("should get 10 knowledges", 10, make_tuple(kAbilityGroupKnowledgesId)),
                          make_test("should get 10 skills", 10, make_tuple(kAbilityGroupSkillsId)),
                          make_test("should get 10 talents", 10, make_tuple(kAbilityGroupTalentsId)),
                          make_test("should get 0 for an invalid id too small", 0, make_tuple(0)),
                          make_test("should get 0 for an invalid id too large", 0, make_tuple(4)),
                      }));
}

TestResults test_Ability_static_GetKnowledgeLabel() {
  return execute_suite(make_test_suite(
      "SBF::Ability::GetKnowledgeLabel(int)",
      Ability::GetKnowledgeLabel,
      {
          make_test("should get \"Bureaucracy\" for kKnowledgeBureaucracyId",
                    kKnowledgeBureaucracyLabel,
                    make_tuple(kKnowledgeBureaucracyId)),
          make_test("should get \"Computer\" for kKnowledgeComputerId",
                    kKnowledgeComputerLabel,
                    make_tuple(kKnowledgeComputerId)),
          make_test("should get \"Finance\" for kKnowledgeFinanceId",
                    kKnowledgeFinanceLabel,
                    make_tuple(kKnowledgeFinanceId)),
          make_test("should get \"Investigation\" for kKnowledgeInvestigationId",
                    kKnowledgeInvestigationLabel,
                    make_tuple(kKnowledgeInvestigationId)),
          make_test("should get \"Law\" for kKnowledgeLawId", kKnowledgeLawLabel, make_tuple(kKnowledgeLawId)),
          make_test("should get \"Linguistics\" for kKnowledgeLinguisticsId",
                    kKnowledgeLinguisticsLabel,
                    make_tuple(kKnowledgeLinguisticsId)),
          make_test("should get \"Medicine\" for kKnowledgeMedicineId",
                    kKnowledgeMedicineLabel,
                    make_tuple(kKnowledgeMedicineId)),
          make_test(
              "should get \"Occult\" for kKnowledgeOccultId", kKnowledgeOccultLabel, make_tuple(kKnowledgeOccultId)),
          make_test("should get \"Politics\" for kKnowledgePoliticsId",
                    kKnowledgePoliticsLabel,
                    make_tuple(kKnowledgePoliticsId)),
          make_test("should get \"Science\" for kKnowledgeScienceId",
                    kKnowledgeScienceLabel,
                    make_tuple(kKnowledgeScienceId)),
          make_test("should get an empty string for an invalid id too small", string(), make_tuple(0)),
          make_test("should get an empty string for an invalid id too large", string(), make_tuple(11)),
      }));
}

TestResults test_Ability_static_GetKnowledgeLabels() {
  string no_errors = "no errors";
  auto fnToTest = [no_errors]() {
    ostringstream error_message;
    vector expected = kKnowledgeLabels;
    vector actual = Ability::GetKnowledgeLabels();
    compare(error_message, expected, actual);
    string error = error_message.str();
    if (error.size() > 0) {
      return error;
    }
    return no_errors;
  };
  return execute_suite(make_test_suite("SBF::Ability::GetKnowledgeLabels()",
                                       fnToTest,
                                       {
                                           make_test("should get knowledge labels", no_errors, make_tuple()),
                                       }));
}

TestResults test_Ability_static_GetKnowledgesCount() {
  return execute_suite(make_test_suite("SBF::Ability::GetKnowledgesCount()",
                                       Ability::GetKnowledgesCount,
                                       {
                                           make_test("should get 10 knowledges", 10, make_tuple()),
                                       }));
}

TestResults test_Ability_static_GetSkillLabel() {
  return execute_suite(make_test_suite(
      "SBF::Ability::GetSkillLabel(int)",
      Ability::GetSkillLabel,
      {
          make_test(
              "should get \"Animal Ken\" for kSkillAnimalKenId", kSkillAnimalKenLabel, make_tuple(kSkillAnimalKenId)),
          make_test("should get \"Drive\" for kSkillDriveId", kSkillDriveLabel, make_tuple(kSkillDriveId)),
          make_test(
              "should get \"Etiquette\" for kSkillEtiquetteId", kSkillEtiquetteLabel, make_tuple(kSkillEtiquetteId)),
          make_test("should get \"Firearms\" for kSkillFirearmsId", kSkillFirearmsLabel, make_tuple(kSkillFirearmsId)),
          make_test("should get \"Melee\" for kSkillMeleeId", kSkillMeleeLabel, make_tuple(kSkillMeleeId)),
          make_test("should get \"Music\" for kSkillMusicId", kSkillMusicLabel, make_tuple(kSkillMusicId)),
          make_test("should get \"Repair\" for kSkillRepairId", kSkillRepairLabel, make_tuple(kSkillRepairId)),
          make_test("should get \"Security\" for kSkillSecurityId", kSkillSecurityLabel, make_tuple(kSkillSecurityId)),
          make_test("should get \"Stealth\" for kSkillStealthId", kSkillStealthLabel, make_tuple(kSkillStealthId)),
          make_test("should get \"Survival\" for kSkillSurvivalId", kSkillSurvivalLabel, make_tuple(kSkillSurvivalId)),
          make_test("should get an empty string for an invalid id too small", string(), make_tuple(0)),
          make_test("should get an empty string for an invalid id too large", string(), make_tuple(11)),
      }));
}

TestResults test_Ability_static_GetSkillLabels() {
  string no_errors = "no errors";
  auto fnToTest = [no_errors]() {
    ostringstream error_message;
    vector expected = kSkillLabels;
    vector actual = Ability::GetSkillLabels();
    compare(error_message, expected, actual);
    string error = error_message.str();
    if (error.size() > 0) {
      return error;
    }
    return no_errors;
  };
  return execute_suite(make_test_suite("SBF::Abliity::GetSkillLabels()",
                                       fnToTest,
                                       {
                                           make_test("should get skill labels", no_errors, make_tuple()),
                                       }));
}

TestResults test_Ability_static_GetSkillsCount() {
  return execute_suite(make_test_suite("SBF::Ability::GetSkillsCount()",
                                       Ability::GetSkillsCount,
                                       {
                                           make_test("should get 10 skills", 10, make_tuple()),
                                       }));
}

TestResults test_Ability_static_GetTalentLabel() {
  return execute_suite(make_test_suite(
      "SBF::Ability::GetTalentLabel(int)",
      Ability::GetTalentLabel,
      {
          make_test("should get \"Acting\" for kTalentActingId", kTalentActingLabel, make_tuple(kTalentActingId)),
          make_test(
              "should get \"Alertness\" for kTalentAlertnessId", kTalentAlertnessLabel, make_tuple(kTalentAlertnessId)),
          make_test(
              "should get \"Athletics\" for kTalentAthleticsId", kTalentAthleticsLabel, make_tuple(kTalentAthleticsId)),
          make_test("should get \"Brawl\" for kTalentBrawlId", kTalentBrawlLabel, make_tuple(kTalentBrawlId)),
          make_test("should get \"Dodge\" for kTalentDodgeId", kTalentDodgeLabel, make_tuple(kTalentDodgeId)),
          make_test("should get \"Empathy\" for kTalentEmpathyId", kTalentEmpathyLabel, make_tuple(kTalentEmpathyId)),
          make_test("should get \"Intimidation\" for kTalentIntimidationId",
                    kTalentIntimidationLabel,
                    make_tuple(kTalentIntimidationId)),
          make_test("should get \"Leadership\" for kTalentLeadershipId",
                    kTalentLeadershipLabel,
                    make_tuple(kTalentLeadershipId)),
          make_test("should get \"Streetwise\" for kTalentStreetwiseId",
                    kTalentStreetwiseLabel,
                    make_tuple(kTalentStreetwiseId)),
          make_test("should get \"Subterfuge\" for kTalentSubterfugeId",
                    kTalentSubterfugeLabel,
                    make_tuple(kTalentSubterfugeId)),
          make_test("should get an empty string for an invalid id too small", string(), make_tuple(0)),
          make_test("should get an empty string for an invalid id too large", string(), make_tuple(11)),
      }));
}

TestResults test_Ability_static_GetTalentLabels() {
  string no_errors = "no errors";
  auto fnToTest = [no_errors]() {
    ostringstream error_message;
    vector expected = kTalentLabels;
    vector actual = Ability::GetTalentLabels();
    compare(error_message, expected, actual);
    string error = error_message.str();
    if (error.size() > 0) {
      return error;
    }
    return no_errors;
  };
  return execute_suite(make_test_suite("SBF::Abliity::GetTalentLabels()",
                                       fnToTest,
                                       {
                                           make_test("should get talent labels", no_errors, make_tuple()),
                                       }));
}

TestResults test_Ability_static_GetTalentsCount() {
  return execute_suite(make_test_suite("SBF::Ability::GetTalentsCount()",
                                       Ability::GetTalentsCount,
                                       {
                                           make_test("should get 10 talent", 10, make_tuple()),
                                       }));
}

TestResults test_Ability_friend_operator_extract() {
  return execute_suite(make_test_suite("SBF::Ability::operator<<",
                                       [](const Ability& ability) {
                                         ostringstream os;
                                         os << ability;
                                         return os.str();
                                       },
                                       {
                                           make_test("should print knowledge bureaucracy",
                                                     string("Ability: {id: 1, group_id: 3, label: \"Bureaucracy\"}"),
                                                     make_tuple(Ability::FromIds(1, 3))),
                                           make_test("should print knowledge computer",
                                                     string("Ability: {id: 2, group_id: 3, label: \"Computer\"}"),
                                                     make_tuple(Ability::FromIds(2, 3))),
                                           make_test("should print knowledge finance",
                                                     string("Ability: {id: 3, group_id: 3, label: \"Finance\"}"),
                                                     make_tuple(Ability::FromIds(3, 3))),
                                           make_test("should print knowledge investigation",
                                                     string("Ability: {id: 4, group_id: 3, label: \"Investigation\"}"),
                                                     make_tuple(Ability::FromIds(4, 3))),
                                           make_test("should print knowledge law",
                                                     string("Ability: {id: 5, group_id: 3, label: \"Law\"}"),
                                                     make_tuple(Ability::FromIds(5, 3))),
                                           make_test("should print knowledge linguistics",
                                                     string("Ability: {id: 6, group_id: 3, label: \"Linguistics\"}"),
                                                     make_tuple(Ability::FromIds(6, 3))),
                                           make_test("should print knowledge medicine",
                                                     string("Ability: {id: 7, group_id: 3, label: \"Medicine\"}"),
                                                     make_tuple(Ability::FromIds(7, 3))),
                                           make_test("should print knowledge occult",
                                                     string("Ability: {id: 8, group_id: 3, label: \"Occult\"}"),
                                                     make_tuple(Ability::FromIds(8, 3))),
                                           make_test("should print knowledge politics",
                                                     string("Ability: {id: 9, group_id: 3, label: \"Politics\"}"),
                                                     make_tuple(Ability::FromIds(9, 3))),
                                           make_test("should print knowledge science",
                                                     string("Ability: {id: 10, group_id: 3, label: \"Science\"}"),
                                                     make_tuple(Ability::FromIds(10, 3))),
                                           make_test("should print skill animal ken",
                                                     string("Ability: {id: 1, group_id: 2, label: \"Animal Ken\"}"),
                                                     make_tuple(Ability::FromIds(1, 2))),
                                           make_test("should print skill drive",
                                                     string("Ability: {id: 2, group_id: 2, label: \"Drive\"}"),
                                                     make_tuple(Ability::FromIds(2, 2))),
                                           make_test("should print skill etiquette",
                                                     string("Ability: {id: 3, group_id: 2, label: \"Etiquette\"}"),
                                                     make_tuple(Ability::FromIds(3, 2))),
                                           make_test("should print skill firearms",
                                                     string("Ability: {id: 4, group_id: 2, label: \"Firearms\"}"),
                                                     make_tuple(Ability::FromIds(4, 2))),
                                           make_test("should print skill melee",
                                                     string("Ability: {id: 5, group_id: 2, label: \"Melee\"}"),
                                                     make_tuple(Ability::FromIds(5, 2))),
                                           make_test("should print skill music",
                                                     string("Ability: {id: 6, group_id: 2, label: \"Music\"}"),
                                                     make_tuple(Ability::FromIds(6, 2))),
                                           make_test("should print skill repair",
                                                     string("Ability: {id: 7, group_id: 2, label: \"Repair\"}"),
                                                     make_tuple(Ability::FromIds(7, 2))),
                                           make_test("should print skill security",
                                                     string("Ability: {id: 8, group_id: 2, label: \"Security\"}"),
                                                     make_tuple(Ability::FromIds(8, 2))),
                                           make_test("should print skill stealth",
                                                     string("Ability: {id: 9, group_id: 2, label: \"Stealth\"}"),
                                                     make_tuple(Ability::FromIds(9, 2))),
                                           make_test("should print skill survival",
                                                     string("Ability: {id: 10, group_id: 2, label: \"Survival\"}"),
                                                     make_tuple(Ability::FromIds(10, 2))),
                                           make_test("should print talent acting",
                                                     string("Ability: {id: 1, group_id: 1, label: \"Acting\"}"),
                                                     make_tuple(Ability::FromIds(1, 1))),
                                           make_test("should print talent alertness",
                                                     string("Ability: {id: 2, group_id: 1, label: \"Alertness\"}"),
                                                     make_tuple(Ability::FromIds(2, 1))),
                                           make_test("should print talent athletics",
                                                     string("Ability: {id: 3, group_id: 1, label: \"Athletics\"}"),
                                                     make_tuple(Ability::FromIds(3, 1))),
                                           make_test("should print talent brawl",
                                                     string("Ability: {id: 4, group_id: 1, label: \"Brawl\"}"),
                                                     make_tuple(Ability::FromIds(4, 1))),
                                           make_test("should print talent dodge",
                                                     string("Ability: {id: 5, group_id: 1, label: \"Dodge\"}"),
                                                     make_tuple(Ability::FromIds(5, 1))),
                                           make_test("should print talent empathy",
                                                     string("Ability: {id: 6, group_id: 1, label: \"Empathy\"}"),
                                                     make_tuple(Ability::FromIds(6, 1))),
                                           make_test("should print talent intimidation",
                                                     string("Ability: {id: 7, group_id: 1, label: \"Intimidation\"}"),
                                                     make_tuple(Ability::FromIds(7, 1))),
                                           make_test("should print talent leadership",
                                                     string("Ability: {id: 8, group_id: 1, label: \"Leadership\"}"),
                                                     make_tuple(Ability::FromIds(8, 1))),
                                           make_test("should print talent streetwise",
                                                     string("Ability: {id: 9, group_id: 1, label: \"Streetwise\"}"),
                                                     make_tuple(Ability::FromIds(9, 1))),
                                           make_test("should print talent subterfuge",
                                                     string("Ability: {id: 10, group_id: 1, label: \"Subterfuge\"}"),
                                                     make_tuple(Ability::FromIds(10, 1))),
                                       }));
}

int main(int argc, char* argv[]) {
  TestResults results;

  results += test_AbilityGroup_constructor();
  results += test_AbilityGroup_constructor_int_string_string();
  results += test_AbilityGroup_GetAbilityCount();
  results += test_AbilityGroup_GetAbilityLabels();
  results += test_AbilityGroup_id_getter();
  results += test_AbilityGroup_id_setter();
  results += test_AbilityGroup_plural_getter();
  results += test_AbilityGroup_plural_setter();
  results += test_AbilityGroup_singular_getter();
  results += test_AbilityGroup_singular_setter();
  results += test_AbilityGroup_operator_equal_to();
  results += test_AbilityGroup_operator_not_equal_to();

  results += test_AbilityGroup_static_FromId();
  results += test_AbilityGroup_static_GetPluralLabels();
  results += test_AbilityGroup_static_GetAbilityLabels();
  results += test_AbilityGroup_static_GetCount();

  results += test_AbilityGroup_friend_operator_extract();

  results += test_Ability_constructor();
  results += test_Ability_constructor_int_int_string();
  results += test_Ability_group_id_getter();
  results += test_Ability_group_id_setter();
  results += test_Ability_id_getter();
  results += test_Ability_id_setter();
  results += test_Ability_label_getter();
  results += test_Ability_label_setter();
  results += test_Ability_operator_equal_to();
  results += test_Ability_operator_not_equal_to();

  results += test_Ability_static_FromIds();
  results += test_Ability_static_FromKnowledgeId();
  results += test_Ability_static_FromSkillId();
  results += test_Ability_static_FromTalentId();
  results += test_Ability_static_GetCount();
  results += test_Ability_static_GetKnowledgeLabel();
  results += test_Ability_static_GetKnowledgeLabels();
  results += test_Ability_static_GetKnowledgesCount();
  results += test_Ability_static_GetSkillLabel();
  results += test_Ability_static_GetSkillLabels();
  results += test_Ability_static_GetSkillsCount();
  results += test_Ability_static_GetTalentLabel();
  results += test_Ability_static_GetTalentLabels();
  results += test_Ability_static_GetTalentsCount();

  results += test_Ability_friend_operator_extract();

  PrintResults(cout, results);

  return results.failed() + results.errors();
}
