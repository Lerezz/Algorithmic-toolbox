#include<iostream>
#include<vector>
using namespace std;

void get_partition(int sorts, vector<int> goods, int avg)
{
	int score[avg+1][sorts+1]={0};
	for(int i=1;i<=avg;i++)
	{
		for(int j=1;j<=sorts;j++)
		{
			int k=i-goods[j-1];
			if(i==goods[j-1] || (k>0 && score[k][j-1]>0))
			{
				if(score[i][j-1]==0)
					score[i][j]=1;
				else
					score[i][j]=2;
			}
			else
			{
				score[i][j]=score[i][j-1];
			}
		}
	}
	if(score[avg][sorts]==2)
		cout<<1;
	else
		cout<<0;
}

int main()
{
	int num;
	cin>>num;
	
	vector<int> sou(num);
	int sum=0;
	for(int i=0;i<num;i++)
	{
		cin>>sou[i];
		sum+=sou[i];
	}
	if(sum%3!=0 || num<3)
	{
		cout<<0;
		return 0;
	}
	int avg=sum/3;
	get_partition(num, sou, avg);
}
