#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> list;
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		int temp;
		cin >> temp;
		list.push_back(temp);
		sum += temp;
	}
	sort(list.begin(), list.end());
	int answer1, answer2;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sum - list[i] - list[j] == 100) {
				answer1 = i, answer2 = j;
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		if (i == answer1 || i == answer2) continue;
		cout << list[i] << endl;
	}
	return 0;
}
