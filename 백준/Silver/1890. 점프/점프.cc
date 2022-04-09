#include <iostream>

using namespace std;
int m[101][101], n;
long long dp[101][101];

long long solve(int r, int c) {
	int k = m[r][c];
	if ((r != n || c != n) && k == 0) return 0;
	if (k == 0) return 1;

	long long& ret = dp[r][c];
	if (ret != 0) return ret;

	if (r + k <= n)
		ret += solve(r + k, c);
	if (c + k <= n)
		ret += solve(r, c + k);
	return ret;
}
int main() {
	cin >> n;
	for (int i{ 1 }; i <= n; ++i)
		for (int j{ 1 }; j <= n; ++j) {
			std::cin >> m[i][j];
			dp[i][j] = 0;
		}
	cout << solve(1, 1);
}