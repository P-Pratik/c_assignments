#python program to add polynomials
'''
test case= 3x^2 + 4x + 2  b= 5x + 4 
expected answer = 3x^2 + 9x + 6 
'''

a=[]
b=[]
s=[]

def accept_a():
    global n
    n=int(input("enter the number of terms in polynomial 1"))
    for i in range (n):
        for j in range (1):
            y=list(map(int,input().split()))
        a.append(y)

def accept_b():
    global m
    m=int(input("enter the number of terms in polynomial 1"))
    for i in range (m):
        for j in range (1):
            y=list(map(int,input().split()))
        b.append(y)

def print_a():
	print("The first polynomial is:-")
	for i in range (2):
		for j in range (n):
			print(a[j][i],end=" ")
		print()

def print_b():
	print("The second polynomial is:- ")
	for i in range (2):
		for j in range (m):
			print(b[j][i],end=" ")
		print()

def binary_search(b, x):									#non-recursive binary search
	low = 0
	high =len(b)-1
	mid = 0
	while low<=high:
		mid = (low+high)//2
		if b[mid][1] < x:
			low = mid + 1
		elif b[mid][1] > x:
			high = mid - 1
		else:
			return mid
	return -1

def binary_search(a, x):									#non-recursive binary search
	low = 0
	high =len(a)-1
	mid = 0
	while low<=high:
		mid = (low+high)//2
		if a[mid][1] < x:
			low = mid + 1
		elif a[mid][1] > x:
			high = mid - 1
		else:
			return mid
	return -1

def search():
	k=0
	for i in range(m):
		if a[k][1]==b[i][1]:
			return i
		else:
			k+=1
	return -1
			

def poly_add():
	for i in range(n):
		x=a[i][1]
		#print("first run:= x:",x) 
		index=binary_search(b,x)
		#print(index)
		t=[]
		if index==-1:
			for l in range (2):
				t.append(a[i][l])
		else:
			t.append(a[i][0]+b[index][0])
			t.append(a[i][1])
		s.append(t)
	for i in range(m):
		x=b[i][1]
		t=[]
		index=binary_search(a,x)
		#print(index,":- 2nd run")
		if index==-1:
			for l in range (2):
				t.append(b[i][l])
			s.append(t)


'''		t=[]
		for k in range(m):
			if a[i][1]==b[k][1]:
				t.append(a[i][0]+b[k][0])
				t.append(a[i][1])
				break
			else: 
				for l in range (2):
					t.append(a[i][l])
				break
		s.append(t)
		t=[]
		for k in range(n):
			if b[i][1]!=a[k][1]:
				t.append(b[i][1])
				break
		s.append(t)'''

def print_add():
	print("The added polynomial is:-")
	for i in range (2):
		for j in range (len(s)):
			print(s[j][i],end="\t")
		print()

def main():
	accept_a()
	accept_b()
	print_a()
	print_b()
	poly_add()
	print_add()

main()
