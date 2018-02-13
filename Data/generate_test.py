import numpy as np
import random

nb_examples = 1000;

good_model =
bad_model =

def generate_example(model):
    ex = []
    for mi in model:
        m, v = mi
        ex.append( np.random.normal(m,v) )
        # print("coucou")
    # print(sample)
    return ex

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
