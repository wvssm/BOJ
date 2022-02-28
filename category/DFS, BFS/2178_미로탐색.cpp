/*
* 문제 : 백준 2178번 미로탐색(https://www.acmicpc.net/problem/2178)
* 
* 접근 방법 : bfs(너비 우선 탐색)을 이용하여 미로에서의 최단 거리를 구하였다.
* 
* 디버깅 기록 :
* 
* Q)가로,세로 vertex 속성이 2개 있는데 큐에 어떻게 넣지?
* A)큐의 속성을 튜플로 만들고, make_pair 함수를 통해 해당 좌표를 튜플로 만들어 큐에 저장한다.
* 
* Q)어떻게 N,M vertex(미로끝)에서 탐색을 멈추지?
* A)굳이 미로끝에서 탐색을 멈출 필요가 없다.
* dfs 탐색을 통해 각 vertex들을 방문하면서 vertex마다 깊이(depth)를 이차원 배열에 저장하고, 
* 마지막에 미로끝의 깊이를 출력하면 된다.
* 
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100;

string map[MAX]; // 미로
int vis[MAX][MAX]; // 방문 체크
int dist[MAX][MAX]; // 이동 거리

int n, m; //가로, 세로

int dy[4] = { 1,0,-1,0 }; // 시계방향
int dx[4] = { 0,1,0,-1 };

void bfs(int x, int y) {
	vis[y][x] = 1; //방문 처리
	dist[y][x] = 1; //처음 거리

	queue<pair<int, int>> q;
	q.push(make_pair(x, y)); //튜플 만들어서 삽입

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();
		for (int i = 0; i < 4; i++) {
			int newY = y + dy[i]; // 새로운 y 값
			int newX = x + dx[i]; // 새로운 x 값

			if (0 <= newY && newY < n && 0 <= newX && newX < m) { //x,y가 해당 좌표안에 있고
				if (map[newY][newX] == '1' && vis[newY][newX] == 0) { //길이 있고 방문 안했을 경우
					dist[newY][newX] = dist[y][x] + 1; //거리 증가
					vis[newY][newX] = 1; // 방문 표시
					q.push(make_pair(newX, newY)); // 집어 넣기
				}
			}
		}
	}
}


int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> map[i]; // 입력 받기
	}

	bfs(0, 0);

	cout << dist[n-1][m-1]; //해당 vertex까지 최소거리 출력
}
