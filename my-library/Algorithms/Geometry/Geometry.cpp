#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

//#define DEBUG
//#define int long long
#define COOL_LD 0
#define LD 1
#define INT 2
#define MYLD COOL_LD

#ifdef DEBUG
void check_warning(bool expr, string warning = "WARNING", int line = nan(""), string file = "---") {
	if (!expr) {
		cerr << warning << " (LINE: " << line << ", FILE: " << file << ").\n";
	}
}
void check_error(bool expr, string error = "ERROR", int line = nan(""), string file = "---") {
	if (!expr) {
		cerr << error << " (LINE: " << line << ", FILE: " << file << ").\n";
		exit(3);
	}
}
#else
void check_warning(bool expr, string warning = "WARNING", int line = nan(""), string file = "---") {}
void check_error(bool expr, string error = "ERROR", int line = nan(""), string file = "---") {}
#endif // DEBUG

#if MYLD == COOL_LD
const long double EPS = 1e-9;

long double my_abs(long double x) { return x < 0 ? -x : x; }
long double my_sqrt(long double x) { return x < 0 ? 0 : sqrt(x); }
int sign(long double x) {
	if (abs(x) <= EPS) {
		return 0;
	}
	return x < 0 ? -1 : +1;
}
int my_sign(long double x) {
	if (abs(x) <= EPS) {
		return 0;
	}
	return x < 0 ? -1 : +1;
}
long double my_atan2(long double y, long double x) { return atan2(y, x); }

namespace myld {
	struct ld {
		long double x;

		ld() {}
		ld(int _x) : x(_x) {}
		ld(long long _x) : x(_x) {}
		ld(float _x) : x(_x) {}
		ld(double _x) : x(_x) {}
		ld(long double _x) : x(_x) {}
	};
	istream& operator>>(istream &in, ld &a) { return in >> a.x; }
	ostream& operator<<(ostream &out, ld a) { return out << a.x; }
	bool operator==(ld a, ld b) { return my_abs(a.x - b.x) <= EPS; }
	bool operator!=(ld a, ld b) { return !(a == b); }
	bool operator<(ld a, ld b) { return a.x + EPS < b.x; }
	bool operator<=(ld a, ld b) { return a < b || a == b; }
	bool operator>(ld a, ld b) { return a.x > b.x + EPS; }
	bool operator>=(ld a, ld b) { return a > b || a == b; }
	ld operator+(ld a) { return a.x; }
	ld operator-(ld a) { return -a.x; }
	ld operator+(ld a, ld b) { return a.x + b.x; }
	ld& operator+=(ld &a, ld b) { return a = a + b; }
	ld operator-(ld a, ld b) { return a.x - b.x; }
	ld& operator-=(ld &a, ld b) { return a = a - b; }
	ld operator*(ld a, ld b) { return a.x * b.x; }
	ld& operator*=(ld &a, ld b) { return a = a * b; }
	ld operator/(ld a, ld b) { return a.x / b.x; }
	ld& operator/=(ld &a, ld b) { return a = a / b; }
	template<class T> bool operator==(ld a, T b) { return my_abs(a.x - b) < EPS; }
	template<class T> bool operator!=(ld a, T b) { return !(a == b); }
	template<class T> bool operator<(ld a, T b) { return a.x + EPS < b; }
	template<class T> bool operator<=(ld a, T b) { return a < b || a == b; }
	template<class T> bool operator>(ld a, T b) { return a.x > b + EPS; }
	template<class T> bool operator>=(ld a, T b) { return a > b || a == b; }
	template<class T> ld operator+(ld a, T b) { return a.x + b; }
	template<class T> ld& operator+=(ld &a, T b) { return a = a + b; }
	template<class T> ld operator-(ld a, T b) { return a.x - b; }
	template<class T> ld& operator-=(ld &a, T b) { return a = a - b; }
	template<class T> ld operator*(ld a, T b) { return a.x * b; }
	template<class T> ld& operator*=(ld &a, T b) { return a = a * b; }
	template<class T> ld operator/(ld a, T b) { return a.x / b; }
	template<class T> ld& operator/=(ld &a, T b) { return a = a / b; }
	template<class T> bool operator==(T a, ld b) { return my_abs(a - b.x) < EPS; }
	template<class T> bool operator!=(T a, ld b) { return !(a == b); }
	template<class T> bool operator<(T a, ld b) { return a + EPS < b.x; }
	template<class T> bool operator<=(T a, ld b) { return a < b || a == b; }
	template<class T> bool operator>(T a, ld b) { return a > b.x + EPS; }
	template<class T> bool operator>=(T a, ld b) { return a > b || a == b; }
	template<class T> ld operator+(T a, ld b) { return a + b.x; }
	template<class T> ld& operator+=(T &a, ld b) { return a = a + b; }
	template<class T> ld operator-(T a, ld b) { return a - b.x; }
	template<class T> ld& operator-=(T &a, ld b) { return a = a - b; }
	template<class T> ld operator*(T a, ld b) { return a * b.x; }
	template<class T> ld& operator*=(T &a, ld b) { return a = a * b; }
	template<class T> ld operator/(T a, ld b) { return a / b.x; }
	template<class T> ld& operator/=(T &a, ld b) { return a = a / b; }
}

