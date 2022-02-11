import heterocl as hcl
import numpy as np
from heterocl.dsl import def_

target = hcl.Platform.cadence_stratus
target.config(compiler='stratus_hls', project='./project', mode='csim')
# target="shls"

def test_hierarchical():

    hcl.init()

    def algo(A, B):

        @hcl.def_([A.shape, ()])
        def add_one(A, x):
            hcl.return_(A[x] + 1)


        @hcl.def_([A.shape, B.shape, ()])
        def find_max(A, B, x):
            with hcl.if_(A[x] > B[x]):
                hcl.return_(add_one(A, x))
            with hcl.else_():
                hcl.return_(B[x]) 
        
        with hcl.for_(0, 8, 2) as i:
            A[i] = A[i] + 1
        C = hcl.compute((10,), lambda x: A[x] * B[x], "C")
        tmp = hcl.compute((10,), lambda x : find_max(A, B, x))
        D = hcl.compute((10,), lambda x: C[x] + tmp[x] + B[x], "D")
        return D

    A = hcl.placeholder((10,), "A")
    B = hcl.placeholder((10,), "B")
    s = hcl.create_schedule([A, B], algo)
    s.partition(algo.C, hcl.Partition.Block)
    f = hcl.build(s, target=target, name="dut")
    
    return f

def main():
    A = np.random.randint(10, size=(10,))
    B = np.random.randint(10, size=(10,))
    D = np.zeros((10,))
    A_ = hcl.asarray(A)
    B_ = hcl.asarray(B)
    D_ = hcl.asarray(D)
    f = test_hierarchical()
    f(A_, B_, D_)

if __name__ == "__main__":

    main()
