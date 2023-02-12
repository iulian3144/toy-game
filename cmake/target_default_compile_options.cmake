function(target_default_compile_options_c THIS)
    set_target_properties(${THIS} PROPERTIES
        C_STANDARD 99
        C_STANDARD_REQUIRED 99)

    target_compile_options(${THIS} PRIVATE
        $<$<C_COMPILER_ID:MSVC>:/W3 /WX>
        $<$<NOT:$<C_COMPILER_ID:MSVC>>:-Wall -Wextra -Werror>)
endfunction()
