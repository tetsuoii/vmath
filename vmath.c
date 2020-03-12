#include <math.h>

#if !defined(VEC_PRECISION)
#define VEC_PRECISION 1
#endif

#if VEC_PRECISION == 1
typedef float scalar;
#elif VEC_PRECISION == 2
typedef double scalar;
#else
#error "unsupported scalar type"
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

typedef struct vec4_s
{
	scalar x, y, z, w;
} vec4, quad, plane;

// a,b,c,d are rows of the matrix
// i.e. row major matrix

typedef struct mat3x3_s
{
	vec3 a, b, c;
} mat3, mat3x3;

typedef struct mat3x4_s
{
	vec4 a, b, c;
	// d = {0, 0, 0, 1}
} mat3x4;

typedef struct mat4x4_s
{
	vec4 a, b, c, d;
} mat4, mat4x4;






#if VEC_PRECISION == 1
#define vsqrt sqrtf
#define vabs absf
#elif VEC_PRECISION == 2
#define vsqrt sqrt
#define vabs abs
#endif


// -------------------
// --- common vec2 ---
// -------------------

// = |v|^2
scalar vec2_len2(vec2 *v)
{
	return v->x * v->x + v->y * v->y;
}

// = |v|
scalar vec2_len(vec2 *v)
{
	return vsqrt(v->x * v->x + v->y * v->y);
}

// v = 0
void vec3_zero(vec3 *v)
{
	v->x = v->y = 0;
}

// v = {x, y}
void vec2_set(vec2 *v, scalar x, scalar y)
{
	v->x = x; v->y = y;
}

// r = v
void vec2_copy(vec2 *r, vec2 *v)
{
	r->x = v->x; r->y = v->y;
}

// r = s * v
void vec2_scale(vec2 *r, scalar s, vec2 *v)
{
	r->x = s * v->x; r->y = s * v->y;
}

// n = v / |v|
void vec2_norm(vec2 *n, vec2 *v)
{
	scalar s = v->x * v->x + v->y * v->y;
	if (s == 0)
	{
		n->x = n->y = 0;
		return;
	}
	s = 1 / vsqrt(s);
	n->x = s * v->x; n->y = s * v->y;
}

// r = u + v
void vec2_add(vec2 *r, vec2 *u, vec2 *v)
{
	r->x = u->x + v->x; r->y = u->y + v->y;
}

// r = u - v
void vec2_sub(vec2 *r, vec2 *u, vec2 *v)
{
	r->x = u->x - v->x; r->y = u->y - v->y;
}

// = u · v
scalar vec2_dot(vec2 *u, vec2 *v)
{
	return u->x * v->x + u->y * v->y;
}

// r = u + s * v
void vec2_ma(vec2 *r, vec2 *u, scalar s, vec2 *v)
{
	r->x = u->x + s * v->x; r->y = u->y + s * v->y;
}

// = |u - v|^2
scalar vec2_dist2(vec2 *u, vec2 *v)
{
	scalar t, d;
	t = u->x - v->x; d  = t * t;
	t = u->y - v->y; d += t * t;
	return d;
}

// |u - v|
scalar vec2_dist(vec2 *u, vec2 *v)
{
	scalar t, d;
	t = u->x - v->x; d  = t * t;
	t = u->y - v->y; d += t * t;
	return vsqrt(d);
}

// = ||u - v||
scalar vec2_dist0(vec2 *u, vec2 *v)
{
	return vabs(u->x - v->x) + vabs(u->y - v->y);
}


// -------------------
// --- common vec3 ---
// -------------------

// = |v|^2
scalar vec3_len2(vec3 *v)
{
	return v->x * v->x + v->y * v->y + v->z * v->z;
}

// = |v|
scalar vec3_len(vec3 *v)
{
	return vsqrt(v->x * v->x + v->y * v->y + v->z * v->z);
}

// v = 0
void vec3_zero(vec3 *v)
{
	v->x = v->y = v->z = 0;
}

// r = {x, y, z}
void vec3_set(vec3 *v, scalar x, scalar y, scalar z)
{
	v->x = x; v->y = y; v->z = z;
}

