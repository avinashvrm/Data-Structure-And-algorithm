#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
#define ll long long
#define vi vector<int> 
#define pb push_back
 
void s_g_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
// Implementation of a Binary Indexed Tree (Fennwick Tree)
class BIT {
private:
	vector<int> fen;
public:
	BIT(vector<int> &arr) 
	{
		// Initialize BIT with arr in O(n)
		fen.resize(arr.size() + 1, 0);
		for (int idx = 0; idx < arr.size(); idx++) 
		{
			fen[idx + 1] = arr[idx];
		}

		for (int idx = 1; idx < fen.size(); idx++) 
		{
			int idx2 = idx + (idx & -idx);
			if (idx2 < fen.size()) 
			{
				fen[idx2] += fen[idx];
			}
		}
		for (int idx = 1; idx < fen.size(); idx++) 
		{
			cout<<fen[idx]<<"  ";
		}
		cout<<endl<<endl;
	}

	int prefix_query(int idx) const 
	{
		// Computes prefix sum of up to fenthe element at index idx
		int result = 0;
		++idx; 
		for (;idx > 0; idx -= idx & -idx) 
		{
			result += fen[idx];
		}
		return result;
	}

	int range_query(int from_idx, int to_idx) const 
	{
		// Computes the range sum between two indices (both inclusive)
        if (from_idx == 0)
            return prefix_query(to_idx);
        else
            return prefix_query(to_idx) - prefix_query(from_idx - 1);
	}

	void update(int idx, int add) 
	{
		// Add a value to the element at index idx
		++idx; 
		for (;idx < fen.size(); idx += idx & -idx) 
		{
			fen[idx] += add;
		}
	}
};
int main()
{
	s_g_c();

	vector<int> array{ 1, 7, 3, 0, 5, 8, 3, 2, 6, 2, 1, 1, 4, 5 };
  int length = array.size();
	BIT bit(array);
	int res1 = bit.range_query(0,4);
	cout<<res1<<endl;
	bit.update(0, 1);
	int res = bit.range_query(0,4);
	cout<<res;
	return 0;

}
