#include <iostream>
#include <stack>
using namespace std;

int m[100001];
int main() {
	int n; cin >> n;
	for (int i{ 1 }; i <= n; ++i)
		cin >> m[i];
	stack<int> s;
	string str;

	int j{ 1 };
	for (int i{ 1 }; i <= n; ++i) {
		if (s.empty() || s.top() != m[j]) {
			s.push(i);
			str += "+\n";
		}
		else if (s.top() == m[j]) {
			s.pop();
			str += "-\n";
			if (++j > n)
				break;
			--i;
		}
	}
	while (!s.empty()) {
		if (s.top() != m[j++]) {
			cout << "NO";
			return 0;
		}
		str += "-\n";
		s.pop();
	}
	cout << str;
}
