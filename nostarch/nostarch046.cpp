#include <cstdio>

int main() {
    char house[] = "a house of gold.";
    char16_t chinese[] = u"\u4e66\u4e2d\u81ea\u6709\u9ec4\u91d1\u5c4b";
    printf("A book holds %s\n", house);
    printf("chinese letters: %hn\n", chinese);
}
