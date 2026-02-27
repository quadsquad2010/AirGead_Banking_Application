#include "InvestmentCalculator.h"

InvestmentCalculator::InvestmentCalculator(const InvestmentData& data)
    : m_data(data) {
}

// Calculate monthly interest using:
// (Opening Amount + Deposited Amount) * ((Interest Rate / 100) / 12)
double InvestmentCalculator::CalculateMonthlyInterest(double openingAmount,
                                                      double depositedAmount) const {
    double monthlyRate = (m_data.GetAnnualInterestRate() / 100.0) / 12.0;
    return (openingAmount + depositedAmount) * monthlyRate;
}

void InvestmentCalculator::CalculateWithoutDeposits() {
    m_recordsWithoutDeposits.clear();

    double openingAmount = m_data.GetInitialInvestment();
    double depositedAmount = 0.0;
    double yearlyInterest = 0.0;
    int totalMonths = m_data.GetTotalMonths();

    for (int month = 1; month <= totalMonths; ++month) {
        double interest = CalculateMonthlyInterest(openingAmount, depositedAmount);
        openingAmount += interest;
        yearlyInterest += interest;

        if (month % 12 == 0) {
            YearlyRecord record;
            record.year = month / 12;
            record.yearEndBalance = openingAmount;
            record.yearEndInterest = yearlyInterest;
            m_recordsWithoutDeposits.push_back(record);
            yearlyInterest = 0.0;
        }
    }
}

void InvestmentCalculator::CalculateWithDeposits() {
    m_recordsWithDeposits.clear();

    double openingAmount = m_data.GetInitialInvestment();
    double monthlyDeposit = m_data.GetMonthlyDeposit();
    double yearlyInterest = 0.0;
    int totalMonths = m_data.GetTotalMonths();

    for (int month = 1; month <= totalMonths; ++month) {
        openingAmount += monthlyDeposit;
        double interest = CalculateMonthlyInterest(openingAmount, monthlyDeposit);
        openingAmount += interest;
        yearlyInterest += interest;

        if (month % 12 == 0) {
            YearlyRecord record;
            record.year = month / 12;
            record.yearEndBalance = openingAmount;
            record.yearEndInterest = yearlyInterest;
            m_recordsWithDeposits.push_back(record);
            yearlyInterest = 0.0;
        }
    }
}

const std::vector<YearlyRecord>& InvestmentCalculator::GetRecordsWithoutDeposits() const {
    return m_recordsWithoutDeposits;
}

const std::vector<YearlyRecord>& InvestmentCalculator::GetRecordsWithDeposits() const {
    return m_recordsWithDeposits;
}