#include <iostream>
#include <algorithm>
#include <cstring>
#pragma warning(disable:4996)

int dp[100001][101], w[101]{ 0 }, v[101]{ 0 }, n;
int maxValue(int k, int start) {
	int& ret = dp[k][start];
	if (ret != 0)
		return ret;

	int i;
	for (i = start + 1 ; i <= n; ++i) {
		if (k - w[i] < 0) break;
		ret = std::max(ret, maxValue(k - w[i], i) + v[i]);	
	}
	return ret;
}
int main() {
	int k;
	scanf("%d%d", &n, &k);
	memset(dp, 0, sizeof(int) * 101 * n);

	for (int i{ 1 }; i <= n; ++i) 
		scanf("%d%d", &w[i], &v[i]);
	for (int i{ 1 }; i <= n; ++i)
		for (int j{ i + 1 }; j <= n; ++j) 
			if (w[i] > w[j]) {
				int temp = w[i]; w[i] = w[j]; w[j] = temp;
				temp = v[i]; v[i] = v[j]; v[j] = temp;
			}
		
	printf("%d", maxValue(k, 0));	
}      