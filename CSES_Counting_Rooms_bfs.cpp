#include <bits/stdc++.h>
using namespace std;

#define f(i,a,n) for(long long i = a; i < n; i++)
#define rf(i,a,n) for(long long i = a; i > n; i--)
#define endl "\n"
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define meh {cout<<"NO"<<endl;return;}
#define yay {cout<<"YES"<<endl;return;}
#define ok(t) {cout<<t<<endl;return;}
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define vin(v) for(auto&x:v)cin>>x;

typedef vector<int> vi;
typedef vector<pair<int,int>> vpii;
typedef vector<vector<int>> vvi;
typedef map<int,int> mii;
typedef set<int> si;
typedef set<char> sc;

const int MAXN = 200100;
const int MOD = 1000000007;
const int imax = LONG_LONG_MAX;
const int imin = LONG_LONG_MIN;

vi dx={1,-1,0,0};
vi dy={0,0,1,-1};

bool valid(int x,int y,int n,int m)
{
    if(x>=0 && x<n && y>=0 && y<m)
    {
        return true;
    }
    return false;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin>>c;
            if(c=='.')
            {
                arr[i][j]=1;
            }
            else
            {
                arr[i][j]=0;
            }
        }
    }
    bool vis[n][m];
    memset(vis,false,sizeof(vis));
    int count=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(arr[i][j]==0)
            {
                continue;
            }

            if(arr[i][j]==1 && !vis[i][j])
            {
                queue<pair<int,int>> q;
                q.push(mp(i,j));
                vis[i][j]=true;
                while (!q.empty())
                {
                    pair<int,int> p=q.front();
                    q.pop();
                    int x=p.first;
                    int y=p.second;
                    for (int k = 0; k < 4; k++)
                    {
                        int new_x=x+dx[k];
                        int new_y=y+dy[k];
                        if(valid(new_x,new_y,n,m))
                        {
                            if(!vis[new_x][new_y]&&arr[new_x][new_y]==1)
                            {
                                q.push(mp(new_x,new_y));
                                vis[new_x][new_y]=true;
                            }
                        }
                    }
                }
                count++;
                
            }

        }
        
    }
    cout<<count<<endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    for(int I = 1; I <= T; I++)
    {
        solve();
    }
    return 0;
}
