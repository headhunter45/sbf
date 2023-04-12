## test_fn implicit template values
### Error Message
test.cpp(350, 16): argument types are: (const wchar_t [18], lambda [](int id)->std::wstring, std::__1::vector<std::__1::tuple<const wchar_t *, const wchar_t *, std::__1::tuple<int>, lambda [](std::__1::wstring left, std::__1::wstring right)->bool, lambda [](int id)->void, lambda [](int id)->void, bool>, std::__1::allocator<std::__1::tuple<const wchar_t *, const wchar_t *, std::__1::tuple<int>, lambda [](std::__1::wstring left, std::__1::wstring right)->bool, lambda [](int id)->void, lambda [](int id)->void, bool>>>, lambda [](std::__1::wstring left, std::__1::wstring right)->bool, lambda [](int id)->void, lambda [](int id)->void, bool)
test_fn
+2 overloads

### Declaration
template<typename TResult, typename FnToTest, typename... TInputParams>
    test_method_result test_fn(
        wstring suiteName, /* suiteName - This is the name of the test suite. It will be used in logs. */
        FnToTest testFn, /* testFn - This is the function to be tested. It will be called with std::apply and the inputParams from each test in tests below. */
        vector<
            tuple<
                wstring /* testName */,
                TResult /* expectedOutput */,
                tuple<TInputParams...> /* inputParams - The input parameters for this test. These will be used when calling std::apply with testFn to execute the test. */,
                bool(*)(const TResult expected, const TResult actual) /* testCompareFn - If this is not nullprt then this function will be called instead of suiteCompareFn to determine if the test passes. Use this to check for side effects of the test. Return true if the test passes and false otherwise. */,
                void(*)(TInputParams...) /* testSetupFn - If this is not nullptr this function is called before each test to setup the environment. It is called with std::apply and inputParams so you can use them to mock records with specific IDs or calculate an expected result. */,
                void(*)(TInputParams...) /* testTeardownFn - If this is not nullptr this function is called after each test to cleanup any allocated/shared resources. */,
                bool /* testIsEnabled - If this is false the test, setup, and teardown functions are not run. */
            >  /* <no name> - This is the data and config functions for a specific test run. */
        > tests, /* tests - Each tuple in the vector is a test run with a name, enabledStatus, input, expected output, and optional compare, setup, and teardown functions. */
        bool(*suiteCompareFn)(TResult a, TResult b) /* suiteCompareFn used to compare*/,
        void(*suiteSetupFn)() /* suiteSetupFn called before running the test suite */,
        void(*suiteTeardownFn)() /* suiteTeardownFn called after all tests have run */,
        bool /* suiteIsEnabled - If this is false the entire test suite is skipped. The skipped tests will be reported as skipped/disabled. */
    );

### For SO post
(
    const wchar_t [18],
    lambda [](int id)->std::wstring,
    std::vector<
        std::tuple<
            const wchar_t *,
            const wchar_t *,
            std::tuple<int>,
            lambda [](std::wstring left, std::wstring right)->bool,
            lambda [](int id)->void,
            lambda [](int id)->void,
            bool
        >,
        std::allocator<
            std::tuple<
                const wchar_t *,
                const wchar_t *,
                std::tuple<int>,
                lambda [](std::wstring left, std::wstring right)->bool,
                lambda [](int id)->void,
                lambda [](int id)->void,
                bool
            >
        >
    >,
    lambda [](std::wstring left, std::wstring right)->bool,
    lambda [](int id)->void,
    lambda [](int id)->void,
    bool
)

template<typename TResult, typename FnToTest, typename... TInputParams>
test_method_result test_fn(
    wstring suiteName,
    FnToTest testFn,
    vector<
        tuple<
            wstring,
            TResult,
            tuple<TInputParams...>,
            bool(*)(const TResult expected, const TResult actual),
            void(*)(TInputParams...),
            void(*)(TInputParams...),
            bool
        >
    > tests,
    bool(*suiteCompareFn)(TResult a, TResult b),
    void(*suiteSetupFn)(),
    void(*suiteTeardownFn)(),
    bool
);

