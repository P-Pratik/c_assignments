a=[]
b=[]
s=[]
t=[]
sub=[]
mul=[]
r=int(input("Enter the number of rows in arr:- "))
c=int(input("Enter the number of columns is arr:- "))
def array1():
    print("Enter the elements of array 1")
    for i in range(r):
        k=[]
        for j in range(c):
            k.append(int(input()))
        a.append(k)

def p_array1():
    print("A Matrix = \n")
    for i in range(r):
        for j in range(c):
            print(a[i][j],end=" ")
        print()

def array2():
    print("Enter the elements of array 2")
    for i in range(r):
        k=[]
        for j in range(c):
            k.append(int(input()))
        b.append(k)

def p_array2():
    print("B Matrix = \n")
    for i in range(r):
        for j in range(c):
            print(b[i][j],end=" ")
        print()

def sum_array():
    for i in range(r):
        k=[]
        for j in range(c):
            d=a[i][j]+b[i][j]
            k.append(d)
        s.append(k)

def p_sum():
    print("sum of both Matrices is")
    for i in range(r):
        for j in range(c):
            print(s[i][j], end=" ")
        print()

def sub_array():
    for i in range(r):
        k=[]
        for j in range(c):
            d=a[i][j]-b[i][j]
            k.append(d)
        sub.append(k)

def p_sub():
    print("difference of both Matrices is")
    for i in range(r):
        for j in range(c):
            print(sub[i][j], end=" ")
        print()

def mul_array():
    for i in range(r):
        k=[]
        for j in range(c):
            d=a[i][j]*b[i][j]
            k.append(d)
        mul.append(k)

def p_mul():
    print("multiplication of both Matrices is")
    for i in range(r):
        for j in range(c):
            print(mul[i][j], end=" ")
        print()

def trans_a():
    print("The Transpose of a matrix is :- \n")
    for i in range (c):
        for j in range(r):
            print(a[j][i], end=" ")
        print()

def trans_b():
    print("The Transpose of b matrix is :- \n")
    for i in range (c):
        for j in range(r):
            print(b[j][i], end=" ")
        print()

def main_menu():
    print("\n1:Addition of 2 Matrices\n2:Substraction of 2 Matrices\n3: Multiplication of 2 matrices\n4: Transpose of A matrix\n5: Transpose of B Matrix\n6:EXIT")
    global n
    n=1

def main():
    array1()
    array2()
    p_array1()
    p_array2()
    main_menu()
    for n in range (6):
        n =int(input("Enter your Choice:- \n"))
        if n==1:
            sum_array()
            p_sum()
        elif n==2:
            sub_array()
            p_sub()
        elif n==3:
            mul_array()
            p_mul()
        elif n==4:
            trans_a()
        elif n==5:
            trans_b()
        else:
            print("Exiting the program")
        
main()

