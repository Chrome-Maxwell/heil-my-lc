# Keyword: constexpr(since C++11)
`constexpr` is used to indicate that the expression can be evaluated at the compile time. 

- `constexpr` variables: used on static data members, will generally inline the const data members. 
```cpp
class Solution
{
private:
    static constexpr int dy[] = {-1, 0, 1, 0};
    static constexpr int dx[] = {0, 1, 0, -1};
public:
    ...
}
```

- `constexpr` functions: TBD
  
> Read more: [cppReference](https://en.cppreference.com/w/cpp/language/constexpr)
