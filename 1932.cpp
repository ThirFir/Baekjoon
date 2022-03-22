#include <iostream>
#include <vector>
#pragma warning(disable:4996)

using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<vector<int>> k(n+1, vector<int>(n+1));
	for (int i{ 1 }; i <= n; ++i) 
		for (int j{ 1 }; j <= i; ++j) 
			scanf("%d", &k[i][j]);
			
	vector<vector<int>> dp(n+1, vector<int>(n+1));
	for (int j{ 1 }; j <= n; ++j) 
		dp[n][j] = k[n][j];
	
	for (int i{ n - 1 }; i > 0; --i) 
		for (int j{ i }; j > 0; --j) 
			dp[i][j] = std::max(dp[i + 1][j], dp[i + 1][j + 1]) + k[i][j];		
	printf("%d\n", dp[1][1]);
}