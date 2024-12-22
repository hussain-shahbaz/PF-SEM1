def oddish_or_evenish(number):
    ans = 0
    while number > 0:
        rem = number % 10
        ans += rem
        number //= 10   
    if(ans%2!=0):
     return "Oddish"
    else :
     return "evenish"
num = int(input("Enter The Number To Check: "))
print(oddish_or_evenish(num))
