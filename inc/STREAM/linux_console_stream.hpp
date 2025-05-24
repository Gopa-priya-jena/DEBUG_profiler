
#if defined __linux__
#pragma once
#include <FORMATTER/color_formatter.hpp>
#include <STREAM/STREAM.hpp>
#include <mutex>
#include <unistd.h>
namespace DEBUG_profiler {

class Linux_stream : public Stream {
private:
  std::mutex mtx_lock;
  Color_format fmt;

public:
  Linux_stream();
  ~Linux_stream() {}

  void StreamI(std::string_view Data);
  void StreamB(std::string_view Data);
  void DefaultStream(std::string_view Data);
  void flush();
  // Stream &operator<<(std::string_view Data);
};
} // namespace DEBUG_profiler
#endif
