import time
from functools import wraps

def measure_time(func):
    @wraps(func)
    def wrapper(*args, **kwargs):
        start_time = time.time()
        result = func(*args, **kwargs)
        end_time = time.time()
        print(f"Execution time of {func.__name__}: {end_time - start_time:.4f} seconds")
        return result
    return wrapper


class CreateOperationCommand:
    def __init__(self, bank_account, category, amount, date, description=""):
        self.bank_account = bank_account
        self.category = category
        self.amount = amount
        self.date = date
        self.description = description

    @measure_time
    def execute(self):
        operation_facade = OperationFacade()
        return operation_facade.create_operation(
            self.bank_account, self.category, self.amount, self.date, self.description
        )
