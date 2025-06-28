#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <utility>

struct CompanyBusinessCard
{
private:
    std::string name;
    std::string address;
    std::string phoneNumber;
    std::string email;

public:
    CompanyBusinessCard() = default;

    CompanyBusinessCard(
        std::string name,
        std::string address,
        std::string phoneNumber,
        std::string email
    ) : name(std::move(name)),
        address(std::move(address)),
        phoneNumber(std::move(phoneNumber)),
        email(std::move(email))
    {
    }

    [[nodiscard]] const std::string& getName() const;

    [[nodiscard]] const std::string& getAddress() const;

    [[nodiscard]] const std::string& getPhoneNumber() const;

    [[nodiscard]] const std::string& getEmail() const;

    void updateName(std::string newName);

    void updateAddress(std::string newAddress);

    void updatePhoneNumber(std::string newPhoneNumber);

    void updateEmail(std::string newEmail);

    void display() const;

    friend std::ostream& operator<<(
        std::ostream& os,
        const CompanyBusinessCard& BC
    );

    friend std::istream& operator>>(std::istream& is, CompanyBusinessCard& BC);
};
