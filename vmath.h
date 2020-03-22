#ifndef _VMATH_INCLUDE_
#define _VMATH_INCLUDE_

#ifdef VMATH_STATICDEF
#define VMATHDEF static
#else
#define VMATHDEF extern
#endif

#ifdef VMATH_DOUBLEPREC
typedef double scalar;
#else
typedef float  scalar;
#endif

typedef struct vec2_s
{
	scalar x, y;
} vec2;

typedef struct vec3_s
{
	scalar x, y, z;
} vec3;

// plane: x,y,z is unit normal
//        w is (signed) distance in normal direction
// quat: x,y,z is i,j,k components, w is real comp.

typedef struct vec4_s
{
	scalar x, y, z, w;
} vec4, quat, plane;

// a,b,c,d are rows of the matrix
// i.e. row major matrix

typedef struct mat3x3_s
{
	vec3 a, b, c;
} mat3, mat3x3;

typedef struct mat3x4_s
{
	vec4 a, b, c; // d = {0, 0, 0, 1}
} mat3x4;

typedef struct mat4x4_s
{
	vec4 a, b, c, d;
} mat4, mat4x4;

// FUNCTIONS

// vec2 common
VMATHDEF scalar vec2_lensqr(vec2 *v); // return v . v
VMATHDEF scalar vec2_len(vec2 *v); // return |v|
VMATHDEF scalar vec2_len1(vec2 *v); // return d1(v, 0)
VMATHDEF void vec2_zero(vec2 *v); // v = 0
VMATHDEF void vec2_setc(vec2 *v, scalar x, scalar y); // v = {x, y}
VMATHDEF void vec2_seta(vec2 *v, scalar *u); // v = {u}
VMATHDEF void vec2_set(vec2 *r, vec2 *v); // v = u
VMATHDEF void vec2_scale(vec2 *r, scalar s, vec2 *v); // r = s * v
VMATHDEF void vec2_neg(vec2 *r, vec2 *v); // r = -v
VMATHDEF void vec2_normalize(vec2 *r, vec2 *v); // r = v / |v| (possible div. by 0)
VMATHDEF void vec2_add(vec2 *r, vec2 *u, vec2 *v); // r = u + v
VMATHDEF void vec2_sub(vec2 *r, vec2 *u, vec2 *v); // r = u - v
VMATHDEF void vec2_tmul(vec2 *r, vec2 *u, vec2 *v); // r = u * v (term-wise mult.)
VMATHDEF scalar vec2_dot(vec2 *u, vec2 *v); // return u . v
VMATHDEF void vec2_ma(vec2 *r, vec2 *u, scalar t, vec2 *v); // r = u + t * v
VMATHDEF void vec2_comb(vec2 *r, scalar s, vec2 *u, scalar t, vec2 *v); // r = s * u + t * v (linear combination)
VMATHDEF void vec2_lerp(vec2 *r, vec2 *u, vec2 *v, scalar t); // r = (1-t) * u + t * v
VMATHDEF scalar vec2_distsqr(vec2 *u, vec2 *v); // return (u - v) . (u - v)
VMATHDEF scalar vec2_dist(vec2 *u, vec2 *v); // return |u - v|
VMATHDEF scalar vec2_dist1(vec2 *u, vec2 *v); // return d1(u, v)
VMATHDEF void vec2_project(vec2 *r, vec2 *n, vec2 *v); // r = proj. of v wrt n
VMATHDEF void vec2_reflect(vec2 *r, vec2 *n, vec2 *v); // r = refl. of v wrt n

// vec3 common
VMATHDEF scalar vec3_lensqr(vec3 *v);
VMATHDEF scalar vec3_len(vec3 *v);
VMATHDEF scalar vec3_len1(vec3 *v);
VMATHDEF void vec3_zero(vec3 *v);
VMATHDEF void vec3_setc(vec3 *v, scalar x, scalar y, scalar z);
VMATHDEF void vec3_seta(vec3 *v, scalar *u);
VMATHDEF void vec3_set(vec3 *r, vec3 *v);
VMATHDEF void vec3_scale(vec3 *r, scalar s, vec3 *v);
VMATHDEF void vec3_neg(vec3 *r, vec3 *v);
VMATHDEF void vec3_normalize(vec3 *r, vec3 *v);
VMATHDEF void vec3_add(vec3 *r, vec3 *u, vec3 *v);
VMATHDEF void vec3_sub(vec3 *r, vec3 *u, vec3 *v);
VMATHDEF void vec3_tmul(vec3 *r, vec3 *u, vec3 *v);
VMATHDEF scalar vec3_dot(vec3 *u, vec3 *v);
VMATHDEF void vec3_ma(vec3 *r, vec3 *u, scalar t, vec3 *v);
VMATHDEF void vec3_comb(vec3 *r, scalar s, vec3 *u, scalar t, vec3 *v);
VMATHDEF void vec3_lerp(vec3 *r, vec3 *u, vec3 *v, scalar t);
VMATHDEF scalar vec3_distsqr(vec3 *u, vec3 *v);
VMATHDEF scalar vec3_dist(vec3 *u, vec3 *v);
VMATHDEF scalar vec3_dist1(vec3 *u, vec3 *v);
VMATHDEF void vec3_project(vec3 *r, vec3 *n, vec3 *v);
VMATHDEF void vec3_reflect(vec3 *r, vec3 *n, vec3 *v);

// vec4 common
VMATHDEF scalar vec4_lensqr(vec4 *v);
VMATHDEF scalar vec4_len(vec4 *v);
VMATHDEF scalar vec4_len1(vec4 *v);
VMATHDEF void vec4_zero(vec4 *v);
VMATHDEF void vec4_setc(vec4 *v, scalar x, scalar y, scalar z, scalar w);
VMATHDEF void vec4_seta(vec4 *v, scalar *u);
VMATHDEF void vec4_set(vec4 *r, vec4 *v);
VMATHDEF void vec4_scale(vec4 *r, scalar s, vec4 *v);
VMATHDEF void vec4_neg(vec4 *r, vec4 *v);
VMATHDEF void vec4_normalize(vec4 *r, vec4 *v);
VMATHDEF void vec4_add(vec4 *r, vec4 *u, vec4 *v);
VMATHDEF void vec4_sub(vec4 *r, vec4 *u, vec4 *v);
VMATHDEF void vec4_tmul(vec4 *r, vec4 *u, vec4 *v);
VMATHDEF scalar vec4_dot(vec4 *u, vec4 *v);
VMATHDEF void vec4_ma(vec4 *r, vec4 *u, scalar s, vec4 *v);
VMATHDEF void vec4_comb(vec4 *r, scalar s, vec4 *u, scalar t, vec4 *v);
VMATHDEF void vec4_lerp(vec4 *r, vec4 *u, vec4 *v, scalar t);
VMATHDEF scalar vec4_distsqr(vec4 *u, vec4 *v);
VMATHDEF scalar vec4_dist(vec4 *u, vec4 *v);
VMATHDEF scalar vec4_dist1(vec4 *u, vec4 *v);
VMATHDEF void vec4_project(vec4 *r, vec4 *n, vec4 *v);
VMATHDEF void vec4_reflect(vec4 *r, vec4 *n, vec4 *v);

// vec2, vec3, vec4 conversions (r = v)
VMATHDEF void vec2_set_vec3(vec2 *r, vec3 *v);
VMATHDEF void vec2_set_vec4(vec2 *r, vec4 *v);
VMATHDEF void vec3_set_vec2(vec3 *r, vec2 *v);
VMATHDEF void vec3_set_vec4(vec3 *r, vec4 *v);
VMATHDEF void vec4_set_vec2(vec4 *r, vec2 *v);
VMATHDEF void vec4_set_vec3(vec4 *r, vec3 *v);

// vec misc
VMATHDEF scalar vec2_cross(vec2 *u, vec2 *v); // scalar since first 2 components are always 0
VMATHDEF void vec3_cross(vec3 *r, vec3 *u, vec3 *v);
VMATHDEF void vec4_cross(vec4 *r, vec4 *u, vec4 *v); // ignores last component
VMATHDEF void plane_from_points(plane *p, vec3 *a, vec3 *b, vec3 *c);
VMATHDEF void vec3_plane_project(vec3 *r, plane *p, vec3 *v); // same as vec3_project
VMATHDEF void vec3_plane_reflect(vec3 *r, plane *p, vec3 *v); // same as vec3_reflect
VMATHDEF void plane_normalize(plane *r, plane *v); // normalize the normal part

