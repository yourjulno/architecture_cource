import uuid
from datetime import datetime


class BankAccount:
    def __init__(self, name: str, balance: float = 0.0):
        self.id = str(uuid.uuid4()) 
        self.name = name  
        self.balance = balance 

    def update_balance(self, amount: float):
        self.balance += amount

    def __str__(self):
        return f"BankAccount(id={self.id}, name={self.name}, balance={self.balance})"


class Category:
    def __init__(self, name: str, category_type: str):
        self.id = str(uuid.uuid4())  
        self.name = name 
        self.category_type = category_type  

    def __str__(self):
        return f"Category(id={self.id}, name={self.name}, category_type={self.category_type})"


class Operation:
    def __init__(self, bank_account: BankAccount, category: Category, amount: float, date: datetime, description: str = ""):
        self.id = str(uuid.uuid4()) 
        self.bank_account = bank_account 
        self.category = category 
        self.amount = amount 
        self.date = date 
        self.description = description 

    def __str__(self):
        return f"Operation(id={self.id}, bank_account={self.bank_account.id}, category={self.category.name}, amount={self.amount}, date={self.date}, description={self.description})"
