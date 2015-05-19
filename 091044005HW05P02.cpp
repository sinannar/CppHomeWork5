#include "091044005HW05P03.h"
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;



/********************************************/
/*constructors*/
Polinomial::Polinomial()//no parameters constructor
{
    degree=0;
    coefficients.push_back(0);
    calculateMostPower(degree);
}

Polinomial::Polinomial(vector<int>coef)//vector parameter constructor
{
   degree=coef.size();
   for(int i=0;i<=degree;++i)
   coefficients.push_back(coef[i]);
   calculateMostPower(degree);
}

Polinomial::Polinomial(int power)//one integer parameter constructor
{
    degree=power;
    for(int i=0;i<power;++i)
    coefficients.push_back(0);
    coefficients.push_back(1);
    calculateMostPower(degree);
}

Polinomial::Polinomial(int power,int coef)//two integer parameter constructor
{
    degree=power;
    for(int i=0;i<power;++i)
    coefficients.push_back(0);
    coefficients.push_back(coef);
    calculateMostPower(degree);
}

/********************************************/
/*functions for adding*/
void Polinomial::addElement(int power)//adding elements function on Polinomial with one integer
{
    if(power>degree)
    {
        for(int i=degree+1;i<power;++i)
            coefficients.push_back(0);
        coefficients.push_back(1);
        degree=power;
    }
    else
    {
        coefficients[power]=1;
    }
    calculateMostPower(power);
}

void Polinomial::addElement(int power,int coef)//adding elements function on Polinomial with two integer
{
    if(power>degree)
    {
        for(int i=degree+1;i<power;++i)
            coefficients.push_back(0);
        coefficients.push_back(coef);
        degree=power;
    }
    else
    {
        coefficients[power]=coef;
    }
    calculateMostPower(power);
}

/********************************************/
/*functions for deleting*/
void Polinomial::deleteElement(int power)//deleting elements function on Polinomial with one integer
{
    if(power<degree)
    {
        for(int i=power;i<degree;++i)
            coefficients[degree+1]=0;
        degree=power;
    }
}

void Polinomial::deleteElement(int power,int coef)//deleting elements function on Polinomial with two integer
{
    if(power<degree)
    {
        for(int i=power;i<degree;++i)
            coefficients[degree+1]=0;
        degree=power;
    }
}

/********************************************/
/*function for checking is that quadratic*/
bool Polinomial::isThatQuadratic()const
{
    if(degree==2)
        return true;
    return false;
}

/********************************************/
/*function for evaluation*/
int Polinomial::evaluate(int& x)
{
    int sum(0);
    for(int i=0;i<degree+1;++i)
    {
        sum+=(coefficients[i] * pow(x,i));
    }
    return sum;
}

/********************************************/
/*operators overloaded below*/


const Polinomial operator +(const Polinomial& first,const Polinomial& second)
{
    Polinomial temp;
    if(first.degree>second.degree)
    {
        temp.degree=first.degree;
        for(int i=0;i<=second.degree;++i)
        temp.coefficients.push_back(first.coefficients[i]+second.coefficients[i]);
        for(int i2=second.degree+1;i2<=first.degree;++i2)
        temp.coefficients.push_back(first.coefficients[i2]);
    }
    else if(first.degree<second.degree)
    {
        temp.degree=second.degree;
        for(int i=0;i<=first.degree;++i)
        temp.coefficients.push_back(first.coefficients[i]+second.coefficients[i]);
        for(int i2=first.degree+1;i2<=second.degree;++i2)
        temp.coefficients.push_back(second.coefficients[i2]);

    }
    else if(first.degree==second.degree)
    {
        temp.degree=second.degree;
        for(int i=0;i<=first.degree;++i)
        temp.coefficients.push_back(first.coefficients[i]+second.coefficients[i]);
    }

    return temp;
}


const Polinomial operator -(const Polinomial& first,const Polinomial& second)
{
    Polinomial temp;
    if(first.degree>second.degree)
    {
        temp.degree=first.degree;
        for(int i=0;i<=second.degree;++i)
        temp.coefficients.push_back(first.coefficients[i]-second.coefficients[i]);
        for(int i2=second.degree+1;i2<=first.degree;++i2)
        temp.coefficients.push_back(first.coefficients[i2]);
    }
    else if(first.degree<second.degree)
    {
        temp.degree=second.degree;
        for(int i=0;i<=first.degree;++i)
        temp.coefficients.push_back(first.coefficients[i]-second.coefficients[i]);
        for(int i2=first.degree+1;i2<=second.degree;++i2)
        temp.coefficients.push_back((-1)*second.coefficients[i2]);

    }
    else if(first.degree==second.degree)
    {
        temp.degree=second.degree;
        for(int i=0;i<=first.degree;++i)
        temp.coefficients.push_back(first.coefficients[i]-second.coefficients[i]);
    }

    return temp;
}

const Polinomial operator *(const Polinomial& first ,const Polinomial& second)
{
    Polinomial temp;
    temp.degree=first.degree*second.degree;
    for(int i2=0;i2<=temp.degree;++i2)
    temp.coefficients.push_back(0);
    for(int i=0;i<=first.degree;++i)
    for(int j=0;j<=second.degree;++j)
    temp.coefficients[i+j] = temp.coefficients[i+j]+ (first.coefficients[i]*second.coefficients[j]);

    return temp;
}

/*broken*/
const Polinomial operator -(const Polinomial& makingNeg)
{
    Polinomial temp;

    temp.degree=makingNeg.degree;
    for(int i=0;i<=makingNeg.degree;++i)
	{
	    temp.coefficients.push_back( (-1)*makingNeg.coefficients[i] );
	}

    return temp;
}


int& Polinomial::operator [](int power)
{
    if(!(power>degree))
    return coefficients[power];
    else
    {
        for(int i=degree+1;i<=power;++i)
        coefficients.push_back(0);
        degree=power;
        return coefficients[power];
    }
}

/********************************************/
/*printing polinomial function*/
void Polinomial::printPolinomial()const
{
    cout<<"F(x)=";
    for(int i=0;i<degree+1;++i)
    {
	if(coefficients[i]!=0)
        cout<<coefficients[i]<<"x^"<<i<<"+";
    }
    cout<<endl;
}
/********************************************/
int Polinomial::calculateMostPower(int pow)
{
    if (pow>largestDegree)
    largestDegree=pow;
    return  largestDegree;
}
/********************************************/
int Polinomial::descartSignRule()
{
	int numOfPositiveRoots=0;
	for(int i=0;i<degree;++i)
	if( !((coefficients[i]==0) && (coefficients[i]==0)) )
	if(	( (coefficients[i]<0) && (coefficients[i]>0) ) ||
		( (coefficients[i]>0) && (coefficients[i]<0) ) )
		++numOfPositiveRoots;

	return numOfPositiveRoots;
}
/********************************************/
