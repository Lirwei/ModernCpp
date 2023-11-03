set(MAIN_FILES
        Template_variadic.cpp
        )

foreach (file ${MAIN_FILES})
    get_filename_component(fn ${file} NAME_WE)
    add_executable(${fn} ${file})
endforeach ()