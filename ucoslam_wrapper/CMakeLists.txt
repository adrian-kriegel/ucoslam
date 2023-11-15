
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_LIST_DIR}/include)

PROJECT(ucoslam_wrapper CXX)

FIND_PACKAGE(OpenCV 	REQUIRED )
FIND_PACKAGE(ucoslam 	REQUIRED )


LINK_LIBRARIES(${OpenCV_LIBS}  ${ucoslam_LIBS})

ADD_LIBRARY(
    ucoslam_wrapper SHARED src/ucoslam_wrapper.cpp
)

set_target_properties(ucoslam_wrapper PROPERTIES PUBLIC_HEADER "include/ucoslam_wrapper/ucoslam_wrapper.h")


CONFIGURE_FILE("../cmake/config.cmake.in" "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake")

INSTALL(
    TARGETS ucoslam_wrapper
    EXPORT ucoslam_wrapper
    LIBRARY 
    DESTINATION lib/
    PUBLIC_HEADER DESTINATION include/ucoslam_wrapper
)

INSTALL(FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake" DESTINATION share/${PROJECT_NAME} )