using namespace myld;

ld abs(ld a) { return my_abs(a.x); }
ld my_sqrt(ld a) { return my_sqrt(a.x); }
ld atan2(ld a, ld b) { return my_atan2(a.x, b.x); }
int sign(ld a) { return my_sign(a.x); }
#elif MYLD == LD
typedef long double ld;

ld my_sqrt(ld x) { return x < 0 ? 0 : sqrt(x); }
int sign(ld x) {
	if (x == 0) {
		return 0;
	}
	return x < 0 ? -1 : +1;
}
#elif MYLD == INT
typedef int ld;

int my_sqrt(int x) { return sqrt(x); }
int sign(ld x) {
	if (x == 0) {
		return 0;
	}
	return x < 0 ? -1 : +1;
}
#endif

namespace myg2d {
	const long double PI = ::atan2(0, -1);

	struct Point;
	struct Vector;
	ld dist2(Point A, Point B);
	ld dist(Point A, Point B);
	ld dot_product(Vector a, Vector b);
	ld cross_product(Vector a, Vector b);
	bool operator==(Point A, Point B);
	Point operator+(Point A, Vector a);
	Vector operator*(Vector a, ld k);


	/* Definition */
	struct Point {
		ld x, y;

		Point() {}
		Point(ld _x, ld _y) : x(_x), y(_y) {}
	};
	struct Vector {
		ld x, y;

		Vector() {}
		Vector(ld _x, ld _y) : x(_x), y(_y) {}
		Vector(Point A) : x(A.x), y(A.y) {}
		Vector(Point A, Point B) : x(B.x - A.x), y(B.y - A.y) {}
	};
	struct Seg {
		Point A, B;

		Seg() {}
		Seg(Point _A, Point _B) : A(_A), B(_B) {}
	};
	struct Ray {
		Point O;
		Vector r;

		Ray() {}
		Ray(Point _O, Vector _r) : O(_O), r(_r) {}
		Ray(Point A, Point B) : O(A), r(A, B) {}
	};
	struct Angle {
		Point A, O, B;

		Angle() {}
		Angle(Point _A, Point _O, Point _B) : A(_A), O(_O), B(_B) {}
	};
	struct Line {
		ld a, b, c;

		ld get(Point A) { return a * A.x + b * A.y + c; }
		Vector dir_vec() { return Vector(-b, a); }

		ld operator()(Point A) { return get(A); }
		Point operator[](int i) {
			return Point(-a * c / (a * a + b * b), -b * c / (a * a + b * b))
				+ dir_vec() * i;
		}

		void init(Point A, Point B) {
			a = A.y - B.y;
			b = B.x - A.x;
			c = -(a * A.x + b * A.y);
		}

