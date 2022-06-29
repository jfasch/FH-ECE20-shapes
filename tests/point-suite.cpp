#include <gtest/gtest.h>

#include <point.h>

TEST(point_suite, default_ctor)
{
    const point p;

    ASSERT_EQ(p.x(), 0);
    ASSERT_EQ(p.y(), 0);
}

TEST(point_suite, coordinates_ctor)
{
    const point p{1,2};

    ASSERT_EQ(p.x(), 1);
    ASSERT_EQ(p.y(), 2);
}

TEST(point_suite, operator_eq_ne)
{
    const point p{1,2};
    const point q{3,4};

    bool b;

    b = (p == q);
    ASSERT_FALSE(b);

    b = (p != q);
    ASSERT_TRUE(b);

    b = (p == p);
    ASSERT_TRUE(b);

    b = (p != p);
    ASSERT_FALSE(b);
}

TEST(point_suite, operator_pluseq)
{
    point p{1,2};
    const point vec{3,4};
    const point& p1 = p += vec;

    ASSERT_EQ(p.x(), 4);
    ASSERT_EQ(p.y(), 6);

    bool b = (p == p1);
    ASSERT_TRUE(b);

    ASSERT_EQ(&p1, &p);  // operator+=() returns point& !!
}

TEST(point_suite, operator_plus)
{
    const point p{1,2};
    const point vec{3,4};

    const point p1 = p + vec;

    ASSERT_EQ(p1.x(), 4);
    ASSERT_EQ(p1.y(), 6);
}

TEST(point_suite, operator_unary_minus)
{
    const point p{1,2};
    const point minus_p = -p;

    ASSERT_EQ(minus_p.x(), -1);
    ASSERT_EQ(minus_p.y(), -2);
}

TEST(point_suite, operator_ostream)
{
    const point p{1,2};

    std::ostringstream buf;
    buf << p;

    ASSERT_EQ(buf.str(), "(1,2)");
}