// mat3 common
VMATHDEF void mat3_zero(mat3 *m); // m = 0
VMATHDEF void mat3_id(mat3 *m); // m = I
VMATHDEF void mat3_seta(mat3 *m, scalar *s); // m = [s]
VMATHDEF void mat3_setv(mat3 *m, vec3 *a, vec3 *b, vec3 *c); // m = [a, b, c] (rows)
VMATHDEF void mat3_set(mat3 *r, mat3 *m); // r = m
VMATHDEF void mat3_colx(vec3 *r, mat3 *m); // x col of m
VMATHDEF void mat3_coly(vec3 *r, mat3 *m); 
VMATHDEF void mat3_colz(vec3 *r, mat3 *m); 
VMATHDEF void mat3_rowa(vec3 *r, mat3 *m); // a row of m
VMATHDEF void mat3_rowb(vec3 *r, mat3 *m); 
VMATHDEF void mat3_rowc(vec3 *r, mat3 *m); 
VMATHDEF void mat3_scale(mat3 *r, scalar s, mat3 *m); // r = s * m
VMATHDEF void mat3_rsc(mat3 *r, mat3 *m, scalar a, scalar b, scalar c); // scale rows of m with a, b, c resp.
VMATHDEF void mat3_rsv(mat3 *r, mat3 *m, vec3 *v); // scale rows of m with components of v resp.
VMATHDEF void mat3_neg(mat3 *r, mat3 *m); // r = -m
VMATHDEF void mat3_add(mat3 *r, mat3 *f, mat3 *g); // r = f + g
VMATHDEF void mat3_sub(mat3 *r, mat3 *f, mat3 *g); // r = f - g
VMATHDEF void mat3_tmul(mat3 *r, mat3 *f, mat3 *g); // r = f * g (term-wise mult.)
VMATHDEF void _vec3_mul_mat3(vec3 *r, vec3 *v, mat3 *m); // r = v * m (r != v)
VMATHDEF void mat3_mul(mat3 *r, mat3 *f, mat3 *g); // r = f * g
VMATHDEF void mat3_ma(mat3 *r, mat3 *f, scalar t, mat3 *g); // r = f + t * g
VMATHDEF void mat3_comb(mat3 *r, scalar s, mat3 *f, scalar t, mat3 *g); // r = s * f + t * g
VMATHDEF void mat3_lerp(mat3 *r, mat3 *f, mat3 *g, scalar t); // r = (1 - t) * f + t * g
VMATHDEF scalar mat3_det(mat3 *m); // return det(m)
VMATHDEF void vec3_mul_mat3(vec3 *r, vec3 *v, mat3 *m); // r = v * m
VMATHDEF void mat3_mul_vec3(vec3 *r, mat3 *m, vec3 *v); // r = m * v
VMATHDEF void mat3_trans(mat3 *m); // m = transpose(m)
VMATHDEF void mat3_transpose(mat3 *r, mat3 *m); // r = transpose(m)
VMATHDEF void mat3_vtrace(vec3 *v, mat3 *m); // v = trace vector of m
VMATHDEF scalar mat3_trace(mat3 *m); // return trace of m

// mat3x4 common
VMATHDEF void mat3x4_zero(mat3x4 *m);
VMATHDEF void mat3x4_id(mat3x4 *m);
VMATHDEF void mat3x4_seta(mat3x4 *m, scalar *s);
VMATHDEF void mat3x4_setv(mat3x4 *m, vec4 *a, vec4 *b, vec4 *c);
VMATHDEF void mat3x4_set(mat3x4 *r, mat3x4 *m);
VMATHDEF void mat3x4_colx(vec3 *r, mat3x4 *m);
VMATHDEF void mat3x4_coly(vec3 *r, mat3x4 *m);
VMATHDEF void mat3x4_colz(vec3 *r, mat3x4 *m);
VMATHDEF void mat3x4_colw(vec3 *r, mat3x4 *m);
VMATHDEF void mat3x4_rowa(vec4 *r, mat3x4 *m); 
VMATHDEF void mat3x4_rowb(vec4 *r, mat3x4 *m); 
VMATHDEF void mat3x4_rowc(vec4 *r, mat3x4 *m); 
VMATHDEF void mat3x4_scale(mat3x4 *r, scalar s, mat3x4 *m);
VMATHDEF void mat3x4_rsc(mat3x4 *r, mat3x4 *m, scalar a, scalar b, scalar c);
VMATHDEF void mat3x4_rsv(mat3x4 *r, mat3x4 *m, vec3 *v);
VMATHDEF void mat3x4_neg(mat3x4 *r, mat3x4 *m);
VMATHDEF void mat3x4_add(mat3x4 *r, mat3x4 *f, mat3x4 *g);
VMATHDEF void mat3x4_sub(mat3x4 *r, mat3x4 *f, mat3x4 *g);
VMATHDEF void mat3x4_tmul(mat3x4 *r, mat3x4 *f, mat3x4 *g);
VMATHDEF void _vec4_mul_mat3x4(vec4 *r, vec4 *v, mat3x4 *m);
VMATHDEF void mat3x4_mul(mat3x4 *r, mat3x4 *f, mat3x4 *g);
VMATHDEF void mat3x4_ma(mat3x4 *r, mat3x4 *f, scalar t, mat3x4 *g);
VMATHDEF void mat3x4_comb(mat3x4 *r, scalar s, mat3x4 *f, scalar t, mat3x4 *g);
VMATHDEF void mat3x4_lerp(mat3x4 *r, mat3x4 *f, mat3x4 *g, scalar t);
VMATHDEF scalar mat3x4_det(mat3x4 *m);
VMATHDEF void vec4_mul_mat3x4(vec4 *r, vec4 *v, mat3x4 *m);
VMATHDEF void mat3x4_mul_vec4(vec4 *r, mat3x4 *m, vec4 *v);
VMATHDEF void mat3x4_trans(mat3x4 *m);
VMATHDEF void mat3x4_transpose(mat3x4 *r, mat3x4 *m);
VMATHDEF void mat3x4_vtrace(vec3 *v, mat3x4 *m);
VMATHDEF scalar mat3x4_trace(mat3x4 *m);

// mat4 common
VMATHDEF void mat4_zero(mat4 *m);
VMATHDEF void mat4_id(mat4 *m);
VMATHDEF void mat4_seta(mat4 *m, scalar *s);
VMATHDEF void mat4_setv(mat4 *m, vec4 *a, vec4 *b, vec4 *c, vec4 *d);
VMATHDEF void mat4_set(mat4 *r, mat4 *m);
VMATHDEF void mat4_colx(vec4 *r, mat4 *m);
VMATHDEF void mat4_coly(vec4 *r, mat4 *m);
VMATHDEF void mat4_colz(vec4 *r, mat4 *m);
VMATHDEF void mat4_colw(vec4 *r, mat4 *m);
VMATHDEF void mat4_rowa(vec4 *r, mat4 *m);
VMATHDEF void mat4_rowb(vec4 *r, mat4 *m);
VMATHDEF void mat4_rowc(vec4 *r, mat4 *m);
VMATHDEF void mat4_rowd(vec4 *r, mat4 *m);
VMATHDEF void mat4_scale(mat4 *r, scalar s, mat4 *m);
VMATHDEF void mat4_rsc(mat4 *r, mat4 *m, scalar a, scalar b, scalar c, scalar d);
VMATHDEF void mat4_rsv(mat4 *r, mat4 *m, vec4 *v);
VMATHDEF void mat4_neg(mat4 *r, mat4 *m);
VMATHDEF void mat4_add(mat4 *r, mat4 *f, mat4 *g);
VMATHDEF void mat4_sub(mat4 *r, mat4 *f, mat4 *g);
VMATHDEF void mat4_tmul(mat4 *r, mat4 *f, mat4 *g);
VMATHDEF void _vec4_mul_mat4(vec4 *r, vec4 *v, mat4 *m);
VMATHDEF void mat4_mul(mat4 *r, mat4 *f, mat4 *g);
VMATHDEF void mat4_ma(mat4 *r, mat4 *f, scalar t, mat4 *g);
VMATHDEF void mat4_comb(mat4 *r, scalar s, mat4 *f, scalar t, mat4 *g);
VMATHDEF void mat4_lerp(mat4 *r, mat4 *f, mat4 *g, scalar t);
VMATHDEF scalar mat4_det(mat4 *m);
VMATHDEF scalar mat4_det3(mat4 *m);
VMATHDEF void vec4_mul_mat4(vec4 *r, vec4 *v, mat4 *m);
VMATHDEF void mat4_mul_vec4(vec4 *r, mat4 *m, vec4 *v);
VMATHDEF void mat4_trans(mat4 *m);
VMATHDEF void mat4_transpose(mat4 *r, mat4 *m);
VMATHDEF void mat4_vtrace(vec4 *v, mat4 *m);
VMATHDEF scalar mat4_trace(mat4 *m);

// mat3, mat3x4, mat4 conversion (r = m)
VMATHDEF void mat3_set_mat4(mat3 *r, mat4 *m);
VMATHDEF void mat3_set_mat3x4(mat3 *r, mat3x4 *m);
VMATHDEF void mat3x4_set_mat3(mat3x4 *r, mat3 *m);
VMATHDEF void mat3x4_set_mat4(mat3x4 *r, mat4 *m);
VMATHDEF void mat4_set_mat3(mat4 *r, mat3 *m);
VMATHDEF void mat4_set_mat3x4(mat4 *r, mat3x4 *m);

