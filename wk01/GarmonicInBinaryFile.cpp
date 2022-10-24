#include <fstream>
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
	
	const char* FName = "D:\\1\\1.txt";
	
	auto garmonic = GarmonicVector(1);
	
	for (int i = 0 ; i < n ; ++i){
    	Vector.push_back(garmonic.next());
	}
	
	for (auto& elem : Vector ){
		ofstream out(FName, ios::binary);
			out.write((char*)&elem, sizeof(elem));
		out.close();		
	}
}