#define _XOPEN_SOURCE_EXTENDED
#include <iostream>
#include <cstdio>
#include <string>
#include <cstdint>
#include <vector>
#include "test.h"

// using namespace std;
using std::cout;
using std::tuple;
using std::wcerr;
using std::string;
using std::endl;
using std::pair;
using std::get;
using std::make_tuple;
using std::vector;
using Test::TestResults;
using std::optional;
using std::function;
using std::for_each;

// using namespace Test;

// size_t get_index_of(const string& text, const string& search, size_t start);
// string word_wrap(const string& text, int maxWidth);
// string get_substring(const string& text, int32_t var1, int32_t var2);
// string make_fit_l(const string& text, size_t length, char paddCh);
// string left(const string& text, size_t length);
// string string_dollar(size_t length, char ch);

// int main(int argc, char* argv[]) {
//     // TODO: Come up with a good way to enable/disable tests.
//     // Maybe replace the expected, params pairs with another tuple for enabled, expected, params.
//     // Maybe have the test functions take an enabled bool param.

//     setlocale(LC_ALL, "");

//     TestResults results;

//     string longText = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.";
//     results = results + Test::test_fn("get_index_of", get_index_of,
//         vector<pair<size_t, tuple<string, string, size_t>>>({
//         pair(22, make_tuple(longText, "dummy", 0)),
//         pair(-1, make_tuple(longText, "acid", 0)),
//         pair(120, make_tuple(longText, "dummy", 100)),
//         pair(-1, make_tuple(longText, "dummy", longText.size())),
//         pair(6, make_tuple("these are words", "are", 0)),
//         pair(4, make_tuple("one two one two", "two", 0)),
//         pair(12, make_tuple("one two one two", "two", 5)),
//     }));

//     results = results + test_fn("get_substring", get_substring, vector({
//         pair("234", make_tuple("1234567890", 1, 3)),
//         pair("Paris", make_tuple("Where is Paris?", 10-1, 5)),
//     }));

//     results = results + test_fn("left", left, vector({
//         pair("Micro", make_tuple("Microsoft QBasic", 5)),
//     }));

//     results = results + test_fn("make_fit_l", make_fit_l, vector({
//         pair("12___", make_tuple("12", 5, L'_')),
//     }));

//     results = results + test_fn("string_dollar", string_dollar, vector({
//         pair("AAAAA", make_tuple(5, L'A')),
//     }));

//     results = results + test_fn("word_wrap", word_wrap, vector({
//         pair("0123_", make_tuple("0123", 5)),
//         pair("01234", make_tuple("01234", 5)),
//         pair("01234\n5____", make_tuple("012345", 5)),
//         pair("01234\n56789\n0____", make_tuple("01234567890", 5)),
//         pair("01 23\n45 67\n89 01", make_tuple("01 23 45 67 89 01", 5)),
//         pair("01 34\n67 90\n23 56\n89___", make_tuple("01 34 67 90 23 56    89      ", 5)),
//     }));

//     cout << "Total tests ran: " << get<0>(results) << endl;
//     cout << "Total failures: " << get<1>(results) << endl;

//     return 0;
// }

// string word_wrap(const string& text, int maxWidth) {
//     string output = "";
//     string thisLine = "";
//     string nextChunk = "";
//     int32_t thisLineStartPosition = 0;
//     int32_t thisLineCurrentPosition = 0;
//     int32_t nextSpace = -1;
//     int32_t textLength = text.size();
//     size_t thisLineLength = 0;

//     bool done = false;

//     while (!done) {
//         nextSpace = get_index_of(text, " ", thisLineCurrentPosition);
//         if (nextSpace < 0) {
//             nextSpace = textLength;
//         }
//         nextChunk = get_substring(text, thisLineCurrentPosition, nextSpace - thisLineCurrentPosition);
//         auto nextChunkLength = nextChunk.size();
//         if (nextChunkLength > 0) {
//             auto needsSpace = thisLine.size() > 0;
//             if (needsSpace) {
//                 thisLine = thisLine + " ";
//             }
//             thisLineLength = thisLine.size();
//             if (nextChunkLength > maxWidth) {
//                 nextChunk = get_substring(text, thisLineCurrentPosition, maxWidth - thisLineLength);
//                 nextSpace = thisLineStartPosition + maxWidth;
//                 thisLine = thisLine + nextChunk;
//                 thisLineCurrentPosition = nextSpace;
//             } else if(thisLineLength + nextChunkLength > maxWidth) {
//                 thisLine = make_fit_l(thisLine, maxWidth, L' ');
//             } else {
//                 thisLine = thisLine + nextChunk;
//                 thisLineCurrentPosition = nextSpace + 1;
//             }
//             thisLineLength = thisLine.size();
//         } else {
//             thisLineCurrentPosition = nextSpace + 1;
//         }
//         if (thisLineLength >= maxWidth || thisLineCurrentPosition > textLength) {
//             if (thisLineCurrentPosition > textLength) {
//                 done = true;
//             }
//             thisLine = make_fit_l(thisLine, maxWidth, L'_');
//             output += thisLine + (done ? "" : "\n");
//             thisLine = "";
//             thisLineLength = thisLine.size();
//             thisLineStartPosition = thisLineCurrentPosition;
//         }
//     }

