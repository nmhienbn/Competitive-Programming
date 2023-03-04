#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "depart"
const int maxn = 1e4+5;
const int mod = 1e9+7;

using namespace std;

struct node {
    int child[26];
    bool isEnd;
} T[maxn*100];

int n, cnt, L[maxn];
string S;

void Add(string s){
    int x = 0;
    for (auto c : s){
        int now = c - 'a';
        if (T[x].child[now] == 0) T[x].child[now] = ++cnt;
        x = T[x].child[now];
    }
    T[x].isEnd = 1;
}

void Calc(int bd){
    int x = 0;
    fi(i, bd, n){
        int c = S[i] - 'a';
        if (T[x].child[c] == 0) return;
        x = T[x].child[c];
        if (T[x].isEnd) L[i] = (L[i]+L[bd-1]) % mod;
    }
}

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> n;
    while (n--){
        string s;
        cin >> s;
        Add(s);
    }
    cin >> S;
    n = S.size();
    S = ' ' + S;
    L[0] = 1;
    fi(i, 1, n){
        Calc(i);
    }
    cout << L[n];
}