		Line() {}
		Line(ld _a, ld _b, ld _c) : a(_a), b(_b), c(_c) {}
		Line(Point A, Point B) { init(A, B); }
		Line(Seg s) { init(s.A, s.B); }
		Line(Point A, Vector r) { init(A, A + r); }
		Line(Ray f) { init(f.O, f.O + f.r); }
	};
	struct Circle {
		Point O;
		ld r;

		Circle() {}
		Circle(Point _O, ld _r) : O(_O), r(_r) {}
	};
	struct Triangle {
		Point A, B, C;

		vector<ld> get_sides2() { return { dist2(A, B), dist2(B, C), dist2(C, A) }; }
		vector<ld> get_sides() { return { dist(A, B), dist(B, C), dist(C, A) }; }

		vector<ld> get_sorted_sides2() {
			vector<ld> sides = get_sides2();
			sort(sides.begin(), sides.end());
			return sides;
		}

		Triangle() {}
		Triangle(Point _A, Point _B, Point _C) : A(_A), B(_B), C(_C) {}
	};
	struct Polygon : vector<Point> {
		Polygon() {}
		Polygon(int n) { resize(n); }
		Polygon(vector<Point> p) { *this = p; }
		Polygon(Triangle t) { *this = vector<Point>({ t.A, t.B, t.C }); }
	};


	/* Secondary functions */
	pair<ld, ld> make_pair(Point A) { return { A.x, A.y }; }
	pair<ld, ld> make_pair(Vector a) { return { a.x, a.y }; }
	pair<Point, Point> make_pair(Seg q) { return { q.A, q.B }; }


	/* Operators */
	istream& operator>>(istream &in, Point &A) { return in >> A.x >> A.y; }
	istream& operator>>(istream &in, Vector &a) { return in >> a.x >> a.y; }
	istream& operator>>(istream &in, Seg &q) { return in >> q.A >> q.B; }
	istream& operator>>(istream &in, Ray &g) { return in >> g.O >> g.r; }
	istream& operator>>(istream &in, Angle &phi) { return in >> phi.A >> phi.O >> phi.B; }
	istream& operator>>(istream &in, Line &n) { return in >> n.a >> n.b >> n.c; }
	istream& operator>>(istream &in, Circle &w) { return in >> w.O >> w.r; }
	istream& operator>>(istream &in, Triangle &t) { return in >> t.A >> t.B >> t.C; }
	istream& operator>>(istream &in, Polygon &p) {
		int n;
		in >> n;
		p.resize(n);
		for (int i = 0; i < n; ++i) {
			in >> p[i];
		}
		return in;
	}
	ostream& operator<<(ostream &out, Point A) { return out << A.x << ' ' << A.y; }
	ostream& operator<<(ostream &out, Vector a) { return out << a.x << ' ' << a.y; }
	ostream& operator<<(ostream &out, Seg q) { return out << q.A << ' ' << q.B; }
	ostream& operator<<(ostream &out, Ray g) { return out << g.O << '\n' << g.r; }
	ostream& operator<<(ostream &out, Angle phi) { return out << phi.A << '\n' << phi.O << '\n' << phi.B << '\n'; }
	ostream& operator<<(ostream &out, Line n) { return out << n.a << ' ' << n.b << ' ' << n.c; }
	ostream& operator<<(ostream &out, Circle a) { return out << a.O << ' ' << a.r; }
	ostream& operator<<(ostream &out, Triangle t) { return out << t.A << '\n' << t.B << '\n' << t.C; }
	ostream& operator<<(ostream &out, Polygon p) {
			for (Point A : p) {
				out << A << '\n';
			}
			return out;
		}
	bool operator==(Point A, Point B) { return make_pair(A) == make_pair(B); }
	bool operator==(Vector a, Vector b) { return make_pair(a) == make_pair(b); }
	bool operator==(Seg q, Seg e) { return make_pair(q) == make_pair(e); }
	// TODO: operator==(Ray g, Ray h)
	// TODO: operator==(Angle phi, Angle psi)
	bool operator==(Line n, Line m) {
		return n.a * m.b == n.b * m.a && n.b * m.c == n.c * m.b && n.c * m.a == n.a * m.c;
	}
	bool operator==(Circle w, Circle u) { return w.O == u.O && w.r == u.r; }
	bool operator==(Triangle t, Triangle r) { return t.get_sorted_sides2() == r.get_sorted_sides2(); }
	// TODO: operator==(Polygon p, Polygon r)
	bool operator!=(Point A, Point B) { return !(A == B); }
	bool operator!=(Vector a, Vector b) { return !(a == b); }
	bool operator!=(Seg q, Seg e) { return !(q == e); }
	// TODO: operator!=(Ray g, Ray h)
	// TODO: operator!=(Angle phi, Angle psi)
	bool operator!=(Line n, Line m) { return !(n == m); }
	bool operator!=(Triangle t, Triangle r) { return !(t == r); }
	bool operator!=(Circle w, Circle u) { return !(w == u); }
	// TODO: operator!=(Polygon p, Polygon r)
	Point operator+(Point A, Point B) { return { A.x + B.x, A.y + B.y }; }
	Point operator+(Point A, Vector a) { return { A.x + a.x, A.y + a.y }; }
	Point& operator+=(Point &A, Vector a) { return A = A + a; }
	Point operator-(Point A, Vector a) { return { A.x - a.x, A.y - a.y }; }
	Point& operator-=(Point &A, Vector a) { return A = A - a; }
	Vector operator-(Vector a) { return { -a.x, -a.y }; }
	Vector operator*(ld k, Vector a) { return { a.x * k, a.y * k }; }
	Vector operator*(Vector a, ld k) { return k * a; }
	Vector& operator*=(Vector &a, ld k) { return a = a * k; }
	Vector operator/(Vector a, ld k) { return (1 / k) * a; }
	Vector& operator/=(Vector &a, ld k) { return a = a / k; }
	Vector operator+(Vector a, Vector b) { return { a.x + b.x, a.y + b.y }; }
	Vector& operator+=(Vector &a, Vector b) { return a = a + b; }
	Vector operator-(Vector a, Vector b) { return { a.x - b.x, a.y - b.y }; }
	Vector& operator-=(Vector &a, Vector b) { return a = a - b; }
	Line operator+(Line n, Vector a) {
		n.c -= n.a * a.x + n.b * a.y;
		return n;
	}
	Line operator-(Line n, Vector a) { return n + -a; }
	Line& operator+=(Line &n, Vector a) { return n = n + a; }
	Line& operator-=(Line &n, Vector a) { return n = n - a; }


