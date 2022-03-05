#include"veiler/opaque_bool.hpp"
#include<cassert>

#define TEST(T, t, f){ \
  static constexpr T default0{}; \
  static constexpr T true0{true}; \
  static constexpr T false0{false}; \
  T true1; \
  true1 = t; \
  T false1; \
  false1 = f; \
  static_assert(true0 == t); \
  static_assert(false0 == f); \
  assert(true0 == true1); \
  assert(false0 == false1); \
  static_assert(true0 != false0); \
  static_assert(t); \
  static_assert(!f); \
  static_assert(t.get()); \
  static_assert(!f.get()); \
}

int main(){
  using ed = veiler::opaque_bool::enable_disable<struct ed_tag>;
  using yn = veiler::opaque_bool::yes_no<struct yn_tag>;
  using vi = veiler::opaque_bool::valid_invalid<struct vi_tag>;
  TEST(ed, ed::enable, ed::disable)
  TEST(yn, yn::yes, yn::no)
  TEST(vi, vi::valid, vi::invalid)
}
