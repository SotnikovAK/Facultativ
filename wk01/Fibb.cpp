#include <iostream>
#include <sstream>
#include <array>
#include <algorithm>
#include <iterator>


using namespace std;
class FibSeq{
	public:
		FibSeq(int first, int second): first(first), second(second),third(0){}
	    int next(){
	        third = first + second;
	        first = second;
	        second = third;
	        return first;
	    }
	private:
	    int first, second, third;
};


int main(){
	
	array<long long, 10> array_1 = {};
	
    auto fibbo = FibSeq(0, 1);
    
    for (auto& elem : array_1){
    	elem =  fibbo.next();
    	
	}
	for (auto& elem : array_1){
		cout << elem << " ";
	} 

    return 0;
}