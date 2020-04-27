#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void get_longest_common_sequences(vector<int> a, vector<int> b)
{
	vector<int> row(b.size() + 1, 0);
	vector< vector<int> > score(a.size() + 1, row);
	for (int i = 1; i < a.size() + 1; i++)
	{
		for (int j = 1; j < b.size() + 1; j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				score[i][j] = 1 + score[i - 1][j - 1];
			}
			else
			{
				score[i][j] = max(score[i - 1][j], score[i][j - 1]);
			}
		}
	}
	cout << score[a.size()][b.size()];
}

int main()
{
	int lena, lenb;
	vector<int> a, b;
	cin >> lena;
	for (int i = 0; i < lena; i++)
	{
		int num;
		cin >> num;
		a.push_back(num);
	}
	cin >> lenb;
	for (int i = 0; i < lenb; i++)
	{
		int num;
		cin >> num;
		b.push_back(num);
	}
	get_longest_common_sequences(a, b);
}