// r = v
void vec3_copy(vec3 *r, vec3 *v)
{
	r->x = v->x; r->y = v->y; r->z = v->z;
}

// r = s * v
void vec3_scale(vec3 *r, scalar s, vec3 *v)
{
	r->x = s * v->x; r->y = s * v->y; r->z = s * v->z;
}

// n = v / |v|
void vec3_norm(vec3 *n, vec3 *v)
{
	scalar s = v->x * v->x + v->y * v->y + v->z * v->z;
	if (s == 0)
	{
		n->x = n->y = n->z = 0;
		return;
	}
	s = 1 / vsqrt(s);
	n->x = s * v->x; n->y = s * v->y; n->z = s * v->z;
}

// r = u + v
void vec3_add(vec3 *r, vec3 *u, vec3 *v)
{
	r->x = u->x + v->x; r->y = u->y + v->y; r->z = u->z + v->z;
}

// r = u - v
void vec3_sub(vec3 *r, vec3 *u, vec3 *v)
{
	r->x = u->x - v->x; r->y = u->y - v->y; r->z = u->z - v->z;
}

// = u · v
scalar vec3_dot(vec3 *u, vec3 *v)
{
	return u->x * v->x + u->y * v->y + u->z * v->z;
}

// r = u + s * v
void vec3_ma(vec3 *r, vec3 *u, scalar s, vec3 *v)
{
	r->x = u->x + s * v->x; r->y = u->y + s * v->y; r->z = u->z + s * v->z;
}

// = |u - v|^2
scalar vec3_dist2(vec3 *u, vec3 *v)
{
	scalar t, d;
	t = u->x - v->x; d  = t * t;
	t = u->y - v->y; d += t * t;
	t = u->z - v->z; d += t * t;
	return d;
}

// |u - v|
scalar vec3_dist(vec3 *u, vec3 *v)
{
	scalar t, d;
	t = u->x - v->x; d  = t * t;
	t = u->y - v->y; d += t * t;
	t = u->z - v->z; d += t * t;
	return vsqrt(d);
}

// = ||u - v||
scalar vec3_dist0(vec3 *u, vec3 *v)
{
	return vabs(u->x - v->x) + vabs(u->y - v->y) + vabs(u->z - v->z);
}


// -------------------
// --- common vec4 ---
// -------------------

// = |v|^2
scalar vec4_len2(vec4 *v)
{
	return v->x * v->x + v->y * v->y
	     + v->z * v->z + v->w * v->w;
}

// = |v|
scalar vec4_len(vec4 *v)
{
	return vsqrt(v->x * v->x + v->y * v->y
	           + v->z * v->z + v->w * v->w);
}

// v = 0
void vec4_zero(vec4 *v)
{
	v->x = v->y = v->z = v->w = 0;
}

// v = {x, y, z, w}
void vec4_set(vec4 *v, scalar x, scalar y, scalar z, scalar w)
{
	v->x = x; v->y = y; v->z = z; v->w = w;
}

// r = v
void vec4_copy(vec4 *r, vec4 *v)
{
	r->x = v->x; r->y = v->y;
	r->z = v->z; r->w = v->w;
}

// r = s * v
void vec4_scale(vec4 *r, scalar s, vec4 *v)
{
	r->x = s * v->x; r->y = s * v->y;
	r->z = s * v->z; r->w = s * v->w;
}

// n = v / |v|
void vec4_norm(vec4 *n, vec4 *v)
{
	scalar s = v->x * v->x + v->y * v->y
	         + v->z * v->z + v->w * v->w;
	if (s == 0)
	{
		n->x = n->y = n->z = n->w = 0;
	}
	s = 1 / vsqrt(s);
	n->x = s * v->x; n->y = s * v->y;
	n->z = s * v->z; n->w = s * v->w;
}

// r = u + v
void vec4_add(vec4 *r, vec4 *u, vec4 *v)
{
	r->x = u->x + v->x; r->y = u->y + v->y;
	r->z = u->z + v->z; r->w = u->w + v->w;
}

// r = u - v
void vec4_sub(vec4 *r, vec4 *u, vec4 *v)
{
	r->x = u->x - v->x; r->y = u->y - v->y;
	r->z = u->z - v->z; r->w = u->w - v->w;
}

