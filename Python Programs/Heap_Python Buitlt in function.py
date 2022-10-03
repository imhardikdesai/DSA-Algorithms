from heapq import heapify, heappop, heappush
# We have to create a one dimensional array and we can add the values from the other
heap = []
nums = [1, 5, 6, 89, 35, -2, 56]
# We can push the elements to the heap while it does the rest in in-Built
for num in nums:
    heappush(heap, num)

# We will pop and print the Heap sort by using the heappop method
while heap:
    print(heappop(heap))

# We can make the heap representation of an array using the heapify process
heapify(nums)
print(nums)