// quat common
VMATHDEF scalar quat_norm(quat *v);
VMATHDEF void quat_id(quat *v);
VMATHDEF void quat_inv(quat *r, quat *v);
VMATHDEF void quat_conj(quat *r, quat *v);
VMATHDEF void quat_set_vec3(quat *r, vec3 *v);
VMATHDEF void vec3_set_quat(vec3 *r, quat *v);
VMATHDEF void quat_mul(quat *r, quat *u, quat *v);
VMATHDEF void quat_mul_vec3(quat *r, quat *u, vec3 *v);
VMATHDEF void vec3_mul_quat(quat *r, vec3 *u, quat *v);
VMATHDEF void vec3_rotate_quat(vec3 *r, quat *q, vec3 *v);
VMATHDEF void mat3_from_quat(mat3 *m, quat *q);
VMATHDEF void quat_from_mat3(quat *q, mat3 *m);


#endif // _VMATH_INCLUDE_

#define VMATH_IMPLEMENTATION
#ifdef VMATH_IMPLEMENTATION


#include <math.h>

#ifndef VMATH_NOSTDMEM
#include <string.h>
#define vmemset memset
#define vmemcpy memcpy
#else
#error "not implemented"
#endif

#ifndef VMATH_DOUBLEPREC
#define vsqrt sqrtf
#define vabs fabsf
#define vsin sinf
#define vcos cosf
#else
#define vsqrt sqrt
#define vabs fabs
#define vsin sin
#define vcos cos
#endif


// -------------------
// --- common vec2 ---
// -------------------

// = v · v
VMATHDEF scalar vec2_lensqr(vec2 *v)
{
	return v->x * v->x + v->y * v->y;
}

// = |v|
VMATHDEF scalar vec2_len(vec2 *v)
{
	return vsqrt(v->x * v->x + v->y * v->y);
}

// = d1(v, 0)
VMATHDEF scalar vec2_len1(vec2 *v)
{
	return vabs(v->x) + vabs(v->y);
}

// v = 0
VMATHDEF void vec2_zero(vec2 *v)
{
	v->x = v->y = 0;
}

// v = {x, y}
VMATHDEF void vec2_setc(vec2 *v, scalar x, scalar y)
{
	v->x = x; v->y = y;
}

// v = {...}
VMATHDEF void vec2_seta(vec2 *v, scalar *u)
{
	v->x = u[0]; v->y = u[1];
}

// r = v
VMATHDEF void vec2_set(vec2 *r, vec2 *v)
{
	r->x = v->x; r->y = v->y;
}

// r = s * v
VMATHDEF void vec2_scale(vec2 *r, scalar s, vec2 *v)
{
	r->x = s * v->x; r->y = s * v->y;
}

// r = -v
VMATHDEF void vec2_neg(vec2 *r, vec2 *v)
{
	r->x = -(v->x); r->y = -(v->y);
}

// r = v / |v| (possible division by 0)
VMATHDEF void vec2_normalize(vec2 *r, vec2 *v)
{
	scalar s = vsqrt(v->x * v->x + v->y * v->y);
	r->x = v->x / s; r->y = v->y / s;
}

// r = u + v
VMATHDEF void vec2_add(vec2 *r, vec2 *u, vec2 *v)
{
	r->x = u->x + v->x; r->y = u->y + v->y;
}

// r = u - v
VMATHDEF void vec2_sub(vec2 *r, vec2 *u, vec2 *v)
{
	r->x = u->x - v->x; r->y = u->y - v->y;
}

// r = u * v (term-wise)
VMATHDEF void vec2_tmul(vec2 *r, vec2 *u, vec2 *v)
{
	r->x = u->x * v->x; r->y = u->y * v->y;
}

// = u · v
VMATHDEF scalar vec2_dot(vec2 *u, vec2 *v)
{
	return u->x * v->x + u->y * v->y;
}

// r = u + s * v
VMATHDEF void vec2_ma(vec2 *r, vec2 *u, scalar t, vec2 *v)
{
	r->x = u->x + t * v->x; r->y = u->y + t * v->y;
}

// r = s * u + t * v
VMATHDEF void vec2_comb(vec2 *r, scalar s, vec2 *u, scalar t, vec2 *v)
{
	r->x = s * u->x + t * v->x; r->y = s * u->y + t * v->y;
}

// r = (1 - t) * u + t * v
VMATHDEF void vec2_lerp(vec2 *r, vec2 *u, vec2 *v, scalar t)
{
	scalar s = 1 - t;
	r->x = s * u->x + t * v->x; r->y = s * u->y + t * v->y;
}

// = |u - v|^2
VMATHDEF scalar vec2_distsqr(vec2 *u, vec2 *v)
{
	scalar t, d;
	t = u->x - v->x; d  = t * t;
	t = u->y - v->y; d += t * t;
	return d;
}

// |u - v|
VMATHDEF scalar vec2_dist(vec2 *u, vec2 *v)
{
	scalar t, d;
	t = u->x - v->x; d  = t * t;
	t = u->y - v->y; d += t * t;
	return vsqrt(d);
}

// = d1(u, v)
VMATHDEF scalar vec2_dist1(vec2 *u, vec2 *v)
{
	return vabs(u->x - v->x) + vabs(u->y - v->y);
}

// r = projection of v wrt n
VMATHDEF void vec2_project(vec2 *r, vec2 *n, vec2 *v)
{
	scalar t = -(vec2_dot(n, v) / vec2_dot(n, n));
	vec2_ma(r, v, t, n);
}

// r = reflection of v wrt n
VMATHDEF void vec2_reflect(vec2 *r, vec2 *n, vec2 *v)
{
	scalar t = -2 * (vec2_dot(n, v) / vec2_dot(n, n));
	vec2_ma(r, v, t, n);
}


// -------------------
// --- common vec3 ---
// -------------------

// = v · v
VMATHDEF scalar vec3_lensqr(vec3 *v)
{
	return v->x * v->x + v->y * v->y + v->z * v->z;
}

// = |v|
VMATHDEF scalar vec3_len(vec3 *v)
{
	return vsqrt(v->x * v->x + v->y * v->y + v->z * v->z);
}

// = d1(v, 0)
VMATHDEF scalar vec3_len1(vec3 *v)
{
	return vabs(v->x) + vabs(v->y) + vabs(v->z);
}

// v = 0
VMATHDEF void vec3_zero(vec3 *v)
{
	v->x = v->y = v->z = 0;
}

// r = {x, y, z}
VMATHDEF void vec3_setc(vec3 *v, scalar x, scalar y, scalar z)
{
	v->x = x; v->y = y; v->z = z;
}

// v = {...}
VMATHDEF void vec3_seta(vec3 *v, scalar *u)
{
	v->x = u[0]; v->y = u[1]; v->z = u[2];
}

// r = v
VMATHDEF void vec3_set(vec3 *r, vec3 *v)
{
	r->x = v->x; r->y = v->y; r->z = v->z;
}

// r = s * v
VMATHDEF void vec3_scale(vec3 *r, scalar s, vec3 *v)
{
	r->x = s * v->x; r->y = s * v->y; r->z = s * v->z;
}

// r = -v
VMATHDEF void vec3_neg(vec3 *r, vec3 *v)
{
	r->x = -(v->x); r->y = -(v->y); r->z = -(v->z);
}

// r = v / |v|  (possible division by 0)
VMATHDEF void vec3_normalize(vec3 *r, vec3 *v)
{
	scalar s = vsqrt(v->x * v->x + v->y * v->y + v->z * v->z);
	r->x = v->x / s; r->y = v->y / s; r->z = v->z / s;
}

// r = u + v
VMATHDEF void vec3_add(vec3 *r, vec3 *u, vec3 *v)
{
	r->x = u->x + v->x; r->y = u->y + v->y; r->z = u->z + v->z;
}

// r = u - v
VMATHDEF void vec3_sub(vec3 *r, vec3 *u, vec3 *v)
{
	r->x = u->x - v->x; r->y = u->y - v->y; r->z = u->z - v->z;
}

// r = u * v (term-wise)
VMATHDEF void vec3_tmul(vec3 *r, vec3 *u, vec3 *v)
{
	r->x = u->x * v->x; r->y = u->y * v->y; r->z = u->z * v->z;
}

// = u · v
VMATHDEF scalar vec3_dot(vec3 *u, vec3 *v)
{
	return u->x * v->x + u->y * v->y + u->z * v->z;
}

// r = u + t * v
VMATHDEF void vec3_ma(vec3 *r, vec3 *u, scalar t, vec3 *v)
{
	r->x = u->x + t * v->x; r->y = u->y + t * v->y; r->z = u->z + t * v->z;
}

// r = s * u + t * v
VMATHDEF void vec3_comb(vec3 *r, scalar s, vec3 *u, scalar t, vec3 *v)
{
	r->x = s * u->x + t * v->x; r->y = s * u->y + t * v->y;
	r->z = s * u->z + t * v->z;
}

// r = (1 - t) * u + t * v
VMATHDEF void vec3_lerp(vec3 *r, vec3 *u, vec3 *v, scalar t)
{
	scalar s = 1 - t;
	r->x = s * u->x + t * v->x; r->y = s * u->y + t * v->y;
	r->z = s * u->z + t * v->z;
}

