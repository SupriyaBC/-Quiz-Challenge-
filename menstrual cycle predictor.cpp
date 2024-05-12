#include <iostream>
#include <vector>
#include <string>
#include <ctime>

void predictNextCycleDate(const std::vector<std::string>& cycleDates) {
    if (cycleDates.size() != 3) {
        std::cout << "Please provide dates for exactly three previous menstrual cycles." << std::endl;
        return;
    }

    std::vector<time_t> cycleTimes;

    // Convert string dates to time_t
    for (const auto& date : cycleDates) {
        struct tm cycleDate;
        sscanf(date.c_str(), "%d-%d-%d", &cycleDate.tm_year, &cycleDate.tm_mon, &cycleDate.tm_mday);
        cycleDate.tm_year -= 1900;
        cycleDate.tm_mon--;
        cycleDate.tm_hour = 12;  // Assuming the cycle starts at noon
        cycleDate.tm_min = 0;
        cycleDate.tm_sec = 0;
        cycleTimes.push_back(mktime(&cycleDate));
    }

    // Calculate average cycle length in seconds
    int cycle1Length = cycleTimes[1] - cycleTimes[0];
    int cycle2Length = cycleTimes[2] - cycleTimes[1];
    int averageCycleLength = (cycle1Length + cycle2Length) / 2;

    // Predict next cycle start date based on average cycle length
    time_t nextCycleStartTime = cycleTimes[2] + averageCycleLength;
    struct tm* nextCycleDate = localtime(&nextCycleStartTime);

    std::cout << "Based on your last three menstrual cycles, ";
    std::cout << "the predicted start date of your next menstrual cycle is: ";
    std::cout << nextCycleDate->tm_year + 1900 << '-' << nextCycleDate->tm_mon + 1 << '-' << nextCycleDate->tm_mday << std::endl;
}

int main() {
    std::vector<std::string> cycleDates;
    std::string date;

    std::cout << "Enter the dates of your last three menstrual cycles (YYYY-MM-DD):" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cin >> date;
        cycleDates.push_back(date);
    }

    predictNextCycleDate(cycleDates);

    return 0;
}