//     return output;
// }

// string string_dollar(size_t length, char ch) {
//     string str = "";
//     for (size_t i = 0; i<length; i++) {
//         str += ch;
//     }
//     return str;
// }

// string left(const string& text, size_t length) {
//     return text.substr(0, length);
// }

// string make_fit_l(const string& text, size_t length, char paddCh) {
//     return left(text + string_dollar(length, paddCh), length);
// }

// string get_substring(const string& text, const int32_t var1, const int32_t var2) {
//     return text.substr(std::min<int32_t>(var1, text.length()-1), std::max(var2, 0));
// }

// size_t get_index_of(const string& text, const string& search, size_t start) {
//     return text.find(search, start);
// }

namespace Test {
    const string fn1(const string& s, int l) {
        return s.substr(0, l);
    }
    
    // _Step_1
    // template<typename _T1, typename F, typename... T2>
    // TestResults test_fn(string test_name, F f, vector<pair<_T1, tuple<T2...>>> tests);
    // TestResults dummyTest(){
    //     return test_fn("/Dummy", [](int id){return id==0?"":"Unknown";}, vector({
    //         pair("", make_tuple(0)),
    //     }));
    // }

    // _Step_2
    // template<typename _T1, typename F, typename... T2>
    // TestResults test_fn(string test_name, F f, vector<tuple<_T1, tuple<T2...>>> tests);
    // TestResults dummyTest(){
    //     return test_fn("/Dummy", [](int id){return id==0?"":"Unknown";}, vector({
    //         make_tuple("", make_tuple(0)),
    //     }));
    // }

    // _Step_3
    // template<typename TResult, typename FnToTest, typename... TInputParams>
    // TestResults test_fn(string suite_label, FnToTest testFn, vector<tuple<TResult, tuple<TInputParams...>>> tests);
    // TestResults dummyTest() {
    //     return test_fn("/Dummy", [](int id){return id==0?"":"Unknown";}, vector({
    //         make_tuple("", make_tuple(0)),
    //     }));        
    // }

    // _Step_4
    // template<typename TResult, typename FnToTest, typename... TInputParams>
    // TestResults test_fn(string suite_label, FnToTest testFn, vector<tuple<string, TResult, tuple<TInputParams...>>> tests);
    // TestResults dummyTest() {
    //     return test_fn("/Dummy", [](int id){return id==0?"":"Unknown";}, vector({
    //         make_tuple((string)"", "", make_tuple(0)),
    //     }));        
    // }

    // _Step_5
    // auto testFunction = [](int id){return id==0?"":"";};
    // template<typename TResult, typename FnToTest, typename... TInputParams>
    // TestResults test_fn(string suite_label, FnToTest testFn, vector<tuple<string, TResult, tuple<TInputParams...>>> tests);
    // TestResults dummyTest() {
    //     return test_fn("/Dummy", testFunction, vector({
    //         make_tuple((string)"", "", make_tuple(0)),
    //     }));        
    // }

    // _Step_6
    // auto testFunction = [](int id){return id==0?"":"";};
    // auto compareFunction = [](string a, string b){return a==b;};
    // template<typename TResult, typename FnToTest, typename... TInputParams>
    // TestResults test_fn(
    //     string suite_label,
    //     FnToTest testFn,
    //     bool(*compare_function)(TResult a, TResult b),
    //     vector<tuple<string, TResult, tuple<TInputParams...>>> tests);
    // TestResults dummyTest() {
    //     return test_fn<string>(
    //         "/Dummy",
    //         testFunction,
    //         compareFunction,
    //         vector({
    //             make_tuple((string)"", (string)"", make_tuple(0)),
    //         }));        
    // }

