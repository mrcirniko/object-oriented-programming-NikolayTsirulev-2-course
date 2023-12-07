#include <gtest/gtest.h>
#include "figure.hpp"
#include "pentagon.hpp"
#include "hexagon.hpp"
#include "octagon.hpp"
#include <sstream>

#define EPS 1e-7

template<typename T> bool isEqual(T x, T y) {
    return (std::abs(x - y) < EPS);
}

template<typename T> bool isEqualPair(std::pair<T, T> p1, std::pair<T, T> p2) {
    return isEqual(p1.first, p2.first) && isEqual(p1.second, p2.second);
}

TEST(pentagon, test01) {
    std::stringstream stream;
    stream << "0 0\n2 0\n2 3\n1 4\n0 3\n";
    std::vector<std::pair<double, double>> vertices;
    double x, y;
    while (stream >> x >> y) {
        vertices.emplace_back(x, y);
    }
    Pentagon<double> p(vertices);
    ASSERT_TRUE(isEqual((double) p, 7.0));
    ASSERT_TRUE(isEqualPair<double>(p.center(), std::make_pair(0, -3.507323133352506)));
    Pentagon<double> p1;
    p1 = p;
    ASSERT_TRUE(p == p1);
}

TEST(hexagon, test01) {
    std::stringstream stream;
    stream << "0 1\n-0.8660254037844386 0.5\n-0.8660254037844386 -0.5\n0 -1\n0.8660254037844386 -0.5\n0.8660254037844386 0.5\n";
    std::shared_ptr<Figure<double> > p;
    std::vector<typename Figure<double>::vertex_t> vertices;
    double x, y;
    while (stream >> x >> y) {
        vertices.emplace_back(x, y);
    }
    p = std::make_shared<Hexagon<double> >(vertices);
    ASSERT_TRUE(isEqual((double) *p, 2.5980762113533156));
    ASSERT_TRUE(isEqualPair(p->center(), std::make_pair(0.0, 0.0)));
    std::shared_ptr<Figure<double> > p1;
    p1 = p;
    ASSERT_TRUE(p == p1);
}

TEST(hexagon, test02) {
    std::stringstream stream;
    stream << "-0.848076211353316 10.12916512459885\n-7.348076211353316 7.129165124598851\n-8 0\n-2.151923788646684 -4.129165124598851\n4.348076211353316 -1.1291651245988508\n5 6\n";
    std::vector<std::pair<double, double>> vertices;
    double x, y;
    while (stream >> x >> y) {
        vertices.emplace_back(x, y);
    }
    Hexagon<double> p(vertices);
    ASSERT_TRUE(isEqual((double) p, 133.151405831857460));
    ASSERT_TRUE(isEqualPair(p.center(), std::make_pair(-1.5, 3.0)));
    Hexagon<double> p1;
    p1 = p;
    ASSERT_TRUE(p == p1);
}

TEST(hexagon, test03) {
    std::stringstream stream;
    stream << "0 0\n2 0\n3 1\n2 2\n0 2\n-1 1\n";
    std::vector<std::pair<int, int>> vertices;
    int x, y;
    while (stream >> x >> y) {
        vertices.emplace_back(x, y);
    }
    Hexagon<int> p(vertices);
    ASSERT_TRUE(isEqual((double) p, 10.392304845413264));
    std::pair<int, int> center = p.center();
    ASSERT_TRUE(center.first == 1 && center.second == 1);
    Hexagon<int> p1;
    p1 = p;
    ASSERT_TRUE(p == p1);
}

TEST(octagon, test01) {
    std::stringstream stream;
    stream << "1 0\n2 1\n2 3\n1 4\n-1 4\n-2 3\n-2 1\n-1 0\n";
    std::vector<std::pair<double, double>> vertices;
    double x, y;
    while (stream >> x >> y) {
        vertices.emplace_back(x, y);
    }
    Octagon<double> p(vertices);
    ASSERT_TRUE(isEqual((double) p, 14.0));
    ASSERT_TRUE(isEqualPair(p.center(), std::make_pair(0.0, 2.0)));
    Octagon<double> p1;
    p1 = p;
    ASSERT_TRUE(p == p1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}