// = |u - v|^2
VMATHDEF scalar vec3_distsqr(vec3 *u, vec3 *v)
{
	scalar t, d;
	t = u->x - v->x; d  = t * t;
	t = u->y - v->y; d += t * t;
	t = u->z - v->z; d += t * t;
	return d;
}

// |u - v|
VMATHDEF scalar vec3_dist(vec3 *u, vec3 *v)
{
	scalar t, d;
	t = u->x - v->x; d  = t * t;
	t = u->y - v->y; d += t * t;
	t = u->z - v->z; d += t * t;
	return vsqrt(d);
}

// = d1(u, v)
VMATHDEF scalar vec3_dist1(vec3 *u, vec3 *v)
{
	return vabs(u->x - v->x) + vabs(u->y - v->y) + vabs(u->z - v->z);
}

// r = projection of v wrt n
VMATHDEF void vec3_project(vec3 *r, vec3 *n, vec3 *v)
{
	scalar t = -(vec3_dot(n, v) / vec3_dot(n, n));
	vec3_ma(r, v, t, n);
}

// r = reflection of v wrt n
VMATHDEF void vec3_reflect(vec3 *r, vec3 *n, vec3 *v)
{
	scalar t = -2 * (vec3_dot(n, v) / vec3_dot(n, n));
	vec3_ma(r, v, t, n);
}


// -------------------
// --- common vec4 ---
// -------------------

// = v · v
VMATHDEF scalar vec4_lensqr(vec4 *v)
{
	return v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w;
}

// = |v|
VMATHDEF scalar vec4_len(vec4 *v)
{
	return vsqrt(v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w);
}

// = d1(v, 0)
VMATHDEF scalar vec4_len1(vec4 *v)
{
	return vabs(v->x) + vabs(v->y) + vabs(v->z) + vabs(v->w);
}

// v = 0
VMATHDEF void vec4_zero(vec4 *v)
{
	v->x = v->y = v->z = v->w = 0;
}

// v = {x, y, z, w}
VMATHDEF void vec4_setc(vec4 *v, scalar x, scalar y, scalar z, scalar w)
{
	v->x = x; v->y = y; v->z = z; v->w = w;
}

// v = {...}
VMATHDEF void vec4_seta(vec4 *v, scalar *u)
{
	v->x = u[0]; v->y = u[1]; v->z = u[2]; v->w = u[3];
}

// r = v
VMATHDEF void vec4_set(vec4 *r, vec4 *v)
{
	r->x = v->x; r->y = v->y;
	r->z = v->z; r->w = v->w;
}

// r = s * v
VMATHDEF void vec4_scale(vec4 *r, scalar s, vec4 *v)
{
	r->x = s * v->x; r->y = s * v->y;
	r->z = s * v->z; r->w = s * v->w;
}

// r = -v
VMATHDEF void vec4_neg(vec4 *r, vec4 *v)
{
	r->x = -(v->x); r->y = -(v->y);
	r->z = -(v->z); r->w = -(v->w);
}

// r = v / |v| (possible division by 0)
VMATHDEF void vec4_normalize(vec4 *r, vec4 *v)
{
	scalar s = vsqrt(v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w);
	r->x = v->x / s; r->y = v->y / s;
	r->z = v->z / s; r->w = v->w / s;
}

// r = u + v
VMATHDEF void vec4_add(vec4 *r, vec4 *u, vec4 *v)
{
	r->x = u->x + v->x; r->y = u->y + v->y;
	r->z = u->z + v->z; r->w = u->w + v->w;
}

// r = u - v
VMATHDEF void vec4_sub(vec4 *r, vec4 *u, vec4 *v)
{
	r->x = u->x - v->x; r->y = u->y - v->y;
	r->z = u->z - v->z; r->w = u->w - v->w;
}

// r = u * v (term-wise)
VMATHDEF void vec4_tmul(vec4 *r, vec4 *u, vec4 *v)
{
	r->x = u->x * v->x; r->y = u->y * v->y;
	r->z = u->z * v->z; r->w = u->w * v->w;
}

// = u · v
VMATHDEF scalar vec4_dot(vec4 *u, vec4 *v)
{
	return u->x * v->x + u->y * v->y
	     + u->z * v->z + u->w * v->w;
}

// r = u + s * v
VMATHDEF void vec4_ma(vec4 *r, vec4 *u, scalar s, vec4 *v)
{
	r->x = u->x + s * v->x; r->y = u->y + s * v->y;
	r->z = u->z + s * v->z; r->w = u->w + s * v->w;
}

// r = s * u + t * v
VMATHDEF void vec4_comb(vec4 *r, scalar s, vec4 *u, scalar t, vec4 *v)
{
	r->x = s * u->x + t * v->x; r->y = s * u->y + t * v->y;
	r->z = s * u->z + t * v->z; r->w = s * u->w + t * v->w;
}

// r = (1 - t) * u + t * v
VMATHDEF void vec4_lerp(vec4 *r, vec4 *u, vec4 *v, scalar t)
{
	scalar s = 1 - t;
	r->x = s * u->x + t * v->x; r->y = s * u->y + t * v->y;
	r->z = s * u->z + t * v->z; r->w = s * u->w + t * v->w;
}

// = |u - v|^2
VMATHDEF scalar vec4_distsqr(vec4 *u, vec4 *v)
{
	scalar t, d;
	t = u->x - v->x; d  = t * t;
	t = u->y - v->y; d += t * t;
	t = u->z - v->z; d += t * t;
	t = u->w - v->w; d += t * t;
	return d;
}

// |u - v|
VMATHDEF scalar vec4_dist(vec4 *u, vec4 *v)
{
	scalar t, d;
	t = u->x - v->x; d  = t * t;
	t = u->y - v->y; d += t * t;
	t = u->z - v->z; d += t * t;
	t = u->w - v->w; d += t * t;
	return vsqrt(d);
}

// = d1(u, v)
VMATHDEF scalar vec4_dist1(vec4 *u, vec4 *v)
{
	return vabs(u->x - v->x) + vabs(u->y - v->y)
	     + vabs(u->z - v->z) + vabs(u->w - v->w);
}

// r = projection of v wrt n
VMATHDEF void vec4_project(vec4 *r, vec4 *n, vec4 *v)
{
	scalar t = -(vec4_dot(n, v) / vec4_dot(n, n));
	vec4_ma(r, v, t, n);
}

// r = reflection of v wrt n
VMATHDEF void vec4_reflect(vec4 *r, vec4 *n, vec4 *v)
{
	scalar t = -2 * (vec4_dot(n, v) / vec4_dot(n, n));
	vec4_ma(r, v, t, n);
}


// -------------------
// --- vec convert ---
// -------------------

// vec2 = vec3
VMATHDEF void vec2_set_vec3(vec2 *r, vec3 *v)
{
	r->x = v->x; r->y = v->y;
}

// vec2 = vec4
VMATHDEF void vec2_set_vec4(vec2 *r, vec4 *v)
{
	r->x = v->x; r->y = v->y; 
}

// vec3 = vec2
VMATHDEF void vec3_set_vec2(vec3 *r, vec2 *v)
{
	r->x = v->x; r->y = v->y; r->z = 0; 
}

// vec3 = vec4
VMATHDEF void vec3_set_vec4(vec3 *r, vec4 *v)
{
	r->x = v->x; r->y = v->y; r->z = v->z; 
}

// vec4 = vec2
VMATHDEF void vec4_set_vec2(vec4 *r, vec2 *v)
{
	r->x = v->x; r->y = v->y; r->z = r->w = 0; 
}

// vec4 = vec3
VMATHDEF void vec4_set_vec3(vec4 *r, vec3 *v)
{
	r->x = v->x; r->y = v->y; r->z = v->z; r->w = 0; 
}


// -------------------
// ---- vec other ----
// -------------------

// = u x v (scalar since first 2 components are always 0)
VMATHDEF scalar vec2_cross(vec2 *u, vec2 *v)
{
	return u->x * v->y - u->y * v->x;
}

// = u x v
VMATHDEF void vec3_cross(vec3 *r, vec3 *u, vec3 *v)
{
	scalar x, y, z;
	x = u->y * v->z - u->z * v->y;
	y = u->z * v->x - u->x * v->z;
	z = u->x * v->y - u->y * v->x;
	r->x = x; r->y = y; r->z = z;
}

// = u x v
VMATHDEF void vec4_cross(vec4 *r, vec4 *u, vec4 *v)
{
	scalar x, y, z;
	x = u->y * v->z - u->z * v->y;
	y = u->z * v->x - u->x * v->z;
	z = u->x * v->y - u->y * v->x;
	r->x = x; r->y = y; r->z = z; r->w = 0;
}