// = u · v
scalar vec4_dot(vec4 *u, vec4 *v)
{
	return u->x * v->x + u->y * v->y
	     + u->z * v->z + u->w * v->w;
}

// r = u + s * v
void vec4_ma(vec4 *r, vec4 *u, scalar s, vec4 *v)
{
	r->x = u->x + s * v->x; r->y = u->y + s * v->y;
	r->z = u->z + s * v->z; r->w = u->w + s * v->w;
}

// = |u - v|^2
scalar vec4_dist2(vec4 *u, vec4 *v)
{
	scalar t, d;
	t = u->x - v->x; d  = t * t;
	t = u->y - v->y; d += t * t;
	t = u->z - v->z; d += t * t;
	t = u->w - v->w; d += t * t;
	return d;
}

// |u - v|
scalar vec4_dist(vec4 *u, vec4 *v)
{
	scalar t, d;
	t = u->x - v->x; d  = t * t;
	t = u->y - v->y; d += t * t;
	t = u->z - v->z; d += t * t;
	t = u->w - v->w; d += t * t;
	return vsqrt(d);
}

// = ||u - v||
scalar vec4_dist0(vec4 *u, vec4 *v)
{
	return vabs(u->x - v->x) + vabs(u->y - v->y)
	     + vabs(u->z - v->z) + vabs(u->w - v->w);
}


// -------------------
// --- conversions ---
// -------------------

// vec2 = vec3
void vec2_from3(vec2 *r, vec3 *v)
{
	r->x = v->x; r->y = v->y;
}

// vec2 = vec4
void vec2_from4(vec2 *r, vec4 *v)
{
	r->x = v->x; r->y = v->y; 
}

// vec3 = vec2
void vec3_from2(vec3 *r, vec2 *v)
{
	r->x = v->x; r->y = v->y; r->z = 0; 
}

// vec3 = vec4
void vec3_from4(vec3 *r, vec2 *v)
{
	r->x = v->x; r->y = v->y; r->z = v->z; 
}

// vec4 = vec2
void vec4_from2(vec4 *r, vec2 *v)
{
	r->x = v->x; r->y = v->y; r->z = r->w = 0; 
}

// vec4 = vec3
void vec4_from3(vec4 *r, vec2 *v)
{
	r->x = v->x; r->y = v->y; r->z = v->z; r->w = 0; 
}


// -------------------
// ---- vec other ----
// -------------------

// = u x v (scalar since first 2 component is always 0)
scalar vec2_x(vec2 *u, vec2 *v)
{
	return u->x * v->y - u->y * v->x;
}

// = u x v
void vec3_cross(vec3 *r, vec3 *u, vec3 *v)
{
	scalar x, y, z;
	x = u->y * v->z - u->z * v->y;
	y = u->z * v->x - u->x * v->z;
	z = u->x * v->y - u->y * v->x;
	r->x = x; r->y = y; r->z = z;
}

void mat3_zero(mat3 *m)     { memset(m, 0, sizeof(mat3));   }
void mat3x4_zero(mat3x4 *m) { memset(m, 0, sizeof(mat3x4)); }
void mat4_zero(mat4 *m)     { memset(m, 0, sizeof(mat4));   }

// m = I
void mat3_id(mat3 *m)
{
	mat3_zero(m);
	m->a.x = m->b.y = m->c.z = 1;
}

// m = I
void mat3x4_id(mat3x4 *m)
{
	mat3x4_zero(m);
	m->a.x = m->b.y = m->c.z = 1;
}

// m = I
void mat4_id(mat4 *m)
{
	mat4_zero(m)
	m->a.x = m->b.y = m->c.z = m->d.w = 1;
}

// r = v x m
void vec3_mul_mat3(vec3 *r, vec3 *v, mat3 *m)
{
	scalar x, y, z;
	x = m->a.x * v->x + m->b.x * v->y + m->c.x * v->z;
	y = m->a.y * v->x + m->b.y * v->y + m->c.y * v->z;
	z = m->a.z * v->x + m->b.z * v->y + m->c.z * v->z;
	r->x = x; r->y = y; r->z = z;
}

