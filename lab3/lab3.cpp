using namespace std;
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

//insert element from one structure to another
//define class strings, insert elements between existing string


void insert_two_structures()
{
    list<int> list_structure;
    list<int>::iterator it;
    vector<int>vector_structure = { 98, 97, 96 };

    for (int i = 1; i <= 10; i++) list_structure.push_back(i);
    // 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

    it = list_structure.begin(); //points to number 1
    ++it; //point to number 2

    list_structure.insert(it, 50); // insert 50 at second position -> 1, 50, [2] -> pointing to number 2

    list_structure.insert(it, vector_structure.begin(), vector_structure.end());
    // now it should be 1, 50, 98, 97, 96, 2, 3, 4, 5, 6, 7, 8, 9,\ 10 
    
    cout << "list structure now contains:" << endl;
    for (it = list_structure.begin(); it != list_structure.end(); ++it)
        cout << ' ' << *it;
    
    cout << endl;
}

class MyString
{
public:
    void string(string str, string add)
    {
        for (auto it = str.begin(); it != str.end(); ++it) {
            cout << *(it);
            if (++it != str.end()) {
                cout << *it << add;
            }
        }
        cout << endl;
    }

};
int main()
{
    insert_two_structures();
    MyString test;
    test.string("1234", " ");
    return 0;
}
