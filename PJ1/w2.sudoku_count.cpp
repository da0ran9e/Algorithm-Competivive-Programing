#include <bít/stdc++.h>
using namespace std;

const int N = 9;

// check if num is valid for the given row
bool is_row_valid(int board[N][N], int row, int num) {
	for (int col = 0; col < N; col++) {
		if (board[row][col] == num) {
			return false;
		}
	}
	return true;
}

// check if num is valid for the given column
bool is_col_valid(int board[N][N], int col, int num) {
	for (int row = 0; row < N; row++) {
		if (board[row][col] == num) {
			return false;
		}
	}
	return true;
}

// check if num is valid for the 3x3 grid that (row, col) belongs to
bool is_grid_valid(int board[N][N], int row, int col, int num) {
	int start_row = row - row % 3;
	int start_col = col - col % 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[start_row + i][start_col + j] == num) {
				return false;
			}
		}
	}
	return true;
}

// check if it's safe to place num at board[row][col]
bool check(int board[N][N], int row, int col, int num) {
	return is_row_valid(board, row, num) && 
		   is_col_valid(board, col, num) && 
		   is_grid_valid(board, row, col, num);
}

int solve(int board[N][N], int row, int col) {
	// base case: solution found 
	if (row == N) {
		return 1;
	}
	
	// if the current column is the last column, move to the next row
	if (col == N) {
		return solve(board, row + 1, 0);
	}
	
	// if the current cell is not empty, move to the next cell
	if (board[row][col] != 0) {
		return solve(board, row, col + 1);
	}
	
	// try out all possible numbers for the current cell
	int count = 0;
	for (int num = 1; num <= N; num++) {
		if (check(board, row, col, num)) {
			board[row][col] = num;
			count += solve(board, row, col + 1);
			board[row][col] = 0;
		}
	}
	return count;
}

int main() {
	int input_board[N][N];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input_board[i][j];
		}
	}

		
	cout << solve(input_board, 0, 0);

	return 0;
}