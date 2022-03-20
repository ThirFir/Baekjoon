#include <iostream>
#include <vector>
#pragma warning(disable:4996)

int main() {
	int N;
	scanf("%d", &N);

	int count{ 0 };
	
	if (N % 3 == 1) {
		N -= 10;
		count += 2;
	}
	else if (N % 3 == 2) {
		N -= 5;
		++count;
	}
	while (N >= 15) {
		N -= 15;
		count += 3;
	}
	while (N > 0) {
		N -= 3;
		++count;
	}
	if (N != 0) {
		printf("-1\n");
		return 0;
	}
	printf("%d\n", count);
	


}