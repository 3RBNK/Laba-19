#include "algorithms/task/matrix_transposition.h"
#include "algorithms/task/convert_float.h"
#include "algorithms/task/evaluate_expression.h"
#include "algorithms/task/filter_word.h"
#include "algorithms/task/leave_longest_word.h"
#include "algorithms/task/rearrange_numbers.h"

int main() {
    generate_numbers_array("C:\\Users\\Kirill\\Desktop\\laba_op_19\\task_7.txt");
    print_numbers_array("C:\\Users\\Kirill\\Desktop\\laba_op_19\\task_7.txt");
    rearrange_numbers("C:\\Users\\Kirill\\Desktop\\laba_op_19\\task_7.txt");
    print_numbers_array("C:\\Users\\Kirill\\Desktop\\laba_op_19\\task_7.txt");

    return 0;
}