### For SO Post v2
(
    const wchar_t [18],                 // const wchar_t* suiteName             // Literal wstring
    lambda [](int id)->std::wstring,    // wstring(*)(int id) testFn            //
    std::vector<                        // Begin vector<...> tests              //
        std::tuple<                     //   Begin tuple<...> a test            //
            const wchar_t *,            //     const wchar_t* testName          // Literal const wchar_t*
            const wchar_t *,            //     const wchar_t* expected          // Literal const wchar_t*
            std::tuple<int>,            //     tuple<int> inputParams           // int id
            lambda [](std::wstring left, std::wstring right)->bool,     // bool(*)(const wstring expected, const wstring actual) compareFn  // dummy equals fn
            lambda [](int id)->void,    //      void(*)(int id) testSetupFn     // dummy fn
            lambda [](int id)->void,    //      void(*)(int id) testTeardownFn  // dummy fn
            bool                        //      bool testIsEnabled              // true
        >,                              //   End tuple<...> test                //
        std::allocator<                 //   Begin skipping allocator           //
            std::tuple<
                const wchar_t *,
                const wchar_t *,
                std::tuple<int>,
                lambda [](std::wstring left, std::wstring right)->bool,
                lambda [](int id)->void,
                lambda [](int id)->void,
                bool
            >
        >                               //   End skipping allocator             //
    >,                                  // End vector<...> tests
    lambda [](std::wstring left, std::wstring right)->bool,             // bool(*)()    // dummy equals fn
    lambda [](int id)->void,            // void(*)(int id)                      // dummy fn
    lambda [](int id)->void,            // void(*)(int di)                      // dummy fn
    bool                                //  bool suiteIsEnabled                 // true
)

template<typename TResult, typename FnToTest, typename... TInputParams>
test_method_result test_fn(
    wstring suiteName,                  // wstring suiteName
    FnToTest testFn,                    // FnToTest testName
    vector<                             // Begin vector<...> tests
        tuple<                          //   Begin tuple<...> a test
            wstring,                    //     wstring testName
            TResult,                    //     TResult expectedResult
            tuple<TInputParams...>,     //     tuple<TInputParams...> inputParams
            bool(*)(const TResult expected, const TResult actual),      // bool(*)(const TResult expected, const TResult actual) testCompareFn
            void(*)(TInputParams...),   //     void(*)(TInputParams...) testSetupFn
            void(*)(TInputParams...),   //     void(*)(TInputParams...) testTeardownFn
            bool                        //     bool isTestEnabled
        >                               //   End tuple<...> a test
    > tests,                            // End vector<...> tests
    bool(*suiteCompareFn)(TResult a, TResult b),                         // bool(*)(TResult a, TResult b) suiteCompareFn
    void(*suiteSetupFn)(),              // void(*)() suiteSetupFn
    void(*suiteTeardownFn)(),           // void(*)() suiteTeardownFn
    bool                                // bool isSuiteEnabled
);

### For SO Post v3
### Scratch
(
    const wchar_t [18],                 // const wchar_t* suiteName             // Literal wstring
    lambda [](int id)->std::wstring,    // wstring(*)(int id) testFn            // (wstring)(*)(int id) testFn
    std::vector<                        // Begin vector<...> tests              //
        std::tuple<                     //   Begin tuple<...> a test            //
            const wchar_t *,            //     const wchar_t* testName          // Literal const wchar_t*
            const wchar_t *,            //     const wchar_t* expected          // Literal const wchar_t*
            std::tuple<int>,            //     tuple<int> inputParams           // int id
            lambda [](std::wstring left, std::wstring right)->bool,     // bool(*)(const wstring expected, const wstring actual) compareFn  // dummy equals fn
            lambda [](int id)->void,    //      void(*)(int id) testSetupFn     // dummy fn
            lambda [](int id)->void,    //      void(*)(int id) testTeardownFn  // dummy fn
            bool                        //      bool testIsEnabled              // true
        >,                              //   End tuple<...> test                //
        std::allocator<...>             //   Skipping allocator                 //
    >,                                  // End vector<...> tests
    lambda [](std::wstring left, std::wstring right)->bool,             // bool(*)()    // dummy equals fn
    lambda [](int id)->void,            // void(*)(int id)                      // dummy fn
    lambda [](int id)->void,            // void(*)(int di)                      // dummy fn
    bool                                //  bool suiteIsEnabled                 // true
)

