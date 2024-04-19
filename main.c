#include "matrix_multiplication.h"

int main(int argc,char* argv[])
{   
    
    //insizlize names
    char* infile1 = malloc(64);
    char* infile2 = malloc(64);
    char* out_file = malloc(64);    
    //case of ./MatMul inMartix1 inMartix2 outMatrix
    if(argc == 4)
    {	
    	strcpy(infile1, argv[1]);
    	strcpy(infile2, argv[2]);
    	strcpy(out_file, argv[3]);

    }
    //case of ./MatMul 
    else if(argc == 1)
    {	//defult values of files a b c
        strcpy(infile1, "a");
    	strcpy(infile2, "b");
    	strcpy(out_file, "c");
        
    }
    //False case
    else
    {
        printf("unknown input format\nUsage: ./matMultp Mat1 Mat2 MatOut\nor ./matMultp set input to a b c");
        exit(EXIT_FAILURE);//exit of program
    }
    
    matrix_t mat1,mat2,resultMat;
    struct timeval stop, start;
    mat1 = read_matrix_from_file(string_concat(infile1,".txt"));
    mat2 = read_matrix_from_file(string_concat(infile2,".txt"));
    
    gettimeofday(&start, NULL); //start checking time
    
    resultMat = perMatrix(mat1,mat2);//running method 1
    write_matrix_to_file(&resultMat ,string_concat(out_file,"_per_matrix.txt"));
    
    gettimeofday(&stop, NULL); //end checking time
    printf("for thread per matrix\n");
    printf("Seconds taken %lu\n", stop.tv_sec - start.tv_sec);
    printf("Microseconds taken: %lu\n", stop.tv_usec - start.tv_usec);

    gettimeofday(&start, NULL); //start checking time

    perRow(&mat1,&mat2,&resultMat);
    write_matrix_to_file(&resultMat ,string_concat(out_file,"_per_row.txt"));
    	
    gettimeofday(&stop, NULL); //end checking time
    printf("for thread per row\n");
    printf("Seconds taken %lu\n", stop.tv_sec - start.tv_sec);
    printf("Microseconds taken: %lu\n", stop.tv_usec - start.tv_usec);

    gettimeofday(&start, NULL); //start checking time
    perElement(&mat1,&mat2,&resultMat);
    write_matrix_to_file(&resultMat ,string_concat(out_file,"_per_element.txt"));
    	
    gettimeofday(&stop, NULL); //end checking time
    printf("for thread per element\n");
    printf("Seconds taken %lu\n", stop.tv_sec - start.tv_sec);
    printf("Microseconds taken: %lu\n", stop.tv_usec - start.tv_usec);

    // Free dynamically allocated memory
    free(infile1);
    free(infile2);
    free(out_file);
    
    return 0;
}
