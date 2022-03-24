#include <iostream>
#include <vector>
#pragma warning(disable:4996)

using namespace std;
int main() {
	int n,link[501];
	scanf("%d", &n);
	for (int i{ 0 }; i < 501; ++i)
		link[i] = 0;
	int a, b, max_a{ 0 };
	for (int i{ 1 }; i <= n; ++i) {
		scanf("%d%d", &a, &b);
		link[a] = b;
		max_a = max(max_a, a);
	}
	vector<int> dp(max_a+1);	// dp[i] : i부터의 최대증가수열
	dp[max_a] = 1;
	for (int i{ max_a - 1 }; i > 0; --i) {
		if (link[i] == 0)
			continue;
		int max_length{ 0 };
		for (int j{ i + 1 }; j <= max_a; ++j) {
			if (link[j] > link[i]) {
				max_length = max(max_length, dp[j]);
			}
		}
		dp[i] = max_length + 1;
	}
	int ret{ 0 };
	for (int i{ 1 }; i <= max_a; ++i)
		ret = max(ret, (int)dp[i]);
	printf("%d", n-ret);
}