// p = plane of non collinear points a,b,c
VMATHDEF void plane_from_points(plane *p, vec3 *a, vec3 *b, vec3 *c)
{
	vec3 n, u, v;
	vec3_sub(&u, b, a);
	vec3_sub(&v, c, a);
	vec3_cross(&n, &u, &v);
	vec3_normalize(&n, &n);
	p->x = n.x; p->y = n.y; p->z = n.z;
	p->w = vec3_dot(a, &n);
}

// r = projection of v wrt normal of p
VMATHDEF void vec3_plane_project(vec3 *r, plane *p, vec3 *v)
{
	vec3 n;
	vec3_set_vec4(&n, p);
	vec3_project(r, &n, v);
}

// r = reflection of v wrt normal of p
VMATHDEF void vec3_plane_reflect(vec3 *r, plane *p, vec3 *v)
{
	vec3 n;
	vec3_set_vec4(&n, p);
	vec3_reflect(r, &n, v);
}

// r = plane v with unit normal
VMATHDEF void plane_normalize(plane *r, plane *v)
{
	scalar s = vsqrt(v->x * v->x + v->y * v->y + v->z * v->z);
	r->x = v->x / s; r->y = v->y / s; r->z = v->z / s;
	r->w = s * v->w;
}


// ---------------------
// --- common mat3x3 ---
// ---------------------

// m = 0
VMATHDEF void mat3_zero(mat3 *m)
{
	memset(m, 0, sizeof *m);
}

// m = I
VMATHDEF void mat3_id(mat3 *m)
{
	memset(m, 0, sizeof *m);
	m->a.x = m->b.y = m->c.z = 1;
}

// m = [...]
VMATHDEF void mat3_seta(mat3 *m, scalar *s)
{
	memcpy(m, s, sizeof *m);
}

// m = [a, b, c]^T
VMATHDEF void mat3_setv(mat3 *m, vec3 *a, vec3 *b, vec3 *c)
{
	vec3_set(&m->a, a);
	vec3_set(&m->b, b);
	vec3_set(&m->c, c);
}

// r = m
VMATHDEF void mat3_set(mat3 *r, mat3 *m)
{
	memcpy(r, m, sizeof *m);
}

// r = column(m, ?)
VMATHDEF void mat3_colx(vec3 *r, mat3 *m) { vec3_setc(r, m->a.x, m->b.x, m->c.x); }
VMATHDEF void mat3_coly(vec3 *r, mat3 *m) { vec3_setc(r, m->a.y, m->b.y, m->c.y); }
VMATHDEF void mat3_colz(vec3 *r, mat3 *m) { vec3_setc(r, m->a.z, m->b.z, m->c.z); }
// r = row(m, ?)
VMATHDEF void mat3_rowa(vec3 *r, mat3 *m) { vec3_set(r, &m->a); }
VMATHDEF void mat3_rowb(vec3 *r, mat3 *m) { vec3_set(r, &m->b); }
VMATHDEF void mat3_rowc(vec3 *r, mat3 *m) { vec3_set(r, &m->c); }

// r = s * m
VMATHDEF void mat3_scale(mat3 *r, scalar s, mat3 *m)
{
	vec3_scale(&r->a, s, &m->a);
	vec3_scale(&r->b, s, &m->b);
	vec3_scale(&r->c, s, &m->c);
}

// scale rows with a,b,c
VMATHDEF void mat3_rsc(mat3 *r, mat3 *m, scalar a, scalar b, scalar c)
{
	vec3_scale(&r->a, a, &m->a);
	vec3_scale(&r->b, b, &m->b);
	vec3_scale(&r->c, c, &m->c);
}

// scale rows with v
VMATHDEF void mat3_rsv(mat3 *r, mat3 *m, vec3 *v)
{
	vec3_scale(&r->a, v->x, &m->a);
	vec3_scale(&r->b, v->y, &m->b);
	vec3_scale(&r->c, v->z, &m->c);
}

// r = -m
VMATHDEF void mat3_neg(mat3 *r, mat3 *m)
{
	vec3_neg(&r->a, &m->a);
	vec3_neg(&r->b, &m->b);
	vec3_neg(&r->c, &m->c);
}

// r = f + g
VMATHDEF void mat3_add(mat3 *r, mat3 *f, mat3 *g)
{
	vec3_add(&r->a, &f->a, &g->a);
	vec3_add(&r->b, &f->b, &g->b);
	vec3_add(&r->c, &f->c, &g->c);
}

// r = f - g
VMATHDEF void mat3_sub(mat3 *r, mat3 *f, mat3 *g)
{
	vec3_sub(&r->a, &f->a, &g->a);
	vec3_sub(&r->b, &f->b, &g->b);
	vec3_sub(&r->c, &f->c, &g->c);
}

// r = f * g (term-wise)
VMATHDEF void mat3_tmul(mat3 *r, mat3 *f, mat3 *g)
{
	vec3_tmul(&r->a, &f->a, &g->a);
	vec3_tmul(&r->b, &f->b, &g->b);
	vec3_tmul(&r->c, &f->c, &g->c);
}

// r = v x m (r != v)
VMATHDEF void _vec3_mul_mat3(vec3 *r, vec3 *v, mat3 *m)
{
	r->x = m->a.x * v->x + m->b.x * v->y + m->c.x * v->z;
	r->y = m->a.y * v->x + m->b.y * v->y + m->c.y * v->z;
	r->z = m->a.z * v->x + m->b.z * v->y + m->c.z * v->z;
}

// r = f x g
VMATHDEF void mat3_mul(mat3 *r, mat3 *f, mat3 *g)
{
	mat3 m;
	_vec3_mul_mat3(&m.a, &f->a, g);
	_vec3_mul_mat3(&m.b, &f->b, g);
	_vec3_mul_mat3(&m.c, &f->c, g);
	memcpy(r, &m, sizeof m);
}

// r = f + t * g
VMATHDEF void mat3_ma(mat3 *r, mat3 *f, scalar t, mat3 *g)
{
	vec3_ma(&r->a, &f->a, t, &g->a);
	vec3_ma(&r->b, &f->b, t, &g->b);
	vec3_ma(&r->c, &f->c, t, &g->c);
}

// r = s * f + t * g
VMATHDEF void mat3_comb(mat3 *r, scalar s, mat3 *f, scalar t, mat3 *g)
{
	vec3_comb(&r->a, s, &f->a, t, &g->a);
	vec3_comb(&r->b, s, &f->b, t, &g->b);
	vec3_comb(&r->c, s, &f->c, t, &g->c);
}

// r = (1 - t) * f + t * g
VMATHDEF void mat3_lerp(mat3 *r, mat3 *f, mat3 *g, scalar t)
{
	scalar s = 1 - t;
	vec3_comb(&r->a, s, &f->a, t, &g->a);
	vec3_comb(&r->b, s, &f->b, t, &g->b);
	vec3_comb(&r->c, s, &f->c, t, &g->c);
}

// = det(m)
VMATHDEF scalar mat3_det(mat3 *m)
{
	return m->a.x * (m->b.y * m->c.z - m->b.z * m->c.y)
	     - m->a.y * (m->b.x * m->c.z - m->b.z * m->c.x)
	     + m->a.z * (m->b.x * m->c.y - m->b.y * m->c.x);
}

// r = v x m
VMATHDEF void vec3_mul_mat3(vec3 *r, vec3 *v, mat3 *m)
{
	scalar x, y, z;
	x = m->a.x * v->x + m->b.x * v->y + m->c.x * v->z;
	y = m->a.y * v->x + m->b.y * v->y + m->c.y * v->z;
	z = m->a.z * v->x + m->b.z * v->y + m->c.z * v->z;
	r->x = x; r->y = y; r->z = z;
}

// r = m x v
VMATHDEF void mat3_mul_vec3(vec3 *r, mat3 *m, vec3 *v)
{
	scalar x, y, z;
	x = m->a.x * v->x + m->a.y * v->y + m->a.z * v->z;
	y = m->b.x * v->x + m->b.y * v->y + m->b.z * v->z;
	z = m->c.x * v->x + m->c.y * v->y + m->c.z * v->z;
	r->x = x; r->y = y; r->z = z;
}

// m = transpose(m)
VMATHDEF void mat3_trans(mat3 *m)
{
	scalar t;
	t = m->a.y; m->a.y = m->b.x; m->b.x = t;
	t = m->a.z; m->a.z = m->c.x; m->c.x = t;
	
	t = m->b.z; m->b.z = m->c.y; m->c.y = t;
}

// r = transpose(m)
VMATHDEF void mat3_transpose(mat3 *r, mat3 *m)
{
	scalar t;
	t = m->a.y; r->a.y = m->b.x; r->b.x = t;
	t = m->a.z; r->a.z = m->c.x; r->c.x = t;
	
	t = m->b.z; r->b.z = m->c.y; r->c.y = t;
	
	r->a.x = m->a.x; r->b.y = m->b.y; r->c.z = m->c.z;
}

// trace as a vector
VMATHDEF void mat3_vtrace(vec3 *v, mat3 *m)
{
	v->x = m->a.x; v->y = m->b.y; v->z = m->c.z;
}

