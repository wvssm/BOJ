// 2606_바이러스
// dfs, bfs 관련문제

//디버깅 : 
// 전파 바이러스를 퍼뜨린 컴퓨터를 제외하고 감염된 컴퓨터 수 만 출력해야되는데
// 감염을 퍼뜨린 컴퓨터까지 cnt에 포함하였다. 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100 + 1;

vector<int> a[MAX];
int c[MAX];
int cnt = 0;

void insert_node(int i, int j) {
    a[i].push_back(j);
    a[j].push_back(i);
}

void dfs(int start) {
    if (c[start]) return;

    c[start] = true;
    cnt++;

    for (int i = 0; i < a[start].size(); i++) {
        int y = a[start][i];
        dfs(y);
    }
}

int main()
{
    int n, m, x, y;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        insert_node(x, y);
    }

    for (int i = 1; i <= n; i++) { // 번호가 작은 노드 순서대로 돌도록 vector를 정렬해 줌
        sort(a[i].begin(), a[i].end());
    }

    dfs(1);

    cout << cnt-1;
}
