'''Write a python program to store second year percentage of students in array. Write function for sorting array. Write function for sorting array of floating point numbers in ascentding order using
a)Insertion sort 
b)Shell Sort and display top five scores'''

def accept():
    global n,marks
    print("enter the marks of students <use space to seperate each student>  ")
    marks=list(map(float,input().split()))
    n=len(marks)

def insertion_sort():
    for i in range (1,len(marks)):
        x=marks[i]
        j=i-1
        while j>=0 and x<marks[j]:
            marks[j+1]=marks[j]
            j-=1
        marks[j+1]=x

def shell_sort(marks, n):
	gap=n//2
	while gap>0:
		j=gap
		while j<n:
			i=j-gap
			while i>=0:
				if marks[i+gap]>marks[i]:
					break
				else:
					marks[i+gap],marks[i]=marks[i],marks[i+gap]
				i=i-gap
			j+=1
		gap=gap//2


def topper():
    print("The topper's are :- ")
    for i in range(5):    
        print(marks[n-i-1])

def main():
    text='MENU'
    print(f'{text:-^20}','\n1:Accept the marks\n2:Insertion Sort \n3:Shell Sort \n4:Print Toppers\n5:Exit Program')
    ch=1
    while ch!=5:
        ch=int(input("\nPlease Enter your choice:-\n"))
        if ch==1:
            accept()
        elif ch==2:
            insertion_sort()
            print(marks)
        elif ch==3:
            shell_sort(marks,n)
            print("Sorted List :-",marks)
        elif ch==4:
            topper()
        elif ch==5:
            print("Exiting Program")
        else:
            print("Enter a valid choice")
main()
