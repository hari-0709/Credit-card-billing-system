


📘 01_abstract.md
# Abstrac

The Credit Card Billing System is a console-based C program designed to
simulate basic operations of a retail billing module. The system allows
the user to add products, manage product lists, search items, delete or
update product information, and generate customer bills.
The system stores data in text files and runs on any standard C compiler.

📘 02_features.md
# Features of the Program

- Add new products to the database
- Display all products
- Search product by ID
- Edit product details
- Delete a product
- Generate customer bill
- Save all data to text file persistently
- Easy console-based menu interface

📘 03_technical_requirements.md
# Technical Requirements

- Operating System: Windows / Linux / macOS
- Compiler: GCC, Clang, MinGW, Turbo C, or any ANSI C compiler
- Tools: Terminal / Command Prompt
- RAM: Minimum 2 GB

📘 04_functional_requirements.md
# Functional Requirements

1. System should allow adding product records.
2. System must store product name, ID, price, and quantity.
3. System must allow user to view stored products.
4. System must allow search by product ID.
5. System must allow deleting product by ID.
6. System must generate invoices with total cost.
7. Data should be persistently stored in `products.txt`.

📘 05_how_to_run.md
# How to Run the Program

1. Open terminal in the `src/` folder.
2. Compile the program:

   gcc billing.c -o billing

3. Run it:

   ./billing   (Linux/macOS)
   billing.exe (Windows)

📘 06_data_storage.md
# Data Storage File: products.txt

Each line contains:

ID  Name  Price  Quantity

Sample:
101 Milk 42.50 120
102 Bread 25.00 200

📘 07_menu_screen.md
# Program Menu Screen (ASCII Screenshot)

==========================================
        CREDIT CARD BILLING SYSTEM
==========================================
1. Add Product
2. Display Products
3. Search Product
4. Edit Product
5. Delete Product
6. Generate Bill
7. Exit
------------------------------------------
Enter choice: _

📘 08_add_product_screen.md
# Add Product Screen (ASCII Screenshot)

========== ADD PRODUCT ==========
Enter Product ID: 101
Enter Product Name: Coffee
Enter Price: 150
Enter Quantity: 50
Product added successfully!

📘 09_display_products_screen.md
# Display Products Output (ASCII Screenshot)

============ PRODUCT LIST =============
ID      Name          Price     Qty
----------------------------------------
101     Coffee        150.00    50
102     Sugar         45.00     120
103     Oil           210.00    30
----------------------------------------

📘 10_generate_bill_screen.md
# Generate Bill Screen

Enter product ID: 101
Enter quantity: 2
Enter product ID: 103
Enter quantity: 1
...

========== BILL ==========
Item        Qty    Price    Total
Coffee      2      150      300
Oil         1      210      210
------------------------------
Grand Total: 510

📘 11_search_product_screen.md
# Search Product Screen

Enter product ID: 102

Product Found:
Name: Sugar
Price: 45
Quantity: 120

📘 12_delete_product_screen.md
# Delete Product Screen

Enter ID to delete: 102
Product deleted successfully!

📘 13_edit_product_screen.md
# Edit Product Screen

Enter ID to edit: 101

1. Edit Name
2. Edit Price
3. Edit Quantity

Enter choice: 2
Enter new price: 180
Price updated!

📘 14_file_handling_details.md
# File Handling Details

- Program uses text files for persistence.
- Functions used: fopen(), fprintf(), fscanf(), fclose().
- Temporary file used for delete/edit operations.

📘 15_program_flowchart.md
Start
 ↓
Show Menu
 ↓
User selects option
 ↓
Perform operation (Add, Display, Search...)
 ↓
Return to menu
 ↓
Exit

📘 16_use_case_diagram.md
User → (Manage Products)
User → (Generate Bill)
User → (View Products)

📘 17_er_diagram.md
PRODUCT (ProductID, Name, Price, Quantity)

📘 18_test_cases.md
TC01: Add Product → Should append to file
TC02: Display Products → Should read all lines
TC03: Search Product → Valid ID should return record

📘 19_limitations.md
- No GUI interface
- No complex tax/discount handling
- No database, only text file

📘 20_future_scope.md
- Add SQL database
- Add barcode scanning support
- Add graphical interface

📘 21_conclusion.md
The system demonstrates file handling, modular programming,
and basic retail billing operations using C language.

📘 22_references.md
- ANSI C Standard Library
- GCC Compiler Documentation

📘 23_team_details.md
Team:
- Programmer: ___________________
- Tester: _______________________
# Credit-card-billing-system