// trace
VMATHDEF scalar mat3_trace(mat3 *m)
{
	return m->a.x + m->b.y + m->c.z;
}


// ---------------------
// --- common mat3x4 ---
// ---------------------

// m = 0
VMATHDEF void mat3x4_zero(mat3x4 *m)
{
	memset(m, 0, sizeof *m);
}

// m = I
VMATHDEF void mat3x4_id(mat3x4 *m)
{
	memset(m, 0, sizeof *m);
	m->a.x = m->b.y = m->c.z = 1;
}

// m = [...]
VMATHDEF void mat3x4_seta(mat3x4 *m, scalar *s)
{
	memcpy(m, s, sizeof *m);
}

// m = [a, b, c]^T
VMATHDEF void mat3x4_setv(mat3x4 *m, vec4 *a, vec4 *b, vec4 *c)
{
	vec4_set(&m->a, a);
	vec4_set(&m->b, b);
	vec4_set(&m->c, c);
}

// r = m
VMATHDEF void mat3x4_set(mat3x4 *r, mat3x4 *m)
{
	memcpy(r, m, sizeof *m);
}

// r = column(m, ?)
VMATHDEF void mat3x4_colx(vec3 *r, mat3x4 *m) { vec3_setc(r, m->a.x, m->b.x, m->c.x); } //d.x = 0
VMATHDEF void mat3x4_coly(vec3 *r, mat3x4 *m) { vec3_setc(r, m->a.y, m->b.y, m->c.y); } //d.y = 0
VMATHDEF void mat3x4_colz(vec3 *r, mat3x4 *m) { vec3_setc(r, m->a.z, m->b.z, m->c.z); } //d.z = 0
VMATHDEF void mat3x4_colw(vec3 *r, mat3x4 *m) { vec3_setc(r, m->a.w, m->b.w, m->c.w); } //d.w = 1
// r = row(m, ?)
VMATHDEF void mat3x4_rowa(vec4 *r, mat3x4 *m) { vec4_set(r, &m->a); }
VMATHDEF void mat3x4_rowb(vec4 *r, mat3x4 *m) { vec4_set(r, &m->b); }
VMATHDEF void mat3x4_rowc(vec4 *r, mat3x4 *m) { vec4_set(r, &m->c); }

// r = s * m
VMATHDEF void mat3x4_scale(mat3x4 *r, scalar s, mat3x4 *m)
{
	vec4_scale(&r->a, s, &m->a);
	vec4_scale(&r->b, s, &m->b);
	vec4_scale(&r->c, s, &m->c);
}

// scale rows with a,b,c
VMATHDEF void mat3x4_rsc(mat3x4 *r, mat3x4 *m, scalar a, scalar b, scalar c)
{
	vec4_scale(&r->a, a, &m->a);
	vec4_scale(&r->b, b, &m->b);
	vec4_scale(&r->c, c, &m->c);
}

// scale rows with v
VMATHDEF void mat3x4_rsv(mat3x4 *r, mat3x4 *m, vec3 *v)
{
	vec4_scale(&r->a, v->x, &m->a);
	vec4_scale(&r->b, v->y, &m->b);
	vec4_scale(&r->c, v->z, &m->c);
}

// r = -m
VMATHDEF void mat3x4_neg(mat3x4 *r, mat3x4 *m)
{
	vec4_neg(&r->a, &m->a);
	vec4_neg(&r->b, &m->b);
	vec4_neg(&r->c, &m->c);
}

// r = f + g
VMATHDEF void mat3x4_add(mat3x4 *r, mat3x4 *f, mat3x4 *g)
{
	vec4_add(&r->a, &f->a, &g->a);
	vec4_add(&r->b, &f->b, &g->b);
	vec4_add(&r->c, &f->c, &g->c);
}

// r = f - g
VMATHDEF void mat3x4_sub(mat3x4 *r, mat3x4 *f, mat3x4 *g)
{
	vec4_sub(&r->a, &f->a, &g->a);
	vec4_sub(&r->b, &f->b, &g->b);
	vec4_sub(&r->c, &f->c, &g->c);
}

// r = f * g (term-wise)
VMATHDEF void mat3x4_tmul(mat3x4 *r, mat3x4 *f, mat3x4 *g)
{
	vec4_tmul(&r->a, &f->a, &g->a);
	vec4_tmul(&r->b, &f->b, &g->b);
	vec4_tmul(&r->c, &f->c, &g->c);
}

// r = v x m (r != v)
VMATHDEF void _vec4_mul_mat3x4(vec4 *r, vec4 *v, mat3x4 *m)
{
	r->x = m->a.x * v->x + m->b.x * v->y + m->c.x * v->z;
	r->y = m->a.y * v->x + m->b.y * v->y + m->c.y * v->z;
	r->z = m->a.z * v->x + m->b.z * v->y + m->c.z * v->z;
	r->w = m->a.w * v->x + m->b.w * v->y + m->c.w * v->z + v->w;
}

// r = f x g
VMATHDEF void mat3x4_mul(mat3x4 *r, mat3x4 *f, mat3x4 *g)
{
	mat3x4 m;
	_vec4_mul_mat3x4(&m.a, &f->a, g);
	_vec4_mul_mat3x4(&m.b, &f->b, g);
	_vec4_mul_mat3x4(&m.c, &f->c, g);
	memcpy(r, &m, sizeof m);
}

// r = f + t * g
VMATHDEF void mat3x4_ma(mat3x4 *r, mat3x4 *f, scalar t, mat3x4 *g)
{
	vec4_ma(&r->a, &f->a, t, &g->a);
	vec4_ma(&r->b, &f->b, t, &g->b);
	vec4_ma(&r->c, &f->c, t, &g->c);
}

// r = s * f + t * g
VMATHDEF void mat3x4_comb(mat3x4 *r, scalar s, mat3x4 *f, scalar t, mat3x4 *g)
{
	vec4_comb(&r->a, s, &f->a, t, &g->a);
	vec4_comb(&r->b, s, &f->b, t, &g->b);
	vec4_comb(&r->c, s, &f->c, t, &g->c);
}

// r = (1 - t) * f + t * g
VMATHDEF void mat3x4_lerp(mat3x4 *r, mat3x4 *f, mat3x4 *g, scalar t)
{
	scalar s = 1 - t;
	vec4_comb(&r->a, s, &f->a, t, &g->a);
	vec4_comb(&r->b, s, &f->b, t, &g->b);
	vec4_comb(&r->c, s, &f->c, t, &g->c);
}

// = det(m)
VMATHDEF scalar mat3x4_det(mat3x4 *m)
{
	return m->a.x * (m->b.y * m->c.z - m->b.z * m->c.y)
	     - m->a.y * (m->b.x * m->c.z - m->b.z * m->c.x)
	     + m->a.z * (m->b.x * m->c.y - m->b.y * m->c.x);
}

// r = v x m
VMATHDEF void vec4_mul_mat3x4(vec4 *r, vec4 *v, mat3x4 *m)
{
	scalar x, y, z, w;
	x = m->a.x * v->x + m->b.x * v->y + m->c.x * v->z;
	y = m->a.y * v->x + m->b.y * v->y + m->c.y * v->z;
	z = m->a.z * v->x + m->b.z * v->y + m->c.z * v->z;
	w = m->a.w * v->x + m->b.w * v->y + m->c.w * v->z + v->w;
	r->x = x; r->y = y; r->z = z; r->w = w;
}

// r = m x v
VMATHDEF void mat3x4_mul_vec4(vec4 *r, mat3x4 *m, vec4 *v)
{
	scalar x, y, z, w;
	x = m->a.x * v->x + m->a.y * v->y + m->a.z * v->z + m->a.w * v->w;
	y = m->b.x * v->x + m->b.y * v->y + m->b.z * v->z + m->b.w * v->w;
	z = m->c.x * v->x + m->c.y * v->y + m->c.z * v->z + m->c.w * v->w;
	w = v->w;
	r->x = x; r->y = y; r->z = z; r->w = w;
}

// m = transpose(m) (inner 3x3 only)
VMATHDEF void mat3x4_trans(mat3x4 *m)
{
	scalar t;
	t = m->a.y; m->a.y = m->b.x; m->b.x = t;
	t = m->a.z; m->a.z = m->c.x; m->c.x = t;
	
	t = m->b.z; m->b.z = m->c.y; m->c.y = t;
}

// r = transpose(m) (inner 3x3 only)
VMATHDEF void mat3x4_transpose(mat3x4 *r, mat3x4 *m)
{
	scalar t;
	t = m->a.y; r->a.y = m->b.x; r->b.x = t;
	t = m->a.z; r->a.z = m->c.x; r->c.x = t;
	
	t = m->b.z; r->b.z = m->c.y; r->c.y = t;
	
	r->a.x = m->a.x; r->b.y = m->b.y; r->c.z = m->c.z;
	r->a.w = m->a.w; r->b.w = m->b.w; r->c.w = m->c.w;
}

// trace as a vector
VMATHDEF void mat3x4_vtrace(vec3 *v, mat3x4 *m)
{
	v->x = m->a.x; v->y = m->b.y; v->z = m->c.z;
}

