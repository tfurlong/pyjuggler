
include("CheckCXXSourceCompiles")

function(test_storageclass_threadlocal VAR)
    set(test_source
"
thread_local int i;
int main(int argc, char* argv[])
{
    i = argc;
    return i > 1;
}
")

    check_cxx_source_compiles("${test_source}" TEST_STORAGECLASS_THREADLOCAL)

    set(${VAR} ${TEST_STORAGECLASS_THREADLOCAL} PARENT_SCOPE)
endfunction()

function(test_declspec_thread VAR)
    set(test_source
"
__declspec(thread) int i;
int main(int argc, char* argv[])
{
    i = argc;
    return i > 1;
}
")

    check_cxx_source_compiles("${test_source}" TEST_DECLSPEC_THREAD)

    set(${VAR} ${TEST_DECLSPEC_THREAD} PARENT_SCOPE)
endfunction()

function(detect_threadlocal_support)
    test_storageclass_threadlocal(HAVE_STORAGECLASS_THREADLOCAL)
    test_declspec_thread(HAVE_DECLSPEC_THREAD)

    set(HAVE_STORAGECLASS_THREADLOCAL
        ${HAVE_STORAGECLASS_THREADLOCAL} PARENT_SCOPE)
    set(HAVE_DECLSPEC_THREAD
        ${HAVE_DECLSPEC_THREAD} PARENT_SCOPE)
endfunction()
