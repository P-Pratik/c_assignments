# Print the board
def print_board(board, n):
	for i in range(n):
		for j in range(n):
			print(board[i][j], end = " ")
		print()

# Joining '.' and 'Q'
# making combined 2D Array
# For output in desired format
def add_sol(board, ans, n):
	temp = []
	for i in range(n):
		string = ""
		for j in range(n):
			string += board[i][j]
		temp.append(string)
	ans.append(temp)
	
def is_safe(row, col, board, n):
	x = row
	y = col
	
	# Check for same upper col
	while(x>=0):
		if board[x][y] == "Q":
			return False
		else:
			x -= 1

	x = row
	y = col
	while(y<n and x>=0):
		if board[x][y] == "Q":
			return False
		else:
			y += 1
			x -= 1
			
	# Check for Upper Left diagonal
	x = row
	y = col
	while(y>=0 and x>=0):
		if board[x][y] == "Q":
			return False
		else:
			x -= 1
			y -= 1
	return True

def solveNQueens(row, ans, board, n):
	
	# Base Case
	# Queen is depicted by "Q"
	# adding solution to final answer array
	if row == n:
		add_sol(board, ans, n)
		return
	
	# Solve 1 case and rest recursion will follow
	for col in range(n):
		
		# For each position check if it is safe and if it
		# is safe make a recursive call with
		# row+1, board[i][j]='Q' and then revert the change
		# in board that is make the board[i][j]='.' again to
		# generate more solutions
		if is_safe(row, col, board, n):
			
			# If placing Queen is safe
			board[row][col] = "Q"
			solveNQueens(row+1, ans, board, n)
			
			# Backtrack
			board[row][col] = "."


# Driver Code
if __name__ == "__main__":
	
	# Size 4x4 is taken and we can pass some other
	# dimension for chess board as well
	n = int(input("Enter Thy Matrix side length: "))
	
	# 2D array of string will make our board
	# which is initially all empty
	board = [["." for i in range(n)] for j in range(n)]
	
	# Store all the possible answers
	ans = []
	solveNQueens(0, ans, board, n)
	
	if ans == []:
		print("Solution does not exist")
	else:
		print(len(ans))
		print(f"Out Of {len(ans)} solutions one is following")
		print_board(ans[0], n)