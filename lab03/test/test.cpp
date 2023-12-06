#include <gtest/gtest.h>
#include "vertex.hpp"
#include "figure.hpp"
#include "pentagon.hpp"
#include "hexagon.hpp"
#include "octagon.hpp"
#include <sstream>


const double EPS = 1e-7;

bool isEqual(double x, double y) noexcept {
    return (std::fabs(x - y) < EPS);
}

TEST(hexagon, test01) {
    Hexagon h;
    ASSERT_TRUE(h.center() == Vertex(0, 0));
    ASSERT_TRUE(isEqual((double) h, 0));
}

TEST(hexagon, test02) {
    std::stringstream stream;
    stream << "0 1\n-0.8660254037844386 0.5\n-0.8660254037844386 -0.5\n0 -1\n0.8660254037844386 -0.5\n0.8660254037844386 0.5\n";
    Hexagon h(stream);
    ASSERT_TRUE(h.center() == Vertex(0, 0));
    ASSERT_TRUE(isEqual((double) h, 2.5980762113533156));
    Hexagon h1(h);
    ASSERT_TRUE(h == h1);
}

TEST(hexagon, test03) {
    std::stringstream stream;
    stream << "-0.848076211353316 10.12916512459885\n-7.348076211353316 7.129165124598851\n-8 0\n-2.151923788646684 -4.129165124598851\n4.348076211353316 -1.1291651245988508\n5 6\n";
    Figure *h = new Hexagon(stream);
    ASSERT_TRUE(h->center() == Vertex(-1.5, 3));
    ASSERT_TRUE(isEqual((double) *h, 133.151405831857460));
}

TEST(pentagon, test01) {
    std::stringstream stream;
    stream << "0 0\n2 0\n2 3\n1 4\n0 3\n";
    Pentagon p(stream);
    ASSERT_TRUE(p.center() == Vertex(0, -3.507323133352506));
    ASSERT_TRUE(isEqual((double) p, 7.0));
    Pentagon p1(p);
    ASSERT_TRUE(p == p1);
}

TEST(pentagon, test02) {
    std::stringstream stream;
    stream << "1 2\n3 1\n4 3\n3 5\n1 4\n";
    Figure *p = new Pentagon(stream);
    ASSERT_TRUE(isEqual((double) *p, 8.0));
}

TEST(octagon, test01) {
    std::stringstream stream;
    stream << "1 0\n2 1\n2 3\n1 4\n-1 4\n-2 3\n-2 1\n-1 0\n";
    Octagon p(stream);
    ASSERT_TRUE(p.center() == Vertex(0, 2));
    ASSERT_TRUE(isEqual((double) p, 14.0));
    Octagon p1(p);
    ASSERT_TRUE(p == p1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}