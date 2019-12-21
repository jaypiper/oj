#include <iostream>
#include <stack>
#include <vector>
using namespace std;
long long n, m, s, t;
vector<vector<long long> > c(101, vector<long long>(101, 0));
vector<int> visit(101, 0);
stack<long long> trace;
stack<long long> min_f;
bool dfs(int now) {
    trace.push(now);

    visit[now] = 1;
    if (now == t)
        return true;
    for (int i = 1; i <= n; i++) {
        if (!visit[i] && c[now][i] > 0) {
            if (min_f.empty()) min_f.push(c[now][i]);
            else min_f.push(min(min_f.top(), c[now][i]));
            bool j = dfs(i);
            if (j) return true;
        }
    }
    trace.pop();
    min_f.pop();
    return false;
}

int main() {
    cin >> n >> m >> s >> t;
    int u, v, a;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> a;
        c[u][v] += a;
    }
    long long f = 0;
    while (dfs(s)) {
        int v1 = trace.top();
        int inc = min_f.top();
        trace.pop();
        while (!trace.empty()) {
            int v2 = trace.top();
            trace.pop();
            c[v1][v2] += inc;
            c[v2][v1] -= inc;
            v1 = v2;
        }
        while (!min_f.empty()) min_f.pop();
        for (int i = 1; i <= n; i++) visit[i] = 0;
        f += inc;
    }
    cout << f << endl;
    // system("pause");
    return 0;
}