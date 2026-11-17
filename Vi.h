#ifndef VI_H
#define VI_H

#include <string>
#include "Enumeracions.h"

// Classe Vi: varietat i color identifiquen un vi.
class Vi {
private:
    std::string varietat;
    ColorVi color;

public:
    Vi(const std::string& varietat, ColorVi color);

    const std::string& obteVarietat() const;
    ColorVi obteColor() const;

    bool operator<(const Vi& altre) const;
};

#endif
