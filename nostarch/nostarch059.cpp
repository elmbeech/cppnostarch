#include <cstdio>

struct ClockOfTheLongNow {
    ClockOfTheLongNow(int year_input) { // constructor 
        if (! set_year(year_input)) {
            printf("struct year will be initialized with 2023.\n");
            year = 2023;
        }
    } 
    void add_year() {
        year ++;
        printf("struct increment year to %d\n", year);
    }
    bool set_year(int new_year) {
        if (new_year < 2019) {
            printf("struct it is not possible to set a year < 2019.\n");
            return false;
        }
        year = new_year;
        printf("struct set year to: %d\n", year);
        return true;
    }
    int get_year() {
        return year;
    }
    private:
        int year;
};

int main() {
    ClockOfTheLongNow clock1 {2017};
    printf("year: %d\n", clock1.get_year());
    ClockOfTheLongNow clock2 { 2020 };
    printf("year: %d\n", clock2.get_year());
}

