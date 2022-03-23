#include <iostream>
#pragma warning(disable:4996)

int main() {
	int grape[10001], dp[10001][2], N;
	scanf("%d", &N);
	for (int i{ 1 }; i <= N; ++i)
		scanf("%d", &grape[i]);

	dp[N][0] = grape[N];
	dp[N - 1][0] = grape[N - 1] + grape[N];
	dp[N - 1][1] = grape[N - 1];
	for (int i{ N - 2 }; i >= 1; --i) {
		dp[i][0] = dp[i + 1][1] + grape[i];
		int MAX{ 0 };
		for (int j{ i + 2 }; j <= N; ++j) {
			MAX = std::max(std::max(dp[j][0], dp[j][1]), MAX);
		}
		dp[i][1] = MAX + grape[i];	
	}
	printf("%d\n", std::max(std::max(dp[1][0], dp[1][1]), std::max(dp[2][0], dp[2][1])));
}