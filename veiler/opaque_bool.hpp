#ifndef VEILER_OPAQUE_BOOL_HPP_INCLUDED_
#define VEILER_OPAQUE_BOOL_HPP_INCLUDED_

namespace veiler::opaque_bool{

namespace named_constants{

template<typename T>
struct enable_disable{
  static constexpr T enable{true};
  static constexpr T disable{false};
};

template<typename T>
struct yes_no{
  static constexpr T yes{true};
  static constexpr T no{false};
};

template<typename T>
struct valid_invalid{
  static constexpr T valid{true};
  static constexpr T invalid{false};
};

}

template<typename Tag, template<typename>typename NamedConstants>
class opaque_bool : public NamedConstants<opaque_bool<Tag, NamedConstants>>{
  bool value;
 public:
  [[nodiscard]] constexpr opaque_bool()noexcept = default;
  [[nodiscard]] constexpr explicit opaque_bool(bool b)noexcept:value{b}{}
  [[nodiscard]] constexpr opaque_bool(const opaque_bool&)noexcept = default;
  [[nodiscard]] constexpr opaque_bool(opaque_bool&&)noexcept = default;
  constexpr opaque_bool& operator=(const opaque_bool&)noexcept = default;
  constexpr opaque_bool& operator=(opaque_bool&&)noexcept = default;
  [[nodiscard]] constexpr explicit operator bool()const noexcept{return value;}
  [[nodiscard]] constexpr bool get()const noexcept{return value;}
  [[nodiscard]] constexpr bool operator==(const opaque_bool&)const noexcept = default;
};

template<typename T>
using enable_disable = opaque_bool<T, named_constants::enable_disable>;

template<typename T>
using yes_no = opaque_bool<T, named_constants::yes_no>;

template<typename T>
using valid_invalid = opaque_bool<T, named_constants::valid_invalid>;

}//namespace veiler::opaque_bool

#endif//VEILER_OPAQUE_BOOL_HPP_INCLUDED_
