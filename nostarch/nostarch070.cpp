#include <cstdio>

struct ClockOfTheLongNow {
    ClockOfTheLongNow() {year = 2023;}  // constructor
    void add_year() {
        year ++;
        printf("struc increment year to %d\n", year);
    }
    bool set_year(int new_year) {
        if (new_year < 2019) {
            printf("struc it is not possible to set a year < 2019.\n");
            return false;
        }
        year = new_year;
        printf("struc set year to: %d\n", year);
        return true;
    }
    int get_year() {
        return year;
    }
    private:
        int year;
};

int main() {
    ClockOfTheLongNow clock;
    // 2017
    clock.set_year(2017);
    printf("year: %d\n", clock.get_year());
    clock.add_year();
    printf("year: %d\n", clock.get_year());
    // 2020
    clock.set_year(2020);
    printf("year: %d\n", clock.get_year());
    clock.add_year();
    printf("year: %d\n", clock.get_year());
    // ->
    ClockOfTheLongNow* clock_ptr = &clock;
    clock_ptr->set_year(2023);
    printf("Address of clock: %p\n", clock_ptr);
    printf("Value of clock's year: %d\n", clock_ptr->get_year());
    printf("Value of clock's year: %d\n", (*clock_ptr).get_year());
}
