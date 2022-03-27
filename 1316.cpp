#include <iostream>
#include <cstring>
#include <string>
#pragma warning(disable:4996)

int main() {
	int n;
	std::cin >> n;
	std::string s[100];
	for (int i{ 0 }; i < n; ++i)
		std::cin >> s[i];
	bool used[26];
	
	int cnt{ 0 };
	for (int i{ 0 }; i < n; ++i) {
		memset(used, false, sizeof(bool) * 26);
		used[s[i][0] - 'a'] = true;
		bool cntOK{ true };
		for (int j{ 1 }; j < s[i].length(); ++j) {
			if (used[s[i][j] - 'a']) {
				if (s[i][j - 1] != s[i][j]) {
					cntOK = false;
					break;
				}
			}
			used[s[i][j] - 'a'] = true;
		}
		if (cntOK)
			++cnt;
	}
	printf("%d", cnt);  
}  