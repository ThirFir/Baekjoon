#include <iostream>
#include <cmath>
#include <vector>

std::vector<std::vector<int>> board;
int count[3]{ 0 };

bool isAreaSame(int x, int y, int n) {
	for (int i{ y }; i < y + n; i++) {
		for (int j{ x }; j < x + n; j++) {
			if (board[i][j] != board[y][x])
				return false;
		}
	}
	return true;
}
void solve(int x, int y, int n) {
	if (isAreaSame(x, y, n)) {
		if (board[y][x] == -1)
			++count[0];
		else if (board[y][x] == 0)
			++count[1];
		else if (board[y][x] == 1)
			++count[2];
		return;
	}

	solve(x, y,				n / 3); solve(x + n / 3, y,				n / 3); solve(x + 2 * n / 3, y,				n / 3);
	solve(x, y + n / 3,		n / 3); solve(x + n / 3, y + n / 3,		n / 3); solve(x + 2 * n / 3, y + n / 3,		n / 3);
	solve(x, y + 2 * n / 3, n / 3); solve(x + n / 3, y + 2 * n / 3, n / 3); solve(x + 2 * n / 3, y + 2 * n / 3, n / 3);

}
int main() {
	int N;
	scanf_s("%d", &N);	// NÀº 3ÀÇ Á¦°ö¼ö, 1 <= N <= 3^7.

	int k;
	for (int i{ 0 }; i < N; i++){
		std::vector<int> line;
		for (int j{ 0 }; j < N; j++) {
			scanf_s("%d", &k);
			line.push_back(k);
		}
		board.push_back(line);
	}	
	solve(0, 0, N);

	for (int i{ 0 }; i < 3; ++i)
		printf("%d\n", count[i]);
}