/// version number define
#define MAJOR_VERSION		3
#define MINOR_VERSION		9
#define PATCH_VERSION		2
#define CUSTOM_VERSION		123

/*
	0000 0000 0000 0000	0000 0000 0000 0000
	^^^^ #### #### @@@@ @@@@ **** **** ****
	#### #### @@@@ @@@@ **** **** **** 0000
	0000 0000 0000 0000	0000 0000 0000 #### // 28

	^^^^ #### #### @@@@ @@@@ @*** **** ****
	^^^^ #### #### @@@@ @@@@ @@** **** ****
		  <-------------------------   0011
    0011
	^ : Major version
	# : minor version
	@ : patch version
	* : custom version
*/
#include "../lss_types.h"


/// major version maker: 해당 위치로 값을 이동시키는 매크로. 직접 사용하지 않음
#define MAV_MAKER(V)				((lss_u32)V<<28)
#define MIV_MAKER(V)				((lss_u32)V<<20)
#define PAT_MAKER(V)				((lss_u32)V<<12)
#define CUS_MAKER(V)				((lss_u32)V&0xFFF)

/// 위의 매크로를 이용해서 단일 값에 버전을 만드는 매크로
#define VERSION_MAKER(M,m,p,c)		((lss_u32)(MAV_MAKER(M)|\
									MIV_MAKER(m)|\
									PAT_MAKER(p)|\
									CUS_MAKER(c)))

/// 버전 정보를 쪼개서 원하는 버전 번호를 획득하는 매크로
#define MAJOR_GET_VERSION(V)		((lss_u32)V>>28)
#define MINOR_GET_VERSION(V)		((lss_u32)(V<<4)>>24) //*
#define PATCH_GET_VERSION(V)		((lss_u32)(V<<12)>>24)	//*
#define CUSTOM_GET_VERSION(V)		((lss_u32)V&0xFFF)



