#ifndef EXPENSE_H
#define EXPENSE_H

//main struct
struct expense {
  char description[100];
  double amount;
  char category[50];
  char date[9];
  char time[6];
};

//max expenses in one system
#define MAX_EXPENSES 1000

//prototypes (allthe functions signatures)
void promptExpenseDetails(struct expense* target);
void setTimestamp(struct expense* target);
int setCategory(void);
void addCategory(struct expense* target);
void getCategoryTotal(struct expense expenses[MAX_EXPENSES],int expenseCount);
double sumCategory(struct expense expenses[],int expenseCount, const char category[]);
int loadExpenses(struct expense expenses[MAX_EXPENSES], int expenseCount);
void saveExpense(struct expense expenses[MAX_EXPENSES], int expenseCount);
void addExpense(struct expense expenses[MAX_EXPENSES], int expenseCount);
void viewExpense(struct expense expenses[MAX_EXPENSES], int expenseCount);
void totalExpenses(struct expense expenses[MAX_EXPENSES], int expenseCount);
void seeExpenses(struct expense expenses[MAX_EXPENSES], int expenseCount);
int deleteExpense(struct expense expenses[MAX_EXPENSES], int expenseCount);
int editExpense(struct expense expenses[MAX_EXPENSES], int expenseCount);
void rewriteExpenses(struct expense expenses[MAX_EXPENSES], int expenseCount);



#endif