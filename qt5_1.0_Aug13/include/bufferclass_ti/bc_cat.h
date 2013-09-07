/*
 * bc_cat.h
 *
 * This is a header file supporting buffer class streaming extension. 
 * Useful for video texturing.
 * Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/ 
 * 
 * 
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the   
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/


#ifndef __BC_CAT_H__
#define __BC_CAT_H__

#include <linux/ioctl.h>

#define BC_FOURCC(a,b,c,d) \
    ((unsigned long) ((a) | (b)<<8 | (c)<<16 | (d)<<24))

#define BC_PIX_FMT_NV12     BC_FOURCC('N', 'V', '1', '2') /*YUV 4:2:0*/
#define BC_PIX_FMT_UYVY     BC_FOURCC('U', 'Y', 'V', 'Y') /*YUV 4:2:2*/
#define BC_PIX_FMT_YUYV     BC_FOURCC('Y', 'U', 'Y', 'V') /*YUV 4:2:2*/
#define BC_PIX_FMT_RGB565   BC_FOURCC('R', 'G', 'B', 'P') /*RGB 5:6:5*/

enum BC_memory {
    BC_MEMORY_MMAP          = 1,
    BC_MEMORY_USERPTR       = 2,
};

typedef struct BCIO_package_TAG {
    int input;
    int output;
}BCIO_package;

/* 
 * the following types are tested for fourcc in struct bc_buf_params_t
 *   NV12
 *   UYVY
 *   RGB565 - not tested yet
 *   YUYV
 */
typedef struct bc_buf_params {
    int count;              /*number of buffers, [in/out]*/
    int width;              /*buffer width in pixel, multiple of 8 or 32*/
    int height;             /*buffer height in pixel*/
    unsigned int fourcc;    /*buffer pixel format*/
    enum BC_memory type;
} bc_buf_params_t;

typedef struct bc_buf_ptr {
    unsigned int index;
    int size;
    unsigned long pa;
} bc_buf_ptr_t;

#define BCIO_GID                    'g'
#define BC_IOWR(INDEX)            _IOWR(BCIO_GID, INDEX, BCIO_package)

#define BCIOGET_BUFFERCOUNT       BC_IOWR(0)  /*obsolete, since BCIOREQ_BUFFERS
                                                return the number of buffers*/
#define BCIOGET_BUFFERPHYADDR     BC_IOWR(1)  /*get physical address by index*/
#define BCIOGET_BUFFERIDX         BC_IOWR(2)  /*get index by physical address*/

#define BCIOREQ_BUFFERS           BC_IOWR(3)
#define BCIOSET_BUFFERPHYADDR     BC_IOWR(4)

#endif 

