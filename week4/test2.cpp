#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<string> vec;
	for(int i=0;i<n;i++)
	{
		string num;
		cin>>num;
		vec.push_back(num);
	}
	sort(vec.begin(),vec.end());
	
	int count=1;
	int req=n/2;
	for(int i=0;i<vec.size();i++)
	{
		if((i+req)>vec.size()-1)
			break;
		if(vec[i+req]==vec[i])
		{
			cout<<1;
			return 0;
		}
	}
	cout<<0;
}
