#include "Damage.h"

#include <cmath>  // для std::log2
#include <algorithm>  // для std::max, std::min

namespace DiabroNS {

double F(double fatk, double fdef) {
    if (fdef == 0.0) {
        return 2.0;
    }
    if (fatk == 0.0) {
        return 0.0;
    }
    
    double ratio = fdef / fatk;
    double result = 0.7 - 0.4 * std::log2(ratio);
    
    // Ограничиваем результат в диапазоне [0.0, 2.0]
    return std::max(0.0, std::min(2.0, result));
}

int Damage::Apply(int _atk, int _def)
{
    int damage = _atk * F(_atk, _def) - 0.1 * _def;
    return (damage > 0) ? damage : 0;
}

}   