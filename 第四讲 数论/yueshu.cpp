    #include<iostream>
    #include<vector>
    using namespace std;
    void getYueshu(int x)
    {
        vector<int> v1,v2;
        for(int i=1;i<=x/i;i++)
        {
            if(x%i==0) 
            {
            v1.push_back(i);
            if(x/i!=i) v2.push_back(x/i);
            }
        }
        for(auto &i:v1) cout<<i<<" ";  //前半部分
        for(int i=v2.size()-1;i>=0;i--) cout<<v2[i]<<" ";  //后半部分
        cout<<endl;
    }
    int main()
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            getYueshu(x);
        }
        return 0;
    }