#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "../inc/print.hpp"

void redirect_all_stdout(void)
{
        cr_redirect_stdout();
        cr_redirect_stderr();
}


Test(print_01, sucess, .init=redirect_all_stdout) {
    print("Hello World!");
    cr_assert_stdout_eq_str("Hello World!\n");
}