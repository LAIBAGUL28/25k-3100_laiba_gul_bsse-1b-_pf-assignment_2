#include <stdio.h>
						//pf assignment 2   (question:1)

// Function declarations
void addBook(int isbns[], char titles[][50], float prices[], int quantities[], int *count);
void processSale(int isbns[], int quantities[], int count);
void lowStockReport(int isbns[], char titles[][50], float prices[], int quantities[], int count);

int main() {
    int isbns[100];
    char titles[100][50];
    float prices[100];
    int quantities[100];
    int count = 0;
    int choice;

    do {
        printf("\n		 Liberty Books Inventory System 		\n");
        printf("  1. Add New Book\n");
        printf("  2. Process a Sale\n");
        printf("  3. Generate Low-Stock Report\n");
        printf("  4. Exit\n");
        printf("  Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(isbns, titles, prices, quantities, &count);
                break;
            case 2:
                processSale(isbns, quantities, count);
                break;
            case 3:
                lowStockReport(isbns, titles, prices, quantities, count);
                break;
            case 4:
                printf(" Exiting program!\n----Goodbye----\n");
                break;
            default:
                printf(" Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// 					Function 1: Add New Book
void addBook(int isbns[], char titles[][50], float prices[], int quantities[], int *count) {
    if (*count >= 100) {
        printf("Error: Book limit exceeded!\n");
        return;
    }

    int new_isbn;
    float new_price;
    int new_quantity;
    char new_title[50];

    printf("\nEnter ISBN: ");
    scanf("%d", &new_isbn);

    // Check for duplicate ISBN
    int i;
    for (i = 0; i < *count; i++) {
        if (isbns[i] == new_isbn) {
            printf("Error: Book with this ISBN already exists!\n");
            printf("----------------------------------------------");
            printf("\n");
            return;
        }
    }

    printf("\nEnter Title (NO SPACE ALLOWED): ");
    scanf("%s", new_title);

    printf("\nEnter Price: ");
    scanf("%f", &new_price);

    printf("\nEnter Quantity: ");
    scanf("%d", &new_quantity);

    										// Copy title 
    i = 0;
    while (new_title[i] != '\0') {
        titles[*count][i] = new_title[i];
        i++;
    }
    titles[*count][i] = '\0';

    isbns[*count] = new_isbn;
    prices[*count] = new_price;
    quantities[*count] = new_quantity;

    (*count)++;
    printf("Book added successfully!\n");
    printf("--------------------------");
    printf("\n");
}

												//  Function 2: Process a Sale
void processSale(int isbns[], int quantities[], int count) {
    if (count == 0) {
        printf("No books in inventory!\n");
        printf("------------------------");
        printf("\n");
        return;
    }

    int search_isbn, qty_sold, found = 0;

    printf("\nEnter ISBN of the book sold: ");
    scanf("%d", &search_isbn);

    int i;
    for (i = 0; i < count; i++) {
        if (isbns[i] == search_isbn) {
            found = 1;
            printf("Enter quantity sold: ");
            scanf("%d", &qty_sold);

            if (quantities[i] >= qty_sold) {
                quantities[i] -= qty_sold;
                printf("Sale processed! Remaining stock: %d\n", quantities[i]);
                printf("----------------------------------------------");
                printf("\n");
   			 } 
			else
			 {
                printf("Error: Not enough stock! Only %d left.\n", quantities[i]);
                 printf("----------------------------------------------");
                printf("\n");
             }
            break;
        }
    }

    if (!found) {
        printf("Book with ISBN %d not found!\n", search_isbn);
         printf("----------------------------------------------");
                printf("\n");
    }
}

							//  Function 3: Low-Stock Report 
void lowStockReport(int isbns[], char titles[][50], float prices[], int quantities[], int count) {
    if (count == 0) {
        printf("No books in inventory!\n");
         printf("-------------------------");
                printf("\n");
        return;
    }

    int found = 0;
    printf("\n     Low-Stock Books (Quantity < 5)      \n");

    int i;
    for (i = 0; i < count; i++) {
        if (quantities[i] < 5) {
            printf("ISBN: %d | Title: %s | Price: %.2f | Quantity: %d\n",
                   isbns[i], titles[i], prices[i], quantities[i]);
                    printf("----------------------------------------------");
                printf("\n");
            found = 1;
        }
    }

    if (!found) {
        printf("All books are sufficiently stocked!\n");
         printf("----------------------------------------------");
                printf("\n");
    }
}

