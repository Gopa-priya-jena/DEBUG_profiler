#include <STREAM/File_stream.hpp>
#include <charconv>
#include <filesystem>
#include <format>
#include <iostream>
#include <sstream>
#include <string_view>
namespace DEBUG_profiler
{

  void File_stream::create_logfolder()
  {
    // create log  folder
    // first look for log folders
    namespace fs = std::filesystem;
    fs::path currentDir = fs::current_path();
    fs::path log_path = currentDir / "LOG";

    if ( fs::exists( log_path ) && fs::is_directory( log_path ) )
    // look for the largest  folder
    {
      auto MAX = 0;
      // find max
      for ( const auto &entry : fs::directory_iterator( log_path ) )
      {
        if ( fs::is_directory( entry.status() ) )
        {
          std::string      folder = entry.path().filename().string();
          std::string_view folder_name = folder;
          auto             pos = folder_name.rfind( "_" );

          folder_name = folder_name.substr( pos + 1 );

          auto val = 0;
          std::from_chars( folder_name.data(),
                           folder_name.data() + folder_name.size(), val, 10 );
          if ( val > MAX )
            MAX = val;
        }
      }
      MAX += 1;
      auto folder_name = std::format( "LOG_{}", MAX );
      log_path = log_path / folder_name;
      if ( fs::create_directory( log_path ) && fs::exists( log_path ) &&
           fs::is_directory( log_path ) )
      {

        Log_folder = log_path;

        std::cout << "OK " << Log_folder.string() << std::endl;
      }
      else
      {
        std::cout << "failed LOG_" << MAX << std::endl;
      }
    }
    else
    {
      fs::create_directory( log_path );
      fs::create_directory( log_path / "LOG_1" );
      Log_folder = log_path / "LOG_1";
    }
  }
  char *File_stream::create_File( std::fstream &file, std::thread::id T_id )
  {

    std::stringstream ss;
    ss << "LOG_thread_";
    ss << T_id;
    char *file_buff = new char[ _buffer_size ];
    file.rdbuf()->pubsetbuf( file_buff, _buffer_size );
    std::filesystem::path file_path = Log_folder / ss.str();
    file.open( file_path, std::fstream::out );
    return file_buff;
  }

  int File_stream::get_id( std::thread::id T_id )
  {

    for ( auto i = 0; i < File_list.size(); i++ )
      if ( File_list[ i ].Thread_id == T_id )
        return i;
    _file_list info;
    info.Thread_id = T_id;
    info.file_buff = create_File( info.file, T_id );
    File_list.emplace_back( std::move( info ) );
    return File_list.size() - 1;
  }
  bool File_stream::init()
  {

    const auto core = std::thread::hardware_concurrency();
    File_list.reserve( core * 2 );
    create_logfolder();
    set_formatter( fmt );
    return true;
  }
  void File_stream::terminate()
  {

    for ( auto &i : File_list )
    {

      i.file << std::flush;
      i.file.close();
      delete[] ( i.file_buff );
    }
  }

  void File_stream::StreamI( std::string_view Data )
  {

    File_list[ get_id( std::this_thread::get_id() ) ].file << Data
                                                           << std::flush;
  }
  void File_stream::StreamB( std::string_view Data )
  {

    File_list[ get_id( std::this_thread::get_id() ) ].file << Data;
  }
  void File_stream::DefaultStream( std::string_view Data )
  {
    StreamB( Data );
  }
  void File_stream::flush()
  {
    for ( auto &i : File_list )
    {

      i.file << std::flush;
    }
  }
  // Stream &File_stream::operator<<(std::string_view Data) {
  //   StreamI(Data);
  //   return (*this);
  // }

} // namespace DEBUG_profiler
