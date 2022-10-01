#####################################
# LINEAR SEARCH
#####################################

#getting array input with integer elements.
array = input("Enter the elements(Use space to seperate):").split()

#value to find
value = input("Enter the value you want to search:")

#Note that both the array and value are holding string datatypes.

#Linear search
print("Value:"+value+" is at,")
validator = 0  #to check whether the element exists or not
for index in range(len(array)):
    if array[index] == value:
        validator = 1
        print("Index:",index)
if (validator == 0):   print("No index found")
        
        
