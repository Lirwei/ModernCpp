set(MAIN_FILES
        MoreConcise_1_nullptr.cpp
        MoreConcise_2_override.cpp
        MoreConcise_3_final.cpp
        MoreConcise_4_default.cpp
        MoreConcise_5_delete.cpp
        MoreConcise_6_rawString.cpp
        MoreConcise_7_for.cpp
        MoreConcise_8_initial_list.cpp
        MoreConcise_9_initializer.cpp
        MoreConcise_10_auto.cpp
        MoreConcise_11_decltype.cpp
        MoreConcise_12_decltype_typedef.cpp
        MoreConcise_13_decltype_auto.cpp
        MoreConcise_14_functor.cpp
        MoreConcise_15_lambda.cpp
        MoreConcise_16_lambda.cpp
        MoreConcise_17_lambda_foreach.cpp
        MoreConcise_18_functor_lambda.cpp
        MoreConcise_19_enum.cpp
        )

foreach (file ${MAIN_FILES})
    get_filename_component(fn ${file} NAME_WE)
    add_executable(${fn} ${file})
endforeach ()