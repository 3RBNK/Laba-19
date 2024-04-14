#include "algorithms/task/matrix_transposition.h"
#include "algorithms/task/convert_float.h"
#include "algorithms/task/evaluate_expression.h"
#include "algorithms/task/filter_word.h"
#include "algorithms/task/leave_longest_word.h"
#include "algorithms/task/rearrange_numbers.h"
#include "algorithms/task/remove_true_polynomial.h"
#include "algorithms/task/transpose_non_symmetric_matrix.h"
#include "algorithms/task/get_best_team.h"
#include "algorithms/task/update_product.h"


int main() {
    generate_polynomial("C:\\Users\\Kirill\\Desktop\\laba_op_19\\task_6.txt");
    print_polynomial("C:\\Users\\Kirill\\Desktop\\laba_op_19\\task_6.txt");

    printf("\n");

    remove_true_polynomial("C:\\Users\\Kirill\\Desktop\\laba_op_19\\task_6.txt", 1.0);
    print_polynomial("C:\\Users\\Kirill\\Desktop\\laba_op_19\\task_6.txt");

    return 0;
}

