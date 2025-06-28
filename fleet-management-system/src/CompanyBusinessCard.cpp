#include "CompanyBusinessCard.h"


const std::string& CompanyBusinessCard::getName() const
{
    return name;
}


const std::string& CompanyBusinessCard::getAddress() const
{
    return address;
}


const std::string& CompanyBusinessCard::getPhoneNumber() const
{
    return phoneNumber;
}


const std::string& CompanyBusinessCard::getEmail() const
{
    return email;
}


void CompanyBusinessCard::updateName(std::string newName)
{
    this->name = std::move(newName);
}


void CompanyBusinessCard::updateAddress(std::string newAddress)
{
    this->address = std::move(newAddress);
}


void CompanyBusinessCard::updatePhoneNumber(std::string newPhoneNumber)
{
    this->phoneNumber = std::move(newPhoneNumber);
}


void CompanyBusinessCard::updateEmail(std::string newEmail)
{
    this->email = std::move(newEmail);
}


void CompanyBusinessCard::display() const
{
    std::cout << std::left << std::setw(15) << "Company Name" << " | "
        << std::setw(8) << "Address" << " | "
        << std::setw(20) << "Phone Number" << " | "
        << std::setw(20) << "Email" << "\n"
        << "---------------------------------------------------------" <<
        std::endl;
    std::cout << *this;
}


std::ostream& operator<<(std::ostream& os, const CompanyBusinessCard& BC)
{
    os << std::setw(15) << BC.name << " | "
        << std::setw(8) << BC.address << " | "
        << std::setw(20) << BC.phoneNumber << " | "
        << std::setw(20) << BC.email << " | ";
    return os;
}


std::istream& operator>>(std::istream& is, CompanyBusinessCard& BC)
{
    std::cout << "Enter Company Name: ";
    std::getline(is, BC.name);
    std::cout << "Enter Company Address: ";
    std::getline(is, BC.address);
    std::cout << "Enter Company Phone: ";
    std::getline(is, BC.phoneNumber);
    std::cout << "Enter Company Email: ";
    std::getline(is, BC.email);
    return is;
}
