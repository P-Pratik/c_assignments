def knapSack(W, wt, val, n):
	if n == 0 or W == 0:
		return 0
	if (wt[n-1] > W):
		return knapSack(W, wt, val, n-1)
# C[n, M] = max(profits for case 1,profits for case 2) = max(C[n-1, M], C[n-1, M - wtn ] + pn).

	else:
		return max(
			val[n-1] + knapSack(
				W-wt[n-1], wt, val, n-1),
			knapSack(W, wt, val, n-1))

profit = [60, 100, 120]
weight = [10, 20, 40]

W = 50
n = len(profit)
print (knapSack(W, weight, profit, n))