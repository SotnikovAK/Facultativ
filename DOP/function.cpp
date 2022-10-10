#include <iostream>

#include <vector>
#include <fstream>

using namespace std;


double const stop_time = 50;
double const dt = 0.01;
double const angular_velocity = 1;

void method_heun(vector<double> &coordinates, ofstream &out)
{

    while(stop_time > coordinates[0])
    {
    	coordinates[0] += dt;
    	double x1, x2;
		double v1, v2;
		
        x1 = coordinates[1];
        v1 = coordinates[2];
        x2 = x1 + v1 * dt;
        v2 = v1 - (angular_velocity * angular_velocity * x1) * dt;
        
        coordinates[1] += 0.5 * (v1 + v2) * dt;
        coordinates[2] -= 0.5 * ((x1 + x2) * angular_velocity * angular_velocity) * dt;
        
        for (int i = 0 ; i < 3; ++i ){
        	out << coordinates[i] << " ";
    	}
    	out << endl;
    }
}

void method_euler(vector<double> &coordinates, ofstream &out) 
{
    while(stop_time > coordinates[0] )
    {
    	double tmp;
        tmp = coordinates[1];
        coordinates[0] += dt;
        coordinates[1] += dt * coordinates[2];
        coordinates[2] -= dt * angular_velocity * tmp * angular_velocity;
        
        
        for (int i = 0 ; i < 3; ++i){
        	out << coordinates[i] << " ";
    	}
    	out << endl;
    }
}



int main() 
{
    vector<double> coordinates(3);
    coordinates[0] = 0; ///start_time
    coordinates[1] = 1; ///start_x
    coordinates[2] = 0; ///start_velocity
	
	ofstream out;
    out.open("3.txt");
	 
    for (int i = 0 ; i < 3; ++i ){
        out << coordinates[i] << " ";
	}
    out << endl;
    
    
	method_euler(coordinates, out);
	///method_heun(coordinates, out);
    return 0;
}