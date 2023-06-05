#include <cstdio>

struct RathThing {
    static int rat_things_power;
    static void power_up_rat_thing(int nuclear_isotopes) {
        rat_things_power = rat_things_power + nuclear_isotopes;
        const auto waste_heat = rat_things_power * 20;
        if (waste_heat > 10000) {
            printf("Warning! Hot cat!\n");
        }
        printf("Rat-thing power: %d\n", rat_things_power);
    }
};

int RathThing::rat_things_power {200};

int main() {
    RathThing::power_up_rat_thing(100);
    RathThing::power_up_rat_thing(500);
}
