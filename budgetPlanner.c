#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct budgetplan {
    float income;
    float savingsTarget;
    float food;
    float accommodation;
    float healthcare;
    float education;
    float clothing;
    float entertainment;
    float totalExpenditure;
    float remainingMoney;
};

struct spendMoney {
    char nameItem[50];
    float cost;
};

float add(float x, float y);
float subs(float x, float y);

void createBudgetPlan(struct budgetplan *b);
void viewBudgetPlan(const struct budgetplan *b);
void recordSpending(struct spendMoney s[], int *count, struct budgetplan *b);
void viewSpendingSummary(struct spendMoney s[], int count);
void saveBudgetPlanToFile(const struct budgetplan *b);
void loadBudgetPlanFromFile(struct budgetplan *b);
void saveSpendingToFile(struct spendMoney s[], int count);
void loadSpendingFromFile(struct spendMoney s[], int *count);

int main(void) {
    struct budgetplan bp;
    struct spendMoney spm[200];
    int spendingCount = 0;
    int option;

    printf("\n\t\t *** Welcome to the Budget Planner Application ***\n\n");
    loadBudgetPlanFromFile(&bp);
    loadSpendingFromFile(spm, &spendingCount);

    do {
        printf("1. Create a New Budget Plan\n");
        printf("2. View Budget Plan\n");
        printf("3. Record Spending\n");
        printf("4. View Spending Summary\n");
        printf("5. Save and Quit\n");
        printf("Select an option (1-5): ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                createBudgetPlan(&bp);
                break;
            case 2:
                viewBudgetPlan(&bp);
                break;
            case 3:
                recordSpending(spm, &spendingCount, &bp);
                break;
            case 4:
                viewSpendingSummary(spm, spendingCount);
                break;
            case 5:
                saveBudgetPlanToFile(&bp);
                saveSpendingToFile(spm, spendingCount);
                printf("Data saved successfully. Exiting the application. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 5);

    return 0;
}

float add(float x, float y) {
    return x + y;
}

float subs(float x, float y) {
    return (x > y) ? (x - y) : (y - x);
}

void createBudgetPlan(struct budgetplan *b) {
    printf("\n\t*** Creating a New Budget Plan ***\n");
    printf("Enter your total income: ");
    scanf("%f", &b->income);
    printf("Enter your savings target: ");
    scanf("%f", &b->savingsTarget);

    printf("\nAllocate your budget in different categories:\n");
    printf("Food: ");
    scanf("%f", &b->food);
    printf("Accommodation: ");
    scanf("%f", &b->accommodation);
    printf("Healthcare: ");
    scanf("%f", &b->healthcare);
    printf("Education: ");
    scanf("%f", &b->education);
    printf("Clothing: ");
    scanf("%f", &b->clothing);
    printf("Entertainment: ");
    scanf("%f", &b->entertainment);

    b->totalExpenditure = add(add(b->food, b->accommodation), add(add(b->healthcare, b->education), add(b->clothing, b->entertainment)));
    b->remainingMoney = subs(b->income, b->totalExpenditure);

    if (b->totalExpenditure > b->income - b->savingsTarget) {
        printf("Warning: Your expenditure exceeds your target savings! Consider adjusting your plan.\n");
    } else {
        printf("Budget plan created successfully! Remaining money: %.2f\n", b->remainingMoney);
    }
}

void viewBudgetPlan(const struct budgetplan *b) {
    printf("\n\t*** Viewing Budget Plan ***\n");
    printf("Total Income: %.2f\n", b->income);
    printf("Savings Target: %.2f\n", b->savingsTarget);
    printf("Food: %.2f\n", b->food);
    printf("Accommodation: %.2f\n", b->accommodation);
    printf("Healthcare: %.2f\n", b->healthcare);
    printf("Education: %.2f\n", b->education);
    printf("Clothing: %.2f\n", b->clothing);
    printf("Entertainment: %.2f\n", b->entertainment);
    printf("Total Expenditure: %.2f\n", b->totalExpenditure);
    printf("Remaining Money: %.2f\n", b->remainingMoney);
}

void recordSpending(struct spendMoney s[], int *count, struct budgetplan *b) {
    char cont;
    do {
        printf("\n\t*** Recording Spending ***\n");
        printf("Enter the name of the item: ");
        scanf("%s", s[*count].nameItem);
        printf("Enter the cost of the item: ");
        scanf("%f", &s[*count].cost);

        b->remainingMoney -= s[*count].cost;
        printf("You spent %.2f on %s. Remaining money: %.2f\n", s[*count].cost, s[*count].nameItem, b->remainingMoney);

        (*count)++;

        printf("Do you want to record another spending? (y/n): ");
        scanf(" %c", &cont);
    } while (cont == 'y' && *count < 200);
}

void viewSpendingSummary(struct spendMoney s[], int count) {
    float totalSpent = 0;
    printf("\n\t*** Spending Summary ***\n");
    printf("%-20s %-10s\n", "Item", "Cost");
    printf("--------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s %.2f\n", s[i].nameItem, s[i].cost);
        totalSpent += s[i].cost;
    }
    printf("--------------------------------\n");
    printf("Total Spent: %.2f\n", totalSpent);
}

void saveBudgetPlanToFile(const struct budgetplan *b) {
    FILE *fptr = fopen("BudgetPlan.txt", "w");
    if (fptr == NULL) {
        printf("Error: Unable to save budget plan.\n");
        return;
    }
    fprintf(fptr, "%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n", b->income, b->savingsTarget, b->food, b->accommodation, b->healthcare, b->education, b->clothing, b->entertainment, b->remainingMoney);
    fclose(fptr);
}

void loadBudgetPlanFromFile(struct budgetplan *b) {
    FILE *fptr = fopen("BudgetPlan.txt", "r");
    if (fptr == NULL) {
        printf("No existing budget plan found. Please create a new one.\n");
        return;
    }
    fscanf(fptr, "%f %f %f %f %f %f %f %f %f", &b->income, &b->savingsTarget, &b->food, &b->accommodation, &b->healthcare, &b->education, &b->clothing, &b->entertainment, &b->remainingMoney);
    fclose(fptr);
    printf("Budget plan loaded successfully.\n");
}

void loadSpendingFromFile(struct spendMoney s[], int *count) {
    FILE *fptr = fopen("SpendMoney.txt", "r");
    if (fptr == NULL) {
        printf("No previous spending records found.\n");
        return;
    }
    
    while (fscanf(fptr, "%s %f", s[*count].nameItem, &s[*count].cost) == 2) {
        (*count)++;
        if (*count >= 200) break;  // Ensure you don't exceed the array size
    }

    fclose(fptr);
    printf("Spending records loaded successfully.\n");
}
void saveSpendingToFile(struct spendMoney s[], int count) {
    FILE *fptr = fopen("SpendMoney.txt", "w");
    if (fptr == NULL) {
        printf("Error: Unable to save spending records.\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(fptr, "%s %.2f\n", s[i].nameItem, s[i].cost);
    }
    
    fclose(fptr);
    printf("Spending records saved successfully.\n");
}
