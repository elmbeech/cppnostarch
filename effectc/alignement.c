struct S {
    int i;
    double d;
    char c; 
};

int main(void) {
    unsigned char bad_buff[sizeof(struct S)];
    _Alignas(struct S) unsigned char good_buff[sizeof(struct S)];

    struct S *ps_bad = (struct S *)bad_buff;
    struct S *ps_good = (struct S *)good_buff;

    return 0;
}
