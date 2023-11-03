set(MAIN_FILES
        STL_1_unordered_map.cpp
        STL_2_unordered_set.cpp
        )

foreach (file ${MAIN_FILES})
    get_filename_component(fn ${file} NAME_WE)
    add_executable(${fn} ${file})
endforeach ()