#include <iostream>

int dp[100001];
int main() {
	int n; std::cin >> n;
	dp[0] = 0;
	for (int i{ 1 }; i <= n; ++i)
		dp[i] = 100000;

	for (int i{ 1 }; i <= n; ++i)
		for (int j{ 1 }; j*j <= i; ++j) 
			dp[i] = std::min(dp[i], dp[i - j*j] + 1);
	std::cout << dp[n];
}
