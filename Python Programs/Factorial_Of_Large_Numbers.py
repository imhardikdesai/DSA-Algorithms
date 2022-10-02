######################################
# FACTORIAL OF LARGE NUMBERS
######################################

''' NOTE:- The basic idea of this topic is to
    make the basics clear about the datatype
    storage limits.'''


def factorial(value):
    ans = [1]                                   #As no numerical datatype can hold 100!. So we keep our result in a list
                                                #Each element of this list will be the answer.
    carry = 0
    while (value-1 != 0):                       #value-1 is beacuse a*1 = a i.e. 3! = 3*2*1 = 3*2
        for index in range(len(ans)):
            res = ans[index]*value + carry      #Multiply and carry(basic multiplication)
            ans[index] = int(res%10)            #Stores first digit of result in list.
            carry = int((res-(res%10))/10)      #carry will be added to next multiply
        if (carry != 0):                        #If carry is still left after multiplying all elements
            carry = str(carry)
            for i in range(len(carry)):         #Our list is calculating in reverse order
                                                #So carry should be added at the end in same order.
                ans.append(int(carry[-1-i]))
            carry = 0
        value = value-1
    result = ""
    ans.reverse()
    for element in ans:
        result = result+str(element)
    print("Value:-",result)    
    print("No of digits:",len(ans))

######Main_function#####
value = int(input("Enter the value:"))
factorial(value)
