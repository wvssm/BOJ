//1260번 DFS와 BFS
//동빈나님 유튜브 강의, my devlog 참고
//https://hyunah-home.tistory.com/6

#include <iostream>
#include <string.h> //메모리 초기화 때문에 사용
#include <vector>
#include <queue>
#include <algorithm> //sort 함수 사용하기 위해 사용

using namespace std;
const int MAX = 1000 + 1;
int c[MAX];
vector<int> a[MAX];

void insert_edge(int i, int j) {
    a[i].push_back(j);
    a[j].push_back(i);
}

void dfs(int start)
{
    if (c[start]) return;
    c[start] = true;
    cout << start << ' ';
    for (int i = 0; i < a[start].size(); i++) {
        int y = a[start][i];
        dfs(y);
    }
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    c[start] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << ' ';
        for (int i = 0; i < a[x].size(); i++) {
            int y = a[x][i];
            if (!c[y]) {
                q.push(y);
                c[y] = true;
            }
        }
    }
}

int main()
{
    int n, m, v, x, y;
    cin >> n >> m >> v;

    for (int i = 0; i < m; i++) { //에지 추가
        cin >> x >> y;
        insert_edge(x, y);
    }

    for (int i = 1; i <= n; i++) {
        sort(a[i].begin(), a[i].end());
    }

    dfs(v);
    cout << '\n';
    memset(c, 0, sizeof(c));
    bfs(v);
    cout << '\n';
}