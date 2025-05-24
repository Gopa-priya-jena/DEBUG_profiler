#include <Logger.hpp>
namespace DEBUG_profiler {

void Logger::arg_name_gen(std::string_view Args_name,
                          std::vector<std::string_view> &arg_name) {

  for (auto i = 0; i <= Args_name.size();) {
    std::string_view s;
    auto pos = Args_name.find(",", i);
    if (pos != std::string_view::npos) {
      s = Args_name.substr(i, pos - i);
      i = pos + 1;
      arg_name.push_back(s);
    } else {
      s = Args_name.substr(i);
      arg_name.push_back(s);
      break;
    }
  }
}
void Logger::set_mem_view(std::uint8_t view) { _memory_view = view; }
std::vector<std::string_view> Logger::parse_argname(std::string_view arg_name) {

  std::vector<std::string_view> res;

  for (auto i = 0; i <= arg_name.size();) {
    std::string_view s;
    auto pos = arg_name.find(",", i);
    if (pos != std::string_view::npos) {
      s = arg_name.substr(i, pos - i);
      i = pos + 1;
      res.push_back(s);
    } else {
      s = arg_name.substr(i);
      res.push_back(s);
      return res;
    }
  }
  return res;
}

std::chrono::zoned_time<std::chrono::system_clock::duration>
Logger::get_current_time() {
  auto now_sys = std::chrono::system_clock::now();
  auto now_zoned =
      std::chrono::zoned_time{std::chrono::current_zone(), now_sys};
  return now_zoned;
}

TIME Logger::get_time_elaspsed() {
  auto timediff = std::chrono::high_resolution_clock::now() - start_Time;
  auto fraction =
      std::chrono::duration_cast<std::chrono::nanoseconds>(timediff);

  TIME Time;
  using namespace std::chrono_literals;
  Time.hour = std::chrono::floor<std::chrono::hours>(fraction).count();

  Time.min = std::chrono::floor<std::chrono::minutes>(fraction).count();

  Time.sec = (std::chrono::floor<std::chrono::seconds>(fraction) % 60s).count();

  Time.milli =
      (std::chrono::floor<std::chrono::milliseconds>(fraction) % 60ms).count();
  Time.micro =
      (std::chrono::floor<std::chrono::microseconds>(fraction) % 60us).count();

  Time.nano =
      (std::chrono::floor<std::chrono::nanoseconds>(fraction) % 60ns).count();

  return Time;
}
Logger::Logger() {
  start_Time = std::chrono::high_resolution_clock::now();

  for (auto &i : Stream_list)
    i->init();
}
Logger::~Logger() {
  for (auto &i : Stream_list)
    i->terminate();

  for (auto &i : Stream_list)
    i->~Stream();
}

void Logger::log(const std::string_view data) {
  // std::cout << data;
  auto e_time = get_time_elaspsed();
  auto time = get_current_time();
  for (auto &i : Stream_list)
    i->LOG(log_level::NORMAL, e_time, time, data);
}
void Logger::log(const log_level level, const std::string_view data) {
  auto e_time = get_time_elaspsed();
  auto time = get_current_time();
  for (auto &i : Stream_list)
    i->LOG(level, e_time, time, data);
}
void Logger::log(const std::string_view file, const std::uint16_t line,
                 const std::string_view function, const std::string_view data) {

  // std::cout << data;
  auto e_time = get_time_elaspsed();
  auto time = get_current_time();
  for (auto &i : Stream_list)
    i->LOG(log_level::NORMAL, e_time, time, data);
}
void Logger::log(const std::string_view file, const std::uint16_t line,
                 const std::string_view function, const log_level level,
                 const std::string_view data) {

  // std::cout << data;
  auto e_time = get_time_elaspsed();
  auto time = get_current_time();
  for (auto &i : Stream_list)
    i->LOG(level, e_time, time, {file, line, function}, data);
}

void Logger::trace(const std::string_view file, const std::uint16_t line,
                   const std::string_view function) {

  auto e_time = get_time_elaspsed();
  auto time = get_current_time();

  for (auto &i : Stream_list)
    i->TRACE(e_time, time, {file, line, function});
}
void Logger::STACK_TRACE(std::stacktrace str) {
  auto e_time = get_time_elaspsed();
  auto time = get_current_time();
  for (auto &i : Stream_list)
    i->STACKTRACE(str, e_time, time);
}

void Logger::MEMORY_VIEW(const std::string_view file, const std::uint16_t line,
                         const std::string_view function,
                         std::string_view var_name, std::uint8_t *ptr,
                         std::uint64_t size, std::uint8_t view) {
  auto e_time = get_time_elaspsed();
  auto time = get_current_time();
  if (view == MEM_VIEW::NONE) {
    view = _memory_view;
  }

  for (auto &i : Stream_list)
    i->MEM_view(e_time, time, {file, line, function}, view, var_name, ptr,
                size);
}
} // namespace DEBUG_profiler
