#include <iostream>
#include <vector>

#pragma warning(disable:4996)
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		long long p[101];
		scanf("%d", &n);
		p[0] = 0; p[1] = 1; p[2] = 1;
		for (int i{ 3 }; i <= n; ++i) 
			p[i] = p[i - 3] + p[i - 2];
		printf("%lld\n", p[n]);
	}
}