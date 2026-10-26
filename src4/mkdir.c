#include "mkdir.h"

#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

void lss_mkdir( lss_cstr pathname, lss_u32 mode )
{
	/// 기본 권한을 755 권한으로 설정
	mode_t dir_mode = S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH;
	/// 전달된 모드가 존재하는지 여부를 확인
	if(0 != mode)
	{
		/// 전달된 모드로 현재 설정된 모드를 변경
		dir_mode = mode;
	}

	/// mkdir 시스템을 호출
	if( -1 == mkdir( pathname, dir_mode ) )
	{
		/// 오류가 발생한 경우, 오류 정보 출력
		fprintf( stderr, "mkdir error : %s\n", strerror( errno ) );
	}
}


