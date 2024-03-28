#include "algorithms/task/matrix_transposition.h"
#include "algorithms/task/convert_float.h"
#include "algorithms/task/evaluate_expression.h"
#include "algorithms/task/filter_word.h"
#include "algorithms/task/leave_longest_word.h"


int main() {
    generate_text_file("/home/lenovo/Документы/stock/laba/op/laba_op_19/task_5.txt", 3, 3, 5);
    leave_longest_word("/home/lenovo/Документы/stock/laba/op/laba_op_19/task_5.txt");

    return 0;
}

