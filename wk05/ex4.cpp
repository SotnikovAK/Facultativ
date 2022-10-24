#include <iostream>
#include <float.h>
#include <cmath>

using namespace std;

float euler_in_square(float x)
{
    return exp(- x * x);
}

void _function(float x, long long int N)
{
    float coord1 = 1, coord2 = 0;
	float Integral = 0, h = x / static_cast<float>(N);
	float square;
	
    bool flag = true;
    string s = " ";

    for (long long int i = 1; i <= N && flag; ++i)
    {
    	
        coord2 = euler_in_square(i * h);
        square = 0.5 * h * ( coord1 + coord2 );
        
        Integral += square;
        
        if (square <= FLT_MIN)
        {
            flag = false;
        }
        coord1 = coord2;
        
    }
    cout << scientific << s << "x = " << x << s << " integral is " <<  Integral << endl;
}

int main()
{
    _function(100, 100);
}