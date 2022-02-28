// 2667_단지번호붙이기
// 참고 : 유셩장님, https://sihyungyou.github.io/baekjoon-2667/

/*
    문제 :  https://www.acmicpc.net/problem/2667

    접근 : 지도의 모든 곳을 탐색해야 한다.
    기존의 트리구조와 달리 연결구조가 상하좌우로 이루어져 있다.

    디버깅 : 기존의 dfs를 다룰 때처럼 상하좌우 없이 단순히 한 선으로 
    연결된 노드로 된 트리구조로 생각하여 vector 형식의 노드로 연결하여 만들어 실패하였다.
    하지만 여기 문제에서 아파트는 상하좌우로 연결되어 있으며
    이를 모두 체크하도록 dfs 함수를 작성해야 한다.

    지도의 모든 곳을 탐색하고 그곳에 아파트가 있으면 그자리에서 dfs를 실행하여
    상하좌우를 체크해 또 아파트가 있으면 재귀적으로 dfs를 실행하도록 코드를 작성하였다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 25;

int dx[4] = { 0,1,0,-1 }; // 상하좌우 검사
int dy[4] = { -1,0,1,0 };

string arr[MAX];

int vis[MAX][MAX]; // 방문 여부 판단
int n, cnt;
vector<int> ans; // 답을 담는 벡터

void dfs(int i, int j) {
    vis[i][j] = true; 
    cnt++;

    for (int k = 0; k < 4; k++) { // 상하좌우 검사
        int newY = i + dy[k];
        int newX = j + dx[k];

        if (0 <= newX && newX < n && 0 <= newY && newY < n) { // 해당영역 안에 들어가 있고, 아파트가 있고, 방문하지 않은 지역이면
            if (arr[newY][newX] == '1' && !vis[newY][newX]) {
                dfs(newY, newX); // 재귀적으로 dfs 실행
            }
        }
    }
}

int main()
{
    int i, j;
    cin >> n;

    for (i = 0; i < n; i++) { // string으로 입력 받아 들임
        cin >> arr[i];
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (arr[i][j] == '1' && !vis[i][j]) { 
                cnt = 0;
                dfs(i, j); // 아파트가 있으면 dfs 탐색 시작
                ans.push_back(cnt);
            }
        }
    }

    cout << ans.size() << endl;
    
    sort(ans.begin(), ans.end());

    for (i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
