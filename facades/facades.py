from models import BankAccount, Category, Operation
import datetime

class BankAccountFacade:
    def __init__(self):
        self.accounts = {}

    def create_account(self, name: str, balance: float = 0.0):
        account = BankAccount(name, balance)
        self.accounts[account.id] = account
        return account

    def get_account(self, account_id: str):
        return self.accounts.get(account_id)

    def update_balance(self, account_id: str, amount: float):
        account = self.get_account(account_id)
        if account:
            account.update_balance(amount)


class CategoryFacade:
    def __init__(self):
        self.categories = {}

    def create_category(self, name: str, category_type: str):
        category = Category(name, category_type)
        self.categories[category.id] = category
        return category

    def get_category(self, category_id: str):
        return self.categories.get(category_id)


class OperationFacade:
    def __init__(self):
        self.operations = []

    def create_operation(self, bank_account: BankAccount, category: Category, amount: float, date: datetime, description: str = ""):
        operation = Operation(bank_account, category, amount, date, description)
        self.operations.append(operation)
        bank_account.update_balance(amount)
        return operation
