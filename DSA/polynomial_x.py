#python program to add polynomials and multiply em too :DDDDD #hopeful 
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

def search(arr,z,x):
    j=0
    while j<z:
        if x==arr[j][1]:
            return j
        else:
            j+=1
    return -1
            

def poly_add():
    for i in range(n):
        x=a[i][1]
        z,arr=m,b 
        index=search(arr,z,x)
        #print("run 1:- ",index)
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
        z,arr=n,a
        t=[]
        index=search(arr,z,x)
        #print(index,":- 2nd run")
        if index==-1:
            for l in range (2):
                t.append(b[i][l])
            s.append(t)

def print_add():
    print("The added polynomial is:-")
    for i in range (2):
        for j in range (len(s)):
            print(s[j][i],end="\t")
        print()

def main():
    accept_a()
    print(a)
    accept_b()
    print(b)
    print_a()
    print_b()
    poly_add()
    print_add()

main()
