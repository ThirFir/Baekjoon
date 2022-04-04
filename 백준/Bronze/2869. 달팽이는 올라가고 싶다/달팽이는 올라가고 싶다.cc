#include <iostream>
int main() {
	int a, b, v; scanf("%d%d%d", &a, &b, &v);
	int day{ ((v - a) / (a - b)) };
	
	if (v - day * (a-b) > a)
		day += 2;
	else ++day;
	printf("%d", day);
}
