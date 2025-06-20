#pragma once

#include <Debug_internal.hpp>

#if LOGGER_ENABLE
inline DEBUG_profiler::Logger LOGGER_;
template <typename Args>
inline void mem_info( std::string_view file, std::uint32_t line,
                      std::string_view function, std::string_view argname,
                      Args        &arg,
                      std::uint8_t view = DEBUG_profiler::MEM_VIEW::ALL )
{
  LOGGER_.MEMORY_VIEW( file, line, function, argname,
                       ( std::uint8_t * )( &arg ), sizeof( Args ), view );
}
  // tracer
  #if TRACE_ENABLE
    #define Trace                                                  \
      LOGGER_.trace( __FILE__, __LINE__, FUNCTION_NAME );
    #define Trace_arg( ... )                                        \
      LOGGER_.trace( __FILE__, __LINE__, FUNCTION_NAME, #__VA_ARGS__,          \
                     __VA_ARGS__ );
  #else
    #define Trace
    #define Trace_arg( ... )

  #endif
// logging

  #if LOG_ENABLE
    #if LOG_LEVEL_TRACE_ENABLE
      #define log_( X ) LOGGER_.log( __FILE__, __LINE__, FUNCTION_NAME, X );
    #else
      #define log_( X )
    #endif
    #if LOG_LEVEL_NORMAL_ENABLE
      #define log_nrml( ... ) LOGGER_.log( MSG_concat( __VA_ARGS__ ) );
      #if LOG_LEVEL_INFO_ENABLE
        #define log_info( ... )                                                \
          LOGGER_.log( DEBUG_profiler::log_level::INFO,                        \
                       MSG_concat( __VA_ARGS__ ) );
      #else
        #define log_info( ... )
      #endif
      #if LOG_LEVEL_DEBUG_ENABLE
        #define log_dbg( ... )                                                 \
          LOGGER_.log( DEBUG_profiler::log_level::DEBUGGING,                   \
                       MSG_concat( __VA_ARGS__ ) );
      #else
        #define log_dbg( ... )
      #endif
      #if LOG_LEVEL_WARN_ENABLE
        #define log_wrn( ... )                                                \
            LOGGER_.log( __FILE__, __LINE__, FUNCTION_NAME,                    \
                         DEBUG_profiler::log_level::WARN,                      \
                         MSG_concat( __VA_ARGS__ ) );
      #else
        #define log_wrn( ... )
      #endif
      #if LOG_LEVEL_ERROR_ENABLE
        #define log_err( ... )                                               \
          LOGGER_.log( __FILE__, __LINE__, FUNCTION_NAME,                      \
                       DEBUG_profiler::log_level::ERROR_,                      \
                       MSG_concat( __VA_ARGS__ ) );
      #else
        #define log_err( ... )
      #endif
      #define log_critical( ... )                                              \
        LOGGER_.log( __FILE__, __LINE__, FUNCTION_NAME,                        \
                     DEBUG_profiler::log_level::CRITICAL,                      \
                     MSG_concat( __VA_ARGS__ ) );
    #else
      #define log_critical( ... )

    #endif
  #endif
  // memory related actions and function to
  //  view and analyse memory
  #if MEMORY_DEBUG
    #define mem_inf( X ) mem_info( __FILE__,__LINE__,FUNCTION_NAME,#X,X);

    #define mem_vw( X, POS )                                                 \
      LOGGER_.MEMORY_VIEW( __FILE__, __LINE__, FUNCTION_NAME, #X,              \
                           ( std::uint8_t * )( &X ), sizeof( X ) );
  #else
    #define mem_info( X )
    #define mem_vw( X, POS )
  #endif
  #define st_dump LOGGER_.STACK_TRACE( std::stacktrace::current() );
  // breakpoint
  #define END_LOG    LOGGER_.~Logger();
#else
  // tracer
  #define FUNCTION_PROFILE
  #define FUNCTION_PROFILE_ARG( ... )
  // logging
  #define LOG_AT( X, ... )
  #define LOG_NORMAL( ... )
  #define LOG_INFO( ... )
  #define LOG_DEBUG( ... )
  #define LOG_WARN( ... )
  #define LOG_ERROR( ... )
  #define LOG_CRITICAL( ... )
  // memory related actions and function to
  //  view and analyse memory
  #define MEM_info( X )
  #define MEM_VIEW( X, POS )
  // breakpoint
  #define BREAK( X )
  #define END_LOG
  #define STACK_DUMP
#endif
