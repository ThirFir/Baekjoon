#include <iostream>
#include <vector>
#pragma warning(disable:4996)

int a[1000000];

int main() {
	int N;
	scanf("%d", &N);
	
	for (int i{ 2 }; i <= N; ++i) {
		a[i] = a[i - 1] + 1;
		if (i % 3 == 0)
			a[i] = std::min(a[i], a[i / 3] + 1);
		if (i % 2 == 0)
			a[i] = std::min(a[i], a[i / 2] + 1);
	}
	printf("%d\n", a[N]);
}