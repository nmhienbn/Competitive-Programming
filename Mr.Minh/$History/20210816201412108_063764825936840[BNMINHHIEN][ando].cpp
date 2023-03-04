#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "ando"
const int maxn = 3e5+5;

using namespace std;

struct node {
    int child[2], val;
} T[maxn*32];

int n, a[maxn], cnt, res;

void Add(int x){
    int pos = 0;
    fid(i, 31, 0){
        int now = (x >> i) & 1;
        if (!T[pos].child[now]) T[pos].child[now] = ++cnt;
        pos = T[pos].child[now];
    }
    T[pos].val = x;
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    fi(i, 1, n){
        cin >> a[i];
        //Add(a[i]);
    }
    random_shuffle(a+1, a+n+1);
    fi(i, 2, n){
        fi(j, 1, i-1){
            if (a[i] < res) continue;
            if ((a[i] & a[j]) > res){
                res = a[i] & a[j];
            }
        }
    }
    cout << res;
}
