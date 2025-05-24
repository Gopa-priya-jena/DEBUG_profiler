#if defined(_WIN32) || defined(_WIN64)
#pragma once
#include <FORMATTER/color_formatter.hpp>
#include <STREAM/STREAM.hpp>
#include <mutex>
#include <windows.h>
namespace DEBUG_profiler {
class Win_stream : public Stream {
private:
  std::mutex mtx_lock;
  HANDLE hConsole;
  Color_format fmt;

public:
  Win_stream();
  ~Win_stream() {}
  bool init();
  void StreamI(std::string_view Data);
  void StreamB(std::string_view Data);
  void DefaultStream(std::string_view Data);
  void flush();
};
} // namespace DEBUG_profiler
#endif
