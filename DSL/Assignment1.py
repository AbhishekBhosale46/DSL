# PROBLEM STATEMENT
'''
In second year computer engineering class, group A student's
play cricket, group B students play badminton and group C
students play football.
Write a Python program using functions to compute
following: - a) List of students who play both cricket and
badminton b) List of students who play either cricket or
badminton but not both c) Number of students who play
neither cricket nor badminton d) Number of students who
play cricket and football but not badminton. (Note- While
realizing the group, duplicate entries should be avoided, Do
not use SET built-in functions)
'''

# CONVERTS LIST TO SET
def listToSet(lst):
    newList = []
    for i in lst:
        if i not in newList:
            newList.append(i)
    return newList

# INTERSECTION OF 2 SETS
def intersection(seta, setb):
    newList = []
    seta = listToSet(seta)
    setb = listToSet(setb)
    for a in seta:
        if a in setb:
            newList.append(a)
    return newList

# SYMMETRIC DIFF OF 2 SETS
def symmdiff(seta, setb):
    lst = []
    newlst = []
    seta = listToSet(seta)
    setb = listToSet(setb)
    inter = intersection(seta, setb)
    for a in seta:
        lst.append(a)
    for b in setb:
        lst.append(b)
    for i in lst:
        if i not in inter:
            newlst.append(i)
    return newlst

# PROBLEM 3 SOLUTION
def subprob3(seta, setb, setc, uniset):
    newList = []
    seta = listToSet(seta)
    setb = listToSet(setb)
    setc = listToSet(setc)
    uniset = listToSet(uniset)
    for c in setc:
        if c not in seta and setb:
            newList.append(c)
    for i in uniset:
        if i not in seta:
            if i not in setb:
                if i not in setc:
                    newList.append(i)
    return len(newList)

# PROBLEM 4 SOLUTION
def subprob4(seta, setb, setc):
    seta = listToSet(seta)
    setb = listToSet(setb)
    setc = listToSet(setc)
    newList = intersection(seta, setc)
    lst = []
    for i in newList:
        if i not in setb:
            lst.append(i)
    return len(lst)

# ADDS ELEMENT TO SET
def setter(num):
    lst = []
    for i in range(num):
        ele = int(input())
        lst.append(ele)
    lst = listToSet(lst)
    return lst

# DRIVER CODE
def main():
    numTotal = int(input("Enter total number of students : "))
    print("Enter the roll numbers of total students : ")
    universalset = setter(numTotal)

    numCricket = int(input("Enter total number of cricket students : "))
    print("Enter the roll numbers of cricket students : ")
    cricketset = setter(numCricket)

    numBadminton = int(input("Enter total number of badminton students : "))
    print("Enter the roll numbers of badminton students : ")
    badmintonset = setter(numBadminton)

    numFootball = int(input("Enter total number of football students : "))
    print("Enter the roll numbers of football students : ")
    footballset = setter(numFootball)

    while True:
        print("0] Exit")
        print("1] List of students who play both cricket and badminton")
        print("2] List of students who play either cricket orbadminton but not both")
        print("3] Number of students who play neither cricket nor badminton")
        print("4] Number of students who play cricket and football but not badminton")
        optn = int(input("Enter the option : "))

        if optn == 1:
            print(intersection(cricketset, badmintonset))
            continue
        elif optn == 2:
            print(symmdiff(cricketset, badmintonset))
            continue
        elif optn == 3:
            print(subprob3(cricketset, badmintonset, footballset, universalset))
            continue
        elif optn == 4:
            print(subprob4(cricketset, badmintonset, footballset))
            continue
        elif optn == 0:
            print("Exited...")
            break


if __name__ == "__main__":
    main()