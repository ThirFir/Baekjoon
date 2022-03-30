#include <iostream>
#include <string>

using namespace std;
int p[10001];
int dp[10001];
int maxValue(int n) {
	if (n == 0)
		return 0;
	int& ret = dp[n];
	if (ret != -1) return dp[n];

	for (int i{ 1 }; i < n + 1; ++i)
		ret = max(ret, maxValue(n - i) + p[i]);
	return ret;
}
int main() {
	memset(dp, -1, sizeof(int) * 10001);
	int n; cin >> n;
	for (int i{ 1 }; i < n + 1; ++i) cin >> p[i];
	cout << maxValue(n);
}
