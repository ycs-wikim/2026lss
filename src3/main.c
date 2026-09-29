#include "fileop.h"

#include <stdio.h>
#include <errno.h>			/// errno header
#include <string.h>			/// strerror() header

lss_i32 main( void )
{
	lss_i32 fd = 0;
	lss_i32 ret = 0;
	lss_i8 buf[ STRLEN_128 ] = { 0, };
/*
	if( close( fd ) == -1 )
	{
		printf( "%s:%s:%d - errno[ %d ]: %s\n",
			__FILE__, __FUNCTION__, __LINE__,
			errno, strerror(errno) );
		perror( "Error!" );
	}
*/
	/// interface call
	fd = file_open( "fileop.h", O_RDONLY );
	if( -1 == fd )
	{
		printf("Error: %d\n", errno );
		return -1;
	}

	ret = file_read( fd, buf, STRLEN_128 );
	if( ( -1 == ret ) || ( 0 == ret ) )
	{
		printf( "read fail or EOF\n" );
	}
	else
	{
		printf("BUF: %s\n", buf );
	}

	fd = file_close( fd );
	if( -1 == fd )
		return -1;

	printf("file operations success\n" );
	return 0;
}





