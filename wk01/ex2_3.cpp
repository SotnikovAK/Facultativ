#include <iostream>	
#include <fstream>

using namespace std;

int main(){
	ofstream fout("output.txt");
	
	for (int i = 1 ; i < 31 ; ++i){
		fout << i << " ";
		cout << i << " ";
	}
	
	fout.close();
}