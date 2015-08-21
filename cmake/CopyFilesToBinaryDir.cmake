
# ===========================================================================
# copy_files_to_binary_dir(<DEST> <ARGN...>)
#
# Copies files (starting from second argument) to <DEST> using
# 'cmake -E copy_if_different'.

function(copy_files_to_binary_dir _dest)
    foreach(_file ${ARGN})
        add_custom_command(OUTPUT ${_file}
            COMMAND "${CMAKE_COMMAND}" "-E" "copy_if_different"
            "${CMAKE_CURRENT_SOURCE_DIR}/${_file}"
            "${_dest}/${_file}")
    endforeach()
endfunction()
