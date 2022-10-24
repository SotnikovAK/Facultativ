#include <iostream>
#include <float.h>
#include <cmath>

using namespace std;

float _pow(long long int N)
{
    float pw = 1;
    
    for (long long i = 2; i <= N; ++i)
    {
        pw *= static_cast<float>(i);
    }
    
    return pw;
}

void sin_macloren_device(float x, long long int N)
{
    float d = 0, a;
    
    bool flag = true;
    string s = " ";
    
    for (long long int i = 0; i <= N && flag ; ++i)
    {
    	if (i % 2 == 0){
        	d += pow(x, 2 * i + 1) / _pow(2 * i + 1);
    	}
    	else{
    		d -= pow(x, 2 * i + 1) / _pow(2 * i + 1);
		}
        
        if ( pow(x, 2 * i + 1) / _pow(2 * i + 1 <= FLT_MIN))
        {
            flag = false;
        }
    }
    if (N == 1e7)
	{
		s = " ";
	}
    cout << s << "x = " << x << s << " macloren - " <<  d << endl;
}

int main()
{
    for (int i = -9; i <= 9; ++i)
    {
        sin_macloren_device( 3.14 * static_cast<float>(i) , 17);
    }
}