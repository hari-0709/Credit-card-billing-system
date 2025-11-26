#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    int id;
    char name[50];
    float price;
    int qty;
};

void addProduct();
void displayProducts();
void searchProduct();
void editProduct();
void deleteProduct();
void generateBill();

int main() {
    int choice;

    while(1) {
        printf("\n==========================================\n");
        printf("        CREDIT CARD BILLING SYSTEM\n");
        printf("==========================================\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
        printf("4. Edit Product\n");
        printf("5. Delete Product\n");
        printf("6. Generate Bill\n");
        printf("7. Exit\n");
        printf("------------------------------------------\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addProduct(); break;
            case 2: displayProducts(); break;
            case 3: searchProduct(); break;
            case 4: editProduct(); break;
            case 5: deleteProduct(); break;
            case 6: generateBill(); break;
            case 7: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

void addProduct() {
    FILE *fp = fopen("../data/products.txt","a");
    struct Product p;

    printf("Enter Product ID: ");
    scanf("%d",&p.id);
    printf("Enter Product Name: ");
    scanf("%s",p.name);
    printf("Enter Price: ");
    scanf("%f",&p.price);
    printf("Enter Quantity: ");
    scanf("%d",&p.qty);

    fprintf(fp,"%d %s %.2f %d\n", p.id, p.name, p.price, p.qty);
    fclose(fp);

    printf("Product added successfully!\n");
}

void displayProducts() {
    FILE *fp = fopen("../data/products.txt","r");
    struct Product p;

    printf("\n============ PRODUCT LIST =============\n");
    printf("ID\tName\t\tPrice\tQty\n");
    printf("----------------------------------------\n");

    while(fscanf(fp,"%d %s %f %d", &p.id, p.name, &p.price, &p.qty) != EOF) {
        printf("%d\t%-10s\t%.2f\t%d\n", p.id, p.name, p.price, p.qty);
    }

    fclose(fp);
}

void searchProduct() {
    FILE *fp = fopen("../data/products.txt","r");
    struct Product p;
    int id, found = 0;

    printf("Enter product ID: ");
    scanf("%d",&id);

    while(fscanf(fp,"%d %s %f %d",&p.id,p.name,&p.price,&p.qty)!=EOF){
        if(p.id == id){
            printf("\nProduct Found:\n");
            printf("Name: %s\nPrice: %.2f\nQuantity: %d\n",p.name,p.price,p.qty);
            found = 1;
            break;
        }
    }
    if(!found) printf("Product not found!\n");

    fclose(fp);
}

void deleteProduct() {
    FILE *fp = fopen("../data/products.txt","r");
    FILE *temp = fopen("../data/temp.txt","w");
    struct Product p;
    int id;
    printf("Enter ID to delete: ");
    scanf("%d",&id);

    while(fscanf(fp,"%d %s %f %d",&p.id,p.name,&p.price,&p.qty)!=EOF){
        if(p.id != id){
            fprintf(temp,"%d %s %.2f %d\n",p.id,p.name,p.price,p.qty);
        }
    }

    fclose(fp);
    fclose(temp);
    remove("../data/products.txt");
    rename("../data/temp.txt","../data/products.txt");

    printf("Product deleted successfully!\n");
}

void editProduct() {
    FILE *fp = fopen("../data/products.txt","r");
    FILE *temp = fopen("../data/temp.txt","w");
    struct Product p;
    int id, choice;

    printf("Enter ID to edit: ");
    scanf("%d",&id);

    while(fscanf(fp,"%d %s %f %d",&p.id,p.name,&p.price,&p.qty)!=EOF){
        if(p.id == id){
            printf("\n1. Edit Name\n2. Edit Price\n3. Edit Quantity\n");
            printf("Enter choice: ");
            scanf("%d",&choice);

            if(choice == 1){ printf("New name: "); scanf("%s",p.name); }
            if(choice == 2){ printf("New price: "); scanf("%f",&p.price); }
            if(choice == 3){ printf("New qty: "); scanf("%d",&p.qty); }
        }
        fprintf(temp,"%d %s %.2f %d\n",p.id,p.name,p.price,p.qty);
    }

    fclose(fp);
    fclose(temp);
    remove("../data/products.txt");
    rename("../data/temp.txt","../data/products.txt");

    printf("Product updated!\n");
}

void generateBill() {
    FILE *fp = fopen("../data/products.txt","r");
    struct Product p;
    int id, qty;
    float total = 0;

    printf("Enter product ID (-1 to finish): ");
    while(scanf("%d",&id) && id != -1){
        printf("Enter quantity: ");
        scanf("%d",&qty);

        rewind(fp);
        while(fscanf(fp,"%d %s %f %d",&p.id,p.name,&p.price,&p.qty)!=EOF){
            if(p.id == id){
                float lineTotal = p.price * qty;
                printf("%s  x%d = %.2f\n",p.name,qty,lineTotal);
                total += lineTotal;
            }
        }
        printf("\nEnter product ID (-1 to finish): ");
    }

    fclose(fp);
    printf("\nGrand Total = %.2f\n", total);
}
