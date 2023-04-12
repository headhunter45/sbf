## Why do I have to cast std::nullopt to a specific optional type when calling a templated function i.e.

```c++
template<typename T>
void DoSomething(std::optional<T> = std::nullopt, bool report_errors = false);
```

```text
DoSomething() works fine.
DoSomething(std::nullopt, true) no matching function for call to 'DoSomething' Do_Something<std::optional<string>, bool>(
```

## Which is uglier
```c++
(*after_each)()
after_each->operator()()
after_each.value()();
```
