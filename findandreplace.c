#include <stdio.h>
#include <string.h>

#define MAX 1000

int main() {
    char text[MAX], find[100], replace[100], result[MAX];
    int i = 0, j = 0, k = 0, found;

    printf("Enter the text:\n");
    fgets(text, MAX, stdin);

    printf("Enter the word to find: ");
    scanf("%s", find);

    printf("Enter the word to replace with: ");
    scanf("%s", replace);

    while (text[i] != '\0') {
        found = 1;
        if (text[i] == find[0]) {
            for (k = 0; find[k] != '\0'; k++) {
                if (text[i + k] != find[k]) {
                    found = 0;
                    break;
                }
            }

            if (found) {
                strcpy(&result[j], replace);
                j += strlen(replace);
                i += strlen(find);
            } else {
                result[j++] = text[i++];
            }
        } else {
            result[j++] = text[i++];
        }
    }

    result[j] = '\0';
    printf("\nUpdated text:\n%s", result);

    return 0;
}