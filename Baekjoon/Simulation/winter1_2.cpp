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
	vector<int> outs; //���� ������ ���� ����
	for (int i = 0; i < moves.size(); i++) { //������ Ƚ����ŭ ����
		int outdoll = 0;
		tmp = moves[i] - 1; //��� �������� -1�� ���� �迭�� �°� �ٲ��ش�.
		for (int j = 0; j < board.size(); j++) { //������ ���� Ȯ��
			if (board[j][tmp] != 0) { //ã����
				outdoll = board[j][tmp]; //������ Ż��
				board[j][tmp] = 0;
				break;
			}
		}
		if (outdoll != 0) {
			if (outs.size()< 1 || outdoll != outs[outs.size() - 1]) { //������ ���� �������
				outs.push_back(outdoll);
				continue;
			}
			//���� ������ ���.
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