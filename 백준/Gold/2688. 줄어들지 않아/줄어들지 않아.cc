#include <iostream>

using namespace std;
long long dp[65][10];
int main() {
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		for (int i{ 1 }; i <= n; ++i)
			for (int j{ 0 }; j < 10; ++j)
				dp[i][j] = 0;
		for (int i{ 0 }; i < 10; ++i)
			dp[1][i] = 1;

		for (int i{ 2 }; i <= n; ++i)
			for (int j{ 0 }; j < 10; ++j) 
				for (int k{ j }; k < 10; ++k) 
					dp[i][j] += dp[i - 1][k];
				
		long long sum{ 0 };
		for (int i{ 0 }; i < 10; ++i)
			sum += dp[n][i];
		cout << sum << endl;
	}
}