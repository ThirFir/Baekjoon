#include <iostream>

using namespace std;
char m[100001][3];
int dp[2][3];
int n;
int main() {
	cin >> n;
	
	for (int i{ 0 }; i < n; ++i)
		for (int j{ 0 }; j < 3; ++j) 
			cin >> m[i][j];
	if (n == 1)
		cout << max(max(m[0][0] - '0', m[0][1] - '0'), m[0][2] - '0') << " " << min(min(m[0][0] - '0', m[0][1] - '0'), m[0][2] - '0');
	else {
		for (int i{ 0 }; i < 3; ++i)
			dp[1][i] = m[n - 1][i] - '0';

		for (int i{ n - 2 }; i >= 0; --i) {
			dp[0][0] = max(dp[1][0], dp[1][1]) + m[i][0] - '0';
			dp[1][0] = dp[0][0];
			dp[0][2] = max(dp[1][1], dp[1][2]) + m[i][2] - '0';
			dp[1][2] = dp[0][2];
			dp[0][1] = max(dp[1][0] - m[i][0] + '0', dp[1][2] - m[i][2] + '0') + m[i][1] - '0';
			dp[1][1] = dp[0][1];
		}
		cout << max(max(dp[0][0], dp[0][1]), dp[0][2]) << " ";

		for (int i{ 0 }; i < 3; ++i)
			dp[1][i] = m[n - 1][i] - '0';

		for (int i{ n - 2 }; i >= 0; --i) {
			dp[0][0] = min(dp[1][0], dp[1][1]) + m[i][0] - '0';
			dp[1][0] = dp[0][0];
			dp[0][2] = min(dp[1][1], dp[1][2]) + m[i][2] - '0';
			dp[1][2] = dp[0][2];
			dp[0][1] = min(dp[1][0] - m[i][0] + '0', dp[1][2] - m[i][2] + '0') + m[i][1] - '0';
			dp[1][1] = dp[0][1];
		}
		cout << min(min(dp[0][0], dp[0][1]), dp[0][2]);
	}
}
