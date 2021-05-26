#include "BinaryTree.hpp"
#include "doctest.h"
#include <sstream>
#include <iostream>
#include <functional>

using namespace ariel;
using namespace std;
using std::placeholders::_1;

TEST_CASE("pre_order_int")
{
    BinaryTree<int> b;
    b.add_root(2);
    b.add_left(2, 4);
    b.add_left(4, 8);
    b.add_left(8, 16);
    b.add_left(16, 32);
    b.add_left(32, 64);
    b.add_right(2, 5);
    b.add_right(4, 9);
    b.add_right(8,17);
    ostringstream pout;
    for (auto it = b.begin_preorder(); it != b.end_preorder(); ++it)
    {
        pout << (*it) << " ";
    }
    CHECK_EQ(pout.str(), "2 4 8 16 32 64 17 9 5 ");
    ostringstream pout2;
    auto tmp = ++++++b.begin_preorder();
    for (auto it = b.begin_preorder(); it != tmp; ++it)
    {
        pout2 << (*it) << " ";
    }
    CHECK_EQ(pout2.str(), "2 4 8 ");
}
TEST_CASE("in_order_int")
{
    BinaryTree<int> b;
    b.add_root(2);
    b.add_left(2, 4);
    b.add_left(4, 8);
    b.add_left(8, 16);
    b.add_left(16, 32);
    b.add_left(32, 64);
    b.add_right(2, 5);
    b.add_right(4, 9);
    b.add_right(8,17);

    ostringstream pout;
    for (auto it = b.begin_inorder(); it != b.end_inorder(); ++it)
    {
        pout << (*it) << " ";
    }
    CHECK_EQ(pout.str(), "64 32 16 8 17 4 9 2 5 ");
    ostringstream pout2;
    auto tmp = ++++++b.begin_inorder();
    for (auto it = b.begin_inorder(); it != tmp; ++it)
    {
        pout2 << (*it) << " ";
    }
    CHECK_EQ(pout2.str(), "64 32 16 ");
}
TEST_CASE("post_order_int")
{
    BinaryTree<int> b;
    b.add_root(2);
    b.add_left(2, 4);
    b.add_left(4, 8);
    b.add_left(8, 16);
    b.add_left(16, 32);
    b.add_left(32, 64);
    b.add_right(2, 5);
    b.add_right(4, 9);
    b.add_right(8,17);

    ostringstream pout;
    for (auto it = b.begin_postorder(); it != b.end_postorder(); ++it)
    {
        pout << (*it) << " ";
    }
    CHECK_EQ(pout.str(), "64 32 16 17 8 9 4 5 2 ");
    ostringstream pout2;
    auto tmp = ++++++b.begin_postorder();
    for (auto it = b.begin_postorder(); it != tmp; ++it)
    {
        pout2 << (*it) << " ";
    }
    CHECK_EQ(pout2.str(), "64 32 16 ");
}

TEST_CASE("pre_order_string")
{
    BinaryTree<string> b;
    b.add_root("2");
    b.add_left("2", "4");
    b.add_left("4", "8");
    b.add_left("8", "16");
    b.add_left("16", "32");
    b.add_left("32", "64");
    b.add_right("2", "5");
    b.add_right("4", "9");
    b.add_right("8","17");

    ostringstream pout;
    for (auto it = b.begin_preorder(); it != b.end_preorder(); ++it)
    {
        pout << (*it) << " ";
    }
    CHECK_EQ(pout.str(), "2 4 8 16 32 64 17 9 5 ");
    ostringstream pout2;
    auto tmp = ++++++b.begin_preorder();
    for (auto it = b.begin_preorder(); it != tmp; ++it)
    {
        pout2 << (*it) << " ";
    }
    CHECK_EQ(pout2.str(), "2 4 8 ");

}
TEST_CASE("in_order_string")
{
    BinaryTree<string> b;
    b.add_root("2");
    b.add_left("2", "4");
    b.add_left("4", "8");
    b.add_left("8", "16");
    b.add_left("16", "32");
    b.add_left("32", "64");
    b.add_right("2", "5");
    b.add_right("4", "9");
    b.add_right("8","17");

    ostringstream pout;
    for (auto it = b.begin_inorder(); it != b.end_inorder(); ++it)
    {
        pout << (*it) << " ";
    }
    CHECK_EQ(pout.str(), "64 32 16 8 17 4 9 2 5 ");
    ostringstream pout2;
    auto tmp = ++++++b.begin_inorder();
    for (auto it = b.begin_inorder(); it != tmp; ++it)
    {
        pout2 << (*it) << " ";
    }
    CHECK_EQ(pout2.str(), "64 32 16 ");
}

TEST_CASE("post_order_string")
{
    BinaryTree<string> b;
    b.add_root("2");
    b.add_left("2", "4");
    b.add_left("4", "8");
    b.add_left("8", "16");
    b.add_left("16", "32");
    b.add_left("32", "64");
    b.add_right("2", "5");
    b.add_right("4", "9");
    b.add_right("8","17");

    ostringstream pout;
    for (auto it = b.begin_postorder(); it != b.end_postorder(); ++it)
    {
        pout << (*it) << " ";
    }
    CHECK_EQ(pout.str(), "64 32 16 17 8 9 4 5 2 ");
    ostringstream pout2;
    auto tmp = ++++++b.begin_postorder();
    for (auto it = b.begin_postorder(); it != tmp; ++it)
    {
        pout2 << (*it) << " ";
    }
    CHECK_EQ(pout2.str(), "64 32 16 ");
}
struct stam
{
    int tmp;
    stam(int tmp) : tmp(tmp) {}
    int get_tmp() const
    {
        return this->tmp;
    }
    bool operator!=(stam other)
    {
        return this->tmp != other.tmp;
    }

    bool operator==(stam other)
    {
        return !(*this != other);
    }
    friend ostream &operator<<(ostream &os, const stam &p);
};
ostream &operator<<(ostream &os, const stam &p)
{
    return (os << p.get_tmp() << ' ');
}
TEST_CASE("operator->")
{

    BinaryTree<stam> b;
    b.add_root(2);
    b.add_left(2, 4);
    b.add_right(2, 5);
    CHECK_EQ(2, b.begin_preorder()->tmp);
    CHECK_EQ(4, b.begin_inorder()->tmp);
    b.add_left(4, 8).add_right(4, 9);
    CHECK_NOTHROW(cout << b << endl;);
    CHECK_EQ(2, (++++++++b.begin_postorder())->tmp);
    CHECK_EQ(5, (++++++b.begin_postorder())->tmp);
}
TEST_CASE("operator*")
{

    BinaryTree<stam> b;
    b.add_root(2);
    b.add_left(2, 4);
    b.add_right(2, 5);
    CHECK_EQ(2, (*b.begin_preorder()).get_tmp());
    CHECK_EQ(4, (*b.begin_inorder()).get_tmp());
    b.add_left(4, 8).add_right(4, 9);
    CHECK_NOTHROW(cout << b << endl;);
    CHECK_EQ(2, (*(++++++++b.begin_postorder())).get_tmp());
    CHECK_EQ(5, (*(++++++b.begin_postorder())).get_tmp());
}