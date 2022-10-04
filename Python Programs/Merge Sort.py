def mergeSort(nums):
    # This is the dividing part of this algorithm
    # This is the base case for this algorithm
    if len(nums) == 1:
        return
    # We define the middle index
    middle_index = len(nums)//2
    # We will have the 2 sub arrays
    left_half = nums[: middle_index]
    right_half = nums[middle_index:]
    # We call the merge sort recursively until every element is a single array
    mergeSort(left_half)
    mergeSort(right_half)
    # This is the conquer part
    # We define variables
    # i is for the left sub array
    i = 0
    # j is for the right sub array
    j = 0
    # k is for the temporary array
    k = 0
    # We check both the arrays looking for the smallest item
    while i < len(left_half) and j < len(right_half):
        # If we find the item in the left half
        if left_half[i] < right_half[j]:
            # We assign the value to the nums
            nums[k] = left_half[i]
            i += 1
        # If we find it in the right half
        else:
            # We assign the values to the nums
            nums[k] = right_half[j]
            j += 1
        k += 1
    # At last we check are there are any elements left in the right sub array
    # If they are we get them to the nums array
    while i < len(left_half):
        nums[k] = left_half[i]
        i += 1
        k += 1
    # We also check for the left over items in the left sub-array
    while j < len(right_half):
        nums[k] = right_half[j]
        j += 1
        k += 1


nums = [1, 5, 3, -8, 9, 65, -74, 12, 2]
mergeSort(nums)
print(nums)
