#include <iostream>	
#include <fstream>

using namespace std;

int main(){
	
	ofstream fout("garmonic.txt");
	
	int n;
	cin >> n;
	
	float array[n];
	float Sum;
	
	for (float i = 1 ; i < n + 1 ; ++i){
		Sum += 1 / i;
		fout << 1/i << endl;
		array[i - 1] = (1/i);  
	}
	for (int i = 0 ; i < n; ++i){
		fout << array[i] << " ";
	}
	fout << endl;
	fout << "Summa " << Sum;
	fout.close();
}