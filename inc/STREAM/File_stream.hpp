#pragma once

// DONE:
#include <FORMATTER/nocolor_formatter.hpp>
#include <STREAM/STREAM.hpp>
#include <filesystem>
#include <fstream>
#include <thread>
#include <vector>
namespace DEBUG_profiler
{

  constexpr auto _buffer_size = 2048 * 500;

  struct _file_list
  {
    std::thread::id Thread_id;
    std::fstream    file;
    char           *file_buff;
  };

  class File_stream : public Stream
  {

  private:
    std::vector<_file_list> File_list;
    std::filesystem::path   Log_folder;
    NOColor_format          fmt;
    void                    create_logfolder();
    char *create_File( std::fstream &file, std::thread::id T_id );

    int get_id( std::thread::id T_id );

  public:
    File_stream()
    {
    }
    ~File_stream()
    {
    }
    bool init();
    void StreamI( std::string_view Data );
    void StreamB( std::string_view Data );
    void DefaultStream( std::string_view Data );
    void flush();
    void terminate();

    // Stream &operator<<(std::string_view Data);
  };
} // namespace DEBUG_profiler
