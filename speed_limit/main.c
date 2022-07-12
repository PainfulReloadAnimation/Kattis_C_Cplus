#include <stdio.h>
#include <string.h>

int loop(int *miles) {
    char set[10];
    char * token;
    int s, t;
    int tempval, tempmiles;
    tempmiles = *miles;
    do {
        fgets(set, 10, stdin);
        token = strtok (set," ,.-");
        sscanf(token, "%d", &s);
        token = strtok (NULL, " ,.-");
        sscanf(token, "%d", &t);
    } while (s < 1 || s > 90 || t < 1 || t > 12 || *miles > t);
    *miles = t;
    t = t-tempmiles;
    tempval = s*t;
    return tempval;
}

int main() {
    char dataset[10];
    int n, val;
    int miles;
    do {
        fgets(dataset, 10, stdin);
        dataset[strcspn(dataset, "\n")] = 0;
        sscanf(dataset, "%d", &n);
        if (0 < n && n < 11) {
            val = 0;
            miles = 0;
            for (int i = 0; i < n; i++) {
                val += loop(&miles);
            }
            printf("%d miles\n", val);
        }

    } while (n != -1);
    return 0;
}
