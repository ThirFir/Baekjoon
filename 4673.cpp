#include <iostream>
#include <cstring>
#include <vector>
#pragma warning(disable:4996)

int d[10000];
void f(int n) {
	int cons{ n };
	while (n) {
		cons += n % 10;
		n /= 10;
	}
	if (cons <= 10000)
		++d[cons];
}
int main() {
	memset(d, 0, sizeof(int) * 10000);
	for (int i{ 1 }; i < 10000; ++i) {
		f(i);
		if (d[i] == 0)
			printf("%d\n", i);
	}
}  