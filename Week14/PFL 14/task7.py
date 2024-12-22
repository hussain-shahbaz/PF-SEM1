 
def like_or_dislike(numberoftimes):

    state= "Nothing"
    for i in range(0, numberoftimes, 1):
        b=input("Enter like or dislike: ")
        if b=="like":
            if state=="Like":
                state="Nothing"
            else:
                state="Like"

        elif b=="dislike":
            if state=="Dislike":
                state="Nothing"
            else:
                state="Dislike"
    return state
n = int(input("Enter the number of inputs you want to enter: "))
buttons=like_or_dislike(n)
print(buttons)