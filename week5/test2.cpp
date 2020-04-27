#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void back_trace(vector<int> vec)
{
	vector<int> res;
	int end = vec.size() - 1;
	res.push_back(end);
	while (end > 1)
	{
		int flag = 0;
		if (vec[end - 1] == vec[end] - 1)
		{
			res.insert(res.begin(), end - 1);
			end--;
			flag = 1;
		}
		else if (end % 2 == 0 && vec[end / 2] == vec[end] - 1)
		{
			res.insert(res.begin(), end / 2);
			end = end / 2;
			flag = 1;
		}
		else if (end % 3 == 0 && vec[end / 3] == vec[end] - 1)
		{
			res.insert(res.begin(), end / 3);
			end = end / 3;
			flag = 1;
		}
		if (flag == 0) break;
	}
	res.insert(res.begin(), 1);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
}

void get_result(int num)	// O(n)
{
	vector<int> vec(num + 1);
	for (int i = 0; i < num + 1; i++)
	{
		vec[i] = num + 1;
	}
	vec[0] = 0;
	vec[1] = 1;
	vec[2] = 1;
	vec[3] = 1;
	for (int i = 4; i < num + 1; i++)
	{
		int m1 = vec[i - 1] + 1;
		int m2 = vec[i / 2] + 1 + (i - i / 2 * 2);
		int m3 = vec[i / 3] + 1 + (i - i / 3 * 3);
		vec[i] = min(m1, min(m2, m3));
	}
	cout << vec[num] << endl;
	back_trace(vec);
}

int main()
{
	int num;
	cin >> num;
	if(num==1)
	{
		cout<<0<<endl<<1;
		return 0;
	}
	get_result(num);
}
