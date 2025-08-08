
#include <DEBUG.hpp>
#include <vector>

void test_func( int adad, std::string hfbdif,
                std::vector<std::string_view> dfhufdfd )
{
  FUNCTION_PROFILE_ARG( adad, hfbdif, dfhufdfd )
  MEM_info( hfbdif );
  MEM_VIEW( hfbdif, 32 );
  STACK_DUMP;
  R_assert( "pass", 1 );
  R_assert( "fail", 0 );
}

int main()
{
  LOG( "what" );
  LOG_NORMAL( "HI" )
  LOG_CRITICAL( "HI" )
  LOG_DEBUG( "HI" )
  LOG_ERROR( "hi" )
  LOG_INFO( "dasdila" )
  LOG_WARN( "dhaoisdfhahd" )
  test_func( 32434, "hfbdif", std::vector<std::string_view>{ "dfhufdfd" } );
  // END_LOG
}
