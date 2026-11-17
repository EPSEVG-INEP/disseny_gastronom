#include "CapaDeDomini.h"

#include <stdexcept>

#include "CapaDeDades.h"
#include "FuncionsDomini.h"

CapaDeDomini& CapaDeDomini::instancia() {
    static CapaDeDomini domini;
    return domini;
}

void CapaDeDomini::combina(const std::string& nomP,
                          const std::string& varV,
                          const std::string& colV) {
    ColorVi color;
    if (colV == "blanc") color = ColorVi::BLANC;
    else if (colV == "negre") color = ColorVi::NEGRE;
    else if (colV == "rosat") color = ColorVi::ROSAT;
    else throw std::runtime_error("colorViNoValid");

    Plat& plat = CapaDeDades::instancia().obtePlat(nomP);
    const Vi& vi = CapaDeDades::instancia().obteVi(varV, color);
    plat.combinaVi(vi);
}

Plat::Combinacions CapaDeDomini::combinacionsTemporada() const {
    Plat::Combinacions resultat;
    const Mes mes = mesActual();

	// Es demana a la capa de dades per obtenir tots els plats i, per a cada plat, afegim al resultat els vins amb què combina si és de temporada.
    for (const auto& entrada : CapaDeDades::instancia().totsPlats()) {
        entrada.second.afegeixSiTemporada(resultat, mes);
    }
    return resultat;
}
