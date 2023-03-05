int step_function(int x) {
    int result = 0;
    if (x < 0) result = -1;
    else if (x > 0) result = 1;
    else result = 0;
    return result;
}
