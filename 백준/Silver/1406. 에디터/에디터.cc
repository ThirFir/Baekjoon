#include <iostream>
#include <list>
using namespace std;

int main() {
	string s; cin >> s;
	list<char> str;
	for (int i{ 0 }; i < s.size(); ++i) 
		str.push_back(s[i]);
	
	int m; cin >> m;
	list<char>::iterator cursor{ str.end() };
	while (m--) {
		char op; cin >> op;
		if (op == 'L' && cursor != str.begin())
			--cursor;
		if (op == 'D' && cursor != str.end())
			++cursor;
		if (op == 'B' && cursor != str.begin()) 		
			cursor = str.erase(--cursor);	
		if (op == 'P') {
			char c; cin >> c;
			str.insert(cursor, c);
		}
	}
	for (cursor = str.begin(); cursor != str.end(); ++cursor)
		printf("%c", *cursor);
}
