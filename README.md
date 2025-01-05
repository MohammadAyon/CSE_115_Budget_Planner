

# Budget Planner Application README

## Overview
The Budget Planner Application helps users create and manage their personal budget by tracking income, expenditure, and savings. It allows users to:
- Create a budget plan
- View their budget details
- Record spending on various items
- View a spending summary
- Save and load budget plans and spending records to/from files

## Features
- **Create Budget Plan**: Enter income, savings target, and allocate budget to different categories like food, accommodation, healthcare, education, clothing, and entertainment.
- **View Budget Plan**: View the details of the budget plan, including total income, expenditure, and remaining money.
- **Record Spending**: Track individual spending and update remaining money.
- **View Spending Summary**: Display a list of recorded spending along with the total spent.
- **Save and Load Data**: Budget plans and spending records are saved to files and can be loaded when restarting the application.

## File Handling
- **Budget Plan**: Stored in a file named `BudgetPlan.txt`.
- **Spending Records**: Stored in a file named `SpendMoney.txt`.

## Data Structures
### `struct budgetplan`
Holds the user's budget data including:
- `income`: Total income.
- `savingsTarget`: Desired savings.
- `food`, `accommodation`, `healthcare`, `education`, `clothing`, `entertainment`: Budget allocations.
- `totalExpenditure`: Total spending across categories.
- `remainingMoney`: The remaining money after accounting for expenditure.

### `struct spendMoney`
Stores individual spending data:
- `nameItem`: The name of the item purchased.
- `cost`: The cost of the item.

## Functions

- **`add(float x, float y)`**: Adds two floating-point numbers.
- **`subs(float x, float y)`**: Subtracts the second number from the first, returning the absolute value of the difference.
- **`createBudgetPlan(struct budgetplan *b)`**: Creates a new budget plan.
- **`viewBudgetPlan(const struct budgetplan *b)`**: Displays the current budget plan.
- **`recordSpending(struct spendMoney s[], int *count, struct budgetplan *b)`**: Records an item purchase and updates the budget.
- **`viewSpendingSummary(struct spendMoney s[], int count)`**: Displays a summary of all recorded spending.
- **`saveBudgetPlanToFile(const struct budgetplan *b)`**: Saves the budget plan to a file.
- **`loadBudgetPlanFromFile(struct budgetplan *b)`**: Loads the budget plan from a file.
- **`saveSpendingToFile(struct spendMoney s[], int count)`**: Saves spending records to a file.
- **`loadSpendingFromFile(struct spendMoney s[], int *count)`**: Loads spending records from a file.

## Usage

### Compilation
To compile the program, use the following command in a terminal:

```bash
gcc -o budget_planner budget_planner.c
```

### Running the Application
To run the application, execute the following command:

```bash
./budget_planner
```

### User Interface
Upon starting the application, you will be presented with the following menu options:
1. **Create a New Budget Plan**: Create a new budget by entering your income and category-wise budget allocation.
2. **View Budget Plan**: View your current budget and remaining balance.
3. **Record Spending**: Record the purchase of an item and deduct the cost from your remaining money.
4. **View Spending Summary**: View a summary of all recorded spending.
5. **Save and Quit**: Save the budget plan and spending records, then exit the application.

### Data Files
- The budget plan is saved in `BudgetPlan.txt`.
- Spending records are saved in `SpendMoney.txt`.
- If no existing data is found, you will be prompted to create a new budget plan or record spending.

## License
This software is released under the MIT License.

## Notes
- Ensure that you have write permissions to the directory to store the `BudgetPlan.txt` and `SpendMoney.txt` files.
- The application handles a maximum of 200 spending records.


