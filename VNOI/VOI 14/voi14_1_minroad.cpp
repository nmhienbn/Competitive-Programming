#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;

int n;
pair<int, int> c[maxn];
int now[3], need[3];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> need[1] >> need[2];
    for (int i = 1; i <= n; i++) cin >> c[i].first >> c[i].second;
    sort(c + 1, c + n + 1);
    int j = 1;
    int res = 2e9;
    for (int i = 1; i <= n; i++){
        now[c[i].second]++;
        while (j <= i && now[c[j].second] > need[c[j].second] && now[3 - c[j].second] >= need[3 - c[j].second]){
            now[c[j++].second]--;
        }
        if (now[1] >= need[1] && now[2] >= need[2]){
            res = min(res, c[i].first - c[j].first);
        }
    }
    if (res == 2e9){
        cout << -1;
    }
    else {
        cout << res;
    }
}
