#include <iostream>
#include <vector>
#pragma warning(disable:4996)

int main() {
	int n, p[2][10]{ 0 };
	scanf("%d", &n);
	for (int i{ 1 }; i < 10; ++i)
		p[0][i] = 1;
	
	for (int i{ 1 }; i < n; ++i) {
		for (int j{ 1 }; j < 9; ++j) 
			p[1][j] = (p[0][j - 1] + p[0][j + 1]) % 1000000000;
		p[1][0] = p[0][1] % 1000000000;
		p[1][9] = p[0][8] % 1000000000;
		for (int j{ 0 }; j < 10; ++j)
			p[0][j] = p[1][j];
	}
	int sum{ 0 };
	for (int i{ 0 }; i < 10; ++i)
		sum = (sum + p[1][i]) % 1000000000;
	if (n == 1)
		printf("9");
	else printf("%d", sum);
}