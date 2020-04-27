#include<iostream>
#include<vector>
using namespace std;

int get_min_coins(int amount)
{
	vector<int> vec(amount+1);
	for(int i=1;i<amount+1;i++)
	{
		vec[i]=amount+1;
	}
	vec[0]=0;
	vec[1]=1;
	vec[2]=2;
	vec[3]=1;
	vec[4]=1;
	for(int i=5;i<vec.size();i++)
	{
		vec[i]=min(vec[i-1], min(vec[i-3], vec[i-4]))+1;
	}
	cout<<vec[amount];
}

int main()
{
	int amount;
	cin>>amount;
	int num=0;
	get_min_coins(amount);
}
