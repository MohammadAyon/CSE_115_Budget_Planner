#include<stdio.h>
#include<stdlib.h>

struct budgetplan
{
    float income;
    float savingsTarget;
    float food;
    float accommodion;
    float healthcare;
    float education;
    float clothing;
    float entertainment;
    float totalexpenditure;
    float differenceMoney;
};


struct spendMoney
{
    char nameItem[50];
    float cost;
};

/*struct calcMoney
{
    float remainingMoney;
    float moneySpent;
};*/


float add(float x,float y);
float subs(float x, float y);

void writeBudgetPlan(struct budgetplan s);
void writeSpendMoney(struct spendMoney s[], int x);
void readBudgetplan();


int main(void)
{
    FILE *fp1;
    struct budgetplan emp;
    struct spendMoney spm1[200];
    //struct calcMoney cm;
    float remaingMoney, moneySpent;
    int button1,button2,button3,button4,i=0,j,k=1;


    do
    {
        printf(" \n\t\t ***Welcome to our Budget System App***\n\n");
        printf("1.Create new Budget Plan.\n");
        printf("2.Work with existing budget plan.\n");
        printf("3.Quit\n");
        printf("Press 1,2 or 3 to execute the above-mentioned function:");
        scanf("%d",&button1);
        switch(button1)
        {
        case 1:
            do
            {
                printf("\n\t\t***You Have Opted to Create a New Budget Plan***\n\n ");
                printf("\nEnter  your income :");
                scanf("%f",&emp.income);
                printf("\nThe amount of money you wanted to save :");
                scanf("%f",&emp.savingsTarget);
                printf("\n\n\t\t***Allocate Budget in Different Sectors ***\n\n ");
                printf("\nFood:");
                scanf("%f",&emp.food);
                printf("\nAccommodation:");
                scanf("%f",&emp.accommodion);
                printf("\nHealth care:");
                scanf("%f",&emp.healthcare);
                printf("\nEducation:");
                scanf("%f",&emp.education);
                printf("\nclothing:");
                scanf("%f",&emp.clothing);
                printf("\nEntertainment:");
                scanf("%f",&emp.entertainment);

                emp.differenceMoney = subs(emp.income,emp.savingsTarget);
                emp.totalexpenditure = add(emp.food,emp.accommodion)+add(emp.healthcare,emp.education)+add(emp.clothing,emp.entertainment);

                if(emp.totalexpenditure>emp.differenceMoney)
                {
                    printf("\n\tYour expenditure is too much !!!\n\tPlease re-enter the value!\n\tPress any digit to continue: ");
                    scanf("%d",&button4);

                }
                else if(emp.differenceMoney>emp.totalexpenditure)
                {
                    emp.savingsTarget += subs(emp.differenceMoney,emp.totalexpenditure);
                    printf("\nWith this budget plan you can save extra %.2f Tk. and your savings target will be %.2f Tk.",subs(emp.differenceMoney,emp.totalexpenditure),emp.savingsTarget);
                    writeBudgetPlan(emp);

                    printf("\nPress any digit to continue: ");
                    scanf("%d",&button4);

                }
                else
                {
                    writeBudgetPlan(emp);
                }

            }while(emp.totalexpenditure>emp.differenceMoney);
            break;
        case 2:
            do
            {
                printf("\n\n\t\t***You have opted to use existing budget plan***\n\n");
                printf("1.View your budget plan.\n");
                printf("2.Spend money and keep record.\n");
                printf("3.View your list of spending.\n");
                printf("4.Go to the main menu");
                printf("\n\nPress 1,2,3 or 4 to execute the above-mentioned functions:");
                scanf("%d",&button2);

                if(button2==1)
                {

                    readBudgetplan();

                }
                else if(button2==2)
                {

                     do{
                            printf("\n\n\t\t***You are now spending your Money.***\n\n");
                            fflush(stdin);
                            printf("Name of item you are spending money on:");
                            gets(spm1[i].nameItem);
                            fflush(stdin);
                            printf("The cost of the item:");
                            scanf("%f", &spm1[i].cost);
                            printf("You have spent %.2f money on %s.\n",spm1[i].cost,spm1[i].nameItem);
                            moneySpent += spm1[i].cost;
                            printf("Your total money spent is %.2f\n", moneySpent);
                            remaingMoney = emp.totalexpenditure - moneySpent;
                            printf("Your remaining money is %.2f\n", remaingMoney);

                            printf("Press 0 to go back or any other digit to continue:");
                            scanf("%d",&button3);

                            i++;

                        }while(i<200 && button3!=0);

                        writeSpendMoney(spm1, i);

                }
                /*else if(button2==3)
                {

                }
                else if(button2==4)
                {

                }
                else
                {
                    printf("\nInvalid Entry ! Try again\n!");
                }*/

            }while(button2!=4);

            break;
        case 3:

            break;

        default:

            printf("Invalid Entry ! please try again!\n\n");

        }

    }while(button1!=3);

    return 0;
}
float add(float x,float y)
{
    float z;
    z=x+y;
    return z;
}
float subs(float x,float y)
{
    float z;
    if(x>y)
    {
        z=x-y;
    }
    else
    {
        z=y-x;
    }

    return z;

}
void writeBudgetPlan(struct budgetplan s)
{
    FILE *fptr;
    fptr = fopen("BudgetPlan.txt", "w");
    fprintf(fptr,"%.2f\n",s.income);
    fprintf(fptr,"%.2f\n",s.savingsTarget);
    fprintf(fptr,"%.2f\n",s.food);
    fprintf(fptr,"%.2f\n",s.accommodion);
    fprintf(fptr,"%.2f\n",s.healthcare);
    fprintf(fptr,"%.2f\n",s.education);
    fprintf(fptr,"%.2f\n",s.clothing);
    fprintf(fptr,"%.2f\n",s.entertainment);
    //fprintf(fptr,"%.2f\n",);
    //fprintf(fptr,"%.2f\n",);
    fclose(fptr);
}
void writeSpendMoney(struct spendMoney s[],int x)
{
    FILE *fptr;
    int i;
    fptr = fopen("SpendMoney.txt", "a");
    for(i=0;i<x;i++)
    {
        fprintf(fptr,"%s\n",s[i].nameItem);
        fprintf(fptr,"%.2f\n",s[i].cost);
    }
    fclose(fptr);
}
void readBudgetplan()
{
    struct budgetplan r;
    FILE *fptr;
    fptr=fopen("BudgetPlan.txt","r");
    printf("\n\n\t\t***This is your budget plan***");
    fscanf(fptr,"%f", &r.income);
    printf("\nTotal Income: %.2f", r.income);
    fscanf(fptr,"%f",&r.savingsTarget);
    printf("\nSaving target: %.2f", r.savingsTarget);

    printf("\n\n\t\t***Budget allocation in different sectors***");
    fscanf(fptr,"%f", &r.food);
    printf("\n\nFood: %.2f", r.food);
    fscanf(fptr,"%f", &r.accommodion);
    printf("\nAccommodation:%.2f", r.accommodion);
    fscanf(fptr,"%f", &r.healthcare);
    printf("\nHealth care: %.2f", r.healthcare);
    fscanf(fptr,"%f", &r.education);
    printf("\nEducation: %.2f", r.education);
    fscanf(fptr,"%f", &r.clothing);
    printf("\nClothing: %.2f", r.clothing);
    fscanf(fptr,"%f", &r.entertainment);
    printf("\nEntertainment: %.2f", r.entertainment);
    fclose(fptr);

}