#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 5;
int nt, n, m;
pair<int, int> a[maxn], b[maxn];

bool check(int g){
    for (int i = 1; i <= g; i++) b[i] = a[i];
    sort(b + 1, b + g + 1);
    int j = 1;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= m; i++){
        while (j <= g && b[j].first <= i){
            q.push(b[j].second);
            j++;
        }
        if (q.size()){
            if (q.top() < i) return 0;
            else q.pop();
        }
    }
    return q.empty();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> nt;
    while (nt--){
        cin >> m >> n;
        for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
        int d = 1, c = n;
        while (d <= c){
            int g = (d + c) >> 1;
            if (check(g)) d = g + 1;
            else c = g - 1;
        }
        cout << c << '\n';
    }
}
