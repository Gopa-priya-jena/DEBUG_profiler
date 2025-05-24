#pragma once
#include <FORMATTER/Formatter.hpp>
namespace DEBUG_profiler {

class Color_format : public Formatter {
  std::string Time_format(const TIME time);
  std::string Location_format(const Source_Loc loc);
  std::string F_arg_format(const std::vector<std::string_view> &Args_name,
                           const std::vector<std::string> &Arg_data);

  std::string level_fmt(const log_level lvl);
  std::string current_time_fmt(
      const std::chrono::zoned_time<std::chrono::system_clock::duration> time);
  std::string trace_fmt(const std::stacktrace &stack_trace);
  void BIN_dump(const std::uint8_t *ptr, const std::uint64_t size,
                Stream *stream);

  void HEX_dump(const std::uint8_t *ptr, const std::uint64_t size,
                Stream *stream);
  void OCTAL_dump(const std::uint8_t *ptr, const std::uint64_t size,
                  Stream *stream);
  void STRING_dump(const std::uint8_t *ptr, const std::uint64_t size,
                   Stream *stream);
  void DECIMAL_dump(const std::uint8_t *ptr, const std::uint64_t size,
                    Stream *stream);

public:
  std::string log_fmt(
      const log_level level, const TIME e_time,
      const std::chrono::zoned_time<std::chrono::system_clock::duration> time,
      const std::string_view data);
  std::string log_fmt(
      const log_level lvl, const TIME e_time,
      const std::chrono::zoned_time<std::chrono::system_clock::duration> time,
      const Source_Loc loc, const std::string_view data);

  std::string trace_fmt(
      const Source_Loc loc, const TIME e_time,
      const std::chrono::zoned_time<std::chrono::system_clock::duration> time,
      const std::vector<std::string_view> &Args_name,
      const std::vector<std::string> &Arg_data);
  std::string trace_fmt(
      const Source_Loc loc, const TIME e_time,
      const std::chrono::zoned_time<std::chrono::system_clock::duration> time);
  std::string stack_trace_fmt(
      const std::stacktrace &str, const TIME e_time,
      const std::chrono::zoned_time<std::chrono::system_clock::duration> time);
  void mem_view(
      const TIME e_time,
      const std::chrono::zoned_time<std::chrono::system_clock::duration> time,
      const Source_Loc Loc, std::uint8_t view, const std::string_view var_name,
      const std::uint8_t *ptr, const std::uint64_t size, Stream *stream);
};
} // namespace DEBUG_profiler
