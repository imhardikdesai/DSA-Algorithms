def swap(arr, index1, index2):
    arr[index1], arr[index2] = arr[index2], arr[index1]


def selectionSort(arr):
    for i in range(len(arr)-1):
        index = i
        for j in range(i+1, len(arr)):
            if arr[j] < arr[index]:
                index = j
        if index != i:
            swap(arr, index, i)
    return arr


arr = [1, 5, 3, -8, 9, 65, -74, 12, 2]
x = selectionSort(arr)
print(x)
