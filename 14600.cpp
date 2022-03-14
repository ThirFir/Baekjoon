#include <iostream>
#include <vector>
#pragma warning(disable:4996)

int board[4][4]{ 0 };
int K, x, y, width;
int tile = 1;
bool isFilled() {
	for (int i{ 0 }; i < width; ++i) 
		for (int j{ 0 }; j < width; ++j) 
			if (board[i][j] == 0)
				return false;
	return true;
}
bool isEmpty(int i, int j){
	if (board[i][j] == 0)
		return true;
	return false;
}
bool inRange(int i, int j) {
	if (i < 0 || j < 0 || i >= width || j >= width)
		return false;
	return true;
}
bool isUpperEmpty(int i) {
	for (int j{ 0 }; j < width; ++j)
		if (board[i][j] == 0)
			return true;
	return false;
}
void solve(int i, int j) {
	if (isFilled()) {
		for (int a{ 0 }; a < width; ++a) {
			for (int b{ 0 }; b < width; ++b) {
				printf("%d ", board[a][b]);
			}
			printf("\n");
		}
		exit(0);
	}

	for (int a{ i }; a < width - 1; ++a) {
		for (int b{ 0 }; b < width; ++b) {
			if (isEmpty(a, b)) {
				if (isEmpty(a, b + 1) && isEmpty(a + 1, b + 1) && inRange(a, b + 1) && inRange(a + 1, b + 1)) {		// ¤¡
					board[a][b] = tile;		board[a][b + 1] = tile;		board[a + 1][b + 1] = tile;
					++tile;
					solve(a, b + 1);
					--tile;
					board[a][b] = 0;		board[a][b + 1] = 0;		board[a + 1][b + 1] = 0;
				}
				if (isEmpty(a + 1, b - 1) && isEmpty(a + 1, b) && inRange(a + 1, b - 1) && inRange(a + 1, b)) {		// ¡¹
					board[a][b] = tile;		board[a + 1][b - 1] = tile;		board[a + 1][b] = tile;
					++tile;
					solve(a, b + 1);
					--tile;
					board[a][b] = 0;		board[a + 1][b - 1] = 0;		board[a + 1][b] = 0;
				}
				if (isEmpty(a + 1, b) && isEmpty(a + 1, b + 1) && inRange(a + 1, b) && inRange(a + 1, b + 1)) {			// ¤¤
					board[a][b] = tile;		board[a + 1][b] = tile;		board[a + 1][b + 1] = tile;
					++tile;
					solve(a, b+1);
					--tile;
					board[a][b] = 0;		board[a + 1][b] = 0;		board[a + 1][b + 1] = 0;
				}
				if (isEmpty(a + 1, b) && isEmpty(a, b + 1) && inRange(a + 1, b) && inRange(a, b + 1)) {			// ¡¸
					board[a][b] = tile;		board[a + 1][b] = tile;		board[a][b + 1] = tile;
					++tile;
					solve(a, b + 1);
					--tile;
					board[a][b] = 0;		board[a + 1][b] = 0;		board[a][b + 1] = 0;
				}
			}
		}
		if (isUpperEmpty(a))
			break;
	}



}
int main() {
	scanf("%d%d%d", &K, &x, &y);
	width = 2 * K;
	board[width-y][x-1] = -1;
	solve(0, 0);
}