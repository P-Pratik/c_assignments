'''
Write a python program to store first year percentage of students in array. Write function fo sorting array of floating point numbers in ascending order using
a) Selection sort
b) Bubbly sort and display top five scores
'''

def accept():
    global n,marks
    print("enter the marks of students <use space to seperate each student>  ")
    marks=list(map(float,input().split()))
    n=len(marks)

def selection_sort():
    for i in range(n):
        min_index = i
        for j in range(i+1, n):
            if marks[j] < marks[min_index]:
                min_index = j
        marks[i], marks[min_index] = marks[min_index], marks[i]

def bubble_sort():
    for j in range(n):
        for i in range (n-j-1):
            if marks[i]>marks[i+1]:
                marks[i],marks[i+1]=marks[i+1],marks[i]

def topper():
    print("The topper's are :- ")
    for i in range(5):    
        print(marks[n-i-1])

def main():
    text='MENU'
    print(f'{text:-^20}','\n1:Accept the marks\n2:Selection Sort \n3:Bubble Sort \n4:Print Toppers\n5:Exit Program')
    ch=1
    while ch!=5:
        ch=int(input("\nPlease Enter your choice:-\n"))
        if ch==1:
            accept()
        elif ch==2:
            selection_sort()
            print(marks)
        elif ch==3:
            bubble_sort()
            print(marks)
        elif ch==4:
            topper()
        elif ch==5:
            print("Exiting Program")
        else:
            print("Enter a valid choice")
main()
