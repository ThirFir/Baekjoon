#include <iostream>
#include <cstring>
#include <string>
#pragma warning(disable:4996)

int main() {
	std::string s;
	std::cin >> s;
	
	int cnt{ 0 };
	for (int i{ 0 }; s[i]; ++i) {
		++cnt;
		if (i < s.length() - 2) {
			if (s[i] == 'd' && s[i + 1] == 'z' && s[i + 2] == '=') {
				i += 2;
				continue;
			}
		}
		if (i < s.length() - 1) {
			if ((s[i] == 'c' && s[i + 1] == '=') || (s[i] == 'c' && s[i + 1] == '-') || (s[i] == 'd' && s[i + 1] == '-')
				|| (s[i] == 'l' && s[i + 1] == 'j') || (s[i] == 'n' && s[i + 1] == 'j') || (s[i] == 's' && s[i + 1] == '=')
				|| (s[i] == 'z' && s[i + 1] == '=')) {
				++i;
				continue;
			}
		}
	}
	printf("%d", cnt);  
}  