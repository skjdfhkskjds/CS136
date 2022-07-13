/////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v3)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement:
// https://student.cs.uwaterloo.ca/~cs136/current/assignments/integrity.shtml
/////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// Name: Colin Chu
// login ID: ckychu
/////////////////////////////////////////////////////////////////////////////

#include "cs136.h"

struct rtnl {
  int num;
  int den;
};
// requires: den != 0

int euclidean_alg(int a, int b) {
    while (b > 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int abs_val(int n) {
    if (n < 0) {
        return -n;
    }
    return n;
}

void rtnl_simplify(struct rtnl *r) {
    if (r->num == 0) {
        return;
    }
    //if denom negative
    if (r->den < 0) {
        r->num *= -1;
        r->den *= -1;
    }
    const int a = abs_val(r->num);
    const int b = abs_val(r->den);
    int gcd = 0;
    if (a > b) {
        gcd = euclidean_alg(a, b);
    }
    else {
        gcd = euclidean_alg(b, a);
    }

    r->num /= gcd;
    r->den /= gcd;
}



struct rtnl rtnl_init(int num, int den) {
    assert(den != 0);
    struct rtnl frac = {num, den};
    rtnl_simplify(&frac);
    return frac;
}



struct rtnl rtnl_add(const struct rtnl *r, const struct rtnl *s) {
    int denom = (r->den * s->den);
    int numer = ((r->num * s->den) + (s->num * r->den));
    struct rtnl frac = rtnl_init(numer, denom);
    rtnl_simplify(&frac);
    return frac;
}



struct rtnl rtnl_sub(const struct rtnl *r, const struct rtnl *s) {
    int denom = (r->den * s->den);
    int numer = ((r->num * s->den) - (s->num * r->den));
    struct rtnl frac = rtnl_init(numer, denom);
    rtnl_simplify(&frac);
    return frac;
}



struct rtnl rtnl_mul(const struct rtnl *r, const struct rtnl *s) {
    int denom = (r->den * s->den);
    int numer = (r->num * s->num);
    struct rtnl frac = rtnl_init(numer, denom);
    rtnl_simplify(&frac);
    return frac;
}


bool rtnl_equal(const struct rtnl *r, const struct rtnl *s) {
    struct rtnl r2 = {r->num, r->den};
    struct rtnl s2 = {s->num, s->den};

    rtnl_simplify(&r2);
    rtnl_simplify(&s2);
    if ((r2.num == s2.num) && (r2.den == s2.den)) {
        return true;
    }
    return false;
}

                
int main(void) {
    struct rtnl r = rtnl_init(57, -81);
    assert(r.num == -19);
    assert(r.den == 27);
    
    struct rtnl s = rtnl_init(-18, -12);
    assert(s.num == 3);
    assert(s.den == 2);
    
    struct rtnl sum = rtnl_add(&r, &s);
    assert(sum.num == 43);
    assert(sum.den == 54);
    
    struct rtnl diff = rtnl_sub(&r, &s);
    assert(diff.num == -119);
    assert(diff.den == 54);  
    
    struct rtnl prod = rtnl_mul(&r, &s);
    assert(prod.num == -19);
    assert(prod.den == 18);
    
    assert(!rtnl_equal(&r, &s));
    
    // ADD YOUR OWN TESTS BELOW:
    struct rtnl a = rtnl_init(0, 3);
    assert(a.num == 0);
    assert(a.den == 3);

    struct rtnl b = rtnl_init(9, 9);
    assert(b.num == 1);
    assert(b.den == 1);

    struct rtnl sum2 = rtnl_add(&a, &b);
    assert(sum2.num == 1);
    assert(sum2.den == 1);

    struct rtnl diff2 = rtnl_sub(&a, &b);
    assert(diff2.num == -1);
    assert(diff2.den == 1);

    struct rtnl prod2 = rtnl_mul(&a, &b);
    assert(prod2.num == 0);
    assert(prod2.den == 3);

    struct rtnl c = {3, 9};
    struct rtnl d = {1, 3};
    assert(rtnl_equal(&c, &d));
}
