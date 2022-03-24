#include <iostream>
#include <vector>
#pragma warning(disable:4996)

int main() {
	int n;
	scanf("%d", &n);
	std::vector<int> k(n+1), dp(n+1);
	for (int i{ 1 }; i <= n; ++i)
		scanf("%d", &k[i]);
	
	dp[n] = k[n];
	int ret{ k[n] };
	for (int i{ n - 1 }; i > 0; --i) {
		if (dp[i + 1] >= 0)
			dp[i] = dp[i + 1] + k[i];
		else
			dp[i] = k[i];
		ret = std::max(dp[i], ret);
	}
	printf("%d", ret);
}