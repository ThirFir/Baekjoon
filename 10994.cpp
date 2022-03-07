#include <iostream>
#include <algorithm>

char board[397][397];
int cur_i = 0;
int cur_j = 0;
void fillBoard(int n, int cur_i, int cur_j) {
	for (int i{ cur_i }; i < 4 * n - 3 + cur_i; ++i) {
		for (int j{ cur_j }; j < 4 * n - 3 + cur_j; j++) {
			if (i == cur_i || i == 4 * n - 4 + cur_i)
				board[i][j] = '*';
			else if (j == cur_j || j == 4 * n - 4 + cur_j)
				board[i][j] = '*';
			else
				board[i][j] = ' ';
		}	
	}
	if (n == 1) {
		return;
	}
	fillBoard(n - 1, cur_i += 2, cur_j +=2);
}

int main() {
	int n;
	scanf_s("%d", &n);

	fillBoard(n, cur_i, cur_j);
	for (int i{ 0 }; i < 4 * n - 3; ++i) {
		for (int j{ 0 }; j < 4 * n - 3; ++j) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}

	return 0;
}