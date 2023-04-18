#include "Genders.h"
#include "test.h"
#include <string>
#include <tuple>
#include <vector>
#include <sstream>

using namespace SBF;
using namespace Test;
using namespace std;

namespace Test::Genders {
TestResults test_GetGenderLabel();
TestResults test_FillGenderLabels();
} // End namespace Test::Genders
using namespace Test::Genders;

TestResults main_test_Genders(int argc, char** argv) {
    TestResults results;

    results += test_GetGenderLabel();
    results += test_FillGenderLabels();

    return results;
}

namespace Test::Genders {
TestResults test_GetGenderLabel() {
    return execute_suite<string, int>(make_test_suite(
        "SBF::GetGenderLabel",
        GetGenderLabel,
        vector<TestTuple<string, int>>({
                make_test<string, int>(
                    "should get \"\" for invalid gender id 0",
                    "",
                    make_tuple(0)),
                make_test<string, int>(
                    "should get \"Male\" for gender id 1",
                    "Male",
                    make_tuple(1)),
                make_test<string, int>(
                    "should get \"Female\" for gender id 2",
                    "Female",
                    make_tuple(2)),
                make_test<string, int>(
                    "should get \"Trans-Male\" for gender id 3",
                    "Trans-Male",
                    make_tuple(3)),
                make_test<string, int>(
                    "should get \"Trans-Female\" for gender id 4",
                    "Trans-Female",
                    make_tuple(4)),
                make_test<string, int>(
                    "should get \"Non-Binary\" for gender id 5",
                    "Non-Binary",
                    make_tuple(5)),
                make_test<string, int>(
                    "should get \"\" for invalid gender id 6",
                    "",
                    make_tuple(6)),
        })
    ));
}

TestResults test_FillGenderLabels() {
    auto fnToTest = []()->string {
        ostringstream error_message;
        vector<string> expected = {
            kGenderMaleLabel,
            kGenderFemaleLabel,
            kGenderTransMaleLabel,
            kGenderTransFemaleLabel,
            kGenderNonBinaryLabel,
        };
        vector<string> actual = {"This should be removed."};
        FillGenderLabels(actual);
        compare(error_message, expected, actual);
        string error = error_message.str();
        if (error.size() > 0) {
            return error;
        }
        return "no errors";
    };
    return execute_suite<string>(make_test_suite(
        "SBF::FillGenderLabels",
        fnToTest,
        vector<TestTuple<string>>({
            make_test<string>(
                "should fill genders",
                "no errors",
                make_tuple()),
        })
    ));
}
} // End namespace Test::Genders
