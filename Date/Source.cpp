#include<iostream>
#include<Windows.h>
using namespace std;

class Date
{
	unsigned int Day;
	unsigned int Month;
	unsigned int Year;
public:
	Date()
	{
		SYSTEMTIME st;
		GetSystemTime(&st);
		Day = st.wDay;
		Month = st.wMonth;
		Year = st.wYear;
	}
	Date(unsigned int day, unsigned int month, unsigned int year)
	{
		SetMonth(month);
		SetYear(year);
		SetDay(day);
	}

	bool YearTest(unsigned int year)
	{
		if (year % 4 == 0 || year % 100 == 0 && year % 400 == 0)
		{
			return false;
		}
		return true;
	}

public:
	
	void SetMonth(unsigned int month)
	{
		if (month >= 1 && month <= 12)
		{
			Month = month;
		}
		else
		{
			Month = 1;
		}
		
	}
	void SetYear(unsigned int year)
	{
		if (year >= 1)
		{
			Year = year;
		}
		else
		{
			Year = 2022;
		}
	}

	bool MonthTest(unsigned int month)
	{
		if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12)
		{
			return true;
		}
		else if (Month == 4 || Month == 6 || Month == 9 || Month == 11)
		{
			return false;
		}
	}

	void SetDay(unsigned int day)
	{
		if (MonthTest(Month))
		{
			if (day >= 1 && day <= 31)
			{
				Day = day;
			}
			else
			{
				Day = 1;
			}
		}
		else if (MonthTest(Month) == false)
		{
			if (day >= 1 && day <= 30)
			{
				Day = day;
			}
			else
			{
				Day = 1;
			}
		}
		else if (Month == 2)
		{
			if (YearTest(Year))
			{
				if (day >= 1 && day <= 28)
				{
					Day = day;
				}
				else if (day == 29)
				{
					Day = 28;
				}
				else
				{
					Day = 1;
				}
			}
			else
			{
				if (day >= 1 && day <= 29)
				{
					Day = day;
				}
				else
				{
					Day = 1;
				}
			}
		}
	}

	unsigned int GetDay() const
	{
		return Day;
	}
	unsigned int GetMonth() const
	{
		return Month;
	}
	unsigned int GetYear() const
	{
		return Year;
	}

	void Print()
	{
		cout << GetDay() << ".";
		cout << GetMonth() << ".";
		cout << GetYear() << "\n";
	}

	friend Date operator - (const Date& left, const Date& right);
	friend Date operator + (const Date& OneDate, int days);
	friend istream& operator >> (istream& is, Date& original);
	friend ostream& operator << (ostream& os, const Date& original);
};

Date operator - (const Date& OneDate, const Date& SecondDate)
{
	Date difference;
	int SumDifference = 0;
	difference.Year = OneDate.Year - SecondDate.Year;
	difference.Month = OneDate.Month - SecondDate.Month;
	difference.Day = OneDate.Day - SecondDate.Day;
	
	SumDifference = (difference.Year * 365) + (difference.Month * 30) + difference.Day;
	if (SumDifference < 0)
	{
		SumDifference *= -1;
	}
	difference.Day = SumDifference;
	difference.Month = 0;
	difference.Year = 0;
	return difference;
}

Date operator + (const Date& OneDate, int days)
{
	Date result;
	int Mon;
	result.Day = OneDate.Day + days;
	result.Month = OneDate.Month;
	result.Year = OneDate.Year;
	for (int i = 0; i < days; i++)
	{
		if (result.MonthTest(result.Month) && result.Day >= 31)
		{
			result.Day -= 31;
			if (result.Month != 12 && result.Month >= 1)
			{
				result.Month++;
			}
			else
			{
				result.Month = 1;
				result.Year++;
			}
			
			if (result.Day >= 1 && result.Day <= 31)
			{
				break;
			}
		}
		else
		{
			result.Day -= 30;
			if (result.Month != 12 && result.Month >= 1)
			{
				result.Month++;
			}
			else
			{
				result.Month = 1;
				result.Year++;
			}

			if (result.Day >= 1 && result.Day <= 31)
			{
				break;
			}
		}
	}
	
	return result;
}

bool operator > (const Date& One, const Date& Two)
{
	return One.GetDay() + (One.GetMonth() * 31) + (One.GetYear() * 365) > Two.GetDay() + (Two.GetMonth() * 31) + (Two.GetYear() * 365);
}

bool operator < (const Date& One, const Date& Two)
{
	return One.GetDay() + (One.GetMonth() * 31) + (One.GetYear() * 365) > Two.GetDay() + (Two.GetMonth() * 31) + (Two.GetYear() * 365);
}

bool operator == (const Date& One, const Date& Two)
{
	return One.GetDay() + (One.GetMonth() * 31) + (One.GetYear() * 365) == Two.GetDay() + (Two.GetMonth() * 31) + (Two.GetYear() * 365);
}

bool operator != (const Date& One, const Date& Two)
{
	return One.GetDay() + (One.GetMonth() * 31) + (One.GetYear() * 365) != Two.GetDay() + (Two.GetMonth() * 31) + (Two.GetYear() * 365);
}

istream& operator >> (istream& is, Date& original)
{
	int a;

	cout << "Please enter days:";
	is >> a;
	original.SetDay(a);
	cout << "Please enter months:";
	is >> a;
	original.SetMonth(a);
	cout << "Please enter years:";
	is >> a;
	original.SetYear(a);
	return is;
}

ostream& operator << (ostream& os, const Date& original)
{
	os << original.Day << "." << original.Month << "." << original.Year << "\n";
	return os;
}

int main()
{
	Date a(7, 12, 2003);
	Date difference = a + 726;
	difference.Print();
	cin >> a;
	cout << a;
}