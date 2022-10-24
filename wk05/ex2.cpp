#include <iostream>
#include <float.h>

int main()
{
    float d = 0;
    
    bool flag = true;
    
    std::string s = " ";
    
    for (int n = 10; n <= 1e8 && flag; n *= 10)
    {
        d = 0.;
        
        for (int i = 1; i <= n && flag; ++i)
        {
            d += 1. / static_cast<float>(i);
            
            if (1. / static_cast<float>(i) <= FLT_MIN)
            {
            	flag = false;
                std::cout<< i << " \n";
                
            }
        }
        if (n == 1e7) {
			s = " ";
		}
        std::cout << n << s << " - " <<  d << std::endl;
    }

}