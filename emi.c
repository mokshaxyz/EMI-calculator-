#include <stdio.h>
#include <math.h>

int main() {
    double principal = 5000000.0;
    double annual_interest_rate = 9.0;
    int t = 10;
    int n = t * 12;
    double monthly_interest_rate = annual_interest_rate / 12.0 / 100.0;

    double emi = principal * monthly_interest_rate * (pow(1 + monthly_interest_rate, n) / (pow(1 + monthly_interest_rate, n) - 1));

    printf("The EMI is Rs.: %.2lf\n", emi);

    double loan_amt = principal;
    double remaining_loan = loan_amt;\

    printf("\nPayment Table:\n");

    printf("Month   Year   EMI(Rs.)   Principal(Rs.)   Interest(Rs.)   Remaining Loan(Rs.)\n");

    for (int month = 1, year = 1; month <= n; month++) {
        double interest_amt = remaining_loan * monthly_interest_rate;
        double principal_amt = emi - interest_amt;

        remaining_loan -= principal_amt;

        
        printf("%-8d%-7d%-12.2lf%-17.2lf%-17.2lf%-24.2lf\n", month, year, emi, principal_amt, interest_amt, remaining_loan);

        if (month % 12 == 0) {
            year++;
        }
    }

    return 0;
}