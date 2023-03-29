#include<stdio.h>
/***********************************************************STD_TYPES****************************************************************************************/
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned long  int uint32_t;
typedef signed char int8_t;
typedef signed short int int16_t;
typedef signed long  int int32_t;

/*********************************************************function prototypes*********************************************************************************/
/* Description:
 * - This function takes a reference to an array of integers
 * - Sorts the array in ascending order
 * - Using the insertion sort algorithm
 * Return:
 * - returns -1 if the array is empty
 * - returns -2 if the array size is 0 or >10
 * - returns 0 if sorting is done without errors
 */
int8_t insertionSort(int32_t *array, uint8_t arraySize);
/*************************************************************************************************************************************************************/
/* Description:
 * - This function takes a reference to an array of integers
 * - Prints all array elements
 * Return:
 * - Nothing to return
 */
void printArray(int32_t *array, uint8_t arraySize);
/******************************************************************************************************************************************************************/
/* Description:
 * - This function takes a reference to an array,
 * - array size, and
 * - reference to store the size of the LCS
 * - Using the insertion sort algorithm
 * - The function will search for the LCS in the array and
 * - stores its size
 * Return:
 * - returns -1 if the array is empty
 * - returns -2 if the array size is 0 or >10
 * - returns -3 if there is no LCS,
 * (i.e all array elements are not consecutive at all)
 * - returns 0 otherwise
 */
int8_t lcsGetSize(int32_t *array, uint8_t arraySize, uint8_t *sizeofLCS);
/****************************************************************************************************************************************************************/
#define max_size 100
/************************************************************************************************************************************************************/
void main(void)
{
int32_t arr[max_size];
uint8_t size_array,size_lcs=0;
int8_t return_status;
printf("please enter your array size\n");


scanf("%d",&size_array);

printf("\nplease enter your array\n");

    for(uint8_t i=0;i<size_array;i++)
{

    scanf("%d",&arr[i]);
}
printArray(arr,size_array);
return_status=lcsGetSize(arr,size_array,&size_lcs);
if(return_status==-1)
{
    printf("\nan empty array\n");
}
if(return_status==-2)
{
    printf("\ninvalid size\n");
}
if(return_status==-3)
{
    printf("\nno consecution\n");
}
if(!return_status)
{
    printf("\nthe new sorted array\n");
    printArray(arr,size_array);
    printf("\nthe size of consecution is:%d",size_lcs);

}

}

int8_t insertionSort(int32_t *array,uint8_t arraySize)
{
    int i, key, j;
    if(arraySize==0 || arraySize>10)
    {
        return -2;
    }
    else
    {
        for (i = 1; i < arraySize; i++)
         {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key)
            {
            array[j + 1] = array[j];
            j = j - 1;
            }
        array[j + 1] = key;
          }
          return 0;
    }

}
/***********************************************************************************************************************************************/

void printArray(int32_t *array, uint8_t arraySize)
{
    for(uint8_t index_i=0;index_i<arraySize;index_i++)
    printf("%d\t",array[index_i]);
}

/*********************************************************************************************************************************/

int8_t lcsGetSize(int32_t *array, uint8_t arraySize, uint8_t *sizeofLCS)
{
    uint8_t index_i,count=0;
    int8_t status;
    status=insertionSort(array,arraySize);
    if(status==-2)
    {
        return -2;
    }
     if(status==-1)
    {
        return -1;
    }
    if(!status)
    {
        for(index_i=0;index_i<arraySize;index_i++)
    {
        if(array[index_i+1]-array[index_i]==1)
        {
            count++;
            if(*sizeofLCS<count)
            {
                *sizeofLCS=count+1;
            }
        }
        else
        {
            count=0;
        }
    }
    if(*sizeofLCS==0)
    {
        return -3;
    }
        return 0;
    }

}
