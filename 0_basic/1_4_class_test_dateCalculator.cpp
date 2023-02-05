#include <iostream>

class Date
{
private:
    int year_;
    int month_;
    int day_;

public:
    void SetDate(int year, int month, int date)
    {
        year_ = year;
        month_ = month;
        day_ = date;
    }
    void AddDay(int inc)
    {
        if (month_ % 2 == 1)
        {
            if (day_ + inc > 31)
            {
                month_ += 1;
                day_ = day_ + inc - 31;
            }
            else
                day_ = day_ + inc;
        }
        else if (month_ % 2 == 0 && month_ != 2)
        {
            if (month_ != 12)
            {
                if (day_ + inc > 30)
                {
                    month_ += 1;
                    day_ = day_ + inc - 30;
                }
                else
                    day_ = day_ + inc;
            }
            else
            {
                if (day_ + inc > 30)
                {
                    year_ += 1;
                    month_ = 1;
                    day_ = day_ + inc - 30;
                }
                else
                    day_ = day_ + inc;
            }
        }
        else
        {
            if (day_ + inc > 28)
            {
                month_ += 1;
                day_ = day_ + inc - 30;
            }
            else
                day_ = day_ + inc;
        }
    }
    void AddMonth(int inc)
    {
        if (month_ != 12)
            month_ = month_ + 1;
        else
        {
            year_ = year_ + 1;
            month_ = 1;
        }
    }
    void AddYear(int inc)
    {
        year_ = year_ + inc;
    }

    void ShowDate()
    {
        std::cout << year_ << "년 " << month_ << "월 " << day_ << "일 입니다." << std::endl;
    }
};

int main()
{
    Date date;
    date.SetDate(2022, 10, 20);
    date.ShowDate();
    date.AddDay(12);
    date.ShowDate();
    return 0;
}
