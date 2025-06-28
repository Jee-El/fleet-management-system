#pragma once
#include <string>
#include <memory>
#include <vector>
#include "ForwardDeclarations.h"
#include "CompanyBusinessCard.h"
#include "HRManager.h"

class CEO
{
private:
    std::string fullName;
    std::vector<std::shared_ptr<Company>> companies;

public:
    CEO() = default;

    explicit CEO(std::string fullName)
        : fullName(std::move(fullName))
    {
    }

    [[nodiscard]] const std::string& getFullName() const;

    void launchCompany(CompanyBusinessCard IDCard);

    [[nodiscard]] std::shared_ptr<Company> getCompany(
        const std::string& name
    ) const;

    void setFullName(std::string fullName);

    void setCompanyBusinessCard(
        const std::string& companyName,
        CompanyBusinessCard businessCard
    );

    void setHRManagerFor(HRManager&& managerOfHR, const std::string& name);

    void makeFleetFor(Fleet&& fleet, const std::string& name);

    void shutDownCompany(const std::string& name);

    friend std::istream& operator>>(std::istream& is, CEO& ceo);
};
