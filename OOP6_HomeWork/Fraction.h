#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
class Fraction
{
	int numerator;
	int denominator;
public:
	//Конструкторы
	Fraction(int n, int d) : numerator{ n }, denominator(d) {};
	Fraction() : Fraction(1, 1) {};
	//Наибольший общий делитель
	int NOD(int a, int b){
		a = abs(a);
		b = abs(b);
		while (a != b)
		{
			if (a > b)
				a -= b;
			else
				b -= a;
		}
		return a;
	} 
	//Перегруженный оператор
	Fraction operator+(Fraction& p) {
		if (denominator == p.denominator) 
			return Fraction(numerator + p.numerator, denominator);
		int tempN = numerator * p.denominator + p.numerator*denominator;
		int tempD = denominator * p.denominator;
		int nod = NOD(tempN, tempD);
		if (nod)
			return Fraction(tempN / nod, tempD / nod);
		return Fraction(tempN, tempD);
	}
	Fraction operator-(Fraction& p) {
		if (denominator == p.denominator)
			return Fraction(numerator - p.numerator, denominator);
		int tempN = numerator * p.denominator - p.numerator * denominator;
		int tempD = denominator * p.denominator;
		int nod = NOD(tempN, tempD);
		if (nod)
			return Fraction(tempN / nod, tempD / nod);
		return Fraction(tempN, tempD);
	}
	Fraction operator*(Fraction& p) {
		int tempN = numerator * p.numerator;
		int tempD = denominator * p.denominator;
		int nod = NOD(tempN, tempD);
		if (nod)
			return Fraction(tempN / nod, tempD / nod);
		return Fraction(tempN, tempD);
	}
	Fraction operator/(Fraction& p) {
		int tempN = numerator * p.denominator;
		int tempD = denominator * p.numerator;
		int nod = NOD(tempN, tempD);
		if (nod)
			return Fraction(tempN / nod, tempD / nod);
		return Fraction(tempN, tempD);
	}

	//Функции get и set
	int getNumerator() {
		return numerator;
	}
	int getDenominator() {
		return denominator;
	}
	void setNumerator(int n) {
		numerator = n;
	}
	void setDenominator(int d) {
		denominator = d;
	}
};

