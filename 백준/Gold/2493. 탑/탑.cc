#include <iostream>
#include <stack>
using namespace std;

int m[500001];
int main() {
	int n; cin >> n;
	stack<int> s, index;
	
	for (int i{ 1 }; i <= n; ++i) 
		cin >> m[i];
	s.push(m[1]);
	index.push(1);
	cout << 0 << ' ';
	for (int i{ 2 }; i <= n; ++i) {
		bool find{ false };
		while (!s.empty()) {
			if (s.top() > m[i]) {
				cout << index.top() << ' ';
				find = true;
				break;
			}
			s.pop();
			index.pop();
		}
		if (!find) cout << 0 << ' ';
		s.push(m[i]);
		index.push(i);
	}
	
}
