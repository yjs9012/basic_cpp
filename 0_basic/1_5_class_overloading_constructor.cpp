/******************************************************************************
 1. 함수 오버로딩 단계
    (a) 타입이 정확히 일치하는 함수를 찾는다
    (b) 형변환을 통해서 일치하는 함수를 찾아본다
        - char, unsigned char, short -> int
        - unsigned short는 int의 크기에 따라 int | unsigned int
        - float -> double
        - Enum -> int
    (c) 위와 같이 변환해도 일치하는 것이 없다면 포괄적으로 함수를 찾는다
        - 임의의 숫자 타입은 다른 숫자 타입으로 변환된다
        - Enum도 int가 아닌 다른 숫자 타입으로 변환된다
        - 0은 포인터 타입이나 숫자 타입으로 변환된다
        - 포인터는 void 포인터로 변환된다
2. 생성자(Constructor)와 디폴트 생성자(Default Constructor)

 ******************************************************************************/
#include <iostream>

class Date
{
    int year_;
    int month_; // 1 부터 12 까지.
    int day_;   // 1 부터 31 까지.

public:
    void SetDate(int year, int month, int date);
    void AddDay(int inc);
    void AddMonth(int inc);
    void AddYear(int inc);

    // 해당 월의 총 일 수를 구한다.
    int GetCurrentMonthTotalDays(int year, int month);

    void ShowDate();

    Date(int year, int month, int date) // 생성자(constructor)
    {
        year_ = year;
        month_ = month;
        day_ = date;
    }
    Date() // 디폴트 생성자(default constructor)
    {
        year_ = 2023;
        month_ = 2;
        day_ = 4;
    }
};

void Date::SetDate(int year, int month, int day)
{
    year_ = year;
    month_ = month;
    day_ = day;
}

int Date::GetCurrentMonthTotalDays(int year, int month)
{
    static int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month != 2)
    {
        return month_day[month - 1];
    }
    else if (year % 4 == 0 && year % 100 != 0)
    {
        return 29; // 윤년
    }
    else
    {
        return 28;
    }
}

void Date::AddDay(int inc)
{
    while (true)
    {
        // 현재 달의 총 일 수
        int current_month_total_days = GetCurrentMonthTotalDays(year_, month_);

        // 같은 달 안에 들어온다면;
        if (day_ + inc <= current_month_total_days)
        {
            day_ += inc;
            return;
        }
        else
        {
            // 다음달로 넘어가야 한다.
            inc -= (current_month_total_days - day_ + 1);
            day_ = 1;
            AddMonth(1);
        }
    }
}

void Date::AddMonth(int inc)
{
    AddYear((inc + month_ - 1) / 12);
    month_ = month_ + inc % 12;
    month_ = (month_ == 12 ? 12 : month_ % 12);
}

void Date::AddYear(int inc) { year_ += inc; }

void Date::ShowDate()
{
    std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
              << " 일 입니다 " << std::endl;
}

int main()
{
    // 생성자와 default 생성자 사용
    Date day(2012, 3, 1); // Constructor 작동
    day.ShowDate();
    Date day2; // Default Constructor 작동
    day2.ShowDate();
    Date day3 = Date(); // Default Constructor 작동
    day3.ShowDate();

    return 0;
}