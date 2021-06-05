set(PROJECT_BIN_SRC
    main.cpp
)

add_executable(${PROJECT_BIN_NAME} ${PROJECT_BIN_SRC})
target_link_libraries(${PROJECT_BIN_NAME} ${PROJECT_LIB_NAME})
target_set_warnings(${PROJECT_BIN_NAME} ENABLE ALL)