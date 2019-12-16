
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "iplib2New.h"

void image_analysis(image_ptr imagePtr, int row, int col, int width, int height, int rows, int cols, float *mean, float *sd);

int  	 main(int argc, char **argv)
{
         image_ptr imagePtr, imagePtr2;
         unsigned char ** output_image = NULL;  /* space for output image */
         char * output_filename = NULL;
         int factor = 0;
		float mean = 0;
		float sd = 0;
         int rows, cols, type;   
         int i=0, j=0,  value=0, count=0;
         int tp;
		 int n;

         /* check inputs */
         if (argc != 4)
         {
         printf("wrong inputs: use %s infile out1 out2 \n", argv[0]);  
         return 0;
         } 

/*       first read-in the image */
         printf("reading input image ... \n");

         imagePtr = read_pnm(argv[1], &rows, &cols, &type);

         printf("image read successfully \n");
         printf("rows=%d, cols=%d, type=%d \n", rows, cols, type);
         /* printf("rows=%d, cols=%d, type=%d \n", ROWS, COLS, TYPE); */
        output_filename = argv[2]; //output file = third arg
        factor = atoi(argv[3]); //factor = string to integer of arguemnt 4
		n = rows/factor; //n = dimension of reduced image
		
		//imageptr2 = allocates memory for reduced image 
		imagePtr2 = malloc(n*n*sizeof(unsigned char));
		
		//iterates over the entire image and inputs into image analysis
		for(int i=0; i<rows; i = i+factor){
			for(int j=0; j<cols; j = j+factor){
				image_analysis(imagePtr, i, j, factor, factor, rows, cols, &mean, &sd);
				imagePtr2[(i/factor) * n + j/factor] = mean;
			}
		}
		write_pnm(imagePtr2, output_filename, rows/factor, cols/factor, PGM); //writes to a file 
		image_analysis(imagePtr, 0, 0, rows, cols, rows, cols, &mean, &sd);
		printf("overall mean = %6.2f\n", mean); 
		printf("overall sd = %6.2f\n", sd);
return   0;
}

//image analsis = takes image, row colum of sub block, height and width of the subblock, rows and cols are dimensions of the original image
void image_analysis(image_ptr imagePtr, int row, int col, int width, int height, int rows, int cols, float *mean, float *sd) {
	float sum = 0;
	
	//calculate sum
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			sum += imagePtr[(row + i)*rows + col + j];
		}
	} 
	*mean = sum/(width*height);
	
	sum = 0;
	
	//calculate sd
	for(int i= 0; i< height; i++){
		for(int j=0; j<width;j++){
			sum += pow(imagePtr[(row + i)*rows + col + j]-*mean, 2);
		}
	}
	
	sum = 1.0/(width*height-1.0)*sum;
	*sd = sqrt(sum);
	
}