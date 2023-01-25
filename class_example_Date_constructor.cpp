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

    Date()
    {
        std::cout << "기본 생성자 호출!" << std::endl;
        year_ = 2012;
        month_ = 7;
        day_ = 12;
    }

    Date(int year, int month, int day)
    {
        std::cout << "인자 3개인 생성자 호출!" << std::endl;
        year_ = year, month_ = month, day_ = day;
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
    month_ = (month_ == 12 ? 12 : month_ % 12); // (condition ? return 1 : return 2)
}

void Date::AddYear(int inc) { year_ += inc; }

void Date::ShowDate()
{
    std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
              << " 일 입니다 " << std::endl;
}

int main()
{
    Date day = Date();
    day.ShowDate();

    Date day2;
    day.ShowDate();

    Date day3(2012, 1, 31);
    day.ShowDate();

    return 0;
}