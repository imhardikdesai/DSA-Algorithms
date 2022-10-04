def swap(array, index1, index2):
    array[index1], array[index2] = array[index2], array[index1]


def partition(array, low, high):
    # we define the pivot index to be the middle of the array / sub-array
    pivot_index = (low + high)//2
    # We get the pivot element to the last
    swap(array, pivot_index, high)
    # We define the lower value to the i
    i = low
    # We iterate through the whole sub-array
    for j in range(low, high):
        # We check if the cur element is less than the pivot item
        # if we want the decreasing order we just change the sign to >
        if array[j] <= array[high]:
            # If it is we swap the lower value with the cur element
            swap(array, i, j)
            # We increment the i pointer
            i += 1
    # Finally we swap the pivot item with the low pointer
    swap(array, i, high)
    # This shall make a sub-array partially sorted
    return i


# We implement the quick sort with the recursion
def quickSort(array, low, high):
    # if the low index is greater than or equal it means there is an item in the array
    # or the array is empty
    if low >= high:
        return
    # We get the pivot index
    pivot_index = partition(array, low, high)
    # We call the quick sort on the left and the right sub arrays recursively
    quickSort(array, low, pivot_index-1)
    quickSort(array, pivot_index+1, high)


arr = [1, 5, 3, -8, 9, 65, -74, 12, 2]
quickSort(arr, 0, 8)
print(arr)
