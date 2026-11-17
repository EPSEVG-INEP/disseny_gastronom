#include "Plat.h"

#include <stdexcept>

#include "FuncionsDomini.h"

Plat::Plat(const std::string& nomP,
           const std::set<Mes>& temporada)
    : nomP(nomP), temporada(temporada) {}

const std::string& Plat::obteNom() const {
    return nomP;
}

void Plat::combinaVi(const Vi& vi) {
    if (vins.find(vi) != vins.end()) {
        throw std::runtime_error("combinaExisteix");
    }
    vins.insert(vi);
}

void Plat::afegeixSiTemporada(Combinacions& resultat, Mes mes) const {
    // primera clàusula de l'OR: Si l'atribut temporada es buit, el Plat s'ofereix tot l'any
	// segona clàusula de l'OR: Si el mes actual és dins de l'atribut temporada, el Plat s'ofereix
    if (temporada.empty() || temporada.find(mes) != temporada.end()) {
		// Si el plat s'oferix, afegim el plat i els vins amb què combina al resultat.
        std::set<std::pair<std::string, std::string>> vinsDelPlat;
        for (const Vi& vi : vins) {
            vinsDelPlat.insert({vi.obteVarietat(), nomColor(vi.obteColor())});
        }
        resultat[nomP] = vinsDelPlat;
    }
}
