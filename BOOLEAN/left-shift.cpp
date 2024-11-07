// C++ program to get the shifted values using pow()
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    cout << "2^5 using pow() function" << pow(2, 5) << endl;

    cout << "2^5 using leftshift" << (1 << 5) << endl;

    return 0;
}


