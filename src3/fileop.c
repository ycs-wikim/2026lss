#include "fileop.h"

#include <stdio.h>

lss_i32 file_open( lss_cstr fname, lss_u32 flags )
{
	lss_i32 fd = 0;

	fd = open( fname, flags );
	/// error check
	if( 0 > fd )
	{
		printf( "open fail\n" );
		return -1;
	}

	return fd;
}

lss_i32 file_read( lss_u32 fd, lss_str buf, lss_u32 count )
{
	lss_i32 ret = 0;
	ret = read( fd, buf, count );
	if( -1 == ret )
	{
		printf( "read fail\n" );
		return -1;
	}
	/// ret value -1 : read fail - error
	/// ret value 0 : EOF
	/// ret value > 0 : read bytes
	return ret;
}

lss_i32 file_write( lss_u32 fd, lss_cstr buf, lss_u32 count )
{
	lss_i32 ret = write( fd, buf, count );
	if( -1 == ret )
	{
		printf( "write fail\n" );
		return -1;
	}
	/// ret value -1 : fail
	/// ret value > 0 : write bytes
	return ret;
}

lss_i32 file_close( lss_u32 fd )
{
	lss_i32 ret = 0;
	ret = close( fd );
	/// error check
	if( 0 != ret )
	{
		printf( "close fail\n" );
		return -1;
	}

	return ret;
}




