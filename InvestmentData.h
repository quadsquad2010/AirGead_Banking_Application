#ifndef INVESTMENT_DATA_H
#define INVESTMENT_DATA_H

// InvestmentData Class Definition
class InvestmentData {
public:
    InvestmentData();
    InvestmentData(double initialInvestment,
                   double monthlyDeposit,
                   double annualInterestRate,
                   int numberOfYears);

    // Getter Methods
    double GetInitialInvestment() const;
    double GetMonthlyDeposit() const;
    double GetAnnualInterestRate() const;
    int GetNumberOfYears() const;
    int GetTotalMonths() const;

    // Setter Methods
    void SetInitialInvestment(double value);
    void SetMonthlyDeposit(double value);
    void SetAnnualInterestRate(double value);
    void SetNumberOfYears(int value);

    // InvestmentData Members
private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterestRate;
    int m_numberOfYears;
};

#endif