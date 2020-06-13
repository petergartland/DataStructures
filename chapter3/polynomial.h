#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include "linkedlistNode.h"
#include "linkedlistItr.h"
#include "linkedlistList.h"


class Polynomial;

class Literal
{
public:
	bool operator==(const Literal & rhs) const
	{ return coefficient == rhs.coefficient && exponent == rhs.exponent; }
	
	bool operator!=(const Literal & rhs) const
	{ return coefficient != rhs.coefficient || exponent != rhs.exponent; }
	
	void print(std::ostream & out) const
	{ out << "coef: " << coefficient << " exp: " << exponent;}
private:
	int coefficient;
	int exponent;
	friend class Polynomial;
};

std::ostream & operator<< (std::ostream & out, const Literal & rhs)
{
	rhs.print(out);
	return out;
}

//template<class Object>
//class List;

class Polynomial
{
public:
	Polynomial();
	void insertTerm( int coef, int exp);
	void zeroPolynomial();
	Polynomial operator+(const Polynomial & rhs) const;
	Polynomial operator*(const Polynomial & rhs) const;
	void printTerms() const;
private:
	List<Literal> terms;
};



void Polynomial::zeroPolynomial()
{
	terms.makeEmpty();
	Literal lit;
	lit.coefficient = 0;
	lit.exponent = 0;
	terms.insert(lit, terms.zeroth());
}

Polynomial::Polynomial()
{
	zeroPolynomial();
}

void Polynomial::printTerms() const
{
	printList(terms);
}

void Polynomial::insertTerm(int coeff, int exp)
{
	Literal node;
	node.coefficient = coeff;
	node.exponent = exp;
	ListItr<Literal> itr = terms.first();
	Literal prev;
	prev = itr.retrieve();

	while (itr.retrieve().exponent > exp && !itr.isPastEnd())
	{
		itr.advance();
		prev = itr.retrieve();
	}

	if(itr.retrieve().exponent == exp)
	{
		//std::cout<<"here"<<std::endl;
		Literal temp1 = itr.retrieve();
		Literal temp2 = itr.retrieve();
		temp1.coefficient = temp1.coefficient + coeff;
		terms.insert(temp1, itr);
		terms.remove(temp2);
	}

	else
		terms.insert(node, terms.findPrevious(prev));

}

Polynomial Polynomial::operator+(const Polynomial & rhs) const
{
	Polynomial ret;
	ret.terms = terms;
	ListItr<Literal> itr = rhs.terms.first();
	ListItr<Literal> itr2 = ret.terms.first();
	while(!itr.isPastEnd())
	{
		ret.insertTerm(itr.retrieve().coefficient, itr.retrieve().exponent);
		itr.advance();
	}
	
	return ret;
}


Polynomial Polynomial::operator*(const Polynomial & rhs) const
{
	Polynomial ret;
	ListItr<Literal> itr = rhs.terms.first();

	while (!itr.isPastEnd())
	{
		ListItr<Literal> itr2 = terms.first();
		Literal element = itr.retrieve();
		Literal toBeAdded;
		while(!itr2.isPastEnd())
		{
			ret.insertTerm(element.coefficient * itr2.retrieve().coefficient, element.exponent + itr2.retrieve().exponent);
			itr2.advance();
		}
		itr.advance();
		
	}
	return ret;
}

#endif

