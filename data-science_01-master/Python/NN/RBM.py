



from numpy.random import *
import pylab as p
from scipy import stats, mgrid, c_, reshape, random, rot90
import pandas as pd
import numpy
#import psyco
#psyco.full()


class RBM:

    def __init__(self, nvis, nhid):
        self.sig = 0.2
        self.epsW = 0.5
        self.epsA  = 0.5
        self.nvis = nvis
        self.nhid = nhid
        self.Ndat = 510
        self.cost = 0.00001
        self.moment = 0.90
        self.Svis0 = numpy.zeros(nvis+1)
        self.Svis = numpy.zeros(nvis+1)
        self.Shid = numpy.zeros(nhid+1)
        self.W  = standard_normal((nvis+1, nhid+1))/10
        self.dW = standard_normal((nvis+1, nhid+1))/1000
        self.Avis  =  0.1*numpy.ones(nvis+1)
        self.Ahid  =  numpy.ones(nhid+1)
        self.dA = numpy.zeros(nvis)
        data=pd.read_csv('new_data.csv')
        data= asarray(data)
        self.dat = data

        data_test=pd.read_csv('new_data_test.csv')
        data_test=asarray(data_test)
        self.test_data=data_test

    def sigFun(self, X, A):
        lo = 0.0
        hi = 1.0
        return(lo + (hi-lo)/(1.0 + exp(-A*X)))

    # visible=0, hidden=1

    def activ(self, who):
        if(who==0):
            self.Svis = numpy.dot(self.W, self.Shid) + self.sig*standard_normal(self.nvis+1)
            self.Svis = self.sigFun(self.Svis, self.Avis)
            self.Svis[-1] = 1.0 # bias
        if(who==1):
            self.Shid = numpy.dot(self.Svis, self.W) + self.sig*standard_normal(self.nhid+1)
            self.Shid = self.sigFun(self.Shid, self.Ahid)
            self.Shid[-1] = 1.0 # bias

    #def wview(self):
    #    import pylab as p
    #    p.plot(xrange(size(self.W[2])),self.W[2], 'bo')
    #   p.show()

    def learn(self, epochmax):
        Err = zeros( epochmax, dtype=float32)
        E = zeros( epochmax, dtype=float32)
        self.stat = zeros( epochmax, dtype=float32)
        self.stat2 = zeros( epochmax, dtype=float32)
        ksteps = 1

        for epoch in range(1,epochmax):
            wpos = zeros( (self.nvis+1, self.nhid+1), dtype=float32)
            wneg = zeros( (self.nvis+1, self.nhid+1), dtype=float32)
            apos = zeros( self.nhid+1, dtype=float32)
            aneg = zeros( self.nhid+1, dtype=float32)

            if(epoch>0):
                ksteps=50
            if(epoch>1000):
                ksteps=(epoch-epoch%100)/100+40
            self.ksteps = ksteps

            for point in xrange(self.Ndat)
                #print(self.dat[:][point])
                self.Svis0 = self.dat[:,point]
                self.Svis = self.Svis0
                # positive phase
                self.activ(1)
                wpos = wpos + outer(self.Svis, self.Shid)
                apos = apos + self.Shid*self.Shid
                # negative phase
                self.activ(0)
                self.activ(1)


                for recstep in xrange(ksteps):
                    self.activ(0)
                    self.activ(1)

                tmp = outer(self.Svis, self.Shid)
                wneg = wneg + tmp
                aneg = aneg + self.Shid*self.Shid


                delta = self.Svis0 -self.Svis
                # statistics
                Err[epoch] = Err[epoch] + sum(delta*delta)
                E[epoch] =E[epoch] -sum( dot(self.W.T, tmp) )



            self.dW = self.dW*self.moment + self.epsW * ((wpos-wneg)/size(self.dat) - self.cost*self.W)
            self.W = self.W + self.dW
            self.Ahid = self.Ahid + self.epsA*(apos-aneg)/(size(self.dat)*self.Ahid*self.Ahid)

            Err[epoch] = Err[epoch]/(self.nvis*size(self.dat))
            E[epoch] = E[epoch]/size(self.dat)
            if (epoch%100==0) or (epoch==epochmax) or (epoch==1):
                print "epoch:", epoch, "err:", round_(Err[epoch], 6), "ksteps:", ksteps
            self.stat[epoch] = self.W[0,0]
            self.stat2[epoch] = self.Ahid[0]
        self.Err = Err
        self.E   = E


    def reconstruct(self, Npoint, Nsteps):


        datnew = self.test_data
        self.datout = zeros( (14,Npoint), dtype=float32)
        for point in xrange(Npoint):
            self.Svis[:14] = datnew[:,point]
            for recstep in xrange(Nsteps):
                self.activ(1)
                self.activ(0)

            self.datout[:,point] = self.Svis[:]

if __name__ == "__main__":

    seed(12345)
    rbm = RBM(13,5)
    rbm.learn(4000)


#        p.plot(rbm.datout[0,:],rbm.datout[1,:], 'b.')


    print(around(rbm.W,5))
    print(rbm.Ahid)
