#include <iostream>
#include <string>

using namespace std;
int dp[1001];

int solve(int n) {
	if (n <= 1)
		return 1;
	int& ret = dp[n];
	if (ret != -1) return ret;

	ret = (solve(n - 1) + 2*solve(n - 2)) % 10007;
	return ret;
}
int main() {
	memset(dp, -1, sizeof(int) * 1001);
	int n; cin >> n;
	cout << solve(n);
}
