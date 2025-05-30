# **Inventory Management System**
----
## **Overview**
This C program is an inventory management system designed to track stock levels for a small market or store. It allows users to record sales transactions and automatically updates inventory levels, providing alerts when items fall below a predefined minimum threshold.
____
## **🚀Features**
1. **📊Inventory Tracking :** 
- Tracks 5 predefined items with their codes, names, and quantities
- Predefined items include: Soap, Blade, Candles, Books, and Pop
2. **💸Sales Processing :** 
- Allows entering multiple items purchased in a single transaction
- Validates item codes and quantities
- Prevents sales that would exceed current stock levels
3. **⚠️Alert System :**
- Automatically checks stock levels after each transaction
- Alerts when any item falls below the minimum threshold (20 units)
4. **💾Data Persistance :** 
- Saves updated inventory information to a text file ("Inventory_market_Product_analysis.txt")
- File includes item codes, names, and remaining quantities
5. **👨‍💻User - Friendly Interface**
- Displays available items with their codes before each transaction
- Provides clear error messages for invalid inputs
----
## **🛠️Usage Instructions**
### **📋Requirements**
- GCC compiler (`gcc --version` to verify).
- A terminal (Linux/macOS or Windows WSL).
- Visual Studio Code text editor (optional).

### **⚡Installation & Usage**
```bash
git clone https://github.com/nevinbeno/Inventory-Management.git #clone repository
cd Inventory-Management
```
---
### **Steps to Compile and Run (BASH)**
1. **Open Terminal**:
2. **Compile**:<br>
```bash
gcc Inventory_market.c
```
3. **Run**<br>
```bash
./Inventory_market
```
---
### **🖥️Using Visual Studio Code (Alternative way)**
1. **Open integrated terminal in Visual Studio Code.**
2. **Compile**
```bash
gcc Inventory_market.c
```
3. **Run**
```
./Inventory_market
```
----
### **Entering a Transaction :**
- When prompted, enter the number of distinct items purchased (1-5)
- For each item:
~ Enter the item code (from the displayed list).
~ Enter the quantity purchased.
~ The program will validate all inputs.
----
### **🔍Viewing Results :**
- After each transaction, the program will:
~ Display any low-stock alerts
~ Update the inventory text file
- The text file can be opened with any text editor
----
### **Continuing or Exiting :**
- After each transaction, choose to:
~ Continue (enter any number except 1)
~ Exit (enter 1)
### **❌ Error Handling :**
- The program includes validation for:
~ Number of distinct items purchased (must be between 1-5)
~ Item codes (must match predefined items)
~ Quantities (must be positive and not exceed current stock)