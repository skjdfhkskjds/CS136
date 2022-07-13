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

// By including this line, you are now able to use all
//  functions from q1a-rtnl in this question
//  You will learn more about the role of .h files in Section 6
#include "q1a-rtnl.h"



struct point_3d {
  struct rtnl *x;
  struct rtnl *y;
  struct rtnl *z;
};

struct rtnl point_3d_dist_squared(const struct point_3d *p, 
                                  const struct point_3d *q) {
    struct rtnl delta_x = rtnl_sub(p->x, q->x);
    struct rtnl delta_y = rtnl_sub(p->y, q->y);
    struct rtnl delta_z = rtnl_sub(p->z, q->z);

    struct rtnl sqr_delta_x = rtnl_mul(&delta_x, &delta_x);
    struct rtnl sqr_delta_y = rtnl_mul(&delta_y, &delta_y);
    struct rtnl sqr_delta_z = rtnl_mul(&delta_z, &delta_z);

    struct rtnl sum1 = rtnl_add(&sqr_delta_x, &sqr_delta_y);
    struct rtnl squared_distance = rtnl_add(&sum1, &sqr_delta_z);
    return squared_distance;
}





int main(void) {
  struct rtnl x1 = rtnl_init(57, -81);
  struct rtnl y1 = rtnl_init(3, 1);
  struct rtnl z1 = rtnl_init(0, -7);
  struct point_3d p = {&x1, &y1, &z1};
  
  struct rtnl x2 = rtnl_init(-18, -12);
  struct rtnl y2 = rtnl_init(84, -882);
  struct rtnl z2 = rtnl_init(-12, 12);
  struct point_3d q = {&x2, &y2, &z2};
  
  struct rtnl dist_squared = point_3d_dist_squared(&p, &q);
  assert(dist_squared.num == 2205673);
  assert(dist_squared.den == 142884);
  
  // ADD YOUR OWN TESTS BELOW:
}
