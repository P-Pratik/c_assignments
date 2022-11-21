'''write a python program to store names and mobile numbers of friends in sorted order on names. Search your friend from list using binary search(recursive and non-recursive). Insert friend if not present in phonebook.
write a python program to store names and mobile numbers of friends in sorted order on names. Search your friend from list using fibonacci search. Insert friend if not present in phonebook.'''


arr=[]

def store():
	n=int(input("Number of Entries (use format [name <space> phone number]):-"))
	print("Name    Phone Number")
	for i in range(n):
		friend=input()
		temp=friend.rstrip().split()
		arr.append(temp)

def binary_search(arr, x):									#non-recursive binary search
	low = 0
	high =len(arr)-1
	mid = 0
	while low<=high:
		mid = (low+high)//2
		if arr[mid][0] < x:
			low = mid + 1
		elif arr[mid][0] > x:
			high = mid - 1
		else:
			return mid
	return -1

def binary_search_r(arr,x,low,high):						#recursive binary search
	mid=(low+high)//2
	if arr[mid][0]==x:
		return mid
	elif arr[mid][0]<x:
		return binary_search_r(arr,x,low,mid)
	else:
		return binary_search_r(arr,x,mid,high)
	return -1

def bubble_sort():											#bubble sort
	m=len(arr)
	for i in range(m):
		for j in range(m-i-1):
			if arr[j]>arr[j+1]:
				arr[j],arr[j+1]=arr[j+1],arr[j]


def display():
	print("   Name\t\t\tPhone Number")
	for i in range(len(arr)):
		print("{}.".format(i+1),arr[i][0],"\t\t\t",arr[i][1])
	print("\n")

def search():
	temp=[]
	x=input("enter the element u need to search:-")
	element=binary_search(arr,x)
	if element>=0:
		print("Name = {} \nPhone Number= {}".format(arr[element][0],arr[element][1]))
	if element==-1:
		print("No Data for {} in the Phonebook. \nDo you want to add {} in the Phonebook? ".format(x,x))
		ch=input("(y/n)")
		if ch=='y':
			temp.append(x)
			friend=input('Enter the phone number of {} '.format(x))
			temp.append(friend)
			arr.append(temp)
		if ch=='n':
			print()


def search_r():
	x=input("enter the element u need to search:-  ")
	temp=[]
	element=binary_search_r(arr,x,0,len(arr)-1)
	if element>=0:
		print("Name = {} \nPhone Number= {}".format(arr[element][0],arr[element][1]))
	if element==-1:
		print("No Data for {} in the Phonebook. \nDo you want to add {} in the Phonebook? ".format(x,x))
		ch=input("(y/n)\n")
		if ch=='y':
			temp.append(x)
			friend=input('Enter the phone number of {} :- '.format(x))
			temp.append(friend)
			arr.append(temp)
		if ch=='n':
			print()

def fibonacci_search(arr,x):
	g=len(arr)
	start = -1
	f3=0
	f2=1
	f1=f2+f3
	while(f1<g):
		f3=f2
		f2=f1
		f1=f2+f3

	while(f1>1):
		i=min(start+f3,g-1)
		if (arr[i][1] < x):
			f1 = f2
			f2 = f3
			f3 = f1 - f2
			start = i
		elif arr[i][1] > x:
			f1=f3
			f2=f2-f3
			f3=f1-f2
		else:
			return i
	if(f2 and arr[g-1][1] == x):
		return g-1
	return -1

def search_f():
	temp=[]
	x=input('Enter the phone number:- ')
	element=fibonacci_search(arr,x)
	if element >= 0:
		print("Name: {}\nPhone Number: {}".format(arr[element][0],arr[element][1]))
	if element==-1:
		print("No Data for {} in the Phonebook. \nDo you want to add {} in the Phonebook? ".format(x,x))
		ch=input("(y/n):-\n")
		if ch=='y':
			friend=input('Enter the Name of {}:- '.format(x))
			temp.append(friend)
			temp.append(x)
			arr.append(temp)
		if ch=='n':
			print()


def main():
	print("1:Store Friends in PhoneBook\n2:Display Phonebook\n3:Search for a friend in phonebook(iterative)\n4:Search for a friend in phonebook(recursive)\n5:Search by Number(fibonacci search)\n6:Exit the Program\n")
	z=1
	while(z>=1 and z<=5):
		z=int(input("Enter the choice:-"))
		if z==1:
			store()
			bubble_sort()
		elif z==2:
			bubble_sort()
			display()
		elif z==3:
			search()
		elif z==4:
			search_r()
		elif z==5:
			search_f()
		else:
			print("Exiting program")

main()


