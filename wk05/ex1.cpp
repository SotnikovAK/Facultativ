#include <iostream>

int main()
{
    float d = 0, r;

    std::string s = "";
    
    for (int i = 1; i < 24; ++i)
    {
        r = 1.;
        for (int j = 0; j < i; ++j) {
			r *= 2; 
		}
        d += 1 / r;
        
        std::cout.precision(6);
        
        std::cout << i << " " << d << " " <<  1 / r << std::endl;
    }

}