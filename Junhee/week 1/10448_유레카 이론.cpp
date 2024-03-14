#include <iostream>
#include <vector>

using namespace std;

int t_num[1000] = { 0, 1, };

int main() {
	int max_n;
	for (int i = 2; i < 1000; i++) {
		t_num[i] = t_num[i - 1] + i;
		if (t_num[i] > 1000) {
			max_n = i;
			break;
		}
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		bool flag = false;
		cin >> t;
		for (int i = 1; i < max_n; i++) {
			for (int j = 1; j < max_n; j++) {
				for (int k = 1; k < max_n; k++) {
					if (t_num[i] + t_num[j] + t_num[k] == t) {
						flag = true;
						break;
					}
				}
			}
		}
		if (flag) cout << 1 << endl;
		else cout << 0 << endl;
	}
	return 0;
}
