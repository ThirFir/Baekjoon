#include <stdio.h>

int main() {
	int num;
	int front = 1, back = 50;
	int middle;
	while (1) {
		scanf_s("%d", &num);
		if (num == 0)
			break;
		front = 1;
		back = 50;
		while (front <= back) {			
			middle = (front + back) / 2;
			printf("%d ", middle);

			if (num < middle)
				back = middle - 1;
			else if (num > middle)
				front = middle + 1;
			else
				break;
		}
	}
	return 0;
}