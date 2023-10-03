#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
    else
        return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),
                   knapSack(W, wt, val, n - 1));
}

int main()
{
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    int profit[n], weight[n];
    cout << "Enter profits and weights for each item:\n";
    for (int i = 0; i < n; ++i)
        cin >> profit[i] >> weight[i];

    int W;
    cout << "Enter the knapsack capacity: ";
    cin >> W;

    cout << "Maximum value: " << knapSack(W, weight, profit, n) << endl;
    return 0;
}
