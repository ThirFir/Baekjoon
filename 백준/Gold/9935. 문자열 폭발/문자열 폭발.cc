#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

string s, bomb, result{ "" };
stack<int> bomb_stack;

int main() {
	cin >> s >> bomb;
	int i{ 0 };
	
	LOOP:
	for (; i < s.size(); ++i) {
		for (int a{ 0 }; a < bomb.size(); ++a) {
			if (bomb_stack.empty() && a > 0)
				break;
			if (!bomb_stack.empty() && bomb_stack.top() + 1 < a) 
				break;		
			if (s[i] == bomb[a]) {
				bomb_stack.push(a);

				stack<int> temp;
				if (a + 1 == bomb.size()) {
					for (int k{ 0 }; k < bomb.size(); ++k) {
						if (!temp.empty() && temp.top() != bomb_stack.top() + 1) {
							while (!temp.empty()) {
								bomb_stack.push(temp.top());
								temp.pop();
							}
							break;
						}
						temp.push(bomb_stack.top());
						bomb_stack.pop();
					}
				}
				++i; goto LOOP;
			}
		}
		string s2{ "" };
		int size = bomb_stack.size();
		for (int b{ 0 }; b < size; ++b) {
			s2 += bomb[bomb_stack.top()];
			bomb_stack.pop();
		}
		reverse(s2.begin(), s2.end());
		result += s2 + s[i];
	}

	string s2{ "" };
	int size = bomb_stack.size();
	for (int b{ 0 }; b < size; ++b) {
		s2 += bomb[bomb_stack.top()];
		bomb_stack.pop();
	}
	reverse(s2.begin(), s2.end());
	result += s2;
	if (result == "") result = "FRULA";
	cout << result;
}
