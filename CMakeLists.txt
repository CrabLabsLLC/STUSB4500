cmake_minimum_required(VERSION 3.10)

if(IDF_PROJECT)
    
    idf_component_register(
        SRCS "src/studb4500.c"
        INCLUDE_DIRS "include"
        REQUIRES "driver"
    )

else()
    
    project(STUSB4500 VERSION 0.1 LANGUAGES C)

    add_library(${PROJECT_NAME} STATIC src/stusb4500.c)
    target_include_directories(${PROJECT_NAME} PUBLIC include)

endif()
