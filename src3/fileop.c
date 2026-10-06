#include "fileop.h"

#include <stdio.h>
#include <errno.h>
#include <string.h>

lss_i32 file_open( lss_cstr fname, lss_u32 flags )
{
	lss_i32 fd = 0;
	/// 함수 작성 시, 반드시 처리해야 하는 내용
	/// -> 전달 받은 인수의 유효성 검사
	do
	{
		/// 파일 경로가 잘못 전달되었는지 확인
		if( lss_null != fname )
		{
			/// 파일 개방 플래그가 잘못 되었는지 확인
			if( 0 <= flags )
				break;
		}
		return -1;
	} while( lss_false );

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

	do
	{
		if( 3 <= fd )
		{
			if( buf != lss_null )
			{
				if( 0 < count )
					break;	/// do ~ while 문장을 빠져나간다.
							/// 모든 인수가 정상 값을 갖는다.
			}
		}
		/// 인수 중에 정상적이지 않은 값이 존재한다.
		printf( "read parameter error\n" );
		return -1;
	} while( lss_false );

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
	do
	{
		if( 3 <= fd )
		{
			if( buf != lss_null )
			{
				if( 0 < count )
					break;	/// do ~ while 문장을 빠져나간다.
							/// 모든 인수가 정상 값을 갖는다.
			}
		}
		/// 인수 중에 정상적이지 않은 값이 존재한다.
		printf( "wrtie parameter error\n" );
		return -1;
	} while( lss_false );

	printf( "write : %d %p %d\n", fd, buf, count );

	lss_i32 ret = write( fd, buf, count );
	if( -1 == ret )
	{
		printf( "write fail[ %d ] %s\n", errno, strerror( errno ) );
		return -1;
	}
	/// ret value -1 : fail
	/// ret value > 0 : write bytes
	return ret;
}

lss_i32 file_close( lss_u32 fd )
{
	lss_i32 ret = 0;

	if( 3 > fd )
		return -1;

	ret = close( fd );
	/// error check
	if( 0 != ret )
	{
		printf( "close fail\n" );
		return -1;
	}

	return ret;
}




