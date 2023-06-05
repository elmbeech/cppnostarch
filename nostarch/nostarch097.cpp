#include <cstdio>

struct Tracer {
    //Tracer(const char* name) : name {name} {  // bue 20230319: i don't get the syntax. what is the :.
    Tracer(const char* name) : ich {name} {  // bue 20230319: i don't get the syntax. what is the :.
        //printf("%s constructed.\n", name);
        printf("%s constructed.\n", ich);
    }
    ~Tracer() {  // bue 20230319: why name habe not to be secified here?
        //printf("%s deconstructed.\n", name);
        printf("%s deconstructed.\n", ich);
    }
private:   // to make the variale private is optional, even when used name?
    //const char* const name;
    const char* const ich;
};


static Tracer t1 {"static_variable"};
static thread_local Tracer t2 {"static_thread_local_variabel"};

int main() {
    //const auto ptr_t2 = &t2;
    //const auto ptr_t2 {&t2};
    const Tracer* ptr_t2 {&t2};   // have to be constructed in thread

    printf("A\n");

    Tracer t3 {"automatic_variable"};
    printf("B\n");

    //const auto* t4 = new Tracer {"dynamic variable"};
    //const auto* t4 {new Tracer {"dynamic variable"}};
    //const auto t4 {new Tracer {"dynamic variable"}};
    const Tracer* t4 {new Tracer {"dynamic variable"}};
    printf("C\n");
    delete t4;
}
