// 1012_유기농 배추
// dfs, bfs 관련 문제

/*
* 문제 : https://www.acmicpc.net/problem/1012
* 
* 접근 방법 : 2667번 단지번호붙이기와 같이 단순한 dfs 문제이다.
* 기존 트리구조 탐색과 달리 배추가 좌표 값을 가지고 있어서 이차원 배열로 풀면 편하다.
* 각각의 지역을 탐색하다 배추가 있는 곳이 나타나면
* 그 위치에서 상하좌우로 dfs 탐색을 재귀적으로 해주면 된다.
* 
* 디버깅 : 방문 여부를 알아보는 vi 이차원 배열을 초기화 시켜주지 않아서 오답 처리가 계속 되었다. 
* memset 함수를 이용하여 vi 배열을 초기화시켜 주었다.
* 
* memset(메모리의 시작 주소, 넣을 값, 길이);
* 
* 더 생각해 볼 점 : 시간복잡도를 줄일 수 없을까?
* 이중 for문으로 원래 해결하는 건가?
*/

#include <iostream>
#include <vector>
#include <string.h>
#include <string>
using namespace std;

const int MAX = 50;
int t, m, n, k, x, y, cnt;
int map[MAX][MAX];
bool vi[MAX][MAX];
vector<int> ans;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };

void dfs(int y, int x) {
    vi[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int newY = y + dy[i];
        int newX = x + dx[i];

        if (0 <= newY && newY < n && 0 <= newX && newX < m) {
            if (map[newY][newX] == 1 && !vi[newY][newX]) {
                dfs(newY, newX);
            }
        }
    }
}

int main()
{
    cnt = 0;
    int i, j, p;
    cin >> t;

    for (p = 0; p < t; p++) {
        cnt = 0;
        cin >> m >> n >> k; // 가로, 세로, 배추의 개수 입력
        
        for (j = 0; j < k; j++) {
            cin >> x >> y;
            map[y][x] = 1;
        }

        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (map[i][j] == 1 && !vi[i][j]) {
                        dfs(i, j);
                        cnt++; // 한 배추모임의 탐색 종료 (필요한 지렁이 수 증가)
                }
            }
        }
        
        memset(map, 0, sizeof(map));
        memset(vi, false, sizeof(vi)); // vi 배열 초기화
        ans.push_back(cnt);
    }

    for (i = 0; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}