a=[]
b=[]
s=[]
t=[]
sub=[]
mul=[]
def array1():
    global r1,c1
    r1=int(input("Enter the number of rows in matrix 1:- "))
    c1=int(input("Enter the number of columns is matrix 2:- "))
    print("Enter the elements of matrix 1")
    for _ in range(r1):
        k=[]
        for _ in range(c1):
            k.append(int(input()))
        a.append(k)

def p_array1():
    print("A Matrix = \n")
    for i in range(r1):
        for j in range(c1):
            print(a[i][j],end=" ")
        print()

def array2():
    global r2,c2
    r2=int(input("Enter the number of rows in arr:- "))
    c2=int(input("Enter the number of columns is arr:- "))
    print("Enter the elements of array 2")
    for _ in range(r2):
        k=[]
        for _ in range(c2):
            k.append(int(input()))
        b.append(k)

def p_array2():
    print("B Matrix = \n")
    for i in range(r2):
        for j in range(c2):
            print(b[i][j],end=" ")
        print()

def sum_array():
    if r1==r2 and c1==c2:
        for i in range(r1):
            k=[]
            for j in range(c1):
                d=a[i][j]+b[i][j]
                k.append(d)
            s.append(k)
        p_sum()
    else:
        print("The matrices cannot be added as they are unequal")

def p_sum():
    print("Sum of both Matrices is")
    for i in range(r1):
        for j in range(c1):
            print(s[i][j], end=" ")
        print()

def sub_array():
    if r1==r2 and c1==c2:
        for i in range(r1):
            k=[]
            for j in range(c1):
                d=a[i][j]-b[i][j]
                k.append(d)
            sub.append(k)
        p_sub()
    else: 
        print("The matrices cannot be subtracted as they are unequal")

def p_sub():
    print("Difference of both Matrices is")
    for i in range(r1):
        for j in range(c1):
            print(sub[i][j], end=" ")
        print()

def mul_array():
    if c1==r2:
        for i in range (c2):
            k=[]
            l=0
            for _ in range(c1):
                s=0
                for j in range (c1):
                    d=a[i][j]*b[j][l]
                    s+=d
                k.append(s)
                l+=1
            mul.append(k)
        p_mul()
    else:
        print("This array can't be multiplied")

def p_mul():
    print("multiplication of both Matrices is")
    for i in range(r1):
        for j in range(c2):
            print(mul[i][j], end=" ")
        print()

def trans_a():
    print("The Transpose of a matrix is :- \n")
    for i in range (c1):
        for j in range(r1):
            print(a[j][i], end=" ")
        print()

def trans_b():
    print("The Transpose of b matrix is :- \n")
    for i in range (c2):
        for j in range(r2):
            print(b[j][i], end=" ")
        print()

def main_menu():
    print("\n1:Addition of 2 Matrices\n2:Substraction of 2 Matrices\n3: Multiplication of 2 matrices\n4: Transpose of A matrix\n5: Transpose of B Matrix\n6:EXIT")

def main():
    array1()
    array2()
    p_array1()
    p_array2()
    main_menu()
    n=1
    while n!=6:
        n=int(input("Enter your Choice:- \n"))
        if n==1:
            sum_array()
        elif n==2:
            sub_array()
        elif n==3:
            mul_array()
        elif n==4:
            trans_a()
        elif n==5:
            trans_b()
        elif n==6:
            print("Exiting the program")
        else:
            print("Enter correct choice")
main()

