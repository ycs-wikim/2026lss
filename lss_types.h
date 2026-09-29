/// 윈도우에서 헤더가 중복으로 include 방지를 위한 전처리기
/// -> #pragma once
/// 리눅스에서는 전처리기 등을 지원하지 않음 -> 직접 작성

/// -> IF Not DEFinition
#ifndef __LSS_TYPES_H__
/// 아래 코드가 동작하려면 정의되지 않은 상태
/// __LSS_TYPES_H__가 정의되지 않았으니, 바로 정의
/// -> 중복으로 헤더가 포함될때 위의 문장이 거짓으로 결정
#define __LSS_TYPES_H__
/// 헤더에 포함되어야 할 내용을 추가 -> #endif 까지

/// 0. NULL 값을 정의
#define lss_null					(0)

/// 각종 자료형을 선언
/// 1. 문자 자료형
typedef char						lss_i8;
typedef unsigned char				lss_u8;
/// -> i : 부호가 있다는 의미
/// -> u : 부호가 없다는 의미
/// 8 : 실제 이 자료형의 byte 크기를 나타냄

/// 2. 숫자 자료형
typedef short						lss_i16;
typedef unsigned short				lss_u16;
typedef int							lss_i32;
typedef unsigned int				lss_u32;
typedef long						lss_long;
typedef unsigned long				lss_ulong;
typedef long long					lss_i64;
typedef unsigned long long			lss_u64;
/// 3. 소수점 자료형
typedef float						lss_float;
typedef double						lss_double;
/// 4. 특수 자료형
//typedef size_t						lss_size;

/// 리눅스에는 기본 bool 자료형이 없다!
/// -> 1 bit로 구성되지만, CPU에서 연산하려면 Padding
/// -> 하지만! bool 자료형을 사용하고 싶다!
/// -> #include <stdbool.h> : 굳이 사용하겠다면...

/// 5. bool 자료형 선언
typedef enum lss_bool_types
{
	lss_false	= 0,
	lss_true	= 1
} lss_bool;

/// 6. 포인터 자료형
typedef char*						lss_str;
typedef unsigned char*				lss_ustr;
typedef const char*					lss_cstr;
typedef const unsigned char*		lss_custr;
typedef void*						lss_ptr;
typedef const void*					lss_cptr;

/// 상수 정의 : 숫자 상수를 정의
#define STRLEN_4					4
#define STRLEN_8					8
#define STRLEN_16					16
#define STRLEN_24					24
#define STRLEN_32					32
#define STRLEN_48					48
#define STRLEN_64					64
#define STRLEN_128					128
#define STRLEN_256					256
#define STRLEN_512					512
#define STRLEN_1024					1024
#define STRLEN_2048					2048
/// linux kernel 메모리 할당 방법론에 의한 자료형 선언
#define PAGESIZE					4096
#define TWOPAGE						8192

#endif		// #ifndef __LSS_TYPES_H__

/// 자료형을 선언하는 헤더파일


