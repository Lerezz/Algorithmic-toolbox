#include<iostream>
using namespace std;
int main()
{
	int m;
	cin>>m;
	int amount=0;
	if(m/10!=0)
	{
		amount+=(m/10);
		m=m-m/10*10;
	}
	if(m/5!=0)
	{
		amount+=(m/5);
		m=m-m/5*5;
	}
	amount+=m;
	cout<<amount;
	return 0;
}
