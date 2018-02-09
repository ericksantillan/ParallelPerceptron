import numpy as np
import random

nb_features = 5000;
nb_examples = 10000;

def create_model(nb_features):
    good_model = []
    bad_model = []
    for i in range(nb_features):
        mean = random.uniform(0, 100)
        variance = random.uniform(1,1.5)
        bmean = mean + random.uniform(-0.01,0.01)
        bvariance = variance
        good_model += [(mean, variance) ]
        bad_model += [(bmean, bvariance)]
    return good_model, bad_model

def print_models(good_model, bad_model, filename = "models"):
    f = open(filename, 'w')
    st = str(good_model)
    st += "\n"
    st += str(bad_model)
    f.write(st)
    f.close()

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

# def read_models(filename = None):
#     if filename is None:
#         g, b = create_model(nb_features)
#     else:

good_model,bad_model = create_model(nb_features)

print_models(good_model, bad_model)

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
