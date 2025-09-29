#define TYPE_BITS_32
#define LENGTH_BITS_32

#include <gtest/gtest.h>
#include "serialization_types.h"

TEST(Serialization, TypeFieldSize32) {
  using T = loxis::serialization::type_field_t;
  EXPECT_TRUE(sizeof(T) == 4);
}

TEST(Serialization, TypeFieldLength32) {
  using T = loxis::serialization::length_field_t;
  EXPECT_TRUE(sizeof(T) == 4);
}
