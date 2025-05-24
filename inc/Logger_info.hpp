#pragma once

#include <FORMATTER/ansi.hpp>
#include <FORMATTER/colors.hpp>
#include <array>
#include <string_view>

namespace DEBUG_profiler {

struct log_info {
  std::string_view symbol;
  std::string_view name;
  color fg, bg;
};

enum class log_level : std::uint8_t {
  NORMAL = 0,
  TRACE = 1,
  DEBUGGING = 2,
  INFO = 3,
  WARN = 4,
  ERROR_ = 5,
  CRITICAL = 6,
};
enum MEM_VIEW : std::uint8_t {
  HEX = 1 << 0,
  BINARY = 1 << 1,
  DECIMAL = 1 << 2,
  OCTAL = 1 << 3,
  STRING = 1 << 4,
  NONE = 0,
  ALL = 0x1F,

};
inline constexpr log_info Level_info[7]{
    //           Text       Foreground Color Background Color
    {" \xF0\x9F\x96\x85 ", " NORMAL ", GREEN,
     DEFAULT_BG}, // Normal messages, less prominent
    {" \xF0\x9F\x9E\x8B ", " TRACE ", BLUE,
     DEFAULT_BG}, // Detailed trace information
    {" \xF0\x9F\x90\x9E ", " DEBUG ", CYAN,
     DEFAULT_BG}, // Debugging information
    {" \xF0\x9F\x9B\x88 ", " INFO ", GREEN,
     DEFAULT_BG}, // General informational messages
    {" \xE2\x9A\xA0 ", " WARN ", YELLOW, DEFAULT_BG}, // Warning situations
    {" \xE2\x83\xA0 ", " ERROR ", RED, DEFAULT_BG},   // Error conditions
    {" \xE2\x98\xA0 ", " CRITICAL ", RED,
     WHITE}, // Critical errors (White text on Red background)
};
inline constexpr std::array<const std::string_view, 7> Weekend = {
    "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
inline constexpr std::array<const std::string_view, 12> Month{
    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

struct TIME {
  std::uint8_t hour, min, sec, milli, micro, nano; // high precision time
};

struct Source_Loc {
  std::string_view file_name;
  std::uint16_t line;
  std::string_view function_name;
};

struct VAR_info {
  std::string_view name;
  std::uint8_t *ptr;
  std::size_t var_size;
};
} // namespace DEBUG_profiler
