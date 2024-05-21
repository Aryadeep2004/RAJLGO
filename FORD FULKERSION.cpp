#include<iostream>
#include<queue>
using namespace std;
#define MAX 100

bool bfs(int s,int t,int rg[][MAX],int p[MAX])
{
    bool vi[MAX]={false};
    queue<int> q;
    q.push(s);
    vi[s]=true;
    p[s]=-1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v=0;v<MAX;v++)
        {
            if(!vi[v] && rg[u][v]>0)
            {
                if(v==t)
                {
                    p[v]=u;
                    return true;
                }
                q.push(v);
                p[v]=u;
                vi[v]=true;

            }
        }
    }
    return false;

}

int ff(int s,int t,int g[MAX][MAX])
{
    int rg[MAX][MAX];
    for(int u=0;u<MAX;u++)
    {
        for(int v=0;v<MAX;v++)
        {
            rg[u][v]=g[u][v];
        }
    }
    int mf=0;
    int p[MAX];
    while(bfs(s,t,rg,p))
    {
        int pf=1000000;
        for(int v=t;v!=s;v=p[v])
        {
            int u=p[v];
            pf=min(pf,rg[u][v]);

        }
        for(int v=t;v!=s;v=p[v])
        {
            int u=p[v];
            rg[u][v]=rg[u][v]-pf;
            rg[v][u]=rg[u][v]+pf;
        }
        mf=mf+pf;

    }
    return mf;
}

int main()
{
    int n,s,t;
    cout<<"enter no of edges";
    cin>>n;
    int g[MAX][MAX]={0};
    for(int i=0;i<n;i++)
    {
        int c,u,v;
        cout<<"enter edge no-"<<i+1<<"\n";
        cout<<"from-";
        cin>>u;
        cout<<"to-";
        cin>>v;
        cout<<"cost-";
        cin>>c;
        g[u-1][v-1]=c;
     }
    cout<<"source vertex";
    cin>>s;
    cout<<"Destination vertex";
    cin>>t;
    int mflow=ff(s-1,t-1,g);
    cout<<"max flow is-"<<mflow;

}

