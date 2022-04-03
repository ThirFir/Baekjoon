#include <iostream>
using namespace std;
int file[10001], dp[501][501]{ 0 }, files_sum[501][501]{ 0 }, k;
int solve(int l, int r) {
	int& ret = dp[l][r];
	if (r - 1 == l)
		return ret = files_sum[l][r];
	if (r == l) return 0;
	
	if (ret != 100000000) return ret;
	
	for (int i{ l }; i < r; ++i)
		ret = min(ret, solve(l, i) + solve(i + 1, r));
	return ret = ret + files_sum[l][r];
}
int main() {
	int T; cin >> T;
	while (T--) {
		cin >> k;
		for (int i{ 1 }; i <= k; ++i) {
			cin >> file[i];
			for (int j{ 1 }; j <= k; ++j)
				dp[i][j] = 100000000;
		}
		
		for (int i{ 1 }; i <= k; ++i) 
			for (int j{ i }; j <= k; ++j) 
				files_sum[i][j] = files_sum[i][j - 1] + file[j];
				
		cout << solve(1, k) << endl;
	}
}