import sys
import numpy
import pandas as pd
from RBM import RBM
from utils import *


class CRBM(RBM):
    def propdown(self, h):
        pre_activation = numpy.dot(h, self.W.T) + self.vbias
        return pre_activation

    def sample_v_given_h(self, h0_sample):

        a_h = self.propdown(h0_sample)
        en = numpy.exp(-a_h)
        ep = numpy.exp(a_h)
      """  print " HOLA "
        print en
        en_list=en.copy()
        en_list.flatten()
        en_list=list(en_list)
        print en_list

        coun=0
        for i in en_list:
            if i==1:
                coun=coun+1
        print"Count : "+str(coun)
        """
        v1_mean = 1./(1 - en) -  1./ a_h
        print " v1_mean  : " + str(v1_mean)
        print " floyd"

        U = numpy.array(self.rng.uniform(
            low=0,
            high=1,
            size=v1_mean.shape))

        v1_sample = numpy.log((1 - U * (1 - ep))) / a_h
        print "v1_sample : "
        print v1_sample
        print "pink"
        print numpy.sum(numpy.isnan(v1_sample))
        return [v1_mean, v1_sample]



def test_crbm(learning_rate=0.1, k=1, training_epochs=1000):
    data=pd.read_csv('new_data.csv')
    data=numpy.asarray(data)

    print data
    print "bhainan"
    print numpy.sum(numpy.isnan(data))
    rng = numpy.random.RandomState(123)

    # construct CRBM
    rbm = CRBM(input=data, n_visible=13, n_hidden=5, rng=rng)

    # train
    for epoch in xrange(1):
        rbm.contrastive_divergence(lr=learning_rate, k=k)
        cost = rbm.get_reconstruction_cross_entropy()
        print >> sys.stderr, 'Training epoch %d, cost is ' % epoch, cost



    new_data_test=pd.read_csv('new_data_test.csv')
    new_data_test=numpy.asarray(new_data_test)
    print rbm.reconstruct(new_data_test)


if __name__ == "__main__":
    test_crbm()