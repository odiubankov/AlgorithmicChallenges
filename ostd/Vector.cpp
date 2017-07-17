#include "Vector.h"
#include <gtest/gtest.h>

#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>

#ifdef MSVC
#include <crtdbg.h>
#endif

class MemoryGuard
{
#ifdef MSVC
  _CrtMemState s1, s2, s3;
#endif
public:
  MemoryGuard()
  {
#ifdef MSVC
    _CrtMemCheckpoint(&s1);
#endif
  }

  ~MemoryGuard()
  {
#ifdef MSVC
    _CrtMemCheckpoint(&s2);

    if (_CrtMemDifference(&s3, &s1, &s2))
      _CrtMemDumpStatistics(&s3);
#endif
  }
};

TEST(Vector, push_back)
{
  MemoryGuard memGuard;
  ostd::Vector<int> vInt;
  ASSERT_EQ(vInt.size(), 0);
  vInt.push_back(10);
  ASSERT_EQ(vInt.size(), 1);
}

TEST(Vector, push_back100)
{
  MemoryGuard memGuard;
  ostd::Vector<int> vInt;
  for (int i = 0; i < 100; ++i)
  {
    vInt.push_back(i);
  }

  ASSERT_EQ(vInt.size(), 100);
}


TEST(Vector, pop_back100x2)
{
    MemoryGuard memGuard;
    ostd::Vector<int> vInt;
    for (int i = 0; i < 100; ++i)
    {
      vInt.push_back(i);
    }

    for (int i = 0; i < 100; ++i)
    {
      vInt.pop_back();
    }

    for (int i = 0; i < 100; ++i)
    {
      vInt.push_back(i);
    }

    for (int i = 0; i < 100; ++i)
    {
      vInt.pop_back();
    }

    ASSERT_EQ(vInt.size(), 0);
}


TEST(Vector, operator_brackets)
{
  MemoryGuard memGuard;
  ostd::Vector<int> vInt;
  for (int i = 0; i < 100; ++i)
  {
    vInt.push_back(i);
  }

  for (int i = 0; i < 100; ++i)
  {
    vInt[i] = 10 * i;
  }

  for (int i = 0; i < 100; ++i)
  {
    ASSERT_EQ(vInt[i], 10 * i);
  }
}


TEST(Vector, copy_constructor)
{
  MemoryGuard memGuard;
  ostd::Vector<int> vInt;
  for (int i = 0; i < 100; ++i)
  {
    vInt.push_back(i);
  }

  ostd::Vector<int> vInt2{vInt};
  for (int i = 0; i < 100; ++i)
  {
    ASSERT_EQ(vInt[i], i);
    ASSERT_EQ(vInt2[i], i);
  }
}


TEST(Vector, copy_assignment)
{
  MemoryGuard memGuard;
  ostd::Vector<int> vInt;
  for (int i = 0; i < 100; ++i)
  {
    vInt.push_back(i);
  }

  ostd::Vector<int> vInt2;
  vInt2 = vInt;
  for (int i = 0; i < 100; ++i)
  {
    ASSERT_EQ(vInt[i], i);
    ASSERT_EQ(vInt2[i], i);
  }
}


TEST(Vector, move_constructor)
{
  MemoryGuard memGuard;
  ostd::Vector<int> vInt;
  for (int i = 0; i < 100; ++i)
  {
    vInt.push_back(i);
  }

  ostd::Vector<int> vInt2{ std::move(vInt) };
  for (int i = 0; i < 100; ++i)
  {
    ASSERT_EQ(vInt2[i], i);
  }

  ASSERT_EQ(vInt.size(), 0);
}


TEST(Vector, move_assignment)
{
  MemoryGuard memGuard;
  ostd::Vector<int> vInt;
  for (int i = 0; i < 100; ++i)
  {
    vInt.push_back(i);
  }

  ostd::Vector<int> vInt2; 
  vInt2 = std::move(vInt);
  for (int i = 0; i < 100; ++i)
  {
    ASSERT_EQ(vInt2[i], i);
  }

  ASSERT_EQ(vInt.size(), 0);
}