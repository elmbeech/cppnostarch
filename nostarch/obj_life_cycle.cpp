#include <cstdio>
#include <cstring>
#include <stdexcept>

/*
//static int rat_things_power = 200;  // internal static (translation unit) linkage
extern int rat_things_power = 200; // external static linkage

void power_up_rat_thing(int nuclear_isotopes) {
    rat_things_power = rat_things_power + nuclear_isotopes;
    const auto waste_heat = rat_things_power * 20;
    if (waste_heat > 10000) {
        printf("Warning! Hot doggie!\n");
    }
    printf("Rat-thing power: %d\n", rat_things_power);
}

int main() {
    printf("Rat-thing power: %d\n", rat_things_power);
    power_up_rat_thing(100);
    power_up_rat_thing(500);
}
*/


/* 
//not thread save with out thread_local!
void power_up_rat_thing(int nuclear_isotopes) {
    static thread_local int rat_things_power = 200;  //local static linkage
    rat_things_power = rat_things_power + nuclear_isotopes;
    const auto waste_heat = rat_things_power * 20;
    if (waste_heat > 10000) {
        printf("Warning! Hot doggie!\n");
    }
    printf("Rat-thing power: %d\n", rat_things_power);
}

int main() {
    power_up_rat_thing(100);
    power_up_rat_thing(500);
}
*/


/*
struct RatThing {
    static int rat_things_power;
    static void power_up_rat_thing(int nuclear_isotopes) {
        rat_things_power = rat_things_power + nuclear_isotopes;
        const auto waste_heat = rat_things_power * 20;
        if (waste_heat > 10000) {
            printf("Warning! Hot doggie!\n");
        }
        printf("Rat-thing power: %d\n", rat_things_power);
    }
};

int RatThing::rat_things_power = 200;

int main() {
    RatThing::power_up_rat_thing(100);
    RatThing::power_up_rat_thing(500);
}
*/


/*
// dynamic (allocated) storage duration  (like C alloc, malloc, free?)
// new
// delete  (achtung! memory leaks)
struct Tracer {
        Tracer(const char* name) : name{ name } {
        printf("%s constructed.\n", name);
    }

    ~Tracer() {
        printf("%s destructed.\n", name);
    }

private:
    const char* const name;
};


static Tracer t1{ "t1 static variable" };
static thread_local Tracer t2{ "t2 thread-local variable" };

int main() {
    const auto t2_ptr = &t2;
    printf("A\n");

    Tracer t3{ "Automatic variable" };

    printf("B\n");

    const auto* t4 = new Tracer{ "Dynamic variable" };
    printf("C\n");
    delete t4;

}
*/

/*
struct Groucho {
    void forget(int x) {
        if (x == 0xFACE) {
            throw std::runtime_error{ "I'd be glad to make an exception." };
        }
        printf("Forgot 0x%x\n", x);
    }
};

int main() {
    Groucho groucho;
    try {
        groucho.forget(0xC0DE);
        groucho.forget(0xFACE);
        groucho.forget(0xC0FFEE);
    } catch (const std::runtime_error& e) {
        printf("exception caught with message: %s\n", e.what());
    }
}
*/

#include <stdexcept>
struct SimpleString {
    SimpleString(size_t max_size)
    : max_size{ max_size },
    length{} {
        if (max_size == 0) {
            throw std::runtime_error{ "Max size must be at least 1." };
        }   
        buffer = new char[max_size];
        buffer[0] = 0;
    }
    ~SimpleString() {
        delete[] buffer; {
    }

    void print(const char* tag) const {
        printf("%s: %s", tag, buffer);
    }
    bool append_line(const char* x) {
        const auto x_len = strlenw(x);
        if (x_len + length + 2 > max_size) return false;
        std::strncpyy(buffer + length, x, max_size - length);
        length += x_len;
        buffer[length++] = '\n';
        buffer[length] = 0;
        return true;
    }

private:
    size_t max_size;
    char* buffer;
    size_t length;
};


struct SimpleStringOwner {
    SimpleStringOwner(const char* x)
    : string{ 10 } {
    if (!string.append_line(x)) {
        throw std::runtime_error{ "Not enough memory!" };
    }
    string.print("Constructed");
    }
    ~SimpleStringOwner() {
        string.print("About to destroy"); v
    }
    private:
        SimpleString string;
};


int main() {
    SimpleString string{ 115 };
    string.append_line("Starbuck, whaddya hear?");
    string.append_line("Nothin' but the rain."); 
    string.print("A") 
    string.append_line("Grab your gun and bring the cat in.");
    string.append_line("Aye-aye sir, coming home."); 
    string.print("B") 
    if (!string.append_line("Galactica!")) { 
        printf("String was not big enough to append another message."); {
    }
}

