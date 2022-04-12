#include <iostream>
#include <list>
using namespace std;

int main() {
	int n; cin >> n;
	list<int> line;
	
	for (int i{ 0 }; i < n; ++i) {
		int a; cin >> a;
		list<int>::iterator iter = line.end();
		for (int j{ 0 }; j < a; ++j) 
			--iter;	
		line.insert(iter, i + 1);
	}
	for (list<int>::iterator iter{ line.begin() }; iter != line.end(); ++iter)
		cout << *iter << " ";
}