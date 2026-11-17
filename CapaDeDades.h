#ifndef CAPA_DE_DADES_H
#define CAPA_DE_DADES_H

#include <map>
#include <string>
#include <utility>

#include "Plat.h"
#include "Vi.h"

// Capa de dades: emmagatzematge en memòria per a aquesta aplicació de consola.
class CapaDeDades {
private:
    std::map<std::string, Plat> plats;
    std::map<std::pair<std::string, ColorVi>, Vi> vins;

    CapaDeDades();

public:
    CapaDeDades(const CapaDeDades&) = delete;
    CapaDeDades& operator=(const CapaDeDades&) = delete;

    static CapaDeDades& instancia();

    Plat& obtePlat(const std::string& nomP);
    const Vi& obteVi(const std::string& varietat, ColorVi color) const;
    const std::map<std::string, Plat>& totsPlats() const;
};

#endif
