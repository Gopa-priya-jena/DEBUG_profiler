#pragma once
#include <format>
#include <string_view>
namespace DEBUG_profiler {

struct color {
  std::uint8_t R;
  std::uint8_t G;
  std::uint8_t B;
};

template <size_t N> struct StringLiteral {
  consteval StringLiteral(const char (&str)[N]) {
    for (size_t i = 0; i < N; ++i) {
      value[i] = str[i];
    }
  }
  char value[N];
};

template <StringLiteral start = "", StringLiteral end = "",
          StringLiteral middle = "">
class Custom_delimiters {

  // const char *_s{&start}, _e{&end}, _m{&middle};

  std::string_view starting = start.value; // start.value;
  std::string_view ending = end.value;     // end.value;
  std::string_view centre = middle.value;  // middle.value;

public:
  std::string format(std::string_view Str) const {
    return std::format("{}{}{}", starting, Str, ending);
  }

  auto format(std::string_view Str1, std::string_view Str2) const {

    return std::format("{}{}{}{}{}", starting, Str1, centre, Str2, ending);
  }

  auto format(std::string_view Str1, std::string_view Str2,
              std::string_view Str3) const {

    return std::format("{}{}{}{}{}{}{}", starting, Str1, centre, Str2, centre,
                       Str3, ending);
  }

  auto format(color c) const {

    return std::format("{}{};{};{}{}", starting, c.R, c.G, c.B, ending);
  }
};
} // namespace DEBUG_profiler
