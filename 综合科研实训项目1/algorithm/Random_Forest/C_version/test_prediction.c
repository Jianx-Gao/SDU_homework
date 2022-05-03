#include "RF.h"

double *get_test_prediction(double **train, double **test, int column, int min_size, int max_depth, int n_features, int n_trees, double sample_size, int fold_size, int train_size)
{
    double *predictions = (double *)malloc(fold_size * sizeof(double)); //预测集的行数就是数组prediction的长度
    struct treeBranch **forest = random_forest(train_size, column, train, min_size, max_depth, n_features, n_trees, sample_size);
    for (int i = 0; i < fold_size; i++)
    {
        predictions[i] = predict(test[i], forest, n_trees);
    }
    return predictions; //返回对test的预测数组
}