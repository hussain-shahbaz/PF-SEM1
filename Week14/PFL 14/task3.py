def areaOfCountry(name,area):
    world_landmass=float((area/148940000)*100)
    return world_landmass
name=input("Enter The Name Of Country: ")
area=int(input("Enter The Area Of Country: "))
print(f"{name} is {areaOfCountry(name,area)} % of the total world landmass.")