#include <stdexcept>
#include <cstdio>

struct Groucho {
    std::string name = "hallo";
    void forget(int x) {
        if (x == 0xFACE) {
            //throw std::runtime_error {"I'd be glad to make an exception."};
            throw std::runtime_error { "I'd be glad to " + name + " make an exception."};
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
    } 
    catch(const std::runtime_error& e) {
        printf("exception caught with message: %s\n", e.what());
    
    }
}
