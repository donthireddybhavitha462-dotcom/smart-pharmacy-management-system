import csv
import os
from datetime import datetime

MEDICINE_FILE = "medicines.csv"
SALES_FILE = "sales.csv"


def initialize():
    if not os.path.exists(MEDICINE_FILE):
        with open(MEDICINE_FILE, "w", newline="") as file:
            writer = csv.writer(file)
            writer.writerow([
                "Medicine ID",
                "Medicine Name",
                "Price",
                "Stock"
            ])

    if not os.path.exists(SALES_FILE):
        with open(SALES_FILE, "w", newline="") as file:
            writer = csv.writer(file)
            writer.writerow([
                "Bill ID",
                "Medicine ID",
                "Medicine Name",
                "Quantity",
                "Amount",
                "Date"
            ])


def add_medicine():
    mid = input("Medicine ID: ")
    name = input("Medicine Name: ")
    price = float(input("Price: "))
    stock = int(input("Stock: "))

    with open(MEDICINE_FILE, "a", newline="") as file:
        csv.writer(file).writerow([mid, name, price, stock])

    print("Medicine added successfully!")


def view_medicines():
    with open(MEDICINE_FILE, "r") as file:
        reader = csv.reader(file)

        print("\n===== MEDICINE LIST =====")
        for row in reader:
            print(row)


def sell_medicine():
    medicine_id = input("Medicine ID: ")
    quantity = int(input("Quantity: "))

    rows = []

    with open(MEDICINE_FILE, "r") as file:
        rows = list(csv.reader(file))

    for row in rows[1:]:
        if row[0] == medicine_id:
            stock = int(row[3])

            if stock >= quantity:
                row[3] = str(stock - quantity)

                amount = quantity * float(row[2])

                with open(SALES_FILE, "a", newline="") as sale:
                    csv.writer(sale).writerow([
                        len(open(SALES_FILE).readlines()),
                        row[0],
                        row[1],
                        quantity,
                        amount,
                        datetime.now().strftime("%Y-%m-%d")
                    ])

                print("Sale completed.")
                print("Bill Amount: ₹", amount)
            else:
                print("Insufficient stock.")
            break

    with open(MEDICINE_FILE, "w", newline="") as file:
        csv.writer(file).writerows(rows)


def sales_report():
    total = 0

    with open(SALES_FILE, "r") as file:
        reader = csv.DictReader(file)

        for row in reader:
            total += float(row["Amount"])

    print("\n===== SALES REPORT =====")
    print("Total Revenue: ₹", total)


def menu():
    initialize()

    while True:
        print("\n========== SMART PHARMACY ==========")
        print("1. Add Medicine")
        print("2. View Medicines")
        print("3. Sell Medicine")
        print("4. Sales Report")
        print("5. Exit")

        choice = input("Enter choice: ")

        if choice == "1":
            add_medicine()
        elif choice == "2":
            view_medicines()
        elif choice == "3":
            sell_medicine()
        elif choice == "4":
            sales_report()
        elif choice == "5":
            print("Thank you!")
            break
        else:
            print("Invalid choice.")

if __name__ == "__main__":
    menu()
