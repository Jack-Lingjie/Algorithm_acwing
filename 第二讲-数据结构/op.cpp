#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;

stack<char> op;
stack<int> num;
int ans=0;
void eval()
{
	int y=num.top();num.pop();
	int x=num.top();num.pop();
	char sign=op.top();op.pop();
	if(sign=='+') num.push(x+y);
	else if(sign=='-') num.push(x-y);
	else if(sign=='*') num.push(x*y);
	else num.push(x/y);
}
int main()
{
	string s;
	cin>>s;
	unordered_map<char,int> priority{{'+',1},{'-',1},{'*',2},{'/',2}};
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			int sum=0;
			while(i<s.size()&&s[i]>='0'&&s[i]<='9')
			{
				sum*=10;
				sum+=s[i]-'0';
				i++;
			}
			num.push(sum);
			i--;
		}else if(s[i]=='(')
		{
			op.push(s[i]);
		}else if(s[i]==')')
		{
			while(op.top()!='(') eval();
			op.pop();//弹出（
		}else{//其他符号
			while(!op.empty()&&op.top()!='('&&priority[op.top()]>=priority[s[i]]) eval();
			op.push(s[i]);
		}
	}
	while(!op.empty()) eval();
	cout<<num.top()<<endl;
	return 0;
}