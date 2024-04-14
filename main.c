#include "algorithms/task/matrix_transposition.h"
#include "algorithms/task/convert_float.h"
#include "algorithms/task/evaluate_expression.h"
#include "algorithms/task/filter_word.h"
#include "algorithms/task/leave_longest_word.h"
#include "algorithms/task/rearrange_numbers.h"
#include "algorithms/task/transpose_non_symmetric_matrix.h"
#include "algorithms/task/get_best_team.h"
#include "algorithms/task/update_product.h"


int main() {
    generate_product_and_order("C:\\Users\\Kirill\\Desktop\\laba_op_19\\task_10_1.txt", "C:\\Users\\Kirill\\Desktop\\laba_op_19\\task_10_2.txt");
    print_product_and_order("C:\\Users\\Kirill\\Desktop\\laba_op_19\\task_10_1.txt", "C:\\Users\\Kirill\\Desktop\\laba_op_19\\task_10_2.txt");

    printf("\n");

    update_product("C:\\Users\\Kirill\\Desktop\\laba_op_19\\task_10_1.txt", "C:\\Users\\Kirill\\Desktop\\laba_op_19\\task_10_2.txt");
    print_product_and_order("C:\\Users\\Kirill\\Desktop\\laba_op_19\\task_10_1.txt", "C:\\Users\\Kirill\\Desktop\\laba_op_19\\task_10_2.txt");

    return 0;
}

