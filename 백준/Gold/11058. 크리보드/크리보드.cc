#include <iostream>

using namespace std;
long long dp[101];
int main() {
	int n; cin >> n;
	dp[1] = 1;
	for (int i{ 2 }; i <= n; ++i) {
		dp[i] = dp[i - 1] + 1;
		for (int j{ 3 }; j < i; ++j)
			dp[i] = max(dp[i], dp[i - j] * (j - 1));
	}
	cout << dp[n];
}