    // _Step_7
    // auto testFunction = [](int id){return id==0?"":"";};
    // auto compareFunction = [](const string a, const string b){return a==b;};
    // template<typename TResult, typename FnToTest, typename... TInputParams>
    // TestResults test_fn(
    //     string suite_label,
    //     FnToTest testFn,
    //     bool(*compare_function)(TResult a, TResult b),
    //     vector<tuple<string, bool, TResult, tuple<TInputParams...>>> tests);
    // TestResults dummyTest() {
    //     // Parse argc/argv and return {0,0} if test is disabled.
    //     return test_fn<string>(
    //         // Suite Name
    //         "/Dummy",
    //         testFunction,
    //         compareFunction,
    //         vector({
    //             // Test Name, Expect Output, Inputs
    //             make_tuple((string)"", true, (string)"", make_tuple(0)),
    //         }));        
    // }

    // _Step_8 - Make compareFunction optional
    // Test lifecycle
    // suiteSetupFn(); - This is called to allocate any suite level resources. This is called once when the suite begins.
    // These functions may be called in parallel but execution will not proceed past this block until they have all finished.
    //   testSetupFn(); - This is called once for every test in tests. You may use it to allocate resources or setup mocks, stubs, and spies.
    //   testFn(...); - This is called once for every test to execute the test.
    //   Only one of these test functions will actually be run for each test in tests. They should return true if the test passed, return false if the test failed or there was an error, and be nullptr if they should be skipped. The executed function will be called with expectedOutput and the result of testFn(...). They can be used to test functions with side effects, especially void functions.
    //   maybe_compare_function; - This is the highest priority compare function. If it is not nullptr then it will be called.
    //   suite_compare_function; - This is the second highest priority compare function. If maybe_compare_function is nullptr and this is not nullptr then it will be called.
    //   [](TResult expected, TResult actual) { return expected, actual; } - This is the lowest priority compare function. If all other compare functions are nullptr then this will be called to evaluate the test.
    //   testTeardownFn(); - This is called once for every test in tests. You must free/release any resources allocated by testSetupFn.
    // This ends the parallel test functions section all tests will have completed before execution proceeds.
    // Collect reports - Ths step is not visible to the user at this point, but data returned by all of the test functions is collected here. This is where you will eventually be able to format/log data for reports.
    // suiteTeardownFn(); - This is called after all test calls have completed, all testTeardownFn calls have completed, and all test reports/logs have been written. You should free any resources allocated in suiteSetupFn.
    
    // TODO: Add TShared(*)(string /*test_name*/, UUID /*testRunId*/) allocateSharedData to the test tuple to make some shared data that can be used in a thread safe way by setup, teardown, and evaluate steps of the test.
    // TODO: Add TShared to be returned by the setup functions, and consumed by the evaluate and teardown functions.
    //   Suite setup/teardown functions should allocate/free.
    //   Test setup/teardown functions should consume the data allocated by Suite setup.
    //   Test setup functions may allocate additional resources. If they do then the allocated resources they should be freed by test teardown function.
    //   Suite and/or Test compare functions may consume this shared data, but it will not be shared with the execution of testFn.

