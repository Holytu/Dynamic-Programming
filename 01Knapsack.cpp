#include <iostream>

using namespace std;
int max(int a, int b)
{
	if(a > b)
		return a;
	else 
		return b;
}

int Knapsack(int value[], int weight[], int W, int n)
{
	if( W == 0 || n == 0)
	{
		return 0;
	}

	if(weight[n-1] > W)
		return Knapsack(value, weight, W, n-1);
	else 
		return max(value[n-1] + Knapsack(value, weight, W-weight[n-1], n-1), Knapsack(value, weight, W, n-1));
}

int main()
{
	int value[] = {60, 100, 120};
	int weight[] = {10, 20, 30};
	
	int n = sizeof(value)/sizeof(value[0]);
	int W = 50;

	cout<<Knapsack(value, weight, W, n);	

	return 0;
}