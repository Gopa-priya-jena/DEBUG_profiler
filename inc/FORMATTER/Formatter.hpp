#pragma once
#include <Logger_info.hpp>
#include <chrono>
#include <stacktrace>
#include <string>
#include <string_view>
#include <vector>

namespace DEBUG_profiler {

class Stream;
class Formatter {
public:
  virtual std::string log_fmt(
      const log_level level, const TIME e_time,
      const std::chrono::zoned_time<std::chrono::system_clock::duration> time,
      const std::string_view Data) = 0;
  virtual std::string log_fmt(
      const log_level lvl, const TIME e_time,
      const std::chrono::zoned_time<std::chrono::system_clock::duration> time,
      const Source_Loc loc, const std::string_view data) = 0;

  virtual std::string trace_fmt(
      const Source_Loc loc, const TIME e_time,
      const std::chrono::zoned_time<std::chrono::system_clock::duration> time,
      const std::vector<std::string_view> &Args_name,
      const std::vector<std::string> &Arg_data) = 0;
  virtual std::string
  trace_fmt(const Source_Loc loc, const TIME e_time,
            const std::chrono::zoned_time<std::chrono::system_clock::duration>
                time) = 0;
  virtual std::string stack_trace_fmt(
      const std::stacktrace &str, const TIME e_time,
      const std::chrono::zoned_time<std::chrono::system_clock::duration>
          time) = 0;

  virtual void mem_view(
      const TIME e_time,
      const std::chrono::zoned_time<std::chrono::system_clock::duration> time,
      const Source_Loc Loc, std::uint8_t view, const std::string_view var_name,
      const std::uint8_t *ptr, const std::uint64_t size, Stream *stream) = 0;
};
} // namespace DEBUG_profiler
