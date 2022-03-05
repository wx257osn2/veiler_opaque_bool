# Veiler.OpaqueBool

This header only library provides strong typedef for `bool` .
This library is inspired by [`siv::YesNo`](https://github.com/Reputeless/YesNo) .

It requires C++20 supported compiler.

## What's difference from `siv::YesNo` ?

`siv::YesNo` provides the named constants `Yes` and `No` .
Veiler.OpaqueBool allows to select the pair of named constants from `yes` / `no` , `enable` / `disable` , and `valid` / `invlaid` .
And if you want to use other names, you can change them.

## Usage

```cpp
#include"veiler/opaque_bool.hpp"

using feature = veiler::opaque_bool::enable_disable<struct feature_tag>;

template<typename T>
struct feeling_base{
  static constexpr T good{true};
  static constexpr T bad{false};
};

using feeling = veiler::opaque_bool::opaque_bool<struct feeling_tag, feeling_base>;

constexpr feeling my_feeling(feature cxx20){
  return cxx20 ? feeling::good : feeling::bad;
}

int main(){
  static constexpr auto feeling_if_cxx20_enabled = my_feeling(feature::enable);
  static_assert(feeling_if_cxx20_enabled == feeling::good);
  static constexpr auto feeling_if_cxx20_disabled = my_feeling(feature::disable);
  static_assert(feeling_if_cxx20_disabled == feeling::bad);
}
```

## License

Boost Software License Version 1.0
