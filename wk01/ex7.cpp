#include <iostream>	
#include <fstream>

using namespace std;

int main(){
	ofstream fout("fibbonacci2.txt");
	
	int n;
	
	cin >> n;
	
	int a = 0, b = 1;
	
	fout << a << " " << b << endl;
	
	for (int i = 0 ; i < n - 1 ; ++i){
		int t;
		
		t = b;
		b = a + b;
		a = t;
		
		fout << a << " " << b << endl;
		
		
		
	}
	
	fout.close();
}