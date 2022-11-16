'''Write a python program to store marks scored in subject " Data Structure and Algorithm" by N students in the class, Write functions to compute following:
a) The average score of the class
b) Highest score and lowest score of the class
c) Count of students who were absent for the test
d) Display marks with highest frequency'''

def store():
    global n,marks
    print("Enter the marks of students")
    marks=list(map(float,input().split()))
    n=len(marks)

def avg_marks():
    add=0
    for i in range(n):
        add+=marks[i]
    return add/n


def hi_lo():
    global high,low
    high=low=0
    for j in range(n):
        count=0
        for i in range (1+j,n):
            if marks[j]>=marks[i]:
                count+=1
        if count==n-1-j:
            high=marks[j]
            break

    for j in range(n):
        count=0
        for i in range (1+j,n):
            if marks[j]<=marks[i]:
                count+=1
        if count==n-1-j:
            low=marks[j]
            break

def absent():
    count=0
    for i in range(n):
        if marks[i]==0:
            count+=1
    return count

def hi_freq():
    mc=0
    for j in range(n):
        count=0
        for i in range (0+j,n):
            if marks[j]==marks[i]:
                count+=1
                if count>=mc:
                    mc=count
                    element=marks[j]
    return element,mc

def main():
    print("1.Store marks\n2.Average score of the class\n3.Highest Score\n4. Lowest Score\n5.Students that are absent\n6.Mark's with highest frequency\n")
    ch=0
    while ch!=7:
        ch=int(input("Select Your Choice:-\n"))
        if ch==1:
            store()
            hi_lo()
        elif ch==2:
            avgm=avg_marks()
            print("Average Performance of the class:-",avgm)
        elif ch==3:
            print("Highest Marks are {} in the class".format(high))
        elif ch==4:
            print("Lowest marks are {} in the class".format(low))
        elif ch==5:
            ab=absent()
            print("No of Absent Students :- ",ab)
        elif ch==6:
            hfreq_e,hfreq_t=hi_freq()
            #hfreq_t=mc
            print("The marks that occured the most number of times",hfreq_e,"and the number of times it occurred",hfreq_t,"times")
        elif ch==7:
            print("exiting program")
        else:
            print("Enter a valid choice")

main()