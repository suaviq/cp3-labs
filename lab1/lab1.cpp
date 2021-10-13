#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

template <class T>
class MyImage
{
private:
    T** M;   //image
    int x;   //number of rows
    int y;   //number of columns

public:

    MyImage(int _x, int _y)
    {
        x = _x;
        y = _y;

        M = (T**) new T * [x];

        //allocate memory for each pointer
        for (int i = 0; i < x; i++)
            M[i] = (T*)new T[y];

        for (int i = 0; i < x; i++)
            for (int j = 0; j < y; j++) {
                M[i][j] = rand();
            }
    }
    ~MyImage()
    {
        if (y > 0)
        {
            for (int i = 0; i < x; i++)
                delete[] M[i];
        }

        if (x > 0)
            delete[] M;
    }


    T pixel(int i, int j)
    {
        if ((x > 0) && (y > 0))
            return M[i][j];
        else
            return 0;
    };
};

int main()
{
    MyImage<double> a(100, 100);
    MyImage<float> b(100, 100);

    cout << a.pixel(5, 10) << "\n" << b.pixel(5, 10) << "\n";

    return 0;
}
