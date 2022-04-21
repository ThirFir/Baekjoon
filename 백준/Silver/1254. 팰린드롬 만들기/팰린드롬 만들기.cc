#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string s, s2, s3; cin >> s;

	for (int i{ 0 }; s[i]; ++i) {
		s2 = "";
		for (int j{ 0 }; j < i; ++j)
			s2 += s[j];
		reverse(s2.begin(), s2.end());
		s3 = s + s2;
		reverse(s3.begin(), s3.end());
		if (s3 == s + s2) 
			break;
	}
	cout << s3.size();
}
