import numpy as np
from numpy.random import *
import pandas as pd
from scipy import stats, mgrid, c_,reshape,random,rot90


class RI_CRBM:
    def __init__(self, nvis ,nhid,df):
        self.sd=.25                                                  #standard deviation distribution
        self.lr_W=0.2                                                #learning rate of W
        self.lr_A=0.2                                                #learning rate of A
        self.nvis=nvis
        self.nhid=nhid
                                                                     #number of data points
        self.cost=0.00001                                            #cost and moment are alpha for complex CD
        self.moment=0.90
        self.Svis0=np.zeros(nvis+1,dtype=float)
        self.Svis0[-1]=1.0                                           #Bias Last element visible zeroth layer
        self.Svis=np.zeros(nvis+1,dtype=float)
        self.Svis0[-1]=1.0                                           #Bias Visible

        self.Shid=np.zeros(nhid+1,dtype=float)

        self.W= standard_normal((nvis+1,nhid+1))/10                  #initial weights
        self.dW=standard_normal((nvis+1,nhid+1))/1000                #initial weights

        self.Avis=0.1*np.ones(nvis+1,dtype=float)                    #noise factor visible
        self.Ahid=np.ones(nhid+1 ,dtype=float)                       #hidden noise factor
        self.df=df
        self.df_name=self.df+'.csv'
        data=pd.read_csv(self.df_name)                               #read_train data
        self.Ndat =len(data.index)
        data=np.asarray(data)                                        #convert as numpy
        self.dat=data
        self.dat=self.dat.T


        out_mul=pd.read_csv(self.df_name)
        out_mul['bias']=1
        out_mul=np.asarray(out_mul)

        self.out_feature_data=out_mul

    def sigmoid(self, X , A):                                        #activation function
        lo=0.0
        hi=1.0
        return (lo+(hi-lo)/(1.0+np.exp(-A*X)))

    def activate_layer(self):
        self.Shid    =       np.dot(self.Svis,self.W)+self.sd*standard_normal(self.nhid+1)              #a=b*w + noise
        self.Shid    =       self.sigmoid(self.Shid,self.Ahid)                                          #sigmoid(-AX)
        self.Shid[-1]=       1.0

    def deactivate_layer(self):
        self.Svis    =       np.dot(self.W ,self.Shid)+self.sd*standard_normal(self.nvis+1)             #used in reconstruction phase means negative phase
        self.Svis    =       self.sigmoid(self.Svis,self.Avis)
        self.Svis[-1]=       1.0

    def learn_RBM(self,n_epochs):
        Err=np.zeros(n_epochs,dtype=float)                                          #error Terms
        E=np.zeros(n_epochs,dtype=float)

        steps=1
        for epoch in range(1,n_epochs):


            w_pos=np.zeros((self.nvis+1,self.nhid+1),dtype=float)
            w_neg=np.zeros((self.nvis+1,self.nhid+1),dtype=float)
            a_pos=np.zeros(self.nhid+1 ,dtype=float)
            a_neg=np.zeros(self.nhid+1,dtype=float)

            if(epoch >0):
                steps=50
            if(epoch>1000):
                step=(epoch-epoch%100)/100+40
            self.steps=steps

            for data_point in xrange(self.Ndat):
                self.Svis0[0:self.nvis]=self.dat[:,data_point]
                self.Svis=self.Svis0

                self.activate_layer()

                w_pos= w_pos + np.outer(self.Svis,self.Shid)                       #weight adjustment after activation
                a_pos= a_pos + self.Shid * self.Shid                               #weight adjustment of A

                self.deactivate_layer()                                            #reconstrution aka deactivation from current values
                self.activate_layer()                                              #generation of new chain

                for reconstuct_step in xrange(steps):

                    self.deactivate_layer()
                    self.activate_layer()

                temp=np.outer(self.Svis, self.Shid)                                #negative cycle
                w_neg =w_neg + temp
                a_neg = a_neg + self.Shid*self.Shid

                delta=self.Svis0[0:self.nvis+1]-self.Svis[0:self.nvis+1]       #CD step for every data_point

                Err[epoch] = Err[epoch] +np.sum(delta * delta)        #Epoch Error update
                E[epoch] = E[epoch] - np.sum(np.dot(self.W.T, temp))  #Epoch Error

            self.dW   = self.dW *self.moment + self.lr_W * ((w_pos-w_neg)/np.size(self.dat) -self.cost *self.W)   #adjust dW

            self.W    = self.W +self.dW

            self.Ahid = self.Ahid + self.lr_A*(a_pos-a_neg)/(np.size(self.dat)*self.Ahid*self.Ahid)

            Err[epoch]= Err[epoch]/(self.nvis *np.size(self.dat))
            E[epoch] =E[epoch]/np.size(self.dat)
            print "epoch:", epoch, "err: ",np.round_(Err[epoch],6)   #Output of Error in each step
        self.Err=Err
        self.E=E

    def deep_features(self):
        self.ans=np.dot(self.out_feature_data,self.W)
        index=[]
        index.extend(range(1,self.Ndat+1))
        columns=['x1','x2','x3','x4','x5','x6','x7','x8','x9','x10','x11','x12','x13','x14','x15']
        df_extracted=pd.DataFrame(data=self.ans,columns=columns[0:self.nhid+1],index=index)
        self.df_extracted=df_extracted
        self.W_df=pd.DataFrame(data=self.W)

    def make_csv(self):

        self.name_df_extracted=self.df+'_extracted.csv'
        self.df_extracted.to_csv(self.name_df_extracted,index=False)
        self.name_W=self.df + '_W.csv'
        self.W_df.to_csv(self.name_W,index=False)

def Run_crbm(name):
    seed(seed(28101))
    rbm = RI_CRBM(11,3,name)
    rbm.learn_RBM(2500)
    rbm.deep_features()
    rbm.make_csv()


if __name__ == "__main__":			 #make any previous negative data as positive		

   Run_crbm('df_08_Casual_q2_norm')  #fill na values with mean 
   									 #normalise by min max scaler

   Run_crbm('df_09_Casual_q2_norm')

   Run_crbm('df_08_Petite_Casual_q2_norm')
   Run_crbm('df_09_Petite_Casual_q2_norm')

   Run_crbm('df_08_Petite_Wear_to_Work_q2_norm')
   Run_crbm('df_09_Petite_Wear_to_Work_q2_norm')


   Run_crbm('df_08_Unassigned_q2_norm')
   Run_crbm('df_09_Unassigned_q2_norm')

   Run_crbm('df_08_Shoes_q2_norm')
   Run_crbm('df_09_Shoes_q2_norm')

   Run_crbm('df_08_Wear_to_Work_q2_norm')
   Run_crbm('df_09_Wear_to_Work_q2_norm')




   Run_crbm('df_09_Casual_q1_norm')
   Run_crbm('df_10_Casual_q1_norm')

   Run_crbm('df_09_Petite_Casual_q1_norm')
   Run_crbm('df_10_Petite_Casual_q1_norm')

   Run_crbm('df_09_Petite_Wear_to_Work_q1_norm')
   Run_crbm('df_10_Petite_Wear_to_Work_q1_norm')


   Run_crbm('df_09_Unassigned_q1_norm')
   Run_crbm('df_10_Unassigned_q1_norm')

   Run_crbm('df_09_Shoes_q1_norm')
   Run_crbm('df_10_Shoes_q1_norm')

   Run_crbm('df_09_Wear_to_Work_q1_norm')
   Run_crbm('df_10_Wear_to_Work_q1_norm')










