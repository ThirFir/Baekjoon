#include <iostream>
#pragma warning(disable:4996)

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N;
		scanf("%d", &N);
		int fibo[40][2];
		fibo[0][0] = 1; fibo[0][1] = 0;
		fibo[1][0] = 0, fibo[1][1] = 1;
		for (int i{ 2 }; i <= N; ++i) {
			fibo[i][0] = fibo[i - 1][0] + fibo[i - 2][0];
			fibo[i][1] = fibo[i - 1][1] + fibo[i - 2][1];
		}
		printf("%d %d\n", fibo[N][0], fibo[N][1]);
	}
}