from facades import BankAccountFacade, CategoryFacade, OperationFacade
from utils import JSONImporter
from datetime import datetime


def main():
 
    bank_account_facade = BankAccountFacade()
    category_facade = CategoryFacade()
    operation_facade = OperationFacade()

    account = bank_account_facade.create_account("Основной счет", 1000)
    category_income = category_facade.create_category("Зарплата", "доход")
    category_expense = category_facade.create_category("Кафе", "расход")

    operation1 = operation_facade.create_operation(account, category_income, 5000, datetime.now(), "Зарплата")
    operation2 = operation_facade.create_operation(account, category_expense, -200, datetime.now(), "Ужин в кафе")

    print(f"Баланс после операций: {account.balance}")

    json_importer = JSONImporter()
    operations_data = json_importer.import_data("operations.json")  

    print(f"Импортированные операции: {operations_data}")


if __name__ == "__main__":
    main()
