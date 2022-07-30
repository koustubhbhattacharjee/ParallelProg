import inspect

class dotter(dict):
    __setattr__=dict.__setitem__
    __getattr__=dict.get
    __delattr__=dict.__delitem__
    
A={"please":2,"no":1}
B={"dude":78,"c'mon":5}
A=dotter(A)
print(A.please)
A.please=dotter(B)
print(A.please.dude)