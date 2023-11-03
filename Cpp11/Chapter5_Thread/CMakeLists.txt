set(MAIN_FILES
        Thread_1_create.cpp
        Thread_2_join.cpp
        Thread_3_detach.cpp
        Thread_4_args.cpp
        Thread_5_mutex.cpp
        Thread_6_MutexRAII.cpp
        Thread_7_recursive_mutex.cpp
        Thread_8_condition_variable.cpp
        )

foreach (file ${MAIN_FILES})
    get_filename_component(fn ${file} NAME_WE)
    add_executable(${fn} ${file})
endforeach ()