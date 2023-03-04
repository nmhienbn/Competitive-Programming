#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "strings"
const int maxn = 1e6+5, maxm = 5e4+5, mod = 18102008;

using namespace std;

struct node{
    bool isEnd;
    int child[26];
};

ll L[maxm];
node T[maxn];
int n, cnt = 0;

void Add(string s){
    int x = 0;
    for (char c : s){
        int id = c - 'a';// 0...25
        if (T[x].child[id] == 0) T[x].child[id] = ++cnt;
        x = T[x].child[id];
    }
    T[x].isEnd = 1;
}

int Found(string s){
    int x = 0;
    for (char c : s){
        int id = c - 'a';
        if (T[x].child[id] == 0) return 2;
        x = T[x].child[id];
    }
    return T[x].isEnd;
}

string ss;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    cin >> ss;
    cin >> n;
    while (n--){
        string s;
        cin >> s;
        Add(s);
    }
    n = ss.length();
    ss = ' ' + ss;
    L[0] = 1;
    fi(i, 0, n-1){
        if (L[i] != 0){
            string str = "";
            fi(j, i+1, n){
                str += ss[j];
                int t = Found(str);
                if (t == 1) L[j] = (L[j] + L[i]) % mod;
                else if (t == 2) break;
            }
        }
    }
    cout << L[n];
    return 0;
}