    // This function is called to execute a test suite. You provide it with some configuration info, optional utility callback functions, and test data (input parameters for each call to testFn and the expected result). It returns a TestResults that should be treated as an opaque data type.
    // Not all parameters are named in code, but they are named and explained in the comments and will be described by those names below.
    //   string suite_label - This is the name of this test suite. It is used for reporting messages.
    //   FnToTest testFn - This is the function to test. This may be replaced if necessary by function. It may not currently support class methods, but that is planned.
    //   vector<tuple<...>> tests - This is the test run data. Each tuple in the vector is a single test run. It's members are explained below.
    //     string test_name - This is the name of this test. It is used for reporting messages.
    //     TResult expectedOutput - This is the expected result of executing this test.
    //     bool(*)(const TResult expected, const TResult actual) maybe_compare_function - This is optional. If unset or set to nullptr it is skipped. If set to a function it is called to evaluate the test results. It takes the expected and actual results as parameters and should return true if the test passed and false otherwise. This may be changed to return a TestResults at some point.
    //     void(*)(TInputParams...) testSetupFn - This is optional. If unset or set to nullptr it is skipped. If set to a function it is called before each test to setup the environment for the test. You may use it to allocate resources and setup mocks, stubs, and spies.
    //     void(*)(TInputParams...) testTeardownFn - This is optiona. If unset or set to nullptr it is skipped. If set to a function it is called after each test to cleanup the environment after the test. You should free resources allocated by testSetupFn.
    //     bool isEnabled - This is optional. If unset or set to true the test is run. If set to false this test is skipped. If skipped it will be reported as a skipped/disabled test.
    //   bool(*)(const TResult expected, const TResult actual) suite_compare_function - This is optional. If unset or set to nullptr it is skipped. If set to a function and maybe_compare_function is not called for a test run then this function is called to evaluate the test results. It takes the expected and actual results as parameters and should return true if the test passed and false otherwise. This may be changed to return a TestResults at some point.
    //   void(*)() suiteSetupFn - This is optional. If unset or set to nullptr it is skipped. If set to a function it is called before starting this test suite to setup the environment. You may use it to allocate resources and setup mocks, stubs, and spies.
    //   void(*)() suiteTeardownFn - This is optional. If unset or set to nullptr it is skipped. If set to a function it is called after all tests in this suite have finished and all reporting has finished. You should free resources allocated by suiteSetupFn.
    // This method should be called like so. This is the minimal call and omits all of the optional params. This is the most common usage. You should put one tuple of inputs and expected output for each test case.
    //   results = collect_and_report_TestResultstest_fn(
    //     "Test: functionUnderTest",
    //     functionUnderTest,
    //     vector({
    //       make_tuple(
    //         "ShouldReturnAppleForGroupId_1_and_ItemId_2",
    //         string("Apple"),
    //         make_tuple(1,2),
    //       ),
    //     }),
    //   );
    // The suites can be run from one file as such. From a file called ThingDoer_test.cpp to test the class/methods ThingDoer declared in ThingDoer.cpp. This isn't mandatory but is a best practice.
    // You can use testFn without calling collect_and_report_TestResults() and also could call it from a normal int main(int argc, char** argv) or other function.
    //   TestResults test_main_ThingDoer(int argc, char** argv) {
    //     TestResults results;
    //     results = collect_and_report_TestResults(results, testFn("doThing1", ...), argc, argv);
    //     results = collect_and_report_TestResults(results, testFn("doThing2", ...), argc, argv);
    //     return results;
    //   }
    // Then some test harness either generated or explicit can call test_main_ThingDoer(...) and optionally reported there. Reporting granularity is controlled by how frequently you call collect_and_report_TestResults(...).
    // You can combine test results with results = results + testFn(..); and then collect_and_report_TestResults on the aggregate TestResults value.
    // template<typename TResult, typename FnToTest, typename... TInputParams>
    // TestResults test_fn(
    //     string suite_label, /* suite_label - This is the name of the test suite. It will be used in logs. */
    //     FnToTest testFn, /* testFn - This is the function to be tested. It will be called with std::apply and the inputParams from each test in tests below. */
    //     vector<
    //         tuple<
    //             string /* test_name */,
    //             TResult /* expectedOutput */,
    //             tuple<TInputParams...> /* inputParams - The input parameters for this test. These will be used when calling std::apply with testFn to execute the test. */,
    //             bool(*)(const TResult expected, const TResult actual) /* maybe_compare_function - If this is not nullprt then this function will be called instead of suite_compare_function to determine if the test passes. Use this to check for side effects of the test. Return true if the test passes and false otherwise. */,
    //             void(*)(TInputParams...) /* testSetupFn - If this is not nullptr this function is called before each test to setup the environment. It is called with std::apply and inputParams so you can use them to mock records with specific IDs or calculate an expected result. */,
    //             void(*)(TInputParams...) /* testTeardownFn - If this is not nullptr this function is called after each test to cleanup any allocated/shared resources. */,
    //             bool /* testIsEnabled - If this is false the test, setup, and teardown functions are not run. */
    //         >  /* <no name> - This is the data and config functions for a specific test run. */
    //     > tests, /* tests - Each tuple in the vector is a test run with a name, enabledStatus, input, expected output, and optional compare, setup, and teardown functions. */
    //     bool(*suite_compare_function)(const TResult expected, const TResult actual) /* suite_compare_function used to compare*/,
    //     void(*suiteSetupFn)() /* suiteSetupFn called before running the test suite */,
    //     void(*suiteTeardownFn)() /* suiteTeardownFn called after all tests have run */,
    //     bool /* suiteIsEnabled - If this is false the entire test suite is skipped. The skipped tests will be reported as skipped/disabled. */
    // ) {
    //     return {0,0};
    // };
    // auto testFunction = [](int id){return (string)(id==0?"IS_ZERO":"IS_NOT_ZERO");};
    // auto compareFunction = [](const string a, const string b){return a==b;};
    // auto evaluateFunction = [](const string expected, const string actual){return expected==actual;};
    // auto suiteSetupFunction = [](){};
    // auto suiteTeardownFunction = [](){};
    // auto testSetupFunction = [](){};
    // auto testTeardownFunction = [](){};
    // TestResults doTestSuite() {
    //     return test_fn<string, string(*)(int), int>(
    //         (string)string("MyClass::MyMethod"),
    //         [](int id){return (string)string(id==0?"IS_ZERO":"IS_NOT_ZERO");},
    //         vector({
    //             make_tuple(
    //                 (string)string("ShouldReturn_IS_ZERO_for_id_0"),
    //                 (string)string("IS_ZERO"),
    //                 make_tuple(0),
    //                 [](const string left, const string right){return (bool)(left==right);},
    //                 [](int id){},
    //                 [](int id){},
    //                 true
    //             )
    //         }),
    //         [](const string left, const string right){return left==right;},
    //         [](int id){},
    //         [](int id){},
    //         true
    //     );
    // }

