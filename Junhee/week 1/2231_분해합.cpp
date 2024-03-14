#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N, answer = 0;
	cin >> N;
	for (int i = 0; i <= N; i++) {
		int count = i;
		int num = i;
		while (num != 0) {
			count += num % 10;
			num /= 10;
		}
		if (count == N) {
			answer = i;
			break;
		}
	}
	cout << answer;
	return 0;
}