// trace
VMATHDEF scalar mat3x4_trace(mat3x4 *m)
{
	return m->a.x + m->b.y + m->c.z;
}


// ---------------------
// --- common mat4x4 ---
// ---------------------

// m = 0
VMATHDEF void mat4_zero(mat4 *m)
{
	memset(m, 0, sizeof *m);
}

// m = I
VMATHDEF void mat4_id(mat4 *m)
{
	memset(m, 0, sizeof *m);
	m->a.x = m->b.y = m->c.z = m->d.w = 1;
}

// m = [...]
VMATHDEF void mat4_seta(mat4 *m, scalar *s)
{
	memcpy(m, s, sizeof *m);
}

// m = [a, b, c]^T
VMATHDEF void mat4_setv(mat4 *m, vec4 *a, vec4 *b, vec4 *c, vec4 *d)
{
	vec4_set(&m->a, a);
	vec4_set(&m->b, b);
	vec4_set(&m->c, c);
	vec4_set(&m->d, d);
}

// r = m
VMATHDEF void mat4_set(mat4 *r, mat4 *m)
{
	memcpy(r, m, sizeof *m);
}

// r = column(m, ?)
VMATHDEF void mat4_colx(vec4 *r, mat4 *m) { vec4_setc(r, m->a.x, m->b.x, m->c.x, m->d.x); }
VMATHDEF void mat4_coly(vec4 *r, mat4 *m) { vec4_setc(r, m->a.y, m->b.y, m->c.y, m->d.y); }
VMATHDEF void mat4_colz(vec4 *r, mat4 *m) { vec4_setc(r, m->a.z, m->b.z, m->c.z, m->d.z); }
VMATHDEF void mat4_colw(vec4 *r, mat4 *m) { vec4_setc(r, m->a.w, m->b.w, m->c.w, m->d.w); }
// r = row(m, ?)
VMATHDEF void mat4_rowa(vec4 *r, mat4 *m) { vec4_set(r, &m->a); }
VMATHDEF void mat4_rowb(vec4 *r, mat4 *m) { vec4_set(r, &m->b); }
VMATHDEF void mat4_rowc(vec4 *r, mat4 *m) { vec4_set(r, &m->c); }
VMATHDEF void mat4_rowd(vec4 *r, mat4 *m) { vec4_set(r, &m->d); }

// r = s * m
VMATHDEF void mat4_scale(mat4 *r, scalar s, mat4 *m)
{
	vec4_scale(&r->a, s, &m->a);
	vec4_scale(&r->b, s, &m->b);
	vec4_scale(&r->c, s, &m->c);
	vec4_scale(&r->d, s, &m->d);
}

// scale rows with a,b,c,d
VMATHDEF void mat4_rsc(mat4 *r, mat4 *m, scalar a, scalar b, scalar c, scalar d)
{
	vec4_scale(&r->a, a, &m->a);
	vec4_scale(&r->b, b, &m->b);
	vec4_scale(&r->c, c, &m->c);
	vec4_scale(&r->d, d, &m->d);
}

// scale rows with v
VMATHDEF void mat4_rsv(mat4 *r, mat4 *m, vec4 *v)
{
	vec4_scale(&r->a, v->x, &m->a);
	vec4_scale(&r->b, v->y, &m->b);
	vec4_scale(&r->c, v->z, &m->c);
	vec4_scale(&r->d, v->w, &m->d);
}

// r = -m
VMATHDEF void mat4_neg(mat4 *r, mat4 *m)
{
	vec4_neg(&r->a, &m->a);
	vec4_neg(&r->b, &m->b);
	vec4_neg(&r->c, &m->c);
	vec4_neg(&r->d, &m->d);
}

// r = f + g
VMATHDEF void mat4_add(mat4 *r, mat4 *f, mat4 *g)
{
	vec4_add(&r->a, &f->a, &g->a);
	vec4_add(&r->b, &f->b, &g->b);
	vec4_add(&r->c, &f->c, &g->c);
	vec4_add(&r->d, &f->d, &g->d);
}

// r = f - g
VMATHDEF void mat4_sub(mat4 *r, mat4 *f, mat4 *g)
{
	vec4_sub(&r->a, &f->a, &g->a);
	vec4_sub(&r->b, &f->b, &g->b);
	vec4_sub(&r->c, &f->c, &g->c);
	vec4_sub(&r->d, &f->d, &g->d);
}

// r = f * g (term-wise)
VMATHDEF void mat4_tmul(mat4 *r, mat4 *f, mat4 *g)
{
	vec4_tmul(&r->a, &f->a, &g->a);
	vec4_tmul(&r->b, &f->b, &g->b);
	vec4_tmul(&r->c, &f->c, &g->c);
	vec4_tmul(&r->d, &f->d, &g->d);
}

// r = v x m (r != v)
VMATHDEF void _vec4_mul_mat4(vec4 *r, vec4 *v, mat4 *m)
{
	r->x = m->a.x * v->x + m->b.x * v->y + m->c.x * v->z + m->d.x * v->w;
	r->y = m->a.y * v->x + m->b.y * v->y + m->c.y * v->z + m->d.y * v->w;
	r->z = m->a.z * v->x + m->b.z * v->y + m->c.z * v->z + m->d.z * v->w;
	r->w = m->a.w * v->x + m->b.w * v->y + m->c.w * v->z + m->d.w * v->w;
}

// r = f x g
VMATHDEF void mat4_mul(mat4 *r, mat4 *f, mat4 *g)
{
	mat4 m;
	_vec4_mul_mat4(&m.a, &f->a, g);
	_vec4_mul_mat4(&m.b, &f->b, g);
	_vec4_mul_mat4(&m.c, &f->c, g);
	_vec4_mul_mat4(&m.d, &f->d, g);
	memcpy(r, &m, sizeof m);
}

// r = f + t * g
VMATHDEF void mat4_ma(mat4 *r, mat4 *f, scalar t, mat4 *g)
{
	vec4_ma(&r->a, &f->a, t, &g->a);
	vec4_ma(&r->b, &f->b, t, &g->b);
	vec4_ma(&r->c, &f->c, t, &g->c);
}

// r = s * f + t * g
VMATHDEF void mat4_comb(mat4 *r, scalar s, mat4 *f, scalar t, mat4 *g)
{
	vec4_comb(&r->a, s, &f->a, t, &g->a);
	vec4_comb(&r->b, s, &f->b, t, &g->b);
	vec4_comb(&r->c, s, &f->c, t, &g->c);
}

// r = (1 - t) * f + t * g
VMATHDEF void mat4_lerp(mat4 *r, mat4 *f, mat4 *g, scalar t)
{
	scalar s = 1 - t;
	vec4_comb(&r->a, s, &f->a, t, &g->a);
	vec4_comb(&r->b, s, &f->b, t, &g->b);
	vec4_comb(&r->c, s, &f->c, t, &g->c);
}

#define VDET2(a,b, c,d) ((a)*(d) - (b)*(c))
#define VDET3(a,b,c, d,e,f, g,h,i) \
	((a)*VDET2(e,f,h,i) - (b)*VDET2(d,f,g,i) + (c)*VDET2(d,e,g,h))
// = det(m)
VMATHDEF scalar mat4_det(mat4 *m)
{
	scalar s = 0;
	s += m->a.x * VDET3(m->b.y, m->b.z, m->b.w, m->c.y, m->c.z, m->c.w, m->d.y, m->d.z, m->d.w);
	s -= m->a.y * VDET3(m->b.x, m->b.z, m->b.w, m->c.x, m->c.z, m->c.w, m->d.x, m->d.z, m->d.w);
	s += m->a.z * VDET3(m->b.x, m->b.y, m->b.w, m->c.x, m->c.y, m->c.w, m->d.x, m->d.y, m->d.w);
	s -= m->a.w * VDET3(m->b.x, m->b.y, m->b.z, m->c.x, m->c.y, m->c.z, m->d.x, m->d.y, m->d.z);
	return s;
}

VMATHDEF scalar mat4_det3(mat4 *m)
{
	return m->a.x * (m->b.y * m->c.z - m->b.z * m->c.y)
	     - m->a.y * (m->b.x * m->c.z - m->b.z * m->c.x)
	     + m->a.z * (m->b.x * m->c.y - m->b.y * m->c.x);
}

// r = v x m
VMATHDEF void vec4_mul_mat4(vec4 *r, vec4 *v, mat4 *m)
{
	scalar x, y, z, w;
	x = m->a.x * v->x + m->b.x * v->y + m->c.x * v->z + m->d.x * v->w;
	y = m->a.y * v->x + m->b.y * v->y + m->c.y * v->z + m->d.y * v->w;
	z = m->a.z * v->x + m->b.z * v->y + m->c.z * v->z + m->d.z * v->w;
	w = m->a.w * v->x + m->b.w * v->y + m->c.w * v->z + m->d.w * v->w;
	r->x = x; r->y = y; r->z = z; r->w = w;
}

