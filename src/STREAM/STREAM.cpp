#include <STREAM/STREAM.hpp>

#include "FORMATTER/Formatter.hpp"
namespace DEBUG_profiler {

void Stream::set_formatter(Formatter &formatter) { fmt = &formatter; }

void Stream::LOG(
    const log_level level, const TIME e_time,
    const std::chrono::zoned_time<std::chrono::system_clock::duration> time,
    const Source_Loc Loc, const std::string_view data) {

  this->DefaultStream(fmt->log_fmt(level, e_time, time, Loc, data));
  // mt(level, e_time, time,loc, data));
}

void Stream::LOG(
    const log_level level, const TIME e_time,
    const std::chrono::zoned_time<std::chrono::system_clock::duration> time,
    const std::string_view data) {

  this->DefaultStream(fmt->log_fmt(level, e_time, time, data));
}

void Stream::TRACE(
    const TIME e_time,
    const std::chrono::zoned_time<std::chrono::system_clock::duration> time,
    const Source_Loc Loc) {

  this->DefaultStream(fmt->trace_fmt(Loc, e_time, time));
}

void Stream::TRACE(
    const TIME e_time,
    const std::chrono::zoned_time<std::chrono::system_clock::duration> time,
    const Source_Loc Loc, const std::vector<std::string_view> &args_name,
    const std::vector<std::string> &arg_data) {

  this->DefaultStream(fmt->trace_fmt(Loc, e_time, time, args_name, arg_data));
}
void Stream::MEM_view(
    const TIME e_time,
    const std::chrono::zoned_time<std::chrono::system_clock::duration> time,
    const Source_Loc Loc, std::uint8_t view, std::string_view var_name,
    const std::uint8_t *ptr, const std::uint64_t size) {

  fmt->mem_view(e_time, time, Loc, view, var_name, ptr, size, this);
}

void Stream::STACKTRACE(
    const std::stacktrace &str, const TIME e_time,
    const std::chrono::zoned_time<std::chrono::system_clock::duration> time) {

  this->DefaultStream(fmt->stack_trace_fmt(str, e_time, time));
}
} // namespace DEBUG_profiler
