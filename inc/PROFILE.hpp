#pragma once
#include <chrono>
#include <config.hpp>
#include <iostream>
#include <thread>
#define PROFILER_TRACY 1

#if ( PROFILER_TRACY ) && ( TRACY_ENABLE )
  #include <Tracy.hpp>
inline void wait_for_tracy()
{
  std::cout << "WAITING FOR TRACY " << std::endl;
  while ( !TracyIsConnected )
  {

    std::this_thread::sleep_for( std::chrono::milliseconds( 10 ) );
  }
}

  // tracy macros overload
  #define Profiler_conection_waiting wait_for_tracy();
  #define FUNC_PROF( NAME ) ZoneScopedN(NAME)
// #define
// #define message
#else

  #define Profiler_conection_waiting
  #define FUNC_PROF( NAME )

#endif
