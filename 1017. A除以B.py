class AdivdeB:
    def __init__( self ):
        self.A , self.B = input().split()
        self.B = int( self.B )
        self.L = []
    def dealwith( self ):
        former = 0
        for i in self.A:
            i = int( i ) + former * 10
            D = int( i / self.B )
            self.L.append( D )
            former = i % self.B
        self.L.append( former )
    def display( self ):
        start = 0
        while True:
            if self.L[ start ] != 0:
                break
            start += 1
        length = len(self.L)
        if start == length - 1 :
            print(0,end='')
        for i in range( start , length-1 ):
            print(self.L[ i ],end='')
        print(' %d'%self.L[ length -1 ])
new = AdivdeB()
new.dealwith()
new.display()
