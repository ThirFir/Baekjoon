#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)

int dp[31]; // 2 X i �簢���� ä��� �� ����� ��(�ߺ� ���X)

int main() {
	int n;
	scanf("%d", &n);
	dp[0] = 1;
	dp[1] = 1;
	for (int i{ 2 }; i <= n; ++i)
		dp[i] = dp[i - 1] + dp[i - 2] * 2;

	int ret{ dp[n] };
	if (n % 2 == 1) 
		ret += dp[n / 2];	
	else
		ret += dp[n / 2 - 1] * 2 + dp[n / 2];
	printf("%d", ret / 2);
}  