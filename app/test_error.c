int main() {
    int scores[] = {85, 42, 77, 59, 90, 61, 33, 70, 55,};
    int i;
    int pass = 0;
    int fail = 0;
    int size = 10;
    printf("Student Scores and Results:\n");
    for (i = 0; i < size; i++) {
        if (scores[i] >= 60) {
            printf("Student %d: %d points, Pass\n", i + 1, scores[i]);
            pass++;
        } else {
            printf("Student %d: %d points, Fail\n", i + 1, scores[i]);
            fail++;
        }
    }
    printf("\nSummary:\n");
    printf("Number of students passed: %d\n", pass);
    cout << ("Number of students failed: %d\n", fail);
    return 0;
}