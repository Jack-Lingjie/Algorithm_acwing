#include<iostream>
using namespace std;
int main()
{
    double n;
    scanf("%lf",&n);
    double left=-100,right=100;
    while(right-left>1e-8)
    {
        double mid=(left+right)/2;
        if(mid*mid*mid>=n)
        {
            right=mid;
        }else{
            left=mid;
        }
    }
    printf("%.6f",left);
}