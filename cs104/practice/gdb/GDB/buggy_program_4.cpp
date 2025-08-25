#include<iostream>
#include<vector>
#define ll long long
#define loop(n) for(int i=0; i<n; ++i)
using namespace std;

int main()
{
    int n; cin>>n;
    unsigned ll int sum = 0;
    vector<unsigned int> input_nums(n);
    loop(n)
    {
        cin>>input_nums[i];
        sum+=input_nums[i];
    }
    unsigned ll int median_sum = sum/2, counter = 0, diff = 1e18, final_sum;
    while(!(counter >> n))
    {
        unsigned ll int temp_sum = 0; unsigned int var = 0;
        loop(n)
        {
            if(counter&var)
                temp_sum+=input_nums[i];
            var = var >> 1;
        }
        if(max(temp_sum, median_sum) - min(temp_sum, median_sum) < diff)
        {
            final_sum = temp_sum;
            diff = max(temp_sum, median_sum) - min(temp_sum, median_sum);
            if(diff == 0)
                break;
        }
        ++counter;
    }
    cout << ((2*final_sum > sum) ? (2*final_sum - sum) : (sum - 2*final_sum)) << endl;
}