    // template<typename TResult, typename TFunctionToTest, typename... TInputParams>
    // TestResults test_fn(
    //     string suite_name,
    //     TFunctionToTest test_function,
    //     vector<
    //         TestTuple<TResult, TInputParams...>  /* <no name> - This is the data and config functions for a specific test run. */
    //     > tests,
    //     MaybeTestCompareFunction<TResult> suite_compare_function,
    //     MaybeTestConfigureFunction suite_before_each,
    //     MaybeTestConfigureFunction suite_after_each,
    //     bool is_enabled
    // );

    template <typename TResult, typename... TInputParams>
    TestResults execute_suite(
        string suite_label,
        function<TResult(TInputParams...)> function_to_test,
        vector<TestTuple<TResult, TInputParams...>> tests,
        MaybeTestCompareFunction<TResult> maybe_suite_compare_function,
        MaybeTestConfigureFunction maybe_suite_before_each_function,
        MaybeTestConfigureFunction maybe_suite_after_each_function,
        bool is_enabled) {
        TestResults results;
        cout << "🚀 Beginning Suite: " << suite_label << endl;

        // Step 1: Suite Setup

        if (maybe_suite_before_each_function.has_value()) {
            (*maybe_suite_before_each_function)();
        }

        // Step 2: Execute Tests
        for_each(tests.begin(), tests.end(), [&suite_label, &function_to_test, &results, &maybe_suite_compare_function](
            TestTuple<TResult, TInputParams...> test_data
        ) {
            // Step 2a: Extract our variables from the TestTuple.
            const std::string& test_name = get<0>(test_data);
            const std::string qualified_test_name = suite_label + "::" + test_name;
            const TResult& expected_output = get<1>(test_data);
            std::tuple<TInputParams...> input_params = get<2>(test_data);
            MaybeTestCompareFunction<TResult> maybe_compare_function = get<3>(test_data);
            TestCompareFunction<TResult> compare_function = maybe_compare_function.has_value()
            ? *maybe_compare_function
            : maybe_suite_compare_function.has_value()
            ? *maybe_suite_compare_function
            : [](const TResult& l, const TResult& r){return l==r;};
            MaybeTestConfigureFunction before_each = get<4>(test_data);
            MaybeTestConfigureFunction after_each = get<5>(test_data);

            // Step 2b: Test Setup
            cout << "  Beginning Test: " << qualified_test_name << endl;
            if(before_each.has_value()) {
                (*before_each)();
            }

            TResult actual;
            try {
                // Step 2c: Execute the test method.
                actual = std::apply(function_to_test, input_params);
            } catch(const std::exception& ex) {
                cout << "    ERROR: Caught exception \"" << ex.what() << "\"" << endl;
            } catch(const std::string& message) {
                cout << "    ERROR: Caught string \"" << message << "\"" << endl;
            } catch(...) {
                cout << "    ERROR: Caught something that is neither an std::exception nor a std::string." << endl;
            }

            // Step 2d: Pass or fail.
            TestResults result;
            if (compare_function(expected_output, actual)) {
                result = TestResults().pass();
                cout << "    PASSED" << endl;
            } else {
                result = TestResults().fail();
                cout << "    FAILED: expected: " << expected_output << ", actual: " << actual << endl;
            }
            results += result;

            // Step 2e: Test Teardown
            if (after_each.has_value()) {
                (*after_each)();
            }
            cout << "  Ending Test: " << test_name << endl;
        });

        // Step 3: Suite Teardown
        if (maybe_suite_after_each_function.has_value()) {
            (*maybe_suite_after_each_function)();
        }
        cout << "Ending Suite: " << suite_label << endl;
        return results;
    }

    

