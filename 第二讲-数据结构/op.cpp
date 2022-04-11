#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;

stack<char> op;
stack<int> num;
unordered_map<char, int> prior{ {'+',1},{'-',1},{'*',2},{'/',2} };
int ans;
void eval()
{
	int y = num.top();
	num.pop();
	int x = num.top();
	num.pop();
	// cout<<"x:"<<x<<"y:"<<y<<endl;
	char operate = op.top();
	if (operate == '+') num.push(x + y);
	else if (operate == '-') num.push(x - y);
	else if (operate == '*') num.push(x * y);
	else num.push(x / y);
	op.pop();
	// cout<<num.top()<<"size:"<<num.size()<<endl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		
		
		// cout<<s[i]<<endl;
		// cout<<"i:"<<i<<" "<<num.size()<<endl;
		if (i<s.size()&&s[i] >= '0' && s[i] <= '9')//数字
		{
			int t = 0;
			while (s[i] >= '0' && s[i] <= '9')
			{
				
				t *= 10;
				t += s[i] - '0';
				i++;
			}
			num.push(t);
			// cout<<num.top();
			i--;
			// cout<<t<<endl;
		}

		else if(s[i]=='(')
		{
			op.push(s[i]);
		}
		else if (s[i] == ')')
		{
			
			
			while (op.top() != '(')
			{
				eval();
			}
			op.pop();
		}
		else 
		{
			
			while (!op.empty()&&op.top()!='(' && prior[op.top()] >= prior[s[i]]) 
			{
				
				eval();
			}
			op.push(s[i]);
		}
	}
	// cout<<"out"<<num.top()<<" size"<< num.size()<<endl;
	while (!op.empty()) eval();
	cout << num.top() << endl;
	return 0;

}