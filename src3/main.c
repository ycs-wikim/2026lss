#include "fileop.h"

#include <stdio.h>
#include <errno.h>			/// errno header
#include <string.h>			/// strerror() header
#include <unistd.h>			/// for lseek system call

lss_i32 main( void )
{
	lss_i32 fd = 0;
	lss_i32 ret = 0;
	lss_i8 buf[ STRLEN_128 ] = { 0, };
/*
/// close( )로 닫으면 안되는 FD를 닫을 수 있게 만든 이유
	/// 특정 프로그램에서는 반드시 닫아야 정상 동작하므로
	close( 0 );		/// standard input : scanf( )의 입력
	close( 1 );		/// standard output : printf( )의 출력
	close( 2 );		/// standard error : printf( )의 출력
*/
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
	fd = file_open( "fileop.h", O_RDWR );
	printf( "FD : %d\n", fd );
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

	/// file pointer move
	off_t offset = 0;
	offset = lseek( fd, STRLEN_128, SEEK_END );
	if( -1 == offset )
	{
		printf( "lseek fail\n" );
		file_close( fd );
		return -1;
	}
	/// buf의 null 초기화
	/// buf : 초기화할 버퍼
	/// 0x00 : 0
	/// STRLEN_128 : 초기화할 범위
	memset( buf, 0x00, STRLEN_128 );

	/// file pointer가 정상적으로 이동했다.
	ret = file_write( fd, buf, STRLEN_128 );
	if( -1 == ret )
	{
		printf( "write fail\n" );
		return -1;
	}

	fd = file_close( fd );
	if( -1 == fd )
		return -1;

	printf("file operations success\n" );
	return 0;
}





