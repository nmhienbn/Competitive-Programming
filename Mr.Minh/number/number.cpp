#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define bit(x, i) ((x >> i) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "number"
const int maxn = 1e7+5;
using namespace std;

int a[20], b[20], n;
bool p[maxn];
set<int> cnt;

void Erathosenes(){
    p[0] = p[1] = 1;
    fi(i, 2, 3200) if (!p[i]){
        for (int j = i*i; j <= 1e7; j += i){
            p[j] = 1;
        }
    }
}

void xuli(int n){
    int now = 0;
    fi(i, 1, n){
        now = now*10 + b[i];
    }
    if (!p[now]){
        cnt.insert(now);
    }
}

void ql(int i){
    fi(j, 0, 9) if (a[j]){
        b[i] = j;
        a[j]--;
        if (i < n) ql(i+1);
        xuli(i);
        a[j]++;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    Erathosenes();
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        n = s.size();
        fi(i, 0, 9) a[i] = 0;
        for (char c : s){
            a[c - '0']++;
        }
        cnt.clear();
        ql(1);
        cout << cnt.size() << '\n';
    }
}
