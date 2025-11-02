#include <stdio.h>
#include <string.h>
						//pf assgnment question 5

void reverseString(char str[]) {
    int len = strlen(str);
    int i;
    for ( i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void toggleBits(char *ch) {
    *ch = *ch ^ (1 << 1); 
    *ch = *ch ^ (1 << 4); 
}

void encodeMessage(char message[]) {
    reverseString(message);
    int i;
	for ( i = 0; message[i] != '\0'; i++) {
        toggleBits(&message[i]);
    }
    printf("Encoded message: %s\n", message);
}

void decodeMessage(char message[]) {
    int i;
	for ( i = 0; message[i] != '\0'; i++) {
        toggleBits(&message[i]);
    }
    reverseString(message);
    printf("Decoded message: %s\n", message);
}

int main() {
    char message[200];
    int choice;

    do {
        printf("--- TCS Secure Message System ---\n");
        printf("1. Encode Message\n");
        printf("2. Decode Message\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            printf("Enter message to encode: ");
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = '\0';
            encodeMessage(message);
        } 
        else if (choice == 2) {
            printf("Enter message to decode: ");
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = '\0';
            decodeMessage(message);
        } 
        else if (choice == 3) {
            printf("Exiting program!\n");
        } 
        else {
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}

