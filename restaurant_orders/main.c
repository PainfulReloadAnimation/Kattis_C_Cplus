//
// Created by htk332 on 2022-06-14.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void costloop(char *endptr, char *token, long costlong[], char cost[], long itemlong) {

    fgets(cost, 10000, stdin);
    token = strtok (cost," ,.-");
    costlong[0] = strtol(token, &endptr, 0);
    if (costlong[0] > 1000) {
        exit(0);
    }
    for (int i = 1; i < itemlong; i++) {
        token = strtok (NULL," ,.-");
        costlong[i] = strtol(token, &endptr, 0);
        if (costlong[i] > 1000) {
            exit(0);
        }
    }
}

int itemloop(char *endptr, char *token, long costlong[]){

    char item[10000], cost[10000];
    long itemlong;
    fgets(item, 10000, stdin);
    itemlong = strtol(item, &endptr, 0);
    if(itemlong < 1 || itemlong > 100) {
        exit(0);
    }
    costloop(endptr, token, costlong, cost, itemlong);
    return itemlong;
}

void moneyloop(char *endptr, char *token,  long moneylong[], char money[], long orderlong){

    fgets(money, 10000, stdin);
    token = strtok (money," ,.-");
    moneylong[0] = strtol(token, &endptr, 0);
    if (moneylong[0] < 1 || moneylong[0] > 30000) {
        exit(0);
    }
    for (int i = 1; i < orderlong; i++) {
        token = strtok(NULL, " ,.-");
        moneylong[i] = strtol(token, &endptr, 0);
        if (moneylong[i] < 1 || moneylong[i] > 30000) {
            exit(0);
        }
    }
}

int orderloop(char *endptr, char *token, long moneylong[]) {

    char order[10000], money[10000];
    long orderlong;
    fgets(order, 10000, stdin);
    orderlong = strtol(order, &endptr, 0);
    if(orderlong < 1 || orderlong > 1000) {
        exit(0);
    }
    moneyloop(endptr, token, moneylong, money, orderlong);
    return orderlong;
}



int solution(const long costlong[], int money, int itemtot) {
    int i, j, x, y;
    int n = money;
    int m = itemtot;
    int count[money + 1];
    int from[money + 1];
    memset(count, 0, sizeof(count));
    memset(from, 0, sizeof(from));
    // We need n+1 rows as the table is constructed
    // in bottom up manner using the base case 0
    // value case (n = 0)
    int table[n+1][m];

    // Fill the entries for 0 value case (n = 0)
    for (i=0; i<m; i++)
        table[0][i] = 1;

    // Fill rest of the table entries in bottom
    // up manner
    count[0] = 1;
    for (i = 1; i < n+1; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (count[i-1] > 0){
                int p = i-1 + costlong[j];
                if (p <= money) {
                    if (count[p] == 0 || count[p] > count[i-1] + 1) {
                        count[p] = count[i-1] + 1;
                        from[p] = j;
                    }
                }
            }
            // Count of solutions including S[j]
            x = (i-costlong[j] >= 0)? table[i - costlong[j]][j]: 0;

            // Count of solutions excluding S[j]
            y = (j >= 1)? table[i][j-1]: 0;

            // total count
            table[i][j] = x + y;
        }
    }
    int result[count[money] - 1];
    int v = 0;
    if (table[n][m-1] == 1) {

        int k = money;
        while (k > 0)
        {
            result[count[k] - 2] = from[k]+1;
            k = k - costlong[from[k]];
            v++;
        }
        for(i = 0; i < v; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }
    return table[n][m-1];
}

int main () {
    char *endptr = NULL;
    char *token = NULL;
    long costlong[10000], moneylong[10000];
    int itemtot, ordertot;
    itemtot = itemloop(endptr, token, costlong);
    ordertot = orderloop(endptr, token, moneylong);
    for (int n = 0; n < ordertot; n++) {
        int money = moneylong[n];
        int solved = solution(costlong, money, itemtot);
        if(solved == 0) {
            printf("Impossible\n");
        } else if(solved > 1){
            printf("Ambiguous\n");
        }
    }
    free(endptr);
    free(token);
    return 0;
}