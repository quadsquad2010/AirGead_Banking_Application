#ifndef INVESTMENT_CALCULATOR_H
#define INVESTMENT_CALCULATOR_H

#include <vector>
#include "InvestmentData.h"
#include "YearlyRecord.h"

// InvestmentCalculator Class Definition
class InvestmentCalculator {
public:
    InvestmentCalculator(const InvestmentData& data);

    void CalculateWithoutDeposits();
    void CalculateWithDeposits();

    const std::vector<YearlyRecord>& GetRecordsWithoutDeposits() const;
    const std::vector<YearlyRecord>& GetRecordsWithDeposits() const;

private:
    double CalculateMonthlyInterest(double openingAmount, double depositedAmount) const;

    InvestmentData m_data;
    std::vector<YearlyRecord> m_recordsWithoutDeposits;
    std::vector<YearlyRecord> m_recordsWithDeposits;
};

#endif