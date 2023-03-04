#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define ll long long
#define pii pair <int, int>
#define pb push_back
#define Irelia "mirror"
const int maxn = 1e5 + 5;

using namespace std;

struct dl {
    int x, y, z, t;
} a[maxn];

int w, h, k, m, sx, sy, d;
int tren[maxn], duoi[maxn], trai[maxn], phai[maxn];

/*
0 phai
1 duoi
2 trai
3 tren
*/

bool cmpf(dl a, dl b){
    return a.x == a.x ? a.y < b.y : a.x < b.x;
}
bool cmps(dl a, dl b){
    return a.y == b.y ? a.x < b.x : a.y < b.y;
}
bool cmpt(dl a, dl b){
    return a.t < b.t;
}

void adj(){
    sort(a + 1, a + m + 1, cmpf);
    fi(i, 2, m){
        if (a[i].x == a[i - 1].x){
            duoi[a[i].t] = a[i - 1].t;
            tren[a[i - 1].t] = a[i].t;
        }
    }
    sort(a + 1, a + m + 1, cmps);
    fi(i, 2, m){
        if (a[i].y == a[i - 1].y){
            trai[a[i].t] = a[i - 1].t;
            phai[a[i - 1].t] = a[i].t;
        }
    }
    sort(a + 1, a + m + 1, cmpt);
}

void dfs(int i, int j, int)

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> w >> h >> m >> sx >> sy >> d;
    fi(i, 1, m){
        cin >> a[i].x >> a[i].y >> a[i].z;
        a[i].t = i;
    }
    adj();
    dfs(sx, sy, d);

}
