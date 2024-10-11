file(GLOB_RECURSE SOURCE_FILES "*.cpp")

set(BINARY_NAME "server")

add_executable(${BINARY_NAME} ${SOURCE_FILES})

target_link_libraries(${BINARY_NAME} PRIVATE
        netcpp::netcpp
        fmt::fmt
        protobuf::libprotobuf
)

target_include_directories(${BINARY_NAME} PRIVATE "./")

add_custom_command(TARGET ${BINARY_NAME} PRE_BUILD
        COMMAND
            ${CMAKE_BINARY_DIR}/vcpkg_installed/${VCPKG_TARGET_TRIPLET}/tools/protobuf/protoc
            -I=${CMAKE_SOURCE_DIR}/proto
            --cpp_out=${CMAKE_SOURCE_DIR}/src/generated ${CMAKE_SOURCE_DIR}/proto/*
)