/* sort.c 
 *    Test program to sort a large number of integers.
 *
 *    Intention is to stress virtual memory system.
 *
 *    Ideally, we could read the unsorted array off of the file system,
 *	and store the result back to the file system!
 */

#include "syscall.h"

int A[1024];	/* size of physical memory; with code, we'll run out of space!*/

int
main()
{
    // int i, j, tmp;
    // //
    // int n;
    // do{
    //     PrintString("\nenter size of array: ");
    //     n = ReadInt();
    // }while (n < 0 || n > 100);
    // PrintString ("enter all element of array: \n");
    // for(i = 0; i < n; i++) {
    //     A[i] = ReadInt();
    // }
    // // /* first initialize the array, in reverse sorted order */
    // // for (i = 0; i < 1024; i++)		
    // //     A[i] = 1024 - i;

    // /* then sort! */
    // for (i = 0; i < n; i++)
    //     for (j = i; j < (n - i); j++)
	//     if (A[j] > A[j + 1]) {	/* out of order -> need to swap ! */
    //         tmp = A[j];
    //         A[j] = A[j + 1];
    //         A[j + 1] = tmp;
    //         }
    // PrintString ("Array after sort ascending\n");
    // for (i = 0; i < n; i++) {
    //     PrintInt(A[i]);
    //     PrintChar(' ');
    // }
    Halt();
    //Exit(A[0]);		/* and then we're done -- should be 0! */
}
