import pandas as pd
import numpy as np
from sklearn.model_selection import KFold
from sklearn.linear_model import Perceptron
from sklearn.metrics import accuracy_score
from sklearn.preprocessing import MinMaxScaler


if __name__ == '__main__':
    dataset = np.array(pd.read_csv("sonar.csv", sep=',', header=None))
    k_Cross = KFold(n_splits=3, random_state=8, shuffle=True)
    index = 0
    score = np.array([])
    Scaler = MinMaxScaler()
    data,label = dataset[:,:-1],dataset[:,-1]
    data = Scaler.fit_transform(data)
    for train_index, test_index in k_Cross.split(dataset):
        train_data, train_label = data[train_index, :], label[train_index]
        test_data, test_label = data[test_index, :], label[test_index]
        model = Perceptron(eta0=0.01,max_iter=500)
        model.fit(train_data, train_label)
        pred = model.predict(test_data)
        acc = accuracy_score(test_label, pred)
        score = np.append(score,acc)
        print('score[{}] = {}%'.format(index,acc))
        index+=1
    print('mean_accuracy = {}%'.format(np.mean(score)))