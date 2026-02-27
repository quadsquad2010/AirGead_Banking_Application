#ifndef REPORT_PRINTER_H
#define REPORT_PRINTER_H

#include <vector>
#include "YearlyRecord.h"

// ReportPrinter Class Definition
class ReportPrinter {
public:
    void DisplayReportWithoutDeposits(const std::vector<YearlyRecord>& records) const;
    void DisplayReportWithDeposits(const std::vector<YearlyRecord>& records) const;

private:
    void PrintHeaderWithoutDeposits() const;
    void PrintHeaderWithDeposits() const;
};

#endif