#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct item{
	int val;
	int weight;
	double per;
};

bool fun(item it1, item it2)
{
	if(it1.per>it2.per)
		return 1;
	return 0;
}

int main()
{
	int n, amount;
	cin>>n>>amount;
	vector<item> vec;
	for(int i=0;i<n;i++)
	{
		item it;
		cin>>it.val>>it.weight;
		it.per=(double)it.val/it.weight;
		vec.push_back(it);
	}
	sort(vec.begin(),vec.end(),fun);
	/*for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i].per<<" ";
	}*/
	
	double max=0;
	for(int i=0;i<vec.size();i++)
	{
		if(amount==0)
			break;
		int temp=amount>vec[i].weight?vec[i].weight:amount;
		max+=temp*vec[i].per;
		amount=amount-temp;
	}
	cout.precision(10);
	cout<<max;
}
