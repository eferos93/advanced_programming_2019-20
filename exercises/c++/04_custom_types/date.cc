#include <iostream>

enum class months{january=1, february, march, april, may,
    june, july, august, september, october, november, december};

class Date 
{
    /**
     * suppose that every month has 30 days
     **/
    unsigned int _day, _year;
    months _month;
    public:
        Date(const unsigned int day, const unsigned int year, const months month) 
        {
            _day = day;
            _year = year;
            _month = month;
        }

        unsigned int day() const 
        {
            return _day;
        }

        unsigned int year() const
        {
            return _year;
        }

        months month() const
        {
            return _month;
        }

        void add_days(unsigned int n)
        {
            unsigned int new_day = (_day+n);
            unsigned int month = static_cast<int>(_month);
            unsigned int months_to_add = new_day/30;
            _day = new_day % 30;
            if(months_to_add != 0)
            {
                unsigned int new_month = month + months_to_add;
                unsigned int years_to_add = new_month/12;          
                _month = months(new_month%12);
                _year += years_to_add;
            }
        }
};

int main() {
    Date data{29, 2019, months::december};
    //std::cout << data.day() << "/" << data.month() << "/" << data.year();

}