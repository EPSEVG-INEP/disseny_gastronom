#include "CapaDeDades.h"

#include <stdexcept>

CapaDeDades::CapaDeDades() {
    // Dades d'exemple per poder provar les operacions a classe.
    vins.emplace(std::make_pair("Xarel·lo", ColorVi::BLANC),
                 Vi("Xarel·lo", ColorVi::BLANC));
    vins.emplace(std::make_pair("Txakolí", ColorVi::BLANC),
                 Vi("Txakolí", ColorVi::BLANC));
    vins.emplace(std::make_pair("Cava", ColorVi::BLANC),
                 Vi("Cava", ColorVi::BLANC));
    vins.emplace(std::make_pair("Cabernet Sauvignon", ColorVi::NEGRE),
                 Vi("Cabernet Sauvignon", ColorVi::NEGRE));
    vins.emplace(std::make_pair("Garnacha", ColorVi::NEGRE),
                 Vi("Garnacha", ColorVi::NEGRE));
    vins.emplace(std::make_pair("Rosat de la casa", ColorVi::ROSAT),
                 Vi("Rosat de la casa", ColorVi::ROSAT));

    plats.emplace("Esqueixada", Plat("Esqueixada",
        std::set<Mes>{Mes::JUNY, Mes::JULIOL, Mes::AGOST, Mes::SETEMBRE}));
    plats.emplace("Entrecot amb patates",
        Plat("Entrecot amb patates", std::set<Mes>()));
    plats.emplace("Escudella", Plat("Escudella",
        std::set<Mes>{Mes::GENER, Mes::FEBRER, Mes::NOVEMBRE, Mes::DESEMBRE}));

    plats.at("Esqueixada").combinaVi(vins.at({"Xarel·lo", ColorVi::BLANC}));
    plats.at("Esqueixada").combinaVi(vins.at({"Txakolí", ColorVi::BLANC}));
    plats.at("Esqueixada").combinaVi(vins.at({"Cava", ColorVi::BLANC}));
    plats.at("Entrecot amb patates").combinaVi(
        vins.at({"Cabernet Sauvignon", ColorVi::NEGRE}));
    plats.at("Entrecot amb patates").combinaVi(vins.at({"Garnacha", ColorVi::NEGRE}));
    plats.at("Escudella").combinaVi(vins.at({"Garnacha", ColorVi::NEGRE}));
}

CapaDeDades& CapaDeDades::instancia() {
    static CapaDeDades dades;
    return dades;
}

Plat& CapaDeDades::obtePlat(const std::string& nomP) {
    auto it = plats.find(nomP);
    if (it == plats.end()) throw std::runtime_error("platNoExisteix");
    return it->second;
}

const Vi& CapaDeDades::obteVi(const std::string& varietat, ColorVi color) const {
    auto it = vins.find({varietat, color});
    if (it == vins.end()) throw std::runtime_error("viNoExisteix");
    return it->second;
}

const std::map<std::string, Plat>& CapaDeDades::totsPlats() const {
    return plats;
}
