#define TYPE_BITS_16
#define LENGTH_BITS_16

#include <gtest/gtest.h>
#include "serialization_types.h"

namespace test_size_and_length_of_16 {

TEST(Serialization, TypeFieldSize16) {
  using T = loxis::serialization::type_field_t;
  EXPECT_TRUE(sizeof(T) == 2);
}

TEST(Serialization, TypeFieldLength16) {
  using T = loxis::serialization::length_field_t;
  EXPECT_TRUE(sizeof(T) == 2);
}

} // test_size_and_length_of_16
