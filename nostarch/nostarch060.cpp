#include <cstdio>
#include <cstdint>

struct PodStruct {
    uint64_t a;
    char b[256];
    bool c;
};

int main() {
    // initialize core type
    int a = 0;
    int b {};
    int c {0};
    int d = {};
    int e = {0};
    int f(0); // will work
    int g;  // this is not save

    // initialize POD
    //PodStruct ipod0 = 0;  // will not compile
    PodStruct ipod1 = {};  // all ommited members are zeroed
    PodStruct ipod2 {};
    PodStruct ipod3 {42, "hello"};
    PodStruct ipod4 {42, "hello", true};
    //PodStruct ipod5 (42, "hello", true); // will not compile
    //PodStruct ipod5 {42, true}; // will compile but is a bug! true is 1 and is interpreated as a ascii char which is SOH
    //printf("ipod.b:%s!\n", ipod5.b);
}

