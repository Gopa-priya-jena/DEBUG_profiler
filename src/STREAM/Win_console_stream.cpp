
#if defined(_WIN32) || defined(_WIN64)

#include <STREAM/Win_console_stream.hpp>
#include <iostream>
namespace DEBUG_profiler {
Win_stream::Win_stream() {}

bool Win_stream::init() {
  set_formatter(fmt);
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleOutputCP(65001);
  // Check if we got a valid handle
  if (hConsole == INVALID_HANDLE_VALUE) {
    std::cerr << "Error: Could not get console output handle. Error code: "
              << GetLastError() << std::endl;
    return false;
  }
  return true;
}
void Win_stream::StreamI(std::string_view Data) {
  std::scoped_lock<std::mutex> lock(mtx_lock);
  DWORD bytesWritten = 0;
  WriteConsole(hConsole,      // Handle to the console output buffer
               Data.data(),   // Pointer to the buffer containing the data
               Data.size(),   // Number of characters to write
               &bytesWritten, // Pointer to a DWORD that receives the number
               static_cast<LPVOID>(NULL) // Reserved; must be NULL
  );

  // std::cout << Data << std::flush;
}
void Win_stream::StreamB(std::string_view Data) { StreamI(Data); }
void Win_stream::DefaultStream(std::string_view Data) { StreamI(Data); }
void Win_stream::flush() {}
} // namespace DEBUG_profiler
#endif
