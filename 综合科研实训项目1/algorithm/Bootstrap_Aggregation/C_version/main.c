#include "BA.h"

int main()
{
	char filename[] = "sonar.csv";
	char line[1024];
	row = get_row(filename);
	col = get_col(filename);
	int n_features = col - 1;
	dataset = (double **)malloc(row * sizeof(int *));
	for (int i = 0; i < row; ++i)
	{
		dataset[i] = (double *)malloc(col * sizeof(double));
	} //动态申请二维数组
	get_two_dimension(line, dataset, filename);

	// 输入模型参数，包括每个叶子最小样本数、最大层数、树木个数
	int min_size = 2, max_depth = 10, n_trees = 20;
	double sample_size = 1;
	int n_folds = 8;
	int fold_size = (int)(row / n_folds);

	// Bagging算法，返回交叉验证正确率
	double *score = evaluate_algorithm(dataset, col, n_folds, fold_size, min_size, max_depth, n_features, n_trees, sample_size);
}