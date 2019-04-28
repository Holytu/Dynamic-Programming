#include <iostream>

using namespace std;
int Hanoi(int n)
{
	if(n > 1)
	{
		return 2 * Hanoi(n - 1) + 1;
	}
	else
	{
		return 1;
	}
}
int Combination(int n, int m)
{
	if(n == 1)
	{
		return 1;
	}
	else if(m == 1)
	{
		return n;
	}
	else
	{
		return Combination(n - 1, m - 1) + Combination(n - 1, m);
	}
}
int main(void)
{
	cout<<Hanoi(5)<<endl;

	cout<<Combination(5, 3)<<endl;
	return 0;
}