// Write a program non-recursive and recursive program to calculate Fibonacci numbers and analyze their time and space complexity.
// Name = Pratik Puri
// Roll no = 59

#include <iostream>
using namespace std;

void fibonacci(int n1, int n2, int terms)
{
    terms--;
    int n3;
    n3 = n1 + n2;
    cout << n1 << " ";
    if (terms >= 0)
        fibonacci(n2, n3, terms);
}

int main()
{
    // Method 1 : Non Recursive:

    int ch;
    int f1, f2, f3;
    f1 = 0;
    f2 = 1;
    cout << "Enter number of numbers to generate :";
    cin >> ch;
    cout << "non - recursive:- " << endl;
    cout << f1 << " " << f2 << " ";
    for (int i = 0; i < ch - 2; i++)
    {
        f3 = f1 + f2;
        cout << f3 << " ";
        f1 = f2;
        f2 = f3;
    }

    // Method 2 : Recursive

    cout << " \n \n \n ";
    cout << "recursive :" << endl;
    fibonacci(0, 1, ch - 1);
    cout << endl;
    return 0;
}

/*
Enter number of numbers to generate :6
non - recursive:-
0 1 1 2 3 5
Time Complexity = O(n)
Space Complexity = O(1)

recursive :
0 1 1 2 3 5
Time Complexity = O(2^n)
Space Complexity = O(n)
  */