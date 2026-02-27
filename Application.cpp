#include "Application.h"
#include "InvestmentData.h"
#include "InvestmentCalculator.h"
#include "ReportPrinter.h"

#include <iostream>
#include <limits>

double Application::PromptPositiveDouble(const char* promptText) {
    double value = 0.0;

    while (true) {
        std::cout << promptText;
        std::cin >> value;

        if (std::cin.fail() || value <= 0.0) {
            std::cout << "Please enter a positive number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

int Application::PromptPositiveInt(const char* promptText) {
    int value = 0;

    while (true) {
        std::cout << promptText;
        std::cin >> value;

        if (std::cin.fail() || value <= 0) {
            std::cout << "Please enter a positive whole number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

void Application::Run() {
    bool keepRunning = true;

    while (keepRunning) {
        std::cout << "**********************************\n";
        std::cout << "********** Airgead Banking ********\n";
        std::cout << "**********************************\n\n";

        // Input prompt screen
        std::cout << "Initial Investment Amount: ";
        double initialInvestment = PromptPositiveDouble("");
        std::cout << "Monthly Deposit: ";
        double monthlyDeposit = PromptPositiveDouble("");
        std::cout << "Annual Interest (%): ";
        double annualInterest = PromptPositiveDouble("");
        std::cout << "Number of Years: ";
        int numberOfYears = PromptPositiveInt("");

        std::cout << "Press Enter to continue...";
        std::cin.get();

        // Setup data and calculator
        InvestmentData data(initialInvestment, monthlyDeposit, annualInterest, numberOfYears);
        InvestmentCalculator calculator(data);
        ReportPrinter printer;

        // Calculate and display report without monthly deposits
        calculator.CalculateWithoutDeposits();
        printer.DisplayReportWithoutDeposits(calculator.GetRecordsWithoutDeposits());

        // Calculate and display report with monthly deposits
        calculator.CalculateWithDeposits();
        printer.DisplayReportWithDeposits(calculator.GetRecordsWithDeposits());

        // Ask user to run another simulation
        char choice = 'n';
        std::cout << "Would you like to run another simulation? (y/n): ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice != 'y' && choice != 'Y') {
            keepRunning = false;
        }

        std::cout << "\n";
    }

    std::cout << "Thank you for using Airgead Banking.\n";
}