#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <utility>


struct EmployeeIDCard
{
private:
    friend class HRManager;

    std::string companyName;
    unsigned int ID;
    std::string fullName;
    std::string position;

public:
    EmployeeIDCard() = default;


    EmployeeIDCard(
        std::string companyName,
        unsigned int ID,
        std::string fullName,
        std::string position
    ) : companyName(std::move(companyName)),
        ID(ID),
        fullName(std::move(fullName)),
        position(std::move(position))
    {
    }


    [[nodiscard]] double getID() const;


    [[nodiscard]] const std::string& getFullName() const;


    [[nodiscard]] const std::string& getPosition() const;


    [[nodiscard]] const std::string& getCompanyName() const;


    void display() const;


    friend std::ostream& operator<<(
        std::ostream& os,
        const EmployeeIDCard& IDCard
    );


    friend std::istream& operator>>(std::istream& is, EmployeeIDCard& IDCard);
};