	/* Basic functions */
	ld dist2(Point A, Point B) { return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y); }
	ld dist2(Vector a) { return a.x * a.x + a.y * a.y; }
	ld dist2(Seg s) { return dist2(s.A, s.B); }
	ld dist(Point A, Point B) { return my_sqrt(dist2(A, B)); }
	ld dist(Vector a) { return my_sqrt(dist2(a)); }
	ld dist(Seg q) { return my_sqrt(dist2(q)); }
	ld dist(Point A, Line n) { return n(A) / my_sqrt(n.a * n.a + n.b * n.b); }
	ld double_s(Triangle t) { return cross_product(Vector(t.A, t.B), Vector(t.A, t.C)); }
	ld double_s(Polygon p) {
		ld res = 0;
		for (int i = 1; i < p.size() - 1; ++i) {
			res += double_s(Triangle(p[0], p[i], p[i + 1]));
		}
		return res;
	}
	ld s(Triangle t) { return double_s(t) / 2; }
	ld s(Polygon p) { return double_s(p) / 2; }
	ld s(Circle w) { return PI * w.r * w.r; }
	ld perimeter(Polygon p) {
		if (p.empty()) {
			return 0;
		}
		ld res = dist(p.back(), p[0]);
		for (int i = 1; i < p.size(); ++i) {
			res += dist(p[i], p[i - 1]);
		}
		return res;
	}
	ld perimeter(Triangle t) { return perimeter(Polygon(t)); }
	ld dot_product(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
	ld cross_product(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }
	ld atan2(Point A) { return ::atan2(A.y, A.x); }
	ld atan2(Vector a) { return ::atan2(a.y, a.x); }
	ld atan2(Vector a, Vector b) { return ::atan2(cross_product(a, b), dot_product(a, b)); }


	/* Checkers */
	bool on(Point P, Line n) { return n.get(P) == 0; }
	bool on(Point P, Seg q) {
		return dot_product(Vector(P, q.A), Vector(P, q.B)) <= 0
			&& cross_product(Vector(P, q.A), Vector(P, q.B)) == 0;
	}
	bool on(Point P, Ray g) {
		return dot_product(g.r, Vector(g.O, P)) >= 0
			&& cross_product(g.r, Vector(g.O, P)) == 0;
	}
	bool in(Point P, Angle phi) { return P == phi.O || abs(atan2(Vector(phi.O, phi.A), Vector(phi.O, phi.B))) == abs(atan2(Vector(phi.O, phi.A), Vector(phi.O, P))) + abs(atan2(Vector(phi.O, P), Vector(phi.O, phi.B))); } // TODO: improve
	bool in(Point P, Polygon p);
	bool in(Point P, Triangle t) { return in(P, Polygon(t)); } // TODO: improve
	// TODO: in_convex_hull(Point P, Polygon p)
	bool in(Point P, Circle a) { return dist2(a.O, P) <= a.r * a.r; }
	bool cross(Seg q, Seg e) {
		Line n(q), m(e);
		return sign(m(q.A)) * sign(m(q.B)) <= 0
			&& sign(n(e.A)) * sign(n(e.B)) <= 0;
	} // TODO: improve
	bool is_left(Vector a, Vector b) { return cross_product(a, b) <= 0; } // clockwise
	bool is_right(Vector a, Vector b) { return cross_product(a, b) >= 0; } // counterclockwise
	bool is_collinear(Vector a, Vector b) { return cross_product(a, b) == 0; }
	bool is_co_directed(Vector a, Vector b) { return is_collinear(a, b) && dot_product(a, b) >= 0; }
	bool is_convex_hull(Polygon p) {
		// mb WA
		if (p.size() <= 2) {
			return true;
		}
		if (is_collinear(Vector(p.back(), p[0]), Vector(p[0], p[1]))) {
			return false;
		}
		bool flag = is_left(Vector(p.back(), p[0]), Vector(p[0], p[1]));
		for (int i = 1; i < (int)p.size(); ++i) {
			if (is_collinear(Vector(p[i - 1], p[i]), Vector(p[i], p[(i + 1) % (int)p.size()]))
				|| flag != is_left(Vector(p[i - 1], p[i]), Vector(p[i], p[(i + 1) % (int)p.size()]))) {
				return false;
			}
		}
		return true;
	}

	/* Buildings */
	Point mid(Point A, Point B) { return { (A.x + B.x) / 2, (A.y + B.y) / 2 }; }
	Vector resize(Vector a, ld k) { return a / dist(a) * k; }
	Vector normal(Vector a) { return { -a.y, a.x }; }
	Vector normal(Line n) { return Vector(n.a, n.b); }
	Vector perpendicular(Point A, Line n) { return -resize(normal(n), dist(A, n)); }
	Point perpendicular_base(Point A, Line n) { return A + perpendicular(A, n); }
	Point symmetry(Point A, Line n) { return A + 2 * perpendicular(A, n); }
	Point bissector(Point A, Point O, Point B) {
		ld a = dist(A, B);
		ld b = dist(O, B);
		ld c = dist(O, A);
		return A + c / (b * (1 + c / b)) * Vector(A, B);
	}
	// lines 'n' and 'm' must intersect exactly at the one point
	Point good_intersect(Line n, Line m) {
		ld y = (n.a * m.c - n.c * m.a) / (n.b * m.a - n.a * m.b);
		ld x = (n.b * m.c - n.c * m.b) / (n.a * m.b - n.b * m.a);
		return Point(x, y);
	}
	vector<Point> intersect(Line n, Line m) {
		return is_collinear(n.dir_vec(), m.dir_vec()) ? n == m ? vector<Point>(2) : vector<Point>(0) : vector<Point>({ good_intersect(n, m) });
	}
	vector<Point> intersect(Circle a, Circle b) {
		if (a.r < b.r) {
			swap(a, b);
		}
		if (a == b) {
			return vector<Point>(3);
		}
		else if (a.O == b.O) {
			return {};
		}
		else if (dist2(a.O, b.O) < a.r * a.r) {
			if (dist2(a.O, b.O) == (a.r - b.r) * (a.r - b.r)) {
				return { a.O + resize(Vector(a.O, b.O), a.r) };
			}
			else if (dist2(a.O, b.O) > (a.r - b.r) * (a.r - b.r)) {
				ld d = dist(a.O, b.O);
				ld x = (a.r * a.r - b.r * b.r - d * d) / (2 * d);
				Point H = b.O + resize(Vector(a.O, b.O), x);
				ld h = my_sqrt(b.r * b.r - x * x);
				Vector v = resize(normal(Vector(a.O, b.O)), h);
				return { H + v, H - v };
			}
			else {
				return {};
			}
		}
		else {
			if (dist2(a.O, b.O) == (a.r + b.r) * (a.r + b.r)) {
				return { a.O + resize(Vector(a.O, b.O), a.r) };
			}
			else if (dist2(a.O, b.O) < (a.r + b.r) * (a.r + b.r)) {
				ld d = dist(a.O, b.O);
				ld x = (a.r * a.r - b.r * b.r + d * d) / (2 * d);
				Point H = a.O + resize(Vector(a.O, b.O), x);
				ld h = my_sqrt(a.r * a.r - x * x);
				Vector v = resize(normal(Vector(a.O, b.O)), h);
				return { H + v, H - v };
			}
			else {
				return {};
			}
		}
	}
	vector<Point> intersect(Line n, Circle a) {
		if (abs(dist(a.O, n)) > a.r) {
			return {};
		}
		Vector g = perpendicular(a.O, n);
		Point P = a.O + g;
		Vector t = resize(n.dir_vec(), my_sqrt(a.r * a.r - dist2(g)));
		if (dist(t) == 0) {
			return { P };
		}
		else {
			return { P - t, P + t };
		}
	}
	vector<Point> intersect(Seg q, Circle a) {
		vector<Point> res = intersect(Line(q.A, q.B), a);
		for (int i = 0; i < res.size(); ++i) {
			if (!on(res[i], q)) {
				swap(res[i--], res.back());
				res.pop_back();
			}
		}
		return res;
	}
	Line common_external_tangent(Circle a, Circle b) {
		if (a.r == b.r) {
			Line n(a.O, b.O);
			return n + resize(normal(n), b.r);
		}
		if (a.r < b.r) {
			swap(a, b);
		}
		a.r -= b.r;
		Point M = mid(a.O, b.O);
		vector<Point> arr = intersect(a, Circle(M, dist(a.O, b.O) / 2));
		if (arr.empty()) {
#ifdef DEBUG
			cerr << "External tangent did not found.\n";
#endif // DEBUG
			return { 0, 0, 0 };
		}
		else {
			return Line(b.O, arr[0]) + resize(Vector(a.O, arr[0]), b.r);
		}
	}
	Circle make_circle(Point A, Point B, Point C) {
		Point O = intersect(Line(mid(B, C), normal(Line(B, C))), Line(mid(A, B), normal(Line(A, B))))[0];
		return Circle(O, abs(dist(O, A)));
	}
	Polygon convex_hull(Polygon p);
	Polygon minkovski_sum(Polygon p, Polygon r);


	/* Algorithms */
	bool in(Point P, Polygon p) {
		bool res = false;
		for (int i = 0; i < (int)p.size(); ++i) {
			Point A = p[i];
			Point B = p[(i + 1) % p.size()];
			if (on(P, Seg(A, B))) {
				return true;
			}
			if (A.y > B.y) {
				swap(A, B);
			}
			auto arr = intersect(Line(A, B), Line(P, Vector(1, 0)));
			if (arr.size() == 1 && on(arr[0], Seg(A, B))) {
				res ^= (arr[0] != A && arr[0].x >= P.x);
			}
		}
		return res;
	}
	Polygon convex_hull(Polygon p) {
		sort(p.begin(), p.end(), [](Point A, Point B) { return make_pair(A) < make_pair(B); });
		p.erase(unique(p.begin(), p.end()), p.end());
		sort(p.begin() + 1, p.end(), [&](Point A, Point B) {
			if (is_collinear(Vector(p[0], A), Vector(p[0], B))) {
				return dist(Vector(p[0], A)) > dist(Vector(p[0], B));
			}
			else {
				return !is_left(Vector(p[0], A), Vector(p[0], B));
			}
			});
		Polygon ch;
		for (int i = 0; i < p.size(); ++i) {
			if (i >= 2 && is_collinear(Vector(p[0], p[i]), Vector(p[0], p[i - 1]))) {
				continue;
			}
			while (ch.size() >= 2
				&& is_left(Vector(ch[ch.size() - 2], ch.back()), Vector(ch.back(), p[i]))) {
				ch.pop_back();
			}
			ch.push_back(p[i]);
		}
		return ch;
	}
	Polygon minkovski_sum(Polygon P, Polygon Q) {
		assert(false);
		// polygons must be convex hulls
		// not sure it works
		// TODO orient polygons
		int i = 0, j = 0;
		Point cur = P[0] + Q[0];
		vector<Point> res = { cur };
		while (i != P.size() - 1 || j != Q.size() - 1) {
			if (j == Q.size() - 1 || (i != P.size() - 1 && cross_product(Vector(P[i], P[i + 1]), Vector(Q[j], Q[j + 1])) < 0)) {
				cur += Vector(P[i], P[i + 1]);
				res.push_back(cur);
				++i;
			}
			else {
				cur += Vector(Q[j], Q[j + 1]);
				res.push_back(cur);
				++j;
			}
			res.push_back(cur);
		}
		return res;
	}
	Polygon operator+(Polygon P, Polygon Q) { return minkovski_sum(P, Q); }
}

