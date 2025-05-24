#pragma once

#include <FORMATTER/Formatter.hpp>
#include <Logger_info.hpp>
#include <STREAM/File_stream.hpp>
#include <STREAM/STREAM.hpp>
#include <STREAM/Win_console_stream.hpp>
#include <STREAM/linux_console_stream.hpp>
#include <chrono>
#include <config.hpp>
#include <cstdint>
#include <iostream>
#include <stacktrace>
#include <string_view>
#include <vector>
template <typename T>
concept ostream_printable = requires( T t ) { std::cout << t; };
template <typename T>
concept Nostream_printable = !ostream_printable<T>;

template <ostream_printable T>
T &isprintable( T &data )
{
  return data;
}
template <Nostream_printable T>
std::string_view isprintable( T &data )
{
  return "NOT PRINTABLE";
}

namespace DEBUG_profiler
{

  class Logger
  {
    std::chrono::time_point<std::chrono::high_resolution_clock,
                            std::chrono::nanoseconds>
         start_Time, func_start, func_end;
    TIME get_time_elaspsed();
    std::chrono::zoned_time<std::chrono::system_clock::duration>
    get_current_time();

    std::vector<std::string_view> parse_argname( std::string_view arg_name );
    // memory view  type
    std::uint8_t _memory_view{ 0x1F };
    // some streams to work with
    // Linux_stream lstream;
    // File_stream fstream;
    // storing streams
    std::array<Stream *, 2> Stream_list{ new File_stream,
#if defined( _WIN32 ) || defined( _WIN64 )
                                         new Win_stream,
#endif
#if defined __linux__

                                         new Linux_stream
#endif
    };

    void arg_name_gen( std::string_view               Args_name,
                       std::vector<std::string_view> &arg_name );

  public:
    Logger();
    ~Logger();
    void set_mem_view( std::uint8_t view );
    void log( const std::string_view data );
    void log( const log_level level, const std::string_view Data );
    void log( const std::string_view file, const std::uint16_t line,
              const std::string_view function, const std::string_view data );
    void log( const std::string_view file, const std::uint16_t line,
              const std::string_view function, const log_level level,
              const std::string_view Data );

    template <class... Args>
    void trace( const std::string_view file, const std::uint16_t line,
                const std::string_view function,
                const std::string_view Args_name, Args &...data )
    {

      auto e_time = get_time_elaspsed();
      auto time = get_current_time();

      std::vector<std::string_view> arg_name;
      arg_name_gen( Args_name, arg_name );
      std::ostringstream       Oss;
      std::vector<std::string> data_vec;
      ( ( Oss << isprintable( data ) << "\n", data_vec.push_back( Oss.str() ),
          Oss.str( "" ) ),
        ... );

      for ( auto &i : Stream_list )
        i->TRACE( e_time, time, { file, line, function }, arg_name, data_vec );
    }
    // template <typename... msg> std::string MSG_concat(msg... Msg);

    void trace( const std::string_view file, const std::uint16_t line,
                const std::string_view function );
    void BREAK();
    void STACK_TRACE( std::stacktrace str );

    void MEMORY_VIEW( const std::string_view file, const std::uint16_t line,
                      const std::string_view function,
                      std::string_view var_name, std::uint8_t *ptr,
                      std::uint64_t size, std::uint8_t view = MEM_VIEW::NONE );
  };
} // namespace DEBUG_profiler
