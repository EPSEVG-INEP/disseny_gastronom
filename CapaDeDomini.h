#ifndef CAPA_DE_DOMINI_H
#define CAPA_DE_DOMINI_H

#include <string>

#include "Plat.h"

// Capa de domini: coordina les operacions i aplica les regles del domini.
class CapaDeDomini {
private:
    CapaDeDomini() = default;

public:
    CapaDeDomini(const CapaDeDomini&) = delete;
    CapaDeDomini& operator=(const CapaDeDomini&) = delete;

    static CapaDeDomini& instancia();

    void combina(const std::string& nomP, const std::string& varV, const std::string& colV);
    Plat::Combinacions combinacionsTemporada() const;
};

#endif
