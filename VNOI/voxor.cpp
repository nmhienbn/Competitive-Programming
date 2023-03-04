#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fid(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define gb(x, i) (((x) >> (i)) & 1)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define Irelia "voxor"
const int maxn = 1e5 + 5;
using namespace std;

int n, q, cnt;
int flip[32], ans;

struct node {
    int child[2];
    int deg, num;
} T[maxn * 32];

void add(int n){
    int x = 0;
    fid(i, 31, 0){
        bool now = gb(n, i);
        if (!T[x].child[now]) T[x].child[now] = ++cnt;
        x = T[x].child[now];
        T[x].deg++;
    }
    T[x].num = n;
}

void XOR(int n){
    ans ^= n;
    fid(i, 31, 0) if (gb(n, i)){
        flip[i] ^= 1;
    }
}

int get(int k){
    int x = 0;
    fid(i, 31, 0){
        int l = flip[i], r = l ^ 1;
        if (T[T[x].child[r]].deg >= k) x = T[x].child[r];
        else k -= T[T[x].child[r]].deg, x = T[x].child[l];
    }
    return T[x].num ^ ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen(Irelia".inp", "r", stdin);
    freopen(Irelia".out", "w", stdout);
    cin >> n >> q;
    fi(i, 1, n){
        int x;
        cin >> x;
        add(x);
    }
    while (q--){
        string typ;
        int x;
        cin >> typ >> x;
        if (typ[0] == 'F'){
            cout << get(x) << '\n';
        }
        else {
            XOR(x);
        }
    }

}
