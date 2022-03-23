#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996)
int main() {
	int n, A[1000];
	scanf("%d", &n);
	for (int i{ 0 }; i < n; ++i)
		scanf("%d", &A[i]);

	vector<vector<int>> dp(n, vector<int>(0));
	dp[n - 1].push_back(A[n - 1]);
	for (int i{ n - 2 }; i >= 0; --i) {
		dp[i].push_back(A[i]);

		int max_length{ 0 }, index{ i };
		for (int j{ i+1 }; j < n; ++j) {
			if (dp[j][0] > dp[i][0]) {
				if (dp[j].size() > max_length) {
					max_length = dp[j].size();
					index = j;
				}
			}
		}
		if (index != i) {
			for (int j{ 0 }; j < dp[index].size(); ++j)
				dp[i].push_back(dp[index][j]);
		}
	}
	int ret{ 0 };
	for (int i{ 0 }; i < n; ++i)
		ret = max(ret, (int)dp[i].size());
	printf("%d", ret);
}