// r = m x v
void mat3_mul_vec3(vec3 *r, mat3 *m, vec3 *v)
{
	scalar x, y, z;
	x = m->a.x * v->x + m->a.y * v->y + m->a.z * v->z;
	y = m->b.x * v->x + m->b.y * v->y + m->b.z * v->z;
	z = m->c.x * v->x + m->c.y * v->y + m->c.z * v->z;
	r->x = x; r->y = y; r->z = z;
}

// r = v x m
void vec4_mul_mat3x4(vec4 *r, vec4 *v, mat3x4 *m)
{
	scalar x, y, z, w;
	x = m->a.x * v->x + m->b.x * v->y + m->c.x * v->z;
	y = m->a.y * v->x + m->b.y * v->y + m->c.y * v->z;
	z = m->a.z * v->x + m->b.z * v->y + m->c.z * v->z;
	w = m->a.w * v->x + m->b.w * v->y + m->c.w * v->z + v->w;
	r->x = x; r->y = y; r->z = z; r->w = w;
}

// r = m x v
void mat3x4_mul_vec4(vec4 *r, mat3x4 *m, vec4 *v)
{
	scalar x, y, z, w;
	x = m->a.x * v->x + m->a.y * v->y + m->a.z * v->z + m->a.w * v->w;
	y = m->b.x * v->x + m->b.y * v->y + m->b.z * v->z + m->b.w * v->w;
	z = m->c.x * v->x + m->c.y * v->y + m->c.z * v->z + m->c.w * v->w;
	w = v->w;
	r->x = x; r->y = y; r->z = z; r->w = w;
}

// r = v x m
void vec4_mul_mat4(vec4 *r, vec4 *v, mat4 *m)
{
	scalar x, y, z, w;
	x = m->a.x * v->x + m->b.x * v->y + m->c.x * v->z + m->d.x * v->w;
	y = m->a.y * v->x + m->b.y * v->y + m->c.y * v->z + m->d.y * v->w;
	z = m->a.z * v->x + m->b.z * v->y + m->c.z * v->z + m->d.z * v->w;
	w = m->a.w * v->x + m->b.w * v->y + m->c.w * v->z + m->d.w * v->w;
	r->x = x; r->y = y; r->z = z; r->w = w;
}

// r = m x v
void mat4_mul_vec4(vec4 *r, mat4 *m, vec4 *v)
{
	scalar x, y, z, w;
	x = m->a.x * v->x + m->a.y * v->y + m->a.z * v->z + m->a.w * v->w;
	y = m->b.x * v->x + m->b.y * v->y + m->b.z * v->z + m->b.w * v->w;
	z = m->c.x * v->x + m->c.y * v->y + m->c.z * v->z + m->c.w * v->w;
	w = m->d.x * v->x + m->d.y * v->y + m->d.z * v->z + m->d.w * v->w;
	r->x = x; r->y = y; r->z = z; r->w = w;
}

// r = v x m (r != v)
void _vec3_mul_mat3(vec3 *r, vec3 *v, mat3 *m)
{
	r->x = m->a.x * v->x + m->b.x * v->y + m->c.x * v->z;
	r->y = m->a.y * v->x + m->b.y * v->y + m->c.y * v->z;
	r->z = m->a.z * v->x + m->b.z * v->y + m->c.z * v->z;
}

// r = f x g
void mat3_mul(mat3 *r, mat3 *f, mat3 *g)
{
	mat3 m;
	_vec3_mul_mat3(&m->a, &f->a, g);
	_vec3_mul_mat3(&m->b, &f->b, g);
	_vec3_mul_mat3(&m->c, &f->c, g);
	*r = m; // memcpy?
}

// r = v x m (r != v)
void _vec4_mul_mat3x4(vec4 *r, vec4 *v, mat3x4 *m)
{
	r->x = m->a.x * v->x + m->b.x * v->y + m->c.x * v->z;
	r->y = m->a.y * v->x + m->b.y * v->y + m->c.y * v->z;
	r->z = m->a.z * v->x + m->b.z * v->y + m->c.z * v->z;
	r->w = m->a.w * v->x + m->b.w * v->y + m->c.w * v->z + v->w;
}

