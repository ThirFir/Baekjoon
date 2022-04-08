#include <iostream>

int M[1001][1001], dp[1001][1001];
int main() {
	int n, m; std::cin >> n >> m;

	for (int i{ 1 }; i <= n; ++i)
		for (int j{ 1 }; j <= m; ++j)
			std::cin >> M[i][j];

	dp[n][m] = M[n][m];
	for (int i{ n }; i >= 1; --i) 
		for (int j{ m }; j >= 1; --j) {
			if (i + 1 <= n && j + 1 > m)
				dp[i][j] = dp[i + 1][j] + M[i][j];
			else if (i + 1 > n && j + 1 <= m)
				dp[i][j] = dp[i][j + 1] + M[i][j];
			else
				dp[i][j] = std::max(std::max(dp[i + 1][j], dp[i][j + 1]), dp[i + 1][j + 1]) + M[i][j];
		}	
	std::cout << dp[1][1];
}
