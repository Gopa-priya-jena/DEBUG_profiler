
#include <FORMATTER/nocolor_formatter.hpp>
#include <STREAM/STREAM.hpp>
#include <bitset>
#include <iomanip>
#include <iostream>
#include <sstream>
namespace DEBUG_profiler
{

  std::string NOColor_format::trace_fmt( const std::stacktrace &stack_trace )
  {
    std::ostringstream OSS;
    OSS << " [STACKTRACE] :\n";

    for ( auto i = 0; i < stack_trace.size(); i++ )
      OSS << stack_trace.size() - i << stack_trace[ i ].description() << ":"
          << stack_trace[ i ].source_line();

    return OSS.str();
  }
  std::string NOColor_format::Time_format( const TIME time )
  {

    auto time_fmt = std::format(
        "\n[ELASPSED TIME]:{}hrs {}min {}s {}ms {}us {}ns", time.hour, time.min,
        time.sec, time.milli, time.micro, time.nano );
    return time_fmt;
  }
  std::string NOColor_format ::Location_format( const Source_Loc loc )
  {

    auto Location = std::format( "\n [FILE LOCATION]:{}", loc.file_name );

    auto Function = std::format( "\n [FUNCTON]:{}", loc.function_name );

    auto line = std::format( "\n [LINE NUMBER ]:{}", loc.line );

    return std::format( "{}\t{}\t{}", Location, Function, line );
  }

  std::string
  NOColor_format::F_arg_format( const std::vector<std::string_view> &Args_name,
                                const std::vector<std::string>      &Arg_data )
  {

    std::ostringstream OSS;

    OSS << "\n" << "[FUNCTION ARGS]" << "\n";

    for ( auto i = 0; i < Args_name.size(); i++ )
    {
      OSS << Args_name[ i ] << "\n";
      OSS << "\t >>" << Arg_data[ i ] << "\n";
    }

    return OSS.str();
  }
  std::string NOColor_format::current_time_fmt(
      const std::chrono::zoned_time<std::chrono::system_clock::duration> time )
  {

    return std::format( "\n[TIME]:{:%A %d %B %y -> %I:%M:%S %p }", time );
  }
  std::string NOColor_format::level_fmt( const log_level level )
  {

    auto lvl = static_cast<std::uint8_t>( level );

    return std::format( "{} {} ->", Level_info[ lvl ].symbol,
                        Level_info[ lvl ].name );
  }
  std::string NOColor_format::log_fmt(
      const log_level level, TIME e_time,
      const std::chrono::zoned_time<std::chrono::system_clock::duration> time,
      const std::string_view                                             data )
  {

    return std::format( "\n{}{}{}{}{}", div, level_fmt( level ),
                        Time_format( e_time ), current_time_fmt( time ), data,
                        div );
  }
  std::string NOColor_format::log_fmt(
      const log_level lvl, const TIME e_time,
      const std::chrono::zoned_time<std::chrono::system_clock::duration> time,
      const Source_Loc loc, const std::string_view data )
  {

    return std::format( "\n{}{}{}{}{}{}", div, level_fmt( lvl ),
                        Time_format( e_time ), current_time_fmt( time ),
                        Location_format( loc ), data, div );
  }

  std::string NOColor_format::trace_fmt(
      const Source_Loc loc, const TIME e_time,
      const std::chrono::zoned_time<std::chrono::system_clock::duration> time,
      const std::vector<std::string_view> &Args_name,
      const std::vector<std::string>      &Arg_data )
  {
    return std::format( "\n{}{}{}{}{}{}", div, level_fmt( log_level::TRACE ),
                        Time_format( e_time ), current_time_fmt( time ),
                        Location_format( loc ),
                        F_arg_format( Args_name, Arg_data ), div );
  }
  std::string NOColor_format::trace_fmt(
      const Source_Loc loc, const TIME e_time,
      const std::chrono::zoned_time<std::chrono::system_clock::duration> time )
  {

    return std::format( "\n{}{} {} {} {}{}", div, level_fmt( log_level::TRACE ),
                        Time_format( e_time ), current_time_fmt( time ),
                        Location_format( loc ), div );
  }
  std::string NOColor_format::stack_trace_fmt(
      const std::stacktrace &str, const TIME e_time,
      const std::chrono::zoned_time<std::chrono::system_clock::duration> time )
  {

    return std::format( "{}{}{}", Time_format( e_time ),
                        current_time_fmt( time ), trace_fmt( str ) );
  }

  void NOColor_format::BIN_dump( const std::uint8_t *ptr,
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

  void NOColor_format::HEX_dump( const std::uint8_t *ptr,
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
  void NOColor_format::OCTAL_dump( const std::uint8_t *ptr,
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
  void NOColor_format::STRING_dump( const std::uint8_t *ptr,
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
  void NOColor_format::DECIMAL_dump( const std::uint8_t *ptr,
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

  void NOColor_format::mem_view(
      const TIME                                                         e_time,
      const std::chrono::zoned_time<std::chrono::system_clock::duration> time,
      const Source_Loc Loc, std::uint8_t view, const std::string_view var_name,
      const std::uint8_t *ptr, const std::uint64_t size, Stream *stream )
  {

    stream->StreamI( std::format( "{}{}", div, var_name ) );

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
