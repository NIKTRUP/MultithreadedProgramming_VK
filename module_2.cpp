#include "module_2.h"

namespace module_2{
    std::string derivative(std::string polynomial) {
        std::cmatch polynom_match;
        std::regex reg(R"(([-+]?)([\d]*)([\*]?)([x]?)([\^]?)([\d]*))");
        std::map<std::int32_t, std::int32_t> degree_mult;

        while (std::regex_search(polynomial.c_str(), polynom_match, reg) && !polynomial.empty()){
            if (polynom_match[4] != "") {
                std::int32_t multiplier = (polynom_match[1] == "-") ? -1 : 1,
                             degree = 0;
                multiplier = (polynom_match[2] != "") ? multiplier * std::stoi(polynom_match[2]) : multiplier;

                if (polynom_match[5] != "") {
                    degree = std::stoi(polynom_match[6]);
                    multiplier *= degree--;
                }
                degree_mult[degree] += multiplier;
            }
            polynomial = polynom_match.suffix();
        }
        std::string result;
        for (auto it = degree_mult.rbegin(); it != degree_mult.rend(); ++it) {
            if (!result.empty() && it->second > 0){ result += '+'; }
            result += std::to_string(it->second);
            if (it->first > 0){ result += "*x"; }
            if (it->first > 1){ result += "^" + std::to_string(it->first); }
        }
        return result;
    }
}