template<typename TResult, typename FnToTest, typename... TInputParams>
test_method_result test_fn(
    wstring suiteName,                  // wstring suiteName
    FnToTest testFn,                    // FnToTest testName
    vector<                             // Begin vector<...> tests
        tuple<                          //   Begin tuple<...> a test
            wstring,                    //     wstring testName
            TResult,                    //     TResult expectedResult
            tuple<TInputParams...>,     //     tuple<TInputParams...> inputParams
            bool(*)(const TResult expected, const TResult actual),      // bool(*)(const TResult expected, const TResult actual) testCompareFn
            void(*)(TInputParams...),   //     void(*)(TInputParams...) testSetupFn
            void(*)(TInputParams...),   //     void(*)(TInputParams...) testTeardownFn
            bool                        //     bool isTestEnabled
        >                               //   End tuple<...> a test
    > tests,                            // End vector<...> tests
    bool(*suiteCompareFn)(TResult a, TResult b),                         // bool(*)(TResult a, TResult b) suiteCompareFn
    void(*suiteSetupFn)(),              // void(*)() suiteSetupFn
    void(*suiteTeardownFn)(),           // void(*)() suiteTeardownFn
    bool                                // bool isSuiteEnabled
);

### For SO Post v4
### Scratch
(
    (wstring)const wchar_t [18],        // wstring suiteName                    // Literal wstring
    lambda [](int id)->std::wstring,    // wstring(*)(int id) testFn            // (wstring)(*)(int id) testFn
    std::vector<                        // Begin vector<...> tests              //
        std::tuple<                     //   Begin tuple<...> a test            //
            const wchar_t *,            //     const wchar_t* testName          // Literal const wchar_t*
            const wchar_t *,            //     const wchar_t* expected          // Literal const wchar_t*
            std::tuple<int>,            //     tuple<int> inputParams           // int id
            lambda [](std::wstring left, std::wstring right)->bool,     // bool(*)(const wstring expected, const wstring actual) compareFn  // dummy equals fn
            lambda [](int id)->void,    //      void(*)(int id) testSetupFn     // dummy fn
            lambda [](int id)->void,    //      void(*)(int id) testTeardownFn  // dummy fn
            bool                        //      bool testIsEnabled              // true
        >,                              //   End tuple<...> test                //
        std::allocator<...>             //   Skipping allocator                 //
    >,                                  // End vector<...> tests
    lambda [](std::wstring left, std::wstring right)->bool,             // bool(*)()    // dummy equals fn
    lambda [](int id)->void,            // void(*)(int id)                      // dummy fn
    lambda [](int id)->void,            // void(*)(int di)                      // dummy fn
    bool                                //  bool suiteIsEnabled                 // true
)

template<typename TResult, typename FnToTest, typename... TInputParams>
test_method_result test_fn(
    wstring suiteName,                  // wstring suiteName
    FnToTest testFn,                    // FnToTest testName
    vector<                             // Begin vector<...> tests
        tuple<                          //   Begin tuple<...> a test
            wstring,                    //     wstring testName
            TResult,                    //     TResult expectedResult
            tuple<TInputParams...>,     //     tuple<TInputParams...> inputParams
            bool(*)(const TResult expected, const TResult actual),      // bool(*)(const TResult expected, const TResult actual) testCompareFn
            void(*)(TInputParams...),   //     void(*)(TInputParams...) testSetupFn
            void(*)(TInputParams...),   //     void(*)(TInputParams...) testTeardownFn
            bool                        //     bool isTestEnabled
        >                               //   End tuple<...> a test
    > tests,                            // End vector<...> tests
    bool(*suiteCompareFn)(TResult a, TResult b),                         // bool(*)(TResult a, TResult b) suiteCompareFn
    void(*suiteSetupFn)(),              // void(*)() suiteSetupFn
    void(*suiteTeardownFn)(),           // void(*)() suiteTeardownFn
    bool                                // bool isSuiteEnabled
);

