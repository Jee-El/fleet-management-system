#include "EmployeeIDCard.h"


double EmployeeIDCard::getID() const
{
    return ID;
}


const std::string& EmployeeIDCard::getFullName() const
{
    return fullName;
}


const std::string& EmployeeIDCard::getPosition() const
{
    return position;
}


const std::string& EmployeeIDCard::getCompanyName() const
{
    return companyName;
}


void EmployeeIDCard::display() const
{
    std::cout << std::left << std::setw(15) << "Company Name" << " | "
        << std::setw(8) << "ID" << " | "
        << std::setw(20) << "Full Name" << " | "
        << std::setw(20) << "Position" << "\n"
        << "---------------------------------------------------------" <<
        std::endl;
    std::cout << *this << std::endl;
}


std::ostream& operator<<(std::ostream& os, const EmployeeIDCard& IDCard)
{
    os << std::setw(15) << IDCard.companyName << " | "
        << std::setw(8) << IDCard.ID << " | "
        << std::setw(20) << IDCard.fullName << " | "
        << std::setw(20) << IDCard.position << " | ";
    return os;
}


std::istream& operator>>(std::istream& is, EmployeeIDCard& IDCard)
{
    std::cout << "Enter Company Name: ";
    std::getline(is, IDCard.companyName);
    std::cout << "Enter ID (Positive integer): ";
    double tmpID;
    is >> tmpID;
    IDCard.ID = static_cast<unsigned int>(tmpID);
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter Full Name: ";
    std::getline(is, IDCard.fullName);
    std::cout << "Enter Position: ";
    std::getline(is, IDCard.position);
    return is;
}
