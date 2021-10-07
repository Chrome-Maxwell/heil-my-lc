# Structured Bindings(since C++17)
Is a new feature for simpler unpacking structures. Mostly used on binding array-like or tuple-like types. Example usage:
- Bind built-in arrays
```cpp
int a[2] = {1,2};
 
auto [x,y] = a; // creates e[2], copies a into e, then x refers to e[0], y refers to e[1]
auto& [xr, yr] = a; // xr refers to a[0], yr refers to a[1]
```
- Bind tuples and C++ structs
```cpp
float x{};
char  y{};
int   z{};
std::tuple<float&,char&&,int> tpl(x,std::move(y),z);
const auto& [a,b,c] = tpl;
// a names a structured binding that refers to x; decltype(a) is float&
// b names a structured binding that refers to y; decltype(b) is char&&
// c names a structured binding that refers to the 3rd element of tpl; decltype(c) is const int

#include <iostream>
struct S {
    mutable int x1 : 2;
    volatile double y1;
};
S f() { return S{1, 2.3}; }
int main() {
    const auto [x, y] = f();  // x is an int lvalue identifying the 2-bit bit field
                              // y is a const volatile double lvalue
    std::cout << x << ' ' << y << '\n';  // 1 2.3
    x = -2;   // OK
//  y = -2.;  // Error: y is const-qualified
    std::cout << x << ' ' << y << '\n';  // -2 2.3
}
```

> Read more: [cppRef](https://en.cppreference.com/w/cpp/language/structured_binding)