#include <iostream>
using namespace std;

bool isLeap(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short MonthDays(short year, short month)
{
	if(month==1 || month==3 || month==5 || month==7 || month==12 || month==10 || month==12)return 31;
	else if(month==2)return isLeap(year) ? 29 : 28;
	return 30;
}

short NumberOfDaysFrom1JanToCertainDay(short year, short month, short day)
{
	int n = 0;
	for(int i=1; i<month; i++)
	{
		n += MonthDays(year, i);
	}	
	n += day;
	return n;
}

void DateFromDayOrder(short year, short dayOrder)
{
	int m = 1, d = 0, i = 1;
	while (dayOrder >= MonthDays(year, 2))
	{
		m += 1;
		dayOrder -= MonthDays(year, i);
		i++;
	}
	d = dayOrder;
	cout<<"Date for["<<dayOrder<<"] "<<d<<"/"<<m<<"/"<<year<<endl;
}

short ReadYear()
{
	short x;
	do
	{
		cout<<"Enter Year: ";
		cin>>x;
	}while(x<=0);
	return x;
}

short ReadNumber()
{
	short x;
	do
	{
		cout<<"Enter Number: ";
		cin>>x;
	}while(x<=0 && x>366);
	return x;
}

short ReadDay()
{
	short x;
	do
	{
		cout<<"Enter Day: ";
		cin>>x;
	}while(x<=0 && x>31);
	return x;
}

int main()
{
	int y = ReadYear();
	int n = ReadNumber();
	DateFromDayOrder(y, n);
}
