#include "ReportPrinter.h"
#include <iostream>
#include <iomanip>

// ReportPrinter Implementation
void ReportPrinter::PrintHeaderWithoutDeposits() const {
    std::cout << "  Balance and Interest Without Additional Monthly Deposits\n";
    std::cout << "============================================================\n";
    std::cout << std::left << std::setw(10) << "Year"
              << std::setw(20) << "Year End Balance"
              << std::setw(20) << "Year End Earned Interest" << '\n';
    std::cout << "------------------------------------------------------------\n";
}

// ReportPrinter Implementation
void ReportPrinter::PrintHeaderWithDeposits() const {
    std::cout << "  Balance and Interest With Additional Monthly Deposits\n";
    std::cout << "============================================================\n";
    std::cout << std::left << std::setw(10) << "Year"
              << std::setw(20) << "Year End Balance"
              << std::setw(20) << "Year End Earned Interest" << '\n';
    std::cout << "------------------------------------------------------------\n";
}

// ReportPrinter Implementation
void ReportPrinter::DisplayReportWithoutDeposits(const std::vector<YearlyRecord>& records) const {
    PrintHeaderWithoutDeposits();
    std::cout << std::fixed << std::setprecision(2);

    for (const auto& record : records) {
        std::cout << std::left << std::setw(10) << record.year
                  << "$ " << std::setw(18) << record.yearEndBalance
                  << "$ " << std::setw(18) << record.yearEndInterest << '\n';
    }

    std::cout << '\n';
}

// ReportPrinter Implementation
void ReportPrinter::DisplayReportWithDeposits(const std::vector<YearlyRecord>& records) const {
    PrintHeaderWithDeposits();
    std::cout << std::fixed << std::setprecision(2);

    for (const auto& record : records) {
        std::cout << std::left << std::setw(10) << record.year
                  << "$ " << std::setw(18) << record.yearEndBalance
                  << "$ " << std::setw(18) << record.yearEndInterest << '\n';
    }

    std::cout << '\n';
}