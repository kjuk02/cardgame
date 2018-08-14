#include"date.h"

int myDate::getDayOfMonth() const
{
	return day;
}
int myDate::getMonth() const
{
	return month;
}
int myDate::getYear() const
{
	return year;
}
// Mutator functions (변경자)
void myDate::setDayOfMonth(int day_)
{
	day = day_;
}
void myDate::setMonth(int month_)
{
	month = month_;
}
void myDate::setYear(int year_)
{
	year = year_;
}
void myDate::setDate(int year_, int month_, int day_)
{
	year = year_;
	month = month_;
	day = day_;
}
// utility functions 
bool myDate::isLeapYear() const //윤년

{
	if (((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0)
		return 1;
	else
		return 0;
}
int myDate::getDayOfWeek() const //0=Sunday, 1=Monday, ..., 6=Saturday
{
	int lastday = 0;
	for (int i = 1582; i<year; i++)
	{
		if (((i % 4 == 0) && (i % 100 != 0)) || i % 400 == 0)
			lastday += 366;
		else
			lastday += 365;
	}
	int oneday = 0;
	oneday = (lastday + getDayOfYear() + (day - 1) + 5) % 7;
	return oneday;
}
int myDate::getDayOfYear() const //1=Jan.1, 2=Jan.2, ..., 366=Dec.31 (in a leap year)
{
	int allday = 0;
	for (int m = 1; m < month; m++)
	{
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10)
			allday += 31;

		else if (m == 2)
		{
			if (isLeapYear())
				allday += 29;
			else
				allday += 28;
		}
		else
			allday += 30;
	}
	return allday;
}
int myDate::getNumHolidays() const //휴일수 계산
{
	int red = 0, d = 0;

	for (int i = 1582; i<this->year; i++) //윤년일때는 366 아닐땐 365를 더해준다
	{
		if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
			d += 366;
		else
			d += 365;
	}
	d = (d + 5) % 7;
	if (isLeapYear())
	{
		for (int i = 0; i<366; i++)
		{
			if ((d + i) % 7 == 0 || (d + i) % 7 == 6)
				red++;
			else
				if ((i + 1) == 1 || (i + 1) == 32 || (i + 1) == 33 || (i + 1) == 34 || (i + 1) == 61 || (i + 1) == 126 || (i + 1) == 136 || (i + 1) == 158 || (i + 1) == 199 || (i + 1) == 228 || (i + 1) == 259 || (i + 1) == 260 || (i + 1) == 261 || (i + 1) == 277 || (i + 1) == 360)
					red++;
		}
	}
	else
	{
		for (int i = 0; i<365; i++)
		{
			if ((d + i) % 7 == 0 || (d + i) % 7 == 6)
				red++;
			else
				if ((i + 1) == 1 || (i + 1) == 32 || (i + 1) == 33 || (i + 1) == 34 || (i + 1) == 60 || (i + 1) == 125 || (i + 1) == 135 || (i + 1) == 157 || (i + 1) == 198 || (i + 1) == 227 || (i + 1) == 258 || (i + 1) == 259 || (i + 1) == 260 || (i + 1) == 276 || (i + 1) == 359)
					red++;
		}
	}
	return red;
}
int myDate::getNumSummerTimeDays()const //써머타임 날짜수
{
	int num = 214;
	myDate m3(year, 3, 31);
	myDate m10(year, 10, 31);

	int month_3 = m3.getDayOfWeek();
	int month_10 = m10.getDayOfWeek();

	for(;;)
	{
		if (month_3 == 0)
			break;
		--month_3;
		++num;
	}

	for (;;)
	{
		if (month_10 == 0)
			break;
		--month_10;
		--num;
	}
	return num;
}
int myDate::monthday(int arrayA[])//그달이 며칠인지 확인하고 그날짜만큼 배열에 집어넣기
{
	int count = 0;
	int arrayM[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && isLeapYear())
	{
		for (int i = 0; i < arrayM[month - 1] + 1; i++)
		{
			arrayA[i] = i + 1;
			count++;
		}
	}
	else
	{
		for (int i = 0; i < arrayM[month - 1]; i++)
		{
			arrayA[i] = i + 1;
			count++;
		}
	}

	return count;
}
void myDate::printCalendarOfMonth() // 달력출력하기
{
	int oneday = 0, row = 0, col = 0, count = 0;//oneday는 해당 달의 첫번째 요일이 무슨요일인지 확인,row 7개의 숫자가 출력돼면 다음줄로 넘기기
												//col 일~토까지 숫자가 다출력돼는지 빈칸이 발생하면 0을 출력 ,count는 출력해야할 달의 총요일
	int arrayA[31] = { 0, };//출력해야하는 달의 날짜 넣은 배열
	count = monthday(arrayA);//출력해야하는 달의 총요일
	myDate date3(year, month, 1);
	oneday = date3.getDayOfWeek();//출력해야하는 달의 첫번째요일 확인

	cout << year << " " << month << endl;//출력하는 년도와 달
	for (int j = 0; j < count;)// 날짜 출력
	{
		if (oneday > 0)//첫번째 요일 전인 부분 0출력
		{
			cout << 0 << " ";
			row++;
			oneday--;
			col++;
		}
		else //날짜 출력
		{
			cout << arrayA[j] << " ";
			j++;
			row++;
			col++;
		}
		if (row % 7 == 0)//7개의 문자가 출력돼면 줄을 넘긴다.
		{
			if(j!=count)
			cout << endl;
			row = 0;
		}
	}
	if (col % 7 != 0)
	{
		for (; col % 7 != 0; col++)//마지막 날짜 뒤에 토요일까지 공백일경우 0출력
			cout << 0 << " ";
	}
}