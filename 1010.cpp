#include <iostream>
#include <vector>
#pragma warning(disable:4996)

int site[30][30]{ 0 };	//site[n][m] -> 사이트가 n, m개 씩 남았을 때의 경우의 수
int solve(int n, int m) {
	if (n == 0) 
		return 1;
	if (m < n)
		return 0;
	int& ret = site[n][m];

	if (ret != 0)
		return ret;
	for (int j{ 0 }; j < m; ++j) 
		ret += solve(n - 1, m - 1 - j);
	return ret;
}
int main() {
	int T;
	scanf("%d", &T);

	while (T--) {
		int N, M;
		scanf("%d%d", &N, &M);	// N <= M
		printf("%d\n", solve(N,M));
	}
}