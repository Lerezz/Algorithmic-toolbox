#include <iostream>
#include <cmath>

using namespace std;

long long int Make_operation(long long int num1, long long int num2, char oper) {
	if (oper == '*')
		return num1 * num2;
	else if (oper == '+')
		return num1 + num2;
	else if (oper == '-')
		return num1 - num2;
}

long long int max_value_of_exp(const string &exp) {
	int Len = exp.size();
	int NumOfOperands = (Len + 1) / 2;

	long long int Mini[NumOfOperands][NumOfOperands]={0};
	long long int Maxi[NumOfOperands][NumOfOperands]={0};

	for (int i = 0; i < NumOfOperands; i++) {

		Mini[i][i] = exp[2 * i] - '0';
		Maxi[i][i] = exp[2 * i] - '0';
	}

	for (int s = 0; s < NumOfOperands - 1; s++) {
		for (int i = 0; i < NumOfOperands - s - 1; i++) {
			int j = i + s + 1;
			long long int MinValue = 99999;
			long long int MaxValue = -99999;

			for (int k = i; k < j; k++) {
				long long int a = Make_operation(Mini[i][k], Mini[k + 1][j], exp[2 * k + 1]);
				long long int b = Make_operation(Mini[i][k], Maxi[k + 1][j], exp[2 * k + 1]);
				long long int c = Make_operation(Maxi[i][k], Mini[k + 1][j], exp[2 * k + 1]);
				long long int d = Make_operation(Maxi[i][k], Maxi[k + 1][j], exp[2 * k + 1]);

				MinValue = min(MinValue, min(a, min(b, min(c, d))));
				MaxValue = max(MaxValue, max(a, max(b, max(c, d))));

			}
			Mini[i][j] = MinValue;
			Maxi[i][j] = MaxValue;
		}
	}

	return Maxi[0][NumOfOperands - 1];
}

int main() {
	string exp;
	cin >> exp;

	cout << max_value_of_exp(exp) << endl;
}
