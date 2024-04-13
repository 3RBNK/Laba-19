#include "algorithms/task/matrix_transposition.h"
#include "algorithms/task/convert_float.h"
#include "algorithms/task/evaluate_expression.h"
#include "algorithms/task/filter_word.h"
#include "algorithms/task/leave_longest_word.h"
#include "algorithms/task/rearrange_numbers.h"
#include "algorithms/task/transpose_non_symmetric_matrix.h"

int main() {
    generate_non_symmetric_matrix("C:\\Users\\Kirill\\Desktop\\laba_op_19\\task_8.txt");
    print_bin_file_matrix("C:\\Users\\Kirill\\Desktop\\laba_op_19\\task_8.txt");
    transpose_non_symmetric_matrix("C:\\Users\\Kirill\\Desktop\\laba_op_19\\task_8.txt");
    print_bin_file_matrix("C:\\Users\\Kirill\\Desktop\\laba_op_19\\task_8.txt");

    return 0;
}

