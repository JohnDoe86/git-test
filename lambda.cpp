#include <cstdint>
#include <functional>
std::function<std::int32_t()> f()
{
    std::int32_t i = 12;
    return ([&i]() -> std::int32_t
            {
    i = 100;
    return i; });
    // Non-compliant
}
std::function<std::int32_t()> g()
{

    std::int32_t i = 12;
    return ([i]() mutable -> std::int32_t
            { return ++i; });
    // Compliant
}

void fn()
{

    auto lambda1 = f();
    std::int32_t i = lambda1();
    // Undefined behavior
    auto lambda2 = g();
    i = lambda2();
    // lambda2() returns 13
}

int main()
{
    fn();
    return 0;
}