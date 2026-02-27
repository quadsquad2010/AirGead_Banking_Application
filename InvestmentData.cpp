#include "InvestmentData.h"

// InvestionData Implementation
InvestmentData::InvestmentData()
    : m_initialInvestment(0.0),
      m_monthlyDeposit(0.0),
      m_annualInterestRate(0.0),
      m_numberOfYears(0) {
}

// InvestmentData Parameterized Constructor
InvestmentData::InvestmentData(double initialInvestment,
                               double monthlyDeposit,
                               double annualInterestRate,
                               int numberOfYears)
    : m_initialInvestment(initialInvestment),
      m_monthlyDeposit(monthlyDeposit),
      m_annualInterestRate(annualInterestRate),
      m_numberOfYears(numberOfYears) {
}

// Getter Methods
double InvestmentData::GetInitialInvestment() const {
    return m_initialInvestment;
}

double InvestmentData::GetMonthlyDeposit() const {
    return m_monthlyDeposit;
}

double InvestmentData::GetAnnualInterestRate() const {
    return m_annualInterestRate;
}

int InvestmentData::GetNumberOfYears() const {
    return m_numberOfYears;
}

int InvestmentData::GetTotalMonths() const {
    return m_numberOfYears * 12;
}

void InvestmentData::SetInitialInvestment(double value) {
    m_initialInvestment = value;
}

void InvestmentData::SetMonthlyDeposit(double value) {
    m_monthlyDeposit = value;
}

void InvestmentData::SetAnnualInterestRate(double value) {
    m_annualInterestRate = value;
}

void InvestmentData::SetNumberOfYears(int value) {
    m_numberOfYears = value;
}