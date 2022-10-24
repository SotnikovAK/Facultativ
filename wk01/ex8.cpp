#include <iostream>	
#include <fstream>

using namespace std;

int main(){
	ofstream fout("fibbonacci3.txt");
	
	int n;
	
	
	cin >> n;
	
	int array[n];
	int a = 0, b = 1;
	array[0] = a;
	for (int i = 0 ; i < n - 1 ; ++i){
		int t;
		
		array[i+1] = b;
		t = b;
		b = a + b;
		a = t;
	}
	array[n] = b;
	for (int i = 0 ; i < n + 1; ++i){
		fout << array[i] << " ";
	}
	fout.close();
}