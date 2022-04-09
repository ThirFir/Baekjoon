#include <iostream>
using namespace std;
int dp[201][201];
int solve(int n, int k) {
	if (k == 1)
		return 1;
	int& ret = dp[n][k];
	if (ret != 0) return ret;

	for (int i{ 0 }; i <= n; ++i) 
		ret = (ret + solve(n - i, k - 1)) % 1000000000;
	return ret % 1000000000;
}
int main() {
	int n, k; cin >> n >> k;
	for (int i{ 0 }; i <= n; ++i)
		for (int j{ 0 }; j <= k; ++j)
			dp[i][j] = 0;	
	cout << solve(n, k);
}
