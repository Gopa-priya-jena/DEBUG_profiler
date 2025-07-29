#pragma once
#include <Log_macro.hpp>
#include <cstdlib>
#include <syncstream>

#define CRASH     std::abort();
inline void check( bool check, std::string_view msg, std::string_view fname,
                   std::uint64_t line, std::string_view filename )
{
  if ( !check )
  {

#if LOGGER_ENABLE
    LOGGER_.log( filename, line, fname, msg );
    st_dump;
#else

    std::osyncstream( std::cout ) << msg << std::endl;
#endif
    CRASH
  }
}
#define R_assert( msg, ... )  check( static_cast<bool>(__VA_ARGS__ ),msg, FUNCTION_NAME, __LINE__,__FILE__ );
