#include <iostream>
#include <math.h>
using namespace std;

// Hamming code parity bits calculation
void hamming(int data[], int n)
{
    int r = 0;
    while ((1 << r) < (n + r + 1)) {
        r++;
    }

    int code[n + r];
    int j = 0;
    for (int i = 0; i < n + r; i++) {
        if ((i + 1) == (1 << r)) {
            code[i] = 0;
            r--;
        } else {
            code[i] = data[j];
            j++;
        }
    }

    for (int i = 0; i < (n + r); i++) {
        if ((i + 1) != (1 << r)) {
            int parity = 0;
            for (int j = i; j < (n + r); j += ((i + 1) * 2)) {
                for (int k = j; k < (j + (i + 1)) && k < (n + r); k++) {
                    parity ^= code[k];
                }
            }
            code[i] = parity;
        }
    }

    cout << "Hamming code: ";
    for (int i = 0; i < (n + r); i++) {
        cout << code[i];
    }
    cout << endl;
}




int main()
{
    int data[7];
    cout << "Enter 7-bit ASCII code: ";
    for (int i = 0; i < 7; i++) {
        cin >> data[i];
    }

    hamming(data, 7);

    return 0;
}
