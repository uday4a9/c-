#include <iostream>
#include "CommisionEMployee.h"

using namespace std;

int main(int argc, char **argv)
{
	
	CommissionEmployee emp("Uday Kiran","Vadavalasa","8099303909",10000,.06);
	emp.print();
	cout<<"EMployee earnings : "<<emp.earnings()<<endl;
	emp.setGrossSales(20000);
	emp.setCommissionRate(0.8);
	emp.print();
	cout<<"EMployee earnings : "<<emp.earnings()<<endl;

	return 0;
}
