#include <string>
#include <iostream> 

using namespace std;


int main() {
	int n;
	int cnt = 0, number = 665;
	cin >> n;
	while (cnt != n) {
		string s = to_string(++number);
		for (int i = 0; i < s.size() - 2; i++) {
			if (s[i] == '6' && s[i + 1] == '6' && s[i + 2] == '6') {
				cnt++;
				break;
			}
		}
	}
	cout << number;
	return 0;
}
