#include <iostream>	
#include <fstream>

using namespace std;

int main(){
	ofstream fout("fibbonacci.txt");
	
	int n;
	
	cin >> n;
	
	int a, b = 1;
	
	for (int i = 0 ; i < n - 1 ; ++i){
		int t;
		
		t = b;
		b = a + b;
		a = t;
		
		
		
	}
	
	fout << b;
	
	fout.close();
}