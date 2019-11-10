#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
0 0 0 0 0
0 0 1 0 3
0 2 5 0 1
4 2 4 4 2
3 5 1 3 1

1 5 3 5 1 2 1 4 0
*/

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0, tmp, j;
	vector<int> outs; //나온 인형들 저장 변수
	for (int i = 0; i < moves.size(); i++) { //움직임 횟수만큼 시작
		int outdoll = 0;
		tmp = moves[i] - 1; //어딜 꺼냇는지 -1을 해줘 배열에 맞게 바꿔준다.
		for (int j = 0; j < board.size(); j++) { //위에서 부터 확인
			if (board[j][tmp] != 0) { //찾으면
				outdoll = board[j][tmp]; //저장후 탈출
				board[j][tmp] = 0;
				break;
			}
		}
		if (outdoll != 0) {
			if (outs.size()< 1 || outdoll != outs[outs.size() - 1]) { //인형이 같지 않은경우
				outs.push_back(outdoll);
				continue;
			}
			//같은 인형인 경우.
			outs.resize(outs.size() - 1);
			answer += 2;
		}
	}
	return answer;
}

int main() {
	int arr[8] = { 1, 5,3,5,1,2,1,4 };
	vector<vector<int>> board;
	vector<int> moves;
	int tmp;

	for (int i = 0; i < 5; i++) {
		vector<int> input;
		for (int j = 0; j < 5; j++) {
			cin >> tmp;
			input.push_back(tmp);
		}
		board.push_back(input);
	}
	for (int i = 0; i < 8; i++)
		moves.push_back(arr[i]);

	cout << solution(board, moves);
}