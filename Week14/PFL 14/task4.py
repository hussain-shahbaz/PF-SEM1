def length_of_num(num):
    count = 0
    while num > 0:,
        num = num // 10  
        count += 1
    return count  

number = int(input("Enter the number to count its length: "))
length = length_of_num(number)
print("The length of the number is:",length)



def lenghtNum(num):
    count = 0
    while(num!=0):
        count +=1
        num//=10
    return count
print(lenghtNum(50))