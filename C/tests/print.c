#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "../inc/print.h"

Test(print_01, sucess) {
    cr_redirect_stdout();

    print("Hello World!");
    cr_assert_stdout_eq_str("Hello World!\n");
}