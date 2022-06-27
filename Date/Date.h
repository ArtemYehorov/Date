#include<iostream>
#include<Windows.h>

using namespace std;
#pragma once

class Date
{
	unsigned int Day;
	unsigned int Month;
	unsigned int Year;
public:
	Date();
	Date(unsigned int day, unsigned int month, unsigned int year);

	bool MonthTest(unsigned int month);
	bool YearTest(unsigned int year);

public:

	void SetMonth(unsigned int month);
	void SetYear(unsigned int year);
	void SetDay(unsigned int day);

	unsigned int GetDay() const;
	unsigned int GetMonth() const;
	unsigned int GetYear() const;

	void Print();

	int operator[](int index);

	Date& operator++();
	Date operator++(int);

	Date& operator--();
	Date operator--(int);

	friend Date operator - (const Date& OneDate, const Date& SecondDate);
	friend Date operator + (const Date& OneDate, int days);
	friend bool operator > (const Date& One, const Date& Two);
	friend bool operator < (const Date& One, const Date& Two);
	friend bool operator == (const Date& One, const Date& Two);
	friend bool operator != (const Date& One, const Date& Two);
	friend istream& operator >> (istream& is, Date& original);
	friend ostream& operator << (ostream& os, const Date& original);
};
