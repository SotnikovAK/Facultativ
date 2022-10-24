#include <iostream>
#include <sstream>
#include <array>
#include <algorithm>
#include <iterator>

using namespace std;

class GarmonicArray{
	
	public:
		GarmonicArray(int n) : i(n) {}
		
		double next(){
			
			++i ;
			return 1./(i - 1);
		}
		
	
	private:
		int i;
};

int main(){
	
	double S;
	array<double, 25> array_1 = {};
	
	auto garmonic = GarmonicArray(1);
	
	for (auto& elem : array_1){
    	elem =  garmonic.next();
    	S += elem;
    	
	}
	for (auto& elem : array_1){
		cout << int(elem * 1000) << " " << " * 10^(-3)" << endl;
	}
	cout << endl;
	cout << S;
	
	
	return 0;
}	
		