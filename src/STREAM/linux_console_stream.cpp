#if defined __linux__
#include <STREAM/linux_console_stream.hpp>
namespace DEBUG_profiler {

void Linux_stream::StreamI(std::string_view Data) {

  std::scoped_lock<std::mutex> lock(mtx_lock);
  write(STDOUT_FILENO, Data.data(), Data.size());
}
void Linux_stream::StreamB(std::string_view Data) { StreamI(Data); }
void Linux_stream::DefaultStream(std::string_view Data) { StreamI(Data); }
void Linux_stream::flush() {}

Linux_stream::Linux_stream() { set_formatter(fmt); }

// Stream &Linux_stream::operator<<(std::string_view Data) {
//   DefaultStream(Data);
//   return (*this);
// }
} // namespace DEBUG_profiler
#endif
