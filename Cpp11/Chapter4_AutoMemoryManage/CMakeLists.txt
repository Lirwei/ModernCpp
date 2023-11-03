set(MAIN_FILES
        AMM_1_auto_ptr.cpp
        AMM_2_auto_ptr.cpp
        AMM_3_auto_ptr.cpp
        AMM_4_auto_ptr.cpp
        AMM_5_unique_ptr.cpp
        AMM_6_unique_ptr.cpp
        AMM_7_unique_ptr.cpp
        AMM_8_share_ptr.cpp
        AMM_9_share_ptr.cpp
        )

foreach (file ${MAIN_FILES})
    get_filename_component(fn ${file} NAME_WE)
    add_executable(${fn} ${file})
endforeach ()