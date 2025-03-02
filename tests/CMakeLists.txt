file(GLOB_RECURSE ACID_ALL_TEST_FILES ${CMAKE_CURRENT_SOURCE_DIR}/acid/*_test.cpp)
message(STATUS "LINK DIR: ${CMAKE_CURRENT_BINARY_DIR}/../lib")
if(BUILD_TEST)
    foreach(TEST_FILE ${ACID_ALL_TEST_FILES})
        get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
        add_executable(${TEST_NAME} ${TEST_FILE})
        target_link_libraries(
            ${TEST_NAME}
            ${LIB_NAME}
            gtest
            gtest_main)
        add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
        set_target_properties(
            ${TEST_NAME}
            PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)
        set_target_properties(
            ${TEST_NAME}
            PROPERTIES
            BUILD_RPATH ${CMAKE_CURRENT_BINARY_DIR}/../lib)
    endforeach()
endif()
