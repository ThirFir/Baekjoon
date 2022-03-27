#include <iostream>
#include <cstring>
#include <cmath>
#pragma warning(disable:4996)

bool d[1001];
bool f(int x) {
	if (x < 100)
		return true;
	int a = x / 100;
	int b = (x - a * 100) / 10;
	int c = x - a * 100 - b * 10;
	if (a - b == b - c)
		return true;
	return false;
}
int main() {
	int n;
	scanf("%d", &n);

	int cnt{ 0 };
	for (int i{ 1 }; i <= n; ++i) {
		d[i] = f(i);
		if (d[i])
			++cnt;
	}
	printf("%d", cnt);
}  