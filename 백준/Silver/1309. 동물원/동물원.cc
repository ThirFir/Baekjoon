#include <iostream>

using namespace std;
int n, dp[100001][3];

int main() {
	cin >> n;
	
	dp[n][0] = dp[n][1] = dp[n][2] = 1;
	for (int i{ n - 1 }; i >= 1; --i) {
		dp[i][0] = (dp[i + 1][1] + dp[i + 1][2]) % 9901;
		dp[i][1] = (dp[i + 1][0] + dp[i + 1][2]) % 9901;
		dp[i][2] = (dp[i + 1][1] + dp[i + 1][0] + dp[i + 1][2]) % 9901;
	}
	cout << (dp[1][0] + dp[1][1] + dp[1][2]) % 9901;
}