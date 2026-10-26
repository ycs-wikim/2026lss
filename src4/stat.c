#include "stat.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <time.h>

void stat_function( lss_cstr pathname )
{
	/// 정보 획득을 위한 구조체 선언
	struct stat sb;
	/// lstat을 이용해서 링크 파일이라도 원본 정보를 획득
	if (lstat(pathname, &sb) == -1) {
		/// 획득 실패한 경우 
		perror("lstat");	/// 에러 출력
		exit(EXIT_FAILURE); /// 프로그램 종료
	}

	/// 획득된 정보를 출력
	printf("ID of containing device:  [%x,%x]\n",
					major(sb.st_dev),
					minor(sb.st_dev));

	printf("File type:                ");

	/// S_IFMT 마스크를 이용해서 정보 확인
	/// & 연산 -> AND bit 연산자
	///   110010101
	/// & 000010000	: mask
	/// ------------
	///   000010000
	switch (sb.st_mode & S_IFMT) {
			case S_IFBLK:  printf("block device\n");            break;
			case S_IFCHR:  printf("character device\n");        break;
			case S_IFDIR:  printf("directory\n");               break;
			case S_IFIFO:  printf("FIFO/pipe\n");               break;
			case S_IFLNK:  printf("symlink\n");                 break;
			case S_IFREG:  printf("regular file\n");            break;
			case S_IFSOCK: printf("socket\n");                  break;
			default:       printf("unknown?\n");                break;
	}

	printf("I-node number:            %ju\n", (uintmax_t) sb.st_ino);

	printf("Mode:                     %jo (octal)\n",
					(uintmax_t) sb.st_mode);

	printf("Link count:               %ju\n", (uintmax_t) sb.st_nlink);
	printf("Ownership:                UID=%ju   GID=%ju\n",
					(uintmax_t) sb.st_uid, (uintmax_t) sb.st_gid);

	printf("Preferred I/O block size: %jd bytes\n",
					(intmax_t) sb.st_blksize);
	printf("File size:                %jd bytes\n",
					(intmax_t) sb.st_size);
	printf("Blocks allocated:         %jd\n",
					(intmax_t) sb.st_blocks);

	printf("Last status change:       %s", ctime(&sb.st_ctime));
	printf("Last file access:         %s", ctime(&sb.st_atime));
	printf("Last file modification:   %s", ctime(&sb.st_mtime));

	/// exit는 강제로 프로세스를 무조건 종료
	/// main에서 아직 할 작업이 있기 때문에 주석처리
	//exit(EXIT_SUCCESS);
}

