
#pragma once
#include <Logger.hpp>
#include <config.hpp>
#include <string>
#if defined(__clang__) || defined(__GNUC__)
#define FUNCTION_NAME __PRETTY_FUNCTION__
#elif defined(_MSC_VER)
#define FUNCTION_NAME __FUNCSIG__
#endif

#if defined(__GNUC__) || defined(__clang__)
#include <cxxabi.h>
inline std::string type_info(const char *name) {
  std::string res;
  auto buff = reinterpret_cast<char *>(std::malloc(500));
  size_t buff_size = 500;
  int stat = 0;
  buff = abi::__cxa_demangle(name, buff, &buff_size, &stat);
  res = buff;
  free(buff);
  return res;
}
#define TYPE_OF(X) type_info(typeid(X).name);
#elif defined(_MSC_VER)
inline std::string type_info(const char *name) {}
#define TYPE_OF(x) typeid(x).name()
#endif

#if BREAKPOINT_ENABLE
#if defined(__GNUC__) || defined(__clang__)
#define BREAK asm("int3");
#elif defined(_MSC_VER)
#define BREAK __debugbreak
#endif
#endif
template <typename... msg> std::string MSG_concat(msg... Msg) {

  std::ostringstream Oss;
  Oss << '\n';
  ((Oss << Msg << "\t"), ...);
  std::string res = Oss.str();
  return res;
}
// some symbols