// r = m x v
VMATHDEF void mat4_mul_vec4(vec4 *r, mat4 *m, vec4 *v)
{
	scalar x, y, z, w;
	x = m->a.x * v->x + m->a.y * v->y + m->a.z * v->z + m->a.w * v->w;
	y = m->b.x * v->x + m->b.y * v->y + m->b.z * v->z + m->b.w * v->w;
	z = m->c.x * v->x + m->c.y * v->y + m->c.z * v->z + m->c.w * v->w;
	w = m->d.x * v->x + m->d.y * v->y + m->d.z * v->z + m->d.w * v->w;
	r->x = x; r->y = y; r->z = z; r->w = w;
}

// m = transpose(m)
VMATHDEF void mat4_trans(mat4 *m)
{
	scalar t;
	t = m->a.y; m->a.y = m->b.x; m->b.x = t;
	t = m->a.z; m->a.z = m->c.x; m->c.x = t;
	t = m->a.w; m->a.w = m->d.x; m->d.x = t;
	
	t = m->b.z; m->b.z = m->c.y; m->c.y = t;
	t = m->b.w; m->b.w = m->d.y; m->d.y = t;
	
	t = m->c.w; m->c.w = m->d.z; m->d.z = t;
}

// r = transpose(m)
VMATHDEF void mat4_transpose(mat4 *r, mat4 *m)
{
	scalar t;
	t = m->a.y; r->a.y = m->b.x; r->b.x = t;
	t = m->a.z; r->a.z = m->c.x; r->c.x = t;
	t = m->a.w; r->a.w = m->d.x; r->d.x = t;
	
	t = m->b.z; r->b.z = m->c.y; r->c.y = t;
	t = m->b.w; r->b.w = m->d.y; r->d.y = t;
	
	t = m->c.w; r->c.w = m->d.z; r->d.z = t;
	
	r->a.x = m->a.x; r->b.y = m->b.y; r->c.z = m->c.z; r->d.w = m->d.w;
}

// trace as a vector
VMATHDEF void mat4_vtrace(vec4 *v, mat4 *m)
{
	v->x = m->a.x; v->y = m->b.y;
	v->z = m->c.z; v->w = m->d.w;
}

// trace
VMATHDEF scalar mat4_trace(mat4 *m)
{
	return m->a.x + m->b.y + m->c.z + m->d.w;
}


// -------------------
// ---- mat other ----
// -------------------

VMATHDEF void mat3_set_mat4(mat3 *r, mat4 *m)
{
	vec3_set_vec4(&r->a, &m->a);
	vec3_set_vec4(&r->b, &m->b);
	vec3_set_vec4(&r->c, &m->c);
}

VMATHDEF void mat3_set_mat3x4(mat3 *r, mat3x4 *m)
{
	vec3_set_vec4(&r->a, &m->a);
	vec3_set_vec4(&r->b, &m->b);
	vec3_set_vec4(&r->c, &m->c);
}


VMATHDEF void mat3x4_set_mat3(mat3x4 *r, mat3 *m)
{
	vec4_set_vec3(&r->a, &m->a);
	vec4_set_vec3(&r->b, &m->b);
	vec4_set_vec3(&r->c, &m->c);
}

VMATHDEF void mat3x4_set_mat4(mat3x4 *r, mat4 *m)
{
	vec4_set(&r->a, &m->a);
	vec4_set(&r->b, &m->b);
	vec4_set(&r->c, &m->c);
}

VMATHDEF void mat4_set_mat3(mat4 *r, mat3 *m)
{
	vec4_set_vec3(&r->a, &m->a);
	vec4_set_vec3(&r->b, &m->b);
	vec4_set_vec3(&r->c, &m->c);
	vec4_setc(&r->d, 0, 0, 0, 1);
}

VMATHDEF void mat4_set_mat3x4(mat4 *r, mat3x4 *m)
{
	vec4_set(&r->a, &m->a);
	vec4_set(&r->b, &m->b);
	vec4_set(&r->c, &m->c);
	vec4_setc(&r->d, 0, 0, 0, 1);
}



// -------------------
// ----    quat   ----
// -------------------

VMATHDEF scalar quat_norm(quat *v)
{
	return v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w;
}

// r = 1
VMATHDEF void quat_id(quat *v)
{
	v->x = v->y = v->z = 0; v->w = 1;
}

// r = v^-1 (possible divby0)
VMATHDEF void quat_inv(quat *r, quat *v)
{
	scalar s = vsqrt(v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w);
	r->x = -(v->x / s); r->y = -(v->y / s);
	r->z = -(v->z / s); r->w =  (v->w / s);
}

// r = v'
VMATHDEF void quat_conj(quat *r, quat *v)
{
	r->x = -v->x; r->y = -v->y;
	r->z = -v->z; r->w =  v->w;
}

VMATHDEF void quat_set_vec3(quat *r, vec3 *v)
{
	r->x = v->x; r->y = v->y;
	r->z = v->z; r->w = 0;
}

VMATHDEF void vec3_set_quat(vec3 *r, quat *v)
{
	r->x = v->x; r->y = v->y; r->z = v->z;
}


// = u x v
VMATHDEF void quat_mul(quat *r, quat *u, quat *v)
{
	scalar x, y, z, w;
	w = u->w * v->w - u->x * v->x - u->y * v->y - u->z * v->z;
	x = u->w * v->x + u->x * v->w + u->y * v->z - u->z * v->y;
	y = u->w * v->y - u->x * v->z + u->y * v->w + u->z * v->x;
	z = u->w * v->z + u->x * v->y - u->y * v->x + u->z * v->w;
	r->x = x; r->y = y; r->z = z; r->w = w;
}

// = u x v
VMATHDEF void quat_mul_vec3(quat *r, quat *u, vec3 *v)
{
	scalar x, y, z, w;
	w = - u->x * v->x - u->y * v->y - u->z * v->z;
	x = u->w * v->x + u->y * v->z - u->z * v->y;
	y = u->w * v->y - u->x * v->z + u->z * v->x;
	z = u->w * v->z + u->x * v->y - u->y * v->x;
	r->x = x; r->y = y; r->z = z; r->w = w;
}

// = u x v
VMATHDEF void vec3_mul_quat(quat *r, vec3 *u, quat *v)
{
	scalar x, y, z, w;
	w = - u->x * v->x - u->y * v->y - u->z * v->z;
	x = + u->x * v->w + u->y * v->z - u->z * v->y;
	y = - u->x * v->z + u->y * v->w + u->z * v->x;
	z = + u->x * v->y - u->y * v->x + u->z * v->w;
	r->x = x; r->y = y; r->z = z; r->w = w;
}

// r = qvq'
VMATHDEF void vec3_rotate_quat(vec3 *r, quat *q, vec3 *v)
{
	quat p;
	quat_inv(&p, q);
	vec3_mul_quat(&p, v, &p);
	quat_mul(&p, q, &p);
	r->x = p.x; r->y = p.y; r->z = p.z;
}







// rotation m from unit q (v' = v * m)
VMATHDEF void mat3_from_quat(mat3 *m, quat *q)
{
	scalar x = q->x, y = q->y, z = q->z, w = q->w;
	
	m->a.x = 1 - 2 * (y * y + z * z);
	m->a.y = 2 * (x * y + z * w);
	m->a.z = 2 * (x * z - y * w);
	
	m->b.x = 2 * (x * y - z * w);
	m->b.y = 1 - 2 * (x * x + z * z);
	m->b.z = 2 * (y * z + x * w);
	
	m->c.x = 2 * (x * z + y * w);
	m->c.y = 2 * (y * z - x * w);
	m->c.z = 1 - 2 * (x * x + y * y);
}

// q from rotation m
VMATHDEF void quat_from_mat3(quat *q, mat3 *m)
{
	scalar t, x,y,z,w;
	scalar tr0 = m->a.x, tr1 = m->b.y, tr2 = m->c.z;
	if (tr0 < 0)
	{
		if (tr0 > tr1)
		{
			t = 1 + tr0 - tr1 - tr2;
			x = t;               y = m->a.y + m->b.x;
			z = m->c.x + m->a.z; w = m->b.z - m->c.y;
		}
		else
		{
			t = 1 - tr0 + tr1 - tr2;
			x = m->a.y + m->b.x; y = t;
			z = m->b.z + m->c.y; w = m->c.x - m->a.z;
		}
	}
	else
	{
		if (tr0 < -tr1)
		{
			t = 1 - tr0 - tr1 + tr2;
			x = m->c.x + m->a.z;  y = m->b.z + m->c.y;
			z = t;                w = m->a.y - m->b.x;
		}
		else
		{
			t = 1 + tr0 + tr1 + tr2;
			x = m->b.z - m->c.y; y = m->c.x - m->a.z;
			y = m->a.y - m->b.x; w = t;
		}
	}
	
	t = 0.5 / vsqrt(t);
	q->x = t * x; q->y = t * y; q->z = t * z; q->w = t * w;
}

#endif // VMATH_IMPLEMENTATION




#ifdef VEC_TEST
int main(void) {return 0;}
#endif