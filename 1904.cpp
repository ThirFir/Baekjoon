#include <iostream>
#include <vector>

#pragma warning(disable:4996)
int main() {
	int n, p[3];
	scanf("%d", &n);
	p[0] = 1; p[1] = 2;
	for (int i{ 2 }; i < n; ++i) {
		p[2] = (p[1] + p[0]) % 15746;
		p[0] = p[1] % 15746; p[1] = p[2] % 15746;
	}
	if (n == 1) printf("1");
	else if (n == 2) printf("2");
	else printf("%d", p[2]);
}