#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "autocomp"
const int maxn = 1e6+5;

using namespace std;

struct node {
    int child[26];
    int deg, isEnd, con;
} T[maxn];

int id;

void add(string s, int t){
    int x = 0;
    for (char c : s){
        int now = c - 'a';
        if (!T[x].child[now]) T[x].child[now] = ++id;
        int u = x;
        x = T[x].child[now];
        if (T[x].deg == 0) T[u].con++;
        T[x].deg += t;
        if (T[x].deg == 0) T[u].con--;
    }
    T[x].isEnd += t;
}

int get(string s){
    int x = 0, ans = 0, cnt = 0;
    for (char c : s){
        int now = c - 'a';
        if (T[x].isEnd){
            ans += (cnt > 0);
            cnt = 0;
        }
        if (T[x].con+T[x].isEnd > 1){
            ans++;
            ans += (cnt > 0);
            cnt = 0;
        }
        else {
            cnt++;
        }
        x = T[x].child[now];
    }
    ans += (cnt > 0);
    return ans;
}

int q;
vector<string> s;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> q;
    while (q--){
        char typ;
        cin >> typ;
        if (typ == '+'){
            string t;
            cin >> t;
            s.pb(t);
            add(t, 1);
        }
        else {
            int vt;
            cin >> vt;
            if (typ == '-'){
                add(s[vt-1], -1);
            }
            else {
                cout << get(s[vt-1]) << '\n';
            }
        }
    }
}
