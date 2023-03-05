#include <cstdio>

struct JohanVanDerSmut {
    bool gold = true;
    int year_of_smelting_accident = {1970};
    char key_location[9] {"x-rated"};
};

int main() {
    JohanVanDerSmut jvds;
    printf("johan van der smurf: *%d*\n", jvds.gold);
    printf("johan van der smurf: *%d*\n", jvds.year_of_smelting_accident);
    printf("johan van der smurf: *%s*\n", jvds.key_location);
}
