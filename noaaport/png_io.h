/*
 * This file declares the public interface of the png_io module.
 */
#ifndef PNG_IO_H
#define PNG_IO_H

#include "png.h"
#include "md5.h"

#ifdef __cplusplus
extern "C" {
#endif

int png_get_prodlen();

void png_header(char *memheap,int length);

void unidata_output_flush_fn(png_structp png_p);

void write_row_callback(png_structp pngp,png_uint_32 rownum,int pass);

void unidata_write_data_fn(png_structp png_p, png_bytep data, png_uint_32 length);

void png_set_memheap(char *memheap,MD5_CTX *md5ctxp);

void pngout_init(int width,int height);

void pngout_end();

void pngwrite(char *memheap);

#ifdef __cplusplus
}
#endif

#endif
