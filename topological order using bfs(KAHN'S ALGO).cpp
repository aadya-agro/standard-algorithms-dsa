#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> indegree;

void kahnTopologicalSort(int vertices) {
    queue<int> q;

    for (int i = 0; i < vertices; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << current << " ";

        for (int neighbor : g[current]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    g.resize(n);
    indegree.assign(n, 0);

    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        g[l].push_back(r);
        indegree[r]++;
    }

    cout << "Topological Sorting Order: ";
    kahnTopologicalSort(n);

    return 0;
}