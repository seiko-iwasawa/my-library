// unchecked

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
			check_warning(A == B, "Line isn't correct.", __LINE__, __FILE__);
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
		Polygon(vector<Point> p) {
			for (Point A : p) {
				push_back(A);
			}
		}
		Polygon(Triangle t) { push_back(t.A); push_back(t.B); push_back(t.C); }
	};


	/* Secondary functions */
	pair<ld, ld> make_pair(Point A) { return { A.x, A.y }; }
	pair<ld, ld> make_pair(Vector a) { return { a.x, a.y }; }
	pair<Point, Point> make_pair(Seg s) { return { s.A, s.B }; }


	/* Operators */
	istream& operator>>(istream &in, Point &A) { return in >> A.x >> A.y; }
	istream& operator>>(istream &in, Vector &a) { return in >> a.x >> a.y; }
	istream& operator>>(istream &in, Line &n) { return in >> n.a >> n.b >> n.c; }
	istream& operator>>(istream &in, Circle &a) { return in >> a.O >> a.r; }
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
	istream& operator>>(istream &in, Seg &s) { return in >> s.A >> s.B; }
	ostream& operator<<(ostream &out, Point A) { return out << A.x << ' ' << A.y; }
	ostream& operator<<(ostream &out, Vector a) { return out << a.x << ' ' << a.y; }
	ostream& operator<<(ostream &out, Line n) { return out << n.a << ' ' << n.b << ' ' << n.c; }
	ostream& operator<<(ostream &out, Circle a) { return out << a.O << ' ' << a.r; }
	ostream& operator<<(ostream &out, Triangle t) { return out << t.A << '\n' << t.B << '\n' << t.C; }
	ostream& operator<<(ostream &out, Polygon p) {
			for (Point A : p) {
				out << A << '\n';
			}
			return out;
		}
	ostream& operator<<(ostream &out, Seg &s) { return out << s.A << ' ' << s.B; }
	bool operator==(Point A, Point B) { return make_pair(A) == make_pair(B); }
	bool operator==(Vector a, Vector b) { return make_pair(a) == make_pair(b); }
	bool operator==(Line n, Line m) {
			return n.b * m.a == n.a * m.b && n.a * m.c == n.c * m.a && n.b * m.c == n.c * m.b;
		}
	bool operator==(Circle f, Circle g) { return f.O == g.O && f.r == g.r; }
	bool operator==(Triangle t, Triangle r) { return t.get_sorted_sides2() == r.get_sorted_sides2(); }
	bool operator==(Seg q, Seg w) { return make_pair(q) == make_pair(w); }
	bool operator!=(Point A, Point B) { return !(A == B); }
	bool operator!=(Triangle t, Triangle r) { return !(t == r); }
	bool operator!=(Seg q, Seg w) { return !(q == w); }
	Point operator+(Point A, Point B) { return { A.x + B.x, A.y + B.y }; }
	Point operator+(Point A, Vector a) { return { A.x + a.x, A.y + a.y }; }
	Point& operator+=(Point &A, Vector a) { return A = A + a; }
	Point operator-(Point A, Vector a) { return { A.x - a.x, A.y - a.y }; }
	Point& operator-=(Point &A, Vector a) { return A = A - a; }
	Vector operator-(Vector a) { return { -a.x, -a.y }; }
	Vector operator*(ld k, Vector a) { return { a.x * k, a.y * k }; }
	Vector operator*(Vector a, ld k) { return { a.x * k, a.y * k }; }
	Vector& operator*=(Vector &a, ld k) { return a = a * k; }
	Vector operator/(Vector a, ld k) { return { a.x / k, a.y / k }; }
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
	ld dist(Seg s) { return my_sqrt(dist2(s)); }
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
	ld s(Circle q) { return PI * q.r * q.r; }
	ld perimeter(Polygon p) {
		if (p.size() <= 1) {
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
	bool on(Point P, Seg s) {
		return dot_product(Vector(P, s.A), Vector(P, s.B)) <= 0
			&& cross_product(Vector(P, s.A), Vector(P, s.B)) == 0;
	}
	bool on(Point P, Ray f) {
		return dot_product(f.r, Vector(f.O, P)) >= 0
			&& cross_product(f.r, Vector(f.O, P)) == 0;
	}
	bool in(Point P, Angle a) { return P == a.O || abs(atan2(Vector(a.O, a.A), Vector(a.O, a.B))) == abs(atan2(Vector(a.O, a.A), Vector(a.O, P))) + abs(atan2(Vector(a.O, P), Vector(a.O, a.B))); }
	bool in(Point P, Polygon p);
	bool in(Point P, Triangle t) { return in(P, Polygon(t)); }
	bool in(Point P, Circle a) { return dist2(a.O, P) <= a.r * a.r; }
	bool cross_segs(Seg q, Seg w) {
		Line n(q), m(w);
		return sign(m(q.A)) * sign(m(q.B)) <= 0
			&& sign(n(w.A)) * sign(n(w.B)) <= 0;
	}
	bool is_left(Vector a, Vector b) { return cross_product(a, b) <= 0; } // clockwise
	bool is_right(Vector a, Vector b) { return cross_product(a, b) >= 0; } // counterclockwise
	bool is_collinear(Vector a, Vector b) { return cross_product(a, b) == 0; }
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
	Point mid(Point A, Point B) { return Point((A.x + B.x) / 2, (A.y + B.y) / 2); }
	Vector resize(Vector a, ld k) { return a / dist(a) * k; }
	Vector normal(Vector a) { return { -a.y, a.x }; }
	Vector normal(Line n) { return Vector(n.a, n.b); }
	Vector perpendicular(Point A, Line n) { return -resize(normal(n), dist(A, n)); }
	Point perpendicular_base(Point A, Line n) { return A + perpendicular(A, n); }
	Point symmetry(Point A, Line n) { return A + 2 * perpendicular(A, n); }
	Point bissector(Point A, Point O, Point B) {
		// can be upgrading
		ld a = dist(A, B);
		ld b = dist(O, B);
		ld c = dist(O, A);
		return A + c / (b * (1 + c / b)) * Vector(A, B);
	}
	Point good_intersect(Line n, Line m) {
		/*
		lines 'n' and 'm' must intersect exactly at the one point
		*/
#ifdef DEBUG
		assert(n.b * m.a != n.a * m.b);
#endif // DEBUG
		ld y = (n.a * m.c - n.c * m.a) / (n.b * m.a - n.a * m.b);
		ld x = (n.b * m.c - n.c * m.b) / (n.a * m.b - n.b * m.a);
		return { Point(x, y) };
	}
	vector<Point> intersect(Line n, Line m) {
		if (n.b * m.a == n.a * m.b) {
			if (n.a * m.c == n.c * m.a && n.b * m.c == n.c * m.b) {
				return vector<Point>(2);
			}
			else {
				return {};
			}
		}
		else {
			ld y = (n.a * m.c - n.c * m.a) / (n.b * m.a - n.a * m.b);
			ld x = (n.b * m.c - n.c * m.b) / (n.a * m.b - n.b * m.a);
			return { Point(x, y) };
		}
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