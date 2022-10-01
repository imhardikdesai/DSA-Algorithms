#Bubble sort algorithm takes an unsorted list and orders it in an increasing order.
#This is done by comparing any 2 values at a given time (from left to right)

def bubble_sort(list1):
    indexing_length = len(list1)-1
    #Can not perfrom comparison on the last number of the list.
    sorted=False
    #This variable in the control flow with break us out whenever needed.

    while not sorted:
        #Unknown amount of iterations are required.
        sorted = True
        for i in range(0,indexing_length):
            if list1[i]>list1[i+1]:
                #Comparisonof left and right
                sorted = False
                list1[i],list1[i+1] = list1[i+1],list1[i]
                #Switching the number accordingly

    return list1

print(bubble_sort([6,23,34,41,24,30,10]))