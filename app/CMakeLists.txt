include_directories(
    ./include/
)

add_executable(computor
		src/main.cpp
		src/Computor.cpp
		src/Lexer.cpp
		src/Parser.cpp
		src/DType.cpp
		src/Real.cpp
)

target_link_libraries(computor
		Tmaths
)
