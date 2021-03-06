/* CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License (the "License").
 * You may not use this file except in compliance with the License.
 *
 * You can obtain a copy of the license at src/license_cddl-1.0.txt
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at src/license_cddl-1.0.txt
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */

/* Copyright (c) 2014, Darran Hunt. All rights reserved. */

/*!	\file 	oled.h
*	\brief	OLED library header
*	Created: 15/2/2014
*	Author: Darran Hunt
*/

#ifndef BITSTREAM_H_
#define BITSTREAM_H_

#include <stdint.h>

typedef struct {
    uint8_t mask;		// pixel mask for returned data
    uint8_t bitsPerPixel;	// number of bits per pixel
    const uint16_t *_datap;	// Next data word to read
    uint16_t _size;		// number of pixels
    uint8_t _bits;		// current offset in data word
    uint8_t _wordsize;		// number of bits per data word
    uint16_t _word;
    uint16_t _count;
} bitstream_t;

void bs_init(bitstream_t *bs, const uint8_t bitsPerPixel, const uint16_t *data, const uint16_t size);
uint16_t bs_read(bitstream_t *bs, uint8_t numPixels);
uint16_t bs_available(bitstream_t *bs);

#endif
