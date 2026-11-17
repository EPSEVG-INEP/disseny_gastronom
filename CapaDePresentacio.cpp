#include "CapaDePresentacio.h"

#include <exception>
#include <iostream>
#include <string>

#include "CapaDeDomini.h"
#include "FuncionsDomini.h"

void CapaDePresentacio::combinaPremerOK() {
    std::string nomP, varietat, color;

	// Demana a l'usuari el nom del plat, la varietat i el color del vi, i crida a la capa de domini per crear la combinació.
    std::cout << "Nom del plat: ";
    std::getline(std::cin, nomP);
    std::cout << "Varietat del vi: ";
    std::getline(std::cin, varietat);
    std::cout << "Color del vi (blanc/negre/rosat): ";
    std::getline(std::cin, color);

    try {
		// Crida a la capa de domini per crear la combinació.
        CapaDeDomini::instancia().combina(nomP, varietat, color);
        std::cout << "Combinacio creada correctament.";

    } catch (const std::exception& e) {
		// Mostra un missatge d'error segons el tipus d'excepció llençada per la capa de domini.
        const std::string error = e.what();
        if (error == "platNoExisteix") std::cout << "El plat no existeix." << std::endl;
        else if (error == "viNoExisteix") std::cout << "El vi no existeix." << std::endl;
        else if (error == "colorViNoValid") std::cout << "El color indicat no es valid." << std::endl;
        else if (error == "combinaExisteix")
            std::cout << "El plat ja combina amb aquest vi." << std::endl;
        else std::cout << "S'ha produit un error: " << error << std::endl;
    }
}

void CapaDePresentacio::combinacionsTemporadaInici() const {
	// Crida a la capa de domini per obtenir les combinacions de temporada i les mostra per pantalla.
    const auto combinacions = CapaDeDomini::instancia().combinacionsTemporada();

	// Sortida per pantalla de les combinacions de temporada.
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Combinacions de temporada (" << nomMes(mesActual()) << ")" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    if (combinacions.empty()) {
        std::cout << "No hi ha plats de temporada." << std::endl;
        return;
    }

    for (const auto& plat : combinacions) {
        std::cout << plat.first << ": ";
        if (plat.second.empty()) {
            std::cout << "cap vi associat" << std::endl;
        } else {
            bool primer = true;
            for (const auto& vi : plat.second) {
                if (!primer) std::cout << "; ";
                std::cout << vi.first << ", " << vi.second;
                primer = false;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

void CapaDePresentacio::inicia() {
    std::string opcio;
    do {
        std::cout << "===================================" << std::endl;
        std::cout << "=== Exquisiteses gastronomiques ===" << std::endl;
        std::cout << "===================================" << std::endl;
        std::cout << "1. Combina un plat amb un vi" << std::endl;
        std::cout << "2. Consulta les combinacions de temporada" << std::endl;
		std::cout << "0. Sortir" << std::endl;
        std::cout << "Opcio: ";
        std::getline(std::cin, opcio);

        if (opcio == "1") combinaPremerOK();
        else if (opcio == "2") combinacionsTemporadaInici();
        else if (opcio != "0") std::cout << "Opcio no valida.\\n";
    } while (opcio != "0");
}
