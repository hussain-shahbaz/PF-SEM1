def make_Rug(row, column,proc):
    for i in range (0,row,1):
        for j in range(0,column,1):
            print(proc, end = ' ')
        print ()

h = int(input("Enter height: "))
w = int(input("Enter width: "))
choice = input("Do you want to enter a chracter(Yes/No): ")
if choice == "Yes" :
        proc = (input("Enter character: "))   
else:
    proc = '#'

make_Rug(h,w,proc)