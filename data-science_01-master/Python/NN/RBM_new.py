"""
Continuous Restricted Boltzmann Machine
14/09/2008 - v. 0.1 by http://imonad.com
"""

from numpy import *
from numpy.random import *
import pylab as p
from scipy import stats, mgrid, c_, reshape, random, rot90
import pandas as pd


class RBM:
    def __init__(self, nvis, nhid):
        self.sig = 0.1
        self.epsW = 0.5
        self.epsA  = 0.5
        self.nvis = nvis
        self.nhid = nhid
        self.Ndat = 510
        self.cost = 0.00001
        self.moment = 0.90
        self.Svis0 = zeros( nvis+1, dtype=float32)
        self.Svis0[-1] = 1.0
        self.Svis = zeros( nvis+1, dtype=float32)
        self.Svis[-1] = 1.0
        self.Shid = zeros( nhid+1, dtype=float32)
        self.W  = standard_normal((nvis+1, nhid+1))/10
        self.dW = standard_normal((nvis+1, nhid+1))/1000
        self.Avis  =  0.1*ones( nvis+1, dtype=float32)
        self.Ahid  =  ones( nhid+1, dtype=float32)
        self.dA = zeros( nvis+1, dtype=float32)
        data = pd.read_csv('new_data.csv')
        data = asarray(data)

        self.dat = data
        self.dat=self.dat.T

        data_test = pd.read_csv('new_data_test.csv')
        data_test = asarray(data_test)
        self.test_data = data_test
        self.test_data=self.test_data.T

    # Sigmoidal Function
    def sigFun(self, X, A):
        lo = 0.0
        hi = 1.0
        return(lo + (hi-lo)/(1.0 + exp(-A*X)))

    # visible=0, hidden=1
    def activ(self, who):
        #print "dog"
        if(who==0):
         #   print "dog0"
            self.Svis = dot(self.W, self.Shid) + self.sig*standard_normal(self.nvis+1)
            self.Svis = self.sigFun(self.Svis, self.Avis)
            self.Svis[-1] = 1.0 # bias
        if(who==1):
          #  print "dog1"
            self.Shid = dot(self.Svis, self.W) + self.sig*standard_normal(self.nhid+1)
            self.Shid = self.sigFun(self.Shid, self.Ahid)
            self.Shid[-1] = 1.0 # bias

    def learn(self, epochmax):
        print "cat"
        Err = zeros( epochmax, dtype=float32)
        E = zeros( epochmax, dtype=float32)
        self.stat = zeros( epochmax, dtype=float32)
        self.stat2 = zeros( epochmax, dtype=float32)
        ksteps = 1

        for epoch in range(1,epochmax):
            #print "FALCON"
            wpos = zeros( (self.nvis+1, self.nhid+1), dtype=float32)
            wneg = zeros( (self.nvis+1, self.nhid+1), dtype=float32)
            apos = zeros( self.nhid+1, dtype=float32)
            aneg = zeros( self.nhid+1, dtype=float32)

            if(epoch>0):
                ksteps=50
            if(epoch>1000):
                ksteps=(epoch-epoch%100)/100+40
            self.ksteps = ksteps

            for point in xrange(self.Ndat):
                #print(self.dat[:][point])
                self.Svis0[0:13] = self.dat[:,point]
                self.Svis = self.Svis0

                # positive phase
                self.activ(1)
               # print " TIGER"
                wpos = wpos + outer(self.Svis, self.Shid)
                apos = apos + self.Shid*self.Shid
                # negative phase

                self.activ(0)
                self.activ(1)

                #print" LION"
                for recstep in xrange(ksteps):
                    self.activ(0)
                    self.activ(1)
                 #   print "RHINO"
                tmp = outer(self.Svis, self.Shid)
                wneg = wneg + tmp
                aneg = aneg + self.Shid*self.Shid


                delta = self.Svis0[0:14]-self.Svis[0:14]
                # statistics
                Err[epoch] = Err[epoch] + sum(delta*delta)
                E[epoch] =E[epoch] -sum( dot(self.W.T, tmp) )



            self.dW = self.dW*self.moment + self.epsW * ((wpos-wneg)/size(self.dat) - self.cost*self.W)
            self.W = self.W + self.dW
            self.Ahid = self.Ahid + self.epsA*(apos-aneg)/(size(self.dat)*self.Ahid*self.Ahid)
            #print "PRINT EPOCH"
            Err[epoch] = Err[epoch]/(self.nvis*size(self.dat))
            E[epoch] = E[epoch]/size(self.dat)
            print "epoch:", epoch, "err:", round_(Err[epoch], 6), "ksteps:", ksteps
            self.stat[epoch] = self.W[0,0]
            self.stat2[epoch] = self.Ahid[0]
            #print "EPOCH END"
        self.Err = Err
        self.E   = E


    def reconstruct(self, Npoint, Nsteps):

        print "Elephant"

        datnew = self.test_data
        self.datout = zeros((14, Npoint), dtype=float32)
        for point in xrange(Npoint):
            self.Svis[0:13] = datnew[:,point]
            for recstep in xrange(Nsteps):
                self.activ(1)
                self.activ(0)
            self.datout[:,point] = self.Svis[0:14]
        print self.datout

if __name__ == "__main__":

    seed(7182738)
    rbm = RBM(13,5)
    print rbm.test_data.shape
    rbm.learn(150)
    print(around(rbm.W, 5))
    rbm.reconstruct(10, 150)
    #print "Data_OUT"
    #print rbm.datout[0,:], rbm.datout[1,:]
    print "Data_IN"
    print rbm.test_data
    print "WEIGHT"
    print(around(rbm.W, 5))
    print "HIDDEN"
    print(rbm.Ahid)
