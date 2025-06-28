#include "CEO.h"


const std::string& CEO::getFullName() const
{
    return fullName;
}


void CEO::setFullName(std::string fullName)
{
    this->fullName = std::move(fullName);
}


void CEO::setCompanyBusinessCard(
    const std::string& companyName,
    CompanyBusinessCard businessCard
)
{
    getCompany(companyName)->businessCard = std::move(businessCard);
}


void CEO::launchCompany(CompanyBusinessCard IDCard)
{
    this->companies.push_back(
        std::make_shared<Company>(std::move(IDCard))
    );
}


std::shared_ptr<Company> CEO::getCompany(const std::string& name) const
{
    for (auto& company : this->companies)
    {
        if (company->getBusinessCard().getName() == name)
        {
            return {company};
        }
    }
    throw std::invalid_argument("Company not found");
}


void CEO::setHRManagerFor(HRManager&& managerOfHR, const std::string& name)
{
    auto company = this->getCompany(name);
    managerOfHR.company = company;
    company->managerOfHR = std::make_shared<HRManager>(
        std::move(managerOfHR)
    );
}


void CEO::makeFleetFor(Fleet&& fleet, const std::string& name)
{
    this->getCompany(name)->fleet = std::make_shared<Fleet>(std::move(fleet));
}


void CEO::shutDownCompany(const std::string& name)
{
    auto company = this->getCompany(name);

    auto byName = [company](const std::shared_ptr<Company>& c)
    {
        return c->getBusinessCard().getName() == company->getBusinessCard().
            getName();
    };

    this->companies.erase(
        std::remove_if(
            this->companies.begin(),
            this->companies.end(),
            byName
        ),
        this->companies.end()
    );
}


std::istream& operator>>(std::istream& is, CEO& ceo)
{
    std::cout << "Enter Full Name: ";
    std::getline(is, ceo.fullName);
    return is;
}
