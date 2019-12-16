#ifndef _iplib2_New_H_
#define _iplib2_New_H_

/* file types*/
#define PBM 4
#define PGM 5
#define PPM 6

typedef unsigned char *image_ptr;

image_ptr read_pnm(char *filename, int *rows, int *cols, int *type);
int getnum(FILE *fp);
void write_pnm(image_ptr ptr, char *filename, int rows, int cols, int type);
#endif //_iplib2_New_H_