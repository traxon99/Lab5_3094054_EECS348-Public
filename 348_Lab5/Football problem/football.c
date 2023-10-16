#include <stdio.h>

void calculateCombinations(int score, int touchdowns, int fieldGoals, int safeties, int play, int plays[]) {
    if (score == 0) {
        printf("possible combinations of scoring plays:\n");

        for (int i = 0; i < play; i++) {
            if (plays[i] == 8) {
                printf("(8) TD + 2pt");
            } else if (plays[i] == 7) {
                printf("(7) TD + 1 1pt FG");
            } else if (plays[i] == 6) {
                printf("(6) TD");
            } else if (plays[i] == 3) {
                printf("(3) 3pt FG");
            } else if (plays[i] == 2) {
                printf("(2) Safety");
            }

            if (i < play - 1) {
                printf(", ");
            }
        }

        printf("\n");
    } else if (score > 0) {
        if (score >= 8) {
            plays[play] = 8;
            calculateCombinations(score - 8, touchdowns + 1, fieldGoals, safeties, play + 1, plays);
        }
        if (score >= 7) {
            plays[play] = 7;
            calculateCombinations(score - 7, touchdowns + 1, fieldGoals + 1, safeties, play + 1, plays);
        }
        if (score >= 6) {
            plays[play] = 6;
            calculateCombinations(score - 6, touchdowns + 1, fieldGoals, safeties, play + 1, plays);
        }
        if (score >= 3) {
            plays[play] = 3;
            calculateCombinations(score - 3, touchdowns, fieldGoals + 1, safeties, play + 1, plays);
        }
        if (score >= 2) {
            plays[play] = 2;
            calculateCombinations(score - 2, touchdowns, fieldGoals, safeties + 1, play + 1, plays);
        }
    }
}

int main() {
    int score;
    int plays[100]; // Maximum number of plays

    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if (score <= 1) {
            break;
        }

        calculateCombinations(score, 0, 0, 0, 0, plays);
    }

    return 0;
}
