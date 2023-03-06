#include <cstdio>


struct ClockOfTheLongNow {
    ClockOfTheLongNow() {year = 2023;} // constructor I

    ClockOfTheLongNow(int year_in) {
        if (!set_year(year_in)) {
            year = 2222;
        }
    } // constructor II

    //void add_year() {
    //    year++;
    //}

    bool set_year(int new_year) {
        if (new_year < 2019) {
            printf("struct it is not possible to set a year < 2019.\n");
            return false;
        }
        this->year = new_year;
        printf("struct set year to: %d\n", year);
        return true;
    }

    int get_year() const {
        return year;
    }
    private:
        int year;
};

//void add_year(ClockOfTheLongNow* clock) {
    //(*clock).set_year((*clock).get_year() + 1);
    //clock->set_year(clock->get_year() + 1);
//}

void add_year(ClockOfTheLongNow& clock) {
    clock.set_year(clock.get_year() + 1);
}

bool is_leap_year(const ClockOfTheLongNow& clock) {
    if (clock.get_year() % 4 > 0) return false;
    if (clock.get_year() % 100 > 0) return true;
    if (clock.get_year() % 400 > 0) return false;
    return true;
}


struct Avout {
    Avout(const char* name, int year_of_apert)
    : name {name} , apert {year_of_apert} // initializer list
    {}  // pass constructor

    void announce() const {
        printf("My name is %s and my next apert is %d.\n", name, apert.get_year());
    }

    const char* name;
    ClockOfTheLongNow apert;
};

//void does_not_compile(const Avout& avout) {
//    avout.apert.add_year(); // does not compile because avout is const
//}


int main() {
    ClockOfTheLongNow clock;

    // 2017
    printf("\n2017:\n");
    clock.set_year(2017);
    printf("year: %d\n", clock.get_year());
    printf("leap year: %d\n", is_leap_year(clock));
    add_year(clock);
    //add_year(&clock);
    printf("year: %d\n", clock.get_year());
    printf("leap year: %d\n", is_leap_year(clock));

    // 2020
    printf("\n2020:\n");
    clock.set_year(2020);
    printf("year: %d\n", clock.get_year());
    printf("leap year: %d\n", is_leap_year(clock));
    add_year(clock);
    //add_year(&clock);
    printf("year: %d\n", clock.get_year());
    printf("leap year: %d\n", is_leap_year(clock));

    printf("\navout:\n");
    Avout raz {"Erasmas", 3010};
    Avout jad {"Jad", 4000};
    raz.announce();
    jad.announce();
}

