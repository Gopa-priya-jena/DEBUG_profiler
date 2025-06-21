#include "Logger_info.hpp"
#include <FORMATTER/ansi.hpp>
#include <FORMATTER/color_formatter.hpp>
#include <FORMATTER/colors.hpp>
#include <STREAM/STREAM.hpp>
#include <bitset>
#include <format>
#include <iomanip>
#include <iostream>
#include <sstream>
namespace DEBUG_profiler
{

  std::string Color_format::trace_fmt( const std::stacktrace &stack_trace )
  {
    std::ostringstream OSS;
    OSS << std::format( "{}\n{}{} STACKTRACE :\n", RESET_SEQ,
                        color_rgb_fg.format( hot_pink ),
                        color_rgb_bg.format( DEFAULT_BG ) );

    for ( auto i = 0; i < stack_trace.size(); i++ )
      OSS << " # > " << stack_trace.size() - i << " "
          << stack_trace[ i ].description() << "\t:\t"
          << stack_trace[ i ].source_line() << "\n";

    OSS << RESET_SEQ;
    return OSS.str();
  }
  std::string Color_format::Time_format( const TIME time )
  {

    auto time_fmt = std::format(
        "\n{}{}{}{} [ELASPSED TIME]:{}{}", RESET_SEQ,
        color_rgb_fg.format( purple ), color_rgb_bg.format( DEFAULT_BG ),
        _stopwatch,
        italic_mode.format( std::format( "{}hrs {}min {}s {}ms {}us {}ns",

                                         time.hour, time.min, time.sec,
                                         time.milli, time.micro, time.nano ) ),
        RESET_SEQ );
    return time_fmt;
  }
  std::string Color_format ::Location_format( const Source_Loc loc )
  {

    auto Location = std::format( "\n{}{}{}[FILE LOCATION]:{}", RESET_SEQ,
                                 color_rgb_fg.format( plum ),
                                 color_rgb_bg.format( DEFAULT_BG ),
                                 bold_mode.format( loc.file_name ), RESET_SEQ );

    auto Function = std::format(
        "\n{}{}{}[FUNCTON]:{}{}", RESET_SEQ, color_rgb_fg.format( gold ),
        color_rgb_bg.format( DEFAULT_BG ),
        italic_mode.format( loc.function_name ), RESET_SEQ );

    auto line = std::format(
        "\n{}{}{}[LINE NUMBER ]:{}{}", RESET_SEQ,
        color_rgb_fg.format( royal_blue ), color_rgb_bg.format( DEFAULT_BG ),
        bold_mode.format( std::to_string( loc.line ) ), RESET_SEQ );

    return std::format( "{}{}{}", Location, Function, line );
  }

  std::string
  Color_format::F_arg_format( const std::vector<std::string_view> &Args_name,
                              const std::vector<std::string>      &Arg_data )
  {

    std::ostringstream OSS;

    OSS << "\n"
        << RESET_SEQ << color_rgb_fg.format( aquamarine )
        << color_rgb_bg.format( DEFAULT_BG )
        << bold_mode.format( "[FUNCTION ARGS]" ) << RESET_SEQ << "\n";

    for ( auto i = 0; i < Args_name.size(); i++ )
    {
      OSS << color_rgb_fg.format( *RGB_clrs_[ RGB_start_ + i ] )
          << color_rgb_bg.format( DEFAULT_BG )
          << italic_mode.format( Args_name[ i ] ) << RESET_SEQ << "\n";

      OSS << color_rgb_fg.format( *RGB_clrs_[ RGB_start_ + i + 2 ] )
          << color_rgb_bg.format( DEFAULT_BG )
          << italic_mode.format( Arg_data[ i ] ) << RESET_SEQ << "\n";
    }

    return OSS.str();
  }
  std::string Color_format::current_time_fmt(
      const std::chrono::zoned_time<std::chrono::system_clock::duration> time )
  {

    return std::format( "\n{}{}{}{} [TIME]:{:%A %d %B %y -> %I:%M:%S %p }{}",
                        RESET_SEQ, color_rgb_fg.format( royal_blue ),
                        color_rgb_bg.format( DEFAULT_BG ), _clock, time,
                        RESET_SEQ );
  }
  std::string Color_format::level_fmt( const log_level level )
  {

    auto lvl = static_cast<std::uint8_t>( level );

    return std::format(
        "\n{}{}{}  {} {}{}", RESET_SEQ,
        color_rgb_fg.format( Level_info[ lvl ].fg ),
        color_rgb_bg.format( Level_info[ lvl ].bg ),
        bold_mode.format( std::format( " {} {}", Level_info[ lvl ].symbol,
                                       Level_info[ lvl ].name ) ),
        _arrow, RESET_SEQ );
  }
  std::string Color_format::data_fmt( const log_level  level,
                                      std::string_view data )
  {

    auto lvl = static_cast<std::uint8_t>( level );
    return std::format(
        "{}{}{}{}{}", RESET_SEQ, color_rgb_fg.format( Level_info[ lvl ].fg ),
        color_rgb_bg.format( Level_info[ lvl ].bg ), data, RESET_SEQ );
  }

