#include <iostream>

using namespace std;
int n, A[201], dp[201];

int main() {
	cin >> n;
	for (int i{ 1 }; i <= n; ++i) {
		cin >> A[i];
		dp[i] = 1;
	}

	dp[n] = 1;
	for (int i{ n - 1 }; i >= 1; --i)
		for (int j{ i + 1 }; j <= n; ++j)
			if (A[i] < A[j])
				dp[i] = max(dp[i], dp[j] + 1);
	int Max{ 0 };
	for (int i{ 1 }; i <= n; ++i)
		Max = max(Max, dp[i]);
	cout << n - Max << endl;
}