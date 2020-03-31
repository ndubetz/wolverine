set(LIBRARY_NAME unity)

file(GLOB unity_src "*.c")

add_library(${LIBRARY_NAME} 
    ${unit_src}
)
