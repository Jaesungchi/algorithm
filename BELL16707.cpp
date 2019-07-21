#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
using namespace std;

int N, M, dist[10000];

struct Edge {
	int start, dest, distance;
};

Edge* edge;

void printArr() {
	for (int i = 0; i < N+1; ++i)
		dist[i] == INT_MAX ? printf("%d \t\tINF\n", i) : printf("%d \t\t %d\n", i, dist[i]);
}

void BellmanFord(int src) {
	for (int i = 0; i < N; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < M*2; j++) {
			int u = edge[j].start;
			int v = edge[j].dest;
			int weigth = edge[j].distance;
			//시작점이 무한대가 아니고. 시작점까지의 최단거리 + 가중치가 도착점의 가중치보다 작을때
			if (dist[u] != INT_MAX && dist[u] + weigth < dist[v])
				dist[v] = dist[u] + weigth;
		}
	}
	printArr();
}

int main() {
	cin >> N >> M; //위치 수 N, 도로 수 M;
	edge = (struct Edge*) malloc(N * sizeof(struct Edge));
	for (int i = 0; i < M*2; i+=2) {
		int A = 0, B = 0, C = 0;
		cin >> A >> B >> C;
		edge[i].start = edge[i+1].dest = A-1;
		edge[i].dest = edge[i+1].start = B-1;
		edge[i].distance = edge[i+1].distance= C;
	}
	BellmanFord(0);
	
}