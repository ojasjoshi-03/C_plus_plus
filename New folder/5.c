#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], copiedStr[100];
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Accept String\n");
        printf("2. Print String Length\n");
        printf("3. Print String in Reverse Order\n");
        printf("4. Copy String and Print Both\n");
        printf("5. Compare Two Strings\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0'; 
                break;

            case 2: {
                int length = 0;
                while (str1[length] != '\0') {
                    length++;
                }
                printf("Length of the string: %d\n", length);
                break;
            }

            case 3: {
                int length = 0;
                while (str1[length] != '\0') {
                    length++;
                }
                printf("String in reverse: ");
                for (int i = length - 1; i >= 0; i--) {
                    printf("%c", str1[i]);
                }
                printf("\n");
                break;
            }

            case 4: {
                int i = 0;
                while (str1[i] != '\0') {
                    copiedStr[i] = str1[i];
                    i++;
                }
                copiedStr[i] = '\0';
                printf("Original String: %s\n", str1);
                printf("Copied String: %s\n", copiedStr);
                break;
            }

            case 5: {
                printf("Enter the first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';  
                printf("Enter the second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0'; 
                
                int result = strcmp(str1, str2);
                if (result == 0) {
                    printf("The strings are equal.\n");
                } else if (result > 0) {
                    printf("The first string is greater.\n");
                } else {
                    printf("The second string is greater.\n");
                }
                break;
            }

            case 6:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
