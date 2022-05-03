#include <stdio.h>
#include <stdlib.h>

    /**
 * C program to add two matrix using pointers.
 */

/*header data */



/* Function declaration to input, add, print and subtract matrix  */
void matrixInput(int**mat,int matsize);
void matrixPrint(int**mat,int matsize);
void matrixAdd(int**mat1, int**mat2, int**res, int matsize);
void matrixSub(int**mat1, int**mat2, int**res, int matsize);

/**
 * Function to read input from user and store in matrix.
 *
 * @mat     Two dimensional integer array to store input.
 */
void matrixInput(int**mat,int matsize)
{
    int i=0, j=0;


    for (i = 0; i < matsize; i++)
    {
        for (j = 0; j < matsize; j++)
        {
            // (*(mat + i) + j) is equal to &mat[i][j]
            scanf("%d", (*(mat + i) + j));
        }
    }
}

/**
 * Function to  INITIALISE a matrix address.
 *
 * @mat     Two dimensional integer array to print.
 */
 int**matrixInit(int matsize)
 {
     int**mat = calloc(matsize,sizeof(int*));
     return mat;

 }


/**
 * Function to print elements of matrix on console.
 *
 * @mat     Two dimensional integer array to print.
 */
void matrixPrint(int**mat,int matsize)
{

    int i=0, j=0;


    for (i = 0; i < matsize; i++)
    {
        for (j = 0; j < matsize; j++)
        {
            // *(*(mat + i) + j) is equal to mat[i][j]
            printf("%d ", *(*(mat + i) + j));
        }
        printf("\n");
    }
}

/**
 * Function to add two matrices and store their result in given res
 * matrix.
 *
 * @mat1    First matrix to add.
 * @mat2    Second matrix to add.
 * @res     Resultant matrix to store sum of mat1 and mat2.
 */
void matrixAdd(int**mat1, int**mat2, int**res, int matsize)
{
    int i=0, j=0;


    // Iterate over each matrix elements
    for (i = 0; i < matsize; i++)
    {
        for (j = 0; j < matsize; j++)
        {
            // res[i][j] = mat1[i][j] + mat2[i][j]
            (*(*(res + i) + j)) = (*(*(mat1 + i) + j)) + (*(*(mat2 + i) + j));
        }
    }
}

void matrixSub(int**mat1, int**mat2, int**res, int matsize)
{
    int i=0, j=0;


    // Iterate over each matrix elements
    for (i = 0; i < matsize; i++)
    {
        for (j = 0; j < matsize; j++)
        {
            // res[i][j] = mat1[i][j] - mat2[i][j]
            (*(*(res + i) + j)) = (*(*(mat1 + i) + j)) - (*(*(mat2 + i) + j));
        }
    }


}

//ALL ABOVE FUNCTIONS ARE TO BE PUT IN THE LIBARY

int main()
{
    int matsize;

    int**mat1;
    int**mat2;
    int**res1;
    int**res2;




    printf("Enter the size of the square matrices:\n");
    scanf("%d",&matsize);

    mat1 = matrixInit(matsize);
    mat2 = matrixInit(matsize);
    res1 = matrixInit(matsize);
    res2 = matrixInit(matsize);

    // Input elements in first matrix
    printf("Enter elements in first matrix of size %dx%d: \n", matsize, matsize);
    matrixInput(mat1,matsize);

    // Input element in second matrix
    printf("\nEnter elemetns in second matrix of size %dx%d: \n", matsize, matsize);
    matrixInput(mat2,matsize);

    // Finc sum of both matrices and print result
    matrixAdd(mat1, mat2, res1, matsize);

    printf("\nSum of first and second matrix: \n");
    matrixPrint(res1, matsize);


    //Find the difference of both matrices

    matrixSub(mat1, mat2, res2, matsize);

    printf("\nDifference of first and second matrix: \n");
    matrixPrint(res2, matsize);

    return 0;
}



