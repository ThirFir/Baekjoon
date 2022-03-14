#include <iostream>
#include <vector>
#include <cmath>
#pragma warning(disable:4996)

int r, c;
int last{ 0 };

int quadrant(int n) { // Z ¼ø¼­·Î 1,2,3,4
	if (r < n / 2 && c < n / 2)
		return 1;
	if (r < n / 2 && c >= n / 2)
		return 2;
	if (r >= n / 2 && c < n / 2)
		return 3;
	if (r >= n / 2 && c >= n / 2)
		return 4;
}
void solve(int n) {
	if (n == 1) {
		printf("%d\n", last);
		return;
	}
	switch (quadrant(n)) {
	case 1:
		break;
	case 2:
		last += (n / 2) * (n / 2);
		c -= n / 2;
		break;
	case 3:
		last += (n / 2) * (n / 2) * 2;
		r -= n / 2;
		break;
	case 4:
		last += (n / 2) * (n / 2) * 3;
		r -= n / 2;
		c -= n / 2;
		break;
	}
	solve(n / 2);
}
int main() {
	int N;
	scanf("%d%d%d", &N, &r, &c);

	solve((int)pow(2, N));
}