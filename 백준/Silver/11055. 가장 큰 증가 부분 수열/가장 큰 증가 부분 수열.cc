#include <iostream>

int A[1001], dp[1001];
int main() {
	int n; std::cin >> n;
	for (int i{ 1 }; i <= n; ++i) {
		std::cin >> A[i];
		dp[i] = A[i];
	}
	
	dp[n] = A[n];
	for (int i{ n - 1 }; i >= 1; --i)
		for (int j{ i + 1 }; j <= n; ++j) 
			if(A[j] > A[i])
				dp[i] = std::max(dp[i], dp[j] + A[i]);

	int max{ 0 };
	for (int i{ 1 }; i <= n; ++i)
		max = std::max(max, dp[i]);
	std::cout << max;
}
