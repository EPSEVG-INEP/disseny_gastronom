#ifndef PLAT_H
#define PLAT_H

#include <map>
#include <optional>
#include <set>
#include <string>
#include <utility>

#include "Enumeracions.h"
#include "Vi.h"

// Classe Plat: només el plat coneix els vins amb què combina.
class Plat {
public:
    using Combinacions = std::map<
        std::string,
        std::set<std::pair<std::string, std::string>>
    >;

private:
    std::string nomP;
    std::set<Mes> temporada; // sense elements: disponible tot l'any
    std::set<Vi> vins;

public:
    Plat(const std::string& nomP,
         const std::set<Mes>& temporada);

    const std::string& obteNom() const;
    void combinaVi(const Vi& vi);

    // Afegeix al resultat el plat i els vins que hi combinen, si és de temporada.
    void afegeixSiTemporada(Combinacions& resultat, Mes mes) const;
};

#endif
