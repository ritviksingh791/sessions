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

vi dx={-1,0,1,0};
vi dy={0,1,0,-1};
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
    pair<int,int> start;
    vpii mon;
    f(i,0,n)
    {
        f(j,0,m)
        {
            char c;
            cin>>c;
            if(c=='.')
            {
                arr[i][j]=1;
            }
            else if(c=='#')
            {
                arr[i][j]=0;
            }
            else if(c=='A')
            {
                arr[i][j]=1;
                start={i,j};
            }
            else if(c=='M')
            {
                arr[i][j]=2;
                mon.pb({i,j});
            }
        }
    }
    queue<pair<int,int>> q;
    vector<vector<int>> dist(n,vector<int>(m,imax)); 
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    for(auto x:mon)
    {
        q.push(x);
        dist[x.first][x.second]=0;
    }
    while(!q.empty())
    {
        pair<int,int> p =q.front();
        q.pop();
        vis[p.first][p.second]=1;
        for (int i = 0; i < 4; i++)
        {
            int newx=p.first+dx[i];
            int newy=p.second+dy[i];
            if(valid(newx,newy,n,m) && arr[newx][newy]==1 && !vis[newx][newy])
            {
                vis[newx][newy]=1;
                dist[newx][newy]=dist[p.first][p.second]+1;
                q.push({newx,newy});
            }

        }
        

    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if(dist[i][j]==imax)
    //         {
    //             dist[i][j]=-1;
    //         }
    //         cout<<dist[i][j]<<" ";
    //     }
    //     cout<<endl;
        
    // }
    // int dist2[n][m];
    // memset(dist2,imax,sizeof(dist2));
    vector<vector<int>> dist2(n,vector<int>(m,imax));
    vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m,{-1,-1}));
    vector<vector<bool>> vis2(n,vector<bool>(m,false));
    queue<pair<int,int>> q2;
    q2.push(start);
    parent[start.first][start.second]={-2,-2};
    vis2[start.first][start.second]=1;
    dist2[start.first][start.second]=0;
    while (!q2.empty())
    {
        auto p= q2.front();
        q2.pop();
        vis2[p.first][p.second]=1;
        for (int i = 0; i < 4; i++)
        {
            int newx=p.first+dx[i];
            int newy=p.second+dy[i];
            if(valid(newx,newy,n,m) && arr[newx][newy]==1 && !vis2[newx][newy] && dist[newx][newy]>dist2[p.first][p.second]+1)
            {
                vis2[newx][newy]=1;
                dist2[newx][newy]=dist2[p.first][p.second]+1;
                parent[newx][newy]=p;
                q2.push({newx,newy});
            }
        }

    }
    //  for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout<<parent[i][j].first<<","<<parent[i][j].second<<" ";
    //     }
    //     cout<<endl;
        
    // }
    pair<int,int> end;
    int ans=0;
    f(i,0,n)
    {
        if(ans==1)
        {
            break;
        }
        f(j,0,m)
        {
            if(i==0 || j==0 || i==n-1 || j==m-1)
            {
                if(dist2[i][j]!=imax)
                {
                    ans=1;
                    end={i,j};
                    break;
                }
            }
        }
    }
    if(ans==0)
    {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    cout<<dist2[end.first][end.second]<<endl;
    string s="";
    auto curr=end;
    while (curr.first!=-2 && curr.second!=-2)
    {
        auto p=parent[curr.first][curr.second];
        if(p.first==curr.first)
        {
            if(p.second>curr.second)
            {
                s+='L';
            }
            else
            {
                s+='R';
            }
        }
        else
        {
            if(p.first>curr.first)
            {
                s+='U';
            }
            else if(p.first!=-2)
            {
                s+='D';
            }
        }
        curr=p;
    }
    reverse(all(s));
    cout<<s<<endl;

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
