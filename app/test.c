int main() {
    int s1 = 85;
    int s2 = 90;
    int s3 = 77;

    int max = s1;
    int student = 1;

    int i = 2;
    while (i <= 3) {
        if (i == 2 && s2 > max) {
            max = s2;
            student = 2;
        }
        if (i == 3 && s3 > max) {
            max = s3;
            student = 3;
        }
        i++;
    }

    return 0;
}
