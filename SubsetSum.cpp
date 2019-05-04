#include <iostream>

using namespace std;
bool isSubsetSum(int set[], int sum, int n)
{
	if(n == 0 && sum > 0)
		return false;
	else if(sum == 0)
	{
		return true;
	}
	else 
	{
		bool ans;
		for(int i = 0; i < n; i++)
		{
			ans = isSubsetSum(set, sum, n - 1) | isSubsetSum(set, sum - set[i], n - 1);
		}

		return ans;
	}
}
int main()
{
	int set[] = {3, 34, 4, 12, 5, 2};
	int sum = 9;
	int n =sizeof(set)/sizeof(set[0]);

	cout<<isSubsetSum(set, sum, n)<<endl;

	return 0;
}