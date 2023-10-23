#include <iostream>
#include <string>
#include <stdexcept>

class ElectricityBill {
private:
    double costPerKWh;
    int hours;
    std::string date;
    double amountPaid;

public:
    ElectricityBill(double cost, int hrs, std::string dt, double paid)
        : costPerKWh(cost), hours(hrs), date(dt), amountPaid(paid) {}

    ElectricityBill& operator++() {
        hours++;
        amountPaid += costPerKWh;
        return *this;
    }

    ElectricityBill& operator-=(int hoursToSubtract) {
        if (hoursToSubtract < 0) {
            throw std::invalid_argument("Негативні години не можна відняти.");
        }
        if (hours >= hoursToSubtract) {
            hours -= hoursToSubtract;
            amountPaid -= costPerKWh * hoursToSubtract;
        }
        else {
            throw std::out_of_range("Віднімається більше годин, ніж доступно.");
        }
        return *this;
    }

   bool isOnDate( std::string& searchDate)  {
        return date == searchDate;
    }


 bool isOnDate(int year, int month, int day)  {
        std::string searchDate = std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day);
        return date == searchDate;
    }


 

    void printInfo() {
        std::cout << "Дата: " << date << "\n";
        std::cout << "Години: " << hours << "\n";
        std::cout << "Вартість кВт*год: " << costPerKWh << "\n";
        std::cout << "Сплачена сума: " << amountPaid << "\n";
    }
};

int main() {
    setlocale(LC_ALL, "Ukrainian");
    ElectricityBill bill(0.1, 100, "2023-10-08", 10.0);

    std::cout << "Початковий рахунок:\n";
    bill.printInfo();

    ++bill;
    std::cout << "Рахунок після збільшення:\n";
    bill.printInfo();

    try {
        bill -= 50;
        std::cout << "Рахунок після зменшення:\n";
        bill.printInfo();
    }
    catch (std::exception& e) {
        std::cerr << "Помилка: " << e.what() << "\n";
    }

    
   if (bill.isOnDate(2023, 10, 8)) {
        std::cout << "Рахунок знайдено за датою 2023-10-08:\n";
        bill.printInfo();
    }
    else {
        std::cout << "Рахунок не знайдено за датою " << searchDate << "\n";
    }

    return 0;
}
