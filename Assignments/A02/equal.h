#include "cs136.h"

// SEASHELL_READONLY
//
// Version 1.0

// EPSILON is an accuracy threshold that can be used to check whether the
// result of a function is accurate enough: if the difference between the
// returned and the expected value is smaller than EPSILON, the function
// would be considered accurate enough.
extern const double EPSILON;

// is_almost_equal() checks if the difference between value and target does not
// exceed a certain threshold. If so, the function returns true; if the
// difference between value and target is too large, the function returns false.
bool is_almost_equal(const double value, const double target);
