#include <iostream>
#pragma warning(disable:4996)

int list[1001][3];	// list[n][m] : n번째 줄 m색을 선택했을 때 최솟값
int rgb[1001][3];
int solve(int n, int c) {
	int& ret = list[n][c];
	if (n == 0) 
		return ret = rgb[n][c];
	if (ret != INT_MAX)
		return ret;

	int a[2], k = 0;
	for (int i{ 0 }; i < 3; ++i) {
		if (i != c) 
			a[k++] = i;
	}
	return ret = std::min(solve(n - 1, a[0]), solve(n - 1, a[1])) + rgb[n][c];
}
int main() {
	int N;
	scanf("%d", &N);
	for (int i{ 1 }; i <= N; ++i)
		scanf("%d%d%d", &rgb[i][0], &rgb[i][1], &rgb[i][2]);

	for (int i{ 1 }; i <= N; ++i)
		for (int j{ 0 }; j < 3; ++j)
			list[i][j] = INT_MAX;

	for (int i{ 0 }; i < 3; ++i)
		list[N][i] = solve(N, i);

	printf("%d\n", std::min(list[N][0], std::min(list[N][1],list[N][2])));
}				