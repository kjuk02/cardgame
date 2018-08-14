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
// Mutator functions (������)
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
bool myDate::isLeapYear() const //����

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
int myDate::getNumHolidays() const //���ϼ� ���
{
	int red = 0, d = 0;

	for (int i = 1582; i<this->year; i++) //�����϶��� 366 �ƴҶ� 365�� �����ش�
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
int myDate::getNumSummerTimeDays()const //���Ÿ�� ��¥��
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
int myDate::monthday(int arrayA[])//�״��� ��ĥ���� Ȯ���ϰ� �׳�¥��ŭ �迭�� ����ֱ�
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
void myDate::printCalendarOfMonth() // �޷�����ϱ�
{
	int oneday = 0, row = 0, col = 0, count = 0;//oneday�� �ش� ���� ù��° ������ ������������ Ȯ��,row 7���� ���ڰ� ��µŸ� �����ٷ� �ѱ��
												//col ��~����� ���ڰ� ����µŴ��� ��ĭ�� �߻��ϸ� 0�� ��� ,count�� ����ؾ��� ���� �ѿ���
	int arrayA[31] = { 0, };//����ؾ��ϴ� ���� ��¥ ���� �迭
	count = monthday(arrayA);//����ؾ��ϴ� ���� �ѿ���
	myDate date3(year, month, 1);
	oneday = date3.getDayOfWeek();//����ؾ��ϴ� ���� ù��°���� Ȯ��

	cout << year << " " << month << endl;//����ϴ� �⵵�� ��
	for (int j = 0; j < count;)// ��¥ ���
	{
		if (oneday > 0)//ù��° ���� ���� �κ� 0���
		{
			cout << 0 << " ";
			row++;
			oneday--;
			col++;
		}
		else //��¥ ���
		{
			cout << arrayA[j] << " ";
			j++;
			row++;
			col++;
		}
		if (row % 7 == 0)//7���� ���ڰ� ��µŸ� ���� �ѱ��.
		{
			if(j!=count)
			cout << endl;
			row = 0;
		}
	}
	if (col % 7 != 0)
	{
		for (; col % 7 != 0; col++)//������ ��¥ �ڿ� ����ϱ��� �����ϰ�� 0���
			cout << 0 << " ";
	}
}