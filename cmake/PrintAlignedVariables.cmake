
# ===========================================================================
# print_aligned_variables(<ARGV...>)
#
# Prints variables and their value in the format:
#  VAR0........... ${VAR0}
#  VAR1........... ${VAR1}
#  LONG_VAR_NAME.. ${LONG_VAR_NAME}
# Variable names are padded with "." characters such that all variable
# values are aligned.

function(print_aligned_variables)

    # determine longest variable name
    set(_var_max_len 0)
    foreach(_var ${ARGV})
        string(LENGTH "${_var}" _var_len)
        if(${_var_len} GREATER ${_var_max_len})
            set(_var_max_len "${_var_len}")
        endif()
    endforeach()
    math(EXPR _var_max_len "${_var_max_len} + 2")

    # print variables
    foreach(_var ${ARGV})
        string(LENGTH "${_var}" _var_len)
        math(EXPR _var_padding "${_var_max_len} - ${_var_len}")

        # append alignment characters ('.') up to _var_max_len
        set(_msg "${_var}")
        while(${_var_padding} GREATER 0)
            set(_msg "${_msg}.")
            math(EXPR _var_padding "${_var_padding} - 1")
        endwhile()

        # use a placeholder value if variable is undefined
        if(DEFINED ${_var})
            set(_msg "${_msg} ${${_var}}")
        else()
            set(_msg "${_msg} <undefined>")
        endif()

        # print message
        message(STATUS "${_msg}")
    endforeach()
endfunction()