    // auto test_data9 = vector<tuple<
    //         string, string, tuple<const string&, int>,
    //         function<bool(const string&, const string&)>,
    //         function<void(const string&, int)>,
    //         function<void(const string&, int)>,
    //         bool
    // >>({

    // });
    // test_fn_9<string, const string&, int>(
    //     "",
    //     (function<string(const string&, int)>)fn1,
    //     test_data9
    // );
    


    //             string /* test_name */,
    //             TResult /* expectedOutput */,
    //             tuple<TInputParams...> /* inputParams - The input parameters for this test. These will be used when calling std::apply with testFn to execute the test. */,
    //             bool(*)(const TResult expected, const TResult actual) /* maybe_compare_function - If this is not nullprt then this function will be called instead of suite_compare_function to determine if the test passes. Use this to check for side effects of the test. Return true if the test passes and false otherwise. */,
    //             void(*)(TInputParams...) /* testSetupFn - If this is not nullptr this function is called before each test to setup the environment. It is called with std::apply and inputParams so you can use them to mock records with specific IDs or calculate an expected result. */,
    //             void(*)(TInputParams...) /* testTeardownFn - If this is not nullptr this function is called after each test to cleanup any allocated/shared resources. */,
    //             bool /* testIsEnabled - If this is false the test, setup, and teardown functions are not run. */
    
    //char pc3(function<bool(TInputParams...)> compare_function, TInputParams... input_params) {

    // template<typename T>
    // typedef function<bool(const T&, const T&)> compare_function2;

    TestResults do_the_other_thing(){
        auto p1 = "Microsoft QBasic";
        auto p2 = 5;
        // auto exp = "Micro";
        string s = fn1("Microsoft QBasic", 5);
        TestResults tr;

        // tr = tr + execute_suite<string, const string&, int>(
        //     "Test 8 Function",
        //     (function<string(const string&, int)>)fn1,
        //     vector<TestTuple<string, const string&, int>>({
        //     // vector<tuple<string, string, tuple<const string&, int>, MaybeTestCompareFunction<string>>>({
        //         make_tuple(
        //             string("should do something"), // test_name
        //             string("Micro"), // expectedOutput
        //             make_tuple((string)p1, p2),// inputParams,
        //             std::nullopt, // compare_function
        //             std::nullopt, // before_each
        //             std::nullopt, // after_each
        //             true
        //         ),
        //         make_test<string, string, int>(
        //             "should do something else",
        //             "Micro",
        //             make_tuple((string)p1, p2)
        //         )
        //     }));
        
        auto test_data8 = vector<TestTuple<string, const string&, int>>({
            make_test<string, string, int>(
                "Test 8 equals", "Micro", make_tuple((string)p1, p2),
                [](const string& l, const string& r){ return l==r;}),
            make_test<string, string, int>(
                "Test 8 not equals", "Micro", make_tuple((string)p1, p2),
                [](const string& l, const string& r){ return l!=r;}
            ),
            make_test<string, string, int>("Test 8 default compare", "Micro", make_tuple((string)p1, p2)),
            make_test<string, string, int>("Test 8 default compare", "Micro", make_tuple((string)p1, p2)),
            make_test<string, string, int>("Test 8 default compare", "Micro", make_tuple((string)p1, p2))
        });
        tr = tr + execute_suite<string, const string&, int>(
            "Test 8 Function with extra data",
            (function<string(const string&, int)>)fn1,
            test_data8
        );

        return tr;
    }
    //             void(*)(TInputParams...) /* testSetupFn - If this is not nullptr this function is called before each test to setup the environment. It is called with std::apply and inputParams so you can use them to mock records with specific IDs or calculate an expected result. */,
    //             void(*)(TInputParams...) /* testTeardownFn - If this is not nullptr this function is called after each test to cleanup any allocated/shared resources. */,
    //             bool /* testIsEnabled - If this is false the test, setup, and teardown functions are not run. */
    
    //     bool(*suite_compare_function)(const TResult expected, const TResult actual) /* suite_compare_function used to compare*/,
    //     void(*suiteSetupFn)() /* suiteSetupFn called before running the test suite */,
    //     void(*suiteTeardownFn)() /* suiteTeardownFn called after all tests have run */,
    //     bool /* suiteIsEnabled - If this is false the entire test suite is skipped. The skipped tests will be reported as skipped/disabled. */
    