using namespace myg2d;

ld kek(Triangle t, Circle q) {
	if (in(t.B, q) && in(t.C, q)) {
		return abs(s(t));
	}
	else if (!in(t.B, q) && !in(t.C, q)) {
		auto arr = intersect(Seg(t.B, t.C), q);
		if (arr.size() <= 1) {
			return abs(s(q)) * abs(atan2(Vector(t.A, t.B), Vector(t.A, t.C))) / (2 * PI);
		}
		else {
			Point X = arr[0];
			Point Y = arr[1];
			if (dist(t.B, Y) < dist(t.B, X)) {
				swap(X, Y);
			}
			return abs(s(q)) * (abs(atan2(Vector(t.A, t.B), Vector(t.A, X))) + abs(atan2(Vector(t.A, Y), Vector(t.A, t.C)))) / (2 * PI) + abs(s(Triangle(t.A, X, Y)));
		}
	}
	else {
		if (in(t.B, q)) {
			swap(t.B, t.C);
		}
		Point X = intersect(Seg(t.A, t.B), q)[0];
		Point Y = intersect(Seg(t.C, t.B), q)[0];
		return abs(s(Triangle(t.A, Y, t.C))) + abs(s(q)) * abs(atan2(Vector(t.A, X), Vector(t.A, Y))) / (2 * PI);
	}
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout.precision(47); cout << fixed;
	Polygon p;
	Circle q;
	cin >> p >> q;
	ld si = 0;
	for (int i = 0; i < p.size(); ++i) {
		si += kek(Triangle(q.O, p[i], p[(i + 1) % p.size()]), q);
		cout << kek(Triangle(q.O, p[i], p[(i + 1) % p.size()]), q) << '\n';
	}
	cout << abs(s(q)) - si << '\n';
	system("pause");
	return 0;
}
