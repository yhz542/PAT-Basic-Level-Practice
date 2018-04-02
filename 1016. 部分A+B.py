class AB:
    def __init__( self ):
        self.A , self.Da , self.B , self.Db = input().split()
        self.count_a = 0 
        self.count_b = 0
    def find( self ):
        for c in self.A :
            if c == self.Da:
                self.count_a += 1
        for c in self.B :
            if c == self.Db:
                self.count_b += 1
    def display( self ):
        if self.count_a :
            number_a = int( Da * count_a )
        else:
            number_a = 0
        if self.count_b :
            number_b = int( Db * count_b )
        else:
            number_b = 0
        print( number_a + number_b )

In = AB()
In.find()
In.display()
