import numpy as np
import random

nb_features = 5;
nb_examples = 10;

def create_model(nb_features):
    good_model = []
    bad_model = []
    for i in range(nb_features):
        mean = random.uniform(1, 25)
        variance = random.uniform(1,5)
        bmean = -1.0*random.uniform(1, 25)
        bvariance = random.uniform(1,5)
        good_model += [(mean, variance) ]
        bad_model += [(bmean, bvariance)]
    return good_model, bad_model

def generate_example(model):
    ex = []
    for mi in model:
        m, v = mi
        ex.append( np.random.normal(m,v) )
        # print("coucou")
    # print(sample)
    return ex

def print_array(array):
    k=0
    for i in array:
        if k == nb_features:
            print(str(i))
        else:
            print(str(i), end=' ')
        k +=1

good_model,bad_model = create_model(nb_features)


for i in range(nb_examples):
    s = []
    r = random.randint(0,1)
    if r==0:
        s = [1.0]
        s += generate_example(good_model)
    else:
        s = [-1.0]
        s += generate_example(bad_model)
    print_array(s)
