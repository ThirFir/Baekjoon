#include <iostream>

using namespace std;
char m[100001][3];
int dp[100001][3];
int n;

int main() {
	cin >> n;
	
	for (int i{ 0 }; i < n; ++i)
		for (int j{ 0 }; j < 3; ++j) 
			cin >> m[i][j];
	for (int i{ 0 }; i < 3; ++i)
		dp[n - 1][i] = m[n - 1][i] - '0';
	for (int i{ n - 2 }; i >= 0; --i) {
		dp[i][0] = max(dp[i + 1][0], dp[i + 1][1]) + m[i][0] - '0';
		dp[i][2] = max(dp[i + 1][1], dp[i + 1][2]) + m[i][2] - '0';
		dp[i][1] = max(dp[i][0] - m[i][0] + '0', dp[i][2] - m[i][2] + '0') + m[i][1] - '0';
	}
	cout << max(max(dp[0][0], dp[0][1]), dp[0][2]) << " ";

	for (int i{ n - 2 }; i >= 0; --i) {
		dp[i][0] = min(dp[i + 1][0], dp[i + 1][1]) + m[i][0] - '0';
		dp[i][2] = min(dp[i + 1][1], dp[i + 1][2]) + m[i][2] - '0';
		dp[i][1] = min(dp[i][0] - m[i][0] + '0', dp[i][2] - m[i][2] + '0') + m[i][1] - '0';
	}
	cout << min(min(dp[0][0], dp[0][1]), dp[0][2]);
}
