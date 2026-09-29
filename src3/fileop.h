#ifndef __FILEOP_H__
#define __FILEOP_H__

#include "../lss_types.h"

#include <fcntl.h>			/// open system call header
#include <unistd.h>			/// read, write, close system call header

/// file open wrapper function
//extern int file_open( const char* fname, int flags );
extern lss_i32 file_open( lss_cstr fname, lss_u32 flags );
extern lss_i32 file_read( lss_u32 fd, lss_str buf, lss_u32 count );
extern lss_i32 file_write( lss_u32 fd, lss_cstr buf, lss_u32 count );
extern lss_i32 file_close( lss_u32 fd );


#endif	// #ifndef __FILEOP_H__






