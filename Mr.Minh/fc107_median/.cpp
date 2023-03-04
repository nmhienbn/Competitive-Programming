#include <bits/stdc++.h>
#define fi(i, a, b) for(int i=a; i<=b; i++)
#define fid(i, a, b) for(int i=a; i>=b; i--)
#define pb push_back
#define pii pair<int,int>
#define teemo "g"
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define frop freopen(teemo".inp", "r", stdin); freopen(teemo".out", "w", stdout);
#define ll long long

const int maxn = 5e6+5;

using namespace std;

struct node{
    int deg;
    int child[2];
    int ValEnd;
};

node T[maxn];
int cnt, n, a[maxn];

void Add(int k, int v){
    int x = 0;
    fid(i, 29, 0){
        int u = (k >> i)&1;
        if (T[x].child[u] == 0) T[x].child[u] = ++cnt;
        x = T[x].child[u];
        T[x].deg += v;
    }
    T[x].ValEnd = k;
}

void Out(int k){
    int nod = 0;
    fid(i, 29, 0){
        int trai = T[nod].child[0];
        if (k <= T[trai].deg) nod = trai;
        else {
            nod = T[nod].child[1];
            k -= T[trai].deg;
        }
    }
    cout << T[nod].ValEnd << '\n';
}

int main(){ faster //frop
    cin >> n;
    fi(i, 1, n) cin >> a[i], Add(a[i], 1);
    int k = n/2 + n%2;
    fi(i, 1, n){
        Add(a[i], -1);
        Out(k);
        Add(a[i], 1);
    }

}
