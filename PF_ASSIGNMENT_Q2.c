#include<stdio.h>
     						//PF ASSIGNMENT QUESTION 2

															// Function declarations
															
void customer_info(char name[], char cnic[]);
void display_inventory(int codes[], int quantity[], int price[], int size);
void add_to_cart(int codes[], int quantity[], int price[], int size, int cart_code[], int cart_qty[], int *cart_count);
void display_total_bill(int cart_code[], int cart_qty[], int cart_count, int codes[], int price[], char promo[]);
void show_invoice(char name[], char cnic[], int cart_code[], int cart_qty[], int cart_count, int codes[], int price[], char promo[]);

int main() {
    int codes[4] = {1, 2, 3, 4};
    int quantity[4] = {50, 10, 20, 8};
    int price[4] = {100, 200, 300, 150};

    int cart_code[10];
    int cart_qty[10];
    int cart_count = 0;

    char name[30], cnic[20], promo[10];
    int choice;
    	printf("\n Customer Information:");
    	customer_info(name, cnic);

    do {
    	
        printf("\n    Supermarket Inventory System \n");
        printf(" 1. Display Inventory\n");
        printf(" 2. Add Item to Cart\n");
        printf(" 3. Display Total Bill\n");
        printf(" 4. Show Invoice\n");
        printf(" 5. Exit\n");
        printf(" Enter your choice: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                
                 display_inventory(codes, quantity, price, 4);
                break;
            case 2:
               add_to_cart(codes, quantity, price, 4, cart_code, cart_qty, &cart_count);
                break;
            case 3:
           display_total_bill(cart_code, cart_qty, cart_count, codes, price, promo);
                break;
            case 4:
                 show_invoice(name, cnic, cart_code, cart_qty, cart_count, codes, price, promo);
                break;
            case 5:
                 printf("   Exiting system:)   \n Thank you for shopping!\n");
                  printf("-----------------------------\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
                 printf("-----------------------------\n");
        }
    } while (choice != 5);

    return 0;
}

										// Function 1: Customer Information
										
void customer_info(char name[], char cnic[]) {
    printf("\nEnter Customer Name: ");
    scanf("%s", name);  // simple, single word
    printf("Enter Customer CNIC(without dash(-) ): ");
    scanf("%s", cnic);
    printf("  Customer info saved successfully!  \n");
     printf("------------------------------------\n");
}

									// Function 2: Display Inventory
									
void display_inventory(int codes[], int quantity[], int price[], int size) {
    int i;
    printf("\nProduct Code\tQuantity\tPrice\n");
    for (i = 0; i < size; i++) {
        printf("%d\t\t%d\t\t%d\n", codes[i], quantity[i], price[i]);
    }
}

									// Function 3: Add Item to Cart
									
void add_to_cart(int codes[], int quantity[], int price[], int size, int cart_code[], int cart_qty[], int *cart_count) {
    int code, qty, i, found = 0;
    printf("\nEnter Product Code to buy: ");
    scanf("%d", &code);
    printf("Enter Quantity: ");
    scanf("%d", &qty);

    for (i = 0; i < size; i++) {
        if (codes[i] == code) {
            found = 1;
            if (quantity[i] >= qty) {
                quantity[i] -= qty;  					 // update stock
                cart_code[*cart_count] = code;
                cart_qty[*cart_count] = qty;
                (*cart_count)++;
                printf("Item added to cart successfully!\n");
                 printf("-----------------------------\n");
            } else {
                printf("Not enough stock available!\n");
                 printf("-----------------------------\n");
            }
            break;
        }
    }

    if (!found)
        printf("Invalid Product Code!\n");
         printf("-----------------------\n");
}

												// Function 4: Display Total Bill
												
void display_total_bill(int cart_code[], int cart_qty[], int cart_count, int codes[], int price[], char promo[]) {
    int i, j, total = 0;
    for (i = 0; i < cart_count; i++) {
        for (j = 0; j < 4; j++) {
            if (cart_code[i] == codes[j]) {
                total += price[j] * cart_qty[i];
            }
        }
    }

    printf("\nEnter promo code (or 'no' if none): ");
    scanf("%s", promo);

    if (promo[0] == 'E' && promo[1] == 'i' && promo[2] == 'd') { 
        printf("Promo code applied! 25%% discount.\n");
        total = total - (total * 25 / 100);
    } else {
        printf("No discount applied.\n");
         printf("----------------------\n");
    }

    printf("Total Bill: %d\n", total);
     printf("---------------------------\n");
      printf("--------------------------\n");
}

								// Function 5: Show Invoice
								
void show_invoice(char name[], char cnic[], int cart_code[], int cart_qty[], int cart_count, int codes[], int price[], char promo[]) {
    int i, j, total = 0;
    printf("     Invoice     \n");
    printf("Customer: %s\nCNIC: %s\n", name, cnic);
    printf("-----------------------------\n");
    printf("Code\tQty\tPrice\tTotal\n");

    for (i = 0; i < cart_count; i++) {
        for (j = 0; j < 4; j++) {
            if (cart_code[i] == codes[j]) {
                int item_total = price[j] * cart_qty[i];
                printf("%d\t%d\t%d\t%d\n", codes[j], cart_qty[i], price[j], item_total);
                total += item_total;
            }
        }
    }

    if (promo[0] == 'E' && promo[1] == 'i' && promo[2] == 'd') {
        printf("\n25%% Discount Applied!");
         printf("\n-----------------------------\n");
        total = total - (total * 25 / 100);
    }

    printf("\nFinal Bill: %d\n", total);
    printf("----------------------------\n");
     printf("---------------------------\n");
}

