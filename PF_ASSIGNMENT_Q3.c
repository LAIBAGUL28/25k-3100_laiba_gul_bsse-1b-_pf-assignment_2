#include <stdio.h>
 						//pf assignment question 3

void show_menu();
void update_status(int grid[3][3]);
void query_status(int grid[3][3]);
void run_diagnostic(int grid[3][3]);

int main() {
    int grid[3][3] = {0};
    int choice;

    do {
        show_menu();
        printf("Enter your choice:\n ");
        scanf("%d", &choice);

        if (choice == 1) {
            update_status(grid);
        } 
        else if (choice == 2) {
            query_status(grid);
        } 
        else if (choice == 3) {
            run_diagnostic(grid);
        }
        else if (choice == 4) {
            printf("\nExiting system... \n    Goodbye!\n");
        } 
        else {
            printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}

									// Menu display function
									
void show_menu() {
    printf("\n----- IESCO Power System -----\n");
    printf(" 1. Update Sector Status\n");
    printf(" 2. Query Sector Status\n");
    printf(" 3. Run System Diagnostic\n");
    printf(" 4. Exit\n");
}

									// Update status of a sector
									
void update_status(int grid[3][3]) {
    int row, col, bit, action;

    printf("\nEnter Sector Coordinates (row col) 0-2 range:\n ");
    scanf("%d %d", &row, &col);

    if (row < 0 || row >= 3 || col < 0 || col >= 3) {
        printf("Invalid coordinates!\n");
         printf("----------------------\n");
        return;
    }

    printf("\nSelect Status Flag to Update:\n");
    printf(" 0. Power Status (1=ON, 0=OFF)\n");
    printf(" 1. Overload Warning (1=Yes, 0=No)\n");
    printf(" 2. Maintenance Required (1=Yes, 0=No)\n");
    printf(" Enter bit number (0-2): \n");
    scanf("%d", &bit);

    printf(" Enter Action (1=Set ON, 0=Clear OFF): ");
    scanf("%d", &action);

    if (action == 1)
        grid[row][col] = grid[row][col] | (1 << bit);   // set bit
    else
        grid[row][col] = grid[row][col] & (~(1 << bit)); // clear bit

    printf("\nSector (%d,%d) updated successfully!\n", row, col);
     printf("----------------------------------------\n");
}

								// Query a sector’s current status

void query_status(int grid[3][3]) {
    int row, col, value;

    printf("\nEnter Sector Coordinates to Query (row col): \n ");
    scanf("%d %d", &row, &col);

    if (row < 0 || row >= 3 || col < 0 || col >= 3) {
        printf("Invalid coordinates!\n");
         printf("--------------------\n");
        return;
    }

    value = grid[row][col];

    printf("\n----- Sector (%d,%d) Status -----\n", row, col);
    if (value & (1 << 0))
    {
        printf("Power: ON\n");
         printf("--------------\n");
    }
    else
    {
        printf("Power: OFF\n");
         printf("---------------\n");
    }

    if (value & (1 << 1))
    {
        printf("Overload: Overloaded\n");
         printf("------------------\n");
	}
    else
    {
	    printf("Overload: Normal\n");
         printf("--------------------\n");
	}
    if (value & (1 << 2))
    {
        printf("Maintenance: Required\n");
         printf("------------------\n");
    }
	else
	{
        printf("Maintenance: Not Required\n");
         printf("-------------------------\n");
	
    printf("Encoded Value (Decimal): %d\n", value);
     printf("----------------------------------------\n");
	}
}

							// Scan grid and show diagnostics

void run_diagnostic(int grid[3][3]) {
    int r, c;
    int overloaded_count = 0;
    int maintenance_count = 0;

    for (r = 0; r < 3; r++) {
        for (c = 0; c < 3; c++) {
            if (grid[r][c] & (1 << 1)) // bit 1 = overload
                overloaded_count++;
            if (grid[r][c] & (1 << 2)) // bit 2 = maintenance
                maintenance_count++;
        }
    }

    printf("\n----- System Diagnostic Report -----\n");
    printf("Total Overloaded Sectors: %d\n", overloaded_count);
    printf("Total Maintenance Required: %d\n", maintenance_count);
    printf("----------------------------------------\n");
}

