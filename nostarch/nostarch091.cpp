#include <cstdio>

//extern int rat_things_power = 200;  // spits a warning out, not an error!
//static int rat_things_power = 200;
int rat_things_power = 200;

void power_up_rat_thing(int nuclear_isotopes) {  // automatic storage duration
    rat_things_power = rat_things_power + nuclear_isotopes;
    //int waste_heat = 0;  // automatic storage duration
    const auto waste_heat = rat_things_power * 20; // constant within the storage duration
    if (waste_heat > 10000) {
        printf("Warning! Hot cat!\n");
    }
}

int main() {
    printf("Rat-thing power: %d\n", rat_things_power);
    power_up_rat_thing(100);
    printf("Rat-thing power: %d\n", rat_things_power);
    power_up_rat_thing(500);
    printf("Rat-thing power: %d\n", rat_things_power);
}
