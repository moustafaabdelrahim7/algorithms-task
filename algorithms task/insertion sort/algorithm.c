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
#define max_size 100
/************************************************************************************************************************************************************/
void main(void)
{
int32_t arr[max_size];
int8_t return_status;
uint8_t size_array;
printf("please enter your array size\n");

scanf("%d",&size_array);

printf("\nplease enter your array\n");

for(uint8_t i=0;i<size_array;i++)
{

    scanf("%d",&arr[i]);
}

if(size_array==0 || size_array>10)
{
    printf("\ninvalid size");
}

return_status=insertionSort(arr,size_array);
if(!return_status)
{
printf("\nthe new sorted array\n");
printArray(arr,size_array);
}

}
/***********************************************func implementation**************************************************************************************/

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

