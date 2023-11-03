set(MAIN_FILES
        MoreEffective_1_assert.cpp
        MoreEffective_2_static_assert.cpp
        MoreEffective_3_rightValueRef.cpp
        MoreEffective_4_constRef.cpp
        MoreEffective_5_constReview.cpp
        MoreEffective_6_move_constructor.cpp
        MoreEffective_7_defaultMove.cpp
        MoreEffective_8_moveapply.cpp
        MoreEffective_9_constructors.cpp
        MoreEffective_10_memoryBlock.cpp
        MoreEffective_11_STL.cpp
        MoreEffective_12_forward.cpp
        MoreEffective_13_interface.cpp
        MoreEffective_14_function.cpp
        MoreEffective_15_function_selectSort.cpp
        MoreEffective_16_function_observer.cpp
        MoreEffective_17_bind.cpp
        MoreEffective_18_bind_objMember.cpp
        MoreEffective_19_bind_overload.cpp
        MoreEffective_20_bind_function.cpp
        MoreEffective_21_bind_function_cocos.cpp
        )

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-elide-constructors")

foreach (file ${MAIN_FILES})
    get_filename_component(fn ${file} NAME_WE)
    add_executable(${fn} ${file})
endforeach ()