// r = f x g
void mat3x4_mul(mat3x4 *r, mat3x4 *f, mat3x4 *g)
{
	mat3x4 m;
	_vec4_mul_mat3x4(&m->a, &f->a, g);
	_vec4_mul_mat3x4(&m->b, &f->b, g);
	_vec4_mul_mat3x4(&m->c, &f->c, g);
	*r = m; // memcpy?
}

// r = v x m (r != v)
void _vec4_mul_mat4(vec4 *r, vec4 *v, mat4 *m)
{
	r->x = m->a.x * v->x + m->b.x * v->y + m->c.x * v->z + m->d.x * v->w;
	r->y = m->a.y * v->x + m->b.y * v->y + m->c.y * v->z + m->d.y * v->w;
	r->z = m->a.z * v->x + m->b.z * v->y + m->c.z * v->z + m->d.z * v->w;
	r->w = m->a.w * v->x + m->b.w * v->y + m->c.w * v->z + m->d.w * v->w;
}

// r = f x g
void mat4_mul(mat4 *r, mat4 *f, mat4 *g)
{
	mat4 m;
	_vec4_mul_mat4(&m->a, &f->a, g);
	_vec4_mul_mat4(&m->b, &f->b, g);
	_vec4_mul_mat4(&m->c, &f->c, g);
	_vec4_mul_mat4(&m->d, &f->d, g);
	*r = m; // memcpy?
}



// r = transpose(m)
void mat3_trans(mat3 *r, mat3 *m)
{
	scalar t;
	t = m->a.y; m->a.y = m->b.x; m->b.x = t;
	t = m->a.z; m->a.z = m->c.x; m->c.x = t;
	
	t = m->b.z; m->b.z = m->c.y; m->c.y = t;
}

// r = transpose(m) ?
void mat3x4_trans(mat3x4 *r, mat3x4 *m)
{
	scalar t;
	t = m->a.y; m->a.y = m->b.x; m->b.x = t;
	t = m->a.z; m->a.z = m->c.x; m->c.x = t;
	
	t = m->b.z; m->b.z = m->c.y; m->c.y = t;
}

// r = transpose(m)
void mat4_trans(mat4 *r, mat4 *m)
{
	scalar t;
	t = m->a.y; m->a.y = m->b.x; m->b.x = t;
	t = m->a.z; m->a.z = m->c.x; m->c.x = t;
	t = m->a.w; m->a.w = m->d.x; m->d.x = t;
	
	t = m->b.z; m->b.z = m->c.y; m->c.y = t;
	t = m->b.w; m->b.w = m->d.y; m->d.y = t;

	t = m->c.w; m->c.w = m->d.z; m->d.z = t;
}



void mat3_from4(mat3 *r, mat4 *m)
{
	vec3_from4(&r->a, &m->a);
	vec3_from4(&r->b, &m->b);
	vec3_from4(&r->c, &m->c);
}

void mat3_from3x4(mat3 *r, mat3x4 *m)
{
	vec3_from4(&r->a, &m->a);
	vec3_from4(&r->b, &m->b);
	vec3_from4(&r->c, &m->c);
}


void mat3x4_from3(mat3x4 *r, mat3 *m)
{
	vec4_from3(&r->a, &m->a);
	vec4_from3(&r->b, &m->b);
	vec4_from3(&r->c, &m->c);
}

void mat3x4_from4(mat3x4 *r, mat4 *m)
{
	vec4_copy(&r->a, &m->a);
	vec4_copy(&r->b, &m->b);
	vec4_copy(&r->c, &m->c);
}

void mat4_from3(mat4 *r, mat3 *m)
{
	vec4_from3(&r->a, &m->a);
	vec4_from3(&r->b, &m->b);
	vec4_from3(&r->c, &m->c);
	vec4_set(&r->d, 0, 0, 0, 1);
}

void mat4_from3x4(mat4 *r, mat3x4 *m)
{
	vec4_copy(&r->a, &m->a);
	vec4_copy(&r->b, &m->b);
	vec4_copy(&r->c, &m->c);
	vec4_set(&r->d, 0, 0, 0, 1);
}