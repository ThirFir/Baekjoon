#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string s; getline(cin, s);
	
	for (int i{ 0 }; i < s.size(); ++i) {
		if (s[i] == '<') 
			while (s[++i] != '>');		
		else if (s[i] == ' ') continue;
		else {
			int j{ i };
			while (j < s.size() && (s[j] != '<' && s[j] != ' ')) ++j;
			reverse(s.begin() + i, s.begin() + j);
			i = j - 1;
		}
	}
	cout << s;
}
