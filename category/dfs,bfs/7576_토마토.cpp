/*
* 문제 : 백준 7576 토마토 (https://www.acmicpc.net/problem/7576)
* 
* 문제 설명 : 창고에 보관된 토마토들 중 익은 토마토는 상하좌우 인근 토마토에게
* 다음날 익도록 영향을 준다. 토마토가 없는 경우는 -1로 표기되고 영향을 주지 않는다.
* 모든 토마토가 익으려면 최소 며칠이 되는지 구하는 것이 문제이다.
* 
* 접근 방법 : bfs (너비우선탐색) 이용
* 깊이가 가장 깊은 인덱스가 가장 마지막에 익는 토마토가 된다.
* 
* 디버깅 기록 :
* Q) 토마토가 없는 영역은 어떻게 처리 할 것인가?
* A) bfs 탐색을 멈춘다.
* 
* Q) 모든 토마토가 익었는지는 어떻게 확인 할 것인가?
* A) for문을 일일이 돌려 확인한다.
* 
* Q) 1이 여려개 있을때 동시에 bfs 탐색을 어떻게 할 것인가?
* A) bfs를 잘모를때 하는 질문이다.
* 가장 먼저 탐색할 것들을 queue(큐)에다가 집어 넣으면 된다.
* 그 이후에 bfs 탐색 함수를 돌리면 자연스럽게 이루어 질것이다.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1000; 
// 무식한점 채우기 static 변수는 함수를 벗어나더라도 사라지지 않고 유지
// const 변수 : 값을 변경할 수 없는 변수

int map[MAX][MAX];
int vis[MAX][MAX];
int dist[MAX][MAX];

int m,n;

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
queue<pair<int, int>>q;

void bfs() {
    while (!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int newY = dy[i] + y;
            int newX = dx[i] + x;

            if (0 <= newY && newY < n && 0 <= newX && newX < m) {
                if (map[newY][newX] == 0 && vis[newY][newX] == 0) {
                    dist[newY][newX] = dist[y][x] + 1;
                    vis[newY][newX] = 1;
                    q.push(make_pair(newY, newX));
                }
            }
        }
    }
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i++) { // 토마토 위치 입력 받기
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < n; i++) { // 익은 토마토가 있는 곳에서 bfs 탐색 시작
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 1) {
                q.push(make_pair(i, j));
            }
        }
    }
    bfs();

    int result = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] == 0 && map[i][j] == 0) { 
                cout << -1; // 익지 않은 토마토 있으면 -1 출력
                return 0;
            }
            result = max(result, dist[i][j]); // 그렇지 않은 경우에는 가장 마지막일에 익은 토마토 날짜 구하기
        }
    }

    cout << result;
    return 0;
}