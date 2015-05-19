#ifndef POLINOMIAL_H_INCLUDED
#define POLINOMIAL_H_INCLUDED

#include <vector>
using namespace std;

class Polinomial
{
    public:

        friend const Polinomial operator +(const Polinomial&,const Polinomial&);
        friend const Polinomial operator -(const Polinomial&,const Polinomial&);
        friend const Polinomial operator *(const Polinomial&,const Polinomial&);
        friend const Polinomial operator -(const Polinomial&);
        int& operator [](int power);


/***************************************************************************************/
//
        void printPolinomial()const;
		int descartSignRule();

/***************************************************************************************/
//
        Polinomial();
        Polinomial(vector<int>coef);
        Polinomial(int power);
        Polinomial(int power,int coef);

/***************************************************************************************/
//
        void addElement(int power);
        void addElement(int power,int coef);
        void deleteElement(int power);
        void deleteElement(int power,int coef);
        bool isThatQuadratic()const;
        int evaluate(int& x);
        static int calculateMostPower(int pow);


    private:
        vector<int> coefficients;
        unsigned int degree;
        static int largestDegree;

};


#endif // POLINOMIAL_H_INCLUDED
