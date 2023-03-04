#include <bits/stdc++.h>
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define Seraphine "keylogger"
const int maxn = 1e6+5;

using namespace std;

char c;
list<char> a;

int main(){
    faster
    freopen(Seraphine".inp", "r", stdin);
    freopen(Seraphine".out", "w", stdout);
    auto x = a.begin();
    while (cin >> c){
        if (c == '<' && x != a.begin()) x--;
        else if (c == '>' && x != a.end()) x++;
        else if (c == '-' && x != a.begin()){
            x--;
            x = a.erase(x);
        }
        else a.insert(x, c);
    }
    for (auto t : a) cout << t;
}
