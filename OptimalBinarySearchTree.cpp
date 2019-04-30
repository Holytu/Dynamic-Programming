#include <iostream> 
using namespace std; 
int sum(int i, int j, int freq[])
{
	int sum = 0;
	for (int k = i; k <= j; k++)
	{
		sum += freq[k];
	}

	return sum;
}

int OptCost(int keys[], int freq[], int i, int j)
{
	if (j < i)
		return 0;
	else if (j == i)
		return freq[i];

	int min = 1e9;
	int fsum = sum(i , j, freq);

	for (int r = i; r <= j; ++r)
	{
		int optL = OptCost(keys, freq, i, r-1);
		int optR = OptCost(keys, freq, r+1, j);

		if (min > optR + optL)
		{
			min = optL + optR;
		}
	}
	
	return min + fsum;
}

int OptimalBinarySearchTree(int keys[], int freq[], int n)
{
	return OptCost(keys, freq, 0, n - 1);
}
int main(void)
{
	int keys[] = {10, 12, 20};
	int freq[] = {34, 8, 50};

	int n = sizeof(keys)/sizeof(keys[0]);

	cout<<OptimalBinarySearchTree(keys,freq,n)<<endl;
	return 0;
}