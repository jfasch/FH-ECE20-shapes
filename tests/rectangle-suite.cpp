#include <gtest/gtest.h>

#include <rectangle.h>

TEST(rectangle_suite, default_ctor)
{
    const rectangle r;
}

TEST(rectangle_suite, coordinates)
{
    {
        const rectangle r;
        ASSERT_EQ(r.bottom_left(), point(0,0));
        ASSERT_EQ(r.top_right(), point(0,0));
        ASSERT_EQ(r.top_left(), point(0,0));
        ASSERT_EQ(r.bottom_right(), point(0,0));
    }

    {
        const point bottom_left{1,2};
        const point top_right{8,6};
        const rectangle r{bottom_left, top_right};

        ASSERT_EQ(r.bottom_left(), point(1,2));
        ASSERT_EQ(r.top_right(), point(8,6));
        ASSERT_EQ(r.top_left(), point(1,6));
        ASSERT_EQ(r.bottom_right(), point(8,2));
    }
}

TEST(rectangle_suite, area)
{
    {
        const rectangle r;

        ASSERT_EQ(r.width(), 0);
        ASSERT_EQ(r.height(), 0);
        ASSERT_EQ(r.area(), 0);
    }

    {
        const rectangle r{point(3,4), point(8,6)};

        ASSERT_EQ(r.width(), 5);
        ASSERT_EQ(r.height(), 2);
        ASSERT_EQ(r.area(), 10);
    }
}

TEST(rectangle_suite, operator_eq_ne)
{
    const rectangle r1(point(1,2), point(3,4));
    const rectangle r2(point(1,2), point(3,5));

    bool b;

    b = (r1 == r2);
    ASSERT_FALSE(b);

    b = (r1 == r1);
    ASSERT_TRUE(b);

    b = (r1 != r1);
    ASSERT_FALSE(b);

    b = (r1 != r2);
    ASSERT_TRUE(b);
}

TEST(rectangle_suite, operator_plus_equal_vec)
{
    rectangle r(point(3,4), point(8,6));
    const point vec(1,2);

    const rectangle r1 = r += vec;

    ASSERT_EQ(r.bottom_left(), point(4,6));
    ASSERT_EQ(r.top_right(), point(9,8));

    ASSERT_EQ(r, r1);
}

TEST(rectangle_suite, plus_vec)
{
    const rectangle r(point(3,4), point(8,6));
    const point vec(1,2);

    const rectangle r1 = r + vec;

    ASSERT_EQ(r1.bottom_left(), point(4,6));
    ASSERT_EQ(r1.top_right(), point(9,8));

    ASSERT_EQ(r, rectangle(point(3,4), point(8,6)));
}

TEST(rectangle_suite, operator_ostream)
{
    const rectangle r(point(3,4), point(8,6));

    std::ostringstream buf;
    buf << r;

    ASSERT_EQ(buf.str(), "((3,4),(8,6))");
}
