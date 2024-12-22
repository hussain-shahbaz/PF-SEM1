f = open("file.txt",'w')
while(True):
    name = input("Please enter Names: (press q to exit): ")
    if(name == "q"):
        break
    f.write(name)
    f.write("\n")
f.close()
