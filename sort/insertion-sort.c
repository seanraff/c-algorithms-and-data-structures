typedef __SIZE_TYPE__ size_t;
extern void *memcpy(void *, void *, size_t);
extern void *malloc(size_t);
extern void free(void *);

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
               int (*compar)(const void *, const void *))
{
    /* Allocate constant space to hold each value we insert */
    void *value = malloc(size);
    /* Select each element from the right side of the array and insert it
     * into the left side, maintaining the invariant that the left side
     * is sorted. Note that the left side is originally (trivially) sorted */
    for (size_t i = size; i < nmemb * size; i += size) {
        /* Selection of element */
        memcpy(value, array + i, size);
        size_t hole = i;
        /* Find the proper location while shifting elements to make room */
        while (hole > 0 && compar(value, array + hole - size) < 0) {
            memcpy(array + hole, array + hole - size, size);
            hole -= size;
        }
        /* Insert our element into its location */
        memcpy(array + hole, value, size);
    }
    free(value);
}
