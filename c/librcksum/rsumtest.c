/*
 *   zsync - client side rsync over http
 *   Copyright (C) 2005 Colin Phipps <cph@moria.org.uk>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the Artistic License v2 (see the accompanying 
 *   file COPYING for the full license terms), or, at your option, any later 
 *   version of the same license.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   COPYING file for details.
 */

#include "zsglobal.h"

#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include "rcksum.h"

// From RFC1320
const unsigned char correct_checksum[CHECKSUM_SIZE] = {0xbd, 0xe5, 0x2c, 0xb3, 0x1d, 0xe3, 0x3e, 0x46, 0x24, 0x5e, 0x05, 0xfb, 0xdb, 0xd6, 0xfb, 0x24 };

int main(void)
{
	unsigned char checksum[CHECKSUM_SIZE];
	rcksum_calc_checksum(checksum, (unsigned char*)"a", 1);
	exit(memcmp(checksum,correct_checksum,CHECKSUM_SIZE));
}
