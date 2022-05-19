#include <vector>

void fun(std::vector<int>& t)
{
   auto f = [](auto const& a){
       return ([&a](int b){
           return a>b?a:b;
       });
   };
}


#include <utility>
#include <iostream>
template<class F> decltype(auto) invoke(F&& fn) {
    return std::forward<F>(fn)();
}
int main() {
    std::cout << "Yes, I exist." << std::endl;
    auto n = 0;
    return invoke([&] {
        return n;
    });
}

#include <utility>
#include <iostream>

template<class F> decltype(auto) invoke(F&& fn) {
    return std::forward<F>(fn)();
}

int main() {
    auto n = 0;
    // cert_exp61_cpp_violation: Returning lambda object "main::[lambda() (instance 1)](n)" which captures object by reference directly by return statement.
    return invoke([&] { // fpdefect
        return n;
    });
}