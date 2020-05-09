#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<vector<int>, vector<int>>> tgem; // 어디와 연결 되어있는지
//tgem[index].first = 갈수 있는곳.
//tgem[index].second[0] = 여기를 가야 index가 열림 0이면 열려있음.
//tgem[index].second[0보다 큰값] = index를 들리면 열리는 곳.
int N;

bool BFS(int start, int end) {
	vector<pair<vector<int>, vector<int>>> gem;
	gem.assign(tgem.begin(), tgem.end());
	vector<bool> chk;
	for (int i = 0; i < N; i++)
		chk.push_back(false);
	queue<int> q;
	q.push(start);
	chk[start] = true;
	while (!q.empty()) {
		int idx = q.front();
		q.pop();
		for (int i = 1; i < gem[idx].second.size(); i++)
			gem[gem[idx].second[i]].second[0] = 0; //문을 연다.
		if (idx == end) {
			tgem[end].second[0] = 0; //문을 연다.
			for (int i = 1; i < tgem[end].second.size(); i++)
				tgem[tgem[end].second[i]].second[0] = 0; //문을 연다.
			return true;
		}
		//이동한다.
		for (int i = 0; i < gem[idx].first.size(); i++) {
			int toGo = gem[idx].first[i];
			if (chk[toGo])
				continue; //들렀던 곳.
			if (gem[toGo].second[0] == 0) {
				q.push(toGo);
				chk[toGo] = true;
			}
		}
	}
	return false;
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
	N = n; //방 갯수확인.
	vector<int> tmp;
	vector<int> tmp2;
	tmp2.push_back(0);//첫번째는 해제할 수 있는 문.
	for (int i = 0; i < n; i++)
		tgem.push_back(make_pair(tmp, tmp2));
	for (int i = 0; i < path.size(); i++) {
		int head = path[i][0];
		int child = path[i][1];
		tgem[head].first.push_back(child); //자식을 넣는다.
		tgem[child].first.push_back(head);
	}
	for (int i = 0; i < order.size(); i++) {
		int key = order[i][0];
		int door = order[i][1];
		tgem[door].second[0] = key;
		tgem[key].second.push_back(door); //이곳을 들리면 열리는 곳.
	}
	//order를 갈 수 있는지 확인하며, 유효성 검사만 한다.
	while (order.size() > 0) {
		int cnt = 0;
		for (int i = 0; i < order.size(); i++) {
			if (BFS(order[i][0], order[i][1])) {
				cnt++;
				order.erase(order.begin() + i);
				i--;
				break;
			}
		}
		if (cnt == 0)
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//vector < vector<int>> arr;
	//vector<int>tmp;
	//tmp.clear();
	//tmp.push_back(0);
	//tmp.push_back(1);
	//arr.push_back(tmp);
	//tmp.clear();
	//tmp.push_back(0);
	//tmp.push_back(3);
	//arr.push_back(tmp);
	//tmp.clear();
	//tmp.push_back(0);
	//tmp.push_back(7);
	//arr.push_back(tmp);
	//tmp.clear();
	//tmp.push_back(8);
	//tmp.push_back(1);
	//arr.push_back(tmp);
	//tmp.clear();
	//tmp.push_back(3);
	//tmp.push_back(6);
	//arr.push_back(tmp);
	//tmp.clear();
	//tmp.push_back(1);
	//tmp.push_back(2);
	//arr.push_back(tmp);
	//tmp.clear();
	//tmp.push_back(4);
	//tmp.push_back(7);
	//arr.push_back(tmp);
	//tmp.clear();
	//tmp.push_back(7);
	//tmp.push_back(5);
	//arr.push_back(tmp);
	//vector < vector<int>> arr2;
	//tmp.clear();
	//tmp.push_back(4);
	//tmp.push_back(1);
	//arr2.push_back(tmp);
	//tmp.clear();
	//tmp.push_back(8);
	//tmp.push_back(7);
	//arr2.push_back(tmp);
	//tmp.clear();
	//tmp.push_back(6);
	//tmp.push_back(5);
	//arr2.push_back(tmp);

	//2번
	vector < vector<int>> arr;
	vector<int>tmp;
	tmp.clear();
	tmp.push_back(8);
	tmp.push_back(1);
	arr.push_back(tmp);
	tmp.clear();
	tmp.push_back(0);
	tmp.push_back(1);
	arr.push_back(tmp);
	tmp.clear();
	tmp.push_back(1);
	tmp.push_back(2);
	arr.push_back(tmp);
	tmp.clear();
	tmp.push_back(0);
	tmp.push_back(7);
	arr.push_back(tmp);
	tmp.clear();
	tmp.push_back(4);
	tmp.push_back(7);
	arr.push_back(tmp);
	tmp.clear();
	tmp.push_back(0);
	tmp.push_back(3);
	arr.push_back(tmp);
	tmp.clear();
	tmp.push_back(7);
	tmp.push_back(5);
	arr.push_back(tmp);
	tmp.clear();
	tmp.push_back(3);
	tmp.push_back(6);
	arr.push_back(tmp);
	vector < vector<int>> arr2;
	tmp.clear();
	tmp.push_back(4);
	tmp.push_back(1);
	arr2.push_back(tmp);
	tmp.clear();
	tmp.push_back(5);
	tmp.push_back(2);
	arr2.push_back(tmp);
	cout << solution(9,arr,arr2);
}