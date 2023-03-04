#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "exam"
const int maxn = 2e5+5, maxm =2e6+5;

using namespace std;

int p[maxm];
void Erathosenes(){
    fi(i, 1, 2e6) p[i] = i;
    int u = sqrt(2e6);
    fi(i, 2, u) if (p[i] == i){
        for (int j = i*i; j <= 2e6; j += i){
            p[j] = i;
        }
    }
}

int n, res;
ll cnt[maxm];

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    Erathosenes();
    cin >> n;
    fi(i, 1, n){
        int x;
        cin >> x;
        int u = x;
        while (u > 1){
            int v = p[u];
            cnt[v]++;
            while (u % v == 0){
                u /= v;
            }
        }
    }
    fi(i, 1, 2e6){
        if (cnt[i]*i > cnt[res]*res){
            res = i;
        }
    }
    cout << res;
}
