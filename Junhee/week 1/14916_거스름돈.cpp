#include <iostream>

using namespace std;

int main() {
	int charge;
	cin >> charge;
	int answer = 0;
	while (charge > 0) {
		if (charge % 5 == 0) {
			answer += charge / 5;
			break;
		}
		charge -= 2;
		answer += 1;
	}
	if (charge == -1) cout << -1;
	else cout << answer;
	return 0;
}
