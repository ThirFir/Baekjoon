#include <iostream>

int board[128][128] = { -1 };

int white = 0;
int blue = 0;
void cutPaper(int n, int init_i, int init_j) {
	if (n == 1) {
		if (board[init_i][init_j] == 0)
			++white;
		else if (board[init_i][init_j] == 1)
			++blue;
		return;
	}

	bool isAllSame{ true };
	int first = board[init_i][init_j];
	for (int i{ init_i }; i < n + init_i; i++) {
		for (int j{ init_j }; j < n + init_j; j++) {
			if (board[i][j] != first) {
				isAllSame = false;
				break;
			}
		}
		if (!isAllSame)
			break;
	}
	if (isAllSame) {
		if (board[init_i][init_j] == 0)
			++white;
		else if (board[init_i][init_j] == 1)
			++blue;
		return;
	}
	
	for (int i{ 0 }; i < 4; i++)
		switch (i) {
		case 0:
			cutPaper(n / 2, init_i, init_j);
			break;
		case 1:
			cutPaper(n / 2, init_i, init_j + n / 2);
			break;
		case 2:
			cutPaper(n / 2, init_i + n / 2, init_j);
			break;
		case 3:
			cutPaper(n / 2, init_i + n / 2, init_j + n / 2);
			break;
		}	
}
int main() {
	int N;
	scanf_s("%d", &N);
	
	for (int i{ 0 }; i < N; ++i) 
		for (int j{ 0 }; j < N; ++j) 
			scanf_s("%d", &board[i][j]);
		
	cutPaper(N, 0, 0);
	printf("%d\n%d\n", white, blue);
}