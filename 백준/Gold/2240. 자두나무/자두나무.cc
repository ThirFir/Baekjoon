#include <iostream>
using namespace std;
int t[1001], w[31], T, dp[1001][31][3];
int solve(int tStart, int w, int locate) {
	if (tStart == T) return 0;
	if (T - tStart <= w) return T - tStart;	

	if (w == 0) {
		int cnt{ 0 };
		for (int i{ tStart+1 }; i <= T; ++i)
			if (locate == t[i])
				++cnt;
		return cnt;
	}
	int& ret = dp[tStart + 1][w][locate];
	if (ret != -1) return ret;

	int cnt{ t[tStart+1] == locate };
	return ret = max(solve(tStart + 1, w, locate), solve(tStart + 1, w - 1, locate == 1 ? 2 : 1)) + cnt;
}
int main() {
	int W; cin >> T >> W;
	for (int i{ 0 }; i <= T; ++i)
		for (int j{ 1 }; j <= W; ++j)
			for (int k{ 1 }; k <= 2; ++k)
				dp[i][j][k] = -1;
	for (int i{ 1 }; i <= T; ++i)
		cin >> t[i];
	cout << solve(-1, W, 1);
}
