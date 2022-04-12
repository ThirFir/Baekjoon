#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n; cin >> n;
	stack<int> s;
	for (int i{ 0 }; i < n; ++i) {
		int a; cin >> a;
		s.push(a);
	}
	int last{ s.top() }, cnt{ 1 };
	while (!s.empty()) {
		if (s.top() > last) {
			last = s.top();
			++cnt;
		}
		s.pop();
	}
	cout << cnt;
}