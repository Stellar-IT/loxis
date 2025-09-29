#define TYPE_BITS_64
#define LENGTH_BITS_64

#include <gtest/gtest.h>
#include "serialization_types.h"

TEST(Serialization, TypeFieldSize64) {
  using T = loxis::serialization::type_field_t;
  EXPECT_TRUE(sizeof(T) == 8);
}

TEST(Serialization, TypeFieldLength64) {
  using T = loxis::serialization::length_field_t;
  EXPECT_TRUE(sizeof(T) == 8);
}
