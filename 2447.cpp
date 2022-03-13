#include <iostream>
#include <vector>

std::vector<std::string> board;

void solve(int line, int n) {
	if (n == 3) {
		board[line] += "***";
		board[line + 1] += "* *";
		board[line + 2] += "***";
		return;
	}

	int h;
	for (int i{ 0 }; i < 9; i++) {
		if (i < 3)
			h = 0;
		else if (i < 6)
			h = n / 3;
		else if (i < 9)
			h = n * 2 / 3;

		if (i != 4)
			solve(line + h, n / 3);
		else {
			for (int j{ 0 }; j < n / 3; j++) {
				for (int k{ 0 }; k < n / 3; k++)
					board[line + j + h] += " ";
			}
		}

	}
}
int main() {
	int N;
	scanf_s("%d", &N); // N = 3^k, 1 <= k < 8
	board.resize(N);

	solve(0, N);
	for (int i{ 0 }; i < board.size(); i++)
		std::cout << board[i] << std::endl;
	
}