```c++
typedef FnTotest wstring(*)(int id);
typedef TResult wstring;
typedef TInputParams int;
(
    wstring,                                                // wstring suiteName                                        // wstring suiteName                                    // (wstring)L"MyClass::MyMethod"
    lambda [](int id)->wstring,                             // wstring(*)(int id) testFn                                // FnToTest testFn                                      // [](int id){return (wstring)(id==0?L"IS_ZERO":L"IS_NOT_ZERO");}
    vector<                                                 // Begin vector<...> tests                                  // vector<                                              // vector({
        tuple<                                              //   Begin tuple<...> a test                                //   tuple<                                             //   make_tuple(
            basic_string<wchar_t...>,                       //     basic_string<...> testName                           //     wstring testName                                 //     (wstring)L"ShouldReturn_IS_ZERO_for_id_0"
            basic_string<wchar_t...>,                       //     basic_string<...> expectedResult                     //     TResult expectedResult                           //     (wstring)L"IS_ZERO"
            tuple<int>,                                     //     tuple<int> inputParams                               //     tuple<TInputParams...>                           //     make_tuple(0)
            lambda [](wstring left, wstring right)->bool,   //     bool(*)(wstring left, wstring right) testCompareFn   //     bool(*)(const TResult expected, TResult actual)  //     [](wstring left, wstring right){return left==right;}
            lambda [](int id)->void,                        //     void(*)(int id) testSetupFn                          //     void(*)(int id) testSetupFn                      //     []()(int id)[] dummy function
            lambda [](int id)->void,                        //     void(*)(int id) testSetupFn                          //     void(*)(int id) testTeardownFn                   //     []()(int id)[] dummy function
            bool                                            //     bool isTestEnabled                                   //     bool isTestEnabled                               //     true
        >,                                                  //   End tuple<...> a test                                  //   > a test                                           //   )
        allocator<>                                         //   Skipping allocator                                     //
    >,                                                      // End vector<...> tests                                    // > tests                                              // })
    lambda [](wstring left, wstring right)->bool,           // bool(*)(wstring left, wstring right) suiteCompareFn      // bool(*)(TResult a, TResult b) suiteCompareFn         //     [](wstring left, wstring right){return left==right;}
    lambda [](int id)->void,                                // void(*)(int id) suiteSetupFn                             // void(*)(int id) suiteSetupFn                         // [](int id){} dummy function
    lambda [](int id)->void,                                // void(*)(int id) suiteTeardownFn                          // void(*)(int id) suiteTeardownFn                      // [](int id){} dummy function
    bool                                                    // bool isSuiteEnabled                                      // bool isSuiteEnabled                                  // true
)
```
TResult basic_string<...>, wstring /* const TResult */, wstring


test.cpp(350, 16): argument types are: (wstring, lambda [](int id)->wstring, vector<tuple<basic_string<wchar_t, char_traits<wchar_t>, allocator<wchar_t>>, basic_string<wchar_t, char_traits<wchar_t>, allocator<wchar_t>>, tuple<int>, lambda [](wstring left, wstring right)->bool, lambda [](int id)->void, lambda [](int id)->void, bool>, allocator<tuple<basic_string<wchar_t, char_traits<wchar_t>, allocator<wchar_t>>, basic_string<wchar_t, char_traits<wchar_t>, allocator<wchar_t>>, tuple<int>, lambda [](wstring left, wstring right)->bool, lambda [](int id)->void, lambda [](int id)->void, bool>>>, lambda [](wstring left, wstring right)->bool, lambda [](int id)->void, lambda [](int id)->void, bool)




instance of constructor "
std::__1::vector<_Tp, _Allocator>::vector
[with
    _Tp=std::__1::tuple<
        std::__1::wstring,
        std::__1::wstring,
        std::__1::tuple<
            const std::__1::wstring &, int
        >
    >,
    _Allocator=std::__1::function<bool (const std::__1::wstring &, const std::__1::wstring &)>
]" matches the argument listC/C++(289)
test.cpp(667, 13): argument types are: ({...})
class std::__1::vector<
    std::__1::tuple<
        std::__1::wstring,
        std::__1::wstring,
        std::__1::tuple<const std::__1::wstring &, int>
    >,
    std::__1::function<bool (const std::__1::wstring &, const std::__1::wstring &)>
>