  std::string Color_format::log_fmt(
      const log_level level, TIME e_time,
      const std::chrono::zoned_time<std::chrono::system_clock::duration> time,
      const std::string_view                                             data )
  {

    return std::format( "{}{}{}{}", level_fmt( level ), Time_format( e_time ),
                        current_time_fmt( time ), data_fmt( level, data ) );
  }
  std::string Color_format::log_fmt(
      const log_level lvl, const TIME e_time,
      const std::chrono::zoned_time<std::chrono::system_clock::duration> time,
      const Source_Loc loc, const std::string_view data )
  {

    return std::format( "{}{}{}{}{}", level_fmt( lvl ), Time_format( e_time ),
                        current_time_fmt( time ), Location_format( loc ),
                        data_fmt( lvl, data ) );
  }

  std::string Color_format::trace_fmt(
      const Source_Loc loc, const TIME e_time,
      const std::chrono::zoned_time<std::chrono::system_clock::duration> time,
      const std::vector<std::string_view> &Args_name,
      const std::vector<std::string>      &Arg_data )
  {
    return std::format( "{}{}{}{}{}", level_fmt( log_level::TRACE ),
                        Time_format( e_time ), current_time_fmt( time ),
                        Location_format( loc ),
                        F_arg_format( Args_name, Arg_data ) );
  }
  std::string Color_format::trace_fmt(
      const Source_Loc loc, const TIME e_time,
      const std::chrono::zoned_time<std::chrono::system_clock::duration> time )
  {

    return std::format( "{} {} {} {}", level_fmt( log_level::TRACE ),
                        Time_format( e_time ), current_time_fmt( time ),
                        Location_format( loc ) );
  }
  std::string Color_format::stack_trace_fmt(
      const std::stacktrace &str, const TIME e_time,
      const std::chrono::zoned_time<std::chrono::system_clock::duration> time )
  {

    return std::format( "{}{}{}", Time_format( e_time ),
                        current_time_fmt( time ), trace_fmt( str ) );
  }

  void Color_format::BIN_dump( const std::uint8_t *ptr,
                               const std::uint64_t size, Stream *stream )
  {
    std::ostringstream OSS;

    OSS << "\n BINARY " << size << " \n";
    std::uint8_t offset = 1;
    while ( offset <= size )
    {

      std::bitset<8> VAL{ *( ptr++ ) };
      std::bitset<4> L{ VAL.to_ulong() & 0xF },
          H{ ( VAL.to_ulong() >> 4 ) & 0xF };

      OSS << VAL[ 0 ] << " " << VAL[ 1 ] << " " << VAL[ 2 ] << " " << VAL[ 3 ]
          << "  " << VAL[ 4 ] << " " << VAL[ 5 ] << " " << VAL[ 6 ] << " "
          << VAL[ 7 ] << "  ";
      if ( !( ( offset ) % 2 ) )
        OSS << "  ";

      if ( !( ( offset ) % 4 ) )
        OSS << "    ";

      if ( !( ( offset ) % 8 ) )
      {
        OSS << "\n";
        stream->StreamI( OSS.str() );
        OSS.str( "" );
      }
      offset++;
    }
    stream->StreamI( OSS.str() );
  }

