#ifndef __INSERTION_SORT_H__
#define __INSERTION_SORT_H__

/*------------------------------------------------------------------------------
 * function:    insertion_sort
 *------------------------------------------------------------------------------
 * return:      void
 * @array:      the array of elements to sort
 * @nmemb:      number of elements in the array
 * @size:       size (in bytes) of each element
 * @compar:     comparison function
 *              - returns a negative value if first < second
 *              - returns a positive value if first > second
 *              - returns zero if first = second
 *------------------------------------------------------------------------------
 * runtime:     O(n^2)
 * space:       O(1)
 *------------------------------------------------------------------------------
 * This function takes in an array of values and sorts them. It selects elements
 * from the right side of the array and inserts them into the left side of the
 * array while maintaining the invariant that the left side remains sorted.
 *----------------------------------------------------------------------------*/
void
insertion_sort(void *array, 
               size_t nmemb,
               size_t size,
               int (*compar)(const void *, const void *));

#endif
