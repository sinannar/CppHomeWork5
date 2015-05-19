#include "091044005HW05P03.h"
#include <iostream>
#include <vector>
using namespace std;

int Polinomial::largestDegree=0;
int main()
{
	Polinomial pol1,pol2,pol3;
	vector<int>x1;
	vector<int>x2;

	for(int i=0;i<5;++i)
	{
		x1.push_back(i);
		x2.push_back(2*i);
	}

	Polinomial pol4(x1),pol5(x2),pol6(10,3),pol7(11,4);

		pol1.addElement(2,3);
		cout<<"pol1"<<endl;
		pol1.printPolinomial();

		cout<<"pol2"<<endl;
		pol2.printPolinomial();

		pol2.addElement(3,4);
		cout<<"pol1"<<endl;
		pol1.printPolinomial();

		cout<<"pol2"<<endl;
		pol2.printPolinomial();

		pol1.addElement(4,5);
		cout<<"pol1"<<endl;
		pol1.printPolinomial();

		cout<<"pol2"<<endl;
		pol2.printPolinomial();

		pol2.addElement(5,6);
		cout<<"pol1"<<endl;
		pol1.printPolinomial();

		cout<<"pol2"<<endl;
		pol2.printPolinomial();

		pol3=pol1+pol2;
		cout<<"pol1+pol2"<<endl;
		pol3.printPolinomial();

		pol3=pol1-pol2;
		cout<<"pol1-pol2"<<endl;
		pol3.printPolinomial();

		pol3=pol1*pol2;
		cout<<"pol1*pol2"<<endl;
		pol3.printPolinomial();
		pol3=-pol2;
		cout<<"-pol2"<<endl;
		pol3.printPolinomial();

		cout<<"adding "<<endl;
		pol3.addElement(5,12);
		pol3.printPolinomial();

		cout<<"P4 "<<endl;
		pol4.printPolinomial();

		cout<<"P5 "<<endl;
		pol5.printPolinomial();

		cout<<"P6 "<<endl;
		pol6.printPolinomial();

		cout<<"P7 "<<endl;
		pol7.printPolinomial();

		cout<<"-P7 "<<endl;
		pol7=-pol7;
		pol7.printPolinomial();

		cout<<"P8 "<<endl;
		Polinomial pol8;
		pol8=Polinomial(2);
		cout<<pol8.isThatQuadratic()<<endl;
		int x=2;
		cout<<"x=2 -> F(x)="<<pol8.evaluate(x)<<endl;
		cout<<"descartes sign rule "<<pol8.descartSignRule()<<endl;


    return 0;
}
