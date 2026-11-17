#include "Vi.h"

Vi::Vi(const std::string& varietat, ColorVi color)
    : varietat(varietat), color(color) {}

const std::string& Vi::obteVarietat() const {
    return varietat;
}

ColorVi Vi::obteColor() const {
    return color;
}

bool Vi::operator<(const Vi& altre) const {
    if (varietat != altre.varietat) return varietat < altre.varietat;
    return static_cast<int>(color) < static_cast<int>(altre.color);
}
