#include<iostream>
#include<io.h>
#include<direct.h>
#include<string>

#include<gflags/gflags.h>
#include<glog/logging.h>
#include<md5/md5fcxx.h>

int main( int argc , char** argv ){
    std::string log_info_folder    = ".\\LOG_INFO\\";
    std::string log_warning_folder = ".\\LOG_WARNING\\";
    std::string log_error_folder   = ".\\LOG_ERROR\\";
    std::string log_fatal_folder   = ".\\LOG_FATAL\\";

#pragma region check_log_folder

#define _NOT_CREATED_ -1

	if ( _access( log_info_folder.c_str() , 0 ) == _NOT_CREATED_ )
    {
        _mkdir( log_info_folder.c_str() );
    }
    if ( _access( log_warning_folder.c_str() , 0 ) == _NOT_CREATED_ )
    {
        _mkdir( log_warning_folder.c_str() );
    }
    if ( _access( log_error_folder.c_str() , 0 ) == _NOT_CREATED_ )
    {
        _mkdir( log_error_folder.c_str() );
    }
    if ( _access( log_fatal_folder.c_str() , 0 ) == _NOT_CREATED_ )
    {
        _mkdir( log_fatal_folder.c_str() );
    }
    
#undef _NOT_CREATED_

#pragma endregion check_log_folder

    gflags::ParseCommandLineFlags( &argc , &argv , true );
    google::InitGoogleLogging( argv[0] );
    FLAGS_alsologtostderr = true;
    FLAGS_colorlogtostderr = true;

    google::SetLogDestination( google::GLOG_INFO    , log_info_folder.c_str()    );
    google::SetLogDestination( google::GLOG_WARNING , log_warning_folder.c_str() );
    google::SetLogDestination( google::GLOG_ERROR   , log_error_folder.c_str()   );
    google::SetLogDestination( google::GLOG_FATAL   , log_fatal_folder.c_str()   );

    LOG( INFO ) << "info";
	LOG( WARNING ) << "warning";
	LOG( ERROR ) << "error";

    std::cout << md5( "Hello World!" ) << std::endl;

    google::ShutdownGoogleLogging();

    return 0;
}