#include <iostream>

char board[64][64]{ '2' };
std::string result{ "" };

bool isAreaSame(int x, int y, int n) {
	for (int i{ x }; i < x + n; i++) {
		for (int j{ y }; j < y + n; j++) {
			if (board[i][j] != board[x][y])
				return false;
		}
	}
	return true;
}
std::string quadTree(int x, int y, int n) {
	if (isAreaSame(y, x, n)) {
		if (board[y][x] == '0')
			result += "0";
		else if (board[y][x] == '1')
			result += "1";
		return "";
	}

	result += "(";
	result += quadTree(x,		  y,		 n / 2);
	result += quadTree(x + n / 2, y,		 n / 2);
	result += quadTree(x,		  y + n / 2, n / 2);
	result += quadTree(x + n / 2, y + n / 2, n / 2);
	result += ")";

	return "";
}

int main() {
	int N;
	scanf_s("%d", &N);	// NÀº 2ÀÇ Á¦°ö¼ö, 1 <= N <= 64.

	for (int i{ 0 }; i < N; i++)
		for (int j{ 0 }; j < N; j++)
			std::cin >> board[i][j];
	
	quadTree(0, 0, N);
	
	std::cout << result << std::endl;
}