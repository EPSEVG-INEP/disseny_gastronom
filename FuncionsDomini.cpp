#include "FuncionsDomini.h"

#include <ctime>

std::string nomColor(ColorVi color) {
    switch (color) {
        case ColorVi::BLANC: return "blanc";
        case ColorVi::NEGRE: return "negre";
        case ColorVi::ROSAT: return "rosat";
    }
    return "";
}

std::string nomMes(Mes mes) {
    static const std::string noms[] = {
        "", "gener", "febrer", "març", "abril", "maig", "juny",
        "juliol", "agost", "setembre", "octubre", "novembre", "desembre"
    };
    return noms[static_cast<int>(mes)];
}

Mes mesActual() {
    const std::time_t ara = std::time(nullptr);
    std::tm data = {};
#if defined(_MSC_VER)
    localtime_s(&data, &ara);
#else
    std::tm* tmp = std::localtime(&ara);
    if (tmp != nullptr) {
        data = *tmp;
    }
#endif
    return static_cast<Mes>(data.tm_mon + 1);
}
