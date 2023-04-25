#include "sort.h"

/**
 * partition - array partition
 * @array: array to sort
 * @low: lowest index
 * @high: highest index
 * @size: array size
 * Return: int pivot index
 */
int partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j, temp;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;

            print_array(array, size);
        }
    }

    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    print_array(array, size);

    return (i + 1);
}

/**
 * quicksort - sorts an array of integers recursively
 * @array: array to sort
 * @low: lowest index
 * @high: highest index
 * @size: array size
 */
void quicksort(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot = partition(array, low, high, size);

        quicksort(array, low, pivot - 1, size);
        quicksort(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort - sorts an array of integers using the Quick
 * sort algorithm in ascending order
 * @array: array to sort
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort(array, 0, size - 1, size);
}
