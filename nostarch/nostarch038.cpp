#include <cstdio>

int main() {
    char x = 'M';
    wchar_t y = L'Z';
    char16_t a = u'\u0041';
    char32_t beer = U'\U0001F37A';  // does not work on my commandline.

    printf("Windows binaries start with %c%lc.\n", x, y);
    printf("%c %c, please!\n", a, beer);
}
