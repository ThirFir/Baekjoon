#include <iostream>
#include <stack>
using namespace std;
int main() {
	int T; cin >> T;
W:	while (T--) {
		string s; cin >> s;
		stack<char> stack;
		for (int i{ 0 }; s[i]; ++i) {
			if (s[i] == '(')
				stack.push(s[i]);
			else {
				if (stack.empty()) {
					cout << "NO\n";
					goto W;
				}
				else 
					stack.pop();			
			}
		}
		if (stack.empty()) cout << "YES\n";
		else cout << "NO\n";
	}
}