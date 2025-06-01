#pragma once

#include <FORMATTER/Formatter.hpp>
#include <config.hpp>
#include <string_view>
#include <vector>
namespace DEBUG_profiler
{

#include <Logger_info.hpp>
  class Stream
  {
    Formatter *fmt;

  public:
    Stream()
    {
    }
    virtual ~Stream()
    {
    }
    virtual bool init()
    {
      return true;
    }

    virtual void terminate()
    {
    }
    virtual void StreamI( std::string_view Data ) = 0;
    virtual void StreamB( std::string_view Data ) = 0;
    virtual void DefaultStream( std::string_view Data ) = 0;
    virtual void flush() = 0;
    // virtual Stream &operator<<(std::string_view Data);

    // common function

    void set_formatter( Formatter &formatter );

    void LOG(
        const log_level level, const TIME e_time,
        const std::chrono::zoned_time<std::chrono::system_clock::duration> time,
        const Source_Loc Loc, const std::string_view data );

    void LOG(
        const log_level level, const TIME e_time,
        const std::chrono::zoned_time<std::chrono::system_clock::duration> time,
        const std::string_view data );

    void TRACE(
        const TIME e_time,
        const std::chrono::zoned_time<std::chrono::system_clock::duration> time,
        const Source_Loc Loc );

    void TRACE(
        const TIME e_time,
        const std::chrono::zoned_time<std::chrono::system_clock::duration> time,
        const Source_Loc Loc, const std::vector<std::string_view> &args_name,
        const std::vector<std::string> &arg_data );

    void STACKTRACE(
        const std::stacktrace &str, const TIME e_time,
        const std::chrono::zoned_time<std::chrono::system_clock::duration>
            time );

    void MEM_view(
        const TIME e_time,
        const std::chrono::zoned_time<std::chrono::system_clock::duration> time,
        const Source_Loc Loc, std::uint8_t view, std::string_view var_name,
        const std::uint8_t *ptr, const std::uint64_t size );
  };
} // namespace DEBUG_profiler
