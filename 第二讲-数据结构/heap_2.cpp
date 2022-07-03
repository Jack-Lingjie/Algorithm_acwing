#include<iostream>
using namespace std;
const int N=100010;
int heap[N],p[N],rp[N];
int cnt=0,idx=0;
void heap_swap(int x,int y)
{
    swap(heap[x],heap[y]);
    swap(p[rp[x]],p[rp[y]]);//换反向指针
    swap(rp[x],rp[y]);//换正向指针
}
void down(int x)
{
    int t=x;
    if(x*2<=cnt&&heap[t]>heap[x*2]) t=x*2;
    if(x*2+1<=cnt&&heap[t]>heap[x*2+1]) t=x*2+1;
    if(x==t)
    {
        return ;
    }
    heap_swap(x,t);
    down(t);
    
}
void up(int x)
{
    if(x/2>0&&heap[x/2]>heap[x]) 
    {
        heap_swap(x,x/2);  
        up(x/2);
    }else return;

}
int main()
{
    int n;
    cin>>n;
    string op;
    int k,x;
    for(int i=0;i<n;i++)
    {
        cin>>op;
        if(op=="I")
        {
            cin>>x;
            heap[++cnt]=x;
            p[++idx]=cnt;
            rp[cnt]=idx;
            up(cnt);//上升
        }else if(op=="PM")
        {
            cout<<heap[1]<<endl;
        }else if(op=="DM")
        {
            heap_swap(1,cnt);
            cnt--;//删除
            down(1);
        }else if(op=="D")
        {
            cin>>k;
            int t=p[k];
            heap_swap(p[k],cnt);
            cnt--;
            down(t);
            up(t);
        }else if(op=="C")
        {
            cin>>k>>x;
            // cout<<"Change:"<<heap[p[k]]<<endl;
            heap[p[k]]=x;
            up(p[k]);
            down(p[k]);
            // cout<<"Changed:"<<heap[p[k]]<<endl;
        }
    }
    return 0;
}