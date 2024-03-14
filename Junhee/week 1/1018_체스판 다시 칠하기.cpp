#include <iostream>
#include <algorithm>

using namespace std;
char map[50][50] = { ' ', };
int num_of_print(int col, int row) {
	char temp_map[8][8] = { ' ', };
	int count = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			temp_map[i][j] = map[col + i][row + j];
		}
	}
	int count_w = 0;
	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < 8; j++) {
				if (j % 2 == 0 && temp_map[i][j] != 'W')
					count_w++;
				else if (j % 2 == 1 && temp_map[i][j] != 'B')
					count_w++;
			}
		}
		else {
			for (int j = 0; j < 8; j++) {
				if (j % 2 == 1 && temp_map[i][j] != 'W')
					count_w++;
				else if (j % 2 == 0 && temp_map[i][j] != 'B')
					count_w++;
			}
		}
		
	}
	int count_b = 0;
	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < 8; j++) {
				if (j % 2 == 1 && temp_map[i][j] != 'W')
					count_b++;
				else if (j % 2 == 0 && temp_map[i][j] != 'B')
					count_b++;
			}
		}
		else {
			for (int j = 0; j < 8; j++) {
				if (j % 2 == 0 && temp_map[i][j] != 'W')
					count_b++;
				else if (j % 2 == 1 && temp_map[i][j] != 'B')
					count_b++;
			}
		}
	}
	return min(count_w, count_b);
}

int main() {
	int answer = 2501;
	int col = 0, row = 0;
	cin >> col >> row;
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i + 8 <= col; i++) {
		for (int j = 0; j + 8 <= row; j++) {
			int temp_answer = num_of_print(i, j);
			if (temp_answer < answer)
				answer = temp_answer;
		}
	}
	cout << answer;
	return 0;
}
