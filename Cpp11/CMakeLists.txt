set(MODULES
        Chapter1_MoreConcise
        Chapter2_MoreEffective
        Chapter3_STL
        Chapter4_AutoMemoryManage
        Chapter5_Thread
        )

foreach (module ${MODULES})
    add_subdirectory(${module})
endforeach ()