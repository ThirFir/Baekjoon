#include <iostream>
#include <vector>
using namespace std;
int n, w[10][10], start;
int solve(vector<bool> visited, int here, int path_len) {
	if (path_len == n) return w[here][start];

	visited[here] = true;

	int len{ 2000000000 };
	for (int next{ 0 }; next < n; ++next) {
		if (!visited[next] && w[here][next] != 0) {
			if (path_len + 1 == n && w[next][start] == 0)
				continue;
			len = min(len, solve(visited, next, path_len + 1) + w[here][next]);
			visited[next] = false;
		}
	}
	return len;
}
int main() {
	cin >> n;
	for (int i{ 0 }; i < n; ++i)
		for (int j{ 0 }; j < n; ++j)
			cin >> w[i][j];

	vector<bool> visited(n, false);

	int ret{ 2000000000 };
	for (int here{ 0 }; here < n; ++here) {
		start = here;
		ret = min(ret, solve(visited, here, 1));
		visited[here] = false;
	}
	cout << ret;
}