#include<iostream>
using namespace std;
const int N=100010;
int heap[N];
int cnt=0;//cnt从1开始计数
void down(int x)
{
    int t=x;
    if(x*2<=cnt&&heap[t]>heap[x*2]) t=x*2;
    if(x*2+1<=cnt&&heap[t]>heap[x*2+1]) t=x*2+1;
    if(t==x) return;
    swap(heap[x],heap[t]);
    down(t);
}
void up(int x)//上升
{
    if(x/2&&heap[x/2]>heap[x])
    {
        swap(heap[x/2],heap[x]);
        up(x/2);
    }else return;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>heap[++cnt];
        // up(cnt);//效率低
    }
    for(int i=n/2;i>=1;i--) down(i);
    for(int i=0;i<m;i++)
    {
        cout<<heap[1]<<" ";
        heap[1]=heap[cnt--];
        down(1);
    }
    return 0;
}