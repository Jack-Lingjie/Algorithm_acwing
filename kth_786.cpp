    #include<iostream>
    using namespace std;
    int find_k(int q[],int left,int right,int k)
    {
        // if(left+1==k) return left;
        // cout<<"?"<<endl;
        if(left>=right) return q[left];
        int i=left-1,j=right+1,x=q[left];
        while(j>i)
        {
            while(q[++i]<x);
            while(q[--j]>x);
            if(j>i) swap(q[i],q[j]);
        }
        // cout<<"j:"<<j<<"right:"<<right<<endl;
        if(j+1<k)  return find_k(q,j+1,right,k);//在左边找   
        else return find_k(q,left,j,k);
    }
    int main()
    {
        int n,k;
        cin>>n>>k;
        int *a=new int[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        // cout<<"?"<<endl;
        int result=find_k(a,0,n-1,k);
        cout<<result;
    }