#include <iostream>
#include <stack>
using namespace std;
int main() {
	int n; cin >> n;
	stack<int> s;
	for (int i{ 0 }; i < n; ++i) {
		string str;
		cin >> str;
		if (str == "push") {
			int k; cin >> k;
			s.push(k);
		}
		else if (str == "top")
			cout << (s.empty() ? -1 : s.top()) << endl;
		else if (str == "size")
			cout << s.size() << endl;
		else if (str == "empty")
			cout << (s.empty() ? 1 : 0) << endl;
		else if (str == "pop") {
			if (!s.empty()) {
				cout << s.top() << endl;
				s.pop();
			}
			else
				cout << -1 << endl;
		}
	}
}