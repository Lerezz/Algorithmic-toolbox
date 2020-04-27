#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	if(n==0)
		return 0;
	if(n<=2)
	{
		cout<<1<<endl<<n;
		return 0;
	}
		
	vector<int> vec;
	vec.push_back(1);
	int rest=n-1;
	while(1)
	{
		if(rest>vec[vec.size()-1])
		{
			vec.push_back(vec[vec.size()-1]+1);
			rest-=vec[vec.size()-1];
		}
		else if(rest<=vec[vec.size()-1])
		{
			vec[vec.size()-1]+=rest;
			break;
		}	
	}
	cout<<vec.size()<<endl<<vec[0];
	for(int i=1;i<vec.size();i++)
	{
		cout<<" "<<vec[i];
	}
}
