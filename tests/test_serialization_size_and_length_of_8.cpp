#define TYPE_BITS_8
#define LENGTH_BITS_8

#include <gtest/gtest.h>
#include "serialization_types.h"

namespace test_size_and_length_of_8 {

TEST(Serialization, TypeFieldSize8) {
  using T = loxis::serialization::type_field_t;
  EXPECT_TRUE(sizeof(T) == 1);
}

TEST(Serialization, TypeFieldLength8) {
  using T = loxis::serialization::length_field_t;
  EXPECT_TRUE(sizeof(T) == 1);
}

} // test_size_and_length_of_8
