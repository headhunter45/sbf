#ifndef TEST_H__
#define TEST_H__
#include <cstdint>
#include <tuple>
#include <utility>
#include <string>

namespace Test {
    using std::tuple;
    using std::pair;
    using std::vector;
    using std::wstring;

    typedef tuple<size_t, uint32_t> test_method_result;

    void do_pass_fail(bool passed, uint32_t& failureCount);
    uint32_t do_pass_fail(bool passed);
    template<typename _T1, typename F, typename... T2>
    test_method_result test_fn(wstring testName, F f, vector<pair<_T1, tuple<T2...>>> tests);
    test_method_result operator+(const test_method_result& first, const test_method_result second);
    // TODO: define operator<< for std::tuple
    // TODO: Define operator+= for test_method_result
} // End namespace Test
#endif // End !defined TEST_H__
