#include <iostream>
#include <cstring>

using namespace std;
int dp[11];
int main() {  
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		dp[1] = 1; dp[2] = 2; dp[3] = 4;
		for (int i{ 4 }; i < 11; ++i)
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		cout << dp[n] << endl;
	}
}