    // template<typename TResult, typename... TInputParams>
    // TestResults test_fn(
    //     string suite_label, /* suite_label - This is the name of the test suite. It will be used in logs. */
    //     function<TResult(TInputParams...)> testFn, /* testFn - This is the function to be tested. It will be called with std::apply and the inputParams from each test in tests below. */
    //     vector<
    //         tuple<
    //             string /* test_name */,
    //             TResult /* expectedOutput */,
    //             tuple<TInputParams...> /* inputParams - The input parameters for this test. These will be used when calling std::apply with testFn to execute the test. */,
    //             bool(*)(const TResult expected, const TResult actual) /* maybe_compare_function - If this is not nullprt then this function will be called instead of suite_compare_function to determine if the test passes. Use this to check for side effects of the test. Return true if the test passes and false otherwise. */,
    //             void(*)(TInputParams...) /* testSetupFn - If this is not nullptr this function is called before each test to setup the environment. It is called with std::apply and inputParams so you can use them to mock records with specific IDs or calculate an expected result. */,
    //             void(*)(TInputParams...) /* testTeardownFn - If this is not nullptr this function is called after each test to cleanup any allocated/shared resources. */,
    //             bool /* testIsEnabled - If this is false the test, setup, and teardown functions are not run. */
    //         >  /* <no name> - This is the data and config functions for a specific test run. */
    //     > tests, /* tests - Each tuple in the vector is a test run with a name, enabledStatus, input, expected output, and optional compare, setup, and teardown functions. */
    //     bool(*suite_compare_function)(const TResult expected, const TResult actual) /* suite_compare_function used to compare*/,
    //     void(*suiteSetupFn)() /* suiteSetupFn called before running the test suite */,
    //     void(*suiteTeardownFn)() /* suiteTeardownFn called after all tests have run */,
    //     bool /* suiteIsEnabled - If this is false the entire test suite is skipped. The skipped tests will be reported as skipped/disabled. */
    // ) {
    //     return {0,0};
    // };
    // auto testFunction = [](int id){return (string)(id==0?"IS_ZERO":"IS_NOT_ZERO");};
    // auto compareFunction = [](const string a, const string b){return a==b;};
    // auto evaluateFunction = [](const string expected, const string actual){return expected==actual;};
    // auto suiteSetupFunction = [](){};
    // auto suiteTeardownFunction = [](){};
    // auto testSetupFunction = [](){};
    // auto testTeardownFunction = [](){};
    // TestResults doTestSuite() {
    //     return test_fn<string, string(*)(int), int>(
    //         (string)string("MyClass::MyMethod"),
    //         [](int id){return (string)string(id==0?"IS_ZERO":"IS_NOT_ZERO");},
    //         vector({
    //             make_tuple(
    //                 (string)string("ShouldReturn_IS_ZERO_for_id_0"),
    //                 (string)string("IS_ZERO"),
    //                 make_tuple(0),
    //                 [](const string left, const string right){return (bool)(left==right);},
    //                 [](int id){},
    //                 [](int id){},
    //                 true
    //             )
    //         }),
    //         [](const string left, const string right){return left==right;},
    //         [](int id){},
    //         [](int id){},
    //         true
    //     );
    // }





    // TestResults dummyTest() {
    //     // Parse argc/argv and return {0,0} if test is disabled.
    //     return test_fn<string>(
    //         // Suite Name
    //         "/Dummy",
    //         testFunction,
    //         vector({
    //             // Test Name, Expect Output, Inputs
    //             make_tuple((string)"", (string)"", make_tuple(0)),
    //         }),
    //         compareFunction
    //     );
    // }

    // test_fn(
    //     "Suite Name",
    //     [](){}, // test fn
    //     vector({
    //         make_tuple(
    //             "Test Name",
    //             "Expected Result", // TODO: find a way for this to work with void fn tests
    //             [](string expected, string actual){return true;} // Evaluate fn nullptr allowed and default
    //             [](){}, // Suite setup fn nullptr allowed and default
    //             [](){}, // Suite teardown fn nullptr allowed and default
    //             make_tuple(), // Input params
    //         ),
    //     }),
    //     [](string a, string b) {return a==b;},// compare fn nullptr allowed and default
    //     [](){}, // Suite setup fn nullprt allowed and default
    //     [](){}, // Suite teardown fn nullptr allowed and default
    // )

    // _Step_9 - if T2 is a single value then make_tuple<T2>(T2) and call longer version
    // auto testFunction = [](int id){return id==0?"":"";};
    // auto compareFunction = [](const string a, const string b){return a==b;};
    // template<typename TResult, typename FnToTest, typename... TInputParams>
    // TestResults test_fn(
    //     string suite_label,
    //     FnToTest testFn,
    //     vector<tuple<string, bool, TResult, tuple<TInputParams...>>> tests,
    //     bool(*compare_function)(TResult a, TResult b));
    // TestResults dummyTest() {
    //     // Parse argc/argv and return {0,0} if test is disabled.
    //     return test_fn<string>(
    //         // Suite Name
    //         "/Dummy",
    //         testFunction,
    //         vector({
    //             // Test Name, Expect Output, Inputs
    //             make_tuple((string)"", true, (string)"", make_tuple(0)),
    //         }),
    //         compareFunction
    //     );
    // }

    // _Step_10 - 

    // test_fn(string, _FnToTest, vector<tuple<string, _T1, _CompareFn, <tuple<_T2...>>>)
    //   Default to (string, _FnToTest, vector<tuple<"", _T1, [](a,b){return a==b;}, make_tuple())
    //   Also allow make_tuple(T2) if the last param is not a tuple.
    //bool(*compare_function)(_TResult, _TResult)


    
    // return test_fn(
    //     "/Dummy",
    //     [](int id){ if (id==0) {return "";} return "Unknown";},
    //     [](string a, string b){ return a == b; },
    //     vector({
    //         make_tuple("ShouldReturnEmptyStringForIdZero", "", make_tuple(0))
    //     })
    // );
    // return test_fn(
    //     "/Dummy",
    //     [](int id){ if (id==0) {return "";} return "Unknown";},
    //     [](string a, string b){ return a == b; },
    //     vector({
    //         make_tuple("ShouldReturnEmptyStringForIdZero", "", make_tuple(0))
    //     })
    // );
    // return test_fn(
    //     "/Dummy",
    //     [](){},
    //     [](string a, string b){ return a == b; },
    //     vector({
    //         make_tuple("ShouldReturnEmptyStringForIdZero", "", make_tuple(0))
    //     })
    // );


    // Call like this `auto results = test_fn("left", left, vector({pair("Micro", make_tuple("Microsoft QBasic", 5))}));`
    // template<typename _T1, typename F, typename... T2>
    // TestResults test_fn(string test_name, F f, vector<pair<_T1, tuple<T2...>>> tests) {
    //     size_t testsRun = 0;
    //     uint32_t failures = 0;
    //     cout << "Testing function " << test_name << endl;

    //     for_each(tests.begin(), tests.end(), [&testsRun, &failures, test_name, &f](pair<_T1, tuple<T2...>> data) {
    //         const auto& expected = data.first;
    //         const auto& actual = std::apply(f, data.second);
    //         testsRun++;
    //         cout << "Expected: " << expected << endl;
    //         cout << "Actual:   " << actual << endl;
    //         failures += do_pass_fail(expected == actual);
    //         if (expected!=actual) {
    //             wcerr << test_name << " failed for " << get<0>(data.second) << endl;
    //         }
    //     });

    //     cout << failures << " failures" << endl;
    //     return make_tuple(testsRun, failures);
    // }

    

    TestResults::TestResults()
    : failed_(0)
    , passed_(0)
    , skipped_(0)
    , total_(0) {}

    TestResults::TestResults(const TestResults& other)
    : failed_(other.failed_)
    , passed_(other.passed_)
    , skipped_(other.skipped_)
    , total_(other.total_) {}

    TestResults::TestResults(uint32_t failed, uint32_t passed, uint32_t skipped, uint32_t total)
    : failed_(failed)
    , passed_(passed)
    , skipped_(skipped)
    , total_(total) {}

    TestResults& TestResults::fail() {
        total_++;
        failed_++;
        return *this;
    }

    TestResults& TestResults::pass() {
        total_++;
        passed_++;
        return *this;
    }

    TestResults& TestResults::skip() {
        total_++;
        skipped_++;
        return *this;
    }

    uint32_t TestResults::failed() {
        return failed_;
    }

    uint32_t TestResults::passed() {
        return passed_;
    }

    uint32_t TestResults::skipped() {
        return skipped_;
    }

    uint32_t TestResults::total() {
        return total_;
    }

    TestResults TestResults::operator+(const TestResults& other) const {
        return TestResults(
            failed_ + other.failed_,
            passed_ + other.passed_,
            skipped_ + other.skipped_,
            total_ + other.total_);
    }

    TestResults& TestResults::operator+=(const TestResults& other) {
        failed_ += other.failed_;
        passed_ += other.passed_;
        skipped_ += other.skipped_;
        total_ += other.total_;
        return *this;
    }
} // End namespace Test
