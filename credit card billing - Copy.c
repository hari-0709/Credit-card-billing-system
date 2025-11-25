#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing customer details
struct Customer {
    int id;
    char name[50];
    char cardNumber[20];
    float creditLimit;
    float currentBalance;
};

// Function prototypes
void addCustomer();
void recordPurchase();
void recordPayment();
void viewCustomer();
void generateBill();

int main() {
    int choice;

    while (1) {
        printf("\n=== Credit Card Billing System ===\n");
        printf("1. Add New Customer\n");
        printf("2. Record Purchase\n");
        printf("3. Record Payment\n");
        printf("4. View Customer Details\n");
        printf("5. Generate Billing Statement\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCustomer();
                break;
            case 2:
                recordPurchase();
                break;
            case 3:
                recordPayment();
                break;
            case 4:
                viewCustomer();
                break;
            case 5:
                generateBill();
                break;
            case 6:
                printf("👋 Exiting... Goodbye!\n");
                exit(0);
            default:
                printf("❌ Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to add a new customer
void addCustomer() {
    FILE *fp = fopen("creditcard.dat", "ab+");
    struct Customer c;

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Customer ID: ");
    scanf("%d", &c.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", c.name);
    printf("Enter Card Number: ");
    scanf("%s", c.cardNumber);
    printf("Enter Credit Limit: ");
    scanf("%f", &c.creditLimit);
    c.currentBalance = 0.0;

    fwrite(&c, sizeof(struct Customer), 1, fp);
    fclose(fp);

    printf("✅ Customer added successfully!\n");
}

// Function to record a purchase
void recordPurchase() {
    FILE *fp = fopen("creditcard.dat", "rb+");
    struct Customer c;
    int id, found = 0;
    float amount;

    if (fp == NULL) {
        printf("No customer data found.\n");
        return;
    }

    printf("Enter Customer ID: ");
    scanf("%d", &id);

    while (fread(&c, sizeof(struct Customer), 1, fp)) {
        if (c.id == id) {
            found = 1;
            printf("Enter Purchase Amount: ");
            scanf("%f", &amount);

            if (c.currentBalance + amount > c.creditLimit) {
                printf("❌ Purchase exceeds credit limit!\n");
            } else {
                c.currentBalance += amount;
                fseek(fp, -(long)sizeof(struct Customer), SEEK_CUR);
                fwrite(&c, sizeof(struct Customer), 1, fp);
                printf("✅ Purchase recorded successfully!\n");
            }
            break;
        }
    }

    if (!found)
        printf("❌ Customer not found.\n");

    fclose(fp);
}

// Function to record a payment
void recordPayment() {
    FILE *fp = fopen("creditcard.dat", "rb+");
    struct Customer c;
    int id, found = 0;
    float payment;

    if (fp == NULL) {
        printf("No customer data found.\n");
        return;
    }

    printf("Enter Customer ID: ");
    scanf("%d", &id);

    while (fread(&c, sizeof(struct Customer), 1, fp)) {
        if (c.id == id) {
            found = 1;
            printf("Enter Payment Amount: ");
            scanf("%f", &payment);

            if (payment > c.currentBalance) {
                printf("❌ Payment exceeds current balance!\n");
            } else {
                c.currentBalance -= payment;
                fseek(fp, -(long)sizeof(struct Customer), SEEK_CUR);
                fwrite(&c, sizeof(struct Customer), 1, fp);
                printf("✅ Payment recorded successfully!\n");
            }
            break;
        }
    }

    if (!found)
        printf("❌ Customer not found.\n");

    fclose(fp);
}

// Function to view a customer’s details
void viewCustomer() {
    FILE *fp = fopen("creditcard.dat", "rb");
    struct Customer c;
    int id, found = 0;

    if (fp == NULL) {
        printf("No customer data found.\n");
        return;
    }

    printf("Enter Customer ID: ");
    scanf("%d", &id);

    while (fread(&c, sizeof(struct Customer), 1, fp)) {
        if (c.id == id) {
            printf("\n--- Customer Details ---\n");
            printf("ID: %d\n", c.id);
            printf("Name: %s\n", c.name);
            printf("Card Number: %s\n", c.cardNumber);
            printf("Credit Limit: %.2f\n", c.creditLimit);
            printf("Current Balance: %.2f\n", c.currentBalance);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("❌ Customer not found.\n");

    fclose(fp);
}

// Function to generate a billing statement
void generateBill() {
    FILE *fp = fopen("creditcard.dat", "rb");
    struct Customer c;
    int id, found = 0;
    float interestRate = 0.02; // 2% monthly interest
    float dueAmount;

    if (fp == NULL) {
        printf("No customer data found.\n");
        return;
    }

    printf("Enter Customer ID: ");
    scanf("%d", &id);

    while (fread(&c, sizeof(struct Customer), 1, fp)) {
        if (c.id == id) {
            found = 1;
            printf("\n--- Billing Statement ---\n");
            printf("Customer Name: %s\n", c.name);
            printf("Card Number: %s\n", c.cardNumber);
            printf("Current Balance: %.2f\n", c.currentBalance);

            dueAmount = c.currentBalance + (c.currentBalance * interestRate);
            printf("Interest (2%%): %.2f\n", c.currentBalance * interestRate);
            printf("Total Due Amount: %.2f\n", dueAmount);
            break;
        }
    }

    if (!found)
        printf("❌ Customer not found.\n");

    fclose(fp);
}
