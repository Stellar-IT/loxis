add_executable(loxis_tests
    test_serialization_size_and_length_of_8.cpp
    test_serialization_size_and_length_of_16.cpp
    test_serialization_size_and_length_of_32.cpp
    test_serialization_size_and_length_of_64.cpp
)

target_link_libraries(loxis_tests
    PRIVATE
        loxis_serialization_static
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(loxis_tests)
