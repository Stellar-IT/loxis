#ifndef LOXIS_SERIALIZATION_TYPES_H
#define LOXIS_SERIALIZATION_TYPES_H

#include <cstdint>
#include <cstddef>

namespace loxis {
namespace serialization {

#if defined(TYPE_BITS_8)
  using type_field_t = uint8_t;
#elif defined(TYPE_BITS_16)
  using type_field_t = uint16_t;
#elif defined(TYPE_BITS_32)
  using type_field_t = uint32_t;
#elif defined(TYPE_BITS_64)
  using type_field_t = uint64_t;
#else
  using type_field_t = uint32_t;
#endif

#if defined(LENGTH_BITS_8)
  using length_field_t = uint8_t;
#elif defined(LENGTH_BITS_16)
  using length_field_t = uint16_t;
#elif defined(LENGTH_BITS_32)
  using length_field_t = uint32_t;
#elif defined(LENGTH_BITS_64)
  using length_field_t = uint64_t;
#else
  using length_field_t = uint32_t;
#endif

} // namespace serialization
} // namespace loxis

#endif // LOXIS_SERIALIZATION_TYPES_H
