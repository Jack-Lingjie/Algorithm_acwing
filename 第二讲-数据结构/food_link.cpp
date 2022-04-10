#include<iostream>
using namespace std;
const int N=50010;
int p[N],dist[N];//d距离数组
int find(int x)
{
    if(x!=p[x])
    {
        int t=find(p[x]);
        dist[x]+=dist[p[x]];
        p[x]=t;
    }
    return p[x];
}

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) p[i]=i;
    int sum=0;
    for(int i=0;i<k;i++)
    {
        int d,x,y;
        cin>>d>>x>>y;
        int px=find(x);
        int py=find(y);
        if(x>n||y>n)
        {
            sum++;
            continue;
        }
        if(d==1)//是否是同类
        {

            if(px==py)//在同一个集合中
            {
                if((dist[x]-dist[y])%3==0)//并且属于同一个类
                    continue;
                else sum++
            }else{  //不在同一个集合中
                dist[px]=dist[y]-dist[x];
                p[px]=py;

            }
        }else{//x吃y
            if(px==py)//x和y在同一个集合中
            {
                if((dist[x]-dist[y]-1)%3==0)//能够吃
                    continue;
                else sum++;//假话
            }else{//不在同一个集合中
                dist[px]=dist[y]-dist[x]+1;
                p[find(x)]=find(y);

            }

        }
    }

    cout<<sum<<endl;
    return 0;
}
