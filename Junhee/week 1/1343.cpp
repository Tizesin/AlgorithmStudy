#include <iostream>
#include <vector>

using namespace std;

int main() {
	string board;
	string answer = "";
	cin >> board;
	int cnt = 0;
	bool flag = false;
	for (int i = 0; i < board.size(); i++) {
		if (board[i] == 'X') cnt++;
		if (board[i] == '.') {
			answer += ".";
			// X가 홀수개 나왔을 때
			if (cnt % 2 != 0) {
				flag = true;
				break;
			}
			else cnt = 0;
		}
		// X가 4번 나왔을 때
		if (cnt == 4) {
			answer += "AAAA";
			cnt = 0;
		}
		// X가 2번 나오고, 다음 글자가 X가 아닐 때
		if (cnt == 2 && board[i+1] != 'X') {
			answer += "BB";
			cnt = 0;
		}
	}
	
	if (flag) cout << -1;
	// 마지막이 홀수개의 X로 끝나는 경우 예외처리
	else if (cnt % 2 != 0) cout << -1;
	else cout << answer;
	return 0;
}
