#pragma once
#include <Assert.hpp>
#include <Log_macro.hpp>
#include <PROFILE.hpp>
#define DEBUG_PROFILER

#ifdef DEBUG_PROFILER

  // tracer
  #if TRACE_ENABLE
    #define FUNCTION_PROFILE                                                   \
      Trace                                                                    \
      FUNC_PROF(FUNCTION_NAME);

    #define FUNCTION_PROFILE_ARG( ... )                                        \
          Trace_arg( __VA_ARGS__)                                              \
      FUNC_PROF(FUNCTION_NAME);

  #endif
// logging

  #if LOG_ENABLE
    #if LOG_LEVEL_TRACE_ENABLE
      #define LOG_AT( X ) log_(X)
    #endif
    #if LOG_LEVEL_NORMAL_ENABLE
      #define LOG_NORMAL( ... )      log_nrml(__VA_ARGS__)
      #define LOG( ... )      log_nrml(__VA_ARGS__)
      #if LOG_LEVEL_INFO_ENABLE
        #define LOG_INFO( ... )                                                \
        log_info(__VA_ARGS__)
      #endif
      #if LOG_LEVEL_DEBUG_ENABLE
        #define LOG_DEBUG( ... )                                               \
log_dbg(__VA_ARGS__)
        #if LOG_LEVEL_WARN_ENABLE
          #define LOG_WARN( ... )                                              \
         log_wrn(__VA_ARGS__)
        #endif
      #endif
      #if LOG_LEVEL_ERROR_ENABLE
        #define LOG_ERROR( ... )                                               \
   log_err(__VA_ARGS__)
      #endif
      #define LOG_CRITICAL( ... )                                              \
      log_critical(__VA_ARGS__)
    #endif
  #endif
  // memory related actions and function to
  //  view and analyse memory
  #if MEMORY_DEBUG
    #define MEM_info( X ) mem_inf(X);

    #define MEM_VIEW( X, POS )                                                 \
               mem_vw(X, POS)

  #endif
  #define STACK_DUMP  st_dump
// breakpoint
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
#endif // DEBUG_PROFILER
