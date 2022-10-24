#include <iostream>
#include <sstream>
#include <array>
#include <vector>
#include <iterator>

using namespace std;

class GarmonicVector{
	
	public:
		GarmonicVector(int n) : i(n) {}
		
		double next(){
			
			++i ;
			return 1./(i - 1);
		}
		
	
	private:
		int i;
};


int main(){
	
	int n;
	
	cin >> n;
	vector<double> Vector;
	
	auto garmonic = GarmonicVector(1);
	
	for (int i = 0 ; i < n ; ++i){
    	Vector.push_back(garmonic.next());
	}
	
	for (auto& elem : Vector ){
		cout << int(elem * 1000) << " " << " * 10^(-3)" << endl;
		
	}
	
}