#include <iostream>
#include <vector>
#pragma warning(disable:4996)

using namespace std;
int main() {
	int n, S[1001];
	scanf("%d", &n);
	for (int i{ 1 }; i <= n; ++i)
		scanf("%d", &S[i]);

	vector<int> up(n + 1), down(n + 1);	//up[i] : i에서 '끝나는' 최대증가수열(길이), down[i] : i에서 시작하는 최대감소수열 
	up[1] = 1;
	down[n] = 1;
	
	for (int i{ 2 }; i <= n; ++i) {
		++up[i];

		int max_length{ 0 };
		for (int j{ i - 1 }; j > 0; --j) {
			if (S[j] < S[i]) {
				max_length = max(max_length, up[j]);
			}
		}
		up[i] = max_length + 1;
	}
	for (int i{ n - 1 }; i > 0; --i) {
		++down[i];

		int max_length{ 0 }; 
		for (int j{ i + 1 }; j <= n; ++j) {
			if (S[j] < S[i]) {
				max_length = max(max_length, down[j]);
			}
		}
		down[i] = max_length + 1;
	}
	int ret{ 0 };
	for (int i{ 1 }; i <= n; ++i)
		ret = max(ret, (int)(up[i] + down[i] - 1));
	printf("%d", ret);
}