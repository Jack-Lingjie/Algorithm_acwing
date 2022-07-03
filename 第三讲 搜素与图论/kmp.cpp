    //KMP算法
    #include<iostream>
    #include<string>
    using namespace std;
    int n,m;
    string s,p;
    const int N=100010;
    int ne[N];
    int getNe(int x)
    {
        for(int i=x-1;i>=0;i--)//m^2
        {
            int j;
            for(j=x;j>=x-i;j--)
            {
                if(p[j]!=p[i-(x-j)]) break;
            }
            if(j<x-i) return i;
            if(i==0) return -1;
        }
        return -1;
    }
    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cin>>m;
        cin>>p;
        cin>>n;
        cin>>s;

        m=p.size();
        n=s.size();
        //求next数组
        // for(int i=0;i<m;i++)
        // {
        //     ne[i]=getNe(i);
        // }
        //快速求next数组

        ne[0]=-1;
        for(int i=1;i<m;i++)
        {
            int j=i-1;
            while(j!=-1&&p[i]!=p[ne[j]+1]) j=ne[j];
            if(j==-1) ne[i]=-1;
            else ne[i]=ne[j]+1; 
            // cout<<i<<" ne[i] "<<ne[i]<<endl;
        }
        // for(int i=0;i<m;i++) cout<<ne[i]<<endl;
        //匹配
        for(int i=0,j=-1;i<n;i++)
        {
            while(j!=-1&&s[i]!=p[j+1]) j=ne[j];
            if(s[i]==p[j+1]) j++;
            if(j==m-1)//匹配完成   
            {
                cout<<i-j<<" ";
                j=ne[j];
            }
        }
        cout<<endl;
    }