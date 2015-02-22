#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

namespace {
	double x;
	double y;
	double z;
	double theta;
	double h;
	double phi;
	double r;
}
class convert
{
	public :
		void Cartesian_to_Polar(double  &x, double &y,  double &z, double  &r, double  &theta, double  &phi)
		{
			r = (double) sqrt(x*x + y*y + z*z);
			theta = acos(z/r);
			phi = atan(y/x);
		}

	void Polar_to_Cartesian(double &r,  double &theta,  double &phi, double  &x, double  &y, double  &z)
	
	{
		x = r*sin(theta)*cos(phi);
		y = r*sin(theta)*sin(phi);
		z = r*cos(theta);
	}

	void Cartesian_to_Cylindrical(double &x,  double &y,  double &z, double  &r, double  &theta, double  &h)
	{
		r = (double) sqrt(x*x + y*y);
		h = z;
		theta = acos(z/r);
	}

	void Cylindrical_to_Cartesian(double &r, double  &theta, double  &h, double  &x, double  &y, double  &z)
	{
		h = z;
		x = r*cos(theta);
		y = r*sin(theta);
	}

	void Polar_to_Cylindrical(double &r0, double  &theta0, double  &phi0, double  &r, double  &theta, double  &h)
	{
		Polar_to_Cartesian(r0, theta0, phi0, x, y, z);
		Cartesian_to_Cylindrical(x, y, z, r, theta, h);
	}

	void Cylindrical_to_Polar(double &r, double  &theta, double  &h, double  &r0, double  &theta0, double  &phi0)
	{
		Cylindrical_to_Cartesian(r, theta, h, x, y, z);
		Cartesian_to_Polar(x, y, z, r0, theta0, phi0);
	}

	void printCartesian()
	{
		cout << "CARTESIAN" << endl;
		cout << "(" << x << ", " << y << ", " << z << ")" << endl;
	}

	void printCylindrical()
	{
		cout << "CYLINDRICAL" << endl;
		cout << "R = " << r << " THETA = " << theta << " H = " << h << endl;
	}

	void printPolar()
	{
		cout << "POLAR" << endl;
		cout << "R = " << r << " THETA = " << theta << " PHI = " << phi<< endl;
	}
};

int main()
{
	x = y = z = 1;
	convert c;
	c.Cartesian_to_Polar(x, y, z, r, theta, phi);
	c.printPolar();
	c.Polar_to_Cartesian(r, theta, phi, x, y, z);
	c.printCartesian();
	c.Cartesian_to_Cylindrical(x, y, z, r, theta, h);
	c.printCylindrical();
	c.Cylindrical_to_Cartesian(r, theta, h, x, y, z);
	c.printCartesian();
	return 0;
}