  void Color_format::HEX_dump( const std::uint8_t *ptr,
                               const std::uint64_t size, Stream *stream )
  {

    std::ostringstream OSS;

    OSS << "\n HEX  " << size << "\n";
    std::uint8_t offset = 1;
    while ( offset <= size )
    {

      OSS << std::hex << std::uppercase << std::setw( 2 ) << +*( ptr++ ) << " ";
      // OSS << *(pointer++) << " ";

      if ( !( ( offset ) % 2 ) )
        OSS << "  ";

      if ( !( ( offset ) % 4 ) )
        OSS << "    ";

      if ( !( ( offset ) % 8 ) )
      {
        OSS << "\n";
        stream->StreamI( OSS.str() );
        OSS.str( "" );
      }

      offset++;
    }
    stream->StreamI( OSS.str() );
  }
  void Color_format::OCTAL_dump( const std::uint8_t *ptr,
                                 const std::uint64_t size, Stream *stream )
  {

    std::ostringstream OSS;
    OSS << "\n OCTAL  " << size << "\n";

    std::uint8_t offset = 1;
    while ( offset <= size )
    {

      OSS << std::oct << std::setw( 3 ) << std::setfill( '0' ) << +*( ptr++ )
          << "  ";
      // OSS << *(pointer++) << " ";

      if ( !( ( offset ) % 2 ) )
        OSS << "  ";

      if ( !( ( offset ) % 4 ) )
        OSS << "    ";

      if ( !( ( offset ) % 8 ) )
      {
        OSS << "\n";
        stream->StreamI( OSS.str() );
        OSS.str( "" );
      }
      offset++;
    }
    stream->StreamI( OSS.str() );
  }
  void Color_format::STRING_dump( const std::uint8_t *ptr,
                                  const std::uint64_t size, Stream *stream )
  {

    std::ostringstream OSS;
    OSS << "\n STRING   " << size << "\n";

    std::uint8_t offset = 1;
    while ( offset <= size )
    {

      OSS << *( ptr++ ) << "  ";
      // OSS << *(pointer++) << " ";

      if ( !( ( offset ) % 2 ) )
        OSS << "  ";

      if ( !( ( offset ) % 4 ) )
        OSS << "    ";

      if ( !( ( offset ) % 8 ) )
      {
        OSS << "\n";
        stream->StreamI( OSS.str() );
        OSS.str( "" );
      }
      offset++;
    }

    stream->StreamI( OSS.str() );
  }
  void Color_format::DECIMAL_dump( const std::uint8_t *ptr,
                                   const std::uint64_t size, Stream *stream )
  {

    std::ostringstream OSS;

    OSS << "\n DECIMAL   " << size << "\n";
    std::uint8_t offset = 1;
    while ( offset <= size )
    {

      OSS << std::dec << std::uppercase << std::setw( 3 ) << std::setfill( '0' )
          << +*( ptr++ ) << " ";
      // OSS << *(pointer++) << " ";

      if ( !( ( offset ) % 2 ) )
        OSS << "  ";

      if ( !( ( offset ) % 4 ) )
        OSS << "    ";

      if ( !( ( offset ) % 8 ) )
      {
        OSS << "\n";
        stream->StreamI( OSS.str() );
        OSS.str( "" );
      }
      offset++;
    }
    stream->StreamI( OSS.str() );
  }

  void Color_format::mem_view(
      const TIME                                                         e_time,
      const std::chrono::zoned_time<std::chrono::system_clock::duration> time,
      const Source_Loc Loc, std::uint8_t view, const std::string_view var_name,
      const std::uint8_t *ptr, const std::uint64_t size, Stream *stream )
  {

    stream->StreamI(
        std::format( "{}{}{}{}", color_rgb_fg.format( Yellow_green ),
                     color_rgb_bg.format( DEFAULT_BG ), var_name, RESET_SEQ ) );

    if ( view & MEM_VIEW::BINARY )
    {
      BIN_dump( ptr, size, stream );
    }

    if ( view & MEM_VIEW::HEX )
    {

      HEX_dump( ptr, size, stream );
    }
    if ( view & MEM_VIEW::OCTAL )
    {

      OCTAL_dump( ptr, size, stream );
    }
    if ( view & MEM_VIEW::STRING )
    {

      STRING_dump( ptr, size, stream );
    }

    if ( view & MEM_VIEW::DECIMAL )
    {

      DECIMAL_dump( ptr, size, stream );
    }
  }
} // namespace DEBUG_profiler
