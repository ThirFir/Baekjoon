#include <iostream>
#include <string>
#include <cmath>

void hanoi(int n, int from, int to, int temp) {
	if (n == 1) {
		printf("%d %d\n", from, to);
		return;
	}
	hanoi(n - 1, from, temp, to);
	printf("%d %d\n", from, to);
	hanoi(n - 1, temp, to, from);
}

int main() {
	int N;
	scanf_s("%d", &N);
	std::string count = std::to_string(pow(2, N));

	int x = count.find('.');
	count = count.substr(0, x);
	count[count.length() - 1] -= 1;
	
	std::cout << count << '\n';
	if(N <= 20)
		hanoi(N, 1, 3, 2);
}