#include <iostream>
#pragma warning(disable:4996)

int main() {
	int stair[301], dp[301][2], N;
	scanf("%d", &N);
	for (int i{ 1 }; i <= N; ++i)
		scanf("%d", &stair[i]);

	dp[N][0] = stair[N];
	dp[N-1][0] = stair[N-1] + stair[N];
	for (int i{ N - 2 }; i >= 1; --i) {
		dp[i][0] = dp[i + 1][1] + stair[i];
		dp[i][1] = std::max(dp[i + 2][0], dp[i + 2][1]) + stair[i];
	}
	printf("%d\n", std::max(std::max(dp[1][0], dp[1][1]), std::max(dp[2][0], dp[2][1])));  
}