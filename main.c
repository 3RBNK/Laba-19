#include "algorithms/task/matrix_transposition.h"
#include "algorithms/task/convert_float.h"
#include "algorithms/task/evaluate_expression.h"
#include "algorithms/task/filter_word.h"
#include "algorithms/task/leave_longest_word.h"
#include "algorithms/task/rearrange_numbers.h"
#include "algorithms/task/transpose_non_symmetric_matrix.h"
#include "algorithms/task/get_best_team.h"


int main() {
    generate_team("C:\\Users\\Kirill\\Desktop\\laba_op_19\\task_9.txt",4);
    print_team("C:\\Users\\Kirill\\Desktop\\laba_op_19\\task_9.txt");

    printf("\n");

    get_best_team("C:\\Users\\Kirill\\Desktop\\laba_op_19\\task_9.txt", 4);
    print_team("C:\\Users\\Kirill\\Desktop\\laba_op_19\\task_9.txt");

    return 0;
}

