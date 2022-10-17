#include <iostream>

#include <vector>
#include <fstream>

using namespace std;

typedef double TYPE;
TYPE const stop_time = 50;
TYPE const dt = 0.01;
TYPE const angular_velocity = 1;


void method_heun(vector<TYPE> &coordinates, ofstream &out)
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

void method_euler(vector<TYPE> &coordinates, ofstream &out) 
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

void method_runge_kutte(vector<TYPE> &coordinates, ofstream &out) 
{
    while(stop_time > coordinates[0] )
    {
    	double k1;
    	double k2;
    	double k3;
    	double k4;
        coordinates[0] += dt;
        k1 = coordinates[2];
        k2 = k1 + k1 * dt/2 - dt/2 * angular_velocity * coordinates[1] * angular_velocity ;
        k3 = k2 + k2 * dt/2 - dt/2 * angular_velocity * coordinates[1] * angular_velocity ;
        k4 = k3 + k3 * dt - dt * angular_velocity * coordinates[1] * angular_velocity;
        
        
        coordinates[1] += dt * coordinates[2];
        coordinates[2] += 1/6 * dt * (k1 + 2 * k2 + 2 * k3 + k4);
        
        for (int i = 0 ; i < 3; ++i){
        	out << coordinates[i] << " ";
    	}
    	out << endl;
    }
}

int main() 
{
    vector<TYPE> coordinates(3);
    coordinates[0] = 0; ///start_time
    coordinates[1] = 1; ///start_x
    coordinates[2] = 0; ///start_velocity
	
	ofstream out;
    out.open("4.txt");
	 
    for (int i = 0 ; i < 3; ++i ){
        out << coordinates[i] << " ";
	}
    out << endl;
    
    
	///method_euler(coordinates, out);
	///method_heun(coordinates, out);
	method_runge_kutte(coordinates, out);
    return 0;
}