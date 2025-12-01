int sumsq(int n) {
    int total = 0;
    for (int i = 1; i <= n; i++) {
        total += i * i;
    }
    return total;
}
