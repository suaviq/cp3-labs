#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


class task
{
public:
    vector <int> prime_numbers;
    int arr[100] = {};
    void prime(int n)
    {
        int arr[500] = { 0 };
        for (int i = 2; i < n; i++)
        {
            for (int j = i * i; j < n; j += i)
            {
                arr[j - 1] = 1;
            }
        }
        for (int i = 1; i < n; i++)
        {
            if (arr[i - 1] == 0)
                prime_numbers.push_back(i);
                
                
        }
        for (int i = 0; i < prime_numbers.size(); i++) {
            for (int& s : prime_numbers) {
                if (prime_numbers[i] == s) {
                    cout << s <<"\t";
                }
            }
        }

    }
};

int main() 
{
    vector<string> test_vec { "test1", "test2", "test3", "test4", "test5" };
    for_each(test_vec.begin(), test_vec.end(),
        [](const auto& car) { cout << car << ' '; });
    cout << '\n\n';
    task object;
    object.prime(200);